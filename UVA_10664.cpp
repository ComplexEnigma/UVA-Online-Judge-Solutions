#include<bits/stdc++.h>
using namespace std;
int Arr[ 25 ];
int ind ;
int DP[ 25 ][ 4005 ];

int knapsack( int x )
{
	for(int i = 1; i<=ind; i++ )
	{
		for(int j = 1; j<=x; j++ )
		{
			if( j < Arr[ i ] )
			{
				DP[ i ][ j ] = DP[ i - 1 ][ j ];
			}
			else
			{
				DP[ i ][ j ] = max( DP[ i - 1][ j ] , Arr[ i ] + DP[ i-1 ][ j - Arr[ i ] ] );
			}
		}
	}
	return DP[ ind ][ x ]; 
}

int main()
{
	//freopen("input.txt" , "r" , stdin );
	int t;
	scanf("%d" , &t );
	getchar();
	while( t-- )
	{
		string s;
		getline( cin , s );

		int len = s.length();

		
		int number = 0;
		
		ind = 1;
		int totalWeigth = 0;

		for( int i = 0; i < len; i++ )
		{
			if( s[ i ] == 32 ){
				Arr[ ind++ ] = number; 
				totalWeigth += number;
				number = 0;
			}
			else
			{
				number = number * 10 + s[ i ] - '0';
			}
		}
		Arr[ ind ] = number;
		totalWeigth += number;

		/*for(int i = 1; i <= ind; i++ )
		{
			cout << Arr[ i ] << endl;
		}
		cout << endl;*/
		int ans1 = knapsack( totalWeigth / 2 );
		int ans2 = totalWeigth - ans1;

		//cout << ans1 << " " << ans2 << endl;

		if( ans1 == ans2 )
			puts("YES");
		else
			puts("NO");


	}
	return 0;
}
