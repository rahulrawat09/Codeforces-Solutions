#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI 3.1415926536
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<ll> dp(n+2,0);
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        dp[i]=dp[i-1]+x;
    }
    dp[n+1]=INT_MAX;
    int ma;
    cin>>ma;
    while(ma--)
    {
        ll x;
        cin>>x;
        int i=1,j=n,m;
        while(i<=j)
        {
            m=(i+j)/2;
            if(x>dp[m-1]&&x<=dp[m]) break;
            if(x>dp[m]) i=m+1;
            else j=m-1;
        }
        cout<<m<<"\n";
    }

    return 0;
}
