#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<queue>
#include<algorithm>

#define white 1
#define gray 2
#define black 3

using namespace std;

int adj[100][100];

int color[1000];

int parent[100];
int dis[100];

int node,edge;

void bfs(int startnode)
{
    for(int i=0; i<node; i++)
    {
        color[i]=white;
        dis[i]= INT_MIN;
        parent[i]= -1;

    }
    dis[startnode]=0;
    parent[startnode]=-1;

    queue <int> q;
    q.push(startnode);

    while(!q.empty())
    {
        int x;
        x=q.front();
        q.pop();
        color[x]=gray;
        cout<<x<<"--";
        for(int i=0; i<node; i++)
        {
            if(adj[x][i]==1)
            {
                if(adj[x][i]==white)
                {
                    ///x er neighbour i;
                    ///x no node hocche i no node er parent;
                    dis[i] = dis[x]+1;
                    parent[i]=x;
                    q.push(i);
                }
            }
        }
        color[x]=black;
    }
}

int main()
{
    cin>>node>>edge;

    int n1,n2;
     for (int i=0; i<node; i++)
     {
         cin>>n1>>n2;
         adj[n1][n2]=1;
         adj[n2][n1]=1;
     }
     bfs(0);
     ///distance of 0 no. node to 6 no. node
    //cout<<parent[5]<<endl;
     //cout<<dis[2];

     return 0;
}


