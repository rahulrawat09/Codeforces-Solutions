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

bool comp(vect& a,vect& b)
{
    return a[0] < b[0];
}
ll n;
vector<vect> v(3005,vect(2));
ll dp[3005][3005];

ll dfs(ll i,ll last)
{
    if(i>n) return 0;
    if(dp[i][last] != LLONG_MAX) return dp[i][last];
    dp[i][last] = min(v[i][0]-v[last][0]+dfs(i+1,last),v[i][1]+dfs(i+1,i));
    return dp[i][last];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j] = LLONG_MAX;
    for(int i=1;i<=n;i++) cin>>v[i][0]>>v[i][1];
    sort(v.begin()+1,v.begin()+n+1,comp);

    cout<<v[1][1]+dfs(2,1);
    return 0;
}
