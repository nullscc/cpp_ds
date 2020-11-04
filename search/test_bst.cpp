#include <iostream>
#include <cassert>
#include "bst.cpp"

using namespace std;

void MidSearch(pNode T){
    if(!T) return;

    MidSearch(T->l);
    cout<<T->e;
    MidSearch(T->r);

}

int main() {
    int i;
    pNode p;
    int l[] = {4, 6, 2, 1, 3, 5, 7};
    pNode T = Build(l, 7);
    cout<<"递归方式创建二叉查找树后中序搜索二叉树结果:";
    MidSearch(T);
    cout<<endl;

    pNode T_nonr = BuildNonrecursive(l, 7);
    cout<<"非递归方式创建二叉查找树后中序搜索二叉树结果:";
    MidSearch(T_nonr);
    cout<<endl;

    for(i=1; i<8; i++) {
        p = Search(T, i);
        assert(p);
        assert(p->e);
    }
    assert(!Search(T, 10));

    assert(!Delete(T, 4));
    assert(T->e == 5);
    cout<<"二叉查找树删除4后中序搜索二叉树结果:";
    MidSearch(T);
    cout<<endl;

    assert(!Delete(T, 7));
    assert(T->e == 5);
    cout<<"二叉查找树删除4后中序搜索二叉树结果:";
    MidSearch(T);
    cout<<endl;

    return 0;
}
