#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vii vector<pair<ll, ll>>
#define ff(i, a, b) for (ll i = a; i < b; ++i)
#define fr(i, a, b) for (ll i = a; i >= b; --i)
#define vs vector<string>
#define vec vector<ll>
#define mpll map<ll, ll>
#define mpcl map<char, ll>
#define mpsl map<string, ll>
#define pb push_back
#define vvi vector<vector<ll>>
#define bs(v, a) binary_search(v.begin(), v.end(), a)
// #define endl

#define srtv(v, n) sort(v.begin(), v.end())
#define isortarry(arr, n) sort(arr, arr + n)
#define dsortarry(arr, n) sort(arr, arr + n, greater<int>())
#define mod 1000000007

ll f(vector<ll> &arr, ll ind, ll k, vector<ll> &dp)
{
    if (ind == 0)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    ll maxi = INT_MAX;
    ff(i, 1, k + 1)
    {
        if (ind - i >= 0)
        {
            ll j = f(arr, ind - i, k, dp) + abs(arr[ind] - arr[ind - i]);
            maxi = min(maxi, j);
        }
    }
    return dp[ind] = maxi;
}
// get total set bit
ll getsetbit(ll num)
{
    return __builtin_popcount(num);
}
// check whether it is possible to place cow at min distance of mid or not
bool check(int x, vec &v, ll n, ll k)
{
    ll cnt = 1;
    ll co = v[0];
    ff(i, 1, n)
    {
        if (v[i] - co >= x)
        {
            cnt++;
            co = v[i];
        }
        if (cnt == k)
        {
            return true;
        }
    }
    return false;
}
/*************FIND GCD OF TWO NUMBERS*************/
ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }

    else
    {
        return gcd(a, b % a);
    }
}
/*************FIND LCM OF TWO NUMBERS*************/
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
// extended euclid
ll egcd(int a, int b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    };
    ll x1, y1;
    ll d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
/*************POWER OF A TO B*************/
// ll ul = 1e9 + 7;
ll power(ll a, ll b)
{

    ll ans = 1;
    while (b != 0)
    {
        if (b & 1)
        {
            b--;
            ans = (ans * a);
        }
        else
        {
            a = (a * a);
            b /= 2;
        }
    }
    return ans;
}

/*************FIND NUMBER OF DIGIT IN A*************/
ll digits(ll n)
{
    ll k = 0;

    ll q = n;
    while (q > 0)
    {
        q = q / 10;
        k++;
    }
    return k;
}
bool prime(ll n)
{
    if (n == 1 || n == 0)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    ff(i, 2, sqrt(n) + 1)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void factor(ll p, vector<ll> &ans)
{

    for (int i = 2; i * 1ll * i <= p; ++i)
    {
        if (p % i == 0)
        {
            ans.pb(i);
            if (i != p / i)
            {
                ans.pb(p / i);
            }
        }
    }
}

/*************YOUR CODE GOES HERE*************/
// const int N = (int)1e5 + 5;
// int a[N], b[N];
// ll xxx = 1e9;
// string s;
// vec parent(1e5 + 1)
map<ll, ll> parent;
void bfs(ll root, vector<ll> adj[])
{
    queue<pair<ll, ll>> q;
    q.push({root, -1});
    ll height = 0;
    ll maxi = INT_MIN;
    // parent[root] = -1;
    while (!q.empty())
    {

        ll sz = q.size();

        // maxi = max(maxi, sz);

        ll node = q.front().first;
        ll par = q.front().second;
        q.pop();
        parent[node] = par;

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

// factorial function
ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
// ll mod = 1e9 + 7;

// ll n;
map<ll, vector<ll>> mp;
ll ti = 0;
// vec d;
map<ll, ll> m;
vector<ll> d(1e5 + 1);
ll res = 0;
ll N = 2e5 + 1;
// vector<ll> path(N, 0);
ll c = 0;
// ll N = 2e5 + 1;
vector<ll> path(N, 0);
void dfs(ll node, ll par, vector<ll> adj[])
{

    for (auto it : adj[node])
    {
        // if it not equal to parent
        if (it == par)
        {
            continue;
        }
        path[it] = 1 + path[node];
        dfs(it, node, adj);
    }
}
// finding square root of number
ll square(ll x)
{
    if (x == 0)
    {
        return 0;
    }
    ll s = 0;
    ll e = x;
    long long int mid = s + (e - s) / 2;
    long long ans = -1;
    while (s <= e)
    {
        long long p = mid * mid;
        if (p == x)
        {
            return mid;
        }
        if (p < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
// recurence of 0-1 knapsack
ll knapsack(ll ind, vec &page, vec &price, ll x, vector<vector<ll>> &dp)
{
    if (ind == 0)
    {
        if (x >= price[0])
        {
            return page[0];
        }
        return 0;
    }
    if (dp[ind][x] != -1)
    {
        return dp[ind][x];
    }
    ll notpick = 0 + knapsack(ind - 1, page, price, x, dp);
    ll pick = INT_MIN;
    if (x >= price[ind])
    {
        pick = page[ind] + knapsack(ind - 1, page, price, x - price[ind], dp);
    }
    ll ans = max(pick, notpick);
    return dp[ind][x] = (ans) % mod;
}

// recurence of josephus problem
void Josh(vector<ll> &person, ll k, ll index, vec &ans)
{
    // Base case , when only one person is left
    if (person.size() == 1)
    {
        // cout << person[0] << endl;
        ans.pb(person[0]);
        return;
    }

    // find the index of first person which will die
    index = ((index + k) % person.size());
    ans.pb(person[index]);

    // remove the first person which is going to be killed
    person.erase(person.begin() + index);

    // recursive call for n-1 persons
    Josh(person, k, index, ans);
}

ll mods = 1000000007;

// all prime factor of a number
const ll N1 = 1e6 + 3;
vec allfs;
ll spf[N1 + 1];
void allf(ll n)
{
    // ll spf[N1 + 1];
    ff(i, 2, N1 + 1)
    {
        spf[i] = i;
    }
    for (ll i = 2; i * i <= N1; i++)
    {
        if (spf[i] != i)
        {
            continue;
        }

        for (ll j = i * i; j <= N1; j += i)
        {

            if (spf[j] == j)
            {
                spf[j] = i;
            }
        }
    }
    while (n != 1)
    {
        allfs.pb(spf[n]);
        n = n / spf[n];
    }
}
// find all prime upto number n
vec allp;
ll N2 = 1e6 + 3;
void sieve(int n)
{

    bool prime[N2 + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {

            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            allp.pb(p);
        }
    }
}
// comperator function

bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
    if (p1.first > p2.first)
    {
        return true;
    }
    else if (p1.first == p2.first && p1.second < p2.second)
    {
        return true;
    }
    return false;
}
void dp_on_tree(ll node, vector<ll> adj[], vector<ll> &dp, ll par)
{
    dp[node] = 1;
    for (auto it : adj[node])
    {
        if (it == par)
        {
            continue;
        }
        dp_on_tree(it, adj, dp, node);
        dp[node] += dp[it];
    }
}
// ll sum = 0;

// ll mod = 109 + 7;
void binarylifting(ll node, ll par, vector<ll> adj[], vector<vector<ll>> &dp)
{
    dp[node][0] = par;
    ff(i, 1, 20)
    {

        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }
    // dfs
    for (auto it : adj[node])
    {
        if (it == par)
        {
            continue;
        }
        binarylifting(it, node, adj, dp);
    }
}
void dfs1(ll node, ll par, vector<ll> adj[], vec &p)
{

    for (auto it : adj[node])
    {
        // if it not equal to parent
        if (it == par)
        {
            continue;
        }
        p[it] = 1 + p[node];
        dfs1(it, node, adj, p);
    }
}
void dfs2(ll node, ll par, vector<ll> adj[], vec &q)
{

    for (auto it : adj[node])
    {
        // if it not equal to parent
        if (it == par)
        {
            continue;
        }
        q[it] = 1 + q[node];
        dfs2(it, node, adj, q);
    }
}

void solve()
{
    ll lastnode = 1;
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
    dfs(1, -1, adj);
    ff(i, 1, path.size() + 1)
    {
        if (path[i] > path[lastnode])
        {
            lastnode = i;
        }
    }
    path.assign(N, 0);
    dfs(lastnode, -1, adj);
    ll firstnode = lastnode;
    // cout << *max_element(path.begin(), path.end());
    ff(i, 1, path.size() + 1)
    {
        if (path[i] > path[firstnode])
        {
            firstnode = i;
        }
    }
    vec p(n + 1, 0), q(n + 1, 0);
    dfs1(lastnode, -1, adj, p);
    dfs2(firstnode, -1, adj, q);
    ff(i, 1, n + 1)
    {
        cout << max(p[i], q[i]) << " ";
    }
    // cout << firstnode << " " << lastnode;
}

/*************YOUR CODE GOES HERE*************/
int main()
{
    // ll t;
    // cin >> t;

    // while (t--)
    // {
    //     solve();
    // }
    solve();

    return 0;
}