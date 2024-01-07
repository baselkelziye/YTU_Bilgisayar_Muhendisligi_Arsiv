#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Bstnode
{
    struct Bstnode *right;
    struct Bstnode *left;
    char kelime[20];
    struct linkednode *dosya_isimleri_head;
};

struct linkednode
{
    char dosya_ismi_linked[20];
    struct linkednode *next;
};

void dosya_ekle(char *, struct Bstnode **);
struct Bstnode *getNewNode(char[20], char[20]);
struct Bstnode *insert(struct Bstnode *, char[20], char[20]);
void printTree(struct Bstnode *);
void BelongedFiles(struct Bstnode *);
void searchString(struct Bstnode *, char[20]);
struct Bstnode *findMin(struct Bstnode *);
struct Bstnode *delete_node(struct Bstnode *, char[20]);
struct Bstnode *delete_file(struct Bstnode *, char[20]);
struct Bstnode *file_deletion_control(struct Bstnode *, char[20]);
void addLast(struct linkednode **, char[20]);
void deleteNodeLinkedList(struct linkednode **, char[20]);
int main()
{
    struct Bstnode *root = NULL;
    char input_kelime[20];
    int selection = 0;

    while (selection != -1)
    {
        printf("\n1-Dosya Ekle\t\t\t\t Basel Kelziye 20011906");
        printf("\n2-Dosya Sil");
        printf("\n3-Agaci Yazdir");
        printf("\n4-Kelime Ara");
        printf("\nCikis: -1\n");
        scanf(" %d", &selection);
        switch (selection)
        {
        case 1:
            printf("\nLutfen Eklemek Istediginiz Dosya ismini giriniz\n");
            // fgets(input_kelime, 20, stdin);
            scanf("%s", input_kelime);
            dosya_ekle(input_kelime, &root);
            break;
        case 2:
            printf("\nLutfen Silmek Istediginiz Dosya Ismini giriniz\n");
            scanf("%s", input_kelime);
            root = delete_file(root, input_kelime);
            break;
        case 3:
            printTree(root);
            break;

        case 4:
            printf("\nLutfen Aramak Istediginiz Kelimeyi giriniz\n");
            // fgets(input_kelime, 20, stdin);
            scanf("%s", input_kelime);
            searchString(root, input_kelime);
            break;

        case -1:
            printf("\nCikiliyor....");
            break;
        default:
            printf("\nHata: Yalnis giris");
            break;
        }
    }
    // dosya_ekle("c.txt", &root);
    // dosya_ekle("d.txt", &root);
    // dosya_ekle("b.txt", &root);

    // printTree(root);

    free(root);
    printf("\n");
    return 0;
}

void dosya_ekle(char dosya_adi[20], struct Bstnode **root)
{
    char tmp_kelime[15];
    FILE *fp;
    fp = fopen(dosya_adi, "r");
    if (fp == NULL)
    {
        printf("\nHata:Dosya Acilamadi");
        exit(101);
    }
    while (fscanf(fp, "%s ", tmp_kelime) == 1)
    {
        *root = insert((*root), tmp_kelime, dosya_adi);
        // printf("\n%s", tmp_kelime);
    }

    fclose(fp);
}

struct Bstnode *getNewNode(char new_string[20], char file_name[20])
{
    struct Bstnode *newNode = (struct Bstnode *)malloc(sizeof(struct Bstnode));
    strcpy(newNode->kelime, new_string);
    newNode->dosya_isimleri_head = NULL;
    addLast(&(newNode->dosya_isimleri_head), file_name);

    return newNode;
}

struct Bstnode *insert(struct Bstnode *root, char new_string[20], char file_name[20])
{ // agacta uygun yere node yerlestirir.

    if (root == NULL)
    {
        root = getNewNode(new_string, file_name);
    }

    else if (strcmp(new_string, root->kelime) < 0)
    {
        root->left = insert((root)->left, new_string, file_name);
    }
    else if (strcmp(new_string, root->kelime) > 0)
    {
        root->right = insert(root->right, new_string, file_name);
    }

    else if ((strcmp(new_string, root->kelime) == 0))
    {

        addLast(&(root->dosya_isimleri_head), file_name); // eger node hazirda var ise gectigi dosyalara dosya ismini ekler sadece
        BelongedFiles(root);
    }

    return root;
}

void printTree(struct Bstnode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printTree(root->left);
        if (root->dosya_isimleri_head != NULL)
        {

            printf("\nKelime: %s", root->kelime);
        }
        BelongedFiles(root);
        printTree(root->right);
    }
}

void BelongedFiles(struct Bstnode *root)
{
    struct linkednode *tmp = root->dosya_isimleri_head;
    while (tmp != NULL)
    {
        printf("\n Gectigi Dosyalar: %s", tmp->dosya_ismi_linked);
        tmp = tmp->next;
    }
    printf("\n");
}

void searchString(struct Bstnode *root, char aranan_kelime[20])
{
    if (root == NULL)
    {
        printf("\nHata: Kelime Bulunmamaktadir!");
        return;
    }
    else if (strcmp(root->kelime, aranan_kelime) == 0)
    {
        printf("\nAranan Kelime: %s", aranan_kelime);
        BelongedFiles(root);
    }

    else if (strcmp(root->kelime, aranan_kelime) > 0)
    {
        searchString(root->left, aranan_kelime);
    }
    else if (strcmp(root->kelime, aranan_kelime) < 0)
    {
        searchString(root->right, aranan_kelime);
    }
    return;
}

struct Bstnode *delete_node(struct Bstnode *root, char silinen_kelime[20])
{
    if (root == NULL)
    {
        printf("\nHata: Agacta Silinecek Eleman Bulunmamaktadir!");
        return root;
    }

    else if (strcmp(silinen_kelime, root->kelime) < 0)
    {
        root->left = delete_node(root->left, silinen_kelime);
    }
    else if (strcmp(silinen_kelime, root->kelime) > 0)
    {
        root->right = delete_node(root->right, silinen_kelime);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL; // cuz dangling pointer
        }

        else if (root->left == NULL)
        {
            struct Bstnode *tmp = root;
            root = root->right;
            free(tmp);
        }
        else if (root->right == NULL)
        {
            struct Bstnode *tmp = root;
            root = root->left;
            free(tmp);
        }

        else
        {
            struct Bstnode *tmp = findMin(root->right);
            strcpy(root->kelime, tmp->kelime);
            root->right = delete_node(root->right, tmp->kelime);
        }
    }
    return root;
}

struct Bstnode *findMin(struct Bstnode *root)
{
    if (root == NULL)
    {
        printf("\nHata: Agacta Silinecek Eleman Bulunmamaktadir!");
        exit(101);
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

struct Bstnode *delete_file(struct Bstnode *root, char file_name[20])
{
    if (root == NULL)
    {
        return root;
    }

    else
    {

        root->left = delete_file(root->left, file_name);

        if (root != NULL)
        {

            root->right = delete_file(root->right, file_name);
        }
        if (root->dosya_isimleri_head->next == NULL && strcmp(root->dosya_isimleri_head->dosya_ismi_linked, file_name) == 0)
        {
            deleteNodeLinkedList(&(root->dosya_isimleri_head), file_name);
            root = delete_node(root, root->kelime);
        }
        else
        {
            deleteNodeLinkedList(&(root->dosya_isimleri_head), file_name);
        }
    }
    return root;
}
void deleteNodeLinkedList(struct linkednode **head_ref, char file_name[20])
{

    struct linkednode *temp = *head_ref, *prev;

    if (temp != NULL && strcmp(temp->dosya_ismi_linked, file_name) == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->dosya_ismi_linked, file_name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;

    free(temp); // Free memory
}

void addLast(struct linkednode **head_ref, char file_name[20])
{
    struct linkednode *new_node = (struct linkednode *)(malloc(sizeof(struct linkednode)));

    strcpy(new_node->dosya_ismi_linked, file_name);

    struct linkednode *current;
    if (*head_ref == NULL || strcmp((*head_ref)->dosya_ismi_linked, file_name) > 0)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    if (strcmp((*head_ref)->dosya_ismi_linked, file_name) == 0)
    {
        return;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL && strcmp(current->next->dosya_ismi_linked, new_node->dosya_ismi_linked) < 0)
        {

            if (strcmp((*head_ref)->dosya_ismi_linked, file_name) == 0)
            {
                return;
            }
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}