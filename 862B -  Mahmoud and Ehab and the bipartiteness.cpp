#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>

#define ll unsigned long long int 
#define ld long double
#define pb push_back
#define pi 3.1415926536
#define mod 1e9+7
#define mp make_pair
#define wt while(t--)
#define fillarray for(int i=0;i<n;i++) 
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;

int main() 
{
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    
    vector<vector<int>> edge(n); //adjacency lists to store edges
    vector<bool> visited(n); 
    
    for(int i=0;i<n-1;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	edge[x-1].pb(y-1);
    	edge[y-1].pb(x-1);
    }
    
    queue<int> q;  //now bfs algo using queue
    q.push(0);
    visited[0]=1;
    bool f=1;
    ll one=1,two=0;
    
    while(!q.empty())
    {
        int l=q.size();
        
        int curr=0;
        while(l--)
        {
            int x=q.front();
            visited[x]=1;
            for(int i=0;i<edge[x].size();i++) if(!visited[edge[x][i]]){ q.push(edge[x][i]); curr++;}
            q.pop();
        }
        if(!f) one+=curr;
        else two+=curr;
        f=!f;
    }
    ll ans=one*two-n+1;
    cout<<ans;
}
