#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
 
#define ll long long int
#define ld long double
#define pb push_back
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
#define testcases ll t; cin>>t; while(t--)
 
using namespace std;
//using namespace boost::multiprecision;
 
vector<int> d[2010];
vector<vector<ll>> dp(2001,vector<ll>(2001,-1));
 
ll give(ll n, ll k)
{
    if(k==1) return 1;
    if(dp[n][k]!=-1) return dp[n][k];
    ll ans=0;
    for(int i=0;i<d[n].size();i++)
    {
        ans+=give(d[n][i],k-1);
        ans%=mod;
    }
    dp[n][k]=ans;
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    for(int i = 1; i < 2010; i++)
        for(int j = i; j < 2010; j+=i)
            d[j].pb(i);
 
    ll n,k,ans=0;
    cin>>n>>k;
 
    for(int i=1;i<=n;i++)
    {
        ans+=give(i,k);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
