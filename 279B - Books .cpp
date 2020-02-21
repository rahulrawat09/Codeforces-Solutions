#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI 3.1415926536
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,t;
    cin>>n>>t;
    vector<ll> v(n);
    for(ll& i:v) cin>>i;

    int i=0,j=-1,ans=0,sum=0;
    while(j<n-1)
    {
        j++;
        sum+=v[j];
        while(sum>t)
        {
            sum-=v[i];
            i++;
        }
        ans=max(ans,j-i+1);
    }
    cout<<ans;
    return 0;
}
