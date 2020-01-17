#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define pb push_back
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int l=0,r=0,c=0,ans=0;
 
    if(s[l]=='b') c=1;
    while(r<n)
    {
        while(c>k&&l<=r)
        {
            if(s[l]=='b') c--;
            l++;
        }
        ans=max(ans,r-l+1);
        if(r+1<n&&s[r+1]=='b') c++;
        r++;
    }
 
    l=0;r=0;c=0;
    if(s[l]=='a') c=1;
    while(r<n)
    {
        while(c>k&&l<=r)
        {
            if(s[l]=='a') c--;
            l++;
        }
        ans=max(ans,r-l+1);
        if(r+1<n&&s[r+1]=='a') c++;
        r++;
    }
    cout<<ans;
 
    return 0;
}
