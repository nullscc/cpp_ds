// 循环队列实现

#define MAX 11
typedef int TYPE;

typedef struct {
    int cap;
    int t;
    int h;
    TYPE l[MAX];
}Q, *pQ;

int Init(Q &Q) {
    Q.h = Q.t = 0;
    Q.cap = MAX - 1;
    return 0;
}

int IsEmpty(Q &Q) {
    return Q.h == Q.t;
}

int IsFull(Q &Q) {
    return ((Q.t + 1) % (Q.cap + 1)) == Q.h;
}

int EnQueue(Q &Q, TYPE e) {
    if(IsFull(Q)) return -1;

    Q.l[Q.t] = e;
    Q.t = (Q.t + 1) % (Q.cap + 1);

    return 0;
}

int DeQueue(Q &Q, TYPE &e) {
    if(IsEmpty(Q)) return -1;

    e = Q.l[Q.h];
    Q.l[Q.h] = 255;     // for debug
    Q.h = (Q.h + 1) % (Q.cap + 1);
    return 0;
}

int GetLen(Q &Q) {
    return (Q.t - Q.h + Q.cap + 1) % (Q.cap + 1);
}
