#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI 3.1415926536
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int x=a,y=b,z=c,diff=INT_MAX;

        for(int i=1;i<=10000;i++)
        {
            for(int j=1;j<=10000;j++)
            {
                if(i*j>100000) break;
                for(int k=1;k<=10000;k++)
                {
                    if(i*j*k>100000) break;
                    int f=abs(a-i)+abs(b-i*j)+abs(c-i*j*k);
                    if(f<diff)
                    {
                        x=i;
                        y=i*j;
                        z=i*j*k;
                        diff=f;
                    }
                }
            }
        }
        cout<<diff<<"\n"<<x<<" "<<y<<" "<<z<<"\n";
    }
    return 0;
}
