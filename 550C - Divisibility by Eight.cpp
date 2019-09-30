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
    string s;
    cin>>s;
    
    int l=s.length();
    
    if(s[0]-48==0||s[1]-48==0)
    {
    	cout<<"YES"<<endl<<0;
    	return 0;
    }
    if(l==2)
    {
    	if(s[0]-48==8)
    	{
    	cout<<"YES"<<endl<<s[0]-48;
    	return 0;
        }
        if(s[1]-48==8)
    	{
    	cout<<"YES"<<endl<<s[1]-48;
    	return 0;
        }
    	
    }
    if(l<=3){
    if(stoi(s)%8==0)
    {
    	cout<<"YES"<<endl<<s;
    	return 0;
    }
    }
    
    for(int i=0;i<l;i++)
    {
    	for(int j=i+1;j<l;j++)
    	{
    		for(int k=j+1;k<l;k++)
    		{
    			if((s[i]-48)==0||(s[j]-48)==0||s[k]-48==0)
    			{
    				cout<<"YES"<<endl<<0;
    				return 0;
    			}
    			if(((s[i]-48)*100+(s[j]-48)*10+s[k]-48)%8==0)
    			{
    				cout<<"YES"<<endl<<(s[i]-48)*100+(s[j]-48)*10+s[k]-48;
    				return 0;
    			}
    			if((s[i]-48)%8==0)
    			{
    				cout<<"YES"<<endl<<s[i]-48;
    				return 0;
    			}
    			if((s[j]-48)%8==0)
    			{
    				cout<<"YES"<<endl<<s[j]-48;
    				return 0;
    			}
    			if((s[k]-48)%8==0)
    			{
    				cout<<"YES"<<endl<<s[k]-48;
    				return 0;
    			}
    			if(((s[i]-48)*10+s[j]-48)%8==0)
    			{
    				cout<<"YES"<<endl<<(s[i]-48)*10+s[j]-48;
    				return 0;
    			}
    			if(((s[j]-48)*10+s[k]-48)%8==0)
    			{
    				cout<<"YES"<<endl<<(s[j]-48)*10+s[k]-48;
    				return 0;
    			}
    			if(((s[i]-48)*10+s[k]-48)%8==0)
    			{
    				cout<<"YES"<<endl<<(s[i]-48)*10+s[k]-48;
    				return 0;
    			}
    		}
    	}
    }
    cout<<"NO";
}
    
