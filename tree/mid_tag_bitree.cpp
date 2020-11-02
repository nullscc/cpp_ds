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

void MidSearch(pNode T, pNode &prev) {
    if(!T) return;


    if(!T->ltag) MidSearch(T->l, prev);

    if(prev && !prev->r) {
        prev->r = T;
        prev->rtag = true;
    }
    if(!T->l) {
        T->l = prev;
        T->ltag = true;
    }

    prev = T;
    if(!T->rtag) MidSearch(T->r, prev);
}

void BuildTag(pNode T) {
    pNode prev = NULL;
    MidSearch(T, prev);
    prev->r = NULL;
}

pNode SearchMostLeft(pNode T) {
    if(!T) return NULL;

    pNode p = T;
    while(!p->ltag) {
        p = p->l;
    }
    return p;
}

// 搜寻中序遍历的后置节点
pNode SearchForNext(pNode T) {
    if(!T->rtag) return SearchMostLeft(T->r);
    else return T->r;
}

void SearchFromTag(pNode T, void (*visit) (pNode)) {
    if(!T) return;

    pNode p = SearchMostLeft(T);
    while(p) {
        visit(p); 
        p = SearchForNext(p);
    }
}
