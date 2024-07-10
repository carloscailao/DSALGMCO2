/* Implementation of a BFS traversal*/

struct queue{
	int size;
	int front;
	int rear;
	int* arr;
};

int graph[10][10], visited[10], numVertices;

void initializeQueue(){
	struct queue q;
	q.size = 500;
	q.front = 0;
	q.rear = 0;
	q.arr = (int*) malloc(q.size*sizeof(int));
}

int isEmpty(struct queue *q){
	if(q->rear==q->front){
		return 1;
	}
	return 0;
}

int isFull(struct queue *q){
	if(q->rear==q->size-1){
		return 1;
	}
	return 0;
}

void enqueue(struct queue *q, int val){
	if(isFull(q)){
		printf("This queue is full.\n");
	}
	else{
		q->rear++;
		q->arr[q->rear] = val;
		// printf("Enqueued element: %d\n", val);
	}
}

int dequeue(struct queue *q){
	int a = -1;
	if(isEmpty(q)){
		printf("This queue is empty.\n");
	}
	else{
		q->front++;
		a = q->arr[q->front];
	}
	return a;
}

void BFS(int vertex){
	int j;
	printf("%d ", vertex);
	visited[vertex] = 1;
	
	for(j=0; j<numVertices; j++){
		if(!visited[j] && graph[vertex][j] == 1){
			BFS(j);
		}
	}
}

void unnamedFunction(int sourceNode){
	int i,j;	
	
	/*Adjacency matrix input*/
	for(i=0; i<numVertices; i++){
		for(j=0; j<numVertices; j++){
			// store into graph
			graph[i][j] == ;
		}
	}
	/*
	for(i=0; i<numVertices; i++){
		visited[i] = 0;
	}
	*/
	
	// mark the current node as visited and enqueue it
	visited[sourceNode] = 1;
	enqueue(&q, s);
	
	// iterate over the queue
	while(!isEmpty(&q)){
		// dequeue a vertex from queue and print it
		int node = dequeue(&q);
		printf("%d ", node);
		
		for(int j=0; j<numVertices; j++){
			if(graph[node][j]  && !visited[j]){
				printf("%d ", j);
				visited[j] = 1;
				enqueue(&q, j);
			}
		}
	}
	
	BFS(0);
}
