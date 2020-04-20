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
#define S second
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

bool comp(pair<pair<ll,ll>,ll>& a,pair<pair<ll,ll>,ll>& b)    // pairs
{
    return a.F.F<b.F.F;
}

ll n,w,h,ans=0;
vector<pair<pair<ll,ll>,ll>>  v;
vector<pair<ll,ll>> dp(5001,{0LL,-1});

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>w>>h;
    v.resize(n+1);
    for(int i=1;i<n+1;i++) cin>>v[i].F.F>>v[i].F.S,v[i].S=i;
    sort(v.begin(),v.end(),comp);
    for(int i=1;i<=n;i++) if(w<v[i].F.F&&h<v[i].F.S) dp[i].F=1;

    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i].F);
        for(int j=i+1;j<=n;j++)
        {
            if(dp[j].F>0&&v[j].F.F>v[i].F.F&&v[j].F.S>v[i].F.S)
            {
                if(1+dp[i].F>dp[j].F)
                {
                    dp[j].F++;
                    dp[j].S=i;
                }
                ans=max(ans,dp[j].F);
            }
        }
    }
    ll i=n,x=ans;
    vector<ll> p;
    while(i>0)
    {
        if(dp[i].F==ans)
        {
            p.pb(v[i].S);
            ans=dp[dp[i].S].F;
            i=dp[i].S+1;
        }
        i--;
    }
    reverse(p.begin(),p.end());
    cout<<x<<"\n";
    if(x==0) return 0;
    for(ll& j:p) cout<<j<<" ";
    
    return 0;
}
