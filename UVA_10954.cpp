#include<bits/stdc++.h>
using namespace std;
priority_queue <int,vector<int>,greater<int> > Q;
int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    while( scanf("%d",&n) == 1 && n!=0)
    {
        while(!Q.empty())
        {
            Q.pop();
        }
        for(int i=0;i<n;i++)
        {
            int a ;
            scanf("%d",&a);
            Q.push(a);
        }
        long long cost = 0;
        int a , b;
        while(!Q.empty())
        {
            if(!Q.empty())
            {
                a = Q.top();
                Q.pop();
            }
            else
            {
                a = 0;
            }
            if(!Q.empty())
            {
                b = Q.top();
                Q.pop();
            }
            else
            {
                b = 0;
            }
            cost = cost + a + b;
            if( !Q.empty() )
                Q.push( a + b );
            else
                break;
        }
        printf("%lld\n",cost);
    }
}
