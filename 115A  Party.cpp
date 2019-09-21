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

int bfs(vector<vector<int>> v,int n,int x)
{
	int c=0;
	queue<int> q;
	q.push(x);
	int z=q.size();
	while(!q.empty())
	{
	for(int j=0;j<z;j++)
	{
		int y=q.front();
		q.pop();
		
		for(int i=0;i<v[y].size();i++)
		{
			q.push(v[y][i]);
		}
	}
	z=q.size();
	c++;
	}
	return c; 
}

int main() 
{
    int n; cin>>n;
    vector<vector<int>> v(n);
    vector<int> roots;
    for(int i=0;i<n;++i)
    {
    	
    	int x;
    	cin>>x;
    	if(x==-1) roots.pb(i);
    	else v[x-1].pb(i);
    }
    
    int min=INT_MIN;
    
    for(int i=0;i<roots.size();i++)
    {
    	int x=bfs(v,n,roots[i]);
    	if(x>min) min=x;
    }
    cout<<min;
	return 0;
}
