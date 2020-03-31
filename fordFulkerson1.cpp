struct MaxFlow
{
	ll V, source, sink;
	vector<vl> rG, G;
 
	MaxFlow(ll v)
	{
		V = v+2;
		source = v+1;
		sink = v+2;
		For(i,0,V+1)
		{
			vl t(V+1,0);
			rG.pb(t);
		}
		For(i,0,V+1)
		{
			vl t;
			G.pb(t);
		}
	}
 
	void addEdge(ll u, ll v, ll w)
	{
		rG[u][v] = w;
		rG[v][u] = 0;
		G[u].pb(v);
		G[v].pb(u);
	}
 
	bool dfs(ll u, ll parent[], bool visit[])
	{
		visit[u] = true;
		if (u == sink)
		{
			return true;
		}
		ll ans = false;
		For(i,0,(ll)G[u].size())
		{
			ll k = G[u][i];
			if (visit[k])
			{
				continue;
			}
			if (rG[u][k] > 0)
			{
				parent[k] = u;
				ans = ans or dfs(k, parent, visit);
			}
		}
		return ans;
	}
 
	ll fordFulkerson()
	{
		ll ans = 0;
		ll parent[V+1];
		bool visit[V+1];
		memset(visit,false,sizeof(visit));
		while (dfs(source,parent,visit))
		{
			ll pathFlow = (1e15);
			for (ll v = sink; v != source; v = parent[v])
			{
				ll u = parent[v];
				pathFlow = min(pathFlow,rG[u][v]);
			}
 
			for (ll v = sink; v != source; v = parent[v])
			{
				ll u = parent[v];
				rG[u][v] -= pathFlow;
				rG[v][u] += pathFlow;
			}
			ans += pathFlow;
			memset(visit,false,sizeof(visit));
		}
		return ans;
	}
 
};
