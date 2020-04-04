
const ll NIL = 0;
const ll inf = 1e15;

struct BipartiteMatcher 
{
	vector<vl> G;
	vl L, R, dist;
	ll n, m;
	
	BipartiteMatcher(ll n, ll m) : n(n), m(m), G(n + 1), L(n + 1), R(m + 1), dist(n + 1) {}

	void addEdge(ll u, ll v) 
	{
		G[u].pb(v);
	}

	bool bfs()
	{
		queue<ll> q;
		dist[NIL] = inf;
		For(i,1,n+1)
		{
			if (L[i] == NIL)
			{
				dist[i] = 0;
				q.push(i);
			}
			else
			{
				dist[i] = inf;
			}
		}

		while (q.size() > 0)
		{
			ll u = q.front();
			q.pop();
			if (dist[u] >= dist[NIL])
			{
				continue;
			}
			For(i,0,(ll)G[u].size())
			{
				ll v = G[u][i];
				if (dist[R[v]] == inf)
				{
					dist[R[v]] = dist[u] + 1;
					q.push(R[v]);
				}
			}
		}
	    return (dist[NIL] != inf);
	}

	bool dfs(ll u)
	{
		if (u == NIL)
		{
			return true;
		}
		For(i,0,(ll)G[u].size())
		{
			ll v = G[u][i];
			if (dist[R[v]] == dist[u] + 1 and dfs(R[v]))
			{
				L[u] = v;
				R[v] = u;
				return true;
			}
		}
		return false;
	}

	ll maximum_matching()
	{
		fill(L.begin(), L.end(), NIL);
		fill(R.begin(), R.end(), NIL);
		ll mat = 0;
		while(bfs())
		{
			For(i,1,n+1)
			{
				if (L[i] == NIL and dfs(i))
				{
					mat++;
				}
			}
		}
		return mat;
	}
};
