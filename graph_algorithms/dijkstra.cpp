void dijkstra(lli x){
    priority_queue<ii, vii, greater<ii>> pq;
    for(int i = 0; i < n; i++){
        dist[i] = INF;
    }
    dist[x] = 0;
    pq.push(mp(dist[x],x));
    while(!pq.empty()){
        lli v = pq.top().S; pq.pop();
        for(auto x : adj_list[v]){
            ii u = x;
            if(dist[u.S] > dist[v] + u.F){
                dist[u.S] = dist[v] + u.F;
                pq.push(mp(dist[u.S],u.S));
            }
        }
    }
}
