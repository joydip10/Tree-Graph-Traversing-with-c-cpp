#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define mx 1000

typedef pair<int, int> destcost; ///destinition and cost the two intiger

 vector <destcost> vec[mx];

 struct node
 {
     int inputnode;
     int cost;
 };

 ///bool use for sorting

 bool operator < (node agerta, node porerta)
 {
     return agerta.cost>porerta.cost;
 }

 priority_queue<node>pq;

 int cost[mx];
 int taken[mx];

int vertex, edge;

  int primsalgo(int source)
  {
      for(int i = 0 ; i < vertex ; i++ )
    {
        cost[i] = INT_MAX;
        taken[i] = false;
    }
    cost[source] = 0;
    node temp;
    temp.inputnode = source;
    temp.cost = 0;
    pq.push(temp);
    int ans = 0;

    while(!pq.empty())
    {

        node current = pq.top();
        pq.pop();
        //cout << current.u << " " << current.cost << endl;

        if(taken[current.inputnode])
        {
            ///already taken
            continue;
        }

        taken[current.inputnode] = true;

        ans = ans + current.cost;





        for(int i = 0 ; i < vec[current.inputnode].size() ; i++)
        {
            if(taken[vec[current.inputnode][i].first])
            {
                continue;
            }

            if(vec[current.inputnode][i].second < cost[vec[current.inputnode][i].first])
            {

                node temp2;
                temp2.inputnode = vec[current.inputnode][i].first;
                temp2.cost = vec[current.inputnode][i].second;
                pq.push(temp2);
                cost[vec[current.inputnode][i].first] = vec[current.inputnode][i].second;

            }

        }
    }

    return ans;
}


void printGraph()
{
    for(int i = 0 ; i < vertex ; i++)
    {
        cout << i << " -- ";
        for(int j = 0 ; j < vec[i].size() ; j++)
        {
            cout << vec[i][j].first << "-" << vec[i][j].second << "  ";
        }
        cout <<endl;
    }
    cout <<endl;

}


int main()
{
    cin >> vertex >> edge;

    for(int i = 0 ; i < edge ; i++)
    {
        int source;// , dest , cost;
        destcost p;
        cin >> source >> p.first >> p.second;
        vec[source].push_back(p);
        int source2 = p.first;
        p.first = source;
        vec[source2].push_back(p);
    }
    printGraph();
    cout << "MST IS " << primsalgo(0) << endl;

}
