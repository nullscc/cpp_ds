#include <iostream>
#include <cassert>

typedef char TYPE;

typedef struct Node {
    bool rtag;
    bool ltag;
    Node *l;
    Node *r;
    TYPE e;
}Node, *pNode;

int Build(pNode &T) {
    char ch;
    scanf("%c", &ch);
    
    if(ch == ' ') {
        T = NULL;
    } else {
        pNode pn_node = new Node;
        pn_node->e = ch;
        pn_node->l = NULL;
        pn_node->r = NULL;
        pn_node->ltag = pn_node->rtag = false;
        T = pn_node;
        
        assert(!Build(T->l));
        assert(!Build(T->r));
    }

    return 0;
}

void PreSearch(pNode T, pNode &prev) {
    if(!T) return;

    if(!T->l) {
        T->l = prev;
        T->ltag = true;
    }
    if(prev && !prev->r) {
        prev->r = T;
        prev->rtag = true;
    }

    prev = T;
    if(!T->ltag) PreSearch(T->l, prev);
    if(!T->rtag) PreSearch(T->r, prev);
}

void BuildTag(pNode T) {
    pNode prev = NULL;
    PreSearch(T, prev);
    prev->r = NULL;
}

// 搜寻先序遍历的后置节点
pNode SearchForNext(pNode T) {
    pNode p = T;
    if(!p->rtag && !p->ltag) return p->l;
    else return p->r;
}

void SearchFromTag(pNode T, void (*visit) (pNode)) {
    pNode p = T;
    while(p) {
        visit(p); 
        p = SearchForNext(p);
    }
}
