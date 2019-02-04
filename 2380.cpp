#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vlli;

lli n, source;
vector<vii> adj_list;
vlli visited;
set<int,int> s;

// void BFS(){
// 	vlli print_vec;
// 	print_vec.resize(n);
// 	queue<lli> q;
// 	q.push(source);
// 	visited[source] = 1;
// 	while(!q.empty()){
// 		lli v = q.front();
// 		// cout << u << endl;
// 		cout << v << endl;
// 		q.pop();
// 		for(int i = 0; i < adj_list[v].size(); i++){
// 			lli u = adj_list[v][i].first;
// 			if(visited[u] == 0){
// 				visited[u] = 1;
// 				q.push(u);
// 			}
// 		}
// 	}
// }

void DFS(lli x){
	lli v;
	for(int i = 0; i < adj_list[x].size(); i++){
		v = adj_list[x][i].first;
		if(visited[v] == 0){
			// cout << v << endl;
			visited[v] = 1;
			DFS(v);
		}
	}
	cout << v << endl;
}

int main(){
	lli v1, v2;
	cin >> n >> source;
	adj_list.resize(n+1);
	visited.resize(n+1);
	while(scanf("%lld%lld",&v1,&v2) != EOF){
		adj_list[v1].insert(adj_list[v1].begin(),ii(v2,1));
	}
	DFS(source);
	return 0;
}