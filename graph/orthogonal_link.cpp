#include <iostream>

typedef char TYPE;

typedef struct Edge {
    int h, t;
    Edge *hlink;
    Edge *tlink;
}Edge, *pEdge;

typedef struct {
    pEdge firstin, firstout;
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
        pg->vexes[i].firstin = pg->vexes[i].firstout = NULL;
    }

    pEdge tmp = NULL;
    for(i=0; i<ednum; i++) {
        tmp = new Edge;
        tmp->t = edges[i].first-1;
        tmp->h = edges[i].second-1;
        tmp->tlink = pg->vexes[tmp->t].firstout;
        tmp->hlink = pg->vexes[tmp->h].firstin;
        pg->vexes[tmp->t].firstout = tmp;
        pg->vexes[tmp->h].firstin = tmp;
    }
    return pg;
}

void dfs(pG pg, int i, void (*visit)(pG, int), bool *visited) {
    visit(pg, i);
    visited[i] = true;

    pEdge p = pg->vexes[i].firstout;
    while(p) {
        if(!visited[p->h]) dfs(pg, p->h, visit, visited);
        p = p->tlink;
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
