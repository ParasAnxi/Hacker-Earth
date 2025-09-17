#include <bits/stdc++.h>
using namespace std;
pair<long long, int> pli[2010];

void remove(pair<int, int> x, int &sz) {
  int lst = sz - 1;
  while (lst >= 0 && pli[lst].second >= x.first) {
    pli[lst].first += x.second;
    lst--;
  }
  for (int i = lst + 1; i < sz; i++)
    if (lst == -1 || pli[lst].first > pli[i].first)
      pli[++lst] = pli[i];
  sz = lst + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int te = 1, n, m, k;
  long long dp[2][2010];
  vector<pair<int, int>> sec[2][2010];
  for (int w = 1; w <= te; w++) {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
      int l, r, w;
      cin >> l >> r >> w;
      l--;
      sec[0][l].push_back({r, w});
      sec[1][r - 1].push_back({l, w});
    }
    memset(dp, 63, sizeof(dp));
    int cur = 0;
    for (int w = 0; w < k; w++, cur = !cur) {
      memset(dp[!cur], 63, sizeof(dp[!cur]));
      int sz = 0;
      if (w == 0)
        pli[sz++] = {0ll, -1};
      long long sm = 0;
      for (int i = 0; i < n; i++) {
        for (auto x : sec[0][i])
          sm += x.second;
        if (sz && sm)
          dp[!cur][i] = pli[sz - 1].first + sm;
        for (auto x : sec[1][i]) {
          remove(x, sz);
          sm -= x.second;
        }
        if (sz == 0 || pli[sz - 1].first > dp[cur][i] - sm)
          pli[sz++] = {dp[cur][i] - sm, i};
      }
    }
    long long ans = 1000000000000000000;
    for (int i = 0; i < n; i++)
      ans = min(ans, dp[cur][i]);
    if (ans > 100000000000000000)
      ans = -1;
    cout << ans << endl;
  }
  return 0;
}
