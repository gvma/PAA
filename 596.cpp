#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<lli> vlli;
typedef vector<ii> vii;

#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); ++it)

// 0 for white, 1 for gray and 2 for black

	vector<vii> adj_list;

void visit(lli vertex){
	cout << "Visiting vertex: " << vertex << endl;
}

int BFS(int x, vlli &visited, lli n_of_islands){
	queue<ii> q;
	q.push(ii(x,1));
	visited[x] = 1;
	while(!q.empty()){
		ii v = q.front();
		// cout << "v.second = " << v.second << endl;
		q.pop();
		for(int i = 0; i < adj_list[v.first].size(); i++){
			lli u = adj_list[v.first][i].first;
			if(visited[u] == 0){
				// cout << "u = " << u << endl;
				visited[u] = 1;
				q.push(ii(u,v.second+1));
			}
			if(u == n_of_islands){
				// cout << "retornando " << v.second << endl;
				return v.second;
			}
		}
		// cout << "fim do loop" << endl;
	}
	return -1;
}

int main(){
	lli t, n_of_islands, n_of_bridges, v1, v2;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n_of_islands >> n_of_bridges;
		vlli visited;
		visited.resize(n_of_islands+1);
		adj_list.resize(n_of_islands+1);
		for(int j = 0; j <= n_of_islands; j++){
			visited[i] = 0;
		}
		for(int j = 0; j < n_of_bridges; j++){
			cin >> v1 >> v2;
			adj_list[v1].push_back(ii(v2,1));
			adj_list[v2].push_back(ii(v1,1));
		}
		// cout << "printando visitados: " << endl;
		// for(int j = 0; j < visited.size(); j++){
		// 	cout << visited[j] << endl;
		// }
		// cout << "printando adj_list: " << endl;
		// for(int j = 0; j < adj_list.size(); j++){
		// 	cout << "vertice " << j << ":" << endl;
		// 	for(int k = 0; k < adj_list[j].size(); k++){
		// 		cout << adj_list[j][k].first << "->";
		// 	}
		// 	cout << " //" << endl;
		// }
		cout << BFS(1,visited,n_of_islands) << endl;
		for(int j = 0; j < adj_list.size(); j++){
			adj_list[j].clear();
		}
		adj_list.clear();
		visited.clear();
	}
	return 0;
}
// TO PRINT GRAPH