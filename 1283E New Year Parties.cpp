#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int v[200010]={};
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v[x]++;
    }
    int mini=0,maxi=0;

    for(int i=1;i<=n+1;i++)
    {
        if(v[i]==0) continue;
        if(v[i+1]==0)
        {
            mini++;
            if(v[i+2]) i+=2;
        }
        else
        {
            mini++;
            i+=2;
        }
    }
    for(int i=1;i<=n+1;i++)
    {
        if(v[i]==0) continue;
        if(v[i]==1)
        {
            maxi++;
            if(v[i-1]==0) v[i]=0;
        }
        else if(v[i]==2)
        {
            maxi++;
            if(v[i-1]==0) maxi++;
            else v[i+1]++;
        }
        else
        {
            maxi++;
            if(v[i-1]==0) maxi++;
            v[i+1]++;
        }
    }
    cout<<mini<<" "<<maxi;
    return 0;
}
