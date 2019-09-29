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
    int n,k;
    cin>>n>>k;
    
    vector<int> v(n);
    fillarray cin>>v[i];
    
    int ans=0;
    
    for(int i=1;i<n;i++)
    {
    	if(v[i]+v[i-1]<k)
    	{
    		ans+=k-v[i]-v[i-1];
    		v[i]+=k-v[i]-v[i-1];
    	}
    }
    
    cout<<ans<<endl;
    fillarray cout<<v[i]<<" ";
}
    
