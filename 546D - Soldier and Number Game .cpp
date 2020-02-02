#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define pb push_back
using namespace std;

vector<bool> prime(5000001,1);
vector<ll> coun(5000001,0);
vector<ll> dp(5000001,0);

void com()
{
    prime[1]=0;
    for(int i=2;i<=sqrt(5000000);i++)
    {
        if(prime[i])
        {
            for(int j=i+i;j<5000001;j+=i)
            {
                prime[j]=0;
                coun[j]=i;
            }
        }
    }

    for(int i=2;i<5000001;i++)
    {
        if(prime[i]) coun[i]=1;
        else coun[i]=1+coun[i/(coun[i])];
        dp[i]=dp[i-1]+coun[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    com();

    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<dp[a]-dp[b]<<"\n";
    }

    return 0;
}
