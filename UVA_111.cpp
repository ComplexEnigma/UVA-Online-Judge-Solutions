#include<bits/stdc++.h>
using namespace std;

int A[25];
int B[25];
int N;
int dp[25][25];

void reset()
{
    for( int i=0;i<25;i++)
    {
        B[i] = 0;
        for(int j=0; j<25; j++)
        {
            dp[i][j] = 0;
        }
    }
}

int lcs()
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1; j<=N; j++)
        {
            if( A[i]==B[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max( dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[N][N];
}

int main()
{
    //freopen("input.txt","r",stdin);
    string s, order;
    while( getline( cin, s ) )
    {
        int len = s.length();
        if( s.length() <= 2 )
        {
            N = 0;
            for(int i=0; i<len; i++ )
            {
                N = N * 10;
                N += s[i] - 48;
            }

            getline( cin, order );
            int n = 0;
            int num = 1;

            len = order.length();

            for( int i=0 ; i<len; i++ )
            {
                if( order[i]==32)
                {
                    A[n] = num;
                    num ++;
                    n = 0;
                }
                else
                {
                    n *= 10;
                    n += order[i] - 48;
                }
            }
            A[n] = num;
        }
        else
        {
            reset();
            int n = 0;
            int num = 1;
            for( int i=0 ; i<len; i++ )
            {
                if( s[i]==32)
                {
                    B[n] = num;
                    num ++;
                    n = 0;
                }
                else
                {
                    n *= 10;
                    n += s[i] - 48;
                }
            }
            B[n] = num;
            /*for(int i=0;i<=N;i++)
            {
                cout << "A = " << A[i] << "  B = " << B[i] << endl;
            }*/
            printf("%d\n",lcs());
        }
    }
    return 0;
}
