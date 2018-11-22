#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n , m , Acost;

pair <int,pair<int , int > > Arr[ 100005 ];
int parent[ 10005 ];

void Initialize( int n )
{
	for(int i = 0; i<n+5; i++ )
		parent[ i ] = i;
}

int find_parent( int a )
{
	while( parent[ a ] != a )
	{
		parent[ a ] = parent[ parent[ a ] ];
		a = parent[ a ];
	}

	return a;
}

void Union( int x , int y )
{
	int u = find_parent( x );
	int v = find_parent( y );

	if( u != v )
	{
		parent[ u ] = parent[ v ];
	}
}

ll kruskal()
{
	ll cost = 0;
	for(int i = 0; i<m; i++ )
	{
		int x = Arr[ i ].second.first;
		int y = Arr[ i ].second.second;
		int c = Arr[ i ].first;

		if( find_parent( x ) != find_parent( y ) && c < Acost )
		{
			cost += c;
			Union( x , y );
		}
	}

	return cost;
}

int main()
{
	int t;
	scanf("%d" , &t );

	int cases = 0;

	while( cases++ < t )
	{
		
		scanf("%d %d %d" , &n , &m, &Acost );

		for( int i = 0; i < m; i++ )
		{
			int u , v ,cost;
			scanf("%d %d %d" , &u , &v, &cost );
			Arr[ i ] = { cost , { u , v } };
		}

		Initialize( n );

		sort( Arr , Arr + m );

		ll cost = kruskal( );

		ll total_cost = cost ;
		int airport = 0;

		for(int i = 1; i<=n; i++ )
		{
			if( parent[ i ] == i )
			{
				airport ++;
			}
		}

		total_cost += (ll)airport * (ll)Acost;

		printf("Case #%d: %lld %d\n" , cases , total_cost , airport );
	}

	return 0;
}
