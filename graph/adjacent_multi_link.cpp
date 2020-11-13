#include <iostream>

typedef char TYPE;

typedef struct Edge {
    int ivex, jvex;
    Edge *ilink, *jlink;
}Edge, *pEdge;

typedef struct Vex {
    pEdge first;
    TYPE e;
}Vex, *pVex;

typedef struct {
    pVex vexes;
    int vnum, ednum;
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

    pEdge tmp = NULL;
    for(i=0; i<ednum; i++) {
        tmp = new Edge;
        tmp->ivex = edges[i].first-1;
        tmp->jvex = edges[i].second-1;
        tmp->ilink = pg->vexes[tmp->ivex].first;
        tmp->jlink = pg->vexes[tmp->jvex].first;
        pg->vexes[tmp->ivex].first = tmp;
        pg->vexes[tmp->jvex].first = tmp;
    }
    return pg;
}

void dfs(pG pg, int i, void (*visit)(pG, int), bool *visited) {
    visit(pg, i);
    visited[i] = true;

    pEdge p = pg->vexes[i].first;
    while(p) {
        if(i == p->ivex) {
            if(!visited[p->jvex]) dfs(pg, p->jvex, visit, visited);
            p = p->ilink;
        } else {
            if(!visited[p->ivex]) dfs(pg, p->ivex, visit, visited);
            p = p->jlink;
        }
    }
}

void DFS(pG pg, void (*visit)(pG, int)) {
    bool *visited = new bool[pg->vnum];

    int i;
    for(i=0; i<pg->vnum; i++) visited[i] = false;

    for(i=0; i<pg->vnum; i++) {
        if(!visited[i]) dfs(pg, i, visit, visited);
    }
}
