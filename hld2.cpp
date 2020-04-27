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

public:
	vector<bool> arr;
	vl segment;

	SegmentTree(ll n) : arr(n+1), segment(4*n) {}

	void build(ll v, ll start, ll end)
	{
		if (start == end)
		{
			if (arr[start])
			{
				segment[v] = -1;
			}
			else
			{
				segment[v] = start;
			}
			return;
		}
		ll mid = (start + end) >> 1;
		build(2*v,start,mid);
		build(2*v+1,mid+1,end);
		
		segment[v] = segment[2*v];
		if (segment[v] == -1)
		{
			segment[v]  = segment[2*v+1];
		}
	}

	void update(ll v, ll start, ll end, ll index)
	{
		if (index > end or index < start )
		{
			return;
		}
		if (index<=start and end<=index)
		{
			arr[index] = not arr[index];
			if (arr[start])
			{
				segment[v] = -1;
			}
			else
			{
				segment[v] = start;
			}
			return;	
		}
		ll mid = (start + end) >> 1;
		update(2*v,start,mid,index);
		update(2*v+1,mid+1,end,index);
		segment[v] = segment[2*v];
		if (segment[v] == -1)
		{
			segment[v]  = segment[2*v+1];
		}	
	}

	ll query(ll v, ll start, ll end, ll rangeX, ll rangeY)
	{
		if (rangeX > end or start > rangeY)
		{
			return -1;
		}
		if (rangeX<=start and end<=rangeY)
		{
			return segment[v];
		}
		ll mid = (start + end) >> 1;
		ll ans = query(2*v,start,mid,rangeX,rangeY);
		if (ans == -1)
		{
			ans = query(2*v+1,mid+1,end,rangeX,rangeY);	
		} 
		return ans;
	}

};

struct HeavyLightDecomposition
{

public :

	ll n, t;
	vector<vl> G;
	SegmentTree seg;
	vl position, in, out, sz, par, head, depth;

	HeavyLightDecomposition(ll n) : 
	n(n), t(1), G(n+1), in(n+1), out(n+1), position(n+1),
	head(n+1), sz(n+1), par(n+1), depth(n+1), seg(n) {}

	void addEdge(ll u, ll v)
	{
		G[u].pb(v);
	 	G[v].pb(u);
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
			}
		}
	}

	void dfs_hld(ll u)
	{
		position[t] = u;
		in[u] = t++;
		For(i,0,G[u].size())
		{
			ll k = G[u][i];
			if (k == par[u])
			{
				continue;
			}
			head[k] = ((k == G[u][0]) ? head[u] : k);
			dfs_hld(k);
		}
		out[u] = t-1;
	}

	void doHLD()
	{
		dfs_size(1,0);
		head[1] = 1;
		dfs_hld(1);
		seg.build(1,1,n);
	}

	ll query(ll u, ll v)
	{
		ll ans = -1;
		while (head[u] != head[v])
		{
			if (depth[head[u]] > depth[head[v]])
			{
				swap(u,v);
			}
			ll res = seg.query(1,1,n,in[head[v]],in[v]);
			if (res != -1)
			{
				ans = res;
			}
			v = par[head[v]];
		}
		if (depth[u] > depth[v])
		{
			swap(u,v);
		}
		ll res = seg.query(1,1,n,in[u],in[v]);
		if (res != -1)
		{
			ans = res;
		}
		if (ans == -1)
		{
			return ans;
		}
		return position[ans];
	}

};


void solve () 
{
	ll n, q;
	cin >> n >> q;

	HeavyLightDecomposition hld(n);
	For(i,1,n)
	{
		ll u, v;
		cin >> u >> v;
		hld.addEdge(u,v);
	}

	For(i,1,n+1)
	{
		hld.seg.arr[i] = true;
	}
  
	hld.doHLD();

	For(i,0,q)
	{
		ll choice, u;
		cin >> choice >> u;

		if (choice == 0)
		{
			hld.seg.update(1,1,n,hld.in[u]);
		}

		else if (choice == 1)
		{
			cout << hld.query(u,1) << endl;
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
	// cin >> t ;
	while (t--) solve() ;  

	return 0 ;
}
