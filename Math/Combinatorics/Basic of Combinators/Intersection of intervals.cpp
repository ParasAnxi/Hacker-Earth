#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int s[1000005], f[1000005];
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n + n; ++i)
    	cin >> s[i];
    f[1] = 1;
    for(int i = 3; i <= n + n; i += 2) 
    	f[i] = (1ll * f[i - 2] * i) % mod;
    for(int i = 2; i <= n + n; ++i) 
	{
    	int cnt = f[n + n - 1];
    	cnt = (cnt + mod - (1ll * f[i - 2] * f[n + n - i] % mod)) % mod;
    	ans = (ans + 1ll * (s[i] - s[i - 1]) * cnt) % mod;
    }
    cout << ans << endl;
    return 0;
}
