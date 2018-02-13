#include<bits/stdc++.h>
using namespace std;

map <int, vector <int> > G;
vector <int> level;

void BFS(int source)
{
    queue <int> Q;
    Q.push(source);
    level[source]=0;
    while(Q.empty()==false)
    {
        int u=Q.front();
        Q.pop();
        int sz=G[u].size();
        for(int i=0;i<sz;i++)
        {
            int v=G[u][i];
            if(level[v]==-1)
            {
                level[v]=level[u]+1;
                Q.push(v);
            }
        }
    }
}

void solve()
{
    int t;
    scanf("%d",&t);
    int n,e,x,y;
    while(t--)
    {
        G.clear();
        level.clear();
        scanf("%d %d",&n,&e);
        level.resize(n);
        fill(level.begin(),level.end(),-1);
        while(e--)
        {
            scanf("%d %d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        BFS(0);
        int sz=level.size();
        for(int i=1;i<sz;i++)
        {
            printf("%d\n",level[i]);
        }
        if(t!=0)
            printf("\n");
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
