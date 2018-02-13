/***
         _______________________________

             MD. SYMON HASAN SHOHAN
             UNIVERSITY OF ASIA PACIFIC
             isymonhs@gmail.com
         _______________________________
*/
#include<bits/stdc++.h>
using namespace std;

map <int,int> visited;

void BFS(int source,map <int, vector <int> > G)
{
    queue<int> Q;
    Q.push(source);
    visited[source]=0;
    while (Q.empty() == false)
    {
        int u = Q.front();
        Q.pop();
        int sz = G[u].size();
        for(int i=0; i<sz; i++)
        {
            int v =G[u][i];
            if(!visited.count(v))
            {
                visited[v]=visited[u]+1;
                Q.push(v);
            }
        }
    }
}

void solve()
{
    int nc,cs=1;
    while(scanf("%d",&nc)==1)
    {
        map <int, vector <int> > G;
        if(nc==0)
            break;
        int a,b;
        while(nc--)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }

        while(scanf("%d %d",&a,&b)==2)
        {
            visited.clear();
            if(a==0 && b==0)
                break;
            BFS(a,G);
            map <int,int>::const_iterator it;
            int counter=0;
            for(it=visited.begin(); it!=visited.end(); ++it)
            {
                if((*it).second>b)
                    ++counter;

            }
            it=visited.begin();
            if(G.find(a)==G.end())
            {
                visited.clear();
            }
            counter+=G.size()-visited.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cs,counter,a,b);
            cs++;
        }
    }

}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
