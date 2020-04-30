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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,temp=0,ans=0;
    cin>>n;
    vect v(n+2,0),dp(n+2,0);

    for(int i=1;i<=n;i++) cin>>v[i],dp[i]=min(dp[i-1]+1,v[i]);
    for(int i=n;i>=1;i--)
    {
        temp=min(temp+1,v[i]);
        ans=max(ans,min(dp[i],temp));
    }
    cout<<ans;

    return 0;
}
