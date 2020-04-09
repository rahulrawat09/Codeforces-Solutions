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
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        map<ll,int> m;
        ll s=0,ans=0,r=-1;
        m[0]=-1;
        for(int i=0;i<n;i++)
        {
            s+=v[i];
            if(m.find(s)!=m.end())
            {
                r=max(r,(ll)m[s]+1);
            }
            //cout<<i<<" "<<r<<"\n";
            m[s]=i;
            ans+=i-r;
        }
        cout<<ans;
    }

    return 0;
}
