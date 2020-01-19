#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define pb push_back
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<ll>> f(m+1,vector<ll>(n+1,0)),g(m+1,vector<ll>(n+1,0));

    for(int i=1;i<=n;i++) f[1][i]=1;

    for(int i=2;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1];
            f[i][j]%=MOD;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[i][j]=g[i][j-1]+f[i][j];
            g[i][j]%=MOD;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+f[m][i]*g[m][n-i+1])%MOD;
    }
    cout<<ans;
    return 0;
}

