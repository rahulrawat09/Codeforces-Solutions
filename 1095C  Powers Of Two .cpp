#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define pb push_back
using namespace std;
 
 
int main()
{
    int n,k;
    cin>>n>>k;
 
    if(k>n)
    {
        cout<<"NO";
        return 0;
    }
 
    priority_queue<int> pq;
    int pow=1;
    while(n)
    {
        if(n%2) pq.push(pow);
        n=n>>1;
        pow*=2;
    }
    if(pq.size()>k)
    {
        cout<<"NO";
        return 0;
    }
 
    while(pq.size()!=k)
    {
        if(pq.top()==1) break;
        int x=pq.top();
        pq.pop();
        pq.push(x/2);
        pq.push(x/2);
    }
 
    cout<<"YES\n";
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
 
    return 0;
}
