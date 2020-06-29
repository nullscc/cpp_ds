#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	int e;
	Node *next;
}Node;

typedef struct {
	Node *tail;
	Node *head;
}Queue;



void Init(Queue &Q) {
	Q.head = new Node;
	Q.tail = NULL;
}

bool IsEmpty(Queue &Q) {
	return !Q.tail;
}

void Push(Queue &Q, int e) {
	auto pnode = new Node;
	pnode->e = e;
	pnode->next = NULL;
	if (Q.tail) {
		Q.tail->next = pnode;
	} else {
		Q.head->next = pnode;
	}
	Q.tail = pnode;
}

pair<bool, int> Pop(Queue &Q) {
	if (IsEmpty(Q)) return {false, 0};
	
	Node *bk = Q.head->next;
	Q.head->next = Q.head->next->next;

	if(!Q.head->next) Q.tail = NULL;

	int e = bk->e;
	delete bk;

	return {true, e};
}

int GetTop(Queue &Q) {
	return Q.head->next->e;
}

int main() {
	Queue Q;
	Init(Q);

	cout<<"空的吗:"<<IsEmpty(Q)<<endl;
	Push(Q, 100);
	cout<<"top:"<<GetTop(Q)<<endl;
	Push(Q, 200);
	cout<<"top:"<<GetTop(Q)<<endl;
	auto r = Pop(Q);
	cout<<"pop:"<<r.second<<endl;
	cout<<"top:"<<GetTop(Q)<<endl;
	Pop(Q);
	cout<<"空的吗:"<<IsEmpty(Q)<<endl;
	int i;
	for(i=0; i<10; i++) {
		Push(Q, i+1);
	}

	auto p = Q.head->next;
	while(p) {
		cout<<p->e<<endl;
		p = p->next;
	}

	return 0;
}
