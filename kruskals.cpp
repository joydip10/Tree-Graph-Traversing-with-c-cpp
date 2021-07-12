#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

#define mx 1000

struct edgestructure
{
    int u, v, w;
};

///for sorting using bool

bool operator < (edgestructure left, edgestructure right)
{
    return left.w < right.w;
}


int parent[mx];
int rankparent[mx];

vector <edgestructure> edgevec;

void initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
        rankparent[i]=0;
    }
}

int findparent(int x)
{
    if(x!=parent[x])
    {
        return parent[x] = findparent (parent[x]);

    }
    else
    {
        return x;
    }
}

void unionset(int x, int y)
{
    int px = findparent(x);
    int py = findparent(y);

    if(px==py) return;
    ///cout<<px<<" "<<py<<endl;

    if (rankparent[px] < rankparent[py])
    {
        parent[px] = py;
    }
    else if (rankparent[px] > rankparent[py])
    {
        parent[py] = px;
    }

    else
    {
        parent[py] = px;
        rankparent[px]++;
    }
}

int kruskal(int n)
{
    initialize(n);

    sort(edgevec.begin(), edgevec.end());

    int sz = edgevec.size();

    int ans = 0;
    for(int i = 0 ; i < sz ; i++)
    {
        if(findparent(edgevec[i].u) != findparent(edgevec[i].v))
        {
            //union
            unionset(parent[edgevec[i].u] , parent[edgevec[i].v]);
            //cout << edgeVector[i].u << " " << edgeVector[i].v << endl;
            ans+=edgevec[i].w;
        }
    }
    //cout << endl;
    return ans;
}


int main()
{
    //freopen("kruskal.txt", "r", stdin);
    int vertex, edge;
    cin >> vertex >> edge;

    for(int i = 0 ; i < edge ; i++)
    {
        edgestructure e;
        cin >> e.u >> e.v >> e.w;
        edgevec.push_back(e);
    }
    //cout << "MST" << endl;
    cout << "MST Cost " << kruskal(vertex) << endl;
}
