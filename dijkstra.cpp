#define inf 1e15
vector<pll> adj[N];
ll d[N];
bool vis[N];

void dijkstra(ll v, ll n){
	fill(d+1, d+n+1, inf);
	fill(vis+1,vis+n+1,false);
	d[v] = 0;
	priority_queue<pll, vector<pll>, greater<pll> > pq;
	pq.push(mp(d[v], v));
	while(!pq.empty())
	{
		ll u = pq.top().S; pq.pop();
		if(vis[u])
		{
			continue;
		} 
		vis[u] = true;
		For(i,0,(ll)adj[u].size())
		{
			pll it = adj[u][i];
			if(d[it.F] > d[u] + it.S)
			{
				d[it.F] = d[u] + it.S;
				pq.push(mp(d[it.F], it.F));
			}
		}
	} 
}
