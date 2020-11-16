#include <iostream>
#include "heap.cpp"

using namespace std;

int main() {
    int i;
    int l[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    // int l[] = {1, 2, 3, 4, 5, 6};
    
    heap_sort(l, 9);
    for(i=0; i<9; i++) {
        cout<<l[i]<<" ";
    }
    cout<<endl;

    return 0;
}
