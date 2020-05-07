#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define unmap unordered_map
#define pb push_back
#define F first
#define S second
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

void dfs(vector<string>& v,vector<vector<bool>>& visited,int i,int j)
{
    if(i<0||i>=v.size()||j<0||j>=v[0].size()
       ||visited[i][j]||v[i][j]=='.') return;

    visited[i][j]=1;
    dfs(v,visited,i+1,j);
    dfs(v,visited,i-1,j);
    dfs(v,visited,i,j+1);
    dfs(v,visited,i,j-1);
    return;
}

int numIslands(vector<string>& v)
{
    if(v.empty()) return 0;
    int n=v.size(),m=v[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    int connected_components=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]||v[i][j]=='.') continue;
            connected_components++;
            dfs(v,visited,i,j);
        }
    }

    return connected_components;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;

    vector<string> s(n);
    for(auto& i:s) cin>>i;

    ll f1=0,f2=0;

    for(int i=0;i<n;i++)
    {
        f1++;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                f1--;
                break;
            }
        }
        if(f1) break;
    }

    for(int i=0;i<m;i++)
    {
        f2++;
        for(int j=0;j<n;j++)
        {
            if(s[j][i]=='#')
            {
                f2--;
                break;
            }
        }
        if(f2) break;
    }

    if(f1^f2)
    {
        cout<<-1<<"\n";
        return 0;
    }

    int f,l=-1;
    f1=0;
    for(int i=0;i<n;i++)
    {
        f=0;
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                if(!f) l=j,f=1;
                else
                {
                    if(j-l>1) f1=1;
                    l=j;
                }
            }
        }
    }

    f=0;
    l=-1;
    f2=0;
    for(int i=0;i<m;i++)
    {
        f=0;
        for(int j=0;j<n;j++)
        {
            if(s[j][i]=='#')
            {
                if(!f) l=j,f=1;
                else
                {
                    if(j-l>1) f2=1;
                    l=j;
                }
            }
        }
    }

    if(f1||f2) cout<<-1;
    else cout<<numIslands(s);

    return 0;
}
