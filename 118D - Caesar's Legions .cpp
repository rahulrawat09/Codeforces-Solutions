#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define pb push_back
using namespace std;

ll dp[250][150][5][15];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n[2],m[2];
    cin>>n[0]>>n[1]>>m[0]>>m[1];
    memset(dp,0,sizeof(dp));

    ll ans=0;
    dp[0][0][0][0]=1;

    for(int i=0;i<=n[0]+n[1];i++)
    {
        for(int j=0;j<=min(i,n[0]);j++)
        {
            for(int k=0;k<=1;k++)
            {
                for(int l=0;l<=m[k];l++)
                {
                    if(dp[i][j][k][l]==0) continue;
                    if(i==n[0]+n[1]) ans=(ans+dp[i][j][k][l])%MOD;

                    for (long long c = 0; c <= 1; c++) {
                    long long jj = j;
                    if (c == 0) {
                        jj ++;
                    }
                    if (c == 0) {
                        if (jj > n[0]) continue;
                    } else {
                        if (i + 1- jj > n[1]) continue;
                    }
                    if (c == k) {
                        if (l+1 <= m[c]) {
                            dp[i+1][jj][k][l+1] = (dp[i+1][jj][k][l+1]  + dp[i][j][k][l]) % MOD;
                        }
                    } else {
                        dp[i+1][jj][c][1] = (dp[i+1][jj][c][1] + dp[i][j][k][l]) % MOD;
                    }
                }
                }
            }
        }
    }

    cout<<ans;
    return 0;
}
