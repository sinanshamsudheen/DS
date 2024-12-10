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
struct node* insertNode(struct node *root,int x)
{
   struct node *curr=root;
   char dir;
   while(1)
   {
        printf("Currently at node %d.Enter whether to insert left or right:",curr->data);
        scanf(" %c",&dir);
        if(dir=='L' || dir=='l')
        {
            if(curr->left==NULL)
            {
                printf("Inserting at left of %d\n",curr->data);
                curr->left=createNode(x);
                break;
            }
            else
            {
                curr=curr->left;
            }
        }
        else if(dir=='R' || dir=='r')
        {
            if(curr->right==NULL)
            {
                printf("Inserting at right of %d\n",curr->data);
                curr->right=createNode(x);
                break;
            }
            else
            {
                curr=curr->right;
            }
        }
        else
        {
            printf("invalid direction\n");
        }
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
                if(root==NULL)
                {
                    root=createNode(x);
                    printf("Root node created with value %d\n:",x);
                }
                else
                {
                    insertNode(root,x);
                }
                
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