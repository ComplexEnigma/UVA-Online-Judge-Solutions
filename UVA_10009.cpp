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
    int t;
    scanf("%d",&t);
    string s1,s2;
    while(t--)
    {
        G.clear();
        int n,q;
        scanf("%d %d",&n,&q);
        while(n--)
        {
            cin>>s1>>s2;
            G[s1].push_back(s2);
            G[s2].push_back(s1);
            visited[s1]=-1;
            visited[s2]=-1;
        }
        /* //Graph Print
        map < string, vector < string> >::iterator gt;
        for(gt=G.begin();gt!=G.end();gt++)
        {
            cout<<"From "<<gt->first;
            for(int i=0;i<gt->second.size();i++)
            {
                cout<<" -> "<<gt->second[i];
            }
            cout<<endl;
        }
        cout<<endl;

        //visited print
        map < string, int>::iterator iv;
        for(iv=visited.begin();iv!=visited.end();iv++)
        {
            cout<<iv->first<<" = "<<iv->second<<endl;
        }
        */
        map < string, int>::iterator iv;
        while(q--)
        {
            for(iv=visited.begin(); iv!=visited.end(); iv++)
            {
                iv->second=-1;
            }
            cin>>s1>>s2;
            BFS(s1);
            /* //visited print
            for(iv=visited.begin(); iv!=visited.end(); iv++)
            {
                cout<<iv->first<<" = "<<iv->second<<endl;
            }
            cout<<endl;*/
            /* //previous print
            map <string,string>::iterator p;
            for(p=previous.begin();p!=previous.end();p++)
            {
                cout<<p->first<< " <- " <<p->second<<endl;
            }
            cout<<endl;
            */
            string temp=s2;

            vector <char> res;

            while(temp!=s1)
            {
                //cout<<temp<<" > ";
                res.push_back(temp[0]);
                temp=previous[temp];
            }
            res.push_back(s1[0]);
            int sr=res.size();
            for(int i=sr-1;i>=0;i--)
            {
                printf("%c",res[i]);
            }
            printf("\n");
            res.clear();
            previous.clear();

        }
        if(t!=0)
            printf("\n");

    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
