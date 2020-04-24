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
const ll N = (ll)1e5+10;

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

vl G[N];
ll depth[N];
bool visited[N];
ll lowest[N];
ll backEdges[N];
vector<ll> articulationPoints;
vector<pll> bridges;

void init()
{
	For(i,0,N)
	{
		G[i].clear();
	}
	memset(backEdges,0,sizeof(backEdges));
	memset(depth,0,sizeof(depth));
	memset(visited,false,sizeof(visited));
}

void addEdge(ll u, ll v)
{
	G[u].pb(v);
	G[v].pb(u);
}

void dfs(ll u, ll par)
{
	visited[u] = true;
	depth[u] = depth[par] + 1;
	lowest[u] = depth[u];
	ll count = 0;
	For(i,0,G[u].size())
	{
		ll k = G[u][i];
		if (k == par)
		{
			continue;
		}
		if (not visited[k])
		{
			dfs(k,u);
			backEdges[u] += backEdges[k];
			if (lowest[k] >= depth[u])
			{
				count += 1;
			}
			lowest[u] = min(lowest[u],lowest[k]);
		}
		else
		{
			if (depth[k] >= depth[u])
			{
				backEdges[u] -= 1;
			}
			else
			{
				backEdges[u] += 1;
			}
			lowest[u] = min(lowest[u],depth[k]);
		}
	}	
	if (count >= 1 and depth[u]+count >= 3)
	{
		articulationPoints.pb(u);
	}
	if (u > 1 and backEdges[u] == 0)
	{
		bridges.pb(mp(min(u,par),max(u,par)));
	}
}

void solve () 
{
	init();

	ll n, m;
	cin >> n >> m;

	For(i,1,m+1)
	{
		ll u, v;
		cin >> u >> v;
		addEdge(u,v);
	}

	dfs(1,0);

	sort(articulationPoints.begin(),articulationPoints.end());
	sort(bridges.begin(),bridges.end());

	cout << articulationPoints.size() << endl;
	For(i,0,articulationPoints.size())
	{
		cout << (articulationPoints[i]) << ' ';
	}
	cout << endl;
	cout << bridges.size() << endl;
	For(i,0,bridges.size())
	{
		cout << (bridges[i].F) << ' ' << (bridges[i].S) << endl;
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
