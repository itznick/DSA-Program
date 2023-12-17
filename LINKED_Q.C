#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Queue{
	struct Node *front, *rear;
};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct Queue* createQueue(){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->front = queue->rear = NULL;
	return queue;
}

int isEmpty(struct Queue* queue){
	return (queue->front == NULL);
}

void enqueue(struct Queue* queue, int data){
	struct Node* newNode = createNode(data);
	if(isEmpty(queue)){
		queue->front = queue->rear = newNode;
	}
	else{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	printf("%d Enqueued to the queue", data);
}

int dequeue(struct Queue* queue){
	int data;
	struct Node *temp;
	if(isEmpty(queue)){
		printf("Queue is empty. Unable to dequeue.\n");
		return -1;
	}

	temp = queue->front;
	data = temp->data;
	queue->front = queue->front->next;
	free(temp);
	return data;
}

void display(struct Queue* queue){
	struct Node *temp;
	if(isEmpty(queue)){
		printf("Queue is empty.\n");
		return;
	}
	temp = queue->front;
	printf("\nElements in the queue are: ");
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}

int main(){
	struct Queue* queue = createQueue();
	int choice, data;
	clrscr();
	while(1){
		printf("\n\n--- Queue Menu ---\n");
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("4. Exit\n");

		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1: printf("Enter the element to enqueue: ");
				scanf("%d", &data);
				enqueue(queue, data);
				break;
			case 2: data = dequeue(queue);
				if(data != -1){
					printf("%d dequeued from the queue.\n", data);
				}
				break;
			case 3: display(queue);
				break;
			case 4: printf("Exiting..\n");
				exit(0);
			default: printf("Invalid Choice.Please try again.\n");
		}
	}

	return 0;
}