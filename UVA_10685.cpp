#include<bits/stdc++.h>
using namespace std;
unordered_map < string , int > Id;
int parent[ 5005 ], counter[ 5005 ], ans;

void Reset()
{
        Id.clear();
        for(int i = 0; i<5005; i++ )
        {
                counter[ i ] = 0;
                parent[ i ] = 0;
        }
        ans = 0;

}

int find_parent( int a )
{
        if( parent[ a ]==a )
                return a;
        return parent[ a ] = find_parent( parent[ a ] );

}

void Union( int a , int b )
{
        int u = find_parent( a );
//        cout << "REP   a   " << u << endl;
        int v = find_parent( b );
//        cout << "REP   b   " << v << endl;

        if( u!=v )
        {
//                cout << "YES" << endl;
//                cout << "PREV    " << parent[v] << endl;
                parent[ v ] = u;
//                cout << "New    " << parent[v] << endl << endl;;
        }
}

void print(int n)
{
        for(int i = 1; i<=n; i++ )
        {
                cout << "parent of i " << i << "  is    [     " << parent[ i ]  << "    ]"<< endl << endl;
        }
        cout << endl;
}

int main()
{
//        freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
        int n , m;
        while( scanf("%d %d" , &n, &m)==2 && n!=0 )
        {
                Reset();
                for(int i = 0; i<n; i++ )
                {
                        string a;
                        cin >> a;
                        Id[ a ] = i + 1;
                        parent[ i+1 ] = i + 1;
                }

                for(int i = 0; i<m; i++ )
                {
                        string a, b;
                        cin >> a >> b;
//                        getchar();
//                        cout <<"Name = "<< a << "  -  " << b  << endl;
//                        cout << "Id = " << Id[ a ] << "   -  " << Id[ b ] << endl << endl;
                        int u = Id[ a ];
                        int v = Id[ b ];

                        Union( u ,v );

//                        print( n );
                }

                for(int i = 1; i<=n; i++ )
                {
                        int a = find_parent( i );
                        if( a != i )
                        {
                                parent[ i ] = a;
                        }
                }

//                print( n);
                for(int i = 1; i<=n; i++ )
                {
                        counter[ parent[i] ] ++;
                        ans = max( counter[ parent[i] ] , ans  );
                }

                printf("%d\n" , ans );
                //cout << endl << endl;
        }
        return 0;
}
