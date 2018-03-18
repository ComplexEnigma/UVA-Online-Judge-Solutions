// Author : ComplexEnigma
// Date :

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<utility>
using namespace std;

typedef long long ll;

#define filein        {freopen("input.txt","r",stdin);}
#define fileout     {freopen("output.txt","w",stdout);}
#define fastio      {ios_base::sync_with_stdio(false);cin.tie(NULL);}

#define PB(x,y) x.push_back(y)
#define Clear(x) x.clear()
#define Resize(x) x.resize()
#define Fill(x,y) fill(x.begin(),x.end(),y)
#define Sort(x) sort(x.begin(),x.end())
#define rep(i,n) for( i=0; i<n; i++)
#define REP(i,k,n) for( i=k; i<n; i++)
#define REPR(i,k,n) for( i=k; i>n; i--)

int _I() {int x;scanf("%d",&x);return x;}
ll _LL() {ll x;scanf("%lld",&x);return x;}
float _F() {float x;scanf("%f",&x);return x;}
double _LF() {double x;scanf("%lf",&x);return x;}

map <string,string> Mpp;

void PreCall()
{

}

void C_Enigma()
{
    //PreCall();
    char s[100005];
    while( gets(s) )
    {
        char *token;

        token = strtok(s, " ");
        vector <string> v;
        string word;
        int wordcount = 0;
        while( token != NULL )
        {
            //printf(" %s\n", token );
            word = token;
            if(word!="")
            {
                PB( v, word);
                wordcount ++;
            }
            token = strtok(NULL, " ");
        }

        if(wordcount>=2)
            Mpp[v[1]] = v[0];
        else if(wordcount == 1)
        {
            if(Mpp.count(v[0])==false)
                cout << "eh" << endl;
            else
                cout << Mpp[v[0]] << endl;
        }
    }
}

int main()
{
    //fastio;
    //filein;fileout;
    C_Enigma();

    return 0;
}
