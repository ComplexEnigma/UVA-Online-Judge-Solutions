
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

vector < vector<int> > G;
bool vis[105];
int n;

void BFS(int source)
{
    fill(vis,vis+n,false);
    queue <int> Q;

    Q.push(source);
    while(Q.empty()==false)
    {
        int u=Q.front();
        Q.pop();
        int sz=G[u].size();
        for(int j=0; j<sz; j++)
        {
            if(vis[G[u][j]]==false)
            {
                vis[G[u][j]]=true;
                Q.push(G[u][j]);
            }
        }
    }

    int counter=0;
    CreateVectorInt(node);
    for(int j=0; j<n; j++)
    {
        if(!vis[j])
        {
            counter++;
            PB(node,j+1);
        }
    }
    cout<<counter;
    for(int j=0; j<counter; j++)
    {
        cout<<" "<<node[j];
    }
    cout<<endl;
    Clear(node);
}

void solve()
{
    int x,y;
    while(1)
    {
        Clear(G);
        scanf("%d",&n);
        if(n==0)
            break;
        G.resize(n+1);
        while(1)
        {
            scanf("%d",&x);
            if(x==0)
                break;
            while(1)
            {
                scanf("%d",&y);
                if(y==0)
                    break;
                PB(G[x-1],y-1);
            }
        }

        /*map<int,vector<int> >::iterator it;
        cout<<"GRAPH"<<endl;
        for(it=G.begin();it!=G.end();it++)
        {
            cout<<it->first<<" -> ";
            for(int i=0;i<it->second.size();i++)
            {
                cout<<it->second[i]<<" ";
            }

            cout<<endl;
        }
        cout<<endl;*/

        int q;
        scanf("%d",&q);
        for(int i=0; i<q; i++)
        {
            scanf("%d",&x);
            BFS(x-1);
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

