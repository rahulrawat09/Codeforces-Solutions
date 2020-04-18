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

ll power (ll a,ll b)   
{
    ll ans=1;
    a%=mod;
    while(b) 
    {
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;

    ll c=(b*(b-1))/2;
    c%=mod;
    ll d=(((a*(a+1))/2)%mod)*b+a;
    d%=mod;
    cout<<(c*d)%mod;
    return 0;
}
