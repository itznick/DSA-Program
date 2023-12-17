#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_SIZE 5

struct CircularQueue{
	int A[MAX_SIZE];
	int front, rear;
};

void initializeQueue(struct CircularQueue *queue){
	queue->front = -1;
	queue->rear = -1;
}

int isempty(struct CircularQueue *queue){
	return (queue->front == -1 && queue->rear == -1);
}

int isfull(struct CircularQueue *queue){
	return ((queue->rear+1) % MAX_SIZE == queue->front);
}

void enqueue(struct CircularQueue *queue, int data){
	if(isfull(queue)){
		printf("Queue is full. Cannot enqueue\n");
		return;
	}

	if(isempty(queue)){
		queue->front = 0;
		queue->rear = 0;
	}
	else{
		queue->rear = (queue->rear+1) % MAX_SIZE;
	}

	queue -> A[queue->rear] = data;
	printf("%d Enqueued Successfully\n", data);
}

void dequeue(struct CircularQueue *queue){
	if(isempty(queue)){
		printf("Queue is empty. Cannot dequeue");
		return;
	}

	printf("%d Dequeued successfully. \n", queue->A[queue->front]);

	if(queue->front == queue->rear){
		initializeQueue(queue);
	}
	else{
		queue->front = (queue->front+1) % MAX_SIZE;
	}
}

void display(struct CircularQueue *queue){
	int i;
	if(isempty(queue)){
		printf("Queue is empty. \n");
		return;
	}

	printf("\nQueue Elements: ");
	i = queue->front;
	do{
		printf("%d", queue->A[i]);
		i = (i+1) % MAX_SIZE;
	}while(i!=(queue->rear+1) % MAX_SIZE);

	printf("\n");
}

int main(){
	struct CircularQueue myQueue;
	int choice, data;
	clrscr();
	initializeQueue(&myQueue);

	do{
		printf("\nMENU: \n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");

		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1: printf("Enter the element to enqueue: ");
				scanf("%d", &data);
				enqueue(&myQueue, data);
				break;
			case 2: dequeue(&myQueue);
				break;
			case 3: display(&myQueue);
				break;
			case 4: printf("Exiting the program.\n");
				break;
			default: printf("Invalid choice. Please enter a valid option");
		}
	}while(choice!=4);

	getch();
	return 0;
}
