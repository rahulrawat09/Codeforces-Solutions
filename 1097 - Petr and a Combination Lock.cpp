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

bool give(int *a,int i,int sum,int n)
{
    if(i==n)
    {
        if(sum%360==0) return 1;
        return 0;
    }
    return give(a,i+1,sum+a[i],n)|give(a,i+1,sum-a[i],n);
}

int main() 
{
    int n;
    cin>>n;
    
    int a[n];
    fillarray cin>>a[i];
    
    if(give(a,0,0,n)) cout<<"YES";
    else cout<<"NO";
}
