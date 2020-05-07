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
#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

ll dp[1LL<<20][20]={0};
ll mp[19][19]={0};
vect a(18);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i-1];
    for(int i=0;i<k;i++)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        mp[x-1][y-1]=z;
    }

    for(ll i=0;i<n;i++) dp[1LL<<i][i]=a[i];

    for(ll mask=0;mask<(1LL<<n);mask++)
    {
        for(ll last=0;last<n;last++)
        {
            if(!(mask&(1LL<<last))) continue;
            for(ll now=0;now<n;now++)
            {
                if(mask&(1LL<<now)) continue;
                ll x=mask|(1LL<<now);
                dp[x][now]=max(dp[x][now],dp[mask][last]+a[now]+mp[last][now]);
            }
        }
    }

    ll ans=0;
    for(ll mask=0;mask<(1LL<<n);mask++)
    {
        if(__builtin_popcount(mask)==m)
        {
            for(int i=0;i<n;i++) ans=max(ans,dp[mask][i]);
        }
    }
    cout<<ans;

    return 0;
}
