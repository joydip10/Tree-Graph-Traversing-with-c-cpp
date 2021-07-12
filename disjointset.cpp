#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>

using namespace std;

#define mx 1000

int parent[mx];
int rankparent[mx];

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

void printset(int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<"Node is"<<i<<" parent is" <<parent[i]<<"rank is"<<rankparent[i]<<endl;
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    initialize(n);

    unionset(0,1);
    unionset(4,2);
    unionset(3,1);
    unionset(0,3);
    unionset(0,4);

    printset(n);
}
