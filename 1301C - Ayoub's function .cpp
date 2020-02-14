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
    //t=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        if(m>=n/2) cout<<(n*(n+1))/2-n+m<<"\n";
        else
        {
            ll x=(n-m)/(m+1);
            ll a,c;
            if((n-m)%(m+1)) a=m+1-(n-m)%(m+1),x++,c=(n-m)%(m+1);
            else a=0,c=m+1;
            ll b=x-1;
            cout<<(n*(n+1))/2-c*(x*(x+1))/2-a*((b*(b+1))/2)<<"\n";
        }
    }

    return 0;
}
