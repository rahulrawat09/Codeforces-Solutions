#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ans=1e18,n;
    cin>>n;
    vector<ll> v(n),c(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) cin>>c[i];

    for(int j=1;j<n-1;j++)
    {
        ll x=1e18;
        for(int i=0;i<j;i++)
        {
            if(v[i]<v[j]) x=min(x,c[i]+c[j]);
        }
        if(x==1e18) continue;
        for(int k=j+1;k<n;k++)
        {
            if(v[j]<v[k]) ans=min(ans,x+c[k]);
        }
    }

    if(ans==1e18) cout<<-1;
    else cout<<ans;;

    return 0;
}
