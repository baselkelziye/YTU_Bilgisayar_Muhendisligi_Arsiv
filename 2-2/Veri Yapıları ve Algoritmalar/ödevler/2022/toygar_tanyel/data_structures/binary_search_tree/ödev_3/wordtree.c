#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ONEMLI AYRINTI ve COZUM //
// Hazir string fonksiyonlarinin yapisi geregi cok daha kisitli hareket edebiliyoruz.
// Line icerisindeki kelimeleri okurken yasadigim en buyuk problem ayni line uzerindeki
// son kelimeyi alirken gizli \n'ler var ve tokenizer bunu char olarak aliyordu fakat bizim kontrolumuzde degil,
// dolayisiyla cumle sonundaki beach ve aradaki beach farkli kelimelermis gibi algilaniyordu.
// line[strlen(line)-2] = '\0'; ile bu problemi temiz bir sekilde cozdum ancak 
// atlanmamasi gereken ayrinti EOF, yani dosyanin en sonundaki satirda bu gizli "\n" yok ve son 2 karakter siliniyor. 
// *Bu son iki karakterin silinmemesi icin okuyacagimiz file icinde en sona 2 bosluk atiyoruz.*

struct l{
    struct l *next;
    char *filename;
};
typedef struct l list;

struct n{
    struct l *files;
    char *word;            
    struct n *left;
    struct n *right;
};
typedef struct n node;

node * insertWord2BST(char*, char*, node *);
node * deleteFile(node *, char*);
node * deleteNode(node *, char*);
void search(char*, node *, int, char*);
node *readFile_createTree(node*);
node *readFile_toDelete(node*, char *);
void inOrder(node *);
void preOrder(node *);
void postOrder(node *);
char *find_max(node *);
char *find_min(node *);

int main(){
    node *bst = NULL;
    
    int expression;
    char *word;
    printf("\n\t\t###   Welcome  ####");
    int flag = 1;
    while(flag){
        
        printf("\n\
                1) Initialize/Add New File to the tree. (Please use .txt file to add new file)\n\
                2) Search for a specific word and see the files that contains that word.\n\
                3) Delete a file.\n\
                4) Quit\n\
                Choice: ");

        scanf("%d", &expression);

        switch (expression)
        {
        case 1:
            bst = readFile_createTree(bst);
            printf("\n** Your file is read and new tree is created. Check the words below in different orders. **\n");
            printf("\nInorder BST:\n");
            inOrder(bst);
            printf("\n\nPreorder BST:\n");
            preOrder(bst);
            printf("\n\nPostorder BST:\n");
            postOrder(bst);
            printf("\n");

            break;
        case 2:
            printf("\nEnter the word that you want to search: ");
            scanf("%s", word);
            search(word, bst, 0, NULL);

            break;
        case 3:
            printf("\nEnter the name of file that you want to delete: ");
            scanf("%s", word);

            printf("\n\n###  2 words sample before deletion:  ###\n");
            search("the", bst, 0, NULL); 
            search("sea", bst, 0, NULL);

            printf("\n###  Last files for 3 words after deletion:  ###\n");
            readFile_toDelete(bst, word);
            
            printf("\n\n###  The tree after deletion of file:  ###\n");
            printf("\nInorder BST:\n");
            inOrder(bst);
            printf("\n");
            printf("\nPreorder BST:\n");
            preOrder(bst);
            printf("\n");
            printf("\nPostorder BST:\n");
            postOrder(bst);
            printf("\n");
            
            printf("\n###  Last files for 2 words after deletion:  ###\n");
            search("the", bst, 0, NULL); 
            search("sea", bst, 0, NULL);
            break;
        case 4:
            flag = 0;
            break;            
        default:
            break;
        }
    }    
    return 0;
}


//searches elements in the tree
void search(char *string, node* bst, int delete_mode, char * filename) 
{
    int res;
    if( bst != NULL ) {
        res = strcmp(string, bst->word);
        if( res < 0)
            search(string, bst->left, delete_mode, filename);
        else if( res > 0)
            search(string, bst->right, delete_mode, filename);
        else{
            if(delete_mode == 1){
                deleteFile(bst, filename);
            }
            else{
                list*iter = bst->files;
                printf("\n'%s' found! in following files:\n", string);
            
                while(iter->next != NULL){
                    printf("%s\n", iter->filename);
                    iter = iter->next;
                }
                printf("%s\n", iter->filename);
                }
        }
    }
    else printf("\n'%s' is not in the tree.\n", string);
}


node *readFile_createTree(node*bst){
    FILE *file;
    char in_name[10];
    char *token = NULL;
    char *line = NULL;
    char *filename = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Enter file name:\n");
    scanf("%s", in_name);

    file = fopen(in_name, "r");

    if (file == NULL)
        printf("Can't open %s for reading.\n", in_name);
    else
    {
        while ((read = getline(&line, &len, file)) != -1) {
            printf("%s", line);
            line[strlen(line)-2] = '\0'; // this deletes invisible "\n"s in the file. strtok(line, " \n") is not working
            token = strtok(line, " ");   // i assume that this problem is about mac-windows file sytems difference
            filename = token;
            filename[strlen(filename)-1] = '\0';
            while( token != NULL ) {
                token = strtok(NULL, " ");
                if(token == NULL)
                    break;
                bst = insertWord2BST(filename, token, bst);
            }
        }
        fclose(file);
    }
    return bst;  
}

node *readFile_toDelete(node*bst, char *filename){
    FILE *file;
    char in_name[10];
    char *token = NULL;
    char *line = NULL;
    char *fileName = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen("test.txt", "r");

    if (file == NULL)
        printf("Can't open %s for reading.\n", in_name);
    else
    {
        while ((read = getline(&line, &len, file)) != -1) {
            printf("\n%s", line);
            line[strlen(line)-2] = '\0'; 
            token = strtok(line, " ");   
            fileName = token;
            fileName[strlen(fileName)-1] = '\0';
            if(!(strcmp(fileName, filename))){
                while( token != NULL ) {
                    token = strtok(NULL, " ");
                    if(token == NULL)
                        break;
                    search(token, bst, 1, filename);
                }
            }
        }
        fclose(file);
    }
    return bst;  
}


node * insertWord2BST(char *filename, char *string ,node *bst){

    int res,res2;
    if(bst == NULL){
        bst = (node*)malloc(sizeof(node));
        bst->word = malloc(strlen(string)+1);     // memory for word
        bst->word = strcpy(bst->word, string); 
        bst -> right = NULL;
        bst -> left = NULL;
        // init first appear of word
        bst->files = (list*)malloc(sizeof(list));
        bst->files->filename = malloc(strlen(filename)+1);
        bst->files->filename = strcpy(bst->files->filename, filename);
        bst->files->next = NULL;
    }
    else{
        res = strcmp(string, bst->word);
        //If the new string is 'less than' the bst, go left
        if(res < 0)
            bst->left = insertWord2BST(filename, string, bst->left);
        else if(res > 0)
            bst->right = insertWord2BST(filename, string, bst->right);
        else{
            printf("The word '%s' is already exist.\n", string);

            list*iter = bst->files;
            while(iter->next != NULL && strcmp(iter->filename, filename) != 0)
                iter = iter->next;

            if(strcmp(iter->filename, filename) != 0){
                iter->next = (list*) malloc(sizeof(list));
                iter->next->filename = malloc(strlen(filename)+1);
                iter->next->filename = strcpy(iter->next->filename, filename);
                iter->next->next = NULL;
            }
            return bst;
        }
    }
    return bst;
}


node * deleteFile(node *bst, char *filename){
    
    if(bst->files->next == NULL){
        printf("\n### Deleted file from '%s' and word removed from tree. ###", bst->word);
        deleteNode(bst, bst->word);
        return bst;
    }
    else if(strcmp(bst->files->filename, filename) == 0){ // if the root equals to word we search
        list * tmp = bst->files;
        bst->files = bst->files->next;
        free(tmp);
        printf("\n### Deleted file from '%s':", bst->word);
        search(bst->word, bst, 0, NULL);
        return bst; 
    }
    else{
        list * iter = bst->files;
        while(iter->next != NULL && strcmp(iter->next->filename, filename) != 0)
            iter = iter->next;

        list * tmp = iter->next;
        iter->next = iter->next->next;
        free(tmp); 
        return bst;
    }
    
}

node * deleteNode(node * bst, char * word){
    if (bst == NULL){
        printf("\nThe element is not found in tree to delete.");
        return NULL;
    }
    if (strcmp(word, bst->word) == 0){
        if(bst->left == NULL && bst->right == NULL){ //found element has no child
            free(bst);
            return NULL;
        }
        else if(bst->right != NULL){ //found element has right child
            bst->word = strcpy(bst->word, find_min(bst->right));
            bst->right = deleteNode(bst->right, find_min(bst->right));
        }
        else{ //found element has left child
            bst->word = strcpy(bst->word, find_min(bst->left));
            bst->left = deleteNode(bst->left, find_max(bst->left));
        }
        return bst;
    }
    else if (strcmp(word, bst->word) > 0){ //element still not found, and if x greater than node, search for right node
        bst->right = deleteNode(bst->right, word);
        return bst;
    }
    else{ //element still not found, and if x smaller than node, search for left node
        bst->left = deleteNode(bst->left, word);
        return bst;
    }
}


char *find_max(node *bst){
    while(bst->right != NULL)
        bst = bst->right;
    return bst->word;
}

char *find_min(node *bst){
    while(bst->left != NULL)
        bst = bst->left;
    return bst->word;
}

void preOrder(node *bst) {
    if (bst == NULL){
        return;
    }
    printf("%s ", bst->word);
    preOrder(bst->left);
    preOrder(bst->right);
}

void postOrder(node *bst) {
    if (bst == NULL){
        return;
    }
    postOrder(bst->left);
    postOrder(bst->right);
    printf("%s ", bst->word);
}

void inOrder(node *bst) {
    if (bst == NULL){
        return;
    }
    inOrder(bst->left);
    printf("%s ", bst->word);
    inOrder(bst->right);
}