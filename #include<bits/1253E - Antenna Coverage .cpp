#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define rep(i,st,en) for(int i=st;i<en;i++)
#define sortv(v) sort(v.begin(),v.end())
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<ll> x(n),s(n),dp(m+1);
    rep(i,0,n) cin>>x[i]>>s[i];
    dp[0]=0;
    rep(i,1,m+1) dp[i]=i;

    rep(i,1,m+1)
    {
        rep(j,0,n)
        {
            if(i>=x[j]) dp[i]=min(dp[i],max(0ll,i-x[j]-s[j])+dp[max(1ll,2*x[j]-i)-1]);
            else
            {
                if(x[j]-s[j]<=i) dp[i]=min(dp[i],dp[max(1ll,x[j]-s[j])-1]);
                else dp[i]=min(dp[i],x[j]-s[j]-i+dp[i-1]);
            }
        }
    }

    cout<<dp[m];
    return 0;
}
