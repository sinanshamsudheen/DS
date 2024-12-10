//Muhammed Sinan D
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=data;
    return newNode;
}
void insert(struct Node** root,int data){
    struct Node* newNode=createNode(data);
    if(*root==NULL){
        *root=newNode;
        return;
    }
    struct Node* Q[100];
    struct Node* temp;
    int front=-1,rear=-1;
    Q[++rear]=*root;
    while(front!=rear){
        temp=Q[++front];
        if(temp->left==NULL){
            temp->left=newNode;
            return;
        }
        else{
            Q[++rear]=temp->left;
        }
        if(temp->right==NULL){
            temp->right=newNode;
            return;
        }
        else{
            Q[++rear]=temp->right;
        }
    }
}
void delete(struct Node** root,int item){
    if(*root==NULL){
        printf("Tree is empty.\n");
        return;
    }
    if((*root)->left==NULL && (*root)->right==NULL){
        if((*root)->data==item){
            free(*root);
            *root=NULL;
            return;
        }else{
            printf("item not found");
        }
    }
    struct Node* temp=NULL;
    struct Node* keyNode=NULL;
    struct Node* Q[100];
    int front=-1,rear=-1;

    while(front!=rear){
        temp=Q[++front];
        if(temp->data==item){
            keyNode=temp;
        }
        if(temp->left!=NULL){
            Q[++rear]=temp->left;
        }
        if(temp->right!=NULL){
            Q[++rear]=temp->right;
        }
    }
    //this is incomplete :)
}
void inorderTraversal(struct Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

void main(){
    #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to find nodes at distance k from any leaf node
void findNodesAtDistance(struct Node* root, int path[], int visited[], int pathLen, int k, int* result, int* resCount) {
    if (root == NULL)
        return;

    // Add current node to path
    path[pathLen] = root->data;
    visited[pathLen] = 0;  // Mark this node as not yet visited
    pathLen++;

    // If this is a leaf node
    if (root->left == NULL && root->right == NULL) {
        // Check if the node at distance k exists in the path
        if (pathLen - k - 1 >= 0 && visited[pathLen - k - 1] == 0) {
            result[*resCount] = path[pathLen - k - 1];
            (*resCount)++;
            visited[pathLen - k - 1] = 1;  // Mark this node as visited
        }
        return;
    }

    // Recursive call for left and right subtrees
    findNodesAtDistance(root->left, path, visited, pathLen, k, result, resCount);
    findNodesAtDistance(root->right, path, visited, pathLen, k, result, resCount);
}

// Wrapper function
void nodesAtDistanceK(struct Node* root, int k) {
    int path[1000];       // To store the path from root to the current node
    int visited[1000];    // To mark nodes already printed
    int result[1000];     // To store the result nodes
    int resCount = 0;     // To keep track of the count of result nodes

    findNodesAtDistance(root, path, visited, 0, k, result, &resCount);

    // Print result
    if (resCount == 0) {
        printf("No nodes found at distance %d from any leaf node.\n", k);
    } else {
        printf("Nodes at distance %d from any leaf node are: ", k);
        for (int i = 0; i < resCount; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}
void depth(struct Node* root){
    int leftdepth=0;
    if(root!=NULL){
        depth(root->left);
        leftdepth++;
    }
    if(root!=NULL){
        depth(root->right);
    }
}
// Driver code
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);

    int k = 2;
    nodesAtDistanceK(root, k);

    return 0;
}
//          1
//        /   \
//       2     3
//      / \   / \
//     4   5 6   7
//    / \
//   8   9

//op-> 12 4 2 9 3 