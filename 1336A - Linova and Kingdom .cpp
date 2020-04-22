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

vector<bool> visited(200001,0);
vector<vector<ll>> e(200001);
vector<ll> v;
ll n,k,ans=0;

void addedge()
{
    ll x,y;
    cin>>x>>y;
    e[x].pb(y);
    e[y].pb(x);
}

ll dfs(ll i,ll d)
{
    if(visited[i]) return 0;

    visited[i]=1;

    ll s=0;
    for(auto& j:e[i])
    {
        s+=dfs(j,d+1);
    }
    v.pb(d-s);
    return s+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i=0;i<n-1;i++) addedge();

    dfs(1,0);
    sort(v.begin(),v.end(),greater<ll>());

    for(int i=0;i<k;i++) ans+=v[i];

    cout<<ans;

    return 0;
}
