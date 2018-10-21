#include<bits/stdc++.h>
using namespace std;

struct node{
        int x, y;
};

vector <int> Tree[1006];
vector <node> Branch[ 1006 ];
int visited[1006];


//#define filein
int _I(){ int x; scanf("%d",&x); return x;}

void DFS(int s )
{
        visited[ s ] = 1;

        int sz = Tree[s].size();

        for(int i = 0; i<sz; i++ )
        {
                if( visited[ Tree[s][i] ] == 0 )
                {
                        DFS( Tree[s][i] );
                }
        }
}

void Reset()
{
        for(int i=0; i<1006; i++ )
        {
                Tree[i].clear();
                Branch[i].clear();
                visited[i] = 0;
        }
}

int main()
{
        #ifdef filein
                freopen("input.txt","r",stdin);
                freopen("output.txt","w",stdout);
        #endif // filein

        int t = _I();

        while(t--)
        {
                Reset();
                int n , m , k, d;
                n = _I(); m = _I(); k = _I(); d = _I();

                k = k * k; d = d * d;



                for( int i = 0; i < m ; i++ )
                {
                        node s;
                        s.x = _I();
                        s.y = _I();

                        Branch[1005].push_back( s );

                }

                for(int i = 1 ; i <= n; i++ )
                {
                        int b = _I();

                        for(int j = 0; j < b; j++ )
                        {
                                int x = _I();
                                int y = _I();

                                node s;
                                s.x = x; s.y = y;
                                Branch[i].push_back( s );

                                for(int l = 0; l<m; l++ )
                                {
                                        int x2 = Branch[1005][ l ].x;
                                        int y2 = Branch[1005][ l ].y;

                                        x2 = ( x2 - x ) * ( x2 - x );
                                        y2 = ( y2 - y ) * ( y2 - y );

                                        int dis =  x2 + y2 ;

                                        if( dis<=d )
                                        {
                                                Tree[1005].push_back( i );
                                                Tree[ i ].push_back( 1005 );

                                        }
                                }

                                for(int l=1; l<i; l++ )
                                {

                                        int sz = Branch[ l ].size();

                                        for( int r = 0; r<sz; r++ )
                                        {
                                                //cout << "YES" << endl;
                                                int x2 = Branch[l][r].x;
                                                int y2 = Branch[l][r].y;

                                                x2 = ( x2 - x ) * ( x2 - x );
                                                y2 = ( y2 - y ) * ( y2 - y );

                                                int dis =  x2 + y2 ;

                                                //cout << dis << endl;

                                                if( dis <= k )
                                                {
                                                        Tree[ i ].push_back( l );
                                                        Tree[ l ].push_back( i );
                                                        break;
                                                }
                                        }
                                }

                        }

                }

                DFS( 1 );

                if( visited[1005]==1 )
                        printf("Tree can be saved :)\n");
                else
                        printf("Tree can't be saved :(\n");
//
//
//
//                for(int i=1; i<6; i++ )
//                {
//                        for(int j=0; j<Tree[i].size(); j++ )
//                        {
//                                cout << Tree[i][j] << "   ";
//                        }
//
//                        cout << endl;
//                }



        }
        return 0;
}
