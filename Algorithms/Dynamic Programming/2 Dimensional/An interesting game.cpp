#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, dp[1 << 17], prev[1 << 17];
  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mp[x]++;
  }
  dp[0] = 1;
  for (auto [tmp, c] : mp) {
    copy(dp, end(dp), prev);
    fill(dp, end(dp), 0);
    for (int i = 0; i < 1 << 17; i++)
      dp[i] = (prev[i] + prev[c ^ i]) % 1000000007;
  }
  cout << dp[0] << endl;
}
