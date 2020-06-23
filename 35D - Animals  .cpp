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
#define mp make_pair
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

ll n, x;
vect v(105);
ll dp[105][10005];

ll dfs(ll i,ll k)
{
    if(i>n||k==0) return 0;
    if(dp[i][k] != -1) return dp[i][k];

    dp[i][k] = dfs(i+1,k);
    if(k>=(n-i+1)*v[i]) dp[i][k] = max(dp[i][k],1+dfs(i+1,k-(n-i+1)*v[i]));
    return dp[i][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>v[i];
    memset(dp,-1,sizeof(dp));

    cout<<dfs(1,x);

    return 0;
}
