#include<bits/stdc++.h>
using namespace std;
#define filei
int Arr[ 100005 ];
int main()
{
	#ifdef filein
		freopen("input.txt" , "r" , stdin );
	#endif
	//	freopen("output.txt" , "w" , stdout );

	int t;
	scanf("%d" , &t );

	while( t-- )
	{
		int n;
		scanf("%d" , &n );

		int MX = INT_MIN;
		int RES = INT_MIN;
		

		scanf("%d" , &Arr[ 0 ] );
		MX = Arr[ 0 ];
		for(int i = 1; i < n; i++ )
		{
			scanf("%d" , &Arr[ i ] );

			RES = max( RES , MX - Arr[ i ] );
			MX = max( MX , Arr[ i ] );
			
		}

		
			printf("%d\n" , RES );
	}
	return 0;
}
