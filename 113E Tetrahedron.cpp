#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
 
#define ll long long int
#define ld long double
#define pb push_back
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
#define testcases ll t; cin>>t; while(t--)
 
using namespace std;
//using namespace boost::multiprecision;
 
// 0 for A, 1 B , 2 C, 3 D
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    int dp[n+1][4]={0};
    dp[0][3]=1;   // 0 steps ,at D
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(k!=j)
                {
                    dp[i][j]+=dp[i-1][k];
                    if(dp[i][j]>=mod) dp[i][j]-=mod;
                }
            }
        }
    }
    cout<<dp[n][3];
    return 0;
}
