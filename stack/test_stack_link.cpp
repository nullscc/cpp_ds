#include <iostream>
#include <cassert>
#include "stack_link.cpp"

using namespace std;

int main() {
    int i;
    TYPE e;

    pNode S = Init();
    assert(S);
    assert(IsEmpty(S));
    assert(GetTop(S, e)==-1);

    for(i=0; i<10; i++) {
        assert(!Push(S, i+1));
    }
    assert(!GetTop(S, e));
    assert(e == 10);

    assert(!IsEmpty(S));

    for(i=10; i>0; i--) {
        assert(!Pop(S, e));
        assert(e==i);
    }

    assert(IsEmpty(S));
    assert(GetTop(S, e)==-1);

    for(i=0; i<10; i++) {
        assert(!Push(S, i+1));
    }
    Clear(S);
    assert(IsEmpty(S));
    assert(GetTop(S, e)==-1);
}

