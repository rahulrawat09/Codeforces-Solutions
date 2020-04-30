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

    ll n;
    cin>>n;
    pair<ll,ll> v[n];
    vector<pair<ll,ll>> ans;
    for(int i=0;i<n;i++) cin>>v[i].F>>v[i].S;

    queue<ll> q;
    for(int i=0;i<n;i++)
    {
        if(v[i].F==1) q.push(i);
    }

    while(!q.empty())
    {
        ll p=q.front();
        q.pop();
        if(v[p].F==0) continue;
        v[v[p].S].F--;
        v[v[p].S].S^=p;
        ans.pb({p,v[p].S});
        if(v[v[p].S].F==1) q.push(v[p].S);
    }
    cout<<ans.size()<<"\n";
    for(auto& i:ans) cout<<i.F<<" "<<i.S<<"\n";

    return 0;
}
