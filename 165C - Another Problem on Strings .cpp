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

    ll k,d=0,ans=0;
    cin>>k;

    string s;
    cin>>s;

    map<int,int> m;
    m[d]++;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='0') d++;
        m[d]++;
    }

    for(auto& i:m)
    {
        if(k==0)
        {
            ans+=(i.second*(i.second-1))/2;
            continue;
        }

        if(i.first<k) continue;
        ans+=i.second*m[i.first-k];
    }
    cout<<ans;

    return 0;
}
