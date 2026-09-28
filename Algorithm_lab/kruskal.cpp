#include<bits/stdc++.h>
using namespace std;
struct Edge{
  char u;
  char v;
  int weight;
  bool operator<(const Edge& other) const{
    return weight < other.weight;
  }
};

int find_set(char  v, map<char,char>&parent)
{
  if(v == parent[v])
  {
    return v;
  }
  return find_set(parent[v], parent);
}
bool union_sets(char u , char v, map<char,char> &parent, map<char,int> &rank)
{
  char root_u = find_set(u,parent);
  char root_v = find_set(v,parent);
  if(root_u == root_v)
  {
    return false;
  }
  else if(rank[root_u]>rank[root_v])
  {
    parent[root_v] = root_u;
  }
  else if(rank[root_v]>rank[root_u])
  {
    parent[root_u] = root_v;
  }
  else
  {
    parent[root_u] = root_v;
    rank[root_v]++;
  }
  return true;
}

vector<Edge> kruskal(vector<Edge> edges) //Elog^2V
{
  vector<Edge>mst;
  sort(edges.begin(), edges.end());
  map<char,char>parent;
  map<char, int>rank;
  for(int i = 0 ; i<edges.size(); i++)
  {
    parent[edges[i].u] = edges[i].u;
    parent[edges[i].v] = edges[i].v;
    rank[edges[i].u] = 0;
    rank[edges[i].v] = 0;
  }
 
  for(auto e : edges)
  {
    if(union_sets(e.u,e.v,parent,rank))
    {
      mst.push_back(e);
    }
  }
  return mst;
}

int main()
{
      vector<Edge> edges = {
        {'A', 'B', 4},
        {'A', 'C', 2},
        {'B', 'C', 1},
        {'B', 'D', 5},
        {'C', 'D', 8}
    };
    vector<Edge> mst = kruskal(edges);
    for(auto e : mst)
    {
      cout<<e.u<<"---"<<e.v<<endl;
    }
}