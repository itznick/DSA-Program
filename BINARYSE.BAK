#include<stdio.h>
#include<conio.h>

int BinarySearch(int A[], int left, int right, int target){
	while(left<=right){
		int mid;
		mid = left+(right-left)/2;
		if(A[mid] == target){
			return mid;
		}
		else if(A[mid]<target){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	return -1;
}

int main(){
	int arr[100], index, target, i, size;
	clrscr();

	printf("Enter the array size: ");
	scanf("%d", &size);

	printf("Enter array elements: ");
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}

	printf("Array elements are: ");
	for(i=0; i<size; i++){
		printf("%d,", arr[i]);
	}

	printf("\nEnter target element: ");
	scanf("%d", &target);

	index = BinarySearch(arr, 0, size-1, target);

	if(index == -1){
		printf("\nTarget not found");
	}
	else{
		printf("\nTarget element found at index: %d", index);
	}

	getch();
	return 0;
}



