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

ll n,k;
vect v(2001,0);
vector<string> s(2001);
bool dp[2010][2010];
vect dig{119,18,93,91,58,107,111,82,127,123};

ll check(ll n,ll d)
{
    if((n&d)!=n) return -1;
    //if(__builtin_popcount(d)-__builtin_popcount(n)==0) cout<<1<<" ";
    //cout<<1<<" ";
    return __builtin_popcount(d)-__builtin_popcount(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    memset(dp,0,sizeof(dp));

    for(ll i=1;i<=n;i++)
    {
        cin>>s[i];
        ll c=0;
        for(ll j=6;j>=0;j--)
        {
            if(s[i][j]=='1') v[i]+=(1LL<<c);
            c++;
        }
        //cout<<v[i]<<" ";
    }
    dp[n+1][0]=1;

    for(ll i=n;i>=1;i--)
    {
        //cout<<v[i]<<" ";
        for(ll j=0;j<=k;j++)
        {
            for(ll d=0;d<=9;d++)
            {
                ll x=check(v[i],dig[d]);
                //if(i==1&&d==8) cout<<x<<" ";
                if(x!=-1&&j>=x&&dp[i+1][j-x]) dp[i][j]=1;//cout<<i<<" "<<x<<"\n" ;
            }
        }
    }

    string ans;
    ll y=k;
    for(ll i=1;i<=n;i++)
    {
        ll f=0;
        for(ll j=9;j>=0;j--)
        {
            ll x=check(v[i],dig[j]);
            //cout<<i<<" "<<x<<"\n ";
            if(x==-1||dp[i+1][y-x]==0) continue;
            y-=x;
            f=1;
            ans.pb(j+'0');
            break;
        }
        if(!f) break;
    }
    if(ans.size()!=n) cout<<-1;
    else cout<<ans;

    return 0;
}
