#include <iostream>

#define LH 1
#define RH -1
#define EH 0

typedef int TYPE;

typedef struct Node {
    Node *l;
    Node *r;
    int bf;
    TYPE e;
}Node, *pNode;

void R_Rotate(pNode &T) {
    pNode p = T->l;
    T->l = p->r;
    p->r = T;
    T = p;
}

void L_Rotate(pNode &T) {
    pNode p = T->r;
    T->r = p->l;
    p->l = T;
    T = p;
}

// 因左子树增高而调整左子树
void LeftBalance(pNode &T) {
    pNode tl = T->l;
    if(tl->bf == LH) {
        T->bf = tl->bf = EH;
        R_Rotate(T);
    } else {
        pNode tl_r = tl->r;
        switch(tl_r->bf) {
            case EH:
                T->bf = tl->bf = EH;
                break;
            case LH:
                tl_r->bf = EH;
                tl->bf = EH;
                T->bf = RH;
                break;
            case RH:
                tl_r->bf = EH;
                tl->bf = LH;
                T->bf = EH;
                break;
        }
        L_Rotate(T->l);
        R_Rotate(T);
    }
}

// 因右子树增高而调整右子树
void RightBalance(pNode &T) {
    pNode tr = T->r;
    if(tr->bf == RH) {
        T->bf = tr->bf = EH;
        L_Rotate(T);
    } else {
        pNode tr_l = tr->l;
        switch(tr_l->bf) {
            case EH:
                T->bf = tr->bf = EH;
                break;
            case LH:
                tr_l->bf = EH;
                tr->bf = RH;
                T->bf = EH;
                break;
            case RH:
                tr_l->bf = EH;
                tr->bf = EH;
                T->bf = LH;
                break;
        }
        R_Rotate(T->r);
        L_Rotate(T);
    }
}



// 返回值:
//      1: 长高了
//      0: 没有长高
//      -1: 因有相同值插入失败
int Insert(pNode &T, TYPE e) {
    if(!T) {
        T = new Node;
        T->e = e;
        T->l = T->r = (pNode)NULL;
        T->bf = 0;
        return 1;
    }
    
    if(e == T->e) return -1;

    int taller;
    if(e < T->e) {
        taller = Insert(T->l, e);
        if(taller <= 0)
            return taller;

        switch(T->bf) {
            case EH:
                T->bf = LH;
                return 1;
            case LH:
                // 左平衡操作
                LeftBalance(T);
                return 0;
            case RH:
                T->bf = EH;
                return 0;
            default:
                break;
        }
    } else {
        taller = Insert(T->r, e);
        if(taller <= 0)
            return taller;

        switch(T->bf) {
            case EH:
                T->bf = RH;
                return 1;
            case LH:
                T->bf = EH;
                return 0;
            case RH:
                // 右平衡操作
                RightBalance(T);
                T->bf = EH;
                return 0;
            default:
                break;
        }
    }
    return -1;
}
