#include<bits/stdc++.h>
using namespace std;
int Arr[ 105 ] , idx;
char h[ 4 ];
char dp[ 256 ][ 4 ];
bool store[ 256 ];

void toHex( int n )
{
    int in = 1;
    if( store[ n ]==1 )
    {
        strcpy( h , dp[ n ] );
        return;
    }
    if( n==0 )
    {
        h[ 0 ] = '0' , h[ 1 ] = '0', h[ 2 ] = '\0';
        return;
    }
    h[ 2 ] = '\0';
    int temp = n;
    while( n!= 0 )
    {
        int ld = n % 16;
        //cout << ld << endl;
        if( ld<10 )
        {
            h[ in-- ] = ld + '0';
        }
        else
        {
            h[ in-- ] = ld + 55;
        }
        n /= 16;
    }
    if( in== 0 )
        h[ in ] = '0';
   strcpy( dp[ n ] , h );
}

int main()
{
//    freopen("input.txt" , "r" , stdin );
//    freopen("output.txt" , "w" , stdout );
    int t;
    scanf("%d" , &t );
    getchar();
    int cases =  0;

    while( cases++ < t )
    {
        memset(Arr, 0 , sizeof(Arr) );
        idx = 0;
        string s;
        getline( cin , s );

        int len = s.length();

        for(int i = 0; i < len; i++ )
        {
            if( s[ i ]=='>' ){
                idx = ( idx + 1 ) % 100;
            }
            else if( s[ i ]=='<' ){
                idx--;
                if( idx<0 )
                {
                    idx = 99;
                }
            }
            else if( s[ i ]=='+' )
            {
                Arr[ idx ]++;
                Arr[ idx ] %= 256;
            }
            else if( s[ i ]=='-' )
            {
                Arr[ idx ] --;
                if( Arr[ idx ] < 0 )
                {
                    Arr[ idx ] = 255;
                }
            }
        }

        printf("Case %d: " , cases );
        toHex( Arr[ 0 ] );
        printf("%s", h );
        for(int i = 1; i < 100; i++ )
        {
            toHex( Arr[ i ] );
            printf(" %s" , h );
        }
        printf("\n");
    }
    return 0;
}
