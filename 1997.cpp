#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<lli> vlli;

vvii adj_list;
vlli visited;
lli n, cities, v1, v2, w;
vlli dist;

void dijkstra(lli x){
	for(int i = 0; i < n+1; i++){
		dist[i] = INT_MAX;
	}
	dist[x] = 0;
	priority_queue<ii, vii, greater<ii>> pq;
	pq.push(ii(dist[x],x));
	while(true){
		lli d = -1;
		lli m = INT_MAX;
		while(!pq.empty()){
			lli a = pq.top().second;
			pq.pop();
			if(visited[a] == 0){
				d = a;
				break;
			}
		}
		if(d == -1) break;
		visited[d] = 1;
		for(int i = 0; i < adj_list[d].size(); i++){
			lli distance = adj_list[d][i].first;
			lli act = adj_list[d][i].second;
			if(dist[act] > dist[d] + distance){
				dist[act] = dist[d] + distance;
				pq.push(ii(dist[act],act));
			}
		}
	}
}

int main(){
	cin >> n >> cities;
	adj_list.resize(n+1);
	visited.resize(n+1);
	dist.resize(n+1);
	for(int i = 0; i < cities; i++){
		cin >> v1 >> v2 >> w;
		adj_list[v1].pb(ii(w,v2));
		adj_list[v2].pb(ii(w,v1));
	}
	dijkstra(1);
	cout << dist[dist.size()-1] << endl;
	return 0;
}