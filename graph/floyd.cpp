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
	int a, b, w;
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
	cin>>w;
	while(a && b) {
		g.edge.at(a-1).at(b-1) = w;
		g.edge.at(b-1).at(a-1) = w;
		cin>>a;
		cin>>ch;
		cin>>b;
		cin>>ch;
		cin>>w;
	}
}


pair<vector<vector<int>>, vector<vector<int>>> floyd(G &g) {
	int i, j, k;
	vector<vector<int>> P;
	vector<vector<int>> D;
	
	for(i=0; i<g.vex.size(); i++) {
		vector<int> D_tmp;
		vector<int> P_tmp;
		for(j=0; j<g.vex.size(); j++) {
			D_tmp.push_back(g.edge.at(i).at(j));
			P_tmp.push_back(j);
		}
		D.push_back(D_tmp);
		P.push_back(P_tmp);
	}

	for(k=0; k<g.vex.size(); k++) {
		for(i=0; i<g.vex.size(); i++) {
			for(j=0; j<g.vex.size(); j++) {
				if((D[i][k] != INT_MAX && D[k][j] !=INT_MAX) && (D.at(i).at(k) + D.at(k).at(j) < D.at(i).at(j))) {
					D.at(i).at(j) = D.at(i).at(k) + D.at(k).at(j);
					P.at(i).at(j) = P.at(i).at(k);
				}
			
			}
		}
	}
	return {P, D};
}

void find_path(vector<vector<int>> P, vector<vector<int>> D, int start, int end) {
	int p=start;
	while(p != end) {
		cout<<p<<endl;
		p = P.at(p).at(end);
	}
	cout<<end<<endl;
}

int main() {
	G g;
	get_vex(g);
	get_edge(g);
	auto r = floyd(g);
	find_path(r.first, r.second, 0, 8);
	cout<<"最短路径为:"<<r.second.at(0).at(8)<<endl;
	
	return 0;
}
