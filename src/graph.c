/*
Graph implementation functions go here
*/
#include "main.h"

Vertex *getVertexLoc(Graph graph, String id) {
    int i;
    for (i = 0; i < graph.nVertices; i++) {
        if (strcmp(id, graph.vertices[i].id) == 0) {
            return &graph.vertices[i];
        }
    }
}

Vertex getVertex(Graph graph, String id) {
    int i;
    for(i = 0; i < graph.nVertices; i++) {
        if (strcmp(id, graph.vertices[i].id) == 0) {
            return graph.vertices[i];
        }
    }
}

Vertex initVertex(String id) {
    Vertex newVertex;
    strcpy(newVertex.id, id);
    newVertex.degree = 0;
    return newVertex;
}

Graph initGraph(FILE *fp) {
    int nVertices = 0;
    int row = 0;
    Vertex *vertexLoc;
    String buffer;
    String sourceVertex;
    Graph newGraph;

    fscanf(fp, "%d", &nVertices); // get nVertices

    for (row = 0; row < nVertices; row++) { // per vertex (per row of input)
        fscanf(fp, "%s", buffer); // get token
        newGraph.vertices[row] = initVertex(buffer); // initialize first vertex of row
    }

    //implement adjacency

    for (row = 0; row < nVertices; row++) { // per row
        fscanf(fp, "%s", sourceVertex); // first vertex is source vertex
        while (strcmp(buffer, "-1") != 0) { // while row has not ended
            fscanf(fp, "%s", buffer); // scan the vertex
            vertexLoc = getVertexLoc(newGraph, buffer); // get vertex location
            // lost in the night :: IMPLEMENT EDGE BETWEEN SOURCE VERTEX AND BUFFER
            
        }
    }

    return newGraph;
}