
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

    int n,ans=0,l;
    cin>>n;
    map<int,int> m;
    vector<int> v(n);
    vector<int> p;
    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=0;i<n;i++)
    {
        m[v[i]]=m[v[i]-1]+1;
        if(m[v[i]]>ans)
        {
            ans=m[v[i]];
            l=v[i];
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        if(l==v[i]) l-=1,p.pb(i+1);
    }
    reverse(p.begin(),p.end());
    cout<<ans<<"\n";
    for(int& i:p) cout<<i<<" ";

    return 0;
}
