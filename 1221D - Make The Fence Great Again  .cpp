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
        ll n;
        cin>>n;
        vect a(n+1),b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];

        ll dp[n+1][3];

        dp[1][0]=0;
        dp[1][1]=b[1];
        dp[1][2]=2*b[1];

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=2;j++)
            {
                dp[i][j]=LLONG_MAX;
                for(int k=0;k<=2;k++)
                {
                    if(a[i]+j!=a[i-1]+k)
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+j*b[i]);
                }
            }
        }
        cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<"\n";
    }

    return 0;
}
