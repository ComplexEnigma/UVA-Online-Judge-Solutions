#include<bits/stdc++.h>
using namespace std;

int Arr[ 105 ] , no_track , capacity;
vector<int>  solution;
int best ;


int findsum( vector <int> v, int total , int idx )
{
	if( total > best )
	{
		best = total;
		solution = v;
	}
	else if( total==best && v.size() > solution.size() )
	{
		best = total;
		solution = v;
	}

	if( idx  == no_track )
		return total;

	int c1 = 0, c2 = 0;

	//cout << "BEST " << best << endl;

	int flag = 0;

	if( total + Arr[ idx ] <= capacity )
	{
		
		v.push_back( Arr[ idx ] );
		flag = 1;
/*
		for( auto it:v )
			cout << it << "   " ;
		cout << endl;
*/
		c1 = findsum( v , total + Arr[ idx ] , idx + 1 );
	}

	if( flag )
	{
		v.pop_back();
		flag = 0;
	}

	c2 = findsum( v , total , idx+1 );

	return max( c1 , c2 );
}

int main()
{
	
	while( scanf("%d" , &capacity)==1 )
	{

		solution.clear(); best = -1;

		scanf("%d" , &no_track );
		for(int i = 0; i < no_track; i++ )
		{
			scanf("%d" , &Arr[ i ] );
		}

		vector <int> v;

		int sum = findsum( v, 0 , 0 );

		//cout << sum << endl;

		for( auto it=solution.begin(); it!=solution.end(); it++ )
		{
			cout << *it << " ";
		}
		cout << "sum:" << sum << "\n";

	}
	return 0;
}
