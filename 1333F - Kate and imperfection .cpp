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
#define pi 3.1415926536
#define mod int(1e9+7)
#define mp make_pair
#define testcases ll t; t=1; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

vector<vector<int>> v(500001);

void cal(ll n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=2*i;j<=n;j+=i) v[j].pb(i);
    }
}

bool comp(vector<int>& a,vector<int>& b)
{
    return a[a.size()-1]<b[b.size()-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    testcases
    {
        ll n;
        cin>>n;
        v.resize(n+1);
        v[0].pb(0);
        v[1].pb(1);
        cal(n);
        sort(v.begin(),v.end(),comp);
        for(int i=2;i<=n;i++) cout<<v[i][v[i].size()-1]<<" ";
    }

    return 0;
}
