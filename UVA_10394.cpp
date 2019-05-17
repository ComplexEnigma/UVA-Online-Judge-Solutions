#include<bits/stdc++.h>
using namespace std;
int status[20000005];
vector <pair<int,int> > v;
void sieve()
{
    for(int i=3;i*i<=20000005;i+=2)
    {
        if(status[i]==0)
        {
            for(int j=3*i;j<=20000001;j+=i)
                status[j] = 1;
        }
    }
    for(int i=3;i<=20000000;i+=2)
    {
        if(status[i]==0 && status[i+2]==0)
            v.push_back(make_pair(i,i+2));
    }
}
int main()
{
    sieve();
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("(%d, %d)\n",v[n-1].first,v[n-1].second);
    }
    return 0;
}
