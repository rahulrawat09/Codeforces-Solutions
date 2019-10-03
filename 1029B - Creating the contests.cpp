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
    int n;
    cin>>n;
    
    int a[n],ans=0;
    
    fillarray cin>>a[i];
    
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(a[j+1]<=2*a[j]&&j<n-1)
        {
            j++;
        }
        ans=max(ans,j-i+1);
        i=j;
    }
    
    cout<<ans;
}
