#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int T=1;
    while(1)
    {
        gets(a);
        if(strcmp("*",a)==0)
        {
            break;
        }
        if(strcmp("Hajj",a)==0)
        {
            printf("Case %d: Hajj-e-Akbar\n",T);
            T++;
        }
        if(strcmp("Umrah",a)==0)
        {
            printf("Case %d: Hajj-e-Asghar\n",T);
            T++;
        }
    }
    return 0;
}
