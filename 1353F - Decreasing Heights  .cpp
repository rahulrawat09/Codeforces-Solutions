#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
#define mp make_pair
#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

ll v[101][101],n,m;

ll check(ll start)
{
    ll dp[101][101];
    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            dp[i][j]=LLONG_MAX;
    dp[0][1]=0;
    dp[1][0]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            ll curr=start+i+j-2;
            if(curr>v[i][j]||min(dp[i-1][j],dp[i][j-1])==LLONG_MAX) continue;
            dp[i][j]=v[i][j]-curr;
            dp[i][j]=dp[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        cin>>n>>m;

        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>v[i][j];

        ll ans=LLONG_MAX;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                ll start=v[i][j]-i-j+2;
                ans=min(ans,check(start));
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
