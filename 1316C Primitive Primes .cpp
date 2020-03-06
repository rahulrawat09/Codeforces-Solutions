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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        ll n,m,p;
        cin>>n>>m>>p;
        vector<ll> a(n),b(m);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<m;i++) cin>>b[i];

        int i=0,j=0;
        while(a[i]%p==0) i++;
        while(b[j]%p==0) j++;

        cout<<i+j;
    }
    return 0;
}
