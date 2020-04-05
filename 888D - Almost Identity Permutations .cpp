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

ll der[1001];

void countDer(ll n) 
{ 

    der[0] = 1; 
    der[1] = 0; 
    der[2] = 1; 

    for (ll i = 3; i <= n; ++i) 
        der[i] = (i - 1) * (der[i - 1] +  
                            der[i - 2]); 
    return; 
}

ll binomialCoeff(ll n, ll k)         //  nCk
{ 
    ll C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;  // nC0 is 1 
  
    for (ll i = 1; i <= n; i++) 
    { 
        // Compute next row of pascal triangle using 
        // the previous row 
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 

int main()
{
    countDer(1000);
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=0;i<=k;i++) ans+=binomialCoeff(n,n-i)*der[i];
    cout<<ans;
    return 0;
}

