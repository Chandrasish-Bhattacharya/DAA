#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Edge
{
    int source, destination, weight;
};
void bellmanFord(int graph[][3], int V, int E, int source)
{
    int distance[V];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;
    distance[source] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
        {
            printf("Graph contains negative-weight cycle.");
            return;
        }
    }
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, distance[i]);
}
int main()
{
    int V = 5;
    int E = 10;
    int graph[][3] = {{0, 1, 6}, {0, 4, 7}, {1, 3, -4}, {1, 2, 4}, {1, 4, 8}, {2, 1, -2}, {3, 2, 7}, {3, 0, 2}, {4, 2, -3}, {4, 3, 9}};
    int source = 0;
    bellmanFord(graph, V, E, source);
    return 0;
}