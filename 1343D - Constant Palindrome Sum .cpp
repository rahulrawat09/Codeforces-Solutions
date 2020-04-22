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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        ll n,k,ans;
        cin>>n>>k;
        vect v(n);

        vect p(2*k+5,0),m(2*k+5,0);
        for(ll& i:v) cin>>i;

        for(int i=0;i<n/2;i++)
        {
            ll s=v[i]+v[n-i-1];
            m[s]++;
            ll x=min(v[i],v[n-i-1])+1,y=max(v[i],v[n-i-1])+k;

            p[x]++;
            p[y+1]--;
        }

        for(int i=2;i<2*k+5;i++) p[i]+=p[i-1];

        ans=n/2;
        for(ll x=2;x<=2*k;x++)
        {
            ans=min(ans,p[x]-m[x]+2*(n/2-p[x]));
        }

        cout<<ans<<"\n";
    }

    return 0;
}
