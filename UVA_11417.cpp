#include<bits/stdc++.h>
using namespace std;

map<int,vector<int> > DP;
int A[505];

int gcd(int a,int b)
{
    if (a == 0 || b == 0)
       return 0;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

void precall()
{
    for(int i=1;i<500;i++)
    {
        for(int j=i+1;j<=500;j++)
        {
            DP[i].push_back( gcd(i,j) );
        }
    }
}

int main()
{
    precall();
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int p = n;
        int sum = 0;
        if( A[n]!=0 )
        {
            sum = A[n];
            printf("%d\n",sum);
            continue;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<p-1;j++)
            {
                sum += DP[i][j];
            }
            p --;
        }
        A[n] = sum;
        printf("%d\n",sum);
    }
    return 0;
}
