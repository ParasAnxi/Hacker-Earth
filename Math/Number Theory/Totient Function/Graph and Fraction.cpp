#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using cd = complex<double>;
using pii = pair<int, int>;
using psi = pair<string, int>;
using pll = pair<ll, ll>;
using ppii = pair<int, pii>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using pis = pair<int, string>;
using vs = vector<string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using umii = unordered_map<int, int>;
using umcvi = unordered_map<char, vi>;
using umci = unordered_map<char, int>;
#define pb push_back
#define MOD 1000000007
#define LMOD 1000000000000000007LL

void solve() {
  ll n, m, a, b;
  cin >> n >> m;
  ll M = m, phi[n + 5], ans[n + 5];
  vll adj[n + 5];
  while (M--) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  for (ll i = 1; i <= n; i++)
    phi[i] = i;
  for (ll p = 2; p <= n; p++) {
    if (phi[p] == p) {
      phi[p] = p - 1;
      for (ll i = 2 * p; i <= n; i += p)
        phi[i] = (phi[i] / p) * (p - 1);
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      ans[i] = (n / i) * phi[i];
      ans[i] /= 2;
    } else
      ans[i] = 0;
  }
  for (ll i = 1; i <= n; i += 2) {
    for (ll j = 0; j < adj[i].size(); j++) {
      ll v = adj[i][j];
      if (v % 2 == 1 and v <= i and __gcd(v, i) == 1)
        ans[i] -= (n / i);
    }
  }
  ans[1] = 0;
  for (ll i = 1; i <= n; i++)
    cout << ans[i] << " ";
  cout << "\n";
}
int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  // solve();
  return 0;
}