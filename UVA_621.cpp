#include<bits/stdc++.h>
using namespace std;
int _I() { int x; scanf("%d" , &x); return x; }
int main()
{
    int t = _I();
    getchar();
    while( t-- )
    {
        string s;
        getline( cin, s );
        int len = s.length();

        if( s=="1" || s=="4" || s=="78" )
        {
            puts("+");
        }
        else if( s[ len - 1 ]=='5' && s[ len - 2 ]=='3' )
        {
            puts("-");
        }
        else if( s[ len - 1 ]=='4' && s[ 0 ]=='9' )
        {
            puts("*");
        }
        else
        {
            puts("?");
        }
    }
    return 0;
}
