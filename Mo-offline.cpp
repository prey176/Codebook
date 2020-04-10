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

struct node
{
	ll l, r;
	ll index;
};

ll BLOCK = 320;

bool comparator(node a, node b)
{
	ll L1 = (a.l) / BLOCK;
	ll L2 = (b.l) / BLOCK;
	if (L1 == L2)
	{
		return (a.r < b.r);
	}
	return (L1 < L2);
}

ll a[N];
ll FREQ[N];
map<ll,ll> ID;
ll b[N];

void solve () 
{
	ll n, m;
	cin >> n >> m;
    
  memset(FREQ,0,sizeof(FREQ));
  memset(b,0,sizeof(b));

	For(i,1,n+1)
	{
		cin >> a[i];
		if (ID.find(a[i]) == ID.end())
		{
		    ID[a[i]] = i;
		}
		b[i] = a[i];
		a[i] = ID[a[i]];
	}
	
	
	node query[m+1];
	For(i,1,m+1)
	{
		cin >> query[i].l >> query[i].r;
		query[i].index = i;
	}

	sort(query+1,query+m+1,comparator);
	
	ll L = 1;
	ll R = 1;

	ll ans = 0;

	ll result[m+1];

	FREQ[a[1]] = 1;
	if (FREQ[a[1]] == b[1])
	{
		ans++;
	}
	
	For(i,1,m+1)
	{
		node Q = query[i];

		while (Q.l < L)
		{
			L--;
			FREQ[a[L]]++;
			if (FREQ[a[L]] == b[L])
			{
				ans++;
			}
			else if (FREQ[a[L]] == b[L]+1)
			{
				ans--;
			}
		}
        
        
		while (R < Q.r)
		{
			R++;
			FREQ[a[R]]++;
			if (FREQ[a[R]] == b[R])
			{
				ans++;
			}
			else if (FREQ[a[R]] == b[R]+1)
			{
				ans--;
			}	
		}
    

		while (L < Q.l)
		{
			FREQ[a[L]]--;
			if (FREQ[a[L]] == b[L])
			{
				ans++;
			}
			else if (FREQ[a[L]]+1 == b[L])
			{
				ans--;
			}
			L++;	
		}


		while (R > Q.r)
		{
			FREQ[a[R]]--;
			if (FREQ[a[R]] == b[R])
			{
				ans++;
			}
			else if (FREQ[a[R]]+1 == b[R])
			{
				ans--;
			}
			R--;	
		}
        

		result[Q.index] = ans;
	}

	For(i,1,m+1)
	{
		cout << result[i] << ' ';
	}
	cout << endl;
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
