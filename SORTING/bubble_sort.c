#include<stdio.h>
#include<conio.h>
int c2=0;
void bubble(int arr[],int n)
{
    int c=0,s=0;
    /*printf("unsorted array ::");
    c2++;
    for(int z=0; z<n; z++)
    {
        printf("\t%d",arr[z]);
        c2++;
    }*/
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {

                int temp;
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                s++;
                c2=c2+3;

            }

        }

    }

    printf("\nsorted array   ::");
    c2++;
    for(int z=0; z<n; z++)
    {
        printf("\t%d",arr[z]);
    }

}
void main()
{
    int n,c1=0;
    printf("Enter size of array ::");
    c1++;
    scanf("%d",&n);
    c1++;
    int arr[n];
    printf("Enter elements of array ::");
    c1++;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        c1++;
    }
    bubble(arr,n);
    printf("\nCounter :: %d",c1+c2);
}
