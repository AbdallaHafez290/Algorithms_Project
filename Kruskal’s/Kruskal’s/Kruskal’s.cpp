#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int src, dest, weight;
};


bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DisjointSet {
private:
    vector<int> parent, rank;

public:
   
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }

    
    int find(int node) {
        if (node != parent[node]) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            }
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};


void kruskalMST(int numVertices, vector<Edge>& edges) {
   
    sort(edges.begin(), edges.end(), compareEdge);

    
    DisjointSet ds(numVertices);

    
    vector<Edge> mst; 
    int totalWeight = 0;

    for (Edge& edge : edges) {
        int u = edge.src;
        int v = edge.dest;

       
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);      
            totalWeight += edge.weight;
            ds.unionSets(u, v);       
        }
    }

    
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
    cout << "Total weight of the MST: " << totalWeight << endl;
}

int main() {
   

 
    return 0;
}
