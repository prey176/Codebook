void FW (vector <vector <ll>> edges, ll n)
{
    vector <vector <ll>> d (n, vector<ll>(n,1e18));

    for (vector <ll> a : edges)
    {
        d [a [0]] [a [1]] = a[2];
        d [a [1]] [a [0]] = a[2];
    }

    For (k,0,n)
    {
        For (i,0,n)
        {
            For (j,0,n) 
            {
                d [i] [j] = min (d [i] [j], d [i] [k] + d [k] [j]);
            }
        }
    }
}
