#include <bits/stdc++.h>
using namespace std;
int sum = 0;
struct Graph {
    vector<int> vertex;
    vector<pair<int, pair<int, int>>> edge;
};
//(3, (A,B))
//(4,(B,C))

vector<pair<int, int>> prims(Graph G) {
    vector<pair<int, int>> MST;
    int n = G.vertex.size();
    
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1); 

    key[0] = 0; 

    for (int k = 0; k < n; k++) {    
        int u = -1;
        int minKey = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!inMST[j] && key[j] < minKey) {
                minKey = key[j];
                u = j;
            }
        }

        if (u == -1) break;

        inMST[u] = true;
        sum+= key[u];
        if (parent[u] != -1) {
            MST.push_back({parent[u], u});
        }
        for (int i = 0; i < G.edge.size(); i++) {
            int weight = G.edge[i].first;
            int u_node = G.edge[i].second.first;
            int v_node = G.edge[i].second.second;

            if (u_node == u && !inMST[v_node] && weight < key[v_node]) {
                key[v_node] = weight;
                parent[v_node] = u; 
            } 
            else if (v_node == u && !inMST[u_node] && weight < key[u_node]) {
                key[u_node] = weight;
                parent[u_node] = u; 
            }
        }
    }

    return MST;
}

int main() {
    vector<int> v = {0, 1, 2, 3, 4, 5};
    vector<pair<int, pair<int, int>>> edges = {
        {4, {0, 1}}, // A–B 4
        {2, {0, 2}}, // A–C 2
        {7, {0, 3}}, // A–D 7
        {1, {1, 2}}, // B–C 1
        {5, {1, 3}}, // B–D 5
        {8, {1, 4}}, // B–E 8
        {3, {2, 3}}, // C–D 3
        {6, {2, 4}}, // C–E 6
        {2, {3, 4}}, // D–E 2
        {4, {3, 5}}, // D–F 4
        {3, {4, 5}}  // E–F 3
    };

    Graph g;
    g.vertex = v;
    g.edge = edges;

    vector<pair<int, int>> res = prims(g);
    map<int,char>mp;
    mp[0] = 'A';
    mp[1] = 'B';
    mp[2] = 'C';
    mp[3] = 'D';
    mp[4] = 'E';
    mp[5] = 'F';
    cout << "Edges in MST:\n";
    for (auto e : res) {
        cout << mp[e.first] << " - " << mp[e.second] << "\n";
    }
    cout<<sum;

    return 0;
}