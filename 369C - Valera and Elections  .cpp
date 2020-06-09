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

ll n;
vector<bool> v(100001,0);
vect dp(100001,0);
vector<vector<ll>> e(100001);

void addedge(int w)
{
    for(int i=0;i<w;i++)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        e[x].pb(y);
        e[y].pb(x);
        if(z==2) v[x]=1,v[y]=1;
    }
}

int dfs(ll i,ll p)     // dfs
{
    ll ans=0;
    if(v[i]) ans++;
    for(ll& j:e[i])
    {
        if(j!=p) ans+=dfs(j,i);
    }
    dp[i]=ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    addedge(n-1);
    dp[1]=dfs(1,0);

    vect ans;
    for(int i=1;i<=n;i++) if(dp[i]==1) ans.pb(i);
    cout<<ans.size()<<"\n";
    for(auto& i:ans) cout<<i<<" ";
    return 0;
}
