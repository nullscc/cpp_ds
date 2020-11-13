#include <iostream>
#include <cassert>
#include "prim.cpp"

using namespace std;

int main() {
    // 数据使用《大话数据结构》p247(电子书p271), 图7-6-3
    char vexes[] = "012345678";
    int edges_data[] = {5,8,7,3,9,8,1,2,10,1,6,11,2,9,12,4,8,16,2,7,16,6,7,17,2,3,18,7,8,19,4,5,20,4,9,21,3,4,22,4,7,24,5,6,26};
    Triple edges[15];

    int i;
    for(i=0; i<43; i+=3) {
        Triple tmp;
        tmp.first = edges_data[i];
        tmp.second = edges_data[i+1];
        tmp.w = edges_data[i+2];
        edges[i/3] = tmp;
    }
    pG pg = Build(vexes, 9, edges, 15);

    prim(pg, 0);

    return 0;
}
