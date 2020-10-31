#include <iostream>
#include <cassert>
#include "stack_sequence.cpp"

using namespace std;

int main() {
    int i;
    TYPE e;

    Stack S;
    Init(S);
    assert(S.cap == MAX);
    assert(!S.len);
    assert(!S.top);
    assert(IsEmpty(S));
    assert(!IsFull(S));
    assert(!GetLen(S));
    assert(GetTop(S, e)==-1);

    for(i=0; i<MAX; i++) {
        assert(!Push(S, i+1));
    }
    assert(!GetTop(S, e));
    assert(e == MAX);

    assert(S.len==S.cap);
    assert(S.top==S.cap);
    assert(!IsEmpty(S));
    assert(IsFull(S));
    assert(GetLen(S)==S.cap);

    for(i=MAX; i>0; i--) {
        assert(!Pop(S, e));
        assert(e==i);
    }

    assert(S.cap == MAX);
    assert(!S.len);
    assert(!S.top);
    assert(IsEmpty(S));
    assert(!IsFull(S));
    assert(!GetLen(S));
    assert(GetTop(S, e)==-1);

    for(i=0; i<MAX; i++) {
        assert(!Push(S, i+1));
    }
    Clear(S);
    assert(S.cap == MAX);
    assert(!S.len);
    assert(!S.top);
    assert(IsEmpty(S));
    assert(!IsFull(S));
    assert(!GetLen(S));
    assert(GetTop(S, e)==-1);
}

