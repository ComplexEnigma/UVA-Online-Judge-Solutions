/***
         _______________________________

             MD. SYMON HASAN SHOHAN
             UNIVERSITY OF ASIA PACIFIC
             isymonhs@gmail.com
         _______________________________
*/
#include<bits/stdc++.h>
using namespace std;

map < string, vector < string> > G;

map < string, int> visited;

map <string,string> previous;

vector <string> route;

void BFS(string s)
{
    queue <string> Q;

    Q.push(s);
    visited[s]=0;
    while(Q.empty()==false)
    {
        string u=Q.front();
        Q.pop();
        int sz=G[u].size();
        for(int i=0; i<sz; i++)
        {
            string v=G[u][i];
            if(visited[v]==-1)
            {
                visited[v]=visited[u]+1;
                previous[v]=u;
                Q.push(v);
            }
        }
    }
}


void solve()
{
    int n,cnt=0;
    string s1,s2;

    while(cin>>n)
    {
        G.clear();
        visited.clear();
        previous.clear();
        route.clear();
        if(cnt){
            cout<<"\n";
        }
        while(n--)
        {
            cin>>s1>>s2;
            G[s1].push_back(s2);
            G[s2].push_back(s1);
            visited[s1]=-1;
            visited[s2]=-1;
        }
        cin>>s1>>s2;
        //cout<<visited.size()<<endl;
        //cout<<G.count(s1)<<endl;
        if(G.count(s1)==false || G.count(s2)==false)
        {
            cout<<"No route"<<"\n";
            continue;
        }
        BFS(s1);

        if(visited[s2]==-1)
        {
            cout<<"No route"<<"\n";
            continue;
        }
        string temp=s2;
        while(temp!=s1)
        {
            //cout<<"hang"<<endl;
            route.push_back(temp);
            temp=previous[temp];
        }
        route.push_back(s1);
        int sz=route.size();
        //cout<<sz<<endl;
        int in=0;
        for(int i=sz-1;i>0;)
        {
            cout<<route[i]<<" ";
            i--;
            if(i>=0)
                cout<<route[i]<<"\n";
        }

        cnt++;
    }

}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
