// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

struct node *lca( struct node *root, int v1, int v2 ) {
    while (root) {
        if (v1 < root->data && v2 < root->data)
            root = root->left;
        else if (v1 > root->data && v2 > root->data)
            root = root->right;
        else
            return root;
    }
    return root;    
}