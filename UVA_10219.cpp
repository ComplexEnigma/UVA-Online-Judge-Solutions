#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    long long n , k;
    while(scanf("%lld %lld",&n,&k)==2)
    {
        double ans1 = 0, ans2 = 0;
        long long i, lv = k > (n-k) ? k : (n-k);
        long long lv2 = k < (n-k) ? k : (n-k);
        for(i = lv+1;i<=n;i++)
        {
            ans1 += log10(i);
        }
        for(i = 1; i<= lv2; i++)
        {
            ans2 += log10(i);
        }
        double ans = floor(ans1 - ans2);
        ans += 1;
        printf("%.0f\n",ans);
    }
    return 0;
}
