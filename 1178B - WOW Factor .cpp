#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    vector<int> dp(s.length()+1,0);
    ll c=0,tot=0,ans=0;

    for(int i=1;i<s.length();i++)
    {
        if(s[i-1]=='v'&&s[i]=='v') tot++;
    }

    for(int i=1;i<s.length();i++)
    {
        if(s[i-1]=='v'&&s[i]=='v') c++;
        if(s[i]=='o') ans+=c*(tot-c);
    }
    cout<<ans;
    return 0;
}
