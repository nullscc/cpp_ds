#include<bits/stdc++.h>

using namespace std;

typedef struct {
	string vex;
	vector<vector<bool>> edge;
}G;

void get_vex(G &g) {
	getline(cin, g.vex);
}

void get_edge(G &g) {
	int a, b;
	char ch;
	int i=g.vex.size(), j;
	for(; i>0; i--) {
		j = g.vex.size();
		vector<bool> tmp;
		for(;j>0; j--) {
			tmp.push_back(false);
		}
		g.edge.push_back(tmp);
	}

	cin>>a;
	cin>>ch;
	cin>>b;
	while(a && b) {
		g.edge.at(a-1).at(b-1) = true;
		g.edge.at(b-1).at(a-1) = true;
		cin>>a;
		cin>>ch;
		cin>>b;
	}
}

void dfs(G &g, int i, vector<bool> &visited) {
	cout<<g.vex.at(i)<<" ";
	visited.at(i) = true;

	int j;
	for(j=0; j<g.vex.size(); j++) {
		if(g.edge.at(i).at(j) && !visited.at(j)) {
			dfs(g, j, visited);
		}
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

void bfs(G &g, int m, queue<int> &q, vector<bool> &visited) {
	q.push(m);
	visited.at(m) = true;
	cout<<g.vex.at(m)<<" ";

	int i, j;
	while(!q.empty()) {
		i = q.front();
		q.pop();

		for(j=0; j<g.vex.size(); j++) {
			if(!visited.at(j) && g.edge.at(i).at(j)) {
				visited.at(j) = true;
				cout<<g.vex.at(j)<<" ";
				q.push(j);
			}
		}
	}
}

void BFS(G &g) {
	vector<bool> visited(g.vex.size(), false);
	queue<int> q;

	int i;
	for(i=0; i<g.vex.size(); i++) {
		if(!visited.at(i)) bfs(g, i, q, visited);
	}
}

void dfs_non_recursive(G &g, int m, stack<int> &s, vector<bool> &visited) {
	cout<<g.vex.at(m)<<" ";
	visited.at(m) = true;
	s.push(m);
	bool find = true;
	int p, j;
	while(!s.empty()) {
		if(find) {
			p = s.top();
		} else {
			s.pop();
			p = s.top();
			if(!p) break;
		}
		
		find = false;
		for(j=0; j<g.vex.size(); j++) {
			if(!visited.at(j) && g.edge.at(p).at(j)) {
				cout<<g.vex.at(j)<<" ";
				visited.at(j) = true;
				s.push(j);
				find = true;
				break;
			}
		}
	}

}

void DFS_non_recursive(G &g) {
	vector<bool> visited(g.vex.size(), false);
	stack<int> s;

	int i;
	for(i=0; i<g.vex.size(); i++) {
		if(!visited.at(i)) dfs_non_recursive(g, i, s, visited);
	}

}

int main() {
	G g;
	get_vex(g);
	cout<<"顶点信息:"<<g.vex<<endl<<"顶点个数:"<<g.vex.size()<<endl;
	get_edge(g);

	cout<<"边个数:"<<g.edge.size()<<endl;

	cout<<"深度优先搜索结果:";
	DFS(g);
	cout<<endl;

	cout<<"广度优先搜索结果:";
	BFS(g);
	cout<<endl;

	cout<<"非递归深度优先搜索结果:";
	DFS_non_recursive(g);
	cout<<endl;

	return 0;
}
