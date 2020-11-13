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

void prim(pG pg, int start) {
    int *adjvex = new int[pg->vnum];
    int *lowcost = new int[pg->vnum];
    
    int i;
    for(i=0; i<pg->vnum; i++) {
        adjvex[i] = start;
        lowcost[i] = pg->edges[start][i];
    }
    lowcost[start] = 0;

    int j, min, k;
    for(i=0; i<pg->vnum-1; i++) {
        min = INT_MAX;
        for(j=0; j<pg->vnum; j++) {
            if(lowcost[j] && lowcost[j] < min) {
                k = j;
                min = lowcost[j];
            }
        }

        lowcost[k] = 0;
        std::cout<<adjvex[k]<<"--"<<k<<std::endl;

        for(j=0; j<pg->vnum; j++) {
            if(lowcost[j] && pg->edges[k][j] < lowcost[j]) {
                lowcost[j] = pg->edges[k][j];
                adjvex[j] = k;
            }
        }
    }
}
