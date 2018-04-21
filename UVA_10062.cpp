#include<bits/stdc++.h>
using namespace std;
string s;
map <int,int> Counter;

int main()
{
    int cases = 0;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while( getline(cin,s) )
    {
        Counter.clear();
        int len = s.length();
        if( cases > 0 )
            printf("\n");
        for( int i=0; i<len; i++ )
        {
            Counter [ s[i] ] ++;
        }
        vector <int> v1, v2;
        for( auto it=Counter.begin();it!=Counter.end();it++)
        {
            v1.push_back( it->first );
            v2.push_back( it->second );
            //cout << it->first << " " << it->second << "\n";
        }
        int sz = v1.size();
        for( int i=0; i<sz; i++ )
        {
            for( int j=i+1; j<sz; j++ )
            {
                if( v2[j] < v2[i] )
                {
                    swap( v1[j] , v1[i] );
                    swap( v2[j], v2[i]);
                }
                else if( v2[j] == v2[i] )
                {
                    if( v1[j] > v2[i] ){
                        swap( v1[j] , v1[i]);
                        swap( v2[j], v2[i]);
                    }
                }
            }
        }
        for(int i=0;i<sz;i++)
        {
            printf("%d %d\n",v1[i],v2[i]);
        }
        cases ++;
    }
    return 0;
}
