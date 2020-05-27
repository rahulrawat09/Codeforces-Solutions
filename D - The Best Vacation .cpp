#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll unsigned long long
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

ll n,x;
ll tot[400005]={0};
ll days[400005]={0};
ll v[400005];

ll doBinarySearch(ll ind)
{
    ll l=1,r=ind,ans;

    while(l<=r)
    {
        ll m=(l+r)/2;
        //cout<<l<<" "<<m<<" "<<r<<" "<<days[r]-days[m]<<"\n";
        if(days[ind]-days[m]>=x) l=m+1;
        else
        {
            ans=m;
            r=m-1;
        }
    }
    //cout<<ans<<" "<<ind<<"\n";
    if(x>days[ind]-days[ans-1]) return 0;
    ll extra_days = days[ind] - days[ans-1]-x;
    return tot[ind]-tot[ans-1]-(extra_days*(extra_days+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        v[i+n]=v[i];
    }

    for(int i=1;i<=2*n;i++)
    {
        tot[i]=tot[i-1]+(v[i]*(v[i]+1))/2;
        days[i]=days[i-1]+v[i];
        //cout<<days[i]<<" "<<tot[i]<<"\n";
    }

    ll ans=0;

    for(int i=2*n;i>=1;i--)
    {
        ans=max(ans,doBinarySearch(i));
        //cout<<v[i]<< " " <<ans<< "\n";
    }
    cout<<ans;
    return 0;
}
