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

int Array[105][105];
int Result[105][105];

void PreCall()
{
        for(int i=1;i<=104;i++)
        {
            for(int j=1;j<=104;j++)
            {
                Array[i][j] = 0;
                Result[i][j] = 0;
            }
        }
}

void C_Enigma()
{

    int n , m;
    int cases = 1;
    while(scanf("%d %d",&n , &m ) == 2)
    {
        if(n==0 && m==0)
            break;
        if(cases>1)
            cout << "\n";
        PreCall();
        getchar();
        for(int i=1;i<=n;i++)
        {
            char s[105];
            gets(s);
            for(int j=1;j<=m;j++)
            {
                if(s[j-1] == '*')
                    Array[i][j] = 2;
                else
                    Array[i][j] = 1;
            }
        }

        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout << Array[i][j] << " ";
            }
            cout << endl;
        }*/

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if( Array[i][j] == 2 )
                    Result[i][j]++;

                if( Array[i-1][j] == 2)
                    Result[i][j]++;
                if( Array[i+1][j] == 2 )
                    Result[i][j]++;

                if( Array[i][j-1] == 2)
                    Result[i][j]++;
                if( Array[i][j+1] == 2 )
                    Result[i][j]++;

                if( Array[i+1][j-1] == 2)
                    Result[i][j]++;
                if( Array[i+1][j+1] == 2 )
                    Result[i][j]++;

                if( Array[i-1][j-1] == 2)
                    Result[i][j]++;
                if( Array[i-1][j+1] == 2)
                    Result[i][j]++;

            }
        }

        cout << "Field #" << cases++ <<":\n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if( Array[i][j] == 2)
                    cout << "*";
                else
                    cout << Result[i][j];
            }
            cout << "\n";
        }
    }
}

int main()
{
    //fastio;
    //filein;
    //fileout;
    C_Enigma();

    return 0;
}
