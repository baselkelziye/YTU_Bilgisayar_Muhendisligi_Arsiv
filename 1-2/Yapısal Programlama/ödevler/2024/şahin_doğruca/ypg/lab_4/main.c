#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    unsigned int id;
    char * name, * branch;
    struct node * next;
} Node;

char ** split(char * text);
void readFromFile(Node ** head, char * fileName);
void writeToFile(Node * head, char * fileName);

char ** split(char * text) {
    int i, word_count = 0, j, word_length = 0, length = 0;
    char ** res = (char **) malloc(sizeof(char*) * 0);
    char temp[100];

    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] == ',') {
            temp[word_length] = '\0';

            length = word_length;
            word_length = 0;
            res = realloc(res, sizeof(char *) * (word_count + 1));
            res[word_count] = (char *) malloc(sizeof(char) * (length+1));
            for(j = 0 ; temp[j] != '\0'; j++) {
                res[word_count][j] = temp[j];
            }
            res[word_count][j] = '\0';
            printf("%s\n", res[word_count]);
            word_count++;
        } else {
            temp[word_length++] = text[i];
        }
    }
    
    temp[word_length] = '\0';

    length = word_length;
    word_length = 0;
    res = realloc(res, sizeof(char *) * (word_count + 1));
    res[word_count] = (char *) malloc(sizeof(char) * (length+1));
    for(j = 0 ; temp[j] != '\0'; j++) {
        res[word_count][j] = temp[j];
    }
    res[word_count][j] = '\0';
    printf("%s\n", res[word_count]);

    return res;
}


void readFromFile(Node ** head, char * fileName) {
    Node * p, * last;
    char line[100];
    FILE * file;
    char ** res;

    file = fopen(fileName, "r");
    if(file == NULL) {
            perror("Error opening file");
            return;
       }


    while(fgets(line, 100, file) != NULL) {
        res = split(line);

        p = (Node *) malloc(sizeof(Node));
        p->id = atoi(res[0]);
        p->name = (char *) malloc(sizeof(char) * (strlen(res[1]) + 1));
        strcpy(p->name, res[1]);
        p->name[strlen(res[1])] = '\0';
        p->branch = (char *) malloc(sizeof(char)* (strlen(res[2]) + 1));
        strcpy(p->branch, res[2]);
        p->branch[strlen(res[2])] = '\0';
        p->next = NULL;


        if(*head == NULL) {
            *head = last = p;
        } else {
            last->next = p;
            last = last->next;
        }
    }
    
    fclose(file);
}

int ascending(int id1, int id2) {
    return id1 > id2;
}

int descending(int id1, int id2) {
    return id2 > id1;
}




void display(Node * head) {
    Node * p = head;
    while(p) {
        printf("id:%d, name:%s, branch:%s\n", p->id, p->name, p->branch);
        p = p->next;
    }
}

int main() {

    char fileName[] = "Dataset.txt";
    Node * head = NULL;

    readFromFile(&head, fileName);

    display(head);

    return 0;
}


