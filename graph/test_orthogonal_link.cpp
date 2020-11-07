#include <iostream>
#include <cassert>
#include "orthogonal_link.cpp"

using namespace std;

void visit(pG pg, int i) {
    cout<<pg->vexes[i].e<<" ";
}

int main() {
    // 数据使用《大话数据结构》p239(电子书p263), 图7-5-2
    char vexes[] = "ABCDEFGHI";
    int edges_data[] = {1,2,1,6,2,3,2,7,2,9,3,9,3,4,4,9,4,8,4,7,4,5,5,8,5,6,6,7,7,8};
    pair<int, int> edges[15];

    int i;
    for(i=0; i<29; i+=2) {
        pair<int, int> tmp;
        tmp.first = edges_data[i];
        tmp.second = edges_data[i+1];
        edges[i/2] = tmp;
    }
    pG pg = Build(vexes, 9, edges, 15);

    assert(pg->vexes[0].e == 'A');
    pEdge firstout = pg->vexes[0].firstout;
    cout<<"A的第一条边:"<<firstout->t<<"->"<<firstout->h<<endl;
    cout<<"A的第二条边:"<<firstout->tlink->t<<"->"<<firstout->tlink->h<<endl;
    cout<<"A的第三条边:"<<firstout->tlink->tlink<<endl;

    cout<<"深度优先搜索结果:";
    DFS(pg, visit);
    cout<<endl;

    return 0;
}
