void DFS(lli x){
	visited[x] = 1;
	for(auto u : adj_list[x]){
		if(visited[u] == 0){
			DFS(adj_list[x][u]);
		}
	}
}
