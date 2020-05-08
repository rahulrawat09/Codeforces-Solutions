#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define unmap unordered_map
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
//#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

vect v(505);
ll dp[2][505][505];
ll n,m,mod,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp,0,sizeof(dp));
    cin>>n>>m>>b>>mod;
    for(int i=1;i<=n;i++) cin>>v[i];

    dp[0][0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            //ll bugs=0;
            for(int k=0;k<=b;k++)
            {
                dp[1][j][k]=dp[0][j][k];
                if(j>0&&k>=v[i]) dp[1][j][k]+=dp[1][j-1][k-v[i]];
                dp[1][j][k]%=mod;
            }
        }
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=b;k++) dp[0][j][k]=dp[1][j][k];
        }
    }

    ll ans=0;
    for(int i=0;i<=b;i++) ans+=dp[1][m][i],ans%=mod;
    cout<<ans;
    return 0;
}
