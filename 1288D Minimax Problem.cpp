#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define mp make_pair
#define pb push_back
using namespace std;

int check=0;
pair<int,int> give(auto& v,ll ans)
{
    vector<pair<int,int>> p;
    map<int,int> m;
    for(int i=0;i<v.size();i++)
    {
        int x=0;
        for(int j=0;j<v[0].size();j++) x=(x<<1|(v[i][j]>=ans));
        if(!m[x])
        {
            p.pb(mp(x,i));
            m[x]=1;
        }
    }

    for(int i=0;i<p.size();i++)
    {
        for(int j=0;j<p.size();j++)
        {
            if((p[i].first|p[j].first)==check)
                return {p[i].second,p[j].second};
        }
    }

    return {-1,-1};
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++) check=(check<<1)|1;

    vector<vector<ll>> v(n,vector<ll>(m));
    for(int i=0;i<n;i++) for(ll& j:v[i]) cin>>j;

    ll left=0,right=1e9;
    pair<int,int> p;

    while(left<right)
    {
        ll mid=(left+right+1)/2;
        p=give(v,mid);
        if(p.first==-1) right=mid-1;
        else left=mid;
    }
    p=give(v,(left+right+1)/2);
    cout<<p.first+1<<" "<<p.second+1;
    return 0;
}
