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

ll n,h,l,r;
ll dp[2002][2002];
ll v[2002];

ll dfs(ll i,ll m)
{
    if(i>n)
    {
        if(m>=l&&m<=r&&i!=1) return 1;
        return 0;
    }
    if(dp[i][m]!=-1) return dp[i][m];

    ll c=0;
    if(m>=l&&m<=r&&i!=1) c=1;

    c+=max(dfs(i+1,(m+v[i])%h),dfs(i+1,(m+v[i]-1)%h));
    dp[i][m]=c;

    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>h>>l>>r;
    memset(dp,-1,sizeof(dp));

    for(int i=1;i<=n;i++) cin>>v[i];

    cout<<dfs(1,0);

    return 0;
}
