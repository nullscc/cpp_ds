#include<bits/stdc++.h>

using namespace std;

typedef struct {
	string vex;
	vector<vector<int>> edge;
}G;

void get_vex(G &g) {
	getline(cin, g.vex);
}

void get_edge(G &g) {
	int a, b, weight;
	char ch;
	int i=g.vex.size(), j;
	for(; i>0; i--) {
		j = g.vex.size();
		vector<int> tmp;
		for(;j>0; j--) {
			tmp.push_back(INT_MAX);
		}
		g.edge.push_back(tmp);
	}

	cin>>a;
	cin>>ch;
	cin>>b;
	cin>>ch;
	cin>>weight;
	while(a && b) {
		g.edge.at(a-1).at(b-1) = weight;
		g.edge.at(b-1).at(a-1) = weight;
		cin>>a;
		cin>>ch;
		cin>>b;
		cin>>ch;
		cin>>weight;
	}
}

void prim(G &g, int start) {
	vector<int> lowcost;
	vector<int> adjvex;

	int i, j;
	for(i=0; i<g.vex.size(); i++) {
		lowcost.push_back(g.edge.at(start).at(i));
		adjvex.push_back(start);
	}
	lowcost.at(start) = 0;

	for(i=1; i<g.vex.size(); i++) {
		int min = INT_MAX;
		int k;
		for(j=0; j<g.vex.size(); j++) {
			if(lowcost.at(j) && min > lowcost.at(j)) {
				min = lowcost.at(j);
				k = j;
			}
		}
		if(min==INT_MAX) cout<<"oops, 树不是连通的"<<endl;
		lowcost.at(k) = 0;
		cout<<"找到路径："<<g.vex.at(adjvex.at(k))<<"->"<<g.vex.at(k)<<endl;
		
		for(j=0; j<g.vex.size(); j++) {
			if(lowcost.at(j) && g.edge.at(k).at(j) < lowcost.at(j)) {
				lowcost.at(j) = g.edge.at(k).at(j);
				adjvex.at(j) = k;
			}
		}
	}
}

int main() {
	G g;
	get_vex(g);
	cout<<"顶点信息:"<<g.vex<<endl<<"顶点个数:"<<g.vex.size()<<endl;
	get_edge(g);

	cout<<"边个数:"<<g.edge.size()<<endl;
	prim(g, 0);

	return 0;
}


