#include <iostream>

typedef struct {
    int first;
    int second;
    int w;
}Triple, *pTriple;

int find(int *parent, int i) {
    while(parent[i] >= 0) {
        i = parent[i];
    }
    return i;
}

void kruskal(pTriple edges, int n, int vnum) {
    int i, j, k;

    int *parent = new int[vnum];
    for(i=0; i<vnum; i++) {
        parent[i] = -1;
    }
    
    // TODO: 改成从堆中获取最小权值的边
    for(i=0; i<n; i++) {
        j = find(parent, edges[i].first);
        k = find(parent, edges[i].second);
        if(j != k) {
            std::cout<<edges[i].first<<"---"<<edges[i].second<<std::endl;
            parent[j] = k;
        }
    }
}
