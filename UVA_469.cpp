#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
};
vector <string> G;
int visited[102][102], counter;
int dx[] { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] { 0, 0, 1, -1, -1, 1, 1, -1 };

void Reset()
{
    counter = 0;
    for( int i=0; i<102; i++ )
    {
        for( int j = 0; j<102; j++ )
            visited[ i ][ j ] = 0;
    }
}

void DFS( node s )
{
    int ix = s.x;
    int iy = s.y;

    visited[ix-1][iy-1] = 1;

    int r = G.size();
    int c = G[0].length();
    //cout << r << "  " << c << endl;

    for(int i=0; i<8; i++ )
    {
        if( ix+dx[i]>=1 && ix+dx[i]<=r && iy+dy[i]>=1 && iy+dy[i]<=c )
        {
            s.x = ix + dx[i];
            s.y = iy + dy[i];
        }
         //cout << ix << " -> " << iy << "  = " << s.x << " -> " << s.y << endl << endl;
        if( visited[ s.x-1 ][ s.y-1 ]==0 && G[ s.x-1 ][ s.y-1 ]=='W' )
        {
           // cout << "YES" << endl << endl;
            visited[ s.x-1 ][ s.y-1 ] = 1;
            counter++;
            DFS( s );
        }
    }

}
int main()
{
//    freopen("in.txt","r",stdin);
//   freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t );
    getchar();
    int cases = 1;
    while( cases <= t )
    {
        if( cases>1 )
            printf("\n");
        //cout << "cases = " << cases  << endl;
        string s;
        G.clear();
        while( 1 )
        {
            getline( cin,s );

            if( s[0]>=47 && s[0]<=57 )
                break;
            if( s[0]=='L' || s[0]=='W' )
                    G.push_back( s );
        }

        node source;

        source.x = 0;
        source.y = 0;

        if( s.length()==3 )
        {
            source.x = s[0] - '0';
            source.y = s[2] - '0';
        }
        else if( s.length()==4 )
        {
            if( s[1]==32 )
            {
                source.x = s[0] - '0';

                source.y = s[2] - '0';
                source.y = source.y * 10 + s[3] - '0';
            }
            else
            {

                source.x = s[0] - '0';
                source.x = source.x * 10 + s[1] - '0';

                source.y = s[3] - '0';

            }
        }
        else
        {
            source.x = s[0] - '0';
            source.x = source.x * 10 + s[1] - '0';

            source.y = s[3] - '0';
            source.y = source.y * 10 + s[4] - '0';
        }
        //cout << "Source = " << source.x << "   " << source.y << endl;
        DFS( source );
        printf("%d\n", ++counter );

        while( 1 )
        {
            getline( cin,s );
            Reset();
            if( s=="" )
                break;

            source.x = 0;
            source.y = 0;

            if( s.length()==3 )
            {
                source.x = s[0] - '0';
                source.y = s[2] - '0';
            }
            else if( s.length()==4 )
            {
                if( s[1]==32 )
                {
                    source.x = s[0] - '0';

                    source.y = s[2] - '0';
                    source.y = source.y * 10 + s[3] - '0';
                }
                else
                {

                    source.x = s[0] - '0';
                    source.x = source.x * 10 + s[1] - '0';

                    source.y = s[3] - '0';

                }
            }
            else
            {
                source.x = s[0] - '0';
                source.x = source.x * 10 + s[1] - '0';

                source.y = s[3] - '0';
                source.y = source.y * 10 + s[4] - '0';
            }
            //cout << "Source = " << source.x << "   " << source.y << endl;
            DFS( source );
            printf("%d\n", ++counter );

        }
        cases++;

    }
    return 0;
}
