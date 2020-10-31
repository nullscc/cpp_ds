// 顺序表实现

#include<iostream>

#define MAX 100
typedef int TYPE;

typedef struct {
    TYPE l[MAX];
	int len;
	int cap;
}SQ, *pSQ;

void Init(SQ &L) {
    L.len = 0;
    L.cap = MAX;
}

int Insert(SQ &L, int i, int e) {
    if(i<1 || i>L.len+1 || L.len>=L.cap) return -1;

    int j=L.len;
    for(; j>=i; j--) {
        L.l[j] = L.l[j-1];
    }
    L.l[i-1] = e;
    L.len++;
	return 0;
}

TYPE Delete(SQ &L, int i) {
    if(i<=0 || i>L.len) return -1;

    TYPE ret = L.l[i-1];

    int j=i-1;
    for(; j<L.len-1; j++) {
    
        L.l[j] = L.l[j+1];
    }

    L.len--;
    return ret;
}

int Search(SQ &L, int e) {
    int i = 0;
    for(; i<L.len; i++) {
        if(L.l[i] == e) return i;
    }
    return 0;
}
