#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d" , &t );
	while( t-- )
	{
		int n;
		scanf("%d" , &n );

		vector <int> Arr;

		int MIN = INT_MAX;

		for(int i = 0; i < n; i++ )
		{
			Arr.push_back( 0 );
			scanf("%d" , &Arr[ i ] );
		}

		sort( Arr.begin() , Arr.end() );

		for(int i = Arr[ 0 ]; i < 99; i++ )
		{
			int sum = 0;
			auto lb = lower_bound( Arr.begin() , Arr.end() , i );
			auto ub = upper_bound( Arr.begin() , Arr.end() , i );

			int li = lb - Arr.begin();
			int ui = ub - Arr.begin();

			

			int prev = i;

			for(int j = li; j >= 0; j-- ){
				sum += abs( Arr[ j ] - prev );
				prev = Arr[ j ];
			}
			sum *= 2;

			int su = 0;

			prev = i;

			for(int j = ui; j < n; j++ )
				su += abs( Arr[ j ] - prev );
			su *= 2;

			sum += su;

			MIN = min( MIN , sum );
		}

		printf("%d\n" , MIN );
	}
	return 0;
}
