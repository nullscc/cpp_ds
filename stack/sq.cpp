#include<bits/stdc++.h>

using namespace std;

typedef struct {
	vector<int> l;
	int top;
}Stack;

void Init(Stack &s) {
	s.top = 0;
}

bool IsEmpty(Stack &s) {
	return s.top <= 0;
}

pair<bool, int> GetTop(Stack &s) {
	if(IsEmpty(s)) return {false, 0};

	return {true, s.l.at(s.top - 1)};
}

void Push(Stack &s, int e) {
	auto len = s.l.size();
	if(len<=s.top) {
		s.l.push_back(e);
		s.top = len+1;
	} else {
		s.l.at(s.top++) = e;
	}
}

pair<bool, int> Pop(Stack &s) {
	if(IsEmpty(s)) return {false, 0};
	
	s.top--;
	return {true, s.l.at(s.top)};
}


int main() {
	Stack S;
	Init(S);
	cout<<"空的吗?:"<<IsEmpty(S)<<endl;
	Push(S, 100);
	cout<<"空的吗?:"<<IsEmpty(S)<<endl;
	auto r = GetTop(S);
	cout<<"Top:"<<r.second<<endl;

	Push(S, 200);
	Push(S, 300);
	Push(S, 400);
	r = GetTop(S);
	cout<<"Top:"<<r.second<<endl;

	r = Pop(S);
	cout<<"Pop:"<<r.second<<endl;

	r = GetTop(S);
	cout<<"Top:"<<r.second<<endl;
	while(!IsEmpty(S)) {
		Pop(S);
	}
	r = GetTop(S);
	cout<<"Top:"<<r.first<<endl;
	return 0;
}
