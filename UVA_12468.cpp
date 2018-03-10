#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c;
    while(1)
    {
        cin>>a>>b;
        if(a==-1 && b==-1)
        {
            break;
        }
        if(a>=0 && a<=99 && b>=0 && b<=99)
        {
                 c=abs(a-b);
                 if(c>=50)
                    c=100-c;
                 cout<<c<<endl;
        }
    }
    return 0;
}
