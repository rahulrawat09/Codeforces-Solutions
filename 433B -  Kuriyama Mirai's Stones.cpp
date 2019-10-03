#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>

#define ll unsigned long long int 
#define ld long double
#define pb push_back
#define pi 3.1415926536
#define mod 1e9+7
#define mp make_pair
#define wt while(t--)
#define fillarray for(int i=0;i<n;i++) 
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;

int main() 
{
    int n,m;
    cin>>n;
    
    int a[n];
    ll dp[n+1],dp2[n+1];
    
    fillarray
    {
        cin>>a[i];
        dp[i+1]=dp[i]+a[i];
    }
    
    sort(a,a+n);
    
    fillarray dp2[i+1]=dp2[i]+a[i];
    
    cin>>m;
    
    while(m--)
    {
        int a,b,t;
        cin>>t>>a>>b;
        
        if(t==1) cout<<dp[b]-dp[a-1]<<endl;
        else cout<<dp2[b]-dp2[a-1]<<endl;
    }
    
}
