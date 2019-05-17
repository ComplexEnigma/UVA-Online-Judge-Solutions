// Longest Palindrom
#include<bits/stdc++.h>
using namespace std;

int MX;
string s;
int DP[ 1005 ][ 1005 ];

int longest( int lpos , int rpos, string temp )
{
        if( lpos == rpos )
                return 1;
        if( lpos + 1 == rpos )
        {
                if( temp[ lpos ] == temp[ rpos ] )
                        return 2;
                else
                {
                        return 1;
                }
                
        }
        
        if( DP[ lpos ][ rpos ] != -1 )
                return DP[ lpos ][ rpos ];

        if( temp[ lpos ] == temp[ rpos ] )
                return DP[ lpos ][ rpos ]= 2 + longest( lpos+1, rpos-1 , temp );
        else
        {
               return DP[ lpos ][ rpos ] = max( longest( lpos+1 , rpos , temp ),  longest( lpos , rpos-1, temp ) );
        }        

}

void solve()
{
        int t;
        scanf("%d" , &t ); getchar();

        while( t-- )
        {

                getline( cin , s );

                string temp = s;
                reverse( temp.begin() , temp.end() );

                if( temp == s )
                {
                        printf("%d\n" , temp.size() );
                        continue;
                }

                int len = s.length();

                MX = 0;

                memset( DP, -1, sizeof( DP ) );

               MX = longest( 0 , len - 1, s );

               printf("%d\n" , MX );
        }
}

int main()
{
        #ifndef ONLINE_JUDGE
                freopen("input.txt" , "r" , stdin );
        #endif
        solve();
        return 0;
}
