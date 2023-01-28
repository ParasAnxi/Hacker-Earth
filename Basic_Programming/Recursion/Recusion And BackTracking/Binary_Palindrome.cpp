#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define db(x)
#define el cout << '\n';
typedef long long ll;
typedef vector<unsigned long> vi;
typedef vector<string> vs;
typedef map<long, long> mii;
typedef map<char, long> mci;
typedef unordered_set<long> usi;
typedef set<long> si;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
vi v;
ll bit_to_int(string p)
{
    ll sz = p.size(), ans = 0;
    for (long i = 0; i < sz; i++)
    {
        ans += ((p[i] - 48) * pow(2, sz - i - 1));
    }
    return ans;
} 
void bin(string p, ll si, ll sz)
{
    if (si <= 0)
    {
        string res1 = p;
        ll x = res1.size();
        ll y = sz % 2 ? 2 : 1;
        for (long i = x - y; i >= 0; i--)
        {
            res1.push_back(res1[i]);
        }
        ll res = bit_to_int(res1);
        v.push_back(res);
        return;
    }
    p.push_back('0');
    bin(p, si - 1, sz);
    p.pop_back();
    p.push_back('1');
    bin(p, si - 1, sz);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    v.push_back(0);
    for (long i = 1; i < 32; i++)
    {
        string s = "", p = "1";
        bin(p, ceil(i / 2.0) - 1, i);
    }
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        auto it = lower_bound(v.begin(), v.end(), n);
        ll y = *it;
        it--;
        ll x = *it;
        cout << min(abs(n - x), abs(n - y));
        el
    }
    return 0;
}