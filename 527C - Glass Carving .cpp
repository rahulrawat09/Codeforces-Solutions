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

ll n,h,w,num;
char c;
set<ll> hori,vert;
multiset<ll> maxh,maxv;

ll findmax()
{
    auto m=hori.begin();
    if(c=='H') m=hori.find(num);
    else m=vert.find(num);

    auto l=m,r=m;
    l--;
    r++;

    if(c=='H')
    {
        maxh.erase(maxh.find(*r-*l));
        maxh.insert(num-*l);
        maxh.insert(*r-num);
    }
    else
    {
        maxv.erase(maxv.find(*r-*l));
        maxv.insert(num-*l);
        maxv.insert(*r-num);
    }

    return (*maxv.rbegin())*(*maxh.rbegin());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>w>>h>>n;
    hori={0,h};
    vert={0,w};
    maxh.insert(h);
    maxv.insert(w);

    while(n--)
    {
        cin>>c>>num;
        if(c=='H')
        {
            hori.insert(num);
            cout<<findmax();
        }
        else
        {
            vert.insert(num);
            cout<<findmax();
        }
        cout<<"\n";
    }

    return 0;
}
