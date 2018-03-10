#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int n;
    int a;
    int p;
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        int hc=0,lc=0;
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a);
            if(j==0)
                p=a;
            else
            {
                if(a>p)
                {
                    hc++;
                    p=a;
                }
                else if(a<p)
                {
                    lc++;
                    p=a;
                }
                else
                {
                    p=a;
                }
            }
        }
        printf("Case %d: %d %d\n",i,hc,lc);
    }
    return 0;
}
