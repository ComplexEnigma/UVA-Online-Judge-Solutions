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

vector <string> v;
int mark[105];

void SET()
{
    v.push_back("Happy");
    v.push_back("birthday");
    v.push_back("to");
    v.push_back("you");
    v.push_back("Happy");
    v.push_back("birthday");
    v.push_back("to");
    v.push_back("you");
    v.push_back("Happy");
    v.push_back("birthday");
    v.push_back("to");
    v.push_back("Rujia");
    v.push_back("Happy");
    v.push_back("birthday");
    v.push_back("to");
    v.push_back("you");
}

void solve()
{
    SET();
    int n;
    char s[105][105];
    while(scanf("%d",&n)==1)
    {
        int mark[105]={0};
        getchar();
        for(int i=0; i<n; i++)
        {
            scanf("%s",&s[i]);
        }
        if(n<=16)
        {
            for(int i=0; i<16;)
            {
                for(int j=0; j<n; j++)
                {
                    cout<<s[j]<<": "<<v[i]<<"\n";
                    i++;
                    if(i==16)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            int num=ceil(n/(double)16);
            int p=0;
            num*=16;
            while(1)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<s[j]<<": "<<v[p%16]<<"\n";
                    p++;
                    mark[j]=1;
                    if(mark[n-1]==1 && p%16==0)
                        break;
                }
                if(mark[n-1]==1 && p%16==0)
                        break;
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
