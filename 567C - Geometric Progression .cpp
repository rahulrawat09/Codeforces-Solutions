
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
#define mod int(998244353)
#define mp make_pair
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
    vector<ll> v(n);
    map<ll,ll> m1,m2;
    for(int i=0;i<n;i++) cin>>v[i],m2[v[i]]++;
    ll ans=0;
    m2[v[0]]--;
    for(int i=1;i<n-1;i++)
    {
        m2[v[i]]--;
        m1[v[i-1]]++;
        if(v[i]%k) continue;
        ans+=m1[v[i]/k]*m2[v[i]*k];
    }

    cout<<ans;
    return 0;
}
