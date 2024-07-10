/* Implementation of a BFS traversal*/

#include "main.h"

// transfer this in main.h
typedef struct {
	int size, front, rear;
	Vertex *elements[MAX];
} Queue;

void initializeQueue(Queue *q){
	q->size = 0;
	q->front = -1;
	q->rear = -1;
}

int isEmpty(Queue *q){
	if(q->rear==q->front){
		return 1;
	}
	return 0;
}

int isFull(Queue *q){
	if(q->rear==MAX-1){
		return 1;
	}
	return 0;
}

void enqueue(Queue *q, Vertex *v){
	if(isFull(q)){
		printf("This queue is full.\n");
		return;
	}
	else{
		if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->elements[q->rear] = v;
    q->size++;
	// printf("Enqueued element: %d\n", val);
	}
}

Vertex *dequeue(Queue *q){
	if(isEmpty(q)){
		printf("This queue is empty.\n");
		return NULL;
	}
	else{
		Vertex *v = q->elements[q->front];
    	q->front++;
	    q->size--;
	    if (q->front > q->rear) {
	        q->front = q->rear = -1;
	    }
   		return v;
	}
}

void BFS(Graph *graph, Vertex *start){
	Queue q;
    initializeQueue(&q);

    // Enqueue the source vertex
    start->isVisited = 1;
    enqueue(&q, start);

    // printf("BFS Traversal starting from vertex %s:\n", start->id);
	
	while (!isEmpty(&q)) {
        Vertex *current = dequeue(&q);
        printf("%s ", current->id);

        // Visit all adjacent vertices
        for (int i = 0; i < current->degree; i++) {
            Vertex *adjacent = current->edges[i];
            if (!adjacent->isVisited) {
                adjacent->isVisited = 1;
                enqueue(&q, adjacent);
            }
        }
    }
    printf("\n");
}

void BFSmain(){
	BFS(g, g->vertices[0]);
}
