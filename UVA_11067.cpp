#include<bits/stdc++.h>
using namespace std;
#define ll long long
int row , column;
bool Arr[ 105 ][ 105 ];
bool visited[ 105 ][ 105 ];
ll DP[ 105 ][ 105 ];

ll findway( int r , int c )
{
    // cout << r << "   " << c << endl << endl;
    if( r == row && c== column ){
       //  cout << "YES\n";
        return 1;
    }
    if( r > row || c > column )
        return 0;
    if( Arr[ r ][ c ] == 1 ){
       //  cout << "Crossing "<< "  \n";
        return 0;
    }
    if( visited[ r ][ c ] )
        return 0;
    if( DP[ r ][ c ] != 0 )
        return DP[ r ][ c ];
    

    visited[ r ][ c ] = 1;
    
    ll ret1 = findway( r + 1 , c );
    DP[ r + 1][ c ] += ret1;
    visited[ r ][ c ] = 0;
    ll ret2 = findway( r , c + 1 );
    visited[ r ][ c ] = 0;
    DP[ r ][ c + 1 ] += ret2;

    return DP[ row ][ column ] = ret1 + ret2;
}

void solve()
{

        while( scanf("%d %d" , &row , &column ) == 2 )
        {
                if( row == 0 && column == 0 )
                        break;

                memset( Arr, 0 , sizeof( Arr ) );
                memset( visited, 0 , sizeof( visited ) );

                memset( DP, 0 , sizeof( DP ) );
                
                int n;
                scanf("%d" , &n );

                for(int i = 0; i < n; i++ )
                {
                        int u , v;
                        scanf("%d %d" , &u , &v );
                        Arr[ u ][ v ] = 1;
                }
        
                ll ans = findway( 0 , 0 );

                if( ans == 0 )
                        puts("There is no path.");
                else if( ans == 1 )
                        puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
                else
                        printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n" , ans );
                
        }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin );
    #endif
    solve();
    return 0;
} 
