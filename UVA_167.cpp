/*
*	author: symon hasan
*	date: 
*
*/

#include<bits/stdc++.h>
using namespace std;

int _I(){ int x; scanf("%d" , &x ); return x; }

int Arr[ 10 ][ 10 ] , col[ 10 ] , dig1[ 20 ] , dig2[ 20 ];
int sum , M;

void backtrack( int at )
{
	if( at > 8 ){
		M = max( M , sum );
		return;
	}

	for(int i = 1; i<=8; i++ )
	{
		if( !col[ i ] && !dig1[ i + at ] && !dig2[ 8 + i - at ] )
		{
			col[ i ] = dig1[ i + at ] = dig2[ 8 + i - at ] = 1;
			sum += Arr[ at ][ i ];
			

			backtrack( at + 1 );

			col[ i ] = dig1[ i + at ] = dig2[ 8 + i - at ] = 0;
			sum -= Arr[ at ][ i ];
		}
	}
}

void HypNos()
{
	int t;
	scanf("%d" , &t );
	while( t-- )
	{

		memset( col , 0 , sizeof( col ) );
		memset( dig1 , 0 , sizeof( dig1 ) );
		memset( dig2 , 0 , sizeof( dig2 ) );

		for(int i = 1; i <= 8; i++ )
			for(int j = 1; j <= 8; j++ )
				Arr[ i ][ j ] = _I();

		M = sum = 0;

		backtrack( 1 );

		cout<<setw(5)<<setiosflags(ios::right)<<M<<"\n";
	}
}

int main()
{
	HypNos();
	return 0;
}
