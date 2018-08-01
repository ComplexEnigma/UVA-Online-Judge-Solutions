#include<bits/stdc++.h>
using namespace std;
int _I(){int x;scanf("%d",&x);return x;}
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define ll long long
vector <int> v;
int n ;
long long maxsum()
{
    int i;
    ll result = 0 , sum = 0;
    rep(i,n)
    {
        sum = max( (ll)v[i], sum+(ll)v[i] );
        result = max( sum, result );
    }
    return result;
}
int main()
{
    while(scanf("%d",&n)==1 && n!=0)
    {
        v.clear();
        int i;
        rep(i,n)
        {
            int a = _I();
            v.pb(a);
        }
        ll ans = maxsum();
        if( ans <= 0 )
        {
            puts("Losing streak.");
        }
        else
        {
            printf("The maximum winning streak is %lld.\n", ans );
        }
    }
    return 0;
}
