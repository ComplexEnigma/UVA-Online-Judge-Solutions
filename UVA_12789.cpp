#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while(scanf("%d %d",&n,&m)==2)
    {
        int counter = 0;
        for(int i=0;i<n;i++)
        {
            int flag = 0;
            for(int j=0;j<m;j++)
            {
                int a;
                scanf("%d",&a);
                if(a==0)
                    flag = 1;
            }
            if(!flag)
                counter++;
        }
        printf("%d\n",counter);
    }
    return 0;
}
