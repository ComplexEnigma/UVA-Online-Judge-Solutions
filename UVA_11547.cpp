#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int t;
    scanf("%d",&t);
    int n;
    while(t--)
    {
       scanf("%d",&n);
       long long int r;
       r=n*567;
       r/=9;
       r+=7492;
       r*=235;
        r/=47;
        r-=498;
        r=r%100;
        r/=10;
        printf("%lld\n",abs(r));
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}
