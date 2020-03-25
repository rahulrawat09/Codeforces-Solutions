#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define pll pair<ll,ll>
#define S second
#define F first
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
    
    string s;
    cin>>s;
    ll b,a,c,x,y,z,r;
    cin>>a>>b>>c>>x>>y>>z>>r;
    ll ans=0,e=0,f=0,g=0;

    for(auto& i:s) 
    {
        if(i=='B') e++;
        else if(i=='S') f++;
        else g++;
    }
    
    ll l=0,ri=1e13;

    while(l<=ri)
    {
        ll m=(l+ri)/2;
        ll temp=0;
        if(m*e>a) temp+=(m*e-a)*x;
        if(m*f>b) temp+=(m*f-b)*y;
        if(m*g>c) temp+=(m*g-c)*z;
        if(temp<=r)
        {
            ans=m;
            l=m+1;
        }
        else ri=m-1;
    }

    cout<<ans;
    return 0;
}       
