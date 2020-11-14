#include <iostream>
#include <cassert>
#include "critical_path.cpp"

using namespace std;

int main() {
    // 数据使用《大话数据结构》p305(电子书p281), 图7-9-4
    char vexes[] = "0123456789";

    int edges_data[] = {1,2,6,1,3,4,2,4,6,2,5,6,3,4,8,3,6,7,4,5,3,5,7,9,5,8,4,6,8,6,7,10,2,8,9,5,9,10,3};
    Triple edges[13];

    int i;
    for(i=0; i<37; i+=3) {
        Triple tmp;
        tmp.first = edges_data[i];
        tmp.second = edges_data[i+1];
        tmp.w = edges_data[i+2];
        edges[i/3] = tmp;
    }
    pG pg = Build(vexes, 10, edges, 13);

    critical_path(pg, 9);
    return 0;
}
