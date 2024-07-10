#ifndef main_h
#define main_h

// Libraries here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Definitions here
#define MAX 100
// Type String is a character array
typedef char String[MAX];
struct Vertex;

typedef struct Vertex{
    String id;
    int degree;
    int isVisited;
    struct Vertex *edges[MAX];
} Vertex;

typedef struct {
    int nVertices;
    Vertex *vertices[MAX];
} Graph;

typedef struct {
    int top;
    Vertex vertices[MAX];
} StackOfVertices;

// Insert function prototypes here

//Graph
int isVertexInGraph(Graph *graph, String vertexID);
Vertex *getVertexLoc(Graph *graph, String id);
int getVertexIndex(Graph *graph, String id);
Vertex *initVertex(String id);
Graph *initGraph(FILE *fp);
void printGraph(Graph *graph);

//DFS
void dfs(Graph *graph, String startVertex);

#endif //main_h