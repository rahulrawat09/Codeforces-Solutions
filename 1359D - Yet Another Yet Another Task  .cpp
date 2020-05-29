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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    map<ll,ll> m;
    vect v(n);
    for(ll& i:v) cin>>i,m[i]++;

    ll ans=0;

    for(ll x=1;x<=30;x++)
    {
        ll curr=0;
        if(!m[x]) continue;
        for(int i=0;i<n;i++)
        {
            if(v[i]>x) curr=0;
            else curr+=v[i];
            curr=max(curr,0ll);
            ans=max(ans,curr-x);
        }
    }
    cout<<ans;
    return 0;
}
