#include<stdio.h>
#include<conio.h>
int c1=0;
int binary_search(int arr[],int x,int l,int h)
{

    int mid=(l+h)/2;
    c1++;
    if(h>=l)
    {
        if(x==arr[mid])
        {
        c1++;
                return mid;
        }

    else if(x>arr[mid])
    {
        l=mid+1;
        c1++;
        return binary_search(arr,x,l,h);
    }
    else if(x<arr[mid])
    {
        h=mid-1;
        c1++;
        return binary_search(arr,x,l,h);
    }
    }
        return -1;


}



void main()
{
    int c2=0;
    printf("Enter size of array :");
    c2++;
    int h;
    scanf("%d",&h);
    c2++;
    int arr[h],x;
    printf("please enter array :");
    c2++;
    for(int i=0;i<h;i++)
    {
        scanf("%d",&arr[i]);
        c2++;
    }
    int mid,l=0;
    printf("\narray \t:");
    c2++;
    for(int i=0;i<h;i++)
    {
        printf("\t%d",arr[i]);
        c2++;
    }

    printf("\n\nenter value :");
    c2++;
    scanf("%d",&x);
    c2++;

   int ans=0;
   ans= binary_search(arr,x,0,h);
   c2++;
   if(ans==-1){
               printf("\nnot found");
               c2++;
}
   else
   {
       printf(" \n\n%d found at %dth potision",x,ans+1);
       c2++;
   }
   printf("\nCounter = %d",c1+c2);
}
