#include <bits/stdc++.h>
using namespace std;
struct Edge
{
  char to;
  int weight;
};
struct Graph
{
  int V;
  map<char, vector<Edge>> adj;
};
map<char, char> prim(Graph g) //V^2 logv
{
  map<char, int> key;
  map<char, bool> inMist;
  map<char, char> parent;
  for (auto u : g.adj)
  {
    key[u.first] = INT_MAX;
    inMist[u.first] = false;
  }
  key[g.adj.begin()->first] = 0;
  for (int i = 0; i < g.V; i++)
  {
    int min_value = INT_MAX;
    char min_key = '\0';
    for (auto u : key)
    {
      if (!inMist[u.first] && u.second < min_value)
      {
        min_value = u.second;
        min_key = u.first;
      }
    }
    if(min_key == '\0')
    {
      break;
    }
    inMist[min_key] = true;
    for (auto u : g.adj[min_key])
    {
      if(!inMist[u.to] && u.weight< key[u.to])
      {
        key[u.to] = u.weight;
        parent[u.to] = min_key;
      }
    }
  }
  return parent;
}
int main()
{
   Graph g;
   g.V = 4;
   g.adj['A'] = {{'B',4},{'C',2}};
   g.adj['B'] = {{'A',4}, {'C',1}, {'D',5}};
   g.adj['C'] = {{'A', 2}, {'B',1}, {'D',8}};
   g.adj['D'] = {{'B',5}, {'C',8}};
        // {'A', 'B', 4},
        // {'A', 'C', 2},
        // {'B', 'C', 1},
        // {'B', 'D', 5},
        // {'C', 'D', 8}
  map<char, char>parent = prim(g);
  for(auto u : parent)
  {
    cout<<u.first<<"---"<<u.second<<endl;
  }
}