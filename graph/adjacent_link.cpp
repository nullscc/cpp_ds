#include <iostream>

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
        // if(!pg->vexes[edges[i].first-1].first) {
        //     pEdge pedge = new Edge;
        //     pedge->vex = edges[i].second-1;
        //     pedge->next = NULL;
        //     pg->vexes[edges[i].first-1].first = pedge;
        // } else {
        //     pEdge pedge = new Edge;
        //     pedge->vex = edges[i].second-1;
        //     pedge->next = pg->vexes[edges[i].first-1].first;
        //     pg->vexes[edges[i].first-1].first = pedge;
        // }

        // if(!pg->vexes[edges[i].second-1].first) {
        //     pEdge pedge = new Edge;
        //     pedge->vex = edges[i].first-1;
        //     pedge->next = NULL;
        //     pg->vexes[edges[i].second-1].first = pedge;
        // } else {
        //     pEdge pedge = new Edge;
        //     pedge->vex = edges[i].first-1;
        //     pedge->next = pg->vexes[edges[i].second-1].first;
        //     pg->vexes[edges[i].second-1].first = pedge;
        // }
            pEdge pedge = new Edge;
            pedge->vex = edges[i].second-1;
            pedge->next = pg->vexes[edges[i].first-1].first;
            pg->vexes[edges[i].first-1].first = pedge;

            pedge = new Edge;
            pedge->vex = edges[i].first-1;
            pedge->next = pg->vexes[edges[i].second-1].first;
            pg->vexes[edges[i].second-1].first = pedge;

        
    }
    return pg;
}

void dfs(pG pg, int i, bool *visited, void (*visit)(pG, int)) {
    visit(pg, i);
    visited[i] = true;

    pEdge p = pg->vexes[i].first;
    while(p) {
        if(!visited[p->vex]) {
            dfs(pg, p->vex, visited, visit);
        }
        p = p->next;
    }
}

void DFS(pG pg, void (*visit)(pG, int)) {
    int i;
    
    bool *visited = new bool[pg->vnum];

    for(i=0; i<pg->vnum; i++) {
        visited[i] = false;
    }

    for(i=0; i<pg->vnum; i++) {
        if(!visited[i]) {
            dfs(pg, i, visited, visit);
        }
    }
}
