#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a graph
typedef struct Graph {
    int vertices;
    int adj[MAX_VERTICES][MAX_VERTICES];
    int indegree[MAX_VERTICES];
} Graph;

// Function to initialize the graph
void initGraph(Graph *g, int vertices) {
    g->vertices = vertices;
    
    // Initialize adjacency matrix and indegrees
    for (int i = 0; i < vertices; i++) {
        g->indegree[i] = 0;
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Function to add an edge in the graph
void addEdge(Graph *g, int u, int v) {
    g->adj[u][v] = 1;  // Edge from u to v
    g->indegree[v]++;   // Increment indegree of v
}

// Function to perform topological sort using Kahn's Algorithm (BFS-based)
void topologicalSort(Graph *g) {
    int queue[MAX_VERTICES], front = 0, rear = 0;
    int topo[MAX_VERTICES], index = 0;

    // Enqueue all vertices with indegree 0
    for (int i = 0; i < g->vertices; i++) {
        if (g->indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Perform Kahn's algorithm
    while (front != rear) {
        int u = queue[front++];

        // Add u to topological sort result
        topo[index++] = u;

        // For every adjacent vertex v of u
        for (int v = 0; v < g->vertices; v++) {
            if (g->adj[u][v] == 1) {
                // Decrease indegree of v
                g->indegree[v]--;

                // If indegree of v becomes 0, add it to the queue
                if (g->indegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // If topological sort is possible (no cycle)
    if (index == g->vertices) {
        printf("Topological Sort: ");
        for (int i = 0; i < g->vertices; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    } else {
        printf("The graph contains a cycle, topological sort is not possible.\n");
    }
}

int main() {
    Graph g;
    int vertices, edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) where there is an edge u -> v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    // Perform topological sort
    topologicalSort(&g);

    return 0;
}

