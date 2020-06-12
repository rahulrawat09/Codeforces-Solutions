#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define fora(i,n) for(int i=0;i<n;i++)
//#define bint ll 1024_t
#define ld long double
#define vect vector<ll>
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
//#define mp make_pair
#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

vector<bool> prime(10000001,1);  // prime sieve
vector<ll> small(10000001,-1);

void cal()
{
    prime[1]=0;
    for(int i=2;i<=(int)1e7;i++)
    {
        if(prime[i])
        {
            small[i]=i;
            for(int j=2*i;j<=(int)1e7;j+=i)
            {
                prime[j]=0;
                if(small[j]==-1) small[j]=i;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cal();
    //testcases
    //{
        ll n;
        cin>>n;
        vect v(n);
        vector<pll> ans;
        for(ll& i:v) cin>>i;

        for(ll& i:v)
        {
            ll d1=1,d2,x=small[i],y=i;
            while(i%x==0)
            {
                i/=x;
                d1*=x;
            }
            d2=y/d1;
            if(d1>1&&d2>1) ans.pb({d1,d2});
            else ans.pb({-1,-1});
        }
        for(auto& i:ans) cout<<i.F<<" ";
        cout<<"\n";
        for(auto& i:ans) cout<<i.S<<" ";
    //}

    return 0;
}
