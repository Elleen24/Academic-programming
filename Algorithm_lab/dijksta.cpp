#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

struct Edge {
    char to;
    int weight;
};

struct Graph {
    int V;
    map<char, vector<Edge>> adj;
};

void gg(Graph g, char s) {
    map<char, int> dist;
    map<char, bool> visited;

    
    for (auto u : g.adj) {
        dist[u.first] = INT_MAX;
        visited[u.first] = false;
    }

    dist[s] = 0;

    for (int i = 0; i < g.V; i++) {
        char min_key = '\0';
        int min_dist = INT_MAX;

        for (auto u : dist) {
            if (!visited[u.first] && u.second < min_dist) {
                min_key = u.first;
                min_dist = u.second;
            }
        }

 
        if (min_key == '\0') {
            break;
        }

        visited[min_key] = true;

      
        for (auto v : g.adj[min_key]) {
            if (dist[min_key] != INT_MAX && dist[min_key] + v.weight < dist[v.to]) {
                dist[v.to] = dist[min_key] + v.weight;
            }
        }
    }

    
    for (auto u : dist) {
        if (u.second == INT_MAX) {
            cout << u.first << " ---- INF" << endl;
        } else {
            cout << u.first << " ---- " << u.second << endl;
        }
    }
}
int main() //O(V\log V)+ O(V^2log V)+O(E\log V)+O(V)
{
  Graph g2;
    g2.V = 4;
    g2.adj['S'] = {{'A', 1}, {'B', 4}};
    g2.adj['A'] = {{'B', 2}, {'C', 6}};
    g2.adj['B'] = {{'C', 3}};
    g2.adj['C'] = {};

    gg(g2, 'S');
}
