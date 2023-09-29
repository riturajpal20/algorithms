void bfs(ll root, vector<ll> adj[])
{
    queue<pair<ll, ll>> q;
    q.push({root, 0});
    ll height = 0;
    while (!q.empty())
    {

        ll sz = q.size();
        height++;
        while (sz--)
        {
            ll node = q.front().first;
            ll par = q.front().second;
            q.pop();
            for (auto it : adj[node])
            {
                if (it == par)
                {
                    continue;
                }
                q.push({it, node});
            }
        }
    }
    cout << height;
}
