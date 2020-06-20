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
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
#define mod ll(1e9+7)
#define mp make_pair
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

bool check(ll x,ll s,vect& v,ll k)
{
    ll c = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(s)
        {
            if(v[i]<=x)
            {
                c++;
                s^=1;
            }
        }
        else
        {
            c++;
            s^=1;
        }
    }
    return c>=k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;
    vect v(n);
    for(ll& i:v) cin>>i;

    ll l = 0, r = 1e9, ans;

    while(l<=r)
    {
        ll m = (l+r)/2;

        if(check(m,0,v,k)||check(m,1,v,k))
        {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout<<ans;

    return 0;
}
