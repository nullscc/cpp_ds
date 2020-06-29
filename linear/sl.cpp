#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
	int e;
	int next;
}Node;

typedef struct {
	vector<Node> l;
	int ssize;
}Sl;

void Init(Sl &sl) {
	sl.l.push_back(Node({0, 0}));
	sl.l.push_back(Node{0, 2});
	sl.l.push_back(Node{0, 0});
	sl.ssize = 0;
}

int Malloc(Sl &sl) {
	int r = sl.l.at(1).next;
	if(!sl.l.at(r).next) {
		sl.l.push_back(Node{0, 0});
		sl.l.at(1).next = sl.l.size()-1;
		
	} else {
		sl.l.at(1).next = sl.l.at(r).next;
	}
	return r;
}

bool Free(Sl &sl, int i) {
	if(i<2 || i>(sl.l.size()-1)) return false;
	sl.l.at(i).next = sl.l.at(1).next;
	sl.l.at(1).next = i;
	return true;
}

bool Insert(Sl &sl, int i, int e) {
	if(i>(sl.ssize+1)) {
		return false;
	}

	int mi = Malloc(sl);
	sl.l.at(mi).e = e;
	sl.l.at(mi).next = 0;

	int j=1;
	Node *p = &sl.l.at(0);
	while(j<i) {
		p = &sl.l.at((*p).next);
		j++;
	}
	sl.l.at(mi).next = (*p).next;
	(*p).next = mi;

	sl.ssize += 1;
	return true;
}

pair<bool, int> Delete(Sl &sl, int i) {
	if(i>(sl.ssize)) {
		return {false, 0};
	}

	int j=1;
	Node *p = &sl.l.at(0);
	while(j<i) {
		p = &sl.l.at((*p).next);
		j++;
	}
	int bk = (*p).next;
	(*p).next = sl.l.at((*p).next).next;
	Free(sl, bk);
	return {true, sl.l.at(bk).e};
}

int main() {
	Sl sl;
	Init(sl);

	int i;
	for(i=0; i<10; i++) {
		Insert(sl, i+1, i+1);
	}
	Node *p = &sl.l.at(0);
	cout<<"顺序插入结果:"<<endl;
	while((*p).next) {
		cout<<sl.l.at((*p).next).e<<endl;
		p = &sl.l.at((*p).next);
	}
	cout<<endl;

	cout<<"中间插入100:"<<endl;
	Insert(sl, 2, 100);
	p = &sl.l.at(0);
	while((*p).next) {
		cout<<sl.l.at((*p).next).e<<endl;
		p = &sl.l.at((*p).next);
	}

	cout<<endl;
	cout<<"删除第3个:"<<endl;
	Delete(sl, 3);
	p = &sl.l.at(0);
	while((*p).next) {
		cout<<sl.l.at((*p).next).e<<endl;
		p = &sl.l.at((*p).next);
	}

	return 0;
}
