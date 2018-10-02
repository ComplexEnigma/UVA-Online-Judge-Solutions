#include<bits/stdc++.h>
using namespace std;
char Arr[32][32][32];
int level[32][32][32];
int dx[] = { -1, 1, 0, 0 , 0, 0 };
int dy[] = { 0, 0, -1, 1 , 0 , 0};
int dz[] = { 0, 0, 0 , 0 , -1 , 1};
int l , r ,c;
typedef struct node
{

    int x;
    int y;
    int z;


};
void reset()
{
    for(int i=0; i<32; i++ )
        for(int j = 0; j<32; j++)
            for(int k=0; k<32; k++)
                level[i][j][k] = -1;
}

void bfs(node s , node d)
{
    queue <node> Q;
    Q.push( s );
    level[s.x][s.y][s.z] = 0;
    while( !Q.empty() )
    {
        node st = Q.front();
        Q.pop();
        int ix= st.x;
        int iy = st.y;
        int iz = st.z;
       // cout << "i = " << ix << " j = " << iy << " k = " << iz << endl;
        //cout << "level = " << level[ix][iy][iz] << endl;
        for(int i=0; i<6; i++ )
        {
            if( ix+dx[i] >=0 && ix+dx[i]<l )
                st.x = ix+dx[i];
            if( iy+dy[i] >=0 && iy+dy[i]<r )
                st.y = iy+dy[i];
            if( iz+dz[i] >=0 && iz+dz[i]<c )
                st.z = iz+dz[i];
            //cout << st.x << "  " << st.y << "  " << st.z << endl;
            //getchar();
            if( Arr[st.x][st.y][st.z]=='.' && level[st.x][st.y][st.z]==-1)
            {
                //cout << "YES" << endl;
                level[st.x][st.y][st.z] = level[ix][iy][iz] + 1;
                Q.push( st );
            }
            else if( Arr[st.x][st.y][st.z]=='E' && level[st.x][st.y][st.z]==-1)
            {
                //cout << "YES" << endl;
                level[st.x][st.y][st.z] = level[ix][iy][iz] + 1;
                Q.push( st );
            }

        }

    }
}

int main()
{
      //freopen("out.txt","r",stdin);
    while( scanf("%d %d %d" , &l,&r,&c)==3 && l!=0 && r!=0 && c!=0)
    {
        reset();
        //getchar();
        node source, des;
        for(int i = 0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                  scanf("%s" ,Arr[i][j] );
                for(int k = 0 ; k<c; k++)
                {
                    if( Arr[i][j][k]=='S')
                    {
                        source.x = i;
                        source.y = j;
                        source.z = k;
                    }
                    else if( Arr[i][j][k]=='E')
                    {
                        des.x = i;
                        des.y = j;
                        des.z = k;
                    }
                }
            }
        }

        /*for(int i = 0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                cout << Arr[i][j] << endl;
            }
        }*/
        //cout << "source " << source.x << " " << source.y << " " << source.z << endl;
        bfs( source , des );
        if( level[des.x][des.y][des.z]!=-1 )
            printf("Escaped in %d minute(s).\n",level[des.x][des.y][des.z] );
        else
            printf("Trapped!\n");

//        for(int i = 0; i<l; i++)
//        {
//            for(int j=0; j<r; j++)
//            {
//                  for(int k=0; k<c; k++)
//                        cout << level[i][j][k] << "  ";
//                  cout << endl;
//            }
//            cout << endl;
//        }


    }
    return 0;
}
