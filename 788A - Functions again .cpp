#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define sortv(v) sort(v.begin(),v.end())
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> v(n),x,y;
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n-1;i++)
        {
            if(i%2) y.pb(abs(v[i]-v[i+1]));
            else x.pb(abs(v[i]-v[i+1]));
        }

        ll c1=x[0],c2,m=c1;
        if(y.size()>0)
        {
            c2=y[0];
            m=max(c1,c2);
        }
        for(int i=1;i<x.size();i++)
        {
            c1=max(x[i],c1-y[i-1]+x[i]);
            m=max(m,c1);
        }
        for(int i=1;i<y.size();i++)
        {
            c2=max(y[i],c2-x[i]+y[i]);
            m=max(m,c2);
        }

        cout<<m;
    }

    return 0;
}
