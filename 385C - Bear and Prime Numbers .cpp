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
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

ll n,m;
ll a[1000001],v[10000001];
ll dp[10000001];
vector<bool> prime(10000001,1);

void cal()
{
    prime[1]=0;
    for(int i=2;i<=(int)1e7;i++)
    {
        if(prime[i])
        {
            for(int j=i;j<=(int)1e7;j+=i)
            {
                 if(i!=j) prime[j]=0;
                 dp[i]+=v[j];
            }
        }
    }

    for(int i=2;i<=(int)1e7;i++) dp[i]+=dp[i-1];

    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    memset(v,0,sizeof(v));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++) cin>>a[i],v[a[i]]++;
    cin>>m;
    cal();

    while(m--)
    {
        ll l,r;
        cin>>l>>r;
        l=min(l,(ll)1e7);
        r=min(r,(ll)1e7);
        cout<<dp[r]-dp[l-1]<<"\n";
    }

    return 0;
}
