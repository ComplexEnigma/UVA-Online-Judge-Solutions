#include<bits/stdc++.h>
using namespace std;
int row, column;
bool G[1002][1002];
int level[1002][1002];

typedef struct node{

        int x;
        int y;
};

int dx[]{ 1 , -1 , 0 , 0 };
int dy[]{ 0 , 0 , 1 , -1 };

void Reset()
{
        for(int i=0; i<1002; i++)
                for(int j = 0; j<1002; j++)
        {
                G[ i ][ j ] = 1;
                level[ i ][ j ] = -1;
        }
}

void BFS( node s , node d )
{
        queue <node> Q;
        Q.push( s );
        level[ s.x ][ s.y ] = 0;

        while( !Q.empty() )
        {
                node temp = Q.front();
                Q.pop();

                int nx = temp.x;
                int ny = temp.y;

                for(int i=0; i<4; i++ )
                {
                       if( nx+dx[i]>=0 && nx+dx[i]<=row )
                                temp.x = nx + dx[i];
                       if( ny+dy[i]>=0 && ny+dy[i]<=column )
                                temp.y = ny + dy[i];

                       if( level[ temp.x ][ temp.y ]==-1 && G[ temp.x ][ temp.y ]==1 )
                       {
                               level[ temp.x ][ temp.y ] = level[ nx ][ ny ] + 1;
                               Q.push( temp );
                               if( temp.x == d.x && temp.y == d.y )
                               {
                                       printf("%d\n" , level[ d.x ][ d.y ]);
                                       return;
                               }
                       }
                }
        }
}

int main()
{
        while( scanf("%d %d",&row , &column)==2 && row!=0 && column!=0)
        {
                Reset();

                int rows_c_bomb;
                scanf("%d" ,&rows_c_bomb );

                for(int i=0; i<rows_c_bomb ; i++ )
                {
                        int row_no , no_bomb;
                        scanf("%d %d" , &row_no , &no_bomb );
                        for(int j=0; j < no_bomb; j++)
                        {
                                int col_no ;
                                scanf("%d",&col_no);
                                G[ row_no ][ col_no ] = 0;
                        }
                }

                node source , destination;
                scanf("%d %d" , &source.x , &source.y );
                scanf("%d %d" , &destination.x , &destination.y );

                BFS( source, destination );

        }
        return 0;
}
