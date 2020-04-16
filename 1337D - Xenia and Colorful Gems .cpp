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
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

ll cal(ll a,ll b,ll c)
{
    //cout<<(a-b)*(a-b)+(c-b)*(c-b)+(c-a)*(c-a)<<"\n";
    return (a-b)*(a-b)+(c-b)*(c-b)+(c-a)*(c-a);
}

ll give(auto& a,auto& b,auto& c)
{
    ll ans=2e18;
    for(auto i=a.begin();i!=a.end();i++)
    {
        ll y=*i;
        auto i1=b.lower_bound(y);
        if(i1==b.end()) i1--;

        auto i2=c.lower_bound(y);
        if(i2==c.end()||(i2!=c.begin()&& *i2>y)) i2--;

        ans=min(ans,cal(y,*i1,*i2));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        ll n,m,k;
        cin>>n>>m>>k;
        set<ll> a,b,c;
        for(int i=0;i<n;i++)
        {
            ll x;cin>>x;
            a.insert(x);
        }
        for(int i=0;i<m;i++)
        {
            ll x;cin>>x;
            b.insert(x);
        }
        for(int i=0;i<k;i++)
        {
            ll x;cin>>x;
            c.insert(x);
        }
        ll ans=2e18;
        ans=min(ans,give(a,b,c));
        ans=min(ans,give(b,a,c));
        ans=min(ans,give(c,b,a));
        ans=min(ans,give(a,c,b));
        ans=min(ans,give(b,c,a));
        ans=min(ans,give(c,a,b));

        cout<<ans<<"\n";
    }

    return 0;
}
