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

map <string, pair<int,int> > m;
vector <string> v;

void solve()
{
    int n,cases=0;
    string s,s1;
    while(scanf("%d",&n)==1)
    {
        m.clear();
        v.clear();
        if(cases)
        {
            cout<<"\n";
        }
        for(int i=0;i<n;i++)
        {
            cin>>s;
            v.push_back(s);
            m[s].first=0;
            m[s].second=0;
        }
        int m1,a;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            scanf("%d",&a);
            m[s].first+=a;
            scanf("%d",&m1);
            if(m1==0){
                m[s].second+=a;

            }
            for(int j=0;j<m1;j++)
            {
                cin>>s1;
                m[s1].second+=a/m1;
                if(j==0){
                    //cout<<(m[s].first-(a/m1)*m1)<<endl;
                    m[s].first-=(m[s].first-(a/m1)*m1);
                    //cout<<m[s].first<<endl;
                }
            }
        }
        vector <string>::iterator it;
        for(it=v.begin();it!=v.end();it++)
        {
            cout<<*it<<" "<<m[*it].second-m[*it].first<<endl;
        }

        cases++;
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    solve();
    return 0;
}
