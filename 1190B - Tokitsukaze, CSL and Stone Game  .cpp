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
#define mod int(998244353)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,f=0,two=0,three=0,s=0;
    cin>>n;

    map<ll,ll> m;
    vect v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        m[v[i]]++;
    }

    for(auto& i:m)
    {
        if(i.second>1) two++;
        if(i.second>2) three++;
        if(i.second>1&&m[i.first-1]>0) f=1;
    }
    sort(v.begin(),v.end());
    f|=(two>1)|(three>0)|(m[0]>1);
    if(f) cout<<"cslnb";
    else
    {
        for(ll i=0;i<n;i++) s+=v[i]-i;
        if(s%2) cout<<"sjfnb";
        else cout<<"cslnb";
    }

    return 0;
}
