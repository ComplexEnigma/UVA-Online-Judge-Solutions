#include<bits/stdc++.h>
using namespace std;
int status[20000005];
void sieve()
{
    status[0] = 1;
    status[1] = 1;
    for(int i=3; i*i<=20000005; i+=2)
    {
        for(int j=i*3; j<=20000001; j+=i)
        {
            status[j] = 1;
        }
    }
}
int main()
{
    sieve();
    int n;
   // freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1)
    {
        int f = n/2;
        int s = n - f;
        //cout << f <<"  " << s << endl;
        if(f%2==1 && s%2==1)
        {
            f++;
            s--;
        }
        else if(f%2==0 && s%2==1)
        {
            s = 5;
            f = n - s;
        }
        else if(f%2==1 && s%2==0)
        {
            f = 5;
            s = n - f;
        }
        //cout << f <<"  " << s << endl;
        int a, b, c, d;
        int flag1 = 0, flag2 = 0;
        int i = 2;
        while( i<=n/2 )
        {
            if(status[i]==0 && status[f-i]==0 && f-i>=2 && flag1==0)
            {
                if(f-i!=2 && (f-i)%2==0)
                {
                }
                else
                {
                    a = i;
                    b = f - i;
                    flag1 = 1;
                }
            }
            if(status[i]==0 && status[s-i]==0 &&  s-i>=2 && flag2==0)
            {
                if(s-i!=2 && (s-i)%2==0)
                {
                }
                else
                {
                    c = i;
                    d = s - i;
                    flag2 = 1;
                }
            }
            if(flag1 && flag2)
                break;
            if(i==2)
                i++;
            else
                i+=2;
        }

        if(!flag1 || !flag2)
            printf("Impossible.\n");
        else
            printf("%d %d %d %d\n",a,b,c,d);
    }
    return 0;
}
