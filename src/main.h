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
	int size, front, rear, capacity;
	Vertex **elements;
} Queue;

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
void resetVisited(Graph *graph);
void printGraphDegree(FILE *fp, Graph *graph);

//BFS 
int isEmpty(Queue *q);
int isFull(Queue *q);
void enqueue(Queue *q, Vertex *v);
Vertex *dequeue(Queue *q);
Vertex **sortAdjacent(Vertex *vertex);
void BFS(FILE *fp, Graph *graph, String startID,const char *filename);


//DFS
void dfs(FILE *fp, Graph *graph, String startVertex);
void traverse(FILE *fp, Vertex *startVertex);
StackOfVertices *initStackOfVertices();
Vertex **sortNeighbors(Vertex *vertex);
void pushVertex(StackOfVertices *stack, Vertex *vertex);
Vertex *popVertex(StackOfVertices *stack);
int isStackFull(StackOfVertices *stack);
int isStackEmpty(StackOfVertices *stack);
void freeStackOfVertices(StackOfVertices *stack);

#endif //main_h
