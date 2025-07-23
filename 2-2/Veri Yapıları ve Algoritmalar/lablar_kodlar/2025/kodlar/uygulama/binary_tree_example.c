#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Fonksiyon bildirimleri
Node *createNewNode(int data);
Node *insertNode(Node *root, int data);
Node *deleteNode(Node *root, int data);
Node *findMin(Node *root);
void inorder(Node *root);
void freeTree(Node *root);

int main()
{
    Node *root = NULL;

    // Veri ekleme
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 15);
    root = insertNode(root, 30);

    printf("Inorder (Before Deletion): ");
    inorder(root);
    printf("\n");

    // Veri silme
    root = deleteNode(root, 20);  // 2 çocuklu düğüm
    root = deleteNode(root, 3);   // Yaprak düğüm
    root = deleteNode(root, 5);   // 1 çocuklu düğüm
    root = deleteNode(root, 100); // Ağaçta olmayan düğüm

    printf("Inorder (After Deletion): ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}

// Yeni düğüm oluşturma
Node *createNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("MEMORY ERROR !!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{

    if (root == NULL)
        return createNewNode(data);

    if (root->data > data)
        root->left = insertNode(root->left, data);
    else if (root->data < data)
        root->right = insertNode(root->right, data);
    else
        printf("Node already added");
    return root;
}
// En küçük değeri bulma (sağ alt ağacın minimumu)
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Ağacın düğümünü silme
Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        printf("Value %d not found in the tree.\n", data);
        return NULL;
    }

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        // Düğüm bulundu
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // İki çocuklu düğüm: sağ alt ağaçtan minimumu bul
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder sıralama (küçükten büyüğe yazdırır)
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Bellek temizliği
void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
