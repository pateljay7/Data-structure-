#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
//struct node *link;

    struct node *next;
    struct node *prev;
};
struct node *Left=NULL;
struct node *Right=NULL;

struct node *create(int n){
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->info=n;
temp->prev=NULL;
temp->next=NULL;
return temp;
}
struct node *insertAtLeft(int n,struct node *Left){
struct node *temp;
temp=create(n);

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


return Left;


}
struct node *insertAtRight(int n,struct node *Right){
struct node *temp;
temp=create(n);

if(Right==NULL)
{
Left=temp;
Right=temp;
}
else
{
Right->next=temp;
temp->prev=Right;
Right=temp;
}


return Right;


}
struct node *insertAtSpec(int n,int x,struct node *left){
struct node *temp;
struct node *p=NULL;
    temp=create(n);
p=Left;

while(p->info!=x){
p=p->next;
}
temp->prev=p;
temp->next=p->next;
p->next=temp;
temp->next->prev=temp;

return Left;
}
void Display(){
struct node *temp;

temp=Left;
printf("\n Display Doubly Linked List: \n");
while(temp!=NULL){
printf("\t%d",temp->info);
temp=temp->next;
}
}

 void DeleteAtLeft(struct node*Left)
{
    struct node * temp=Left;
    Left=Left->next;
    temp->next=NULL;
    free(temp);
}
void main(){
   int choice,n,x;
    char c;
    do{
        printf("\n 1.Insert Node Form Left \n 2.Insert Node From Right \n 3.Insert At Specific Location \n 4.Display \n 5.Exit\n 6.DeleteAtLeft");
scanf("%d",&choice);
switch(choice) {
case 1:
printf("Enter Data:");
scanf("%d",&n);
Left=insertAtLeft(n,Left);
break;
case 2:
   printf("Enter Data:");
scanf("%d",&n);

Right=insertAtRight(n,Right);
break;
case 3:
printf("Enter Data:");
scanf("%d",&n);
printf("Enter location to Insert:");
scanf("%d",&x);
Left=insertAtSpec(n,x,Left);
break;
case 4:
Display();
break;
case 5:
exit(1);
case 6:
DeleteAtLeft(Left);
Display();
break;



}


} while(choice=5);
}
