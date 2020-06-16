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

ll n;
vect v(1000005,-1);
vect dp(1000005,0);
vect pref(1000005,0);
ll ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x+1] = y;
    }

    for(int i=1;i<=1000002;i++)
    {
        pref[i] += (v[i]!=-1 ? 1:0) + pref[i-1];
    }
    for(int i=1;i<=1000002;i++)
    {
        if(v[i] == -1) dp[i] = dp[i-1];
        else dp[i] = pref[i-1] - pref[max(0LL,i-1-v[i])] + dp[max(0LL,i-1-v[i])];
        ans = min(ans, dp[i-1] + pref[1000001] - pref[i-1]);
    }

    cout<<ans;
    return 0;
}
