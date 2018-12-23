#include<bits/stdc++.h>
using namespace std;
int _I(){ int x; scanf("%d",&x); return x; }
struct node{
    int l , h;
};
int d , _index;

map < int , string > DB;
node  Arr[ 10005 ];

int _search( int a )
{
    int counter = 0;
    for(int i = 1; i <= d; i++ ){

        if( Arr[ i ].l <= a && Arr[ i ].h >= a )
        {
            _index = i;
            counter++;
        }

        if( counter >= 2 )
            break;

    }
    return counter;
}


int main()
{
    int t = _I();
    int cases = 1;

    while( cases++ <= t )
    {
        if( cases > 2 )
            printf("\n");
        DB.clear();
        d = _I();
        getchar();

        for( int i = 1; i <= d; i++ )
        {
            string s ;
            int l , h;
            cin >> s >> l >> h;
            DB[ i ] = s;
            Arr[ i ] = { l , h };
        }

//        for( int i = 1; i <= d; i++ )
//            cout <<DB[ i ] << "   " << Arr[ i ].l << "  " << Arr[ i ].h << endl;

        int q = _I();

        while( q-- )
        {
            int p = _I();
            _index = -1;
            int counter = _search( p );

            if( counter > 1 || _index==-1 )
            {
                puts("UNDETERMINED");
            }
            else
            {
                cout << DB[ _index ] << "\n";
            }
        }
    }
    return 0;
}
