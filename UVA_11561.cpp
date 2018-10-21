#include<bits/stdc++.h>
using namespace std;
int visited[55][55], counter;
int row, column;
char G[55][55];
int dx[] { 1, -1, 0, 0 };
int dy[] { 0, 0, 1, -1 };
struct node
{
    int x, y;
};
void Reset()
{
    for(int i=0; i<55; i++)
    {
        for(int j=0; j<55; j++ )
        {
            G[i][j] = 0;
            visited[i][j] = 0;
            counter = 0;
        }
    }
}
void DFS( node s )
{
    if( G[s.x][s.y]=='#' )
        return ;
    if( G[ s.x ][ s.y ]=='G' )
        counter++;


    visited[ s.x ][ s.y ] = 1;

    int ix = s.x;
    int iy = s.y;

    for(int i=0; i<4; i++ )
    {
        if( ix+dx[i]>=1 && ix+dx[i]<=row )
            s.x = ix + dx[i];
        if( iy+dy[i]>=0 && iy+dy[i]<column )
            s.y = iy + dy[i];
        if( G[ s.x ][ s.y ]=='T' )
                return;
    }

    for(int i=0; i<4; i++ )
    {
        if( ix+dx[i]>=1 && ix+dx[i]<=row )
            s.x = ix + dx[i];
        if( iy+dy[i]>=0 && iy+dy[i]<column )
            s.y = iy + dy[i];

        if( visited[ s.x ][ s.y ]==0)
        {

                DFS( s );
        }
    }
}
int main()
{


    while( scanf("%d %d", &column, &row )==2 )
    {

        Reset();
        node source;
        for(int i = 1; i<=row; i++ )
        {
            cin >> G[i];

        }
        for(int i=1; i<=row; i++ )
        {
            for(int j=0; j<column; j++ )
            {
                if( G[i][j]=='P' )
                {
                        source.x = i;
                        source.y = j;
                        DFS( source );
                        break;
                }

            }
        }


        printf("%d\n", counter );
    }
    return 0;
}
