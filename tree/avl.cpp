#include<bits/stdc++.h>

using namespace std;

#define EH 0
#define LH 1
#define RH -1

typedef struct Node{
	Node *lchild;
	Node *rchild;
	int bf;
	int e;
}Node;

void r_rotate(Node * &T) {
	Node *L = T->lchild;
	Node *LR = L->rchild;
	Node *R = T->rchild;
	L->rchild = T;
	T->lchild = LR;
	T = L;
}

void l_rotate(Node * &T) {
	Node *L = T->lchild;
	Node *R = T->rchild;
	Node *RL = R->lchild;
	R->lchild = T;
	T->rchild = RL;
	T = R;
}

void left_balance(Node * &T) {
	Node *L = T->lchild;
	switch(L->bf) {
		case LH:
			L->bf = T->bf = EH;
			r_rotate(T);
			break;
		case RH:
			Node *LR = L->rchild;
			switch(LR->bf) {
				case LH:
					L->bf = EH;
					T->bf = RH;
					break;
				case RH:
					T->bf = EH;
					L->bf = LH;
					break;
				case EH:
					L->bf = T->bf = EH;
					break;
			}
			l_rotate(T->lchild);
			r_rotate(T);
			break;
	}
}

void right_balance(Node *&T) {
	Node *R = T->rchild;
	switch(R->bf) {
		case RH:
			R->bf = T->bf = EH;
			l_rotate(T);
			break;
		case LH:
			Node *RL = R->lchild;
			switch(RL->bf) {
				case LH:
					T->bf = EH;
					R->bf = RH;
					break;
				case RH:
					T->bf = LH;
					R->bf = EH;
					break;
				case EH:
					R->bf = T->bf = EH;
					break;
			}
			r_rotate(T->rchild);
			l_rotate(T);
			break;
	}
}

bool insert(Node *&T, int e) {
	if(!T) {
		T = new Node;
		T->bf = EH;
		T->e = e;
		T->lchild = NULL;
		T->rchild = NULL;
		return true;
	}
	
	if(e == T->e) return false;
	
	if(e < T->e) {
		bool taller = insert(T->lchild, e);
		if(taller) {
			switch(T->bf) {
				case EH:
					T->bf = LH;
					return true;
				case LH:
					left_balance(T);
					return false;
				case RH:
					T->bf = EH;
					return false;
			}
		}
	} else {
		bool taller = insert(T->rchild, e);
		if(taller) {
			switch(T->bf) {
				case EH:
					T->bf = RH;
					return true;
				case LH:
					T->bf = EH;
					return false;
				case RH:
					right_balance(T);
					return false;
			}
		}
	
	}
	return false;
}

void mid_recursive(Node *T) {
	if(!T) return;
	mid_recursive(T->lchild);
	cout<<T->e<<" ";
	mid_recursive(T->rchild);
}


int main() {
	Node *T = NULL;
	int i;
	array<int, 10> a = {3,2,1,4,5,6,7,10,9,8};
	for(i=0; i<10; i++) {
		insert(T, a[i]);
	}
	cout<<"根结点:"<<T->e<<endl;

	cout<<"中序遍历结果:";
	mid_recursive(T);
	cout<<endl;
	return 0;
}
