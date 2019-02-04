#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vlli;

lli n, individuals, input;
vector<vii> adj_list;
vlli visited;
stack<ii> my_stack;

void visit(lli x){
	cout << "visitando " << x << endl;
}

void DFS(lli x, bool flag){
	visited[x] = 1;
	for(int i = 0; i < adj_list[x].size(); i++){
		if(visited[i] == 0){
			my_stack.push();
			DFS(adj_list[x][i].first, flag);
		}
	}
	visited[x] = 2;
	return;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> individuals;
		adj_list.resize(individuals+1);
		visited.resize(individuals+1);
		for(int j = 0; j < individuals; j++){
			cin >> input;
			if(input == 0) continue;
			adj_list[j+1].push_back(ii(input,1));
		}
		cout << "printando adj_list: " << endl;
		for(int j = 0; j < adj_list.size(); j++){
			cout << "vertice " << j << ":" << endl;
			for(int k = 0; k < adj_list[j].size(); k++){
				cout << adj_list[j][k].first << "->";
			}
			cout << " //" << endl;
		}
		DFS(1, false);
		adj_list.clear();
		visited.clear();
	}
	return 0;
}