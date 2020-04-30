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

ll n,s=0;
pair<ll,ll> p[7001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].F;
    for(int i=0;i<n;i++) cin>>p[i].S;

    vector<bool> visited(n,0);

    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;
        int f=0;
        for(int j=i+1;j<n;j++)
        {
            if(visited[j]) continue;
            if(p[i].F==p[j].F)
            {
                s+=p[j].S;
                if(!f) s+=p[i].S,f=1;
                visited[i]=1;
                visited[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(visited[i]) continue;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]) continue;
            if(((~p[j].F)&p[i].F)==0)
            {
                visited[i]=1;
                s+=p[i].S;
                break;
            }
        }
    }
    cout<<s;
    return 0;
}
