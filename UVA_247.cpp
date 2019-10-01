/*
        author: symon hasan
        date: 01 / 10 / 2019
*/
#include<bits/stdc++.h>
using namespace std;
#define _i64 long long
#define _I( x ) scanf("%d" , &x )
#define _LL( x ) scanf("%lld" , &x )
#define _LF( x ) scanf("%lf" , &x )
#define CLR( x ) x.clear()
#define SZ( x ) x.size()
#define PB push_back
#define F first
#define S second
#define B begin
#define E end
#define MP make_pair
#define Sort( x ) sort( x.begin() , x.end() )
#define pfcase( x ) printf("Case %d: " , x)
#define rep( i , n ) for( int i = 0; i < n; i++ )
#define REP( i , k , n ) for( int i = k; i < n; i++ )
#define RREP( i , k , n ) for( int i = k; i >= n ; i-- )
#define _debug( x ) cout << #x << " = " << x <<"\n"
#define AND( a , b ) ( ( a ) & ( b ) )
#define OR( a , b ) ( ( a ) | ( b ) )
#define EXOR( a , b ) ( ( a ) ^ ( b ) )
#define WHITE 0
#define GRAY 1
#define BLACK 2
typedef pair<int,int> pii;
typedef vector< int > vint;
typedef vector< pii > vpii;
typedef vector< string > vstr;
typedef set< int > sint;
typedef map< int , vint > mapintvint;
typedef map< int , int > mapintint;
typedef map< string , int > mapstrint;
typedef map< int , vstr > mapintvstr;
typedef map< int , sint > mapintsint;
struct node{
        int x , y;
        node(){}
        node( int a , int b )
        {
                x = a;
                y = b;
        }
        bool operator < ( const node& R)
        {
                if( x > R.x )
                return true;
                if( x == R.x && y < R.y )
                return true;
                return false;
        }
};
int n , m;
map < string , int > M;
map < int , string > N;
int mp_sz;
vector < int > G[ 30 ] , GR[ 30 ];
vector < bool > visited;
vector < int > order , componant;

void _Reset()
{
        CLR( M );
        CLR( visited ) , CLR( order );
        CLR( N );
        mp_sz = 1;
        for( int i = 0; i < 30; i++ )
                CLR( G[ i ] ) , CLR( GR[ i ] );
}

void _DFS( int src )
{
        visited[ src ] = true;

        for( size_t i = 0; i < G[ src ].size(); i++ )
                if( !visited[ G[ src ][ i ] ] ) _DFS( G[ src ][ i ] );
        
        order.PB( src );
}

void _DFS2( int src )
{
        visited[ src ] = true;
        componant.PB( src );
        for( size_t i = 0; i < GR[ src ].size(); i++ )
                if( !visited[ GR[ src ][ i ] ] ) _DFS2( GR[ src ][ i ] );
}

void _NomySnasaH()
{
        int cases = 1;
        while( 1 )
        {
                cin >> n >> m;
                getchar();
                if( !n && !m ) break;
                if( cases > 1 )
                        cout << "\n";
                _Reset();
                int i;
                
                rep( i , m )
                {
                        string s1 , s2;
                        cin >> s1 >> s2;

                        if( !M.count( s1 ) ){
                                M[ s1 ] = mp_sz ++;
                        }
                        if( !M.count( s2 ) )
                                M[ s2 ] = mp_sz ++;


                        int u = M[ s1 ] , v = M[ s2 ];

                        N[ u ] = s1 , N[ v ] = s2;

                        G[ u ].push_back( v );
                        GR[ v ].push_back( u );
                        // _debug( s1 ) , _debug( s2 );
                        // _debug( u ) , _debug( v );
                }

                visited.assign( n + 1 , false );

                REP( i , 1 , n + 1 )
                        if( !visited[ i ] ) _DFS( i );

                visited.assign( n + 1, false );
                // _debug( order.size() );
                cout << "Calling circles for data set "<< cases++ <<":\n";
                rep( i , n )
                {
                        int v = order[ n - 1 - i ];

                        if( !visited[ v ] )
                        {
                                _DFS2( v );
                                cout << N[ componant[ 0 ] ];
                                for( size_t j = 1; j < componant.size(); j++ )
                                        cout << ", " << N[ componant[ j ] ];
                                cout << "\n";
                                componant.clear();
                        }          
                }

        }
}

int main()
{
        _NomySnasaH();

        return 0;
}
