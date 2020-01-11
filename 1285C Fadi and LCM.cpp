#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> factor(ll n)
{
    vector<ll> v;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(i==n/i) v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }

    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll> v=factor(n);
    ll a=1,b=n;
    sort(v.begin(),v.end());

    for(int i=2;i<v.size()-1;i++)
    {
        bool f=0;
        for(int j=1;j<i;j++)
        {
            ll x=__gcd(v[i],v[j]);
            if((v[i]*v[j])/x==n)
            {
                a=v[j];
                b=v[i];
                f=1;
                break;
            }
        }
        if(f) break;
    }
    cout<<a<<" "<<b;
    return 0;
}
