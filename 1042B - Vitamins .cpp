#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define pb push_back
using namespace std;

int give(string x,string y)
{
    int a[]={0,0,0};
    a[x[0]-65]++;
    if(x.length()>1) a[x[1]-65]++;
    a[y[0]-65]++;
    if(y.length()>1) a[y[1]-65]++;

    if(a[0]>0&&a[2]>0&&a[1]>0) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,ans=INT_MAX,a=INT_MAX,b=a,c=a;
    cin>>n;
    pair<ll,string> v[n];

    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
        if(v[i].second.length()==1)
        {
            if(v[i].second=="A") a=min(a,v[i].first);
            if(v[i].second=="B") b=min(b,v[i].first);
            if(v[i].second=="C") c=min(c,v[i].first);
        }
        else if(v[i].second.length()==3) ans=min(ans,v[i].first);
    }
    ans=min(ans,a+b+c);
    for(int i=0;i<n;i++)
    {
        if(v[i].second.length()==3) continue;
        for(int j=i+1;j<n;j++)
        {
            if(v[j].second.length()!=3&&give(v[j].second,v[i].second))
            {
                ans=min(ans,v[i].first+v[j].first);
            }
        }
    }
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
    return 0;
}
