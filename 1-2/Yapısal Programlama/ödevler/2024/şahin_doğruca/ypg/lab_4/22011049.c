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


void readFromFile(Node **, char *);
char ** split(char *);


char ** split(char * text) {
    int i, word_count = 0, j, word_length = 0, length = 0;
    char ** res = (char **) malloc(sizeof(char*) * 0);
    char temp[100];

    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] == ' ') {
            temp[word_length] = '\0';

            length = word_length;
            word_length = 0;
            res = realloc(res, sizeof(char *) * (word_count + 1));
            res[word_count] = (char *) malloc(sizeof(char) * (length+1));
            for(j = 0 ; temp[j] != '\0'; j++) {
                res[word_count][j] = temp[j];
            }
            res[word_count][j] = '\0';
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

    return res;
}


void readFromFile(Node ** head, char * fileName) {
    Node * p, * last;
    FILE * file;
    char text[1000];
    char ** res;

    file = fopen(fileName, "r");
    if(file == NULL) {
        perror("Error opening file");
        return;
    }


    fread(text, 1000, 1, file);
    char temp[1000];
    int i = 0;
    int count = 0;
    for(i = 0; text[i] != '\0'; i++) {
        if(text[i] == '\n') {
            count = 0;
            res = split(temp);

            p = (Node *) malloc(sizeof(Node));
            p->productId = atoi(res[0]);
            p->customerId = atoi(res[1]);
            p->customerName = (char *)malloc(sizeof(char) * (strlen(res[2]) + 1));
            strcpy(p->customerName, res[2]);
            p->customerName[strlen(res[2])] = '\0';

            p->productType = (char *)malloc(sizeof(char) * (strlen(res[3]) + 1));
            strcpy(p->productType, res[3]);
            p->productType[strlen(res[3])] = '\0';

            p->day = (char *)malloc(sizeof(char) * (strlen(res[4]) + 1));
            strcpy(p->day, res[4]);
            p->day[strlen(res[4])] = '\0';
            
            p->next = NULL;

             if(*head == NULL) {
                *head = last = p;
            } else {
                last->next = p;
                last = last->next;
            }
        } else {
            temp[count++] = text[i];
        }
    }

}

void sort(Node ** head) {
    Node * p, * q, * t, *k;
    q = *head;
    p = NULL;
    t = NULL;

    int min = 2000000;


    while(q->next->next != NULL) {
        p = q->next;
        t = q;
        min = q->productId;


        while(p->next != NULL) {

            if(p->productId < min) {
                k = p;
            }

            t = p;
            p = p->next;

        }


        if(q==*head) {
            k = *head;
        }

        q->next = k->next;
        k->next = t;
        t->next = q;

        q=q->next;

    }
}


void display(Node * head) {
    Node * p = head;

    while(p) {
        printf("%d %d %s %s %s\n", p->productId, p->customerId, p->customerName, p->productType, p->day);
        p = p->next;
    }
}


void writeToFiles(Node * head) {

    FILE * file;

    Node * p = head;

    while(p) {

        file = fopen(p->customerName, "x");
        char temp[1000] = "merhaba";
        strcat(temp, p->customerName);
        strcat(temp, p->day);
        strcat(temp, "günü tarafinizdan siparis numarasi ");
        strcat(temp, p->productId);
        strcat(temp, p->customerId);
        strcat(temp, "olan");
        strcat(temp, p->productType);
        strcat(temp, "gerceklesmistir");

        fwrite(temp, strlen(temp), 1, file);

        p = p->next;
    }

}


int main() {

    Node * head = NULL;
    char fileName[] = "input.txt";

    readFromFile(&head, fileName);


    display(head);

    // writeToFiles(head);


    return 0;
}