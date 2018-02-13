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


GraphInt;
vector <int> visited(305);
PrevInt;

void BFS(int source)
{
    queue <int> Q;
    Q.push(source);
    visited[source]=0;
    while(Empty(Q)==false)
    {
        int u=Front(Q);
        Pop(Q);
        int sz=Size(G[u]);
        for(int i=0; i<sz; i++)
        {
            int v=G[u][i];
            if(visited[v]==-1)
            {
                visited[v]=visited[u]+1;
                previous[v]=u;
                Push(Q,v);
            }
        }
    }
}

void FindPath(int a,int b)
{
    if(visited[b]==-1)
    {
        printf("connection impossible\n");
        return;
    }
    if(G.count(a)==false || G.count(b)==false)
    {
        printf("connection impossible\n");
        return;
    }
    int temp=b;
    CreateVectorInt(route);
    while(temp!=a)
    {
        PB(route,temp);
        temp=previous[temp];
    }
    PB(route,temp);
    int sz=Size(route);
    for(int i=sz-1; i>=0; i--)
    {
        if(i>0)
            printf("%d ",route[i]);
        else
            printf("%d\n",route[i]);
    }
}

void solve()
{
    int n,q;
    string s;
    char garbage;
    while(scanf("%d",&n)==1)
    {
        FillVector(visited);

        while(n--)
        {
            int router;
            cin >> router;
            getline(cin,s);
            int len=s.length();
            stringstream ss(s);
            int connectedTo;
            while (ss >> garbage >> connectedTo)
            {
                G[router].push_back(connectedTo);
            }
        }
        /*cout<<endl;
        map <int, vector<int> >::iterator it;
        for(it=G.begin();it!=G.end();it++)
        {
            cout<<it->first<<"->";
            for(int i=0;i<it->second.size();i++)
            {
                cout<<it->second[i]<<" ";
            }
            cout<<endl;
        }*/
        scanf("%d",&q);
        int x,y;
        printf("-----\n");
        while(q--)
        {
            scanf("%d %d",&x,&y);
            BFS(x);
            FindPath(x,y);
            /*cout<<endl;
            for(int i=1;i<11;i++)
            {
                cout<<i<<" "<<visited[i]<<endl;
            }*/
            Clear(visited);
            visited.resize(305);
            FillVector(visited);
            Clear(previous);
        }
        Clear(G);
    }
}

int main()
{
    //filein();
    //file();
    solve();
    return 0;
}
