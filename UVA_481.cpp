#include<bits/stdc++.h>
using namespace std;
int Arr[ 100005 ] , Inf[ 100005 ] , Ans[ 100005 ] , L[ 100005 ];
int MAX = INT_MAX , m;

int BS( int a )
{
        int l = 0 , h = m+1;
        while( l<=h )
        {
                int mid = ( l + h )/2;

                if( Inf[ mid ] >= a )
                {
                        h = mid - 1;
                }
                else
                {
                        l = mid + 1;
                }
        }
        return l;
}

void LIS( )
{
        int ans = 0;
        for(int i = 0; i<m; i++ )
        {
                //cout << "YES" << endl;
                int lb = BS( Arr[ i ] );
                //cout <<"LB of " << Arr[ i ] << "   " << lb << endl;
                Inf[ lb ] = Arr[ i ];
                Ans[ i ] = lb;
                ans = max( Ans[ i ] , ans );
        }



        printf("%d\n-\n" , ans );

        int j = 0;

        for(int i = m; i>=0; i-- )
        {
                if( Ans[ i ] == ans )
                {
                       //printf("%d\n" , Arr[ i ] );
                       L[ j ++ ] = Arr[ i ];
                       ans--;
                }
        }
        j--;
        for(  ; j>=0 ; j-- )
        {
                printf("%d\n" , L[ j ] );
        }
}
int main()
{

//        freopen("input.txt","r",stdin);
        int n;
        while( scanf("%d" , &n )==1 )
        {
               Arr[ m++ ] = n;
        }

        Inf[ 0 ] = INT_MIN;
        Ans[ 0 ] = 0;
        for(int i = 1; i<=m; i++ )
        {
                Inf[ i ] = MAX;

        }


        LIS( );
        return 0;
}
