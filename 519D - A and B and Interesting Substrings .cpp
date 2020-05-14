#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
#define mp make_pair
#define mod int(998244353)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> c(26,0);
    string s;
    for(ll& i:c) cin>>i;
    cin>>s;
    ll n=s.length(),ans=0;

    vector<ll> dp(n+1,0);
    for(int i=0;i<n;i++) dp[i+1]=dp[i]+c[s[i]-'a'];

    vector<vector<ll>> v(26);

    for(int i=1;i<=n;i++)
    {
        v[s[i-1]-'a'].pb(i);
    }

    for(int i=0;i<26;i++)
    {
        map<ll,ll> m;
        if(v[i].empty()) continue;

        m[dp[v[i][0]]]=1;
        for(int j=1;j<v[i].size();j++)
        {
            ans+=m[dp[v[i][j]-1]];
            m[dp[v[i][j]]]++;
        }
    }

    cout<<ans;
    return 0;
}
