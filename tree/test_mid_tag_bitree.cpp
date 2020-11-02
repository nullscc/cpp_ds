// 二叉树的测试程序有点麻烦，还是用肉眼看吧...
// 数据为'-+a  *b  -c  d  /e  f   '
// 在命令行中 echo "-+a  *b  -c  d  /e  f   " | a.out 即可
// 此数据的先序遍历为:-+a*b-cd/ef 
//         中序遍历为:a+b*c-d-e/f
//         后序遍历为:abcd-*+ef/-
//         层次遍历为:-+/a*efb-cd
#include <iostream>
#include <cassert>

#include "mid_tag_bitree.cpp"

using namespace std;

void visit(pNode p) {
    cout<<p->e;
}

int main() {
    pNode T = NULL;
    Build(T);
    BuildTag(T);
    cout<<"中序线索二叉树遍历结果:";
    SearchFromTag(T, visit);
    cout<<endl;
}
