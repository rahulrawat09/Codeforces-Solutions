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
#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

ll n,m;
ll v[301];
ll p[301][2];
ll ans=INT_MIN;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=m;i++) cin>>p[i][0]>>p[i][1];
    vect f;
    for(int i=1;i<=n;i++)
    {
        vect ind;
        ll mini=v[i];
        for(int j=1;j<=m;j++)
        {
            if(i<p[j][0]||i>p[j][1]) continue;
            ind.pb(j);
            mini--;
        }

        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            ll maxi=v[j];
            for(auto& k:ind)
            {
                if(j<p[k][0]||j>p[k][1]) continue;
                maxi--;
            }
            if(ans<maxi-mini)
            {
                ans=maxi-mini;
                f=ind;
            }
        }
    }

    if(ans==INT_MIN) cout<<0<<"\n";
    else cout<<ans<<"\n";
    cout<<f.size()<<"\n";
    for(auto& i:f) cout<<i<<" ";
    return 0;
}
