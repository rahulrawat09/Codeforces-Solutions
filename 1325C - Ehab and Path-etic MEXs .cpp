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
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

struct edge
{
    int u;
    int v;
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    edge e[n];

    int i,j,k;
    vector<ll> degree(n+1,0);

    for(i=1;i<=n-1;i++)
    {
        cin>>e[i].u>>e[i].v;
        degree[e[i].u]++;
        degree[e[i].v]++;
    }

    int pf=0;
    int pl=n-2;

    for(i=1;i<=n-1;i++)
    {
        if(degree[e[i].u]==1||degree[e[i].v]==1)
        {
            cout<<pf<<"\n";
            pf++;
        }
        else
        {
            cout<<pl<<"\n";
            pl--;
        }
    }
    return 0;
}
