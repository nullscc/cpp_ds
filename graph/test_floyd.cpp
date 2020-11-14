#include <iostream>
#include <cassert>
#include "floyd.cpp"

using namespace std;

int main() {
    // 数据使用《大话数据结构》p259(电子书p283), 图7-7-2
    char vexes[] = "012345678";

    int edges_data[] = {1,2,1,1,3,5,2,3,3,2,5,5,2,4,7,3,5,1,3,6,7,4,5,2,4,7,3,5,6,3,5,8,9,5,7,6,6,8,5,7,8,2,7,9,7,8,9,4};
    Triple edges[16];

    int i;
    for(i=0; i<46; i+=3) {
        Triple tmp;
        tmp.first = edges_data[i];
        tmp.second = edges_data[i+1];
        tmp.w = edges_data[i+2];
        edges[i/3] = tmp;
    }
    pG pg = Build(vexes, 9, edges, 16);

    floyd(pg, 0, 8);

    return 0;
}
