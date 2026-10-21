#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    int productId;
    int customerId;
    char * customerName;
    char * productType;
    char * day;
    struct node * next;
} Node;

typedef struct type {
    char * name;
    int count;
} Type;

void readFromFile(char **** infos,int *len, char * fileName);
void sortArray(char ****, int);
void arrayToLL(char ***, int, Node **);
void freeArray(char ****, int);
void writeToFile(Node *);
void report(Node *, char *);

void readFromFile(char **** infos,int * len, char * fileName) {
    char * column, ** row, temp[1000];
    int row_count = 0, wordCount = 0, i, j;
    FILE * file;
    file = fopen(fileName, "r");

    char * text = (char *) malloc(sizeof(char) * 1000);
    fread(text, 1, 1000, file);
    // printf("%s", text);
    fclose(file);


    row = (char**) malloc(sizeof(char*) * 0);



    for(i = 0; text[i]!= '\0'; i++) {
        if(text[i] == '\n') {
            row = realloc(row, sizeof(char*) * (row_count+1));
            temp[wordCount] = '\0';
            row[row_count] = (char*) malloc(sizeof(char) * (wordCount+1));
            strcpy(row[row_count], temp);
            row[row_count][wordCount] = '\0';
            // printf("%s\n", row[row_count]);
            row_count++;
            wordCount = 0;
        } else {
            temp[wordCount] = text[i];
            wordCount++;
        }
    }

    (*infos) = realloc(*infos, sizeof(char**) * row_count);

    for(i = 0; i < row_count; i++) {
        (*infos)[i] = (char **) malloc(sizeof(char*) * 5);

        column = strtok(row[i], " ");
        wordCount = 0;
        while(column != NULL) {
            (*infos)[i][wordCount] = (char *) malloc(sizeof(char) * (strlen(column) + 1));
            strcpy((*infos)[i][wordCount], column);
            (*infos)[i][wordCount][strlen(column)] = '\0';
            column = strtok(NULL, " ");

            wordCount++;
        }

    }

    *len = row_count;
    free(text);
    
}

void sortArray(char **** arr, int len) {
    int i, j;
    int min;

    for(i = 0; i < len - 1; i++) {
        min = i;
        for(j = i+1; j < len; j++) {
            if(atoi((*arr)[j][0]) < atoi((*arr)[min][0])) {
                min = j;
            }
        }
        
        // swap min and i;
        char ** temp = (*arr)[i];
        (*arr)[i] = (*arr)[min];
        (*arr)[min] = temp;
    }
}

void arrayToLL(char *** arr, int len, Node ** head) {
    int i;
    Node * p, * last;

    for(i = 0; i < len; i++) {
        p = (Node *) malloc(sizeof(Node));
        p->next= NULL;

        p->productId = atoi(arr[i][0]);
        p->customerId = atoi(arr[i][1]);
        p->customerName = (char*) malloc(sizeof(char) * (strlen(arr[i][2]) + 1));
        strcpy(p->customerName, arr[i][2]);
        p->customerName[strlen(arr[i][2])] = '\0';

        p->productType = (char*) malloc(sizeof(char) * (strlen(arr[i][3]) + 1));
        strcpy(p->productType, arr[i][3]);
        p->productType[strlen(arr[i][3])] = '\0';

        p->day = (char*) malloc(sizeof(char) * (strlen(arr[i][4]) + 1));
        strcpy(p->day, arr[i][4]);
        p->day[strlen(arr[i][4])] = '\0';
        
        if(*head == NULL) {
            (*head) = last = p;
        } else {
            last->next = p;
            last = last->next;
        }
    }
}

void freeArray(char **** arr, int len) {
    int i ,j ;

    for(i = 0; i < len; i++) {
        for(j = 0; j < 5; j++) {
            free((*arr)[i][j]);
        }
        free((*arr)[i]);
    }

    free(*arr);
}

void writeToFile(Node * head) {
    Node * p = head;
    FILE * file;
    char fileName[100], text[1000], temp[100];

    while(p) {
        strcpy(fileName, p->customerName);
        strcat(fileName, ".txt");
        file = fopen(fileName, "wb");

        strcpy(text, "Merhaba ");
        strcat(text, p->customerName);
        strcat(text, ", ");
        strcat(text, p->day);
        strcat(text, " günü tarafinizdan siparis numarasi ");
        sprintf(temp, "%d", p->productId);
        strcat(text, temp);
        strcat(text, " olan müsteri id ");
        sprintf(temp, "%d", p->customerId);
        strcat(text,   temp);
        strcat(text, " olan ");
        strcat(text, p->productType);
        strcat(text, " alisverisi gerceklesmistir. Iyi günler.");
        

        fwrite(text, strlen(text), 1, file);

        p = p->next;
        fclose(file);
    }
}

void report(Node * head, char * fileName) {
    Node * p, * q;
    p = head;

    int typeCount = 0, i, flag = 0;
    Type * arr = (Type *) malloc(sizeof(Type) * 0);

    FILE * file;
    file = fopen(fileName, "wb");
    char text[1000];

    while(p != NULL) {
        flag = 0;
        for(i = 0; i < typeCount; i++) {
            if(strcmp(arr[i].name, p->productType) == 0) {
                flag = 1;
            }
        }

        if(flag==0) {
            arr = realloc(arr, sizeof(Type) * (typeCount + 1));
            arr[typeCount].count++;
            arr[typeCount].name = (char*) malloc(sizeof(char) * (sizeof(p->productType) + 1));
            strcpy(arr[typeCount].name , p->productType);

            printf("%s ", arr[typeCount].name);

            if(p->next != NULL) {
                q = p->next;

                while(q!= NULL) {
                    if(strcmp(p->productType, q->productType) == 0) {
                        arr[typeCount].count++;
                    }
                    q=q->next;
                }
            }
            typeCount++;
        }
        p = p->next; 
    }

    char temp[100];
    for(i = 0; i < typeCount; i++) {
        strcpy(text, arr[i].name);

        sprintf(temp, "%d", arr[i].count);
        strcat(text, " siparis sayisi ");
        strcat(text, temp);
        strcat(text, "\n");

        fwrite(text, strlen(text), 1, file);
    }

    free(arr);
}

int main() {
    char *** customerArray = (char***) malloc(sizeof(char**) * 0);
    int len;
    Node * head = NULL;

    readFromFile(&customerArray, &len , "input.txt");
    sortArray(&customerArray, len);
    arrayToLL(customerArray, len, &head);

    writeToFile(head);
    freeArray(&customerArray, len);


    report(head, "rapor.txt");
    return 0;
}

