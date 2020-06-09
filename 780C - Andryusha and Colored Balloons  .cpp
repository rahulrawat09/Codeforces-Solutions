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
vector<ll> visited(200001,0);
vector<vector<ll>> e(200001);

void addedge(int z)
{
    for(int i=0;i<z;i++)
    {
        ll x,y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
}

void dfs(ll i,ll p,ll c)     // dfs
{
    if(visited[i]) return;
    visited[i]=c;

    ll x=1;
    for(ll j=0;j<e[i].size();j++)
    {
        if(x!=visited[i]&&x!=visited[p]) dfs(e[i][j],i,x);
        else j--;
        if(e[i][j]!=p) x++;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    addedge(n-1);

    ll m=0;
    for(int i=1;i<=n;i++) m=max(m,(ll)e[i].size()+1);

    dfs(1,0,1);
    cout<<m<<"\n";
    for(int i=1;i<=n;i++) cout<<visited[i]<<" ";

    return 0;
}
