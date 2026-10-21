#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node* createNode(int data);
void inorderTraversal(node *tree);
void preorderTraversal(node *tree);
void postorderTraversal(node *tree);


int main(){
    node *root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
void postorderTraversal(node *tree) //left subtree - right subtree - node
{
    if(tree == NULL) return;
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("%d ",tree->data);
}
void preorderTraversal(node *tree) // node - left subtree - right subtree
{
    if(tree == NULL) return;
    printf("%d ",tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

void inorderTraversal(node *tree) // left subtree - node - right subtree
{
    if(tree == NULL) return;
    inorderTraversal(tree->left);
    printf("%d ",tree->data);
    inorderTraversal(tree->right);
}

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Error creating a new node.\n");
        exit(0);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}