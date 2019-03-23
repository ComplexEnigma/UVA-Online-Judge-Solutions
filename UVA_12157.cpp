#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d" , &t );

	int cases = 1;
	while( t-- )
	{
		int n;
		scanf("%d" , &n );

		int sum = 0;
		int arr[ 25  ];
		int a = 0 , b = 0;

		for(int i = 0; i < n; i++ )
		{
			scanf("%d" , &arr[ i ] );
			a += ( arr[ i ] / 30 + 1 ) * 10;
			b += ( arr[ i ] / 60 + 1 ) * 15;
			
		}



		printf("Case %d: " , cases++ );

		if( a < b )
			printf("Mile %d\n" , a );
		else if( a > b )
			printf("Juice %d\n" , b );
		else
			printf("Mile Juice %d\n" , a );
	}
	return 0;
}
