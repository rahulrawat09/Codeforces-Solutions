#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI 3.1415926536
using namespace std;

bool check(int a)
{
    int n=ceil(log2(a));
    return (((1<<n)-1)&a)==((1<<n)-1)||a==0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,f=0;
    cin>>n;
    if(check(n)){ cout<<0;return 0;}
    vector<int> ans;
    while(!check(n))
    {
        int b=ceil(log2(n))+(bool)(ceil(log2(n))==floor(log2(n)));
        ans.pb(b);
        b=(1<<b)-1;
        n=b^n;
        if(check(n)){ f=1;break;}
        n+=1;
    }
    cout<<2*ans.size()-f<<"\n";
    for(int& i:ans) cout<<i<< " ";
    return 0;
}
