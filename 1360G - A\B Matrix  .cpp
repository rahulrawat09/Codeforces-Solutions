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

ll f[51];

bool comp(ll a,ll b)
{
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    testcases
    {
        ll n,m,a,b;
        cin>>n>>m>>a>>b;

        if(a*n != b*m)
        {
            cout<< "NO\n";
            continue;
        }

        for(int i=0;i<m;i++) f[i]=b;
        vector<vector<char>> s(n,vector<char>(m,'0'));

        int c=0;
        for(int i=0;i<n;i++)
        {
            sort(f,f+m,comp);
            for(int j=0;j<a;j++)
            {
                s[i][c] = '1';
                c++;
                c%=m;
                f[j]--;
            }
        }

        cout<< "YES\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cout<< s[i][j];
            cout<< "\n";
        }
    }

    return 0;
}
