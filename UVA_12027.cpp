#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("output.txt","w",stdout);
    string s;
    while( cin >> s )
    {
        if(s=="0") break;
        int num = s[0] - '0';
        int len = s.length();
        if(len%2==0)
            num = (num * 10) + (s[1] - '0');
        len--;
        int ans = sqrt( num );
        printf("%d" , ans );
        for(int i=0; i<len/2; i++)
            printf("0");
        printf("\n");
    }
    return 0;
}
