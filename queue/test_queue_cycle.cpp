#include <iostream>
#include <cassert>

#include "queue_cycle.cpp"

using namespace std;

int main() {
    int i;
    TYPE e;

    Q Q;
    Init(Q);
    assert(Q.h == Q.t);
    assert(!Q.h);
    assert(Q.cap == MAX - 1);
    assert(!GetLen(Q));
    assert(IsEmpty(Q));
    assert(!IsFull(Q));

    for(i=0; i<10; i++) {
        assert(!EnQueue(Q, i+1));
    }
    assert(GetLen(Q) == 10);
    assert(IsFull(Q));
    assert(!IsEmpty(Q));
    
    assert(EnQueue(Q, 10) == -1);

    assert(!DeQueue(Q, e));
    assert(e == 1);
    assert(!DeQueue(Q, e));
    assert(e == 2);

    assert(GetLen(Q) == 8);
    assert(!IsFull(Q));
    assert(!IsEmpty(Q));

    assert(!EnQueue(Q, 1));
    assert(GetLen(Q) == 9);
    assert(!IsFull(Q));

    assert(!EnQueue(Q, 2));
    assert(GetLen(Q) == 10);
    assert(IsFull(Q));

    assert(Q.l[Q.h] == 3);
}
