#include<bits/stdc++.h>
using namespace std;

map <int,int> team_info;
queue <int> team_Q;
map <int, vector<int> > part_Q;
vector <int> Front;
vector <int> Rear;
vector <bool> Q_element;

/*void printQ()
{
    queue <int> tempq;
    tempq = team_Q;
    while( !tempq.empty() )
    {
        cout << tempq.front() << " - ";
        tempq.pop();
    }
    cout << endl;
}*/

void Enqueue( int data )
{
    int team = team_info[ data ];

    if( team_Q.empty()  )
    {
        Rear [ team ] ++;
        team_Q.push( team );
        Q_element[team] = true;
        part_Q[team].push_back( data );

    }
    else if(!team_Q.empty() && !Q_element[team])
    {
        Rear[team] ++;
        team_Q.push( team );
        Q_element[team] = true;
        part_Q[ team ].push_back( data );

    }
    else
    {
        Rear[team] ++;
        part_Q[ team ].push_back( data );

    }
}

int Dequeue()
{
    if( !team_Q.empty() )
    {
        int first = team_Q.front();
        if( Front[ first ] < Rear[first] )
        {
            int value = part_Q[first][ Front[first] ];
            Front[ first ] ++;
            if( Front[first] == Rear[first] )
            {
                part_Q[first].clear();
                team_Q.pop();
                Q_element[first] = false;
                if( team_Q.empty() )
                {
                    part_Q.clear();
                    Q_element.clear();
                    Q_element.resize(1005);
                }
                Front[first] = 0;
                Rear[first] = 0;
            }
            return value;
        }

    }
}
void ClearQ()
{
    while( !team_Q.empty() )
    {
        team_Q.pop();
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    int cases = 1;
    while( scanf( "%d", &t ) == 1 && t!=0)
    {

        ClearQ();
        Front.clear();
        Rear.clear();
        part_Q.clear();
        team_info.clear();

        Front.resize(1005);
        Rear.resize(1005);
        Q_element.resize(1005);

        fill(Q_element.begin(),Q_element.end(),false);



        for ( int i=1; i<=t; i++ )
        {
            int element_no;
            scanf( "%d", &element_no );
            while( element_no-- )
            {
                int id;
                scanf( "%d", &id );
                team_info[id] = i;
            }
        }
        getchar();
        string statement;
        printf("Scenario #%d\n",cases++);
        while( 1 )
        {
            cin >> statement;
            if( statement == "STOP" )
            {
                break;
            }
            else if( statement == "ENQUEUE" )
            {
                int data;
                scanf( "%d", &data );
                getchar();
                /*cout << "data = " << data << " team = " << team_info[data];
                cout << " status = " << Q_element[team_info[data]] << endl;
                printQ();*/
                Enqueue( data );
            }
            else
            {
                /*cout << "Queue = ";
                printQ();*/
                int data = Dequeue();

                printf("%d\n",data);
            }
        }
        printf("\n");

    }
    return 0;
}
