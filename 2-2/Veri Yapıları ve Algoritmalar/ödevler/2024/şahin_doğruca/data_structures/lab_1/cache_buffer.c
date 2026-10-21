#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node * prev;
    struct node * next;
    int counter;
    char * name;
} Node;

typedef struct cache {
    struct node * head;
    struct node * last;
    int len;
    int capacity;
    int c_limit;
} Cache;

void shift(Cache * cache, Node** head_ref, char* name, int counter) {
    Node* t = (Node*)malloc(sizeof(Node));
    if (t == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // save informations on t node
    t->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(t->name, name);
    t->counter = counter;
    t->next = *head_ref;
    t->prev = NULL;

    // set prev if not null
    if (*head_ref != NULL) {
        (*head_ref)->prev = t;
    } else {
        cache->last = t;
    }

    *head_ref = t;
}

void deleteNode(Cache * cache, Node ** head_ref, Node * delNode) {
    if (*head_ref == NULL || delNode == NULL) {
        return;
    }

    // If the node to be deleted is the head node
    if (*head_ref == delNode) {
        *head_ref = delNode->next;
        cache->last = NULL;
    }

    // if the node to be deleted is the last node, set last node equal to last's prev
    if(delNode == cache->last) {
        cache->last = delNode->prev;
    }

    // Change next only if the node to be deleted is NOT the last node
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }

    // Change prev only if the node to be deleted is NOT the first node
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }

    free(delNode);
}

Node * search(Node * head, char * name) {
    Node * p = head;
    while(p) {
        if(strcmp(name, p->name) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void display(Node * head) {
    Node * p = head;
    printf("\n");
    while(p) {
        printf("%s,%d", p->name, p->counter);
        if(p->next != NULL) {
            printf(" <=> ");
        }

        p = p->next;
    }

    printf("\n");
}

void add_to_cache(Cache * cache, char * name) {
    

    Node * k = search(cache->head, name);
    int counterTemp;


    if(k) {
        if(k->counter == cache->c_limit) {
            counterTemp = k->counter;
            deleteNode(cache, &(cache->head), k);
            shift(cache, &(cache->head), name, counterTemp + 1);
        } else {
            k->counter = k->counter + 1;
        }
        
    } else {
        shift(cache, &(cache->head), name, 1);
        (cache->len)++;
    }

    if(cache->len == cache->capacity + 1) {
        deleteNode(cache, &(cache->head), cache->last);
        (cache->len)--;
    } 

    
}

void input_from_cmd(Cache * cache) {
    char inp[50];
    do {
        printf("enter name : ");
        scanf("%s", inp);

        if(strcmp(inp, "q") != 0) {
            add_to_cache(cache, inp);
            display(cache->head);
        }
        
        
    } while(strcmp(inp, "q") != 0);
}

void input_from_file(Cache * cache, char * filename) {
    FILE * file;
    file = fopen(filename, "r");

    char text[50];
    int len;

    while(fgets(text, 50, file) != NULL) {
        len = strlen(text);

        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
            len--;
        }
        
        add_to_cache(cache, text);
        display(cache->head);
    }
}

int main() {

    Cache * cache = (Cache *) malloc(sizeof(Cache));
    cache->head = NULL;
    cache->last = NULL;
    cache->len = 0;

    printf("enter capacity : ");
    scanf("%d", &(cache->capacity));

    printf("enter counter limit : ");
    scanf("%d", &(cache->c_limit));


    // input_from_cmd(cache);
    input_from_file(cache, "names.txt");

}