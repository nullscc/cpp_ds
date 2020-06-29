#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
	int e;
	Node *next;
}Node;

void Init(Node &l) {
	l.next = NULL;
}

bool IsEmpty(Node &l) {
	return !l.next;
}

void Insert(Node &l, int i, int e) {
	Node *pnode = new Node;
	pnode->e = e;
	pnode->next = NULL;
	
	int j=1;
	Node *p = &l;
	while(j<i) {
		p = p->next;
		j++;
	}

	pnode->next = p->next;
	p->next = pnode;
}

pair<bool, int> Delete(Node &l, int i) {
	int j=1;
	Node *p = &l;
	while(p && j<i) {
		p = p->next;
		j++;
	}

	if(i != j) return {false, 0};

	if(!p->next) {
		return {false, 0};
	}
	
	auto bk = p->next;
	p->next = p->next->next;
	
	int v = bk->e;
	delete bk;
	return {true, v};
}

int Locate(Node &l, int e) {
	auto p = l.next;
	int i = 0;
	while(p) {
		i++;
		if(p->e == e) break;
		p = p->next;
	}
	return i;
}


int main() {
	Node s;
	Init(s);
	cout<<IsEmpty(s)<<endl<<endl;;
	int i;
	for(i=0; i<10; i++) {
		Insert(s, i+1, i);
	}
	cout<<"顺序插入后结果:"<<endl<<endl;
	auto p = s.next;
	while(p) {
		cout<<p->e<<endl;
		p = p->next;
	}
	Insert(s, 2, 100);

	cout<<"中间插入后结果:"<<endl<<endl;
	p = s.next;
	while(p) {
		cout<<p->e<<endl;
		p = p->next;
	}
	
	auto r = Delete(s, 2);
	cout<<"删除100结果:"<<r.first<<" "<<r.second<<endl<<endl;
	
	cout<<"删除后结果:"<<endl;
	p = s.next;
	while(p) {
		cout<<p->e<<endl;
		p = p->next;
	}

	cout<<"1所在的位序为:"<<Locate(s, 1)<<endl<<endl;;
	return 0;
}
