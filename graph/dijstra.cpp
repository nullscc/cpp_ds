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

void dijstra(G &g, int i, int j) {
	vector<bool> f(g.vex.size(), false);
	vector<int> parent_path(g.vex.size(), i);
	vector<int> shortest_weight(g.vex.size());

	f.at(i) = 1;
	int m, n;
	for(m=0; m<g.vex.size(); m++) {
		shortest_weight.at(m) = g.edge.at(i).at(m);
	}
	
	for(m=1; m<g.vex.size(); m++) {
		int min = INT_MAX;
		int k;
		for(n=0; n<g.vex.size(); n++) {
			if(!f.at(n) && min > shortest_weight.at(n)) {
				k = n;
				min = shortest_weight.at(n);
			}
		}
		f.at(k) = true;
		for(n=0; n<g.vex.size(); n++) {
			if(!f.at(n) && g.edge.at(k).at(n) != INT_MAX && min + g.edge.at(k).at(n) < shortest_weight.at(n)) {
				shortest_weight.at(n) = min + g.edge.at(k).at(n);
				parent_path.at(n) = k;
			}
		}
	}
	cout<<"最短路径为:"<<shortest_weight.at(j)<<endl;
	n = j;
	while(n) {
		cout<<n<<endl;
		n = parent_path.at(n);
	}
	cout<<n<<endl;
}

int main() {
	G g;
	get_vex(g);
	get_edge(g);
	dijstra(g, 0, 8);

	return 0;
}
