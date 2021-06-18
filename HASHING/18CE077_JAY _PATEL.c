#include<conio.h>
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *Left=NULL;
struct node *Right=NULL;

struct node* Create(int n)
{
    struct node*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=n;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

struct node * InsertAtLeft(int n , struct node*Left)

{
    struct node *temp;
temp=Create(n);

if(Left==NULL)
{
Left=temp;
Right=temp;
}
else
{
temp->next=Left;
Left->prev=temp;
Left=temp;
}
}
void display()
{
    struct node*temp=Left;
    while(temp!=NULL)
    {
        printf("[%u]\t(%d)\t[%u]\t",temp->prev,temp->info,temp->next);
        temp=temp->next;
    }
}
void  main()
{
    int n,choice;
    int i=0;
    int x=0;
    while(1){
    printf("\n=============================================");
    printf("\n1).Insert At Front \n2).Display \n3).Exit");
    printf("\nEnter choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter Data:");
            scanf("%d",&n);
            Left=InsertAtLeft(n,Left);
            break;
        case 2:
            display();
            break;
        case 3:
            exit(1);
        printf("\n=============================================");
    }
}


}

