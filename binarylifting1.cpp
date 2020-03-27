#include <bits/stdc++.h>
using namespace std ;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;

#define ll long long
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define For(i,a,b) for (ll i = a ; i < b ; i++)
#define Forr(i,a,b) for (ll i = a ; i >= b; i--)
#define F first
#define S second
#define vl vector<ll>
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define endl '\n'

// template <class T, class cmp = less<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

ll modulo = (ll)1e9 + 7;

ll fpow(ll a, ll b)
{
	ll ans = 1;
	while (b)
	{
		if (b&1) ans = (ans*a)%modulo;
		a = (a*a)%modulo;
		b = b>>1; 
	}
	return ans;
}

const ll N = 2e5 + 10;
const ll K = 19;
ll parent[N][K];
ll depth[N]; 
vl G[N];
 
void init()
{
	For(i,0,N)
	{
		For(j,0,K)
		{
			parent[i][j] = 0;
		}
		depth[i] = 0;
		G[i].clear();
	}
}
 
void dfs(ll u, ll par)
{	
	parent[u][0] = par;
	depth[u] = depth[par] + 1;		
	For(i,1,K)
	{ 
		parent[u][i] = parent[parent[u][i-1]][i-1];
	}
 	For(i,0,(ll)G[u].size())
 	{
 		ll k = G[u][i];
 		if (k == par)
 		{
 			continue;
 		}
 		dfs(k,u);
 	}
}

ll lca(ll u, ll v)
{
	if (depth[u] > depth[v])
	{
		swap(u,v);
	}
	Forr(i,K-1,0)
	{
		if (depth[parent[v][i]] >= depth[u])
		{
			v = parent[v][i];
		}
	}
	if (u == v)
	{
		return u;
	}
	Forr(i,K-1,0)
	{
		if (parent[v][i] != parent[u][i])
		{
			v = parent[v][i];
			u = parent[u][i];
		}
	}
	return parent[u][0];
}

void addEdge(ll u, ll v)
{
	G[u].pb(v);
	G[v].pb(u);
}

void solve () 
{
	init();

	ll n, q;
	cin >> n >> q;

	For(i,0,n-1)
	{
		ll u; cin >> u;
		ll v; cin >> v;
		addEdge(v,u);
	}

	dfs(1,0);

	For(i,0,q)
	{
		ll u, v;
		cin >> u >> v;
		cout << lca(u,v) << endl;
	}
}


signed main () 
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
	#endif

    fast_io();
	int t = 1 ;
	// cin >> t ;
	while (t--) solve() ;  

	return 0 ;
}
