#ifndef main_h
#define main_h

// Libraries here
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// maximum vertices and edges per vertex is 100
#define MAX 100
// maximum characters in a user input field
#define MAX_CHAR 50

// Type String is a dynamically memory allocated character array
typedef char *String;
// Type inputField is statically allocated to 50 chars
typedef char inputField[MAX_CHAR];
struct Vertex;

typedef struct Vertex{
    String id;
    int degree;
    int isVisited;
    struct Vertex **edges;
} Vertex;

typedef struct {
    int nVertices;
    Vertex **vertices;
} Graph;

typedef struct {
    int top;
    Vertex *vertices[MAX];
} StackOfVertices;

// Insert function prototypes here

//Graph
int isVertexInGraph(Graph *graph, String vertexID);
Vertex *getVertexLoc(Graph *graph, String id);
int getVertexIndex(Graph *graph, String id);
Vertex *initVertex(String id, int degree);
Graph *initGraph(FILE *fp);
void printGraph(Graph *graph);

//DFS
void dfs(Graph *graph, String startVertex);
void pushVertex(StackOfVertices *stack, Vertex *vertex);
Vertex *popVertex(StackOfVertices *stack);
int isStackFull(StackOfVertices *stack);
int isStackEmpty(StackOfVertices *stack);

#endif //main_h