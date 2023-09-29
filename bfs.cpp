#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int>> mp;
int ti = 0;
void dfs(int node, int par, vector<int> adj[])
{
    // intime
    mp[node].first = ti;
    ti++;

    // cout << node << " ";

    for (auto it : adj[node])
    {
        // if it not equal to parent
        if (it == par)
        {
            continue;
        }

        dfs(it, node, adj);
    }
    // out time
    mp[node].second = ti;
    ti++;
}

void solve()
{
}

/*************YOUR CODE GOES HERE*************/
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    // solve();

    return 0;
}