#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>

#define ll unsigned long long
//#define bint int1024_t
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
    
    int b,g;
    
    cin>>b;
    vector<int> boys(b);
    for(int i=0;i<b;i++) cin>>boys[i];
    
    cin>>g;
    vector<int> girls(g);
    for(int i=0;i<g;i++) cin>>girls[i];
    
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    
    int c=0,i=0,j=0; 
    
    while(i!=b&&j!=g)
    {
    	if(abs(boys[i]-girls[j])<=1)
    	{
    		c++;
    		i++;
    		j++;
    		continue;
    	}
    	if(boys[i]<girls[j]) i++;
    	else j++;
    }
    
    cout<<c;
}
