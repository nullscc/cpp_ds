#include <iostream>
#include "build_from_search_sequence.cpp"

using namespace std;

void visit(pNode p) {
    cout<<p->e;
}

int main() {
    char A[] = "ABCDEF";
    char B[] = "CBAEDF";

    pNode T = NULL;
    Build(T, A, 0, 5, B, 0, 5);

    cout<<"中序遍历结果:";
    MidSearch(T, visit);
    cout<<endl;

}
