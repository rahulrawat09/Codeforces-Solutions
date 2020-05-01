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

bool give(int w,int m)
{
    if(w<=3||m==1) return 1;

    if((m-1)%w==0) return give(w,(m-1)/w);
    else if(m%w==0) return give(w,m/w);
    else if((m+1)%w==0) return give(w,(m+1)/w);
    else return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll w,m;
    cin>>w>>m;

    cout<<(give(w,m)?"YES":"NO");

    return 0;
}
