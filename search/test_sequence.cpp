#include <iostream>
#include <cassert>
#include "sequence.cpp"

using namespace std;

int main() {
    int l[] = {0,1,2,3,4,5,6,7};

    int i;
    for(i=7; i>0; i--) assert(Search(l, 8, i) == i);
}
