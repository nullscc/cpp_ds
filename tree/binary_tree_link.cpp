// 二叉树的链表实现

#include <iostream>
#include <cassert>
#include <queue>

typedef char TYPE;

typedef struct Node {
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
        T = pn_node;
        
        assert(!Build(T->l));
        assert(!Build(T->r));
    }

    return 0;
}

void MidSearch(pNode T, void (*visit)(pNode)) {
    if(!T) return;

    MidSearch(T->l, visit);
    visit(T);
    MidSearch(T->r, visit);

}

void PreSearch(pNode T, void (*visit)(pNode)) {
    if(!T) return;

    visit(T);
    PreSearch(T->l, visit);
    PreSearch(T->r, visit);
}

void PostSearch(pNode T, void (*visit)(pNode)) {
    if(!T) return;

    PostSearch(T->l, visit);
    PostSearch(T->r, visit);
    visit(T);
}

void LevelSearch(pNode T, void (*visit)(pNode)) {
    if(!T) return;

    std::queue<pNode> q;

    pNode p = T;
    q.push(p);
    while(!q.empty()) {
        p = q.front();
        q.pop();
        
        // std::cout<<p<<std::endl;
        visit(p);
        
        if(p->l) q.push(p->l);
        if(p->r) q.push(p->r);
    }

}
