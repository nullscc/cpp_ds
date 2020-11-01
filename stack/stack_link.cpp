// 栈的链表实现

#include <iostream>

typedef int TYPE;

typedef struct Node {
    Node *next;
    TYPE data;
}Node, *pNode;

pNode Init() {
    pNode S = new Node;
    S->next = NULL;
    return S;
}

int IsEmpty(pNode S) {
    return !S->next;
}

int GetTop(pNode S, TYPE &e) {
    if(IsEmpty(S)) return -1;

    e = S->next->data;

    return 0;
}

int Push(pNode S, TYPE e) {
    pNode tmp = new Node;
    tmp->next = S->next;
    tmp->data = e;

    S->next = tmp;
    return 0;
}

int Pop(pNode S, TYPE &e) {
    if(IsEmpty(S)) return -1;
    
    pNode tmp = S->next;
    S->next = S->next->next;
    e = tmp->data;

    delete tmp;
    return 0;
}

int Clear(pNode S) {
    pNode p = S->next;
    while(p) {
        pNode del = p;
        p = p->next;
        delete del;
    }
    S->next = NULL;
    return 0;
}

