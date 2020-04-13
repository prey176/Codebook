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
#define infinity 1e18

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


const int M = 25;
const int N = 100100;
ll C[N];
ll F[M][N];
int G, L;
int curL;
int curR;
ll freq[N];
ll currentCost;

void updateCost(int x, int y)
{
	while (curL > x)
	{
		curL--;
		currentCost -= (freq[C[curL]]*(freq[C[curL]]-1))/2;
		freq[C[curL]]++;
		currentCost += (freq[C[curL]]*(freq[C[curL]]-1))/2;
	}

	while (curR < y)
	{
		curR++;
		currentCost -= (freq[C[curR]]*(freq[C[curR]]-1))/2;
		freq[C[curR]]++;
		currentCost += (freq[C[curR]]*(freq[C[curR]]-1))/2;
	}

	while (curL < x)
	{
		currentCost -= (freq[C[curL]]*(freq[C[curL]]-1))/2;
		freq[C[curL]]--;
		currentCost += (freq[C[curL]]*(freq[C[curL]]-1))/2;
		curL++;
	}

	while (curR > y)
	{
		currentCost -= (freq[C[curR]]*(freq[C[curR]]-1))/2;
		freq[C[curR]]--;
		currentCost += (freq[C[curR]]*(freq[C[curR]]-1))/2;
		curR--;
	}
}

void fill(int g, int l1, int l2, int p1, int p2) 
{
    if (l1 > l2)
    {
    	return;
    }

    int lm = (l1 + l2) >> 1;

    F[g][lm] = infinity;
    int bestPosition = -1; 

    For(k,p1,min(p2,lm+1)+1)
    {
    	updateCost(k+1,lm);
        ll newCost = F[g-1][k] + currentCost;
        if (F[g][lm] > newCost) 
        {
            F[g][lm] = newCost;
            bestPosition = k;
        }
    }

    fill(g, l1, lm-1, p1, bestPosition);
    fill(g, lm+1, l2, bestPosition, p2);
}

void solve()
{
	cin >> L >> G;

    For(i,1,L+1)
    {
        cin >> C[i];
    }

    F[1][0] = 0;

    memset(freq,0,sizeof(freq));
    
    currentCost = 0;
    freq[C[1]] = 1;
    curL = 1;
    curR = 1;

    For(l,1,L+1)
    {
    	updateCost(1,l);
        F[1][l] = currentCost;
    }


    For(g,2,G+1)
    {
        fill(g, 0, L, 0, L);
    }    

    cout << F[G][L] << endl;
}

signed main() 
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin) ;
    freopen("output.txt","w",stdout) ;
	#endif

    int t = 1;
    // cin >> t;
    while (t--) solve();

}
