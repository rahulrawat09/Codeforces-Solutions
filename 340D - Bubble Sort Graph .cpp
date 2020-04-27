#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define unmap u5nordered_map
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

ll lis_nlogn(auto& v)
{
    ll n=v.size();
    vector<ll> s(1,v[0]);

    for(int i=1;i<n;i++)
    {
        if(v[i]>=s.back()) s.pb(v[i]);
        else
        {
            int x=lower_bound(s.begin(),s.end(),v[i])-s.begin();
            s[x]=v[i];
        }
    }
    return s.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vect v(n);
    for(ll& i:v) cin>>i;
    cout<<lis_nlogn(v);

    return 0;
}
