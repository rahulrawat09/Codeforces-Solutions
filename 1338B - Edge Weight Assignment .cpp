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

ll n,odd=0,even=0,start=0,leaf=0,x=0;
vector<bool> visited(100001,0);
vector<vector<ll>> e(100001);

void addedge()
{
    ll x,y;
    cin>>x>>y;
    e[x].pb(y);
    e[y].pb(x);
}

bool check(ll i)
{
    for(auto j:e[i]) if(j==start) return 1;
    return 0;
}

ll dfs(ll i,ll d)     // dfs
{
    if(visited[i]) return 0;
    visited[i]=1;
    if(e[i].size()==1&&i!=start)
    {
        if(d%2) odd++;
        else even++;
        return 1;
    }

    ll c=0;
    for(auto& j:e[i])
    {
        c+=dfs(j,d+1);
    }
    if(c>=1||check(i)) x++;

    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0;i<n-1;i++) addedge();

    for(int i=1;i<=n;i++)
    {
        if(e[i].size()==1)
        {
            start=i;
            leaf++;
        }
    }

    dfs(start,0);

    if(even&&!odd) cout<<1<<" "<<n-1-leaf+x<<"\n";
    else cout<<3<<" "<<n-1-leaf+x;

    return 0;
}
