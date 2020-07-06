#include<bits/stdc++.h>

using namespace std;

typedef struct Edge{
	int v;
	Edge *next;
}Edge;

typedef struct {
	int in;
	char e;
	Edge *first;
}Vex;

typedef struct {
	vector<Vex> vex;
}G;

void get_vex(G &g) {
	string vs;
	getline(cin, vs);
	for(auto ch: vs) {
		Vex tmp;
		tmp.e = ch;
		tmp.in = 0;
		tmp.first = NULL;
		g.vex.push_back(tmp);
	}
}

void get_edge(G &g) {
	int a, b;
	char ch;

	cin>>a;
	cin>>ch;
	cin>>b;
	while(a && b) {
		Edge *tmp = new Edge;
		tmp->v = b-1;
		tmp->next = g.vex.at(a-1).first;
		g.vex.at(a-1).first = tmp;
		g.vex.at(b-1).in++;
		
		cin>>a;
		cin>>ch;
		cin>>b;
	}
}

void top_sort(G &g) {
	stack<int> s;
	int i;
	for(i=0; i<g.vex.size(); i++) {
		if(!g.vex.at(i).in) {
			s.push(i);
		}
	}
	while(!s.empty()) {
		int v = s.top();
		s.pop();
		cout<<v<<endl;
		Edge *p = g.vex.at(v).first;
		while(p) {
			if(--g.vex.at(p->v).in<=0) s.push(p->v);
			p = p->next;
		}
	}

}

int main() {
	G g;
	get_vex(g);
	get_edge(g);
	top_sort(g);


	return 0;
}
