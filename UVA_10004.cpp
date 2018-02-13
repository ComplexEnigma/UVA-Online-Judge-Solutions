#include<bits/stdc++.h>
using namespace std;

#define white -1
#define red 0
#define blue 1

map <int, vector<int> > G;
vector <int> color;

bool BFS( int source )
{
    queue <int> Q;
    Q.push( source );
    color[source]=red;

    while( Q.empty()==false )
    {
        int u=Q.front();
        Q.pop();
        int sz=G[u].size();
        for( int i=0; i<sz; i++ )
        {
            int v=G[u][i];
            if( color[v] == white )
            {
                int v=G[u][i];
                if( color[u]==red )
                    color[v]=blue;
                else
                    color[v]=red;
                Q.push(v);
            }
            if(color[u]==color[v])
                return false;

        }
    }
    return true;
}

void solve()
{
    int n;
    while( scanf( "%d",&n )==1 )
    {
        if(n==0)
            break;
        G.clear();
        color.clear();
        color.resize( n );
        fill( color.begin(),color.end(),white );

        int e;
        scanf( "%d",&e );
        int x,y;
        while( e-- )
        {
            scanf( "%d %d",&x,&y );
            G[x].push_back( y );
            G[y].push_back( x );
        }

        if( BFS( 0 ) == true)
        {
            printf( "BICOLORABLE.\n" );
        }
        else
        {
            printf( "NOT BICOLORABLE.\n" );
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
