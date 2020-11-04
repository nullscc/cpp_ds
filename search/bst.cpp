// 二叉查找树

#include <iostream>
#include <cassert>

typedef int TYPE;

typedef struct Node{
    Node *l;
    Node *r;
    TYPE e;
}Node, *pNode;

pNode Insert(pNode &T, TYPE e) {
    if(!T) {
        T = new Node;
        T->e = e;
        T->l = T->r = NULL;
        return T;
    }

    pNode ret = NULL;
    if(e == T->e) return NULL;
    if(e > T->e) return Insert(T->r, e);
    else return Insert(T->l, e);
}

pNode Build(TYPE *l, int n) {
    if(n < 1) {
        return NULL;
    }

    pNode p, T = NULL;
    int i;
    for(i=0; i<n; i++) {
        p = Insert(T, l[i]);
        assert(p->e == l[i]);
    }
    return T;
}

pNode InsertNonrecusive(pNode T, TYPE e) {
    if(!T) return NULL;

    pNode p = T;
    pNode prev = NULL;
    while(p) {
        if(e == p->e) return NULL;

        prev = p;
        if(e > p->e) {
            p = p->r;
        } else {
            p = p->l;
        }
    }

    pNode ret = new Node;
    ret->e = e;
    ret->r = ret->l = NULL;
    if(e > prev->e) {
        prev->r = ret;
    } else {
        prev->l = ret;
    }
    return ret;
}

// 构建不带头结点的二叉查找树，貌似带头结点还不好办一些
pNode BuildNonrecursive(TYPE *l, int n) {
    if(n < 1) return NULL;

    pNode T = new Node;
    T->l = T->r = NULL;
    T->e = l[0];

    pNode p = T;
    int i;
    for(i=1; i<n; i++) {
        p = InsertNonrecusive(T, l[i]);
        assert(p);
    }
    return T;
}

int Delete(pNode &T, TYPE e) {
    if(!T) return -1;
    
    if(e < T->e) return Delete(T->l, e);
    if(e > T->e) return Delete(T->r, e);
    else {
        pNode del = NULL;
        if(!T->l) {
            del = T;
            T = T->r;
            delete del;
        } else if(!T->r) {
            del = T;
            T = NULL;
            delete del;
        } else {
            pNode p = T->r;
            pNode prev = p;
            while(p->l) {
                prev = p;
                p = p->l;
            }
            T->e = p->e;
            return Delete(prev, p->e);
        }
        return 0;
    }
}

pNode Search(pNode T, TYPE e) {
    if(!T) return NULL;
    
    if(e < T->e) return Search(T->l, e);
    else if(e > T->e) return Search(T->r, e);
    else return T;
}

// TODO: 非递归的删除和搜索
