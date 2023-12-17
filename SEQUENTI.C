#include<stdio.h>
#include<conio.h>

int SequentialSearch(int arr[], int n, int target){
	int i;
	for(i=0; i<n; i++){
		if(arr[i] == target){
			return i;
		}
	}
	return -1;
}

int main(){
	int arr[] = {1, 3 , 5, 7, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int target = 5;

	int index = SequentialSearch(arr, n, target);

	clrscr();

	if(index == -1){
		printf("Target not found");
	}
	else{
		printf("Target found at index: %d", index);
	}

	getch();
	return 0;
}
