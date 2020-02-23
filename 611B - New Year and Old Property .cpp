#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI 3.1415926536
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b,ans=0;
    cin>>a>>b;
    ll x=2;

    for(int i=2;i<=60;i++)
    {
        ll y=1;
        x=x<<1;
        //cout<<x-1<<"\n";

        for(int j=0;j<i-1;j++)
        {
            ll z=(x-1)^(y<<j);
            if(z<=b&&z>=a) ans++;
        }
    }

    cout<<ans;
    return 0;
}
