#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>

#define white 1
#define gray 2
#define black 3

using namespace std;

int adj[100][100];

int color[1000];

int node,edge;
void dfsvisit(int x)
{
    color[x]=gray;
    cout<<x<<"--";
    ///smoe work
     for (int i=0; i<node; i++)///check neighbour
     {
         if(adj[x][i]==1)
         {
             if(color[i]==white)
             {
                 dfsvisit(i);
             }
         }
     }

}
void dfs()
{
    for (int i=0; i<node; i++)
    {
        color[i]=white;
    }
    for (int i=0; i<node; i++)
    {
        if(color[i]==white)
        {
            dfsvisit(i);
        }
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
     dfs();
}





