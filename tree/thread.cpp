#include<bits/stdc++.h>

using namespace std;

typedef struct Node {
	char e;
	Node *lchild;
	Node *rchild;
	bool ltag;
	bool rtag;
}Node;

void create(Node * &p) {
	char ch;
	cin>>ch;
	if(ch == ' ') {
		p = NULL;
	} else {
		p = new Node;
		p->e = ch;
		p->ltag = false;
		p->rtag = false;
		create(p->lchild);
		create(p->rchild);
	}
}

void build_thread_recursive(Node *T, Node * &pre) {
	if(!T) return;

	build_thread_recursive(T->lchild, pre);
	
	if(pre && !pre->rchild) {
		pre->rchild = T;
		pre->rtag = true;
	}
	if(!T->lchild) {
		T->lchild = pre;
		T->ltag = true;
	}
	pre = T;

	build_thread_recursive(T->rchild, pre);
}

void f_build_thread_recursive(Node *T) {
	Node *pre = NULL;
	build_thread_recursive(T, pre);
	pre->rchild = NULL;
	pre->rtag = 1;
}

void build_thread(Node *T) {
	Node *p=T;
	Node *pre=NULL;
	stack<Node *> s;
	while(p || !s.empty()) {
		if(p) {
			s.push(p);
			p = p->lchild;
		} else {
			p = s.top();
			s.pop();

			if(pre && !pre->rchild) {
				pre->rchild = p;
				pre->rtag = true;
			}
			if(!p->lchild) {
				p->lchild = pre;
				p->ltag = true;
			}
			pre = p;
			p = p->rchild;
		}
	}
	pre->rchild = NULL;
	pre->rtag = true;
}

Node *build_thread_with_head(Node *T) {
	Node *head = new Node;
	head->ltag = false;
	head->rtag = true;
	head->lchild = T;

	Node *p=T;
	Node *pre=head;		// NOTE: 带头结点的这里设置为头即可
	stack<Node *> s;
	while(p || !s.empty()) {
		if(p) {
			s.push(p);
			p = p->lchild;
		} else {
			p = s.top();
			s.pop();

			if(pre && !pre->rchild) {
				pre->rchild = p;
				pre->rtag = true;
			}
			if(!p->lchild) {
				p->lchild = pre;
				p->ltag = true;
			}

			pre = p;
			p = p->rchild;
		}
	}
	pre->rchild = head;
	pre->rtag = true;
	head->rchild = pre;
	head->rtag = true;
	return head;
}


Node *find_after(Node *T) {
	if(T->rtag) return T->rchild;
	
	Node *p = T->rchild;
	while(!p->ltag) {
		p = p->lchild;
	}
	return p;
}

Node *find_before(Node *T) {
	if(T->ltag) return T->lchild;
	
	Node *p = T->lchild;
	while(!p->rtag) {
		p = p->rchild;
	}
	return p;
}

// 从后往前搜索
void search_with_head_back(Node *head) {
	Node *p = find_after(head);
	while(p!=head) {
		cout<<p->e;
		p = find_before(p);
	}
	cout<<endl;
}
void search_with_head_front(Node *head) {
	Node *p = head->lchild;
	while(!p->ltag) {
		p = p->lchild;
	}
	while(p!=head) {
		cout<<p->e;
		p = find_after(p);
	}
	cout<<endl;
}


int main() {
	cin>>noskipws;
	Node *T, *pre=NULL;
	create(T);
	// build_thread(T);
	// f_build_thread_recursive(T);
	Node *head = build_thread_with_head(T);
	
	cout<<"前驱遍历结果为:";
	search_with_head_front(head);
	cout<<"后驱遍历结果为:";
	search_with_head_back(head);

	return 0;
}
