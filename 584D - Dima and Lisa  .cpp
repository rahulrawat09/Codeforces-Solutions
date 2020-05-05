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

bool isprime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,x;
    cin>>n;

    if(isprime(n))
    {
        cout<<1<<"\n"<<n;
        return 0;
    }
    x=n-1;

    while(!isprime(x)) x--;

    if(isprime(n-x))
    {
        cout<<2<<"\n";
        cout<<n-x<<" "<<x;
        return 0;
    }
    cout<<3<<"\n";
    cout<<x<<" ";
    ll y=n-x;

    for(int i=2;i<=300;i++)
    {
        if(isprime(i)&&isprime(y-i))
        {
            cout<<i<<" "<<y-i;
            return 0;
        }
    }
    return 0;
}
