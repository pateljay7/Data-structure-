#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *first;
struct node *create(int n){
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->info=n;
	temp->link=NULL;
	return temp;
}
struct node *
 insert(int n,struct node *first){
	struct node *temp;
	temp=create(n);

    temp->link=first;
	first=temp;
	//printf("%d",first);
	return first;
}
struct node*insertAtLast(int n, struct node*first)
{
     struct node*temp1=first;

     struct node*temp=create(n);

     while(temp1->link!=NULL)
     {
         temp1=temp1->link;
     }
     temp->info=n;
     //temp->link='NULL';
     temp1->link=temp;

     return first;
}
struct node *Delete()
{
    struct node*temp=first;
    first=first->link;
    free(temp);
    return first;
}
struct node*deleteATLast(struct node*first)
{
        struct node *temp=first;
        struct node *temp1=first;
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
            temp1=temp->link->link;
        }
            temp->link=NULL;
            free(temp1);
            return first;
}
struct node*insertAfter(struct node*first,int n,int x)
{
    struct node* node=create(n);
    struct node*temp=first;
    struct node*temp1=first;
    while(temp->info!=x)
    {
        temp=temp->link;
    }
    temp1=temp->link;
    node->link=temp1;
    temp->link=node;

  return first;
}
struct node*DeleteAtSpecific(struct node*first,int n)
{
    struct node* temp=first;
    struct node* temp1=first;
    if(temp->info==n)
    {
        first=first->link;
        free(temp);
        return first;
    }
    while(temp->link->info!=n)
    {
        temp=temp->link;
    }
    temp1=temp->link;
    if(temp->link=NULL)
    {
                free(temp1);
    }
    else{

    temp->link=temp1->link;
    free(temp1);}
 return first;
}
void Display(){
     struct node *temp;
     temp=first;
	printf("\nDisplay Linked List : \n");
	while(temp!=NULL){

		printf("\t%d",temp->info);
		temp=temp->link;
	}

}
void main(){
	int choice,n,x;
	char c;

	do{

        printf("\n=============================================");
		printf(" \n1.Insert Node \n2.Display\n3.Exit\n4.Insert AT Last\n5.delete at front\n6.Delete at last\n7.Insert After Specific\n8.Delete At specific ");
		printf("\nEnter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter data:");
				scanf("%d",&n);
				first=insert(n,first);
				break;
			case 2:
				Display();
				break;
			case 3:
					exit(1);
			case 4:
			printf("Enter data:");
				scanf("%d",&n);
				first=insertAtLast(n,first);
				break;
            case 5:
                first=Delete(first);
                break;
            case 6:
                first=deleteATLast(first);
                break;
            case 7:
                printf("Enter data:");
				scanf("%d",&n);
				printf("Enter position:");
				scanf("%d",&x);
                first=insertAfter(first,n,x);
                break;
            case 8:
                printf("Enter data:");
                scanf("%d",&n);
                first=DeleteAtSpecific(first,n);
                break;

            }

        printf("\n=============================================");

}while(choice=3);
}
