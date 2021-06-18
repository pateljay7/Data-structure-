#include<stdio.h>
#include<conio.h>

struct node{
int info;
struct node*link;
};
struct node*rear=NULL;
struct node*front=NULL;
struct node*create(n)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->info=n;
    temp->link=NULL;
    return temp;
};
struct node* enqueue(struct node*rear,int n)
{
    struct node* temp=create(n);
    if(rear==NULL&&front==NULL)
    {
        rear=temp;
        front=temp;
    }

}
void main()
{

}
