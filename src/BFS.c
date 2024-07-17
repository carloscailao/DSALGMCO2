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
	if(q->front==-1 && q->rear==-1){
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

Vertex **sortAdjacent(Vertex *vertex){
    int degree = vertex->degree;
    Vertex **tempArr = (Vertex **)malloc(degree * sizeof(Vertex *));
    int i;

    for (i=0; i<degree; i++){
        tempArr[i] = vertex->edges[i];
    }

    for (i=0; i < degree-1; i++){
        int minIndex = i;
        for (int j=i+1; j<degree; j++){
            if (strcasecmp(tempArr[j]->id, tempArr[minIndex]->id) < 0){
                minIndex = j;
            }
        }
        
        Vertex *temp = tempArr[minIndex];
        tempArr[minIndex] = tempArr[i];
        tempArr[i] = temp;
    }
    return tempArr;
}

void BFS(Graph *graph, String start){
	Queue q;
    initializeQueue(&q);
    printf("BFS is initialized\n");

	Vertex *startVertex = getVertexLoc(graph, start);
    // Enqueue the source vertex
    startVertex->isVisited = 1;
    enqueue(&q, startVertex);

     printf("BFS Traversal starting from vertex %s:\n", startVertex->id);
	
	while (!isEmpty(&q)){
        Vertex *current = dequeue(&q);
        
		if(!current->isVisited){
			current->isVisited = 1;
			printf("%s ", current->id);
			
			Vertex **sortedAdjacent = sortAdjacent(current);

	        for (int i = current->degree - 1; i >= 0; i--){
	            //Vertex *adjacent = current->edges[i];
	            if (!sortedAdjacent[i]->isVisited){
	                //adjacent->isVisited = 1;
	                enqueue(&q, sortedAdjacent[i]);
	            }
			}
			free(sortedAdjacent);
        }
    }
    printf("\n");
}
