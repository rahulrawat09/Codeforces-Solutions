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

ll n,m;
vector<vect> v(1001,vect(3));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    vect ans(n+1,0);
    for(int i=0;i<m;i++)
    {
        cin>>v[i][0]>>v[i][1]>>v[i][2];
        if(v[i][0] == 1)
        {
            for(int j = v[i][1]+1; j <= v[i][2]; j++)
                ans[j] = 1;
        }
    }

    for(int i=0;i<m;i++)
    {
        if(v[i][0] == 0)
        {
            int f = 1;
            for(int j = v[i][1]+1; j <= v[i][2]; j++)
                if(ans[j] == 0)
                    f=0;

            if(f)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    ans[1]=5000;
    cout<<ans[1]<<" ";
    for(int i=2;i<=n;i++)
    {
        if(ans[i] == 0) ans[i]=ans[i-1]-1;
        else ans[i] = ans[i-1]+1;
        cout<<ans[i]<<" ";
    }

    return 0;
}
