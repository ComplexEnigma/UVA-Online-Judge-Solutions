/***
         _______________________________

             MD. SYMON HASAN SHOHAN
             UNIVERSITY OF ASIA PACIFIC
             isymonhs@gmail.com
         _______________________________
*/
#include<bits/stdc++.h>
using namespace std;

void solve()
{
    char s[16];
    int i=1;
    while(1)
    {
        gets(s);
        if(strlen(s)==1 && s[0]=='#')
            break;
        printf("Case %d: ",i);
        i++;
        if(strcmp(s,"HELLO")==0)
        {
            printf("ENGLISH\n");
        }
        else if(strcmp(s,"HOLA")==0)
        {
            printf("SPANISH\n");
        }
        else if(strcmp(s,"HALLO")==0)
        {
            printf("GERMAN\n");
        }
        else if(strcmp(s,"BONJOUR")==0)
        {
            printf("FRENCH\n");
        }
        else if(strcmp(s,"CIAO")==0)
        {
            printf("ITALIAN\n");
        }
        else if(strcmp(s,"ZDRAVSTVUJTE")==0)
        {
            printf("RUSSIAN\n");
        }
        else
        {
            printf("UNKNOWN\n");
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}
