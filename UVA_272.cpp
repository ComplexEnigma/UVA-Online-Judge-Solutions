#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    string s;
    int c=0;
    while(getline(cin,s))
    {
        int len=s.length();
        int i=0;
        while(i<len)
        {
            if(s[i]==34)
            {
                if(c%2==0)
                    printf("``");
                else
                    printf("''");
                c++;
                i++;
                continue;
            }
            printf("%c",s[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}
