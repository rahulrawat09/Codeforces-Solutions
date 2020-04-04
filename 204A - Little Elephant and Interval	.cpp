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
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

ll cal(ll x)
{
    if(x<10) return x;
    ll l=0,n=x;
    while(n) l=n%10,n/=10;
    return 9+x/10-((x%10)<l?1:0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll l,r;
    cin>>l>>r;
    cout<<cal(r)-cal(l-1)<<"\n";
    return 0;
}
