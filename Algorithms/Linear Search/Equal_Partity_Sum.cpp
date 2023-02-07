#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,
		sum = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i & 1)
			a[i] *= -1;
		sum += a[i];
	}
	if (sum == 0)
	{
		cout << "YES\n";
		return;
	}
	if (sum & 1)
	{
		cout << "NO\n";
		return;
	}
	sum /= 2;
	map<int, int> mp;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		x += a[i];
		if (mp[x - sum] > 0)
		{
			cout << "YES\n";
			return;
		}
		mp[x] = 1;
	}
	cout << "NO\n";
	return;
}
int32_t main()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
}