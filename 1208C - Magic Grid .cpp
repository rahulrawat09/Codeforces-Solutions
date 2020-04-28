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

    ll n,x;
    cin>>n;
    x=n/2;
    vector<vect> v(n,vect(n));

    int k=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<x;j++)
        {
            v[i][j]=k++;
            v[i+x][j]=4*v[i][j]+1;
            v[i][j+x]=4*v[i][j]+2;
            v[i+x][j+x]=4*v[i][j]+3;
            v[i][j]*=4;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
