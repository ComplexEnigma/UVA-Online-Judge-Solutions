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

void solve()
{
    int t;
    scanf("%d",&t);
    int n;
    vector <string> v;
    string s1,s2;
    while(t--)
    {
        v.clear();
        int ans=0,a;
        scanf("%d",&n);
        while(n--)
        {
            cin>>s1;
            if(s1=="SAME")
            {
                cin>>s2>>a;
                v.push_back(v[a-1]);
                if(v[a-1]=="LEFT")
                    ans--;
                else
                    ans++;
            }
            else{
                v.push_back(s1);
                if(s1=="LEFT")
                    ans--;
                else
                    ans++;
            }
        }
        printf("%d\n",ans);
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
