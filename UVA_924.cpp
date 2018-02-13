/***
         _______________________________

             MD. SYMON HASAN SHOHAN
             UNIVERSITY OF ASIA PACIFIC
             isymonhs@gmail.com
         _______________________________
*/
#include<bits/stdc++.h>
using namespace std;

map < int, vector<int> > G;

map <int,int> visited;

vector <int> counter(2501);

void BFS(int source)
{
    queue <int> Q;
    Q.push(source);
    visited[source]=0;
    while(Q.empty()==false)
    {
        int u=Q.front();
        Q.pop();
        int sz=G[u].size();
        for(int i=0;i<sz;i++)
        {
            int v=G[u][i];
            if(visited[v]==-1)
            {
                visited[v]=visited[u]+1;
                counter[visited[v]]++;
                Q.push(v);
            }
        }
    }
}

void solve()
{
    int e;
    while(scanf("%d",&e)==1)
    {
        int l=0,a;
        while(e--)
        {
            int n;
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&a);
                //G[a].push_back(l);
                G[l].push_back(a);
            }
            visited[l]=-1;
            l++;
        }
        /*
        map < int, vector<int> >::iterator ig;
        for(ig=G.begin();ig!=G.end();ig++)
        {
            cout<<ig->first;
            for(int i=0;i<ig->second.size();i++)
                cout<<" -> "<<ig->second[i];
            cout<<endl;
        }
        cout<<endl;*/
        int t;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d",&a);
            BFS(a);
            map <int,int>::iterator it;
            int MAX=0,IN=0;
            for(it=visited.begin();it!=visited.end();it++)
            {
                //cout<<it->first<<" "<<it->second<<endl;
                it->second=-1;
            }
            //cout<<endl;
            vector <int>::iterator vt;
            int in=0;
            for(vt=counter.begin();vt!=counter.end();vt++)
            {
                if(*vt>MAX)
                {
                    MAX=*vt;
                    IN=in;
                }
                in++;
            }
            counter.clear();
            counter.resize(2501);

            if(MAX!=0)
                printf("%d %d\n",MAX,IN);
            else
                printf("0\n");

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
