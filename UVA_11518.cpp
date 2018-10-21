#include<bits/stdc++.h>
using namespace std;
vector <int> G[10005];
int visited[ 10005 ], counter;
int _I(){ int x; scanf("%d" ,&x ); return x;}
void Reset()
{
        counter = 0;
        for(int i=0; i<10005; i++ )
        {
                G[i].clear();
                visited[ i ] = 0;
        }
}
void DFS(int s )
{
        if( visited[s]==0 )
        {
                visited[ s ] = 1;
                counter++;
        }
        int sz = G[ s ].size();

        for(int i=0; i<sz; i++ )
        {
                if( visited[ G[s][i] ]==0)
                {
                        DFS( G[s][i] );
                }
        }
}
int main()
{
        
        int t = _I();
        while( t-- )
        {
                Reset();
                int n = _I();
                int m = _I();
                int l = _I();

                for(int i=0; i<m; i++ )
                {
                        int a = _I();
                        int b = _I();

                        G[a].push_back( b );
                }

                for(int i=0; i<l; i++ )
                {
                        int s = _I();

                        DFS( s );
                }

                printf("%d\n" , counter );
        }
        return 0;
}
