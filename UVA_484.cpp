#include<bits/stdc++.h>
using namespace std;

vector <int> v;
int POS[100005];
int NEG[100005];

int main()
{
    int n;
    while(scanf("%d",&n) == 1 )
    {
        if( n >=0 && POS[n]== 0)
        {
            v.push_back(n);
            POS[n] ++;
        }
        else if( n>=0 && POS[n]!=0 )
        {
            POS[n] ++;
        }
        else if( n<0 && NEG[abs(n)]==0)
        {
            v.push_back(n);
            NEG[abs(n)] ++;
        }
        else
        {
            NEG[abs(n)] ++;
        }
    }
    for(auto it=v.begin();it!=v.end();it++)
    {
        printf("%d",*it);
        if( *it<0 )
        {
            printf(" %d\n",NEG[abs(*it)]);
        }
        else
        {
            printf(" %d\n",POS[*it]);
        }
    }
    return 0;
}
