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

    ll n,m,k;
    cin>>n>>m>>k;

    if((2*n*m)%k)
    {
        cout<<"NO";
        return 0;
    }
    ll a,b;
    if(k%2==0)
    {
        k/=2;
        a=n/__gcd(n,k);
        b=m/(k/__gcd(n,k));
    }
    else
    {
        a=n/__gcd(n,k);
        b=m/(k/__gcd(n,k));
        if(2*a<=n) a*=2;
        else b*=2;
    }
    cout<<"YES\n0 0\n";
    cout<<a<<" "<<0<<"\n";
    cout<<0<<" "<<b<<"\n";

    return 0;
}
