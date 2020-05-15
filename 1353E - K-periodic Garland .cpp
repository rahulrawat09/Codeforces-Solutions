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
 
    testcases
    {
        ll n,k,o=0;
        cin>>n>>k;
        string s;
        cin>>s;
        s="*"+s;
 
        ll dp[n+1][2];
        ll pref[n+1]={0};
        memset(dp,0,sizeof(dp));
 
        for(int i=1;i<=n;i++) pref[i]+=pref[i-1]+(s[i]=='1');
        for(int i=1;i<=n;i++)
        {
            if(i<=k)
            {
                dp[i][1]=(s[i]=='0')+pref[i-1];
                dp[i][0]=(s[i]=='1')+min(dp[i-1][0],dp[i-1][1]);
                continue;
            }
            dp[i][1]=(s[i]=='0')+min(dp[i-k][1]+pref[i-1]-pref[i-k],pref[i-1]);
            dp[i][0]=(s[i]=='1')+min(dp[i-1][0],dp[i-1][1]);
        }
        
        cout<<min(dp[n][0],dp[n][1])<<"\n";
    }
 
    return 0;
}
