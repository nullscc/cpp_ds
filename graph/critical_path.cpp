#include<bits/stdc++.h>

using namespace std;

typedef struct Edge{
	int w;
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
	int a, b, w;
	char ch;

	cin>>a;
	cin>>ch;
	cin>>b;
	cin>>ch;
	cin>>w;
	while(a && b) {
		Edge *tmp = new Edge;
		tmp->w = w;
		tmp->v = b-1;
		tmp->next = g.vex.at(a-1).first;
		g.vex.at(a-1).first = tmp;
		g.vex.at(b-1).in++;
		
		cin>>a;
		cin>>ch;
		cin>>b;
		cin>>ch;
		cin>>w;
	}
}

vector<int> top_sort(G &g, stack<int> &s_path) {
	vector<int> etv(g.vex.size(), 0);
	stack<int> s;
	int i;
	for(i=0; i<g.vex.size(); i++) {
		if(!g.vex.at(i).in) {
			s.push(i);
		}
		etv.at(i) = 0;
	}
	while(!s.empty()) {
		int v = s.top();
		s.pop();
		s_path.push(v);
		// cout<<v<<endl;
		Edge *p = g.vex.at(v).first;
		int min = INT_MAX;
		while(p) {
			if(--g.vex.at(p->v).in<=0) {
				s.push(p->v);

			}
			if(etv.at(p->v) < p->w + etv.at(v)) {
				etv.at(p->v) = p->w + etv.at(v);
			}

			p = p->next;
		}
	}
	return etv;
}

void critical_path(G &g) {
	int ete, lte;
	stack<int> s;
	vector<int> etv = top_sort(g, s);
	vector<int> ltv(g.vex.size(), etv.at(g.vex.size()-1));
	cout<<etv.at(g.vex.size()-1)<<endl;
	
	int v;
	while(!s.empty()) {
		v = s.top();
		s.pop();

		Edge *p = g.vex.at(v).first;
		
		while(p) {
			if(ltv.at(p->v)-p->w < ltv.at(v)) {
				ltv.at(v) =  ltv.at(p->v) - p->w;
			}
			p = p->next;
		}
	}

	int i = 0;
	for(auto vex: g.vex) {
		Edge *p = vex.first;
		ete = etv.at(i);
		while(p) {
			lte = ltv.at(p->v) - p->w;
			if(lte == ete) {
				cout<<i<<"-->"<<p->v<<endl;
			}
			p = p->next;
		}
		i++;
	}

}

int main() {
	G g;
	get_vex(g);
	get_edge(g);
	critical_path(g);

	return 0;
}
