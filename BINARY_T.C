#include<stdio.h>
#include<conio.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node*  createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

struct Node* insertNode(struct Node* root, int data){
	if(root == NULL){
		return createNode(data);
	}

	if(data < root->data){
		root->left = insertNode(root->left, data);
	}
	else if(data > root->data){
		root->right = insertNode(root->right, data);
	}
	return root;
}

void preOrderTraversal(struct Node* root){
	if(root!=NULL){
		printf("%d ", root->data);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

void inOrderTraversal(struct Node* root){
	if(root!=NULL){
		inOrderTraversal(root->left);
		printf("%d ", root->data);
		inOrderTraversal(root->right);
	}
}

void postOrderTraversal(struct Node* root){
	if(root!=NULL){
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		printf("%d ", root->data);
	}
}

int main(){
	struct Node* root = NULL;

	clrscr();

	root = insertNode(root, 50);
	root = insertNode(root, 70);
	root = insertNode(root, 30);
	root = insertNode(root, 10);
	root = insertNode(root, 20);

	printf("Pre-Order Traversal: ");
	preOrderTraversal(root);

	printf("\nIn-Order Traversal: ");
	inOrderTraversal(root);

	printf("\nPost_Order Traversals: ");
	postOrderTraversal(root);

	getch();
	return 0;
}