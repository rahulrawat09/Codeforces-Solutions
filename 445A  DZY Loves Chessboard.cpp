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
    
    int n,m;
    cin>>n>>m;
    
    vector<string> s(n);
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    
    for(int i=0;i<n;i++) cin>>s[i];
    
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]=='.')
            {
                if((i+j)%2==0) s[i][j]='B';
                else s[i][j]='W';
            }
        }
        cout<<s[i]<<endl;
    }
}
