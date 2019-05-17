#include<bits/stdc++.h>
using namespace std;
int DP[ 10005 ];
class LastNonZero{

public:
        int n ;
        LastNonZero( int a )
        {
                n = a;
                
                DP[ 0 ] = 1, DP[ 1 ] = 1, DP[ 2 ] = 2, DP[ 3 ] = 6;
                DP[ 4 ] = 4, DP[ 5 ] = 2, DP[ 6 ] = 2, DP[ 7 ] = 4;
                DP[ 8 ] = 2, DP[ 9 ] = 8;
        }

        int Compute( int a )
        {
                if( DP[ a ] != -1 )
                        return DP[ a ];

                int second_digit = ( a / 10 ) % 10;
                
                if( !(second_digit & 1) )
                {
                        return DP[ a ] =  ( 6 * Compute( a / 5 ) * DP[ a%10 ] ) % 10;
                }
                else
                {
                        return DP[ a ] =  ( 4 * Compute( a / 5 ) * DP[ a%10 ] ) % 10; 
                }
        }
};

int main()
{
        #ifndef ONLINE_JUDGE
                freopen("input.txt" , "r" , stdin );
        #endif
        int a;
        memset( DP , -1 , sizeof( DP ) );
        while( scanf("%d" , &a )==1 )
        {
                LastNonZero ob( a );
                int ans = ob.Compute( a );
                printf("%5d -> %d\n" , a , ans );
        }
        return 0;
}
