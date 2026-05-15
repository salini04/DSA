//BFS TRAVERSAL
#include <stdio.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int visited[MAX_VERTICES] = {0};
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

void resetVisited(int count)
{
    for (int i = 0; i < count; i++)
    {
        visited[i] = 0;
    }
}

void bfs(int startVertex)
{
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    visited[startVertex] = 1;
    queue[rear++] = startVertex;
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        for (int i = 0; i < numVertices; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main()
{
    numVertices = 5;
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    bfs(0); 
    return 0;
}


