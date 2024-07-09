#ifndef main_h
#define main_h

// Libraries here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definitions here
#define MAX 100
// Type String is a character array
typedef char String[MAX];
struct Vertex;

typedef struct Vertex{
    String id;
    int degree;
    struct Vertex *edges[MAX];
} Vertex;

typedef struct {
    int nVertices;
    Vertex vertices[MAX];
} Graph;

// Insert function prototypes here

//Helpers
int getInput();

//Graph
Vertex *getVertexLoc(Graph *graph, String id);
Vertex getVertex(Graph graph, String id);
Vertex initVertex(String id);
Graph *initGraph(FILE *fp);

#endif //main_h