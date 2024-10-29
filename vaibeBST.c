#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
}*root=NULL,*stack[100];
int top=-1;
void push(struct node *temp)
{
    if(top<99)
    {
        top++;
        stack[top]=temp;
    }
}
struct node *pop()
{
    if(top>=0)
    {
        return stack[top--];
    }
    else
    {
        return NULL;
    }
}
struct node *createNode(int x)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->left=NULL;new->right=NULL;
    return new;
}
void insertNode(int x)
{
   struct node *new=createNode(x);
   if(root==NULL)
   {
        root=new;
        printf("Root node created with data %d\n",new->data);
        return;  
   }
   struct node *curr=root;
   struct node *ptr=NULL;
   while(curr!=NULL)
   {
        ptr=curr;
        if(x<curr->data)
        {
            curr=curr->left;   //move to left subtree
        }
        else if (x>curr->data)
        {
            curr=curr->right;  //move to right subtree
        }
        else
        {
            //if value already exists, dont insert it, as no duplicate allowed
            printf("Duplicate value %d not inserted.\n",x);
            return;
        }
   }
    //now ptr points to where the new node should be attached
    if(x<ptr->data)
    {
        ptr->left=new;
    }
    else
    {
        ptr->right=new;
    }
}
void inorder(struct node *root)
{
    struct node *curr=root;
    while(curr!=NULL||top!=-1)
    {
        while(curr!=NULL)
        {
            push(curr);
            curr=curr->left;
        }
        curr=pop();
        printf("%d,",curr->data);
        curr=curr->right;
    }
    printf("\n");
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d,",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d,",root->data);
    }
}
void main()
{
    int ch,x;
    while(1)
    {
        printf("1.insertNode 2.inorder 3.preorder 4.postorder 5.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter data to enter:");
                scanf("%d",&x);
                insertNode(x);
                break;
            case 2:
                printf("Inorder traversal\n");
                inorder(root);
                break;
            case 3:
                printf("Preorder traversal\n");
                preorder(root);
                break;
            case 4:
                printf("Postorder traversal\n");
                postorder(root);
                break;
            case 5:
                exit(0);
            default:
                printf("invalid choice!!");
        }
    }
}