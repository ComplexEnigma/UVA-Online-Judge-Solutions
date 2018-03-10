/***
         _______________________________

             MD. SYMON HASAN SHOHAN
             UNIVERSITY OF ASIA PACIFIC
             isymonhs@gmail.com
         _______________________________
*/
#include<bits/stdc++.h>
using namespace std;

#define filein() freopen("input.txt","r",stdin)
#define file() {freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}
#define fastio() { ios_base::sync_with_stdio(false);cin.tie(NULL);}
#define GraphString map<string, vector<string> > G
#define GraphInt map<int,vector<int> > G
#define VisitedString map<string,int> visited
#define VisitedInt map<int,int> visited
#define PrevString map<string,string> previous
#define PrevInt map<int,int> previous

#define Size(x) x.size()
#define Front(x) x.front()
#define Pop(x) x.pop()
#define Push(x,y) x.push(y)
#define Empty(x) x.empty()
#define PresentInMap(x,y) x.count(y)
#define PB(x,y) x.push_back(y)
#define Clear(x) x.clear()
#define FillVector(x) fill(x.begin(),x.end(),-1)
#define CreateVectorInt(x) vector<int> x

void solve()
{
    int t;
    scanf("%d",&t);
    getchar();
    string s;
    while(t--)
    {
        getline(cin,s);
        int len=s.length();
        int m=0,f=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='M')
                m++;
            else if(s[i]=='F')
                f++;
        }
        if(m==f && m!=1)
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
