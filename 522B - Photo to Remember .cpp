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
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;


int main()
{
    int n;
    cin>>n;
    int v[n+2][2],dp1[n+2][2],dp2[n+2][2];
    for(int i=1;i<=n;i++) cin>>v[i][0]>>v[i][1];
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));

    for(int i=1;i<=n;i++) 
    {
        dp1[i][0]=dp1[i-1][0]+v[i][0];
        dp1[i][1]=max(dp1[i-1][1],v[i][1]);
    }

    for(int i=n;i>=1;i--) 
    {
        dp2[i][0]=dp2[i+1][0]+v[i][0];
        dp2[i][1]=max(dp2[i+1][1],v[i][1]);
    }

    for(int i=1;i<=n;i++) cout<<(dp1[i-1][0]+dp2[i+1][0])*max(dp1[i-1][1],dp2[i+1][1])<<" ";

    return 0;
}


