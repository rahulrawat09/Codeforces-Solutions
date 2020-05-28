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

    ll n,k;
    cin>>n>>k;
    vect v(n);
    for(ll& i:v) cin>>i;
    map<ll,ll> m;
    m[0]=1;
    ll sum=0,ans=0;

    for(ll i=0;i<n;i++)
    {
        sum+=v[i];
        ll c=1;
        if(k==1)
        {
            ans+=m[sum-1];
            m[sum]++;
            continue;
        }
        if(k==-1)
        {
            ans+=m[sum+1];
            ans+=m[sum-1];
            m[sum]++;
            continue;
        }
        while(c<=1e15)
        {
            //cout<<sum-c<<" ";
            ans+=m[sum-c];
            c*=k;
        }
        //cout<<"\n";
        m[sum]++;
        //cout<<sum<<"\n";
    }

    cout<<ans;
    return 0;
}
