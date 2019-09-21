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

int give(const auto& edge,const auto& node,auto& visited,int index,int m,int x) // x is count of cats till now
{
	if(edge[index].size()==1&&index!=0)
	{
		if(x+node[index]<=m) return 1;
		else return 0;
	}
	if(visited[index]) return 0;
	visited[index]=1;
	
	if(node[index]) x++;
	else x=0;
	
	if(x>m) return 0;
	
	int sum=0;
	for(int i=0;i<edge[index].size();i++)
	{
		sum+=give(edge,node,visited,edge[index][i],m,x);
	}
	return sum;
}
int main() 
{
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; 
    cin>>n>>m;
    vector<vector<int>> edge(n);
    vector<bool> node(n);
    vector<bool> visited(n,0);
    
    fillarray{
    	bool x; cin>>x;
    	node[i]=x;
    }
    for(int i=0;i<n-1;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	edge[x-1].pb(y-1);
    	edge[y-1].pb(x-1);
    }
    cout<<give(edge,node,visited,0,m,0);
}
