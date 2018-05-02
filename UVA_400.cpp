/*
*   Created By : nomyspy
*   Date :
*   Complexity:
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    vector <string> v;
    while(scanf("%d",&n)==1)
    {
        getchar();
        v.clear();
        string s;
        printf("--------------------");
        printf("--------------------");
        printf("--------------------\n");
        int maxlen = 0;
        for(int i=0;i<n;i++)
        {
            getline(cin,s);
            v.push_back(s);
            int len = s.length();
            if(len>maxlen)
                maxlen = len;
        }

        int column;
        if( maxlen==29 || maxlen==30 )
            column = 2;
        else
            column = 60 / (double)(maxlen+2);
        column = max(1,column);

        int row = ceil(n/(double)column);
        //cout << "r = " << row << " c = " << column << endl;
        maxlen += 2;

        sort(v.begin(),v.end());
        for(int i=0;i<row;i++)
        {
            cout << v[i] ;
            int j = i+row;
            int c = 1;
            int len = maxlen - v[i].length();
            if(j>=n)
                len -= 2;
            for(int k=0;k<len;k++)
                printf(" ");
            while( j<n && c<column)
            {
                //cout << "count = " << c << endl;
                cout << v[j];
                len = maxlen - v[j].length();
                if(j+row>=n)
                    len -= 2;
                for(int k=0;k<len;k++)
                    printf(" ");
                j+=row;
                c++;
            }

            printf("\n");
        }
    }
    return 0;
}
