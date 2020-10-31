// 链表实现

#include<iostream>

typedef int TYPE;

typedef struct Node {
    Node *next;
    TYPE data;
}Node, *pNode;

pNode Init() {
    pNode ret = new Node;
    ret->next = NULL;

    return ret;
}

int Insert_head(Node &L, TYPE e) {

    pNode n_pnode = new Node;
    n_pnode->data = e;
    n_pnode->next = L.next;
    L.next = n_pnode;

    return 0;
}

int Insert(Node &L, int i, TYPE e) {
    if(i<1) return -1;

    int j=1;
    pNode next = &L;
    for(; j<=i-1; j++) {
        next = next->next;
        if(!next) return -1;
    }

    pNode n_pnode = new Node;
    n_pnode->data = e;
    n_pnode->next = next->next;
    next->next = n_pnode;

    return 0;
}

pNode Search_data(Node &L, TYPE e) {
    pNode next = &L;
    pNode prev = &L;
    while(next) {
        next = next->next;
        if (next->data==e) return prev;
        prev = next;
    }

    return NULL;
}

// 删除第一个
int Delete(Node &L, TYPE e) {
    pNode prev = Search_data(L, e);
    if(!prev) return -1;
    
    pNode del = prev->next;
    prev->next = prev->next->next;

    delete del;

    return 0;
}

// 删除所有
int Delete_all(Node &L, TYPE e) {
    int ret = -1;

    pNode next = &L;
    pNode prev = &L;
    
    pNode tmp;
    while(next && next->next) {
        next = next->next;
        if(next->data == e) {
            tmp = prev->next;
            prev->next = next->next;
            delete tmp;
            ret = 0;

            next = prev;
        }
        prev = next;
    }
    return ret;
}
