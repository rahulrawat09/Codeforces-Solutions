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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    vector<string> s(n+1);
    for(int i=1;i<=n;i++) cin>>s[i];
    vector<vector<ll>> dp(n+1,vector<ll>(2,1e18));
    dp[0][1]=0;
    dp[0][0]=0;
    //cout<<dp[1][0]<<" "<<dp[1][1]<<endl;

    for(int i=1;i<=n;i++)
    {
        string x=s[i-1],rx=x;
        reverse(rx.begin(),rx.end());
        string y=s[i],ry=y;
        reverse(ry.begin(),ry.end());

        if(x<=y)
        {
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        }
        if(rx<=y)
        {
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        }
        if(x<=ry)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
        }
        if(rx<=ry)
        {
            dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
        }
    }

    if(min(dp[n][0],dp[n][1])==1e18) cout<<-1;
    else cout<<min(dp[n][0],dp[n][1]);

    return 0;
}
