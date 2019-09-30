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

int Max(int a,int b,int c)
{
    cout<<a<<" "<<b<<" "<<c<<endl;
    return max(a,max(b,c));
}

int main() 
{
    int n;
    cin>>n;
    
    int x[n],h[n];
    fillarray cin>>x[i]>>h[i];
    
    int ans=1,pos=x[0];
    
    for(int i=1;i<n-1;i++)
    {
        if(x[i]-h[i]>pos)
        {
            ans++;
            pos=x[i];
            continue;
        }
        if(x[i]+h[i]<x[i+1])
        {
            ans++;
            pos=x[i]+h[i];
            continue;
        }
        pos=x[i];
    }
    if(n>=2) ans++;
    
    cout<<ans;
}
