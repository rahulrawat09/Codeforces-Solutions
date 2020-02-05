#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define rep(i,st,en) for(int i=st;i<en;i++)
#define sortv(v) sort(v.begin(),v.end())
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin>>s;

    rep(i,0,n)
    {
        rep(j,i+1,n)
        {
            rep(k,j+1,n)
            {
               if(s[k]<s[j]&&s[j]<s[i])
               {
                   cout<<"NO";
                   return 0;
               }
            }
        }
    }
    char last='a';
    cout<<"YES\n";
    rep(i,0,n)
    {
        if(s[i]>=last)
        {
            last=s[i];
            cout<<1;
        }
        else cout<<0;
    }

    return 0;
}
