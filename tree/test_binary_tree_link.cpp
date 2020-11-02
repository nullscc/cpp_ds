// 二叉树的测试程序有点麻烦，还是用肉眼看吧...
// 数据为'-+a  *b  -c  d  /e  f   '
// 在命令行中 echo "-+a  *b  -c  d  /e  f   " | a.out 即可
// 此数据的先序遍历为:-+a*b-cd/ef 
//         中序遍历为:a+b*c-d-e/f
//         后序遍历为:abcd-*+ef/-
//         层次遍历为:-+/a*efb-cd
#include <iostream>
#include <cassert>

#include "binary_tree_link.cpp"

using namespace std;

void visit(pNode p) {
    cout<<p->e;
}

int main() {
    pNode p = NULL;
    Build(p);

    cout<<"中序遍历结果:";
    MidSearch(p, visit);
    cout<<endl;
    cout<<"非递归中序遍历结果:";
    MidSearch_NonRecursive(p, visit);
    cout<<endl;


    cout<<"先序遍历结果:";
    PreSearch(p, visit);
    cout<<endl;
    cout<<"非递归先序遍历结果:";
    PreSearch_NonRecursive(p, visit);
    cout<<endl;
    
    cout<<"后序遍历结果:";
    PostSearch(p, visit);
    cout<<endl;
    cout<<"非递归后序遍历结果:";
    PostSearch_NonRecursive(p, visit);
    cout<<endl;

    cout<<"层次遍历结果:";
    LevelSearch(p, visit);
    cout<<endl;

    return 0;
}
