#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
#define mp make_pair
#define mod int(998244353)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    ll a,b,n=s.length();
    cin>>a>>b;
    ll pref[n+1]={0},suff[n+1]={0};
    ll pow=1;

    for(int i=n-1;i>=0;i--)
    {
        suff[i]=suff[i+1]+(s[i]-'0')*pow;
        suff[i]%=b;
        pow=(pow*10)%b;
    }
    pref[0]=(s[0]-'0')%a;
    pow=10;
    for(int i=1;i<n;i++)
    {
        pref[i]=(s[i]-'0')+10*pref[i-1];
        pref[i]%=a;
    }

    for(int i=0;i<n-1;i++)
    {
        if(s[i+1]!='0'&&pref[i]==0&&suff[i+1]==0)
        {
            cout<<"YES\n";
            cout<<s.substr(0,i+1)<<"\n";
            cout<<s.substr(i+1);
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
