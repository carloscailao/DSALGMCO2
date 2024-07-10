/*
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
        for (int i = 0; i < graph->vertices[startVertexIndex].degree; i++) { // per adjacent vertex 
            if (!graph->vertices[startVertexIndex].edges[i]->isVisited) {
                
            }
        }
        nVisited++;
    }
}

StackOfVertices initStackOfVertices() {
    StackOfVertices newStack;
    newStack.top = 0;
    newStack.vertices;
    for (int i = 0; i < MAX; i++) {
        newStack.vertices[i] = malloc(sizeof(Vertex));
        // this where i left off
    }
    return newStack;
}

void pushVertex(StackOfVertices stack, Vertex vertex) {

}
*/