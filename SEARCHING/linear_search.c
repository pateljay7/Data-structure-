#include<stdio.h>
#include<conio.h>
void main()
{
    int n,i=0,c=0,ct=0,h;
     printf("Enter size of array :");
     ct++;
    scanf("%d",&h);
    ct++;
    int arr[h];
    printf("please enter array :\n");
    ct++;
    for(int i=0;i<h;i++)
    {
        scanf("%d",&arr[i]);
        ct++;
    }
    printf("enter value:");
    ct++;
    scanf(  "%d",&n);
    ct++;

    for(int j=0;j<=h;j++)
    {
        if(n==arr[j])
        {
            printf("*");
            printf("\n%d found at position::%d",n,j);
            ct++;
            break;
        }
            ct++;

         if(j==h){printf("\nvalue not found");ct++;}
    }
        printf("\nCounter = %d",ct);
}
