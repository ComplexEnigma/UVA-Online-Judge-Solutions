// Created By ComplexEnigma

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<utility>
using namespace std;

typedef long long ll;

#define filein() {freopen("input.txt","r",stdin);}
#define fileout() {freopen("output.txt","w",stdout);}

int _I() {int x;scanf("%d",&x);return x;}
ll _LL() {ll x;scanf("%lld",&x);return x;}
float _F() {float x;scanf("%f",&x);return x;}
double _LF() {double x;scanf("%lf",&x);return x;}

#define PB(x,y) x.push_back(y)
#define Clear(x) x.clear()
#define Resize(x) x.resize()
#define Fill(x,y) fill(x.begin(),x.end(),y)
#define Sort(x) sort(x.begin(),x.end())

int prime[1000005];
vector <int> v;

void Seive()
{
    prime[0]=1;
    prime[1]=1;
    for(int i=4; i<1000005; i+=2)
    {
        prime[i]=1;
    }
    //PB(v,2);
    for(int i=3; i*i<1000005; i+=2)
    {
        if(prime[i]==0)
        {
            for(int j=3*i;j<1000005;j+=i)
            {
                prime[j]=1;
            }
        }
    }
}

void C_Enigma()
{
    int N;
    Seive();
    for(int i=0;i<1000005;i++)
    {
        if(prime[i]==0)
            PB(v,i);
    }
    while( scanf("%d", &N) == 1 )
    {
        if(N==0)
            break;
        int maximum=0,number1,number2;
        /*for(int i=2;i<N;i++)
        {
            if(prime[i]==0 && i+N-1>=N)
            {
                for(int j=N-1;j>i;j--)
                {
                    if(prime[j]==0 && i+j==N && abs(i-j)>maximum)
                    {
                        maximum = abs(i-j);
                        number1 = i;
                        number2 = j;
                        break;
                    }
                    if(i+j<N)
                        break;
                }
            }
        }*/
        int sz=v.size();
        //cout<<sz<<endl;

        for(int i=0;v[i]<N;i++)
        {
            if(prime[N-v[i]]==0)
            {
                number2=v[i];
                number1=N-v[i];
            }
        }
        printf("%d = %d + %d\n",N,number1,number2);
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
