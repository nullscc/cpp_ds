#include <iostream>
#include <stack>

typedef struct Edge{
    int vex;
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

pG Build(char *vexes, int vnum, std::pair<int, int> *edges, int ednum) {
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
            pedge->vex = edges[i].second-1;
            pedge->next = pg->vexes[edges[i].first-1].first;
            pg->vexes[edges[i].first-1].first = pedge;
    }
    return pg;
}

void topo(pG pg) {
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
        std::cout<<i<<" ";
        p = pg->vexes[i].first;
        while(p) {
            in_degree[p->vex]--;
            if(in_degree[p->vex] <= 0) {
                s.push(p->vex);
            }
            p = p->next;
        }
    }
    std::cout<<std::endl;
    delete[] in_degree;
}
