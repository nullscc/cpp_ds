#include<iostream>
#include<cassert>
#include"list.cpp"

using namespace std;

int main() {
    int i, j;
    Node L = *Init();

    assert(!L.next);

    for(i=10; i>0; i--) {
        assert(!Insert_head(L, i));
    }

    for(i=10; i>0; i--) {
        pNode tmp = Search_data(L, i);
        assert(tmp->next->data == i);
    }

    assert(!Delete(L, 1));
    assert(L.next->data == 2);
    for(i=10; i>1; i--) {
        assert(!Delete(L, i));
    }
    assert(!L.next);

    for(i=10; i>0; i--) {
        assert(!Insert_head(L, 100));
    }
    assert(L.next->data == 100);

    assert(!Insert(L, 5, 1));
    pNode next = &L;
    for(i=0; i<11; i++) {
        next = next->next;
        assert(next);
        if(i==4) assert(next->data == 1);
        else assert(next->data == 100);
    }

    assert(!Delete_all(L, 100));

    assert(L.next->data == 1);
    assert(!L.next->next);

	return 0;
}
