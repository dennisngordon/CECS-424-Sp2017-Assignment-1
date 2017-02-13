//title: merge sort in c
//by: dennis gordon
//assignment: lab 1, 2/13/17
#include <stdio.h>

void msort(int *a, int n); // merge sort array a with n elements in place in C (from assignment)
void merge(int *a, int a_length, int *b, int b_length, int *c);// function to merge sorted arrays
void print(int *a);// printer function for the array

int arrayLength;

int main()
{
	//write a simple main function to test your sort functions with the input
	//sequence: 4, 65, 2, -31, 0, 99, 2, 83, 782, 1 and print result to console
	arrayLength = 10;
	int a[] ={ 4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
	
	printf("unsorted: ");
	print(a);
	msort(a, arrayLength);
	printf("\nsorted: ");
	print(a);
	return 0;
}

void msort(int *a, int n)
{
	//merge sort algorithm
	int i;
	int *a1, *a2;//need to divide a into two arrays a1 and a2
	if(n < 2) //array of one element is sorted
		return;
	int n1 = n / 2;//calculate length of the first half of the list
	int n2 = n - n1;//find the length of the 2nd half of the list
	a1 = (int*)malloc(sizeof(int) * n1);//allocating memory for the first half of list based on size of ints
	a2 = (int*)malloc(sizeof(int) * n2);//doing the same thing for the rest of the elements in the list 
	
	//move the first half of a into a1
	for(i = 0; i < n1; i++)
		a1[i] = a[i];
	//now move the rest of the elements into a2
	for(i = 0; i < n2; i++)
		a2[i] = a[i + n1];
	
	//performce a recursive call of msort on the first half of the list
	msort(a1, n1);
	//and now recursion on the 2nd half of the list
	msort(a2, n2);
	//now once all elements have been split into arrays of size one, merge them all together into one sorted array
	merge(a1, n1, a2, n2, a);
}

void merge(int *a, int a_length, int *b, int b_length, int *c)
{
	//merge algorithm
	int i = 0;//iterator for first array to be merged
	int j = 0;//iterator for 2nd array to be merged
	int k = 0;//iterator for the final merged and sorted array
	while (i < a_length && j < b_length)//while loop to go through the entire a1 and a2
	{
		if (a[i] <= b[j])//if the eleement in a is smaller than element in b, put it into c
		{
			c[k] = a[i];
			i++;
		}
		else//otherwise put the element from b into c
		{
			c[k] = b[j];
			j++;
		}
		k++;//then move the iterator one spot next in c
	}
	//if all the elements in b are put in c while items still remain in a, merge the remainder of a into c
	while (i < a_length)
	{
		c[k] = a[i];
		i++;
		k++;
	}
	//same goes here, if all of a has been merged into c already, merge the rest of b into c
	while (j < b_length)
	{
		c[k] = b[j];
		j++;
		k++;
	}
}

void print(int *a)
//simple printer function, shouldnt need explination
{
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