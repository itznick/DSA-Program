#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 100

void printArray(int *A, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d, ", A[i]);
	}
	printf("\n");
}

void merge(int A[], int mid, int low, int high){
	int B[SIZE], i, j, k;
	i=low;
	j=mid+1;
	k=low;

	while(i<=mid && j<=high){
		if(A[i] < A[j]){
			B[k]=A[i];
			i++;
			k++;
		}
		else{
			B[k]=A[j];
			j++;
			k++;
		}
	}
	while(i <= mid){
		B[k]=A[i];
		i++;
		k++;
	}
	while(j <= high){
		B[k]=A[j];
		j++;
		k++;
	}
	for(i=low; i<=high; i++){
		A[i] = B[i];
	}
}

void mergeSort(int A[], int low, int high){
	int mid;
	if(low < high){
		mid = (low+high)/2;
		mergeSort(A, low, mid);
		mergeSort(A, mid+1, high);
		merge(A, mid, low, high);
	}
}

int main(){
	int A[SIZE],i, n;
	clrscr();

	printf("Enter array size: ");
	scanf("%d", &n);

	printf("\nEnter array elements: ");
	for(i=0; i<n; i++){
		scanf("%d", &A[i]);
	}

	printArray(A, n);
	mergeSort(A, 0, n-1);
	printArray(A, n);

	getch();
	return 0;
}












