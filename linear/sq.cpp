#include<bits/stdc++.h>

using namespace std;

typedef struct {
	vector<int> data;
	int end;
}Sq;

void Init(Sq &s) {
	s.end = 0;
}

bool IsEmpty(Sq &s) {
	return s.end == 0;
}

void Insert(Sq &s, int i, int e) {
	s.data.push_back(0);
	int j = i;
	for(j=s.end; j>=i; j--) {
		s.data.at(j) = s.data.at(j-1);
	}
	s.data.at(i-1) = e;
	s.end += 1;
}

pair<int, int> Delete(Sq &s, int i) {
	if (s.end == 0 || (i-1)>s.end) return {0, 0};
	int e = s.data.at(i-1);
	int j;
	for(j=i-1; j<s.end-1; j++) {
		s.data.at(j) = s.data.at(j+1);
	}
	s.end -= 1;
	return pair<int, int>(1, e);
}

int main() {
	Sq s;
	Init(s);
	cout<<IsEmpty(s)<<endl;
	int i;
	for(i=0; i<10; i++) {
		Insert(s, i+1, i);
	}
	cout<<"顺序插入后结果:"<<endl;
	for(i=0; i<s.end; i++) {
		cout<<s.data.at(i)<<endl;
	}
	cout<<"s.end:"<<s.end<<endl;
	Insert(s, 2, 100);

	cout<<"中间插入后结果:"<<endl;
	for(i=0; i<s.end; i++) {
		cout<<s.data.at(i)<<endl;
	}
	cout<<"s.end:"<<s.end<<endl;
	
	auto r = Delete(s, 2);
	cout<<"删除100结果:"<<r.first<<" "<<r.second<<endl;
	
	cout<<"删除后结果:"<<endl;
	for(i=0; i<s.end; i++) {
		cout<<s.data.at(i)<<endl;
	}
	cout<<"s.end:"<<s.end<<endl;

	return 0;
}
