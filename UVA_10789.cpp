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

int status[10005];
map <char,int> counter;

void PreCall()
{
    status[0] = 1;
    status[1] = 1;
    for( int i=4;i<10005;i+=2)
        status[i] = 1;
    for(int i=3;i*i<=10005;i+=2)
    {
        if(status[i] == 0)
        {
            for(int j=i*i;j<10005;j+=i)
                status[j] = 1;
        }
    }
}

void C_Enigma()
{
    PreCall();
    int N = _I();
    getchar();
    int cases = 1;
    while( N-- )
    {
        counter.clear();
        string s;
        cin >> s;
        getchar();
        int length = s.length();
        int maximum = 0;
        for(int i=0;i<length;i++)
        {
            counter[s[i]]++;
        }

        map <char,int>::const_iterator it;
        //set <char> S;

        it = counter.begin();
        bool flag = false;
        cout << "Case " << cases++ << ": ";
        while( it != counter.end() )
        {
            if( status[it->second] == 0)
            {
                flag = true;
                cout << it->first;
            }
            it ++;
        }
        if(flag == false)
            cout << "empty";
        cout << endl;
    }
}

int main()
{
    //fastio;
    //filein;fileout;
    C_Enigma();

    return 0;
}
