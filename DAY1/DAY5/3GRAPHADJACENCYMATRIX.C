// GRAPH ADJacency matrix
#include <stdio.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices = 0;
void addEdge(int u, int v)
{
    if (u >= numVertices || v >= numVertices)
    {
        printf("Error: Vertex number out of range.\n");
        return;
    }
    graph[u][v] = 1;
    graph[v][u] = 1;
}
void displayGraph()
{
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < numVertices; i++)
    {
        for (j = 0; j < numVertices; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    numVertices = 5; 
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    displayGraph();
    return 0;
}
