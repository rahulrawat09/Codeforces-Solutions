#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define pb push_back
using namespace std;
 
ll pow2(int n)     // pow of 2
{
    ll p=1;
    while(n--) p*=2;
    return p;
}
 
int main()
{
    int n;
    cin>>n;
 
    while(n--)
    {
        ll l,r;
        cin>>l>>r;
        int bit[65]={};
        ll i=0,temp=l,ans=l;
        while(temp)
        {
            bit[i]=temp%2;
            temp=temp>>1;
            i++;
        }
        temp=l;
        for(int j=0;temp<=r;j++)
        {
            if(!bit[j])
            {
                temp=temp+pow2(j);
                if(temp<=r) ans=temp;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
