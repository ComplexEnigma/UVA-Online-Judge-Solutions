/*
*   Created By: nomyspy
*   Date :
*   Complexity:
*/
#include<bits/stdc++.h>
using namespace std;
vector <int> Counter;
int main()
{
    int t;
    scanf("%d",&t);
    int cases = 1;
    while( cases <= t )
    {
        Counter.clear();
        Counter.resize(27);
        int r, c, m, n;
        scanf("%d %d %d %d",&r,&c,&m,&n);
        getchar();
        string s;
        int MAX = 0;
        for(int i=0;i<r;i++)
        {
            getline(cin,s);
            int len = s.length();
            for(int j=0;j<len;j++)
            {
                Counter[s[j]-64] ++;
                if(Counter[s[j]-64]>MAX)
                    MAX = Counter[s[j] - 64];
            }
        }
        int ans = 0;
        int temp = 0;
        for(int i=1;i<27;i++)
        {
            if(Counter[i]==MAX)
            {
                ans += m * Counter[i];
            }
            else
            {
                temp += Counter[i];
            }
        }
        ans += temp * n;
        printf("Case %d: %d\n",cases++, ans);
    }
    return 0;
}
