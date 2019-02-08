#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;

vvii adj_list;
vlli visited, dist;
lli t, n, m, v1, v2, w, k;

void DIJKSTRA(){
	for(int i = 1; i <= n+1; i++){
		dist[i] = INT_MAX;
	}
	dist[1] = 0;
	priority_queue<ii, vii, less<ii> > pq;
	pq.push(mp(dist[1],1));
	while(1){
		lli davez = -1;
		while(!pq.empty()){
			lli atual = pq.top().second;
			pq.pop();
			if(visited[atual] == 0){
				davez = atual;
				break;
			}
		}
		if(davez == -1) return;
		for(int i = 0; i < adj_list[davez].size(); i++){
			lli distance = adj_list[davez][i].first;
			lli act = adj_list[davez][i].second;
			if(dist[act] > dist[davez] + distance){
				dist[act] = dist[davez] + distance;
				pq.push(mp(dist[act],act));
			}
		}
	}
}

//FIRST = WEIGHT || SECOND = VERTEX

int main(){
	lli ans = 0;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		adj_list.resize(n+1);
		visited.resize(n+1);
		dist.resize(n+1);
		for(int j = 0; j < m; j++){
			cin >> v1 >> v2 >> w;
			adj_list[v1].pb(mp(w,v2));
			adj_list[v2].pb(mp(w,v1));
		}
		cin >> k;
		DIJKSTRA();
		for(int j = 0; j < k; j++){
			cin >> v1;
			ans += dist[v1] * 2;
		}
		cout << "caso " << i+1 << ": " << ans << endl;
		ans = 0;
		adj_list.clear();
		visited.clear();
		dist.clear();
	}
	return 0;
}