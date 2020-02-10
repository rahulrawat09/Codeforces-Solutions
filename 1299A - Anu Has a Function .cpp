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
    t=1;
    //cin>>t;
    while(t--)
    {
        int n,x=0;
        cin>>n;
        vector<int> v(n);
        vector<vector<int>> bit(n,vector<int>(32));

        for(int i=0;i<n;i++)
        {
            int y;
            cin>>y;
            v[i]=y;
            for(int b=31;b>-1;b--)
            {
                bit[i][b]=y%2;
                y/=2;
            }
        }

        for(int i=0;i<32;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(bit[j][i])
                {
                    c++;
                    x=j;
                }
                if(c>1) break;
            }
            if(c==1) break;
        }

        cout<<v[x]<<" ";
        for(int i=0;i<n;i++) if(i!=x) cout<<v[i]<<" ";
    }

    return 0;
}
