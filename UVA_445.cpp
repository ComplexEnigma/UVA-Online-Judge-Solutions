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
    string s;
    while( getline(cin,s) )
    {
        int length = s.length();
        int sum = 0;
        for(int i = 0; i < length; i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                sum+=s[i]-48;
            }
            else
            {
                char ch;

                if(s[i]=='!'){
                    printf("\n");
                    sum = 0;
                    continue;
                }
                else if(s[i] == 'b')
                {
                    ch = 32;
                }
                else
                {
                    ch = s[i];
                }
                for(int i = 0; i<sum;i++)
                {
                    printf("%c",ch);
                }
                sum = 0;
            }
        }
        puts("");
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
