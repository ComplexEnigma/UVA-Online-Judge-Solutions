#include<bits/stdc++.h>
using namespace std;


int W[ 1005 ] , P[ 1005 ];
int n;
int DP[ 1005 ][ 3005 ];

int knapsack( int x )
{
	for(int i = 1; i <=n ; i++ )
	{
		for(int j = 1; j <= x; j++ )
		{
			if( j < W[ i ] )
			{
				DP[ i ][ j ] = DP[ i -1 ][ j ];
			}
			else
			{
				DP[ i ][ j ] = max( DP[ i-1 ][ j ] , P[ i ] + DP[ i-1 ][ j - W[ i ] ] );
			}
		}
	}

	return DP[ n ][ x ];
}

int main()
{
	//freopen("input.txt" , "r" , stdin);
	int t;
	scanf("%d" , &t );

	while( t-- )
	{

		scanf("%d" , &n );

		for(int i = 1; i <= n ; i++ )
		{
			int p , w;
			scanf("%d %d" , &p , &w );

			W[ i ] = w;
			P[ i ] = p;
		}

		//sort( Arr , Arr + n );

		int g;
		scanf("%d" , &g );
		int profit = 0;

		while( g-- )
		{
			int x;
			scanf("%d" , &x );
			profit += knapsack( x );
		}

		printf("%d\n" , profit );
	}

	return 0;
}
