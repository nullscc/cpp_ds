#include<bits/stdc++.h>

using namespace std;

typedef struct Edge{
	int hvex;
	int tvex;
	Edge *hlink;
	Edge *tlink;
}Edge;

typedef struct Vex{
	char e;
	Edge *firstin;
	Edge *firstout;
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
		tmp.firstin = NULL;
		tmp.firstout = NULL;
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
		tmp->hvex = b-1;
		tmp->tvex = a-1;
		tmp->hlink = g.vex.at(b-1).firstin;
		tmp->tlink = g.vex.at(a-1).firstout;
		g.vex.at(a-1).firstout = tmp;
		g.vex.at(b-1).firstin = tmp;
		
		cin>>a;
		cin>>ch;
		cin>>b;
	}
}

void dfs(G &g, int m, vector<bool> &visited) {
	cout<<g.vex.at(m).e<<" ";
	visited.at(m) = true;

	Edge *p = g.vex.at(m).firstout;
	while(p) {
		if(!visited.at(p->hvex)) {
			dfs(g, p->hvex, visited);
		}
		p = p->tlink;
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
