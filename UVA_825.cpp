#include<bits/stdc++.h>
using namespace std;

int row , column;
bool Arr[ 10005 ][ 10005 ];
bool visited[ 10005 ][ 10005 ];
int findway( int r , int c )
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
    

    visited[ r ][ c ] = 1;
    
    int ret1 = findway( r + 1 , c );
    visited[ r ][ c ] = 0;
    int ret2 = findway( r , c + 1 );
    visited[ r ][ c ] = 0;

    return ret1 + ret2;
}

void solve()
{
    int t;
    scanf("%d" , &t );
    int cases = 1;
    while( t-- )
    {
        if( cases ++ >= 2 )
            printf("\n");
        memset( Arr , 0 , sizeof( Arr ) );
        scanf("%d %d" , &row , &column );
        getchar();

        for(int i = 1; i <= row; i++ )
        {
            // cout << "YES\n";
            string s;
            getline( cin ,s );
            //getchar();
            //cout << s << endl;

            int n = 0;

            int len = s.length();

            int flag = 0;

            for(int j = 0; j < len; j++ )
            {
                if( s[ j ] == 32 && n != 0 )
                {
                    if( flag == 0 )
                    {
                        flag = 1;
                        n = 0;
                        continue;
                    }
                    // cout << i << "  <->  " << n << endl;
                    Arr[ i ][ n ] = 1;
                    n = 0;
                }
                else if( s[ j ] >= '0' && s[ j ] <= '9' )
                {
                    n *= 10;
                    n += s[ j ] - '0';
                }
            }

            if( n != 0 )
            {
                if( !flag )
                    continue;
                Arr[ i ][ n ] = 1;
                n = 0;
            }
        }

        memset( visited , 0 , sizeof( visited ) );
        int ans = findway( 1 , 1 );

        printf("%d\n" , ans );
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
