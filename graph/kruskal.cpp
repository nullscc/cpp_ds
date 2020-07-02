#include<bits/stdc++.h>

using namespace std;

typedef struct {
	int v1;
	int v2;
	int w;
}Edge;

typedef struct {
	string vex;
	vector<Edge> edge;
}G;

void get_vex(G &g) {
	getline(cin, g.vex);
}

void get_edge(G &g) {
	int a, b, weight;
	char ch;

	cin>>a;
	cin>>ch;
	cin>>b;
	cin>>ch;
	cin>>weight;
	while(a && b) {
		g.edge.push_back({a-1, b-1, weight});
		cin>>a;
		cin>>ch;
		cin>>b;
		cin>>ch;
		cin>>weight;
	}
}

int find(vector<int> &parent, int p) {
	while(parent.at(p) >= 0) {
		p = parent.at(p);
	}
	return p;
}


void kruscal(G &g) {
	vector<int> parent(g.vex.size(), -1); 		// NOTE: 这里实际上不能用0，用0需要保证没有end为0值，不然会出bug 

	for(auto edge: g.edge) {
		int v1 = edge.v1;
		int v2 = edge.v2;
		int p1 = find(parent, v1);
		int p2 = find(parent, v2);
		if(p1 != p2) {
			parent.at(p1) = p2;
			cout<<"找到边:"<<g.vex.at(v1)<<"->"<<g.vex.at(v2)<<endl;
		}
	}
}

int main() {
	G g;
	get_vex(g);
	get_edge(g);
	kruscal(g);

	return 0;
}
