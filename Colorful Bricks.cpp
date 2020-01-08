#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
 
#define ll long long int
#define ld long double
#define pb push_back
#define pi 3.1415926536
#define mod 1e9+7
#define mp make_pair
#define testcases ll t; cin>>t; while(t--)
 
using namespace std;
//using namespace boost::multiprecision;
 
vector<vector<ll>> dp(2001,vector<ll>(2001,-1));
 
ll give(ll n,ll m,ll k)
{
    if(n<=k) return 0;
    if(k==0) return m;
 
    if(dp[n][k]!=-1) return dp[n][k];
 
    dp[n][k]=(  (m-1)*give(n-1,m,k-1)+ give(n-1,m,k) )%998244353;
 
    return dp[n][k];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n,m,k;
    cin>>n>>m>>k;
 
    cout<<give(n,m,k)%998244353;
 
    return 0;
}
