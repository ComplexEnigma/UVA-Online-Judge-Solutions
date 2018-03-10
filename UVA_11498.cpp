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
    int q;
    int x,y;
    int a,b;
    while(scanf("%d",&q)==1)
    {
        if(q==0)
            break;
        scanf("%d %d",&x,&y);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            if(a==x || b==y)
            {
                printf("divisa\n");
            }
            else if(a>x && b>y)
            {
                printf("NE\n");
            }
            else if(a>x && b<y)
            {
                printf("SE\n");
            }
            else if(a<x && b>y)
            {
                printf("NO\n");
            }
            else if(a<x && b<y)
            {
                printf("SO\n");
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}
