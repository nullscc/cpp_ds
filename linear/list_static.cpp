// 静态链表实现

#include<iostream>
#include<cassert>

#define MAX 1000

typedef int TYPE;

typedef struct {
    TYPE data;   // 数据域
    int next;   // 指针域
}Elem;

typedef struct {
    int cap;
    int len;
    Elem l[MAX];
}SL, pSL;

int Init(SL &L) {
    L.cap = MAX - 2;
    L.len = 0;

    int i;
    L.l[0].next = 2;
    for(i=2; i<MAX-1; i++) {
        L.l[i].next = i+1;
    }
    L.l[MAX-1].next = 0;
    
    L.l[1].next = 0;
    return 0;
}

int Malloc(SL &L) {
    int ret;
    ret = L.l[0].next;
    assert(ret==0 || ret>=2);
    if (ret) {
        L.l[0].next = L.l[ret].next;
        L.len++;
    }
    return ret;
}

// 这里的p就是数组下标
int Free(SL &L, int p) {
    assert(p<L.cap && p>1);
    int ret = L.l[p].data;

    L.l[p].next = L.l[0].next;
    L.l[0].next = p;
    L.len--;

    return ret;
}

int Insert(SL &L, int i, TYPE e) {
    if(i<1 || i>L.len+1) return -1;

    int j=1;
    int next = 1;
    for(; j<=i-1; j++) {
        next = L.l[next].next;
    }

    int n_index = Malloc(L);
    L.l[n_index].data = e;
    L.l[n_index].next = L.l[next].next;
    L.l[next].next = n_index;

    return n_index;
}

int Insert_head(SL &L, TYPE e) {
    if(L.len >= L.cap) return -1;

    int n_index = Malloc(L);
    
    L.l[n_index].next = L.l[1].next;
    L.l[1].next = n_index;
    L.l[n_index].data = e;

    return 0;
}

TYPE Delete(SL &L, int i) {
    if(i<1 || i>L.len) return -1;

    int j=1;
    int next = 1;
    for(; j<=i-1; j++) {
        next = L.l[next].next;
    }
    int tmp_next = L.l[next].next;
    TYPE ret = L.l[tmp_next].data;
    L.l[next].next = L.l[L.l[next].next].next;
    Free(L, tmp_next);

    return ret;
}

// 第i个元素的数组下标
int Search_index(SL &L, int i) {
    if(i<1 || i>L.len) return -1;

    int j=1;
    int next = 1;
    for(; j<=i; j++) {
        next = L.l[next].next;
    }
    return L.l[next].data;
}

// 第1个元素等于e的数组下标
int Search_data(SL &L, TYPE e) {
    int j=1;
    int next = 1;
    for(; j<=L.len; j++) {
        next = L.l[next].next;
        if(L.l[next].data == e) return next;
    }
    return 0;
}
