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


void floyd(pG pg, int start, int end) {
    int k, i, j;
    int **D = new int*[pg->vnum];
    int **P = new int*[pg->vnum];

    for(i=0; i<pg->vnum; i++) {
        D[i] = new int[pg->vnum];
        P[i] = new int[pg->vnum];
        for(j=0; j<pg->vnum; j++) {
            D[i][j] = pg->edges[i][j];
            P[i][j] = j;
        }
    }

    for(k=0; k<pg->vnum; k++) {
        for(i=0; i<pg->vnum; i++) {
            for(j=0; j<pg->vnum; j++) {
                if(D[i][k]!=INT_MAX && D[k][j]!=INT_MAX && D[i][k]+D[k][j]<D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[i][k];
                }
            }
        }
    }

    k = start;
    while(k != end) {
        std::cout<<k<<"-->";
        k = P[k][end];
    }
    std::cout<<k<<std::endl;

    for(i=0; i<pg->vnum; i++) {
        delete[] D[i];
        delete[] P[i];
    }

    delete[] D;
    delete[] P;
}
