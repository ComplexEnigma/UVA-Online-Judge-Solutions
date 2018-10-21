#include<bits/stdc++.h>
using namespace std;

int row, G[30][30], visited[30][30], counter ;
int dx[]{ 1 , -1 , 0 , 0 , -1 , 1, -1 , 1 };
int dy[]{ 0, 0, 1, -1, -1, -1, 1 , 1 };
struct node{
        int x;
        int y;
        node(){}
};

void Reset()
{
        counter = 0;
        for(int i=0; i<30; i++)
        {
                for(int j=0; j<30; j++ )
                {
                        G[i][j] = 0;
                        visited[ i ][ j ] = 0;
                }
        }
}

void DFS(node s)
{
        visited[s.x][s.y] = 1;

        int ix = s.x;
        int iy = s.y;

        for(int i=0; i<8; i++)
        {
                if( ix+dx[i]>=0 && ix+dx[i]<row )
                        s.x = ix + dx[i];
                if( iy+dy[i]>=0 && iy+dy[i]<row )
                        s.y = iy + dy[i];

                if( visited[s.x][s.y]==0 && G[s.x][s.y]==1 )
                {
                        DFS( s );
                }
        }
}

int main()
{
        int cases = 1;

        while( scanf("%d" , &row )==1 )
        {
                Reset();
                char str[100];
                for(int i=0; i<row; i++ )
                {
                        scanf("%s" , str );
                        for(int j = 0; j<row; j++)
                        {
                                int a;
                                G[i][j] = str[j]-'0';
                        }
                }

                node source;

                for(int i=0; i<row; i++ )
                {
                        for(int j=0; j<row; j++ )
                        {
                                if( visited[i][j]==0 && G[i][j]==1 )
                                {
                                        source.x = i; source.y = j;
                                        counter++;
                                        DFS( source );
                                }
                        }
                }

                printf("Image number %d contains %d war eagles.\n", cases++, counter );
        }
        return 0;
}
