/*
Graph implementation functions go here
*/
#include "main.h"

Vertex *getVertexLoc(Graph *graph, String id) {
    int i;
    for (i = 0; i < graph->nVertices; i++) {
        if (strcmp(id, graph->vertices[i].id) == 0) {
            return &graph->vertices[i];
        }
    }
    return NULL;
}

Vertex getVertex(Graph graph, String id) {
    int i;
    for(i = 0; i < graph.nVertices; i++) {
        if (strcmp(id, graph.vertices[i].id) == 0) {
            return graph.vertices[i];
        }
    }
    Vertex emptyVertex = {"", 0, {NULL}}; // return empty vertex if not found
    return emptyVertex;
}

Vertex initVertex(String id) {
    Vertex newVertex;
    strcpy(newVertex.id, id);
    newVertex.degree = 0;
    for (int i = 0; i < MAX; i++) {
        newVertex.edges[i] = NULL;
    }
    return newVertex;
}

Graph *initGraph(FILE *fp) {
    int nVertices = 0;
    int row = 0;
    Vertex *vertexLoc;
    String buffer;
    Graph *newGraph = malloc(sizeof(Graph));

    fscanf(fp, "%d", &nVertices); // get nVertices
    newGraph->nVertices = nVertices;

    // initialize vertices

    for (row = 0; row < nVertices; row++) { // per vertex (per row of input)
        fscanf(fp, "%s", buffer); // get token
        newGraph->vertices[row] = initVertex(buffer); // initialize first vertex of row - this is the source vertex
    }

    // initialize adjacencies

    for (row = 0; row < nVertices; row++) { // per row
        fscanf(fp, "%s", buffer); // read through source vertex
        while (fscanf(fp, "%s", buffer) == 1 && strcmp(buffer, "-1") != 0) { // while row has not ended, scan for vertex
            vertexLoc = getVertexLoc(newGraph, buffer);
            newGraph->vertices[row].edges[newGraph->vertices[row].degree] = vertexLoc;
            newGraph->vertices[row].degree++;
            // at source vertex, access edge based on current degree of vertex, assign adjacent vertexLoc to vertex pointer array edges
            // at the end of the while loop, all addresses of adjacent vertices of source vertex will be in edges array of source vertex
        }
        // at the end of the for loop, all adjacencies of all source vertices will be placed in corresponding edges array of source vertices
    }

    return newGraph;
}