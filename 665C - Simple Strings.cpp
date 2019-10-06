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
    
    string s;
    cin>>s;
    
    int l=s.length();
    
    for(int i=0;i<l-1;i++)
    {
        
        if(s[i]==s[i+1])
        {
            if(i==l-2) s[i+1]++;
            else if(s[i+1]==s[i+2]) s[i+1]++;
            else{ 
                if(s[i+1]=='z')
                {
                    if(s[i+2]=='a') s[i+1]='y';
                    else s[i+1]='a';
                }
                else if(s[i+1]=='y'&&s[i+2]=='z') s[i+1]='x';
                else s[i+1]+=s[i+1]+1==s[i+2]?2:1;
            }
            
            if(s[i+1]=='{') s[i+1]='a';
        }
    }
    
    cout<<s;
}
