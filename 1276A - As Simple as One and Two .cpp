#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e8)
#define mp make_pair
#define sortv(v) sort(v.begin(),v.end())
#define pb push_back
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    //t=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length();
        vector<int> v;

        for(int i=0;i<n-2;i++)
        {
            if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
            {
                if(i>1&&s[i-1]=='w'&&s[i-2]=='t')
                {
                    v.pop_back();
                    v.pb(i+1);
                }
                else v.pb(i+2);
                continue;
            }
            if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o') v.pb(i+2);
        }

        cout<<v.size()<<"\n";
        for(auto& i:v) cout<<i<<" ";
        cout<<"\n";
    }

    return 0;
}
