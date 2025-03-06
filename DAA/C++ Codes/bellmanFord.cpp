 #include <iostream>
#include <climits> // For INT_MAX

using namespace std;

// Global variables
int n, m, src;
int edges[100][3]; // Assuming a maximum of 100 edges
int dist[100];     // Assuming a maximum of 100 vertices

// Function to implement the Bellman-Ford algorithm
void bellmanFord() {
    // Step 1: Initialize distances from source to all other vertices as infinite
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0; // Distance from source to itself is 0

    // Step 2: Relax all edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0]; // Source vertex
            int v = edges[j][1]; // Destination vertex
            int wt = edges[j][2]; // Weight of the edge

            // Relaxation step
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    bool hasNegativeCycle = false;
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            hasNegativeCycle = true;
            break;
        }
    }

    // Print all distances from the source vertex
    if (!hasNegativeCycle) {
        cout << "Vertex\tDistance from Source (" << src << ")\n";
        for (int i = 1; i <= n; i++) {
            cout << i << "\t\t" << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
        }
    } else {
        cout << "Negative weight cycle detected." << endl;
    }
}

int main() {
    // Input for number of vertices and edges
    cout << "Number of vertices (n): ";
    cin >> n;
    cout << "Number of edges (m): ";
    cin >> m;
    cout << "Source vertex: ";
    cin >> src;

    // Input edges
    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    // Call the Bellman-Ford algorithm
    bellmanFord();

    return 0;
}