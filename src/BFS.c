/* Implementation of a BFS traversal*/

#include "main.h"

void initializeQueue(Queue *q){
    q->elements = malloc((MAX * 3) * sizeof(Vertex *));
    q->capacity = MAX * 3;
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
	if(q->rear==q->capacity - 1){
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
    int i,j;

    for (i=0; i<degree; i++){
        tempArr[i] = vertex->edges[i];
    }

    for (i=0; i < degree-1; i++){
        int minIndex = i;
        for (j=i+1; j<degree; j++){
            if (strcasecmp(tempArr[j]->id, tempArr[minIndex]->id) < 0){
                minIndex = j;
            }
        }
        
        //printf("SORT minIndex %d\n", minIndex);
        
        Vertex *temp = tempArr[minIndex];
        tempArr[minIndex] = tempArr[i];
        tempArr[i] = temp;
        
        //printf("SORT ID %s\n", temp->id);
    }
    
    /*
    for(i=0; i< degree; i++){
    	printf("[sorting] %s ", tempArr[i]->id);
	}
	printf("\n");
    */
    return tempArr;
}

void BFS(FILE *fp, Graph *graph, String startID) {
    Queue q;
    initializeQueue(&q);
    int i, j;
    
    // Output formatting
    fprintf(fp, "\n"); 

    // Allocate memory for tracking visited vertices
    Vertex **tempVisited = malloc(sizeof(Vertex*) * graph->nVertices);
    if (tempVisited == NULL) {
        perror("Failed to allocate memory for tempVisited");
        return;
    }
    int tempCount = 0;

    // Get the starting vertex
    Vertex *startVertex = getVertexLoc(graph, startID);
    if (startVertex == NULL) {
        fprintf(fp, "Start vertex not found\n");
        free(tempVisited);
        return;
    }

    // Enqueue the starting vertex
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        Vertex *current = dequeue(&q);
        
        if (!current->isVisited) {
            current->isVisited = 1;
            fprintf(fp, "%s ", current->id);

            // Sort the adjacent vertices
            Vertex **sortedAdjacent = sortAdjacent(current);
            if (sortedAdjacent == NULL) {
                perror("Failed to sort adjacent vertices");
                free(tempVisited);
                return;
            }

            // Process each sorted adjacent vertex
            for (i = 0; i < current->degree; i++) {
                Vertex *adj = sortedAdjacent[i];
                if (!adj->isVisited) {
                    enqueue(&q, adj);

                    // Check if the adjacent vertex is already in tempVisited
                    int alreadyExists = 0;
                    for (j = 0; j < tempCount; j++) {
                        if (strcmp(tempVisited[j]->id, adj->id) == 0) {
                            alreadyExists = 1;
                            break;
                        }
                    }

                    if (!alreadyExists) {
                        // Add to tempVisited and write to DOT file
                        tempVisited[tempCount++] = adj;
                    }
                }
            }
            free(sortedAdjacent);
        }
    }
    free(tempVisited);
    //printf("Graph DOT file \"%s\" has been generated.\n", filename);
}

