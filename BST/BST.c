#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node* left,*right;
};
struct node*root=NULL;
struct node* create(int n)
{
    struct node*temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->key=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* insert(struct node* root, int key)
{

    if (root == NULL)

        return create(key);


    if (key<root->key)
        root->left  = insert(root->left, key);
    else if (key >root->key)
        root->right = insert(root->right, key);


    return root;
}

void inorder(struct node* ptr)
{
    if(ptr!=NULL)
    {
        if(ptr->left==NULL && ptr->right==NULL)
        printf("\t%d",ptr->key);
    else
    {
        inorder(ptr->left);
        printf("\t%d",ptr->key);
        inorder(ptr->right);
    }
       }
}
void postorder(struct node* root)
{
    if(root!=NULL)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                printf("\t%d",root->key);
            }
            else
            {
                postorder(root->left);
                postorder(root->right);
                printf("\t%d",root->key);
            }
        }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        if(root->left==NULL&&root->right==NULL)
            printf("\t%d",root->key);
        else
        {
            printf("\t%d",root->key);
            preorder(root->left);
            preorder(root->right);
        }
    }
}
void Search(struct node *root, int data)
{
	int depth = 0;
	struct node *temp = create(data);
	temp = root;
	while(temp != NULL)
	{
		depth++;
		if(temp->key == data){
			printf("\n Data found at depth : %d",depth);
			return;
		}
		else if(temp->key > data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	printf("\n Data not found");
	return;
}
struct node * minNode(struct node* node)
{
    struct node* temp = node;
    while (temp && temp->right != NULL)
        temp = temp->right;
     return temp;
}
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL)
		 return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
         if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right,temp->key);
    }
    return root;
}


void main()
{
        int ch,n;
        while(1){
        printf("\n1 .insert data in tree\n2 .inorder\n3 .postorder \n4 .preorder\n5.Searching\n6.Delete node\n7 .exit");
        scanf("%d",&ch);

                switch(ch)
                {
                    case 1:
                        printf("enter data");
                        scanf("%d",&n);
                        root=insert(root,n);

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
                         printf("Enter data:");
                         scanf("%d",&n);
                        Search(root,n);
                        break;
                     case 6:
                        printf("Enter data:");
                        scanf("%d",&n);
                        root=deleteNode(root,n);
                        break;
                    case 7:
                        exit(1);
                }

        }



}
