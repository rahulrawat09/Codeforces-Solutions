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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vect> v(1002,vect(1002,0));
    vector<vect> dp1(1002,vect(1002,0));
    vector<vect> dp2(1002,vect(1002,0));
    vector<vect> dp3(1002,vect(1002,0));
    vector<vect> dp4(1002,vect(1002,0));

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>v[i][j];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) dp1[i][j]=v[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++) dp2[i][j]=v[i][j]+max(dp2[i+1][j],dp2[i][j-1]);
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--) dp3[i][j]=v[i][j]+max(dp3[i-1][j],dp3[i][j+1]);
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--) dp4[i][j]=v[i][j]+max(dp4[i+1][j],dp4[i][j+1]);
    }

    ll ans=0;

    for(int i=2;i<n;i++) for(int j=2;j<m;j++) ans=max(ans, dp1[i][j-1]+dp4[i][j+1]+dp2[i+1][j]+dp3[i-1][j]),ans=max(ans, dp1[i-1][j]+dp4[i+1][j]+dp2[i][j-1]+dp3[i][j+1]);

    cout<<ans;

    return 0;
}
