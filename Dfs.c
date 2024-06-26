#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int currentVertex, int visited[])
{
    printf("%d ", currentVertex);
    visited[currentVertex] = 1;
    for (int i = 0; i < vertices; ++i)
        if (graph[currentVertex][i] == 1 && !visited[i])
            dfs(graph, vertices, i, visited);
}
int main()
{
    int vertices = 5, edges = 4;
    int graph[MAX_VERTICES][MAX_VERTICES] = {{0, 1, 1, 0, 0},
                                             {1, 0, 1, 1, 0},
                                             {1, 1, 0, 0, 1},
                                             {0, 1, 0, 0, 1},
                                             {0, 0, 1, 1, 0}};
    int startVertex = 0;
    int visited[MAX_VERTICES] = {0};
    printf("DFS traversal starting from vertex %d: ", startVertex);
    dfs(graph, vertices, startVertex, visited);

    return 0;
}