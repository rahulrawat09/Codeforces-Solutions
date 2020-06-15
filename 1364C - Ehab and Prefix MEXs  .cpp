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

ll n;
set<ll> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    vect v(n), ans(n);
    for(int i = 0; i <= 2*n; i++) s.insert(i);

    bool ok = 1;
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
        if(v[i]>i+1) ok = 0;
        if(s.find(v[i])!=s.end()) s.erase(v[i]);
    }

    if(!ok)
    {
        cout<<-1;
        return 0;
    }

    for(int i = 0; i < n; i++)
    {
        if(i > 0 && v[i] != v[i-1]) ans[i] = v[i-1];
        else
        {
            ans[i] = *s.begin();
            s.erase(s.begin());
        }
    }

    for(ll& i:ans) cout<<i<<" ";

    return 0;
}
