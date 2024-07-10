#include "main.h"

void dfs(Graph *graph, String startVertex) {
    printf("DFS Initialized!\n");
    int startVertexIndex = getVertexIndex(graph, startVertex);
    int nVisited = 0;
    printf("nVertices: %d\n", graph->nVertices);
    while (nVisited < graph->nVertices) { // while not all vertices are visited
        printf("Visiting vertex %d ", startVertexIndex);
        printf("%s ", graph->vertices[startVertexIndex]->id);
        graph->vertices[startVertexIndex]->isVisited = 1;
        for (int i = 0; i < graph->vertices[startVertexIndex]->degree; i++) { // per adjacent vertex 
            if (!graph->vertices[startVertexIndex]->edges[i]->isVisited) {
                
            }
        }
        nVisited++;
    }
}

StackOfVertices *initStackOfVertices() {
    StackOfVertices *newStack = malloc(sizeof(StackOfVertices));
    newStack->top = -1;
    for (int i = 0; i < MAX; i++) {
        newStack->vertices[i] = NULL; // Initialize all stack elements to NULL
    }
    return newStack;
}

void pushVertex(StackOfVertices *stack, Vertex *vertex) {
    if (isStackFull(stack)) {
        printf("Stack overflow on DFS stack\n");
        return;
    }
    stack->top++;
    stack->vertices[stack->top] = vertex;
    printf("%s pushed at stack top [%d]", vertex->id, stack->top);
}

Vertex *popVertex(StackOfVertices *stack) {
    Vertex *emptyVertex = malloc(sizeof(Vertex));
    emptyVertex = initVertex("emptyStack", 0);
    if(isStackEmpty(stack)) {
        printf("Stack underflow on DFS stack\n");
        return emptyVertex;
    }
    return stack->vertices[stack->top];
}

int isStackFull(StackOfVertices *stack) {
    if (stack->top == MAX - 1) {
        return 1;
    }
    return 0;
}

int isStackEmpty(StackOfVertices *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}