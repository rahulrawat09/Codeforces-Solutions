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

ll n;
vector<vect> e(200001);
vect visited(200001,0),b(200001);
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
bool comp(ll a,ll c)
{
    return b[a]<b[c];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    addedge(n-1);
    vect v(n+1),a;
    for(int i=0;i<n;i++) cin>>v[i],b[v[i]]=i;

    for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end(),comp);

    queue<ll> q;
    q.push(1);
    visited[1]=1;
    while(!q.empty())
    {
        ll l=q.size();
        while(l--)
        {
            ll x=q.front();
            a.pb(x);
            q.pop();
            for(auto& i:e[x])
            {
                if(!visited[i])
                {
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
        if(v[i]!=a[i])
        {
            cout<<"NO";
            return 0;
        }
    cout<<"YES";
    return 0;
}
