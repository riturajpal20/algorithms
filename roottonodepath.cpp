bool dfs(ll node, ll par, vector<ll> adj[], vec &ans, ll x)
{
    if (adj[node].empty())
    {
        return false;
    }
    ans.pb(node);
    if (node == x)
    {
        return true;
    }

    for (auto it : adj[node])
    {

        if (it == par)
        {
            continue;
        }

        if (dfs(it, node, adj, ans, x))
        {
            return true;
        };
    }
    ans.pop_back();
    return false;
}
void solve()
{
    ll n, x;
    cin >> n >> x;
    vec adj[n + 1];
    ff(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vec ans;
    dfs(1, -1, adj, ans, x);
    ff(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
}