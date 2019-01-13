#include<bits/stdc++.h>
using namespace std;
int _I() { int x; scanf("%d" , &x); return x; }
int counter = 0;

void dig( int n )
{
    ++counter;
    if( n==1 )
        return;
    int digit = 0;
    while( n!=0 )
    {
        digit++;
        n/=10;
    }
    dig( digit );
}
int main()
{
    //freopen("out.txt" ,"w" , stdout );
    string s;
    while( getline( cin , s ) )
    {
        if( s=="END" )
            break;
        int len = s.length();
        counter = 1;
        dig( len  );
        if( s=="1" )
            counter = 1;
        printf("%d\n" , counter );
    }
    return 0;
}

