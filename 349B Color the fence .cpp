#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    int v,x=1;
    string s;
    cin>>v;
    vector<int> d(10);
    for(int i=1;i<=9;i++) cin>>d[i];
    for(int i=1;i<=9;i++)
    {
        if(d[i]<=d[x]) x=i;
    }

    while(v>=d[x])
    {
        s.pb(x+48);
        v-=d[x];
    }
    if(v)
    {
        for(int i=0;i<s.length();i++)
        {
            if(!v) break;
            for(int j=9;j>=1;j--)
            {
                if(d[j]-d[x]<=v)
                {
                    s[i]=(j+48);
                    v-=d[j]-d[x];
                    break;
                }
            }
        }
    }

    if(s=="") cout<<-1;
    else cout<<s;


    return 0;
}
