
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
#define testcases ll t; t=1; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        int k;
        cin>>k;
        cout<<2<<" "<<3<<"\n";
        cout<<k+(1<<17)<<" "<<k<<" "<<0<<"\n";
        cout<<(1<<17)<<" "<<k+(1<<17)<<" "<<k<<"\n";
    }
    return 0;
}
