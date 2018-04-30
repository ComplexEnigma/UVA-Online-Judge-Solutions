#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while( getline(cin,s) )
    {
        if( s=="#" )
            break;
        bool val = next_permutation(s.begin(),s.end());
        if(val)
            cout << s << endl;
        else
            cout << "No Successor\n";
    }
    return 0;
}
