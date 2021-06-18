#include<stdio.h>
static int comp=0;
static int x=7;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high,int comp)
{
int n = sizeof(arr)/sizeof(arr[0]);
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
	{
	    printf("\nj = %d",j);
if (arr[j] < pivot)
		{
		    	    printf("\n\tarr[%d]<pivot||%d < %d",j,arr[j],pivot);

			i++;
			swap(& arr[i], &arr[j]);
			printf("\n\t\tswap(%d , %d)",arr[i],arr[j]);
			printArray(arr,6);
			comp++;
            printf("\n");
comp++;
			}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
	    printf("\nlow<high||%d < %d",low,high);
		int pi = partition(arr, low, high,comp);
		comp++;
        quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void printArray(int arr[], int size)
{
	int i;
	printf("\t");
	comp++;
	for (i=0; i < size; i++)
        {
		printf("%d ", arr[i]);
		comp++;
        }
	printf("\n");
}
int main()
{
	int arr[] ={6,5,4,3,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("unSorted array:");
	comp++;
	printArray(arr, n);
	quickSort(arr, 0, n-1);
	printf("\nSorted array:");
	comp++;
	printArray(arr, n);
	printf("\n\nComparision : %d",comp);
	return 0;
}
