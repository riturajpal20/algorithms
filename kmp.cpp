#include <bits/stdc++.h>
using namespace std;
map<int, pair<int, int>> mp;
int ti = 0;
vector<int> pref(string &s)
{
    vector<int> prefarray(s.length(), 0);
    for (int i = 1; i < s.length(); i += 1)
    {
        int prev_ind = prefarray[i - 1];
        while (prev_ind > 0 && s[i] != s[prev_ind])
        {
            prev_ind = prefarray[prev_ind - 1];
        }
        if (s[i] == s[prev_ind])
        {
            prev_ind += 1;
        }
        prefarray[i] = prev_ind;
    }
    return prefarray;
}
int kmpfunc(string &s, string &t, vector<int> &prefarray)
{
    // s is the smaller string and t is the bigger string 
    
    int pos = -1;
    int i = 0;
    int j = 0;
    while (i < t.size())
    {
        if (t[i] == s[i])
        {
            j++;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = prefarray[j - 1];
            }
            else
            {

                i += 1;
            }
        }
        if (j == s.size())
        {
            pos = i - s.length();
            break;
        }
    }
    return pos;
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