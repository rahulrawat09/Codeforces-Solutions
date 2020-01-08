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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    vector<ll> a(n+1),b(n+1),dp1(n+1,0),dp2(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
 
    for(int i=1;i<=n;i++)
    {
        dp1[i]=max(dp1[i-1],a[i]+dp2[i-1]);
        dp2[i]=max(dp2[i-1],b[i]+dp1[i-1]);
    }
 
    cout<<max(dp1[n],dp2[n]);
    return 0;
}
