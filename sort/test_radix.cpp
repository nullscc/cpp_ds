#include <iostream>
#include <cassert>
#include "radix.cpp"

using namespace std;

int main() {
    int i;
    int l[] = {109, 108, 709, 612, 5, 4, 3, 2, 1};
    
    assert(get_width(l, 9)==3);
    assert(get_kth(109, 1)==9);
    assert(get_kth(109, 2)==0);
    assert(get_kth(109, 3)==1);
    radix(l, 9);

    for(i=0; i<9; i++) {
        cout<<l[i]<<" ";
    }
    cout<<endl;

    return 0;
}
