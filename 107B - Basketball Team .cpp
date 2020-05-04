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

ld n,w,h,ans=0,s=0;
vector<ld> v(1001);

ld ncr(int n,int r)
{
   int i;
   ld p=1.0,q=1.0,ans=1.0;

   if(r>n)
       return 0.0;

   for(i=0;i<r;i++)
   {
       p=n-i;
       q=i+1;
       ans*=(p/q);
   }

   return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>w>>h;
    for(int i=1;i<=w;i++) cin>>v[i],s+=v[i];

    v[h]--;
    if(s<n)
    {
        cout<<-1;
        return 0;
    }

    s--;
    s-=v[h];
    n--;
    ld t=0;
    for(int i=0;i<=min(v[h],n);i++)
    {
        ans+=ncr(v[h],i)*ncr(s,n-i);
        if(i==0) t=ans;
    }
    cout<<(ans-t)/ans;
    return 0;
}
