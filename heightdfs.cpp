void dfs(ll node, ll par, vector<ll> adj[], vector<ll> &level, ll l)
{
    // intime
    // mp[node].first = ti;
    // ti++;

    // cout << node << " ";
    level[node] = l;

    for (auto it : adj[node])
    {
        // if it not equal to parent
        if (it == par)
        {
            continue;
        }

        dfs(it, node, adj, level, l += 1);
    }
    // out time
    // mp[node].second = ti;
    // ti++;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> adj[n + 1];
    ff(i, 0, n - 1)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<ll> level(n + 1);
    // bfs(1, adj);
    ll ans = 0;
    dfs(1, 0, adj, level, 0);
    ff(i, 1, n + 1)
    {
        ans = max(ans, level[i] + 1);
    }
    cout << ans;
}