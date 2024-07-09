#include "main.h"
#include "graph.c"
#include "helpers.c"

int main (void) {
    String filename;
    String startVertex;
    
    printf("Input filename: ");
    scanf("%99s", filename);
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s not found.", filename);
        exit(1);
    }

    Graph *graph = initGraph(fp);
    fclose(fp);

    printGraph(*graph);

    printf("Input start vertex for the traversal: ");
    scanf("%s", startVertex);
    if (!isVertexInGraph(graph, startVertex)) {
        printf("Vertex %s not found.", startVertex);
        exit(1);
    }

    // traversals here

    free(graph);

    return 0;
}