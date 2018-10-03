#include<bits/stdc++.h>
using namespace std;
char G[102][102];
bool visited[ 102 ][ 102 ];
int n , m;
int dx[]{1 , 0 , -1 , 0 , -1 , 1, -1, 1};
int dy[]{0 , 1 , 0 , -1 , -1 , -1, 1, 1};
struct node{
        int x, y;
};
void Reset()
{
        for(int i=0; i<102; i++)
                for(int j=0; j<102; j++ )
                        visited[i][j] = 0;
}

bool isvalid( int x, int y )
{
        if( x>=0 && x<=n && y==-1 )
                return true;
        if( y>=0 && y<=m && x==-1 )
                return true;
        return false;
}

void DFS( node s )
{
        visited[ s.x ][ s.y ] = 1;
        int ix = s.x;
        int iy = s.y;
        for(int i=0; i<8; i++ )
        {
                if( isvalid( ix+dx[i] , -1 ) )
                {
                        s.x = ix + dx[i];
                }
                if( isvalid( -1 , iy+dy[i] ) )
                {
                        s.y = iy + dy[i];
                }

                if( !visited[ s.x ][ s.y ] && G[ s.x ][ s.y ]=='@')
                {
                        DFS( s );
                }
        }
}
int main()
{

        while( scanf("%d %d" , &n, &m)==2 && n!=0 )
        {
                Reset();
                for(int i=0 ; i<n; i++ )
                {
                        scanf("%s" , &G[i] );
                }
                int counter = 0;
                for(int i=0; i<n; i++ )
                {
                        for(int j = 0; j<m ; j++ )
                        {
                                if( !visited[i][j] && G[i][j]=='@')
                                {
                                        node source;
                                        source.x = i;
                                        source.y = j;

                                        DFS( source );

                                        counter ++;
                                }
                        }
                }

                printf("%d\n" , counter);


        }
        return 0;
}
