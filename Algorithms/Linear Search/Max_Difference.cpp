#include<bits/stdc++.h>
using namespace std;
 
int main() {
  	int t = 1;
  	cin >> t;
  	while(t--) 
	{
    	int n; 
		cin >> n;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++) 
			cin >> a[i];
    	sort(a.begin(), a.end());
    	if(n <= 3) 
		    cout << a[n - 1] -  a[0] << endl;
    	else
      		cout << a[n - 1] - a[0] + a[n - 2] - a[1] << "\n";
    }
  	return 0;
}