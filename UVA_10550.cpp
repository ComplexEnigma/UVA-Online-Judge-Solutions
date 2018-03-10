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
    int p,c1,c2,c3,ans,mid;
    while(scanf("%d %d %d %d",&p,&c1,&c2,&c3)==4)
    {
        ans=0;
        if(p==0 && c1==0 && c2==0 && c3==0)
            break;
        if(p==0)
            p=40;
        if(c1==0)
            c1=40;
        if(c2==0)
            c2=40;
        if(c3==0)
            c3=40;
        p+=40;
        c1+=40;
        c2+=40;
        c3+=40;

        ans+=360*2;
        //cout<<ans<<" ";
        if(p-c1>=0)
            ans+=abs(p-c1)*9;
        else
            ans+=((p-c1)+40)*9;
        //cout<<ans<<" ";
        ans+=360;
        //cout<<ans<<" ";
        if(c2-c1>=0)
            ans+=abs(c2-c1)*9;
        else
            ans+=((c2-c1)+40)*9;
        //ans+=(abs(c2-c1)*9);
        //cout<<ans<<endl;
        if(c2-c3>=0)
            ans+=abs(c2-c3)*9;
        else
            ans+=((c2-c3)+40)*9;
        //ans+=(abs(c3-c2)*9);

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
