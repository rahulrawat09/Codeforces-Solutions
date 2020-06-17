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
#define pll pair<ll,ll>
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
        string s;
        cin>>s;
        ll n;
        cin>>n;
        vect b(n),m(27,0);
        vector<char> ans(n,'*');
        for(ll& i:b) cin>>i;
        for(auto& i:s) m[i-'a']++;

        int pointer = 25;

        while(1)
        {
            vect zero;
            for(int i = 0; i<n; i++)
            {
                if (ans[i] == '*' && b[i] == 0) zero.pb(i);
            }
            if(zero.empty()) break;
            while(m[pointer]<zero.size()) pointer--;

            for(int i = 0; i<n; i++)
            {
                if (ans[i] == '*' && b[i] == 0) ans[i] = 'a' + pointer;
            }

            for(auto& i:zero)
            {
                for(int j = 0; j<n; j++)
                {
                    if(ans[j]!='*') continue;
                    b[j] -= abs(j-i);
                }
            }
            pointer--;
        }
        for(auto& i:ans) cout<<i;
        cout<<"\n";
    }

    return 0;
}
