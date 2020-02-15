#include<bits/stdc++.h>
#define ll long long
#define modu int(1e9+7)
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    //t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> v(n,vector<ll>(3));
        for(int i=0;i<n;i++) cin>>v[i][0]>>v[i][1]>>v[i][2];

        ll time=0,s=m,e=m,f=0;
        for(int i=0;i<n;i++)
        {
            ll dif=v[i][0]-time;
            time=v[i][0];
            s-=dif;
            e+=dif;
            if(s>v[i][2]||e<v[i][1])
            {
                f=1;
                break;
            }
            s=max(s,v[i][1]);
            e=min(v[i][2],e);
        }
        if(f) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}
