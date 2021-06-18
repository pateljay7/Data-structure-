#include<stdlib.h>
#include<stdio.h>
int com=0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        com++;
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
        com++;
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            com++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            com++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        com++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
        com++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        com++;
        mergeSort(arr, l, m);
        com++;
        mergeSort(arr, m+1, r);
        com++;
        merge(arr, l, m, r);
        com++;
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        printf("%d ", A[i]);
        com++;
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printf("Merge Sort\n\nNumber of elements =  %d",arr_size);
    printf("\n\nUnsorted array is : ");
    com++;
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("\nSorted array is : ");
    printArray(arr, arr_size);
    printf("\nNumber of Comparision in Merge Sort: %d",com);
    printf("\n");

    return 0;
}
