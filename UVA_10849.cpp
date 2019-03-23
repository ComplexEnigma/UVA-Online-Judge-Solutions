#include<bits/stdc++.h>
using namespace std;

long long r1 , c1, r2 , c2;

void do_calc()
{
	if( r1==r2 && c1==c2 )
			puts("0");
	else if( r1==c2 && r2==c1 )
		puts("1");
	else if( abs( r1 - c1 ) == abs( r2 - c2 ) )
	{
		
		if( ( r1 - c1 ) >= 0 && ( r2 - c2 ) >= 0 )
			puts("1");
		else if( ( r1 - c1 ) < 0 && ( r2 - c2 ) < 0 )
			puts("1");
		else
			puts("2");
	}
	else if( ( r1+c1 ) == ( r2 + c2 ) )
		puts("1");
	else
		puts("2");
}

int main()
{
	int t;
	scanf("%d" , &t );
	while( t-- )
	{
		int n , q;
		scanf(" %d %d" , &q , &n );
		while( q-- )
		{
			
			scanf("%lld %lld %lld %lld" , &r1 , &c1 , &r2 , &c2 );

			if( abs( r1 - c1 ) % 2 == 0 && abs( r2 - c2 ) % 2 == 0 )
			{
				do_calc();
			}
			else if( abs( r1 - c1 ) % 2 == 1 && abs( r2 - c2 ) % 2 == 1 )
			{
				do_calc();
			}
			else
				puts("no move");
		}
	}
	return 0;
}
