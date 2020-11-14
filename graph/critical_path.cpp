#include <iostream>
#include <stack>

typedef struct {
    int first;
    int second;
    int w;
}Triple, *pTriple;

typedef struct Edge{
    int vex;
    int w;
    Edge *next;
}Edge, *pEdge;

typedef struct Vex {
    pEdge first;
    char e;
}Vex, *pVex;

typedef struct {
    pVex vexes;
    int vnum;
    int ednum;
}G, *pG;

pG Build(char *vexes, int vnum, pTriple edges, int ednum) {
    pG pg = new G;
    pg->vexes = new Vex[vnum];
    pg->vnum = vnum;
    pg->ednum = ednum;
    
    int i;
    for(i=0; i<vnum; i++) {
        pg->vexes[i].e = vexes[i];
        pg->vexes[i].first = NULL;
    }

    for(i=0; i<ednum; i++) {
        pEdge pedge = new Edge;
        pedge->w = edges[i].w;
        pedge->vex = edges[i].second-1;
        pedge->next = pg->vexes[edges[i].first-1].first;
        pg->vexes[edges[i].first-1].first = pedge;
    }
    return pg;
}

void topo(pG pg, int *etv, std::stack<int> &up_s) {
    int *in_degree = new int[pg->vnum];
    int i;
    std::stack<int> s;

    pEdge p;
    for(i=0; i<pg->vnum; i++) {
        in_degree[i] = 0;
    }

    for(i=0; i<pg->vnum; i++) {
        p = pg->vexes[i].first;
        while(p) {
            in_degree[p->vex]++;
            p = p->next;
        }
    }

    for(i=0; i<pg->vnum; i++) {
        if(in_degree[i] <= 0) {
            s.push(i);
        }
    }

    while(!s.empty()) {
        i = s.top();
        s.pop();

        up_s.push(i);

        p = pg->vexes[i].first;
        while(p) {
            in_degree[p->vex]--;
            if(in_degree[p->vex] <= 0) {
                s.push(p->vex);
            }
            if(etv[i]+p->w > etv[p->vex]) {
                etv[p->vex] = etv[i] + p->w;
            }
            p = p->next;
        }
    }
    delete[] in_degree;
}

void critical_path(pG pg, int end) {
    int *ltv = new int[pg->vnum];
    int *etv = new int[pg->vnum];
    int i, lte, ete;
    pEdge p;
    std::stack<int> up_s;

    for(i=0; i<pg->vnum; i++) {
        etv[i] = 0;
    }
    topo(pg, etv, up_s);

    for(i=0; i<pg->vnum; i++) {
        ltv[i] = etv[end];
    }
    while(!up_s.empty()) {
        i = up_s.top();
        up_s.pop();
        p = pg->vexes[i].first;
        while(p) {
            if(ltv[p->vex]-p->w < ltv[i]) {
                ltv[i] = ltv[p->vex]-p->w;
            }
            p = p->next;
        }
    }

    for(i=0; i<pg->vnum; i++) {
        p = pg->vexes[i].first;
        while(p) {
            ete = etv[i];
            lte = ltv[p->vex] - p->w;
            if(ete == lte) {
                std::cout<<i<<"---"<<p->vex<<std::endl;
            }
            p = p->next;
        }
    }
    delete[] etv;
    delete[] ltv;
}
