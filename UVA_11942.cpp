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


void C_Enigma()
{
    int n=_I();
    printf("Lumberjacks:\n");
    while(n--){
    int a[10],previous,operation=0;
    for( int i=0; i<10; i++)
    {
        a[i]=_I();
        if(i==0)
        {
            previous=a[i];
            continue;
        }
        if(i==1)
        {
            if(a[i]>previous)
            {
                operation=1;
            }
            else if(a[i]<previous)
            {
                operation=2;
            }
            previous=a[i];
            continue;
        }
        if(operation==1 && a[i]<previous)
        {
            operation=3;
        }
        else if(operation==2 && a[i]>previous)
        {
            operation=3;
        }
        previous=a[i];
    }
    if(operation==0 || operation==1 || operation==2)
        printf("Ordered\n");
    else if(operation==3)
        printf("Unordered\n");
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
