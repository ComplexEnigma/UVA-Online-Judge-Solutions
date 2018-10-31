#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector <int> G[ 105 ], learn;
int level[ 105 ] , counter, ans, n;
int _I(){ int x; scanf("%d" , &x); return x; }

void Reset()
{
      for(int i = 0; i<105; i++ )
      {
            G[ i ].clear();
            level[ i ] = 0;
      }
      counter = 0;
      ans = 0;
      learn.clear();
}

void BFS( int s )
{
      queue <int> Q;
      Q.push( s );


      while( !Q.empty() )
      {
            int u = Q.front();
            Q.pop();

            level[ u ] = 1;

            int sz = G[ u ].size();

            int max_learn = 0;
            int vertex = -1;

            for(int i = 0; i<sz; i++ )
            {
                  if( level[ G[u][i] ]==0 )
                  {
                        if( learn[ G[u][i] ] > max_learn )
                        {
                              max_learn = learn[ G[u][i] ];
                              vertex = G[ u ][ i ];
                        }
                  }
            }
            //cout << vertex << endl;
            if( vertex == -1 ){
                  ans = u;
                  return;
            }
            Q.push( vertex );
            counter += learn[ vertex ];
            //cout << counter << endl;
      }

}
int main()
{
      int t = _I();
      int cases  = 1 , l,h,w;
      while( cases<= t )
      {
            Reset();
             n = _I();
            int m = _I();

            for(int i = 0; i<n; i++ )
            {
                  int a = _I();
                  learn.push_back( a );
            }

            for(int i = 0 ; i<m ; i++ )
            {
                  int u = _I();
                  int v = _I();

                  G[ u ].push_back( v );
            }

            BFS( 0 );

            printf("Case %d: %d %d\n" , cases++, counter , ans );
      }
      return 0;
}
