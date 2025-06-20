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
#define MX 5000000
bool prime[MX + 1];
int res[MX + 1];
void solve() {
  memset(prime, 1, sizeof(prime));
  for (ll i = 2; i * i <= MX; ++i)
    if (prime[i])
      for (ll j = i * i; j <= MX; j += i)
        prime[j] = 0;
  prime[0] = 0, prime[1] = 0, prime[2] = 0;

  for (ll i = 0; i <= MX; i++)
    res[i] = prime[i] ? (res[i - 1] + (i >> 1)) % MOD : res[i - 1];
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
    cout << res[x] << "\n";
  }
  // solve();
  return 0;
}