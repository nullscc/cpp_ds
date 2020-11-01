#include <iostream>
#include <cassert>

#include "queue_link.cpp"

using namespace std;

int main() {
    int i;
    TYPE e;
    Q Q;
    Init(Q);
    assert(Q.t == Q.h);
    assert(!Q.h->next);
    assert(IsEmpty(Q));
    
    for(i=1; i<11; i++) {
        assert(!EnQueue(Q, i));
    }
    assert(Q.h->next->data == 1);
    assert(Q.t->data == 10);

    for(i=1; i<11; i++) {
        assert(!DeQueue(Q, e));
        assert(e == i);
    }

    assert(IsEmpty(Q));
    
    for(i=1; i<11; i++) {
        assert(!EnQueue(Q, i));
    }

    Clear(Q);
    IsEmpty(Q);

    return 0;
}
