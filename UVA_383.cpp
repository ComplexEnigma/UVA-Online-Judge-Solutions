#include<bits/stdc++.h>
using namespace std;

map <string, vector <string> > G;
map <string,int> level;

void BFS(string s)
{
    queue <string> Q;
    Q.push(s);
    level[s]=0;
    while(Q.empty()==false)
    {
        string u=Q.front();
        Q.pop();
        int sz=G[u].size();
        for(int i=0;i<sz;i++)
        {
            string v=G[u][i];
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
    int n,e,q,cost;
    int cases=1;
    string s1,s2;
    while(cases<=t)
    {
        G.clear();
        scanf("%d %d %d",&n,&e,&q);
        while(n--)
        {
            cin>>s1;

        }
        while(e--)
        {
            cin>>s1>>s2;
            G[s1].push_back(s2);
            G[s2].push_back(s1);
            level[s1]=-1;
            level[s2]=-1;
        }
        if(cases==1)
        {
            printf("SHIPPING ROUTES OUTPUT\n\n");
        }
        map <string,int>::iterator it;

        printf("DATA SET  %d\n\n",cases);
        while(q--)
        {
            cin>>cost>>s1>>s2;
            BFS(s1);

            int ans=level[s2]*cost*100;
            if(ans<=0)
            {
                printf("NO SHIPMENT POSSIBLE\n");
            }
            else
            {
                printf("$%d\n",ans);
            }
            for(it=level.begin();it!=level.end();it++)
                it->second=-1;

        }
        printf("\n");
        cases++;
        if(cases>t)
            printf("END OF OUTPUT\n");

    }
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}
