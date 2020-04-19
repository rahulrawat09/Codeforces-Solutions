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

    // int k=0;
    // testcases
    // {
        

    //     cout<<"Case #"<<++k<<": "<<ans<<"\n";
    // }

    ll n,m;
    cin>>n>>m;
    vect v(n);
    for(ll& i:v) cin>>i,i%=m;

    if(n>m) 
    {
        cout<<"YES";
        return 0;
    }

    sort(v.begin(),v.end());
    vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
    //dp[0][0]=1;

    for(ll i=1;i<=n;i++)
    {
        //cout<<v[i-1]<<"  ";
        dp[i][v[i-1]]=1;
        for(ll j=0;j<=m;j++)
        {
            if(dp[i-1][j])
            {
                dp[i][j]=1;
                dp[i][(j+v[i-1])%m]=1;
            }
           // cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }

    if(dp[n][0]) cout<<"YES";
    else cout<<"NO";

    return 0;
}
