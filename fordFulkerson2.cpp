struct MaxFlow
{
	ll V, source, sink;
	vector<map<ll,ll> > rG;

	MaxFlow(ll v)
	{
		V = v+2;
		source = v+1;
		sink = v+2;

		For(i,0,V+1)
		{
			map<ll,ll> t;
			rG.pb(t);
		}
	}

	void addEdge(ll u, ll v, ll w1, ll w2)
	{
		rG[u][v] = w1;
		rG[v][u] = w2;
	}

	bool dfs(ll u, ll parent[], bool visit[])
	{

		visit[u] = true;
		if (u == sink)
		{
			return true;
		}
		map<ll,ll>::iterator it;
		ll ans = false;
		for(it = rG[u].begin(); it != rG[u].end(); it++)
		{
			ll k = it->F;
			ll w = it->S;
			
			if (not visit[k] and w)
			{
				parent[k] = u;
				ans = ans or dfs(k,parent,visit);
			}
		}
		return ans;
	}

	bool bfs(ll parent[])
	{
		bool visit[V+1];
		memset(visit,false,sizeof(visit));

		queue<ll> q;
		q.push(source);
		visit[source] = true;

		while (q.size() > 0)
		{
			ll u = q.front();
			q.pop();

			map<ll,ll>::iterator it;
			for (it = rG[u].begin(); it != rG[u].end(); it++)
			{
				ll k = it->F;
				ll w = it->S;
				if (visit[k] or w == 0)
				{
					continue;
				}
				parent[k] = u;
				q.push(k);
				visit[k] = true;
				if (visit[sink])
				{
					return true;
				}
			}
		}
		return visit[sink];
	}

	bool result(ll choice, ll parent[])
	{
		if (choice == 1)
		{
			return bfs(parent);
		}
		if (choice == 2)
		{
			bool visit[V+1];
			memset(visit,false,sizeof(visit));
			return dfs(source,parent,visit);
		}
	}

	ll fordFulkerson(ll choice = 2)
	{
		ll ans = 0;
		ll parent[V+1];
		
		while (result(choice,parent))
		{
			ll pathFlow = (1e6);
			for (ll v = sink; v != source; v = parent[v])
			{
				pathFlow = min(pathFlow,rG[parent[v]][v]);
			}

			for (ll v = sink; v != source; v = parent[v])
			{
				rG[parent[v]][v] -= pathFlow;
				rG[v][parent[v]] += pathFlow;
			}
			ans += pathFlow;
		}
		return ans;
	}

};
