#include <iostream>
#include <cassert>
#include "topo.cpp"

using namespace std;

void visit(pG pg, int i) {
    cout<<pg->vexes[i].e<<" ";
}

int main() {
    // 数据使用《大话数据结构》p239(电子书p263), 图7-5-2
    char vexes[] = "ABCDEFGHIJKLMN";
    int edges_data[] = {1,5,1,6,1,12,2,3,2,5,2,9,3,6,3,7,4,3,4,14,5,8,6,9,6,13,7,6,9,8,10,11,10,12,11,14,13,10};
    pair<int, int> edges[19];

    int i;
    for(i=0; i<37; i+=2) {
        pair<int, int> tmp;
        tmp.first = edges_data[i];
        tmp.second = edges_data[i+1];
        edges[i/2] = tmp;
    }
    pG pg = Build(vexes, 14, edges, 19);

    topo(pg);
    return 0;
}
