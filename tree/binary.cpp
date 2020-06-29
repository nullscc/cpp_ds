#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
	Node *lchild;
	Node *rchild;
	char e;
}Node;

void create(Node * &p) {
	Node *r;
	char ch;
	cin>>ch;
	if(ch == ' ') {
		p = NULL;
	} else {
		p = new Node;
		p->e = ch;
		create(p->lchild);
		create(p->rchild);
	}
}

void mid_recursive(Node *T) {
	if(!T) return;
	mid_recursive(T->lchild);
	cout<<T->e;
	mid_recursive(T->rchild);
}
void pre_recursive(Node *T) {
	if(!T) return;
	cout<<T->e;
	pre_recursive(T->lchild);
	pre_recursive(T->rchild);
}

void post_recursive(Node *T) {
	if(!T) return;
	post_recursive(T->lchild);
	post_recursive(T->rchild);
	cout<<T->e;
}

void mid(Node *T) {
	stack<Node *>s;
	auto p = T;
	while(p || !s.empty()) {
		if(p) {
			s.push(p);
			p = p->lchild;
		} else {
			p = s.top();
			s.pop();
			cout<<p->e;
			p = p->rchild;
		}
	}
}

void pre(Node *T) {
	stack<Node *>s;
	auto p = T;
	while(p || !s.empty()) {
		if(p) {
			cout<<p->e;
			s.push(p);
			p = p->lchild;
		} else {
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

void post(Node *T) {
	stack<Node *>s;
	auto p = T;
	Node *record=NULL;
	while(p || !s.empty()) {
		if(p) {
			s.push(p);
			p = p->lchild;
		} else {
			p = s.top();
			if(p->rchild && p->rchild != record) {
				s.push(p->rchild);
				p = p->rchild->lchild;
			} else {
				cout<<p->e;
				s.pop();
				record = p;
				p = NULL;
			}
		}
	}
}

void level(Node *T) {
	queue<Node *> q;
	q.push(T);
	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		cout<<p->e;
		if(p->lchild) q.push(p->lchild);
		if(p->rchild) q.push(p->rchild);
	}
}

// 数据使用《数据结构（C语言版）》 p129
int main() {
	cin>>noskipws;
	Node *root=NULL;
	create(root);
	cout<<"中序遍历结果:";
	mid_recursive(root);
	cout<<endl;

	cout<<"先序遍历结果:";
	pre_recursive(root);
	cout<<endl;

	cout<<"后序遍历结果:";
	post_recursive(root);
	cout<<endl;

	cout<<"非递归中序遍历结果:";
	mid(root);
	cout<<endl;

	cout<<"非递归先序遍历结果:";
	pre(root);
	cout<<endl;

	cout<<"非递归后序遍历结果:";
	post(root);
	cout<<endl;

	cout<<"层序遍历结果:";
	level(root);
	cout<<endl;


	return 0;
}
