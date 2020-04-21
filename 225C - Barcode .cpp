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
vector<vector<int>> dp(1001,vector<int>(2,1e8));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y;
    cin>>n>>m>>x>>y;

    int b[m+1];
    int w[m+1];
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    memset(w,0,sizeof(w));
    memset(b,0,sizeof(b));

    for(int j=1;j<=m;j++)
    {
        ll s1=0,s2=0;   
        for(int i=1;i<=n;i++)
        {
            s1+=(v[i-1][j-1]=='#');
            s2+=(v[i-1][j-1]=='.');
        }
        b[j]=b[j-1]+s1;
        w[j]=w[j-1]+s2;
    }
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=x;j<=y;j++)
        {
            if(j>i) continue;
            dp[i][0]=min(dp[i][0],dp[i-j][1]+w[i]-w[i-j]);
            dp[i][1]=min(dp[i][1],dp[i-j][0]+b[i]-b[i-j]);
        }
    }

    cout<<min(dp[m][0],dp[m][1]);

    return 0;
}
