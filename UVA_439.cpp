#include<bits/stdc++.h>
using namespace std;
char s[4] , d[4];
int level[9][9];
int dx[]{2 , 1 , -1, -2, -2, -1, 1, 2 };
int dy[]{-1 , -2, -2, -1, 1, 2, 2, 1 };
struct node{
        int x, y;
};
void Reset()
{
        for(int i=0; i<9; i++ )
                for(int j=0; j<9; j++)
                        level[i][j] = -1;
}
bool isvalid(int x )
{
        if( x>=1 && x<=8 )
                return true;
        return false;
}
void BFS( node s, node d )
{
        queue <node> Q;
        Q.push( s );
        level[ s.x ][ s.y ] = 0;
        while( !Q.empty() )
        {
                node st = Q.front();
                Q.pop();

                int ix = st.x;
                int iy = st.y;

                for(int i=0; i<8; i++ )
                {
                        if( isvalid( ix+dx[i] ) && isvalid( iy+dy[i] ) )
                        {
                              st.x = ix + dx[i];
                              st.y = iy + dy[i];
                        }

                        //cout << st.x <<"  " << st.y << " --- " <<ix << "   -> " << iy << endl;
                        if( level[ st.x ][ st.y ]==-1 ){
                                level[ st.x ][ st.y ] = level[ ix ][ iy ] + 1;
                                Q.push( st );
                        }
                }
        }
}
int main()
{
        while( scanf("%s %s",&s,&d)==2 )
        {
                Reset();

                node source, destination;
                source.x = s[0]%96;
                source.y = s[1]-'0';

                destination.x = d[0]%96;
                destination.y = d[1]-'0';

                //cout << source.x << "   " << source.y << "  " << destination.x << "   " << destination.y << endl;

                BFS( source, destination );

                /*for(int i=1; i<=8; i++)
                {
                        for(int j=1; j<=8; j++)
                        {
                                cout << level[i][j] << "   ";
                        }
                        cout << endl;
                }*/

                printf("To get from %s to %s takes %d knight moves.\n" , s, d, level[ destination.x ][ destination.y ] );
        }
        return 0;
}
