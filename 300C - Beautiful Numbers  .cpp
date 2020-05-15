#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
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

ll fact[1000001];    // factorial array

ll power (ll a,ll b)   // a^b % mod
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

ll Inv(ll n)
{
 return power(n,mod-2);
}

ll nCr(ll n,ll k)
{
    return (((fact[n])*(Inv(fact[k])))%mod*(Inv(fact[n-k])))%mod;
}

ll a,b,n,ans;

bool check(ll n)
{
    while(n)
    {
        if((n%10)!=a&&(n%10)!=b) return 0;
        n/=10;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    fact[0]=1;
    for(ll i=1;i<=1000000;i++) fact[i]=(i*fact[i-1])%mod;

//    testcases
  //  {
        ans=0;
        cin>>a>>b>>n;

        for(int i=0;i<=n;i++)
        {
            if(check(a*i+(n-i)*b)) ans+=nCr(n,i),ans%=mod;
        }
        cout<<ans<<"\n";
 //   }

    return 0;
}
