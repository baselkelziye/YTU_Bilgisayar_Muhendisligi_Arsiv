// https://www.hackerrank.com/challenges/tree-preorder-traversal/problem
// https://www.hackerrank.com/challenges/tree-postorder-traversal/problem
// https://www.hackerrank.com/challenges/tree-inorder-traversal/problem

void preOrder( struct node *root) {
    if (root == NULL){
        return;
    }
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder( struct node *root) {
    if (root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void inOrder( struct node *root) {
    if (root == NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}