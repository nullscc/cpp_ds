#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 10

typedef struct {
	array<int, MAXSIZE> l;
	int head;
	int tail;
}Queue;

void Init(Queue &Q) {
	Q.head = 0;
	Q.tail = 1;
}

bool IsEmpty(Queue &Q) {
	return ((Q.head%MAXSIZE) + 1) == Q.tail;
}

bool IsFull(Queue &Q) {
	return Q.tail == Q.head;
}

bool Push(Queue &Q, int e) {
	if(IsFull(Q)) return false;

	Q.l.at(Q.tail) = e;	
	Q.tail = (Q.tail + 1) % MAXSIZE;
	return true;
}

pair<bool, int> Pop(Queue &Q) {
	if(IsEmpty(Q)) return {false, 0};

	Q.head = (Q.head + 1) % MAXSIZE;
	return {true, Q.l.at(Q.head)};
}

int GetTop(Queue &Q) {
	return Q.l.at((Q.head + 1) % MAXSIZE);
}

int main() {
	Queue Q;
	Init(Q);
	cout<<"空的吗:"<<IsEmpty(Q)<<endl;

	Push(Q, 100);
	cout<<"top:"<<GetTop(Q)<<endl;
	cout<<"空的吗:"<<IsEmpty(Q)<<endl;
	Pop(Q);
	cout<<"空的吗:"<<IsEmpty(Q)<<endl;

	int i;
	for(i=1; i<10; i++) {
		Push(Q, i);
	}
	cout<<"空的吗:"<<IsEmpty(Q)<<endl;
	cout<<"满的吗:"<<IsFull(Q)<<endl;
	cout<<"Q.head:"<<Q.head<<endl;
	cout<<"Q.tail:"<<Q.tail<<endl;
	Pop(Q);
	cout<<"Q.head:"<<Q.head<<endl;
	cout<<"Q.tail:"<<Q.tail<<endl;
	cout<<"满的吗:"<<IsFull(Q)<<endl;
	Push(Q, 900);
	cout<<"空的吗:"<<IsEmpty(Q)<<endl;
	cout<<"满的吗:"<<IsFull(Q)<<endl;
	Pop(Q);
	Push(Q, 1000);
	
	for(auto i: Q.l) {
		cout<<i<<endl;
	}

	return 0;
}
