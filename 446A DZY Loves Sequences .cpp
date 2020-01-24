#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define mp make_pair
#define pb push_back
using namespace std;
vector<vector<int>> e(401);

int main()
{
    int n;
    cin>>n;
    vector<ll> v(n),l(n),r(n);
    for(ll& i:v) cin>>i;
    l[0]=0;
    r[n-1]=0;
    ll p=0;
    for(int i=1;i<n;i++)
    {
        if(v[i]<=v[i-1])
        {
            l[i]=i-p;
            p=i;
        }
        else l[i]=i-p;
    }
    p=n-1;
    for(int i=n-2;i>=0;i--)
    {
        if(v[i]>=v[i+1])
        {
            r[i]=p-i;
            p=i;
        }
        else r[i]=p-i;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(i>0&&i<n&&v[i+1]-v[i-1]>1) ans=max(ans,l[i]+r[i]+1);
        else ans=max({ans,1+l[i],1+r[i]});
    }
    cout<<ans;
    return 0;
}
