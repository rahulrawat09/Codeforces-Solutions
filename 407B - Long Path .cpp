#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define unmap u5nordered_map
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

vect dp(1001,1),v(1001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,s=2;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];

    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int p=v[i];p<i;p++)
        {
            dp[i]+=1+dp[p];
            dp[i]%=mod;
        }
        s+=dp[i];
        s%=mod;
    }
    cout<<(s+n-1)%mod;
    return 0;
}
