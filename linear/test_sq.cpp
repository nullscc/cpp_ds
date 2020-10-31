// 顺序表实现的测试

#include<iostream>
#include "sq.cpp"
#include <cassert>

using namespace std;

int main() {
	SQ L;
	
    // 初始化
	Init(L);
	assert(MAX==L.cap);
	assert(!L.len);
	
	int i=1;
	for (; i<=10; i++) {
		assert(!Insert(L, L.len+1, i));
	}
	cout<<"插入10个元素后，顺序表里面的数据为:";
	for (i=1; i<=L.len; i++) {
		cout<<L.l[i-1]<<" ";
	}
    cout<<endl;

	assert(L.cap==MAX);
	assert(L.len==10);
	
	for (i=1; i<=L.len; i++) {
		assert(Search(L, i)==i-1);
	}
	
	assert(!Insert(L, 9, 8));
	cout<<"在9的位置上插入8后:";
	for (i=1; i<=L.len; i++) {
        cout<<L.l[i-1]<<" ";
	}
    cout<<endl;
	assert(L.len==11);
	
	//删除9上的8
	TYPE tmp = Delete(L, 9);
	assert(tmp);
	assert(tmp == 8);
	assert(L.len==10);
	cout<<"删除9上的8后，动态数组里面的数据为:";
	for (i=1; i<=L.len; i++) {
        cout<<L.l[i-1]<<" ";
	}
    cout<<endl;

	return 0;
}

