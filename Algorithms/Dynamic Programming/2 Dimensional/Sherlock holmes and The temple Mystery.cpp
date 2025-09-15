#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, N, arr[100];
  unordered_set<int> uS[2];
  cin >> t;
  while (t--) {
    cin >> N;
    for (int i = 0; i < N; i++)
      cin >> arr[i];
    uS[0].clear();
    uS[1].clear();
    uS[0].insert(arr[0]);
    for (int i = 1; i < N; i++) {
      int cur = i & 1, prev = cur ^ 1;
      for (auto e : uS[prev]) {
        uS[cur].insert(abs(e - arr[i]));
        uS[cur].insert(abs(e + arr[i]));
      }
      uS[prev].clear();
    }
    cout << (uS[(N - 1) & 1].count(0) ? "YES" : "NO") << endl;
  }
  return 0;
}
