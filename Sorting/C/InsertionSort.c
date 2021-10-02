#include <stdio.h>

// function to sort
void insertionSort(int array[], int n) {
  int temp,i,j;

  /* sorting in ascending order */
  //loop starts from 1st index as 0th index is consider as a sorted.
  for(i=1;i<n;i++){ 
	temp=array[i];
	j=i-1;
	//traverse array until we find an index for temp value
	while(j>=0 && array[j]>temp){
		array[j+1]=array[j];
		j--;
	     
	}
	array[j+1]=temp;
  }
}

// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

//main function
int main() {
  int data[] = {2,-4,7,8,4,7}; 
  int n = sizeof(data) / sizeof(data[0]);
  printf("Unsorted Array\n");
  printArray(data, n);
  
  insertionSort(data, n); /* calling the Insertion sort function by passing the array and the size of the array */
  printf("Sorted array in ascending order: \n");
  printArray(data, n);
}
