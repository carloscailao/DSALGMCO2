/*
Graph implementation functions go here
*/
#include "main.h"

int isVertexInGraph(Graph *graph, String vertexID) {
    for (int i = 0; i < graph->nVertices; i++) {
        if (strcasecmp(graph->vertices[i]->id, vertexID) == 0) {
            return 1;
        }
    }
    return 0;
}

Vertex *getVertexLoc(Graph *graph, String id) {
    int i;
    for (i = 0; i < graph->nVertices; i++) {
        if (strcmp(id, graph->vertices[i]->id) == 0) {
            return graph->vertices[i];
        }
    }
    return NULL;
}

int getVertexIndex(Graph *graph, String id) {
    for (int i = 0; i < graph->nVertices; i++) {
        printf("Comparing %s with %s\n", graph->vertices[i]->id, id);
        if (strcasecmp(graph->vertices[i]->id, id) == 0) {
            return i;
        }
    }
    return -1;
}

Vertex *initVertex(String id, int degree) {
    Vertex *newVertex = malloc(sizeof(Vertex));
    newVertex->id = malloc(strlen(id) + 1);
    strcpy(newVertex->id, id);
    newVertex->degree = degree;
    newVertex->isVisited = 0;
    newVertex->edges = malloc(degree * sizeof(Vertex *));
    for (int i = 0; i < degree; i++) {
        newVertex->edges[i] = NULL;
    }
    return newVertex;
}

Graph *initGraph(FILE *fp) {
    int nVertices = 0;
    int row = 0;
    int nAdjacency = 0;
    int tempDegree = 0;
    inputField sourceVertex;
    Vertex *vertexLoc;
    inputField buffer;
    Graph *newGraph = malloc(sizeof(Graph));

    fscanf(fp, "%d", &nVertices); // get nVertices
    newGraph->nVertices = nVertices;
    printf("nVertices initialized to %d\n", newGraph->nVertices);
    newGraph->vertices = malloc(nVertices * sizeof(Vertex *));
    printf("Size of vertex * is %d\n", (int)sizeof(Vertex *));
    printf("Vertices pointer array memory allocated %d\n", nVertices * (int)sizeof(Vertex *));

    // initialize vertices and allocate memory for edges

    for (row = 0; row < nVertices; row++) { // per vertex (per row of input)
        tempDegree = 0;
        printf("Initializing vertices\n");
        fscanf(fp, "%s", sourceVertex); // get token
        printf("%s in sourceVertex\n", sourceVertex);
        while (fscanf(fp, "%s", buffer) == 1 ) { // while row has not ended, parse through vertex
            if (strcmp(buffer, "-1") == 0) {
                break; // End of adjacency list
            }
            // for dynamic allocation of edges based on vertex degree
            tempDegree++;
            printf("Scanned degree of %s is %d\n", sourceVertex, tempDegree);
        }
        newGraph->vertices[row] = initVertex(sourceVertex, tempDegree);
        printf("Vertex %s initialized in graph vertices[%d]\n", sourceVertex, row);
    }

    fseek(fp, 1, SEEK_SET); // return to start of vertices (offset by 1 for nVertices)

    // allocate memory for edges based on degree
    for (row = 0; row < nVertices; row++) {
        if (newGraph->vertices[row]->degree > 0) { // if vertex has edges
            newGraph->vertices[row]->edges = malloc(newGraph->vertices[row]->degree * sizeof(Vertex *));
            // allocate memory for vertex pointers in edges
        }
    }

    // initialize adjacencies

    for (row = 0; row < nVertices; row++) { // per row
        printf("Analyzing adjacency\n");
        fscanf(fp, "%s", buffer); // read through source vertex
        printf("%s in buffer\n", buffer);
        for (nAdjacency = 0; nAdjacency < newGraph->vertices[row]->degree; nAdjacency++) {
            if (strcmp(buffer, "-1") == 0) {
                break; // End of adjacency list
            }
            vertexLoc = getVertexLoc(newGraph, buffer);
            if (vertexLoc != NULL) {
                newGraph->vertices[row]->edges[nAdjacency] = vertexLoc;
            }
       }
    }

    return newGraph;
}

void printGraph(Graph *graph) {
    int i, j;
    printf("Printing graph!\n");
    for (i = 0; i < graph->nVertices; i++) { // per vertex
        printf("Source vertex: %s is adjacent to: ", graph->vertices[i]->id);
        for (j = 0; j < graph->vertices[i]->degree; j++) { // per edge of vertex
            if (graph->vertices[i]->edges[j] != NULL) {
                printf("%s, ", graph->vertices[i]->edges[j]->id);
            }
        }
        printf("\n");
    }
}