#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
//#define bint int1024_t
#define ld long double
#define vect vector<ll>
#define unmap unordered_map
#define pb push_back
#define F first
#define S second
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        vector<string> v(k);

        for(int i=0;i<n;i++)
        {
            v[i%k].pb(s[i]);
        }
        int f=0;
        string ans=v[0];
        for(int i=1;i<k;i++)
        {
            if(v[i][0]!=v[i-1][0]) f=1;
            ans=max(ans,v[i]);
        }
        if(f)
        {
            cout<<ans.substr(0,1)<<"\n";
            continue;
        }
        string c=ans;
        ans=v[0].substr(0,1);
        for(int i=0;i<k;i++)
        {
            for(int j=1;j<v[i].length();j++) ans.pb(v[i][j]);
        }
        sort(ans.begin(),ans.end());
        cout<<min(c,ans)<<"\n";
    }

    return 0;
}

