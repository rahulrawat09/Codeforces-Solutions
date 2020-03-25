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
    
    ll l,r,ans=0,x,y;
    cin>>l>>r;
    x=l,y=r;
    
	for(ll i=0;i<64&&(l||r);i++)
	{
		if(y-x>=(1LL<<i) || (l&1)!=(r&1)) ans|=(1LL<<i);
		l=l>>1;
		r=r>>1;
	}
	cout<<ans;

    return 0;
}       
