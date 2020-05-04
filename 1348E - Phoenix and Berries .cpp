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

ll n,k,ans=0;
vect a(501),b(501);
vector<vect> dp(501,vect(501));


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];

    ll A=0,B=0;
    for(int i=1;i<=n;i++) A+=a[i],B+=b[i];

    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<k;j++)
        {
            dp[i][j]=dp[i-1][(j-a[i]%k+k)%k];
            for(int m=0;m<=min(k-1,a[i]);m++)
            {
                if((a[i]-m)%k+b[i]>=k) dp[i][j]|=dp[i-1][(j-m+k)%k];
            }
        }
    }

    for(int i=0;i<k;i++)
    {
        if(dp[n][i]) ans=max(ans,(A+B-i)/k);
    }
    cout<<ans<<"\n";
    return 0;
}
