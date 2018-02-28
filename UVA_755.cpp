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
    int t;
    t=_I();

    map <char,char> m;
    m['A']='2';m['B']='2';m['C']='2';
    m['D']='3';m['E']='3';m['F']='3';
    m['G']='4';m['H']='4';m['I']='4';
    m['J']='5';m['K']='5';m['L']='5';
    m['M']='6';m['N']='6';m['O']='6';
    m['P']='7';m['R']='7';m['S']='7';
    m['T']='8';m['U']='8';m['V']='8';
    m['W']='9';m['X']='9';m['Y']='9';
    m['0']='0';m['1']='1';m['2']='2';
    m['3']='3';m['4']='4';m['5']='5';
    m['8']='8';m['7']='7';m['6']='6';
    m['9']='9';

    while(t--)
    {
        int N,flag=0;
        N=_I();

        //cout<<"n = "<<N<<endl;
        map < string,int> data;
        while(N--)
        {
            char s[10005];
            scanf("%s",&s);
            getchar();

            char num[100];
            num[3]='-';
            int ind=0;
            for(int i=0;s[i]!='\0' && ind<8;i++)
            {
                if(s[i]!='Z' && s[i]!='Q' && s[i]!='-' && s[i]>=65 && s[i]<=90 || s[i]>=48 && s[i]<=57)
                {
                    //cout<<m[s[i]];
                    num[ind]=m[s[i]];
                    ind++;
                    if(ind==3)
                        ind++;
                }
            }
            //cout<<endl;
            num[ind]='\0';
            //cout<<num<<endl;
            if(data.count(num)==false)
                data[num]=1;
            else
            {
                flag=1;
                data[num]++;
            }
        }
        if(flag==0)
            printf("No duplicates.\n");
        else
        {
            map<string,int>::iterator it;
            for(it=data.begin();it!=data.end();it++)
            {
                if(it->second!=1)
                    cout<<it->first<<" "<<it->second<<endl;
            }
        }
        if(t)
            printf("\n");
        //cout<<N<<endl;
    }
}

int main()
{
    //filein();fileout();
    C_Enigma();

    return 0;
}
