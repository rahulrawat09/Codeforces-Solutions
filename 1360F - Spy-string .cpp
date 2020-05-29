#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint ll 1024_t
#define ld long double
#define vect vector<ll>
#define pb push_back
#define F first
#define pll pair<ll,ll>
#define S second
#define pi 3.1415926536
#define mp make_pair
#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int comp(string a, string b)
{
    int c=0;
    for(int i=0;i<a.length();i++) c+=(a[i]!=b[i]);
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        ll n,m;
        cin>>n>>m;
        vector<string> s(n);
        for(auto& i:s) cin>>i;

        string ans;
        int f=0;
        for(int k=0;k<m;k++)
        {
            char z=s[0][k];
            for(char c='a';c<='z';c++)
            {
                s[0][k]=c;
                int i=1;
                for(i=1;i<n;i++)
                {
                    if(comp(s[0],s[i])>1) break;
                }
                if(i==n)
                {
                    f=1;
                    ans=s[0];
                    break;
                }
            }
            s[0][k]=z;
            if(f) break;
        }

        if(!f) cout<<-1;
        else cout<<ans;
        cout<<"\n";

    }

    return 0;
}
