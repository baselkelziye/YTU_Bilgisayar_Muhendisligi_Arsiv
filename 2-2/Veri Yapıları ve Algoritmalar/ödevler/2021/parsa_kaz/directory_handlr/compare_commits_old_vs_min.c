#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*IMPORTANT NOTE:
    all the methods are tested manually and work perfectly;
    but when it comes to user input, it has a bug which the
    name parameter remains the same.
    Also: added the extra TREE functionality!
        type tree to see the whole subdirectories recursively
*/



#define PROMPT "$ " // shell prompt symbol
#define MAX_NAME 32

// ... Structure ..............................................................
typedef struct Node{
    char* name; // The name of the directory
    struct Node* parent;
    struct Node* child; // The first child, access all children via first
    struct Node* next; // The left sibiling, horizontal LinkedList
} Node;

// ... Methods ................................................................
Node* initNode(char* name){
    Node* node = (Node*) malloc(sizeof(Node));
    if (node== NULL){
        printf("ALLOC_ERR: Couldn't Create the directory!\n");
        exit(0);
    }
    node->name = (char*)malloc(MAX_NAME * sizeof(char));
    strcpy(node->name, name);  // #CHANGED
    node->parent = NULL;
    node->child = NULL;
    node->next = NULL;

    return node;
}


void addChild(Node* node, Node* child){
    if(node->child == NULL){ // add the first child
        node->child = child;
        node->child->parent = node;
    }

    else{ // add the child as a sibiling lf the first child
        Node* temp = node->child;
        while (temp->next != NULL) // traverse untill the end
            temp = temp->next;
        
        temp->next = child;
    }
}


void deleteDir(Node* node, char* name){

    /*  Since it's always Top-Down, there's no need to control if it's root
        Because there's no way to reach upper than root (chdir handles it)*/

    if (node->child == NULL){ // Nothing to delete, empty dir
        printf("DEL_ERR: Directory not found!\n"); // Same exception
        return;
    }

    Node* current = node->child; // head of the linked list

    if(!strcmp(current->name, name)){ // head-deletion  #CHANGED
        // check if it has child before deletion
        if(current->child != NULL){ // non-recursive deletion #TODO recursive
            printf("DEL_ERR: The directory is not empty\n");
            return;
        }
        // deleting current
        node->child = current->next; // Works even if next is NULL
        current->next->parent = node;
        free(current);
        return;
    }

    // deleting non-head
    Node* prev = current; // ATM, current is head
    current = current->next;

    while (current != NULL && strcmp(current->name, name)){  // #CHANGED
        prev = current;
        current = current->next;
    }

    if (current != NULL){
    // check if it has child before deletion
    if(current->child != NULL){ // non-recursive deletion #TODO recursive
        printf("DEL_ERR: The directory is not empty");
        return;
    }
    // deleting current
    prev->next = current->next;
    prev->parent = node;
    free(current);
    }
    else
        printf("DEL_ERR: Directory not found!\n");

}


Node* getNode(Node* node, char* name){ // search by value between children

    if(!strcmp(name, ".."))
        return node->parent;

    Node* temp = node->child;
        for (; temp != NULL; temp=temp->next)
            if(!strcmp(temp->name, name))  //if found  #CHANGED
                return temp;
    // not found
    printf("CD_ERR: Directory not found!\n");
    return node; // CHDIR: stays the same
}

int countList(Node* node){
    int count = 0;

    Node* temp = node->child;
    for (; temp != NULL; temp=temp->next)
        count++;
    
    return count;
}


void printList(Node* node){
    Node* temp = node->child;
    for (; temp != NULL; temp=temp->next){
        printf("\t%s\n", temp->name);
    }
}


void printTree(Node* node, int level){ // #EXTRA
    for (int i = 0; i < level; i++) // Indentation
        printf("\t");
    
    printf("/%s\n", node->name);

    Node* temp = node->child;
    for (; temp != NULL; temp=temp->next){
        printTree(temp, level+1);
    }
    
}

// ... Utilities ..............................................................

void printPromptDir();

// ... Main ...................................................................
int main(int argc, char** argv){

    Node* root = initNode("root");
    Node** currentDir;
    currentDir = &root;

    char command[MAX_NAME]; // #CHANGED

    printf(PROMPT);
    scanf("%s", command);
    //len = getline(&command, &size, stdin);

    while (strcmp(command, "exit")){  // #CHANGED
        
        if(!strcmp(command, "mkdir")){
            char name[MAX_NAME];
            scanf("%s", name);
            Node* newNode = initNode(name);
            addChild(*currentDir, newNode);
        }
        else if (!strcmp(command, "chdir")){            
            char name[MAX_NAME];
            scanf("%s", name);
            Node* newNode = getNode(*currentDir, name);
            currentDir = &newNode;
        }
        else if (!strcmp(command, "rmdir")){            
            char name[MAX_NAME];
            scanf("%s", name);
            deleteDir(*currentDir, name);
        }
        else if (!strcmp(command, "dir")){
            printList(*currentDir);
        }
        else if (!strcmp(command, "count")){
            printf("Total directories: %d\n", countList(*currentDir));
        }
        else if (!strcmp(command, "tree")){
            printTree(*currentDir, 0);
        }

        printf(PROMPT);
        scanf("%s", command);
    
    }
    
    free(root);
    return 0;
}