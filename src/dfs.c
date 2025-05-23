#include "main.h"
void dfs(FILE *fp, Graph *graph, String startVertex) {
    //printf("DFS Initialized!\n");
    fprintf(fp, "\n\n"); // output file formatting
    traverse(fp, getVertexLoc(graph, startVertex));
}

void traverse(FILE *fp, Vertex *startVertex) {
    StackOfVertices *stack = initStackOfVertices();
    pushVertex(stack, startVertex);
	int i;
    while (!isStackEmpty(stack)) {
        Vertex *currVertex = popVertex(stack);

        if (!currVertex->isVisited) {
            // Mark the current vertex as visited
            currVertex->isVisited = 1;
            fprintf(fp, "%s ", currVertex->id);

            // Sort neighbors of current vertex
            Vertex **sortedNeighbors = sortNeighbors(currVertex);

            // Push neighbors to the stack
            for (i = currVertex->degree - 1; i >= 0; i--) {
                if (!sortedNeighbors[i]->isVisited) {
                    pushVertex(stack, sortedNeighbors[i]);
                }
            }

            // Free the allocated memory for sortedNeighbors
            free(sortedNeighbors);
        }
    }

    // Clean up the stack
    freeStackOfVertices(stack);
}

StackOfVertices *initStackOfVertices() {
    StackOfVertices *newStack = malloc(sizeof(StackOfVertices));
    newStack->top = -1;
    newStack->vertices = malloc((MAX * 3) * sizeof(Vertex *));
    newStack->capacity = MAX * 3;  // Store the capacity of the stack
    return newStack;
}

Vertex **sortNeighbors(Vertex *vertex) {
    int degree = vertex->degree;
    Vertex **tempArr = (Vertex **)malloc(degree * sizeof(Vertex *));
    int i,j;

    // Copy the original array of vertex pointers to tempArr
    for (i = 0; i < degree; i++) {
        tempArr[i] = vertex->edges[i];
    }

    // Sort the array using selection sort
    for (i = 0; i < degree - 1; i++) {
        int minIndex = i;
        for (j = i + 1; j < degree; j++) {
            if (strcasecmp(tempArr[j]->id, tempArr[minIndex]->id) < 0) {
                minIndex = j;
            }
        }
        Vertex *temp = tempArr[minIndex];
        tempArr[minIndex] = tempArr[i];
        tempArr[i] = temp;
    }

    return tempArr;
}

void pushVertex(StackOfVertices *stack, Vertex *vertex) {
    if (isStackFull(stack)) {
        printf("Stack overflow on DFS stack\n");
        return;
    }
    stack->vertices[++stack->top] = vertex;
}

Vertex *popVertex(StackOfVertices *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack underflow on DFS stack\n");
        return NULL;
    }
    return stack->vertices[stack->top--];
}

int isStackFull(StackOfVertices *stack) {
    return stack->top == stack->capacity - 1;
}

int isStackEmpty(StackOfVertices *stack) {
    return stack->top == -1;
}

void freeStackOfVertices(StackOfVertices *stack) {
    free(stack);
}
