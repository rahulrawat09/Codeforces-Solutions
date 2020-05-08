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

vect v(500005),dp(500005,0);
ll n,m,mod,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];

    if(n==1)
    {
        cout<<v[1];
        return 0;
    }

    sort(v.begin()+1,v.begin()+1+n,greater<ll>());
    for(int i=1;i<=n;i++)dp[i]=dp[i-1]+v[i];

    ll ans=LLONG_MIN;
    for(int i=1;i<n;i++)
    {
        //cout<<dp[i]<<" ";
        ans=max(ans,dp[i]-(dp[n]-dp[i]));
    }
    cout<<ans;
    return 0;
}
