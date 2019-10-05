#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>

#define ll unsigned long long
//#define bint int1024_t
#define ld long double
#define unmap unordered_map
#define pb push_back
#define pi 3.1415926536
#define mod int(1e9+7)
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
    
    int n,c=0;
    cin>>n;
    
    string a,b;
    cin>>a>>b;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]) continue;
        if(i<n-1&&(a[i]-48)==!(a[i+1]-48)&&(b[i]-48)==!(b[i+1]-48))
        {
            c++;
            i++;
            continue;
        }
        c++;
    }
    
    cout<<c;
}
