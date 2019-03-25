#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef long long int lli;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;

stack<lli> topoStack;
vvlli graph;
vlli visited;

void topologicalSort(lli x)
{
	visited[x] = 1;
	for (auto y : graph[x]){
		if (visited[y] == 0){
			visited[y] = 1;
			topologicalSort(y);
		}
	}
	topoStack.push(x);
}

int main()
{
	graph.resize(10);
	visited.resize(10);
	graph[0].pb(1);
	graph[1].pb(2);
	graph[2].pb(3);
	graph[2].pb(4);
	topologicalSort(0);
	while (!topoStack.empty()){
		lli x = topoStack.top(); topoStack.pop();
		cout << x << " ";
	}
	cout << endl;
	return 0;
}