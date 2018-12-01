#include<bits/stdc++.h>
using namespace std;

int no_city , no_link;
char city1[ 100 ] , city2[ 100 ] ;
int b_cost;

unordered_map < string , int > City_ID;
pair < int , pair <int,int> > Arr[ 50005 ];
int parent[ 2005 ];

void Initialize( int a )
{
	for(int i = 0; i<=a+1; i++ )
	{
		parent[ i ] = i;
	}
}

inline int find_parent( int x )
{
	while( parent[ x ] != x )
	{
		parent[ x ] = parent[ parent[ x ] ];
		x = parent[ x ];
	}

	return x;
}

void Union( int x , int y )
{
	

	if( x != y )
		parent[ x ] = parent[ y ];
}

inline int Kruskal()
{
	int cost = 0;

	for(int i = 0; i<no_link; i++ )
	{
		int c = Arr[ i ].first;

		int x = Arr[ i ].second.first;
		int y = Arr[ i ].second.second;

		//cout << x << "   " << y << "  " << c << endl;

		int u = find_parent( x );
		int v = find_parent( y );

		if( u != v )
		{
			cost += c;
			Union(u , v ) ;
		} 
	}

	return cost;
}

int main()
{
	//freopen("input.txt" , "r" , stdin );
	//freopen("output.txt" , "w" , stdout );
	int t ;
	scanf("%d" , &t );

	int cases = 1;


	while( cases++ <= t )
	{
		City_ID.clear();

		if( cases > 2 )
			printf("\n");
		scanf("%d %d" , &no_city , &no_link );

		getchar();

		for(int i = 0; i < no_link ; i++ )
		{
			//cout << City_ID.size() << endl;
			scanf("%s %s %d" , city1 , city2 , &b_cost );
			// cout << city1 << "   " << city2 << endl;
			//cout << City_ID.size() << endl;
			if( !City_ID[ city1 ] )
			{
				//cout << City_ID.size() << endl;
				City_ID[ city1 ] = City_ID.size();// + 1;
				//cout << City_ID[ city1 ] << "   " << city1 << endl;
			}
			if( !City_ID[ city2 ] )
			{
				//cout << City_ID.size() << endl;
				City_ID[ city2 ] = City_ID.size();// + 1;
				//cout << City_ID[ city2 ] << "   " << city2 << endl;
			}

			//cout << City_ID[ city1 ] << "   " << City_ID[ city2 ] << endl;
			Arr[ i ] = { b_cost , { City_ID[ city1 ] , City_ID[ city2 ] } };

		}
		/*cout << "\nMAP" << endl;
		for( auto it = City_ID.begin(); it!=City_ID.end(); it++ )
		{
			cout << it->first << "   " << it->second << endl;
		}*/

		Initialize( no_city + 1 );

		sort( Arr , Arr + no_link );
		int minimumCost = Kruskal();

		printf("%d\n" , minimumCost );
	}

	return 0;
}
