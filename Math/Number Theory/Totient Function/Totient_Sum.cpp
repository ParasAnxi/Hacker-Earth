#include <bits/stdc++.h>
using namespace std;
#define NIMISH                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define UPADHYAY \
    int t;       \
    cin >> t;    \
    while (t--)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ll long long int
#define ld long double
#define ya "YES\n"
#define na "NO\n"
#define b1(con) ((con) ? ya : na)
#define cr(k) cout << fixed << setprecision(10) << k;
#define pr pair<ll, ll>
#define ff first
#define ss second
ld pi = 3.14159265358979323846;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}

template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }

template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...) 20
#endif

const ll mex = 2e5, mod = 1e9 + 7;
ll etf[mex];

int main()
{
    for (ll i = 1; i < mex; i++)
        etf[i] = i;
    for (ll i = 2; i < mex; i++)
    {
        if (etf[i] == i)
        {
            for (ll j = i; j < mex; j += i)
                etf[j] *= (i - 1), etf[j] /= i;
        }
    }
    ll sum = 0;
    for (ll i = 1; i < mex; i++)
    {
        sum = (sum + etf[i]) % mod;
        etf[i] = (etf[i - 1] + sum * etf[i]) % mod;
        ;
    }
    UPADHYAY
    {
        ll n;
        cin >> n;
        cout << etf[n] << "\n";
    }
}