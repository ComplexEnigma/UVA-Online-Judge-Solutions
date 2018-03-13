#include<stdio.h>

int _I() {int x;scanf("%d",&x);return x;}

int status[1000005];
int digit[1000005];
int counter[1000005];
int i,j;

void sieve()
{
    status[0] = 1;
    status[1] = 1;

    for(i=2;i*i<=1000005;i++)
    {
        if(status[i] == 0)
        {
            for(j=2*i; j<1000005;j+=i)
            {
                status[j] = 1;
            }
        }
    }
    int Counter = 0;
    counter[2] = ++Counter;
    for(i = 3;i<=1000;i++)
    {
        int temp = i;

        int number = temp%10+(temp/10)%10+((temp/10)/10)%10;

        digit[i] = number;

        if(i%2==1 && status[number] == 0 && status[i] == 0)
        {

            if(number&1)
                counter[i] = ++Counter;
            else if(number == 2)
                counter[i] = ++Counter;
            else
                counter[i] = Counter;
        }
        else
        {
            counter[i] = Counter;
        }

    }
}

void PreCall()
{
    int Counter = counter[1000];
    for(i=1001;i<=1000001;i+=2)
    {
        int temp = i;
        int number = 0;
        counter[i-1] = Counter;
        while(temp!=0)
        {
            if(digit[temp]!=0)
            {
                number += digit[temp];
                break;
            }
            number += temp%10;
            temp/=10;
        }

        digit[i] = number;

        if(number == 2 && status[i] == 0)
        {

            counter[i]= ++Counter;

            continue;
        }

        if(status[number] == 0 && status[i] == 0 && i%2==1)
        {

            counter[i] = ++Counter;
        }
        else
        {
            counter[i] = Counter;
        }

    }
}

void C_Enigma()
{
    sieve();
    PreCall();
    int N = _I();

    while( N-- )
    {
        int t1 = _I();
        int t2 = _I();
        printf("%d\n",counter[t2]-counter[t1-1]);
    }
}

int main()
{
    C_Enigma();
    return 0;
}

