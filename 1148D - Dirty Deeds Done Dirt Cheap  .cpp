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
#define mod int(1e9+7)
//ios_base::sync_with_stdio(false);cin.tie(NULL);
#define testcases ll t; cin>>t; while(t--)

using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

bool comp1(vect& a,vect& b)
{
    return a[1]>b[1];
}

bool comp2(vect& a,vect& b)
{
    return a[1]<b[1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vect> a,b;
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        if(x<y) a.pb({x,y,i});
        else b.pb({x,y,i});
    }

    sort(a.begin(),a.end(),comp1);
    sort(b.begin(),b.end(),comp2);

    if(a.size()>b.size())
    {
        cout<<a.size()<<"\n";
        for(auto& i:a) cout<<i[2]+1<<" ";
    }
    else
    {
        cout<<b.size()<<"\n";
        for(auto& i:b) cout<<i[2]+1<<" ";
    }

    return 0;
}
