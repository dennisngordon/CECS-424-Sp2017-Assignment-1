//title: quick sort in c
//by: dennis gordon
//assignment: lab 1, 2/13/17
#include <stdio.h>

void qsort(int *a, int n); // quick sort array a with n elements in place in C (from assignment)
void swap(int *a, int *b);// function to swap elements
void print(int *a);// printer function for the array

int arrayLength;

int main()
{
	//write a simple main function to test your sort functions with the input
	//sequence: 4, 65, 2, -31, 0, 99, 2, 83, 782, 1 and print result to console
	arrayLength = 10;
	int a[] ={ 4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
	//fill a[] with the elements as described in the lab handout
	printf("unsorted: ");
	//printing original array to make sure everything is working
	print(a);
	//calling qsort on the array to perform the sorting algorithm
	qsort(a, arrayLength);
	//print sorted array
	printf("\nsorted: ");
	print(a);
	return 0;
}

void qsort(int *a, int n)
{
	//quicksort algorithm
	if(n < 2) //an array of one element in implicitly sorted
		return;
	int pivot = a[n/2];//selecting a pivot element in the middle of the array
	int *l = a;//find element of left side of array
	int *r = a + n - 1;//find element of right side of array
	while(l <= r)
	{
		if(*l < pivot)//iterate through array until a number greater than pivot is found
			l++;
		else if (*r > pivot) //reverse iterate from right side until item less than pivot is found
			r--;
		else
		{
			swap(l,r);//now swap elements
			l++;
			r--;
		}	
	}
	//now make recursive calls until the entire list is sorted
	qsort(a, r - a + 1);
	qsort(l, a + n - l);
}

void swap(int *a, int *b)
{
	//simple swap algorithm... no explination needed i hope
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int *a)
{
	//again simple printer function, not much to explain
	int i;
	printf("[");
	for(i = 0; i < arrayLength; i++)
	{
		printf("%d", *(a + i));
		if(i<arrayLength-1)
			printf(", ");
	}
	printf("]");
}