#include<bits/stdc++.h>

using namespace std;
#define MAXSIZE 11

typedef struct {
	int weight;
	char e;
	int parent;
	int lchild;
	int rchild;
}Node;

typedef struct {
	array<Node, MAXSIZE+1> l;
	int n;
}HT;

pair<int, int> select(HT &ht) {
	int min;
	int i, j, m;
	min = INT_MAX;
	for(m=1; m<=MAXSIZE; m++) {
		if(ht.l.at(m).weight != -1 && ht.l.at(m).parent==0 && ht.l.at(m).weight<min) {
			min = ht.l.at(m).weight;
			i = m;
		}
	}
	min = INT_MAX;
	for(m=1; m<=MAXSIZE; m++) {
		if(ht.l.at(m).weight != -1 && ht.l.at(m).parent==0 && m != i && ht.l.at(m).weight<min) {
			min = ht.l.at(m).weight;
			j = m;
		}
	}

	return {i, j};
}

void init(HT &ht) {
	ht.n = 6;
	int i;
	int start = 97;
	for(i=1; i<MAXSIZE+1; i++) {
		ht.l.at(i).parent = 0;
		ht.l.at(i).lchild = 0;
		ht.l.at(i).rchild = 0;
		ht.l.at(i).weight = -1;
		if(start<='f') {
			ht.l.at(i).e = start;
			start++;
		} else {
			ht.l.at(i).e = 0;
		}
	}
	ht.l.at(1).weight = 45;
	ht.l.at(2).weight = 13;
	ht.l.at(3).weight = 12;
	ht.l.at(4).weight = 16;
	ht.l.at(5).weight = 9;
	ht.l.at(6).weight = 5;
}

void build(HT &ht) {
	int i;
	for(i=ht.n+1; i<=MAXSIZE; i++) {
		auto min_2 = select(ht);
		ht.l.at(min_2.first).parent = i;
		ht.l.at(min_2.second).parent = i;
		ht.l.at(i).lchild = min_2.first;
		ht.l.at(i).rchild = min_2.second;
		ht.l.at(i).weight = ht.l.at(min_2.first).weight + ht.l.at(min_2.second).weight; 
	}
}

map<char, string> encode(HT &ht) {
	map<char, string> r;
	int i;
	for(i=1; i<=ht.n; i++) {
		int parent = ht.l.at(i).parent;
		int child = i;
		r[ht.l.at(i).e] = string();
		while(parent) {
			if(ht.l.at(parent).lchild == child) {
				r[ht.l.at(i).e].push_back('0');
			} else {
				r[ht.l.at(i).e].push_back('1');
			}
			
			child = parent;
			parent = ht.l.at(parent).parent;
		}
		reverse(r[ht.l.at(i).e].begin(), r[ht.l.at(i).e].end());
	}

	return r;
}

char decode(HT &ht, string in) {
	int p = 11;
	for(auto ch: in) {
		if(ch=='0') {
			p = ht.l.at(p).lchild;
		} else {
			p = ht.l.at(p).rchild;
		}
	}
	return ht.l.at(p).e;
}

/*
数据为:
字母    编码    权重
a       0       45
b       101     13
c       100     12
d       111     16
e       1101    9
f       1100    5
*/
int main() {
	HT ht;
	init(ht);
	build(ht);
	auto code = encode(ht);
	cout<<"101解码:"<<decode(ht, "101")<<endl;
	cout<<"1100解码:"<<decode(ht, "1100")<<endl;

	return 0;
}
