#include <stdio.h>
#include <stdlib.h>

struct n{
    int data;
    struct n *left;
    struct n *right;
};
typedef struct n node;

node * insert(node *, int);
void traverse(node *);
node * delete(node *, int);
int search(node *, int);
int find_max(node *);
int find_min(node *);

int main(){

    node *bst = NULL;
    int element;
    bst = insert(bst, 8);
    bst = insert(bst, 3);
    bst = insert(bst, 1);
    bst = insert(bst, 6);
    bst = insert(bst, 7);
    bst = insert(bst, 10);
    bst = insert(bst, 14);
    bst = insert(bst, 4);

    printf("\nTree elements: ");
    traverse(bst);
    bst = delete(bst, 6);
    printf("\nTree elements after deletion: ");
    traverse(bst);
    printf("\n");
    element = search(bst, 300);
    printf("\n If the results is 1, we found the element. Otherwise, it is not found. \n Result: %d\n", element);
    element = search(bst, 4);
    printf("\n If the results is 1, we found the element. Otherwise, it is not found. \n Result: %d\n", element);
   
    bst = delete(bst, 56);
    printf("\nTree elements after deletion: ");
    traverse(bst);

    printf("\n max: %d, min: %d\n", find_max(bst), find_min(bst));  

    return 0;
}

void traverse(node *bst){
    
    if (bst == NULL){
        return;
    }
    //printf("\n RECURSIVE PASS 1 \n");
    traverse(bst->left);
    //printf("\n RECURSIVE PASS 2 \n");
    printf("%d ", bst->data);
    //printf("\n RECURSIVE PASS 3 \n");
    traverse(bst->right);
    //printf("\n RECURSIVE PASS 4 \n");
}

int search(node *bst, int element){

    if (bst == NULL)
        return -1;
    else if (bst->data == element)
        return 1;

    if (search(bst->right, element) == 1)
        return 1;
    else if (search(bst->left, element) == 1)
        return 1;
    
    return -1;

}

node * insert(node *bst, int x){

    if (bst == NULL){
        node * root = (node*)malloc(sizeof(node));
        root->left = NULL;
        root->right = NULL;
        root->data = x;
        return root;
    }
    else if (bst->data < x)
        bst->right = insert(bst->right, x);
    else
        bst->left = insert(bst->left, x);
    
    return bst;
}

node * delete(node *bst, int x){
    if (bst == NULL){
        printf("\nThe element is not found in tree to delete.");
        return NULL;
    }
    if (bst->data == x){
        if(bst->left == NULL && bst->right == NULL){ //found element has no child
            free(bst);
            return NULL;
        }
        else if(bst->right != NULL){ //found element has right child
            bst->data = find_min(bst->right);
            bst->right = delete(bst->right, find_min(bst->right));
        }
        else{ //found element has left child
            bst->data = find_max(bst->left);
            bst->left = delete(bst->left, find_max(bst->left));
        }
        return bst;
    }
    else if (bst->data < x){ //element still not found, and if x greater than node, search for right node
        bst->right = delete(bst->right, x);
        return bst;
    }
    else{ //element still not found, and if x smaller than node, search for left node
        bst->left = delete(bst->left, x);
        return bst;
    }
}

int find_max(node *bst){
    while(bst->right != NULL)
        bst = bst->right;
    return bst->data;
}

int find_min(node *bst){
    while(bst->left != NULL)
        bst = bst->left;
    return bst->data;
}