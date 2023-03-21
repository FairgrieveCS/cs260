#include <iostream>

#define MAX_VERTICES 50
#define INFINITE 999999

class Graph {
private:
    int vertexCount;  // Number of vertices in the graph
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];  // 2D array to store adjacency matrix of the graph

public:
    // Constructor for the class
    Graph() {
        vertexCount = 0;  // Initialize vertexCount to 0
        for (int i = 0; i < MAX_VERTICES; i++) {  // Initialize the adjacency matrix with all 0s (no edges)
            for (int j = 0; j < MAX_VERTICES; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Method to add a new vertex
    void addVertex() {
        if (vertexCount < MAX_VERTICES) {
            vertexCount++;  // Increment vertex count +1
        } else {
            std::cout << "Maximum number of vertices reached" << std::endl;
            return;
        }
    }

    // Method to add an edge between two vertices with a given weight
    void addEdge(int source, int destination, int weight) {
        // CHecking if source and destination are valid vertices
        if (source >= 0 && source < vertexCount && destination >= 0 && destination < vertexCount) {
            // Add the edge to the adjacency matrix
            adjMatrix[source][destination] = weight;
            adjMatrix[destination][source] = weight;
        } else {
            std::cout << "Invalid source or destination vertex" << std::endl;
        }
    }

    // Method to find vertex with the min distance value that hasn't been visited yet
    int minDistance(int dist[], bool visited[]) {
        int min = INFINITE, minIndex;
        for (int i = 0; i < vertexCount; i++) {
            // If the vertex hasn't been visited and the distance is less than current min,
            // update the min distance and the index of the vertex
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    // Method to find shortest path between two vertices using Dijkstra's algorithm
    void shortestPath(int source, int destination) {
        int dist[MAX_VERTICES]; // Array to store the shortest path distances from the source vertex
        bool visited[MAX_VERTICES]; // Array to store whether a vertex has been visited or not

        // Initialize all distances as infinite and visited[] as false
        for (int i = 0; i < vertexCount; i++) {
            dist[i] = INFINITE;
            visited[i] = false;
        }
       
        dist[source] = 0; // Distance of source vertex from itself is always 0

        // Find shortest path for all vertices
        for (int count = 0; count < vertexCount - 1; count++) {
            // Pick the minimum distance vertex from the set of vertices not yet processed.
            // u is always equal to source in the first iteration.
            int u = minDistance(dist, visited);
         
            visited[u] = true; // Mark the picked vertex as processed

            // Update dist[v] only if it is not visited, there is an edge from u to v,
            // and the total weight of path from source to v through u is smaller than current value of dist[v]
            for (int v = 0; v < vertexCount; v++) {
                if (!visited[v] && adjMatrix[u][v] && dist[u] != INFINITE && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        // Print shortest path
        std::cout << "Shortest path from vertex " << source << " to vertex " << destination << ": ";
        if (dist[destination] == INFINITE) {
            std::cout << "No path exists" << std::endl;
        } else {
            std::cout << dist[destination] << std::endl;
        }
    }

    // Function to find the vertex with the minumum key value that has not been included in mst yet
    int minKey(int key[], bool mstSet[]) {
        int min = INFINITE, minIndex;
        // Iterate through all vertices
        for (int i = 0; i < vertexCount; i++) {
          // If the vertex has not been included in the MST and its key is less than the current minimum,
          // update the minimum key and the index of the vertex
            if (!mstSet[i] && key[i] < min) {
                min = key[i];
                minIndex = i;
            }
        }
        return minIndex;  // Returning the index of the vertex with the minimum key value
    }

    // Function to construct and print the Minimum Spanning Tree (MST) using Prim's algorithm
    void minSpanTree() {
        int parent[MAX_VERTICES]; // Array to store the parent of each vertex
        int key[MAX_VERTICES];  // Array to store the key values used to pick minimum weight edge in cut
        bool mstSet[MAX_VERTICES];  // Array to store whether a vertex is included in the MST or not

        // Initialize all keys as infinite and mstSet[] as false
        for (int i = 0; i < vertexCount; i++) {
            key[i] = INFINITE;
            mstSet[i] = false;
        }

        // Always include first vertex in MST
        key[0] = 0;
        parent[0] = -1;

        // Construct MST for all vertices
        for (int count = 0; count < vertexCount - 1; count++) {
            // Pick the minimum key vertex from the set of vertices not yet included in MST
            int u = minKey(key, mstSet);

            // Add the picked vertex to the MST Set
            mstSet[u] = true;

            // Update key and parent for adjacent vertices of the picked vertex.
            // Only consider vertices that are not yet included in MST.
            for (int v = 0; v < vertexCount; v++) {
                // If there is an edge between u and v, v is not in mstSet, and the weight of edge u-v is smaller than key[v],
                // update parent[v] to u and key[v] to the weight of the edge u-v
                if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // Print MST
        std::cout << "Minimum Spanning Tree:" << std::endl;
        for (int i = 1; i < vertexCount; i++) { // Start from the second vertex (i = 1) as the first vertex has no parent
            std::cout << parent[i] << " - " << i << "\tWeight: " << adjMatrix[i][parent[i]] << std::endl;
        }
    }
};

int main() {
    // Create a new Graph object
    Graph g;

    // Test 1: Add 5 vertices to the graph
    for (int i = 0; i < 5; i++) {
        g.addVertex();
    }

    // Test 2: Add edges between vertices with weights
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    // Test 3: the shortestPath method
    g.shortestPath(0, 4); // We expect: Shortest path from vertex 0 to vertex 4: 7

    // Test 4: the minSpanTree method
    g.minSpanTree();
    /* We expect:
        Minimum Spanning Tree:
        0 - 1   Weight: 2
        1 - 2   Weight: 3
        0 - 3   Weight: 6
        1 - 4   Weight: 5
    */

    return 0;
}

