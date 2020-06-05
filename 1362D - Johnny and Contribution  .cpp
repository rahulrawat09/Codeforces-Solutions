#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint ll 1024_t
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
vect v(500001);
vector<vect> r(500001),t;

bool comp(vect& a,vect& b)
{
    return a[0]<b[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        r[a].pb(b);
        r[b].pb(a);
    }

    for(int i=1;i<=n;i++)
    {
        ll x;cin>>x;
        t.pb({x,i});
    }

    sort(t.begin(),t.end(),comp);
    ll ans[n];
    ll ma[n+1]={0};

    for(int i=0;i<n;i++)
    {
        ll x=t[i][1],y=t[i][0];
        ans[i]=x;
        ma[x]=y;

        map<ll,ll> z;
        for(int j=0;j<r[x].size();j++)
        {
            if(ma[r[x][j]]!=0)
            {
                if(y<=ma[r[x][j]])
                {
                    cout<<-1;
                    return 0;
                }
                ll w=++z[ma[r[x][j]]];
            }
        }
        if(y-z.size()!=1)
        {
            cout<<-1;
            return 0;
        }
        for(int k=1;k<=z.size();k++)
        {
            if(z[k]==0)
            {
                cout<<-1;
                return 0;
            }
        }
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";

    return 0;
}
