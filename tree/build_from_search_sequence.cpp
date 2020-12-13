// 从先序(A)和中序(B)建立二叉树

#include <iostream>
#include <cassert>

typedef char TYPE;

typedef struct Node {
    Node *l;
    Node *r;
    TYPE e;
}Node, *pNode;

void Build(pNode &T, char *A, int i, int j, char *B, int m, int n) {
    if(j<i) return;
    std::cout<<i<<" "<<j<<std::endl;
    assert((j-i) == (n-m));
    T = new Node;
    T->e = A[i];
    T->l = T->r = NULL;

    if(i==j) {
        return;
    }
    
    int k;
    for(k=m; k<=n; k++) {
        if(B[k] == A[i]) break;
    }
    
    Build(T->l, A, i+1, i+k-m, B, m, k-1);
    Build(T->r, A, i+k-m+1, j, B, k+1, n);
}

void MidSearch(pNode T, void (*visit) (pNode)) {
    if(!T) return;

    MidSearch(T->l, visit);
    visit(T);
    MidSearch(T->r, visit);

}
