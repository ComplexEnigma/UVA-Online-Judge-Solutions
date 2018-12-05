#include<bits/stdc++.h>
using namespace std;

int n;
int Arr[ 105 ];
int DP[ 105 ][ 25005 ];

/*void Reset( )
{
    for(int i =0; i<30005; i++ )
        for(int j = 0; j < 105; j++ )
            DP[ i ][ j ] = 0;
}*/

int knapsack( int x )
{
    for(int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= x; j++ )
        {
            if( j < Arr[ i ] )
            {
                DP[ i ][ j ] = DP[ i - 1 ][ j ];
            }
            else
            {
                DP[ i ][ j ] = max( DP[ i - 1 ][ j ] , Arr[ i  ] + DP[ i-1 ][ j - Arr[ i ] ] );
            }
        }
    }

    return DP[ n ][ x ];
}

int main()
{
    //freopen("output.txt" , "w" , stdout );
    int t ;
    scanf("%d" , &t );

    while( t-- )
    {
//        Reset();

        scanf("%d" , &n );

        int total_amount = 0;

        for(int i = 1; i <= n; i++ )
        {
            scanf("%d" , &Arr[ i ] );

            total_amount += Arr[ i ];
        }

        sort( Arr , Arr + n );

        int capacity = total_amount / 2;



        int ans1 = knapsack( capacity );


        int ans2 = total_amount - ans1;

        printf("%d\n" ,  abs( ans1 - ans2 ) );

    }
    return 0;
}
