// Created By ComplexEnigma

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
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

int N;



void C_Enigma()
{
    N = _I();
    getchar();

    while( N-- )
    {
        stack < char > S;
        char s[130];
        gets(s);

        int flag = 0;

        for( int i=0; s[i]!='\0'; i++)
        {
            if( (s[i]==')' && S.empty()) || (s[i]==']' && S.empty()) )
            {
                flag = 1;
                break;
            }
            if( s[i] == ')' || s[i] == ']')
            {
                if( s[i] == ')' && S.top() == '(')
                    S.pop();
                else if( s[i] == ']' && S.top() == '[')
                    S.pop();
                else
                {
                    flag = 1;
                    break;
                }
            }
            else if( s[i] == '(' || s[i] == '[' )
            {
                S.push(s[i]);
            }
        }

        if (flag || !S.empty() )
        {
            printf( "No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
