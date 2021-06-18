//doubly linked by jay patel
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
struct node*InsertAtRight(int n,struct node*Right)
{
    //printf("start Right");
    struct node *temp;
    temp=Create(n);
    if(Right==NULL)
    {
        Right=temp;
        Left=temp;
    }
    else
    {
            Right->next=temp;
            temp->prev=Right;
            Right=temp;
    }

    return Right;
}
struct node*InsertAfert(int n,int x,struct node*Left)
{
        struct node*temp1=Left;
        struct node*temp=Create(n);
        while(temp1->info!=x)
        {
            temp1=temp1->next;
        }
        temp->prev=temp1;
        temp->next=temp1->next;
        temp1->next=temp;
        temp->next->prev=temp;
   /* temp->next=temp1->next->prev;
    temp1->next->prev=temp;
    temp1->next=temp;
    temp->prev=temp1;*/
    return Left;

}
struct node* DeleteAtLeft(struct node*Left)
{
    struct node *temp=Left;
    Left=Left->next;
    Left->prev=NULL;
    free(temp);
    return Left;
}
void display()
{
    struct node*temp=Left;
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}


void  main()
{
    int n,choice;
    int i=0;
    int x=0;
    while(1){
    printf("\n 1.Insert Node Form Left\n 2.Insert Node Form Right \n 3.Delete At Left\n4.insert after\n 7.Display \n 8.Exit");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Enter Data:");
            scanf("%d",&n);
           // printf("\nbefore insert");
            Left=InsertAtLeft(n,Left);
            //printf("\nafter insert");
            break;
        case 2:
            printf("Enter Data:");
            scanf("%d",&n);
           // printf("\nbefore insert");
            Right=InsertAtRight(n,Right);
            //printf("\nafter insert");
            break;
        case 3:
            Left=DeleteAtLeft(Left);
            break;
        case 4:
            printf("enter data");
            scanf("%d",&n);
            printf("enter position");
            scanf("%d",&x);
            Left=InsertAfert(n,x,Left);
            break;
        case 7:
            display();
            break;
        case 8:
            exit(1);

    }


    }


}
