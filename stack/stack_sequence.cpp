// 栈的顺序实现

#include <iostream>

#define MAX 10
typedef int TYPE;

typedef struct {
    int top;
    int len;
    int cap;
    TYPE s[MAX];
}Stack, pStack;

int Init(Stack &S) {
    S.top = 0;
    S.len = 0;
    S.cap = MAX;

    return 0;
}

int IsEmpty(Stack &S) {
    return S.len == 0;
}

int IsFull(Stack &S) {
    return (S.top>=MAX || S.len>=MAX);
}

int GetTop(Stack &S, TYPE &e) {
    if(IsEmpty(S)) return -1;

    e = S.s[S.top-1];

    return 0;
}

int GetLen(Stack &S) {
    return S.len;
}

int Push(Stack &S, TYPE e) {
    if(IsFull(S)) return -1;

    S.s[S.top++] = e;
    S.len++;

    return 0;
}

int Pop(Stack &S, TYPE &e) {
    if(IsEmpty(S)) return -1;

    e = S.s[--S.top];
    S.len--;

    return 0;
}

int Clear(Stack &S) {
    S.len = 0;
    S.top = 0;
    return 0;
}
