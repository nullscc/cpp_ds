#include<bits/stdc++.h>

using namespace std;

typedef struct Edge{
	int v;
	Edge *next;
}Edge;

typedef struct {
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
		
		cin>>a;
		cin>>ch;
		cin>>b;
	}
}

void dfs(G &g, int m, vector<bool> &visited) {
	cout<<g.vex.at(m).e<<" ";
	visited.at(m) = true;

	Edge *p = g.vex.at(m).first;
	while(p) {
		if(!visited.at(p->v)) {
			dfs(g, p->v, visited);
		}
		p = p->next;
	}
}

void DFS(G &g) {
	vector<bool> visited(g.vex.size(), false);
	
	int i;
	for(i=0; i<g.vex.size(); i++) {
		if(!visited.at(i)) {
			dfs(g, i, visited);
		}
	
	}

}

int main() {
	G g;
	get_vex(g);
	get_edge(g);

	DFS(g);
	cout<<endl;

}
