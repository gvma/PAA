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
lli n, m, o, v1, v2;
char ch;

void DIJKSTRA(){
	for(int i = 0; i < n; i++){
		dist[i] = INT_MAX;
	}
	dist[v1] = 0;
	priority_queue<ii, vii, less<ii> > pq;
	pq.push(mp(dist[v1],v1));
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

void adjusting_weights(){
	// cout << "V1 = " << v1 << " E V2 = " << v2 << endl; 
	for(int i = 0; i < adj_list[v1].size(); i++){
		if(adj_list[v1][i].second == v2){
			adj_list[v1][i].first = 0;
		}
	}
	for(int i = 0; i < adj_list[v2].size(); i++){
		if(adj_list[v2][i].second == v1){
			adj_list[v2][i].first = 0;
		}
	}
}

void remove_v1v2(){
	for(int i = 0; i < n; i++){
		lli sz = adj_list[i].size();
		for(int j = 0; j < sz; j++){
			if(adj_list[i][j].second == v2){
				adj_list[i].erase(adj_list[i].begin()+j);
			}
		}
	}
}

//FIRST = WEIGHT || SECOND = VERTEX

int main(){
	cin >> n >> m;
	adj_list.resize(n+1);
	visited.resize(n+1);
	dist.resize(n+1);
	for(int i = 0; i < m; i++){
		cin >> v1 >> v2;
		adj_list[v1].pb(mp(1,v2));
		adj_list[v2].pb(mp(1,v1));
	}
	lli size = n;
	cin >> o;
	// cout << "O = " << o << endl;
	for(int i = 0; i < o; i++){
		bool flagv1 = false, flagv2 = false, flag = false;
		cin >> ch >> v1 >> v2;
		if(ch == 'd'){
			DIJKSTRA();
			cout << dist[v2] << endl;
		} else if(ch == 'c'){
			if(v1 == v2){
				remove_v1v2();
				adj_list[v1].clear();
			} else {
				adjusting_weights();
			}
			for(int i = 0; i < adj_list.size(); i++){
				for(int j = 0; j < adj_list[i].size(); j++){
					if((adj_list[i][j].first == 0) && (adj_list[i][j].second == v1)){
						flagv1 = true;
					}
					if((adj_list[i][j].first == 0) && (adj_list[i][j].second == v2)){
						flagv2 = true;
					}
					if(flagv1 && flagv2) flag = true;
				}
				flagv1 = false;
				flagv2 = false;
			}
			if(!flag){
				size -= 1;
			}
		}
			cout << "OPERACAO = " << ch << " || " << size << endl;
	}
			for(int i = 0; i < adj_list.size(); i++){
				cout << "vertice " << i << ":" << endl;
				for(int j = 0; j < adj_list[i].size(); j++){
					cout << "(" << adj_list[i][j].first << ", " << adj_list[i][j].second << ")-> ";
				}
				cout << endl;
			}
	return 0;
}