#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define pll pair<ll,ll>
#define S second
#define F first
#define unmap unordered_map
#define pb push_back
#define pi 3.1415926536
#define mod int(998244353)
#define mp make_pair
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    string s;
    cin>>n>>s;
    
    int i=0,j=0,o=0,x=0,y=0,ans=0;
    for(auto& i:s) if(i=='G') o++;

    while(j<s.length())
    {
        if(s[j]=='G') o-=1,y+=1;
        else x++;

        while(x>1)
        {
            if(s[i]=='G') o+=1,y-=1;
            else x--;
            i++;
        }
        if(x==1)
        {
            if(o) ans=max(ans,j-i+1);
            else if(y) ans=max(ans,j-i);
        }
        else ans=max(ans,j-i+1);

        j++;
    }

    cout<<ans;
    
    return 0;
}       
