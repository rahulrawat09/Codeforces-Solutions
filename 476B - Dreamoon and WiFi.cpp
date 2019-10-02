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

double fact(int n)
{
    double ans=1;
    
    for(int i=2;i<n+1;i++) ans*=i;
    
    return ans;
}

int main() 
{
    string a,b;
    cin>>a>>b;
    
    double unknown=0,plus=0,minus=0,p=0,m=0;
    
    for(auto i:a)
    {
        if(i=='+') plus++;
        else minus++;
    }
    
    
    for(auto i:b)
    {
        if(i=='+') p++;
        else if(i=='-') m++;
        else unknown++;
    }
    
    if(plus<p||minus<m||(plus-p)+(minus-m)!=unknown) 
    {
        cout<<0;
        return 0;
    }
    
    double ans=(fact(unknown)/(fact(plus-p)*fact(minus-m)))/pow(2,unknown);
    cout<<setprecision(10)<<fixed<<ans;
}
