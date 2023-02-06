#include <iostream>
#include <math.h>
using namespace std;
int main() {
	long long int num;
	int n;    
	int p=1;    
	int ans=0;
	cin >> num;    //Reading input from STDIN
	n=sqrt(num);

	while(n--)    
	{        
		if( (num+p*p)%(2*p)==0 )        
		ans++;        
		p++;    
	}   

	cout  << ans << endl;	// Writing output to STDOUT
}