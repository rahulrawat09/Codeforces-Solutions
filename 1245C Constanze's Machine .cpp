#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    int f=0;
    for(auto& i:s) if(i=='m'||i=='w') f=1;
    if(f)
    {
        cout<<0;
        return 0;
    }

    int dp[s.length()];
    dp[0]=1;
    if(s.substr(0,2)=="nn"||s.substr(0,2)=="uu") dp[1]=2;
    else dp[1]=1;

    for(int i=2;i<s.length();i++) if(s.substr(i-1,2)=="nn"||s.substr(i-1,2)=="uu") dp[i]=(dp[i-1]+dp[i-2])%MOD; else dp[i]=dp[i-1];

    cout<<dp[s.length()-1];
    return 0;
}
