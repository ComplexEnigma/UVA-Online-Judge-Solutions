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

int data[20005];
int data2[20005];
int a[105];

void PreCall()
{

}

void C_Enigma()
{
    //PreCall();
    int n;
    int cases = 1;
    while( scanf("%d",&n) == 1)
    {
        memset(data,0,sizeof(data));
        memset(data2,0,sizeof(data2));
        int flag = 0;
        for(int i=1;i<=n;i++)
        {
            a[i] = _I();
            if( a[i] <= a[i-1])
                flag = 1;
        }
        if(flag)
        {
            cout << "Case #" << cases++ << ": "<<"It is not a B2-Sequence.\n\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int sum = a[i] + a[j];
                if(data[sum] == 0)
                {
                    data[sum] = 1;
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(!flag)
            cout << "Case #" << cases++<< ": "<<"It is a B2-Sequence.\n";
        else
            cout << "Case #" << cases++<< ": "<<"It is not a B2-Sequence.\n";
        puts("");
    }
}

int main()
{
    //fastio;
    //filein;fileout;
    C_Enigma();

    return 0;
}
