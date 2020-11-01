// 队列的链表实现

#include <iostream>

typedef int TYPE;

typedef struct Node {
    Node *next;
    TYPE data;
}Node, *pNode;

typedef struct {
    pNode h;        // head
    pNode t;        // tail
}Q, *pQ;

int Init(Q &Q) {
    pNode p = new Node;
    p->next = NULL;
    Q.h = Q.t = p;
    
    return 0;
}

int IsEmpty(Q &Q) {
    return Q.h == Q.t;
}

int EnQueue(Q &Q, TYPE e) {
    pNode p = new Node;
    p->data = e;
    p->next = NULL;
    Q.t->next = p;
    Q.t = p;

    if(!Q.h->next) Q.h->next = p;       // !IMPORTANT

    return 0;
}

int DeQueue(Q &Q, TYPE &e) {
    if(IsEmpty(Q)) return -1;

    pNode del = Q.h->next;
    e = del->data;
    Q.h->next = del->next;
    delete del;
    
    if(!Q.h->next) Q.t = Q.h;           // !IMPORTANT
    return 0;
}

int Clear(Q &Q) {
    pNode p = Q.h->next;
    while(p) {
        pNode del = p;
        p = p->next;
        delete del;
    }
    
    Q.h->next = NULL;
    Q.t = Q.h;

    return 0;
}
