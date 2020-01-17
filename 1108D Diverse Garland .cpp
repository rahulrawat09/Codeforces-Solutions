#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define pb push_back
using namespace std;
 
int main()
{
    int n,c=0;
    cin>>n;
    string s;
    cin>>s;
    s.pb('1');
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            c++;
            for(auto c:{'R','G','B'})
            {
                s[i]=c;
                if(s[i]!=s[i-1]&&s[i]!=s[i+1]) break;
            }
        }
    }
    s.pop_back();
    cout<<c<<"\n"<<s;
 
    return 0;
}
