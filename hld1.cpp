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

struct SegmentTree
{

public :
	vl arr;
	vl segment;

	SegmentTree(ll n) : arr(n+1), segment(4*n) {}

	void build(ll v, ll start, ll end)
	{
		if (start == end)
		{
			segment[v] = arr[start];
			return;
		}
		ll mid = (start + end) >> 1;
		build(2*v,start,mid);
		build(2*v+1,mid+1,end);
		segment[v] = max(segment[2*v],segment[2*v+1]);
	}

	void update(ll v, ll start, ll end, ll index, ll val)
	{
		if (index > end or index < start)
		{
			return;
		}
		if  (index <= start and end <= index)
		{
			segment[v] = val;
			arr[index] = val;
			return;
		}
		ll mid = (start + end) >> 1;
		update(2*v,start,mid,index,val);
		update(2*v+1,mid+1,end,index,val);
		segment[v] = max(segment[2*v],segment[2*v+1]);
	}

	ll query(ll v, ll start, ll end, ll rangeX, ll rangeY)
	{
		if (rangeX > end or rangeY < start)
		{
			return -1;
		}
		if (rangeX <= start and end <= rangeY)
		{
			return segment[v];
		}
		ll mid = (start + end) >> 1;
		ll total = -1;
		total = max (total,query(2*v+1,mid+1,end,rangeX,rangeY));
		total = max (total,query(2*v,start,mid,rangeX,rangeY));
		return total;
	}

};

struct HeavyLightDecomposition
{

public :

	ll n, t;
	vector<vl> G;
	vector<vl> W;
	SegmentTree seg;
	vl in, out, sz, par, head, depth;

	HeavyLightDecomposition(ll n) : 
	n(n), t(1), G(n+1), in(n+1), out(n+1),
	head(n+1), sz(n+1), par(n+1), W(n+1), depth(n+1), seg(n) {}

	void addEdge(ll u, ll v, ll w)
	{
		G[u].pb(v);
	 	G[v].pb(u);
		W[u].pb(w);
		W[v].pb(w);
	}

	void dfs_size(ll u, ll p)
	{
		par[u] = p;
		depth[u] = depth[p] + 1;
		sz[u] = 1;
		For(i,0,(ll)G[u].size())
		{
			ll k = G[u][i];
			if (k == p)
			{
				continue;
			}
			dfs_size(k,u);
			sz[u] += sz[k];
			if (sz[k] >= sz[G[u][0]] or G[u][0] == p)
			{
				swap(G[u][i],G[u][0]);
				swap(W[u][i],W[u][0]);
			}
		}
	}

	void dfs_hld(ll u, ll w)
	{
		seg.arr[t] = w;
		in[u] = t++;
		For(i,0,G[u].size())
		{
			ll k = G[u][i];
			if (k == par[u])
			{
				continue;
			}
			head[k] = ((k == G[u][0]) ? head[u] : k);
			dfs_hld(k,W[u][i]);
		}
		out[u] = t-1;
	}

	void doHLD()
	{
		dfs_size(1,0);
		head[1] = 1;
		dfs_hld(1,0);
		seg.build(1,1,n);
	}

	ll query(ll u, ll v)
	{

		ll ans = 0;
		while (head[u] != head[v])
		{
			if (depth[head[u]] > depth[head[v]])
			{
				swap(u,v);
			}
			ans = max (ans,seg.query(1,1,n,in[head[v]],in[v]));
			v = par[head[v]];
		}
		if (depth[u] > depth[v])
		{
			swap(u,v);
		}
		ans = max(ans,seg.query(1,1,n,in[u]+1,in[v]));
		return ans;
	}

};


vector<pll> Edges;

void solve () 
{
	Edges.clear();

	ll n;
	cin >> n;

	HeavyLightDecomposition hld(n);

	For(i,1,n)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		hld.addEdge(u,v,w);
		Edges.pb(mp(u,v));
	}

	hld.doHLD();

	while (true)
	{
		string s;
		cin >> s;

		if (s == "DONE")
		{
			break;
		}

		if (s == "QUERY")
		{
			ll u, v;
			cin >> u >> v;
			cout << hld.query(u,v) << endl;
		}

		if (s == "CHANGE")
		{
			ll pos, val;
			cin >> pos >> val;
			pos -= 1;

			ll u = Edges[pos].F, v = Edges[pos].S;
			if (hld.par[u] == v)
			{
				swap(u,v);
			}
			hld.seg.update(1,1,n,hld.in[v],val);
		}
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
	cin >> t ;
	while (t--) solve() ;  

	return 0 ;
}
