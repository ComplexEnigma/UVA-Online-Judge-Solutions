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

map <int,int> row_counter;
map <int,int> column_counter;
int Array[105][105];

void PreCall()
{

}

void C_Enigma()
{
    //PreCall();
    int n;
    while(1)
    {
        n = _I();
        if( n==0 )
            break;

        Clear(row_counter);
        Clear(column_counter);

        vector <int> row,column;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int a = _I();
                Array[i][j] = a;
                row_counter[i]+=a;
                column_counter[j]+=a;
            }
            if(row_counter[i]&1)
                PB(row,i);
        }

        map<int,int>::const_iterator it;
        for( it=column_counter.begin(); it!=column_counter.end(); it++)
        {
            if(it->second&1)
                PB(column, it->first);
        }

        int row_size = row.size();
        int column_size = column.size();

        if( row_size == 0 && column_size == 0)
        {
            cout << "OK\n";
        }
        else if( row_size == 1 && column_size == 1)
        {
            cout << "Change bit (" << row[0]+1 <<"," << column[0]+1 <<")\n";
        }
        else
            cout << "Corrupt\n";

    }
}

int main()
{
    //fastio;
    //filein;fileout;
    C_Enigma();

    return 0;
}
