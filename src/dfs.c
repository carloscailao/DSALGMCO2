
#include "main.h"

void dfs(Graph *graph, String startVertex) {
    printf("DFS Initialized!\n");
    traverse(graph, getVertexLoc(graph, startVertex));
}

void traverse(Graph *graph, Vertex *vertex) {
    // Mark the current vertex as visited
    vertex->isVisited = 1;
    printf("%s ", vertex->id);

    // Recur for all the vertices adjacent to this vertex

    // TO DO: COMPARISON OF MULTIPLE NEIGHBORS
    for (int i = 0; i < vertex->degree; i++) {
        if (vertex->edges[i] != NULL && !vertex->edges[i]->isVisited) {
            traverse(graph, vertex->edges[i]);
        }
    }
}
/*
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
    emptyVertex = initVertex("emptyStack");
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
*/