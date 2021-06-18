#include<stdio.h>
#include<conio.h>
int c2=0;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    c2+=3;
}
void selection(int arr[],int n)
{
    int min=0,pass=0,c=0,e=0;
    printf("unsorted array ::");
    c2++;
    for(int z=0; z<n; z++)
    {
        printf("\t%d",arr[z]);
        c2++;
    }

    int i, min_idx;

    for (pass = 0; pass < n-1; pass++)
    {
        min_idx = pass;
        c2++;
        for (i = pass+1; i < n; i++)
        {
            if (arr[i] < arr[min_idx])
            {
                min_idx = i;
                c2++;
            }

        }

        int temp;
        temp=arr[pass];
        arr[pass]=arr[min_idx];
        arr[min_idx]=temp;
        c2+=3;

    }



    printf("\n\nsorted array   ::");
    c2++;
    for(int z=0; z<n; z++)
    {
        printf("\t%d",arr[z]);
        c2++;
    }

}
void main()
{
    int arr[]= {1,2,3,4,5,6,7,8,9,10},c1=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    c1++;
    printf("Number of elements are  :: %d\n",n);
    c1++;
    selection(arr,n);
    printf("\nCounter :: %d",c1+c2);
}
