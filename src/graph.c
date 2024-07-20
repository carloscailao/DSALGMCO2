/*
Graph implementation functions go here
*/
#include "main.h"

int isVertexInGraph(Graph *graph, String vertexID) 
{
    int i;
	for (i = 0; i < graph->nVertices; i++) {
        if (strcasecmp(graph->vertices[i]->id, vertexID) == 0) {
            return 1;
        }
    }
    return 0;
}

Vertex *getVertexLoc(Graph *graph, String id) {
    int i;
    for (i = 0; i < graph->nVertices; i++) {
        if (strcasecmp(id, graph->vertices[i]->id) == 0) {
            return graph->vertices[i];
        }
    }
    return NULL;
}

int getVertexIndex(Graph *graph, String id) {
    int i;
	for (i = 0; i < graph->nVertices; i++) {
        //printf("Comparing %s with %s\n", graph->vertices[i]->id, id);
        if (strcasecmp(graph->vertices[i]->id, id) == 0) {
            return i;
        }
    }
    return -1;
}

Vertex *initVertex(String id) {
    Vertex *newVertex = malloc(sizeof(Vertex));
    newVertex->id = malloc(strlen(id));
    strcpy(newVertex->id, id);
    newVertex->degree = 0;
    newVertex->isVisited = 0;
    int i;
	for (i = 0; i < MAX; i++) {
        newVertex->edges[i] = NULL;
    }
    return newVertex;
}

Graph *initGraph(FILE *fp) {
    int nVertices = 0;
    int row = 0;
    Vertex *vertexLoc;
    inputField buffer;
    Graph *newGraph = malloc(sizeof(Graph));

    fscanf(fp, "%d", &nVertices); // get nVertices
    newGraph->nVertices = nVertices;

    // initialize vertices

    for (row = 0; row < nVertices; row++) { // per vertex (per row of input)
        fscanf(fp, "%s", buffer); // get token
        newGraph->vertices[row] = initVertex(buffer); // initialize first vertex of row - this is the source vertex
        //printf("Vertex %s has been stored in Graph vertices[%d]\n", buffer, row);
        while (fscanf(fp, "%s", buffer) == 1 ) { // while row has not ended, parse through vertex
            if (strcmp(buffer, "-1") == 0) {
                break; // End of adjacency list
            }
        }
    }

    fseek(fp, 1, SEEK_SET); // return to start of vertices (offset by 1 for nVertices)

    // initialize adjacencies

    for (row = 0; row < nVertices; row++) { // per row
        //printf("Analyzing adjacency\n");
        fscanf(fp, "%s", buffer); // read through source vertex
        //printf("%s in buffer\n", buffer);
        while (fscanf(fp, "%s", buffer) == 1 ) { // while row has not ended, scan for vertex
            if (strcmp(buffer, "-1") == 0) {
                break; // End of adjacency list
            }
            vertexLoc = getVertexLoc(newGraph, buffer);
            if (vertexLoc != NULL) {
                newGraph->vertices[row]->edges[newGraph->vertices[row]->degree] = vertexLoc;
                //printf("%s became adjacent to %s!\n",  newGraph->vertices[row]->id, vertexLoc->id);
                newGraph->vertices[row]->degree++;
                // at source vertex, access edge based on current degree of vertex, assign adjacent vertexLoc to vertex pointer array edges
                // at the end of the while loop, all addresses of adjacent vertices of source vertex will be in edges array of source vertex
            }
        }
        // at the end of the for loop, all adjacencies of all source vertices will be placed in corresponding edges array of source vertices
    }

    return newGraph;
}

void printGraph(Graph *graph) {
    printf("Printing graph!\n");
    int i,j;
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

void resetVisited(Graph *graph) {
	int i;
	for (i = 0; i < graph->nVertices; i++) { // per vertex
		graph->vertices[i]->isVisited = 0; // reset isVisited to 0
	}
}

void printGraphDegree(FILE *fp, Graph *graph) {
    int longestStrlen = 0;

    // First loop to find the longest ID length
    int i;
	for (i = 0; i < graph->nVertices; i++) {
        int len = strlen(graph->vertices[i]->id);
        if (len > longestStrlen) {
            longestStrlen = len;
        }
    }

    // Second loop to print the degrees aligned
	for (i = 0; i < graph->nVertices; i++) {
        fprintf(fp, "%-*s %d\n", longestStrlen, graph->vertices[i]->id, graph->vertices[i]->degree);
    }
}
void generateGraphDotFile(Graph *graph, const char *filename) {
    // Open the DOT file for writing
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Failed to open file");
        return;
    }

    // Write DOT file header
    fprintf(fp, "graph MyGraph {\n");
    fprintf(fp, "  node [shape=box];\n");
	int i,j;
    // Iterate through each vertex and its edges
    for (i = 0; i < graph->nVertices; i++) {
        Vertex *vertex = graph->vertices[i];

        for (j = 0; j < vertex->degree; j++) {
            Vertex *neighbor = vertex->edges[j];
            // Write each edge only once to avoid duplicate edges
            if (strcasecmp(vertex->id, neighbor->id) < 0) {
                fprintf(fp, "  \"%s\" -- \"%s\";\n", vertex->id, neighbor->id);
            }
        }
    }

    // Write DOT file footer
    fprintf(fp, "}\n");
    fclose(fp);

    printf("Graph DOT file \"%s\" has been generated.\n", filename);
}

