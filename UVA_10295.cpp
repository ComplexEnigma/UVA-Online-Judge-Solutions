#include<bits/stdc++.h>
using namespace std;

map <string,int> M;

int main()
{
    //freopen("input.txt","r",stdin);
    int n, m;
    while( scanf("%d %d",&n,&m) == 2 )
    {
        M.clear();
        for(int i=0; i<n; i++)
        {
            string s;
            int a;
            cin>> s >> a;
            M[s] = a;
        }
        for(int i=0; i<m; i++)
        {
            string s;
            long long counter = 0;
            while( getline(cin,s) )
            {
                if( s==".")
                    break;
                stringstream ss(s);
                string temp;
                while(getline( ss, temp, ' '))
                {
                    counter += M[temp];
                }

            }
            printf("%lld\n",counter);
        }
    }
}
