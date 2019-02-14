void BFS(lli x){
	queue<lli> q;
	q.push(x);
	visited[x] = 1;
	while(!q.empty()){
		lli v = q.front(); q.pop();
		for(auto u : adj_list[v]){
			if(visited[u] == 0){
				visited[u] = 1;
				q.push(u);
			}
		}
	}
}
