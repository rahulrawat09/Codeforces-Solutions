#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define fora(i,n) for(int i=0;i<n;i++)
//#define bint ll 1024_t
#define ld long double
#define vect vector<ll>
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
//#define mp make_pair
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
        ll n,m;
        cin>>n>>m;
        ll ma[m*n][2];
        memset(ma,0,sizeof(ma));

        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                ll x;
                cin>>x;
                if(x) ma[j-1+i-1][1]+=1,ma[m-j+n-i][1]+=1;
                else ma[j-1+i-1][0]+=1,ma[m-j+n-i][0]+=1;
            }
        }
        ll ans=0,x=(m*n)/2;

        for(int i=0;i<m*n;i++)
        {
            if((m+n-2)%2==1||i!=(m+n-2)/2) ans+=min(ma[i][0],ma[i][1]);
        }
        cout<<ans/2<<"\n";
    }

    return 0;
}
