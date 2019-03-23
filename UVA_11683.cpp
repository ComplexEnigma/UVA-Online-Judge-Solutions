#include<bits/stdc++.h>
using namespace std;
int Arr[ 10005 ];
int main()
{
	int h , w;
	while( scanf("%d %d" , &h , &w ) == 2 && h != 0 && w != 0 )
	{

		for(int i = 0; i < w; i++ )
			scanf("%d" , &Arr[  i ] );

		int carry = h - Arr[ 0 ];

		int counter = h - Arr[ 0 ];

		for(int i = 1; i < w; i++ )
		{
			if( h - Arr[ i ] > carry )
				counter +=  h - Arr[ i ] - carry;

			carry = h - Arr[ i ];

			//cout << counter << " at " << i << " carry = " << carry<< endl;

		}

		printf("%d\n" , counter );


	}
	return 0;
}
