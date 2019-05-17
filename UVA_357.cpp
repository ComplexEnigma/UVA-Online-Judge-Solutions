#include<bits/stdc++.h>
using namespace std;
#define ll long long
int Arr[] = { 1 , 5 , 10 , 25 , 50 };
ll DP[ 30005 ][ 7 ];

ll coin_change( int n , int idx )
{

    if( n < 0 )
        return 0;
    if( n == 0 )
        return 1;
    if( n == 1 )
        return 1;
    if( idx < 0 && n >= 1)
        return 0;

    if( DP[ n ][ idx ] != -1 )
        return DP[ n ][ idx ];


    DP[ n ][ idx ] = coin_change( n - Arr[ idx ] , idx );
    DP[ n ][ idx ] += coin_change( n , idx - 1 );

    return DP[ n ][ idx ];

}

int main()
{

    memset( DP, -1 , sizeof( DP ) );
    int n;
    while( scanf("%d" , &n ) == 1 )
    {
        ll ans = coin_change( n , 4 );

        if( ans == 1 )
            printf("There is only 1 way to produce %d cents change.\n" , n );
        else
            printf("There are %lld ways to produce %d cents change.\n" , ans , n );

    }
    return 0;
}
