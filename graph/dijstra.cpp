#include <iostream>

typedef struct {
    int first;
    int second;
    int w;
}Triple, *pTriple;

typedef struct {
    char *vexes;
    int **edges;
    int ednum, vnum;
}G, *pG;

pG Build(char *vexes, int vnum, pTriple edges, int ednum) {
    pG pg = new G;
    pg->ednum = ednum;
    pg->vnum = vnum;

    int i, j;
    pg->edges = new int*[vnum];
    for(i=0; i<vnum; i++) {
        pg->edges[i] = new int[vnum];
        for(j=0; j<vnum; j++) {
            pg->edges[i][j] = INT_MAX;
        }
    }

    pg->vexes = new char[vnum];

    for(i=0; i<vnum; i++) {
        pg->vexes[i] = vexes[i];
    }

    for(i=0; i<ednum; i++) {
        pg->edges[edges[i].first-1][edges[i].second-1] = edges[i].w;
        pg->edges[edges[i].second-1][edges[i].first-1] = edges[i].w;
    }
    return pg;
}

int *dijstra(pG pg, int start) {
    bool *f = new bool[pg->vnum];
    int *shortest_weight = new int[pg->vnum];
    int *parent_path = new int[pg->vnum];

    int i, j, min=INT_MAX, k;
    for(i=0; i<pg->vnum; i++) {
        f[i] = false;
        shortest_weight[i] = pg->edges[start][i];
        parent_path[i] = start;
    }
    f[start] = true;

    for(i=1; i<pg->vnum; i++) {
        min = INT_MAX;
        for(j=0; j<pg->vnum; j++) {
            if(!f[j] && shortest_weight[j]<min) {
                k = j;
                min = shortest_weight[j];
            }
        }
        f[k] = true;
        for(j=0; j<pg->vnum; j++) {
            if(!f[j] && pg->edges[k][j]!=INT_MAX && min+pg->edges[k][j] < shortest_weight[j]) {
                shortest_weight[j] = min+pg->edges[k][j];
                parent_path[j] = k;
            }
        }
    }
    delete[] f;
    delete[] shortest_weight;
    return parent_path;
}
