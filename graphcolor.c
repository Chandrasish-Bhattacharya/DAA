#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int num_vertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
};

void initializeGraph(struct Graph *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, int u, int v) {
    graph->adjacency_matrix[u][v] = 1;
    graph->adjacency_matrix[v][u] = 1; 
}

void graphColoring(struct Graph *graph) {
    int result[MAX_VERTICES];
    int num_vertices = graph->num_vertices;
    for (int u = 0; u < num_vertices; u++)
        result[u] = -1;
    result[0] = 0;
    bool available[num_vertices];
    for (int u = 1; u < num_vertices; u++) {
        for (int color = 0; color < num_vertices; color++) {
            available[color] = true;
        }
        for (int v = 0; v < num_vertices; v++) {
            if (graph->adjacency_matrix[u][v] && result[v] != -1) {
                available[result[v]] = false;
            }
        }
        int cr;
        for (cr = 0; cr < num_vertices; cr++) {
            if (available[cr]) {
                break;
            }
        }
        result[u] = cr;
    }
    printf("Vertex\tColor\n");
    for (int u = 0; u < num_vertices; u++)
        printf("%d\t%d\n", u, result[u]);
}

int main() {
    struct Graph graph;
    int num_vertices, num_edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    initializeGraph(&graph, num_vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the edges (vertex1 vertex2):\n");
    for (int i = 0; i < num_edges; i++) {
        printf("Enter edge number %d : ",i);
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }
    printf("Coloring of the graph using Greedy algorithm:\n");
    graphColoring(&graph);
    return 0;
}
