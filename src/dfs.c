#include "main.h"

void dfs(Graph *graph, String startVertex) {
    printf("DFS Initialized!\n");
    int startVertexIndex = getVertexIndex(*graph, startVertex);
    int nVisited = 0;
    printf("nVertices: %d\n", graph->nVertices);
    while (nVisited < graph->nVertices) { // while not all vertices are visited
        printf("Visiting vertex %d ", startVertexIndex);
        printf("%s ", graph->vertices[startVertexIndex].id);
        graph->vertices[startVertexIndex].isVisited = 1;
        nVisited++;
    }
}