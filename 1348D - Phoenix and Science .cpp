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

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        cin>>n;
        vect v(1,1);
        ll s=1,x=1;

        while(s+(1LL<<x)<n) v.pb(1LL<<x),s+=(1<<x),x+=1;

        if(s!=n) v.pb(n-s);

        sort(v.begin(),v.end());

        cout<<v.size()-1<<"\n";
        for(int i=1;i<v.size();i++) cout<<v[i]-v[i-1]<<" ";
        cout<<"\n";
    }

    return 0;
}
