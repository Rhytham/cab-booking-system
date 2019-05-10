#include<iostream>
#include<thread>
#include<bits/stdc++.h>
using namespace std;
#include <windows.h>
#include<bits/stdc++.h>
#include<math.h>
#define M 5
#define V 5

int cars[V][3]={{0,0,-1},{1,0,-1},{2,0,-1},{3,0,-1},{4,0,-1}};
int path[M][M][M];
int cost[M][M];

int graph[M][M]={
                    {0, 40, 0,0,20},
					{40, 0, 80, 0,0},
                    {20, 80, 0, 70,0},
                    {0,0,70,0,9},
                    {0,0,0,90,0},

                };

//int lock[M][M];
//int stop[M][M];

//for(int i=0;i<M;i++)
//    for(int j=0;j<M;j++)
//        lock[i][j]=-1

int minDistance(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < M; v++)
if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}




int dijkstra(int src,int dest)
{
    if(cost[src][dest]!=0){
       return cost[src][dest];
        }
//    if(src==-1){
//        return 0;
//    }
     int dist[M];
     int i;
     bool sptSet[M];


     int parent[M];
     for ( i = 0; i < M; i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i]=-1;
     }


     dist[src] = 0;

     for (int count = 0; count < M-1; count++)
     {

       int u = minDistance(dist, sptSet);

       sptSet[u] = true;

       for (int v = 0; v < M; v++)
   {

         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
           {
               dist[v] = dist[u] + graph[u][v];
            //cost[u][v]=dist[v];
            parent[v]=u;
//            cout<<v<<" "<<parent[v]<<endl;

           }
     }

}


for ( i = 0; i < M; i++){
    cost[src][i]=dist[i];

    int p=i;
stack<int> po;
while(p!=src)
{
    po.push(p);
   // cout<<po.top()<<"r"<<endl;
    p=parent[p];
    //cout<<po.top()<<"t"<<endl;
}
po.push(src);
//cout<<po.top()<<"r"<<endl;
int j=0;
while(!po.empty())
{
    int x=po.top();
    path[src][i][j]=x;
    j++;
    po.pop();
}

}

//cost[src][dest]=dist[dest];


//while(path[src][dest][i]!=-1){
//    cout<<path[src][dest][i++]<<" ";
//}
return dist[dest];

}


void dijkstraa(int src,int dest,int c)
{

                    cars[c][2]=dest;
                    if(cars[c][0]!=src)
                    {
                        int i=0;
                        while(path[cars[c][0]][src][i+1]!=-1)
                        {
                            Sleep(graph[path[cars[c][0]][src][i]][path[cars[c][0]][src][i+1]]*(pow(10,3)));
                            cars[c][0]=path[cars[c][0]][src][i+1];

                            i++;
                        }
                    }

                    if(path[src][dest][1]==-1)
                        {
                        int u=dijkstra(src,dest);
                        }

                        int i=0;
                        while(path[src][dest][i+1]!=-1)
                        {




                            Sleep(graph[path[src][dest][i]][path[src][dest][i+1]]*(pow(10,3)));
                            cars[c][0]=path[src][dest][i+1];
                            i++;
                        }


                            cars[c][1]--;
                            cars[c][2]=-1;


//                else if(cars[c][1]==2)
//                    {
//
//
//                        if(cost[cars[c][0]][cars[c][2]]>cost[cars[c][0]][dest])
//                        {
//                            int i=0;
//                            while(path[cars[c][0]][dest][i+1]]!=-1)
//                            {
//                                Sleep(graph[path[cars[c][0]][dest][i]][path[cars[c][0]][dest][i+1]]);
//                                cars[c][0]=path[src][dest][i+1]];
//                                i++;
//                            }
//                            cars[c][1]--;
//
//
//      }
//
//      if(cost[dest][cars[c][2]]==0){
//        int u=dijkstra(dest,cars[c][2]);
//      }
//
//
//
//            int i=0;
//          while(path[dest][cars[c][2]][i+1]]!=-1)
//          {
//              Sleep(graph[path[dest][cars[c][2]][i]][path[dest][cars[c][2]][i+1]]);
//               cars[c][0]=path[dest][cars[c][2]][i+1]];
//                i++;
//          }
//          cars[c][1]--;
//
//      }
//
//
//
//
//
//
//}
}

int c(int i){
    int ci=cars[i][1];
        if(cars[i][1]==0){

        cars[i][1]++;
    }
    return ci;
}

int findcar(int a1, int a2,int cars[V][3]){
    for(int i=0;i<V;i++){
            if(cost[cars[i][0]][a1]!=-1)
            {
                int y=dijkstra(cars[i][0],a1);
            }
        if(cost[cars[i][0]][a1]<=40){
            if(c(i)==0){
                     return i;


            }

        }
    }

    return -1;


}

int main(){

    cout<<"                            WELCOME TO INDIA'S CAB SERVICE                  \n";
    int i,j;
    for( i=0;i<M;i++)
    for(j=0;j<M;j++)
      for(int k=0;k<M;k++)
       path[i][j][k]=-1;


    for(i=0;i<M;i++){
        for( j=0;j<M;j++){
            cost[i][j]=0;
        }
    }
    map<string,int> m;
    m.insert(pair<string, int>("GIP_Sector_18", 0));
    m.insert(pair<string, int>("DLF_Sector_18", 1));
    m.insert(pair<string, int>("ATTA_Sector_18", 2));
    m.insert(pair<string, int>("WAVE_Sector_18", 3));
    m.insert(pair<string, int>("JIIT_Sector_128", 4));

    map<int,string> mp;
    mp.insert(pair<int,string>(0, "GIP_Sector_18"));
    mp.insert(pair<int,string>(1, "DLF_Sector_18"));
    mp.insert(pair<int,string>(2, "ATTA_Sector_18"));
    mp.insert(pair<int,string>(3, "WAVE_Sector_18"));
    mp.insert(pair<int,string>(4, "JIIT_Sector_128"));

vector<thread> th4;
int b=1;
while(b!=-1)
    {
        cout<<"\nCurrent cab locations: "<<endl;
        for(int i=0;i<M;i++){
            cout<<i<<" : "<<(mp.find(cars[i][0]))->second;
            if(cars[i][2]!=-1){
                cout<<"(Booked)";
            }
            cout<<endl;
        }
        cout<<endl;
     string ps,pd;
     cout<<"Pickup Location: ";
     cin>>ps;
     cout<<"Drop Location: ";
     cin>>pd;
     cout<<endl;
     int c = findcar((m.find(ps))->second,(m.find(pd))->second,cars);

     if(c==-1)
        {

            cout<<"Cab Not Available for user"<<endl;
        }
        else
        {
            cout<<"Cab for user is booked:"<<c<<endl;
            if(path[(m.find(ps))->second][(m.find(pd))->second][1]==-1){
                int u=dijkstra((m.find(ps))->second,(m.find(pd))->second);
            }
            cout<<"Your path is:";
            int k=0;
            while(path[(m.find(ps))->second][(m.find(pd))->second][k]!=-1){
                cout<<" "<<mp.find(path[(m.find(ps))->second][(m.find(pd))->second][k++])->second<<"->";
            }
            cout<<"END"<<endl;
            cout<<"Fare: "<<5*(cost[(m.find(ps))->second][(m.find(pd))->second])<<endl;

            th4.push_back(std::thread(dijkstraa,(m.find(ps))->second,(m.find(pd))->second,c));
        }


        cout<<"\nPRESS 1 TO BOOK MORE CABS \nPRESS -1 TO EXIT\n"<<endl;
        cin>>b;
    }



    for (thread &t : th4) {
        t.join();
    }


    return 0;

}
