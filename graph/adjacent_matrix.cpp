#include <iostream>
#include <queue>
#include <stack>

typedef struct {
    char *vexes;
    int **edges;
    int ednum, vnum;
}G, *pG;

pG Build(char *vexes, int vnum, std::pair<int, int> *edges, int ednum) {
    pG pg = new G;
    pg->ednum = ednum;
    pg->vnum = vnum;

    int i, j;
    pg->edges = new int*[vnum];
    for(i=0; i<vnum; i++) {
        pg->edges[i] = new int[vnum];
        for(j=0; j<vnum; j++) {
            pg->edges[i][j] = 0;
        }
    }

    pg->vexes = new char[vnum];

    for(i=0; i<vnum; i++) {
        pg->vexes[i] = vexes[i];
    }

    for(i=0; i<ednum; i++) {
        pg->edges[edges[i].first-1][edges[i].second-1] = 1;
        pg->edges[edges[i].second-1][edges[i].first-1] = 1;
    }
    return pg;
}

void dfs(pG pg, int i, bool *visited, void (*visit)(pG, int)) {
    visit(pg, i);
    visited[i] = true;

    int j;
    for(j=0; j<pg->vnum; j++) {
        if(pg->edges[i][j] && !visited[j]) {
            dfs(pg, j, visited, visit);
        }
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

void BFS(pG pg, void (*visit)(pG, int)) {
    std::queue<int> q;
    int i;
    bool *visited = new bool[pg->vnum];

    q.push(0);
    visited[0] = true;
    int tmp;
    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        visit(pg, tmp);
        for(i=0; i<pg->vnum; i++) {
            if(pg->edges[tmp][i])
            if(!visited[i] && pg->edges[tmp][i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs_nonrecursive(pG pg, int i, bool *visited, void (*visit)(pG, int)) {
    std::stack<int> s;
    s.push(i);
    visit(pg, i);
    visited[i] = true;
    
    int tmp;
    bool find = false;      // TODO: 总感觉这里的实现不太好~
    int j;
    while(!s.empty()) {
        if(!find) {
            tmp = s.top();
            s.pop();
        }

        find = false;
        for(j=0; j<pg->vnum; j++) {
            if(!visited[j] && pg->edges[tmp][j]) {
                find = true;
                visit(pg, j);
                visited[j] = true;
                tmp = j;
                s.push(j);
                break;
            }
        }
    }
}

void DFSNonRecursive(pG pg, void (*visit)(pG, int)) {
    bool *visited = new bool[pg->vnum];
    int i;

    for(i=0; i<pg->vnum; i++) {
        visited[i] = false;
    }

    for(i=0; i<pg->vnum; i++) {
        if(!visited[i]) {
            dfs_nonrecursive(pg, i, visited, visit);
        }
    }

}
