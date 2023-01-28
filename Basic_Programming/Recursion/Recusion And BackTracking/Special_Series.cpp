 #include <bits/stdc++.h>
#define ll long long int
#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define scll(x) scanf("%lld",&x)
#define pint(c) printf("%d",c)
#define pll(c) printf("%lld",c)
#define ps() printf(" ")
#define pn() printf("\n")

#define vi vector<int>
#define vii vector<pair<int,int> >
#define mp make_pair
#define pb push_back
#define ff(i,n,a) for(i=a;i<n;++i)
#define fb(i,n,a) for(i=n,i>=a;--i)
const int mxn=1e5+1;
const int M=1e9+7;
using namespace std;

void matmult(long long  a[][2], long long b[][2],long long c[][2])
{
    int i,j,k;
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            c[i][j]=0;
            for(k=0;k<2;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j])%M;
                c[i][j]=c[i][j]%M;
            }
        }
    }
 
}
void matpow(long long Z[][2],int n,long long ans[][2])
{
 
    long long temp[2][2];
    ans[0][0]=1;
    ans[1][0]=0;
    ans[0][1]=0;
    ans[1][1]=1;
    int i,j;
    while(n>0)
    {
        if(n&1)
        {
            matmult(ans,Z,temp);
            for(i=0;i<2;i++)
                for(j=0;j<2;j++)
                    ans[i][j]=temp[i][j];
        }
        matmult(Z,Z,temp);
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                Z[i][j]=temp[i][j];
 
 
        n=n/2;
    }
    return;
     
}

long long findFibonacci(long long n)
{
     
    long long fib;
    if(n>2)
    {
        long long int Z[2][2]={{1,1},{1,0}},result[2][2];
        matpow(Z,n-2,result);
        fib=result[0][0]*1 + result[0][1]*0;    
    }
    else
        fib=n-1;
         
    return fib;
}

ll getGcd(string s,ll n)
{
    ll b=0;
    for(int i=0;i<s.length();++i)
        b=(b*10+(s[i]-48))%n;
    return __gcd(n,b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    assert(1 <= t and t <= 100);
    while(t--)
    {

        string s;
        long long n;
        cin>>s;
        assert(s.size() <= 100000 and s.size() >= 1);
        cin>>n;
        assert(1 <= n and n <= 1000000000);
        ll gc=getGcd(s,n);
        cout<<findFibonacci(gc+1)<<"\n";
    }
    return 0;
}