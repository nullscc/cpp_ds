#include<bits/stdc++.h>

using namespace std;

typedef struct Node{
	Node *lchild;
	Node *rchild;
	int e;
}Node;

void insert(Node *&T, int e) {
	if(!T) {
		T = new Node;
		T->lchild = NULL;
		T->rchild = NULL;
		T->e = e;
		return;
	}

	if(e == T->e) {
		return;
	}
	if(e < T->e) insert(T->lchild, e);
	else insert(T->rchild, e);
}

void delete_node(Node *&T, int e) {
	if(!T) return;

	if(e==T->e) {
		if(!T->rchild) {
			Node *tmp = T;
			T = T->lchild;
			delete tmp;
		} else if(!T->lchild) {
			Node *tmp = T;
			T = T->rchild;
			delete tmp;
		} else {
			Node *tmp = T;			// NOTE: tmp是双亲
			Node *after = T->rchild;
			while(after->lchild) {
				tmp = after;
				after = after->lchild;
			}
			int a = after->e;
			delete_node(tmp, a);
			T->e = a;
		}
		return;
	}
	if(e < T->e) delete_node(T->lchild, e);
	else delete_node(T->rchild, e);
}

void mid_recursive(Node *T) {
	if(!T) return;
	mid_recursive(T->lchild);
	cout<<T->e<<" ";
	mid_recursive(T->rchild);
}

int main() {
	array<int, 10> a = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
	int i;
	Node *T=NULL;
	for(i=0; i<10; i++) {
		insert(T, a[i]);
	}

	cout<<"创建排序树完成以后的数据:";
	mid_recursive(T);
	cout<<endl;

	delete_node(T, 62);
	cout<<T->e<<endl;
	cout<<"删除62以后的数据:";
	mid_recursive(T);
	cout<<endl;

}
