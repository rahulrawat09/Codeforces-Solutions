#include<bits/stdc++.h>
#define ll long long
#define MOD int(1e9+7)
#define mp make_pair
#define pb push_back
using namespace std;
vector<vector<int>> e(401);

int main()
{
    map<int,int> m{
    {4,0},{8,1},{15,2},{16,3},{23,4},{42,5}
    };
    map<int,int> p{
    {8,4},{15,8},{16,15},{23,16},{42,23}
    };
    vector<int> c(6,0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==4)
        {
            c[m[4]]++;
            continue;
        }
        if(c[m[p[x]]]>0)
        {
            c[m[p[x]]]--;
            c[m[x]]++;
        }
    }
    cout<<n-6*c[5];
    return 0;
}
