#include<bits/stdc++.h>
using namespace std;
int visited[30] , hn;
vector <int> G[30];
set <int> parent;

void Reset()
{
        for(int i=0; i<30; i++ )
        {
                G[i].clear();

        }

        parent.clear();
}

void BFS( int source )
{
        visited[ source ] = source;
        parent.insert( source );
        queue <int> Q;
        Q.push( source );

        while( !Q.empty() )
        {
                int u = Q.front();
                Q.pop();

                int sz = G[u].size();

                for(int i=0; i<sz; i++ )
                {
                        int v = G[u][i];
                        if( visited[ v ] == 0 )
                        {

                                Q.push( v );
                                visited[ v ] = visited[ u ];
                                parent.insert( visited[v] );
                        }
                }
        }
}
int main()
{
        freopen("input.txt","r",stdin);
        freopen("outp.txt","w",stdout);
        int t;
        string s;
        cin >> t;
        getchar();
        getchar();
        int flag = 0;
        int cases = 1;
        while( cases<=t )
        {
                if( flag )
                {
                        printf("\n");
                }
                while( 1 )
                {
                       getline( cin,s );
                        if( s.length()==1 )
                        {
                                hn = s[0]%64;
                                continue;
                        }
                       if( s.length()==2 )
                       {
                               G[ s[0]%64 ].push_back( s[1]%64 );
                               G[ s[1]%64 ].push_back( s[0]%64 );
                       }

                       if( s=="" )
                        break;

                }

                for(int i=0; i<30; i++ )
                        visited[ i ] = 0;
                for(int i=1; i<=hn; i++ )
                {
                        if( visited[i]==0 )
                                BFS( i );
                }


                int sz = parent.size();
                printf("%d\n" , sz );

                Reset();
                flag = 1;
                cases ++;
        }
        return 0;
}
