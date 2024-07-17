#ifndef main_h
#define main_h

// Libraries here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Definitions here
#define MAX 100
#define MAX_CHAR 50
// Type String can be dynamically allocated
typedef char *String;
// Type inputField is statically allocated 
typedef char inputField[MAX_CHAR];
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
    Vertex **vertices;
    int capacity;
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
void traverse(Graph *graph, Vertex *startVertex);
StackOfVertices *initStackOfVertices(int nVertices);
Vertex **sortNeighbors(Vertex *vertex);
void pushVertex(StackOfVertices *stack, Vertex *vertex);
Vertex *popVertex(StackOfVertices *stack);
int isStackFull(StackOfVertices *stack);
int isStackEmpty(StackOfVertices *stack);
void freeStackOfVertices(StackOfVertices *stack);

#endif //main_h