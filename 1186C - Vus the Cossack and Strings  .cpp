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

    string a,b;
    cin>>a>>b;

    ll n=a.length(),m=b.length(),o=0,ans=0;
    for(auto& i:b) o+=(i=='1');

    ll dp[n+1]={0};
    for(int i=0;i<n;i++) dp[i+1]=dp[i]+(a[i]=='1');

    for(int i=m;i<=n;i++) ans+=((o+dp[i]-dp[i-m])%2==0);

    cout<<ans;

    return 0;
}
