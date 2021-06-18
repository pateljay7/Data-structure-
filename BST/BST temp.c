#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *create(int x){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};
struct node* insert(struct node* node, int x)
{

    if (node == NULL)

        return create(x);


    if (x< node->data)
        node->left  = insert(node->left, x);
    else if (x > node->data)
        node->right = insert(node->right, x);


    return node;
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);

    }

}
struct node * search(struct node * root,int x){
    if(root==NULL||root->data == x ){
        return root;
    }
    if(root->data < x){
        return search(root->right,x);
    }
    return search(root->left,x);
}
int main(){
    struct node *root = NULL;
    struct node *ptr;
    int x,n,h,choice;
    do{
    printf("\n1.insert tree\n");
    printf("2.inorder\n");
    printf("3.postorder\n");
    printf("4.preorder\n");
    printf("5.search\n");
    printf("6.exit\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:

        printf("enter height of tree ");
    scanf("%d",&h);
    n = (pow(2,h+1))-1;
    //printf("%d",n);
    printf("enter root of tree:");
        scanf("%d",&x);
     root = insert(root, x);
    n = n-1;
    while(n--){

     printf("enter data:");
     scanf("%d",&x);
     insert(root,x);

    }
    break;
    case 2:

     inorder(root);
        break;

    case 3:
        postorder(root);
        break;
    case 4:
        preorder(root);
        break;
    case 5:
        printf("enter data you want to search");
        scanf("%d",&x);
       ptr = search(root,x);
       printf("%d\n",ptr);
       printf("%d\n",ptr->data);
       break;
    case 6:
        exit(0);

    }
    }
    while(choice!=5);
        return 0;
}
