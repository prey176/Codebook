bool visit [N];
stack <ll> st;
vector <ll> topo;
vector <ll> graph [N];
ll n;

void dfs (ll u)
{
    visit [u] = true;
    for (auto a : graph [u])
    {
        if (not visit [a])
        {
            dfs (a);
        }
    }
    st.push(u);
}

void TopologicalSort()
{
    For(i,0,n)
    {
        visit [i] = false;
    }
    For(i,0,n)
    {
        if (not visit [i])
        {
            dfs(i);
        }
    }
    while (st.size() > 0)
    {
        topo.push_back(st.top());
        st.pop();
    }
}
