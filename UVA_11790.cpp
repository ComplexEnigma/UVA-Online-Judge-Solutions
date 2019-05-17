#include<bits/stdc++.h>
using namespace std;

int n;
int cases;

class MuriciaSkyline{
public:
        int h[ 100005 ] , w[ 100005 ];
        int inc , dec;
        int DP1[ 10005 ] , DP2[ 10005 ];

        MuriciaSkyline( int a )
        {
                for(int i = 0; i < a; i++ )
                        scanf("%d" , &h[ i ] );
                for(int i = 0; i < a; i++ )
                        scanf("%d" , &w[ i ] );
                inc = 0 , dec  = 0;
        }

        void LIS()
        {
                for(int i = 0; i < n; i++ )
                {
                        DP1[ i ] = w[ i ] ;
                        DP2[ i ] = w[ i ];

                        int temp1 = w[ i ] , temp2 = w[ i ];

                        for(int j = 0; j < i; j++ )
                        {
                                if( h[ j ] < h[ i ] )
                                {
                                        DP1[ i ] = max( DP1[ i ] , temp1 + DP1[ j ] );
                                }
                                if( h[ j ] > h[ i ] )
                                {
                                        DP2[ i ] = max( DP2[ i ] , temp2 + DP2[ j ] );
                                }
                        }

                        inc = max( inc , DP1[ i ] );
                        dec = max( dec , DP2[ i ] );
                }
        }

        void show()
        {
                if( inc >= dec )
                {
                        printf("Case %d. Increasing (%d). Decreasing (%d).\n" , cases++ , inc , dec );
                }
                else
                {
                        printf("Case %d. Decreasing (%d). Increasing (%d).\n" , cases++ , dec , inc );
                }
        }

};

int main()
{
        #ifndef ONLINE_JUDGE
                freopen("input.txt" , "r" , stdin );
        #endif

        int t;
        scanf("%d" , &t );
        cases = 1;

        while( t-- )
        {
                
                scanf("%d" , &n );

                MuriciaSkyline ob( n );
                // cout << ob.inc << "  " << ob.dec << endl;
                ob.LIS();
                ob.show();
                
        }
        return 0;
}
