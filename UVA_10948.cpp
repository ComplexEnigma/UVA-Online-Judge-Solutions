#include<bits/stdc++.h>
using namespace std;
int status[1000005];
void sieve()
{
    status[0] = 1;
    status[1] = 1;
    for(int i=4; i<=1000001; i+=2 )
        status[i] = 1;
    for(int i=3; i*i<=1000001; i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*3; j<=1000001; j+=i)
                status[j] = 1;
        }
    }
}
int main()
{
    int n;
    sieve();
    
    while(scanf("%d",&n)==1 && n!=0)
    {

        int flag = 0;
        int f = 2;
        int s = n - f;
        if(status[n]==0 && status[s]==1)
        {
            printf("%d:\n", n );
            printf("NO WAY!\n");
            continue;
        }
        if(status[s]==0)
        {
            f = 2;
            s = n - f;
            flag = 1;
        }
        if(flag==0)
        {
            for(int i=3; i<=n/2; i+=2)
            {
                f = i; s = n-i;
                if(status[f]==0 && status[s]==0){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            printf("%d:\n" , n );
            printf("%d+%d\n", f , s );
        }
        else
        {
            printf("%d:\n", n );
            printf("NO WAY!\n");
        }
    }
    return 0;
}
