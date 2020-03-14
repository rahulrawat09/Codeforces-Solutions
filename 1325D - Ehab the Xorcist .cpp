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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b;
    cin>>a>>b;

    if((b-a)%2!=0||a>b)
    {
        cout<<-1<<"\n";
        return 0;
    }
    if(a==b&&a==0)
    {
        cout<<0;
        return 0;
    }

    deque<ll> q;
    q.pb((b-a)/2);q.pb((b-a)/2);q.pb(a);
    int s=3;
    while(s!=1)
    {
        if((q[s-1]^q[s-2])==(q[s-1]+q[s-2]))
        {
            ll x=q[s-1]^q[s-2];
            q.pop_back();q.pop_back();
            q.pb(x);
            s--;
        }
        else break;
    }
    cout<<s<<"\n";
    for(ll& i:q) cout<<i<<" ";

    return 0;
}
