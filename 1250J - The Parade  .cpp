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

ll n,k;
vect v(30001);

bool check(ll tar)
{
    if(tar==0) return 1;
    ll extra=0,c=0;

    for(ll i=1;i<=n;i++)
    {
        c+=(v[i]+extra)/tar;
        if((v[i]+extra)/tar!=0) extra=(v[i]+extra)%tar;
        else extra=v[i]%tar;
    }
    return c>=k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        ll sum=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>v[i],sum+=v[i];

        ll l=0,r=sum/k,ans=0,extra=0;

        while(l<=r)
        {
            ll m=(l+r)/2;
            //cout<<m<<" "<<check(m)<<"\n";
            if(check(m))
            {
                ans=m*k;
                l=m+1;
            }
            else r=m-1;
        }

        cout<<ans<<"\n";
    }

    return 0;
}
