#include<stdio.h>
#include<conio.h>
int c2=0;
void bubble(int arr[],int n)
{
    int i;
    printf("unsorted array");
    c2++;
    for(int z=0; z<n; z++)
    {
        printf("\t%d",arr[z]);
        c2++;
    }


    for(int j=1; j<n; j++)
    {
        int key=arr[j];
        i=j-1;
        c2++;
        while(i>=0&&key<arr[i])
        {
            arr[i+1]=arr[i];
            c2++;
            i=i-1;
            c2++;
        }
        arr[i+1]=key;
        c2++;
    }
    printf("\n\nsorted array");
    c2++;
    for(int z=0; z<n; z++)
    {
        printf("\t%d",arr[z]);
        c2++;
    }
}
void main()
{

    int arr[]= {1,2,3,4,5,6,7,8,9,10,11,12,13,25,24,23,22,21,20,19,18,17,16,15,14},c1=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    c1++;
    printf("Number of elements are  :: %d\n",n);
    bubble(arr,n);
    printf("\nCounter  :: %d",c1+c2);
}
