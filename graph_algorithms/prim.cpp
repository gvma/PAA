lli prim(lli x){
	visited[x] = 1;
	lli mst = 0;
	priority_queue<iii, viii, greater<iii>> pq;
	for(auto v : adj_list[x]){
		pq.push(iii(v.F, x, v.S));
	}
	while(!pq.empty()){
		iii v = pq.top(); pq.pop();
		lli f = get<1>(v), a = get<2>(v), w = get<0>(v);
		if(visited[a] == 0){
			mst += w;
			visited[a] = 1;
			for(int i = 0; i < adj_list[a].size(); i++){
				ii u = adj_list[a][i];
				if(visited[u.S] == 0){
					pq.push(iii(u.F, a, u.S));
				}
			}
		}
	}
	return mst;
}