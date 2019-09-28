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

vector<vector<int>> dp(202,vector<int>(2,-1));
int give(auto n,auto k,auto d,int currsum,bool x)
{
	if(dp[currsum][x]!=-1) return dp[currsum][x];
	if(currsum==n) 
	{
		if(x) return 1;
		else return 0;
	}
	if(currsum>n) return 0;
	
	int sum=0;
	int y=x;
	for(int i=1;i<k+1;i++)
	{
		if(!x&&i>=d) x=1;
		sum+=give(n,k,d,currsum+i,x);
		sum%=mod;
	}
	dp[currsum][y]=sum;
	return sum;
}

int main() 
{
 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,d; 
    cin>>n>>k>>d;
    
    cout<<give(n,k,d,0,0);
}
    
