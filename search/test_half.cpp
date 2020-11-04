#include <iostream>
#include <cassert>
#include "half.cpp"

using namespace std;

int main() {
    int l[] = {1,2,3,4,5,6,7};
    
    int i;
    for(i=0; i<7; i++) {
        assert(Search(l, 7, i+1) == i);
    }

    assert(Search(l, 7, 0) == -1);
    assert(Search(l, 7, 8) == -1);

    for(i=0; i<7; i++) {
        assert(InterpolationSearch(l, 7, i+1) == i);
    }

    assert(InterpolationSearch(l, 7, 0) == -1);
    assert(InterpolationSearch(l, 7, 8) == -1);


    return 0;
}
