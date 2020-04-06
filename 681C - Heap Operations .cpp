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
    int n,ans;
    cin>>n;
    ans=n;
    vector<pair<string,int>> v;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        string s;
        int x;
        cin>>s; 
        if(s!="removeMin") cin>> x;

        if(s=="insert") pq.push(x);
        else if(s=="getMin")
        {
            while(!pq.empty()&&pq.top()<x)
            {
                ans++;
                pq.pop();
                v.pb({"removeMin",1});
            }
            if(pq.empty()||pq.top()>x)
            {
                ans++;
                pq.push(x);
                v.pb({"insert",x});
            }
        }
        else if(pq.empty()) 
        {
            ans++;
            v.pb({"insert",1});
        }
        else pq.pop();
        v.pb({s,x});
    }
    cout<<ans<<"\n";
    for(int i=0;i<ans;i++)
    {
        cout<<v[i].first<<" ";
        if(v[i].first!="removeMin") cout<<v[i].second;
        cout<<"\n";
    }
    return 0;
}
