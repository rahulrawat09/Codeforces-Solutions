#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>

#define ll unsigned long long int 
#define ld long double
#define pb push_back
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
#define wt while(t--)
#define fillarray for(int i=0;i<n;i++) 
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,k;
    cin>>t>>k;
    
    ll dp[100001];
    ll dp2[100001]={ };
    for(int i=1;i<100001;i++)
    {
    	if(i==k) dp[i]=2;
    	else if(i<k) dp[i]=1;
    	else dp[i]=dp[i-1]+dp[i-k];
    	
    	dp2[i]=dp[i]+dp2[i-1];
    	dp[i]%=mod;
    }
  
    while(t--)
    {
    	int a,b;
    	cin>>a>>b;
    	
    	cout<<(dp2[b]-dp2[a-1])%mod<<endl;
    }
}
    
