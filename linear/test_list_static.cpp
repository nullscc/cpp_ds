// 静态链表实现的测试

#include<iostream>
#include <cassert>
#include "list_static.cpp"

using namespace std;

int main() {
    int i;
    SL L;
    Init(L);
    assert(L.len==0);
    assert(L.cap==MAX-2);

    assert(L.l[0].next==2);
    assert(L.l[1].next==0);
    assert(L.l[MAX-1].next==0);
    for(i=2; i<MAX-1; i++) {
        assert(L.l[i].next==i+1);
    }

    for(i=MAX-2; i>0; i--) {
        assert(Insert_head(L, i)==0);
    }
    assert(L.len==MAX-2);
    assert(L.cap==MAX-2);

    assert(!Malloc(L));

    for(i=1; i<MAX-1; i++) {
        assert(Search_index(L, i)==i);
    }
    
    for(i=1; i<MAX-1; i++) {
        assert(Search_data(L, i)==MAX-i);
    }
    assert(Delete(L, 5)==5);
    assert(L.len==MAX-3);
    assert(L.l[0].next==MAX-5);
    assert(Search_index(L, 5)==6);

    assert(Insert(L, 5, 5)==MAX-5);
    assert(L.len==MAX-2);
    assert(L.l[0].next==0);

    for(i=1; i<MAX-1; i++) {
        assert(Search_index(L, i)==i);
    }
    
    for(i=1; i<MAX-1; i++) {
        assert(Search_data(L, i)==MAX-i);
    }

    return 0;
}

