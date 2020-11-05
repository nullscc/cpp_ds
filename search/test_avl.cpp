#include <iostream>
#include <cassert>
#include "avl.cpp"

using namespace std;

void MidSearch(pNode T){
    if(!T) return;

    MidSearch(T->l);
    cout<<T->e<<" ";
    MidSearch(T->r);

}
int main() {
	pNode T = NULL;
	int i;
	int l[10] = {3,2,1,4,5,6,7,10,9,8};
	for(i=0; i<10; i++) {
		assert(Insert(T, l[i]) != -1);
	}
	assert(T->e == 4);

	cout<<"中序遍历结果:";
	MidSearch(T);
    cout<<endl;
	return 0;
}
