/*
*   Created By: nomyspy
*   Date :
*   Comlexity:
*/
#include<bits/stdc++.h>
using namespace std;

vector <int> v;
vector <int> DP;

int lcs(int sz)
{
    DP.clear();
    //DP.push_back(v[0]);
    int dps = 0;

    for(int i=0;i<sz;i++)
    {
        int flag = 0;
        //cout << v[i] << endl;
        for(int j=0;j<dps;j++)
        {
            if(DP[j]>=v[i])
            {
                continue;
            }
            else
            {
                DP[j] = v[i];
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            DP.push_back(v[i]);
            dps ++;
        }
    }
    /*for(int i=0;i<dps;i++)
    {
        cout << DP[i] << endl;
    }*/
    return DP.size();
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    int cases = 1;
    while(scanf("%d",&n) ==1 && n!=-1)
    {
        if(cases>1)
            printf("\n");
        v.clear();
        int m;
        int element = 1;
        v.push_back(n);
        while( scanf("%d",&m)==1 && m!=-1)
        {
            v.push_back( m );
            element ++;
        }
        printf("Test #%d:\n",cases++);
        printf("  maximum possible interceptions: %d\n",lcs(element));
    }
    return 0;
}
