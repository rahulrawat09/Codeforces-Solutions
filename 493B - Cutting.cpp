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
    
    int n,b;
    cin>>n>>b;
    
    int a[n];
    fillarray cin>>a[i];
    
    vector<int> v;
    int e=a[0]%2==0?1:0 , o=a[0]%2==0?0:1;
    
    for(int i=1;i<n;i++)
    {
        if(e==o) v.pb(abs(a[i-1]-a[i]));
        
        a[i]%2==0?e++:o++;
    }
    
    if(v.size()==0)
    {
        cout<<0;
        return 0;
    }
    
    sort(v.begin(),v.end());
    int c=0,sum=0;
    
    for(int i=0;i<v.size();i++)
    {
        //cout<<v[i]<<endl;
        sum+=v[i];
        if(sum>b) break;
        c++;
    }
    
    cout<<c;
}
