#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

typedef struct {
    int id;
    char name[MAX]; 
    char surname[MAX];
    char TC[11];
    unsigned int age;
} Patient;

typedef struct {
    Patient arr[MAX];
    int front;
    int rear;
} Queue;

void initialize(Queue **);


void initialize(Queue ** queue) {
    Queue * q = (Queue * ) malloc(sizeof(Queue));
    q->front = -1;
    q->front = -1;

    *queue = q;
}

bool isEmpty(Queue * queue) {
    if(queue->rear == -1) return true;
    if(queue->front > queue->rear) return true;
    return false;
}

bool isFull(Queue * queue) {
    if(queue->rear >= 49) return true;
    return false;
}

void push(Queue ** queue, Patient patient) {
    (*queue)->rear++;
    if((*queue)->front == -1) (*queue)->front = 0;
    if(!isFull(*queue)) ((*queue)->arr)[(*queue)->rear] = patient;
}

void pop(Queue ** queue) {
    ((*queue)->front)++;
}

void printPatient(Patient patient) {
    printf("id:%d, name:%s, surname:%s, TC:%s, age:%d\n", patient.id, patient.name, patient.surname, patient.TC, patient.age);
}

void printQueue(Queue * queue) {
    int i;
    for(i = queue->front; i <= queue->rear; i++) {
        printPatient((queue->arr)[i]);
    }
}


void getPatientInfos(Patient * patient) {
    Patient * p = (Patient *) malloc(sizeof(Patient));
    char text[MAX];
    printf("please enter the patient name : ");
    scanf("%s", p->name);
    printf("please enter the patient surname : ");
    scanf("%s", p->surname);
    printf("please enter the patient TC : ");
    scanf("%s", p->TC);
    printf("please enter the patient age : ");
    scanf("%ud", &(patient->age));
    
    patient = p;
}

int getLastId(char * filename) {
    FILE * file = fopen("rb", filename);

    if(file == NULL) {
        return 1;
    }
    int id = 0;
    Patient patient;
    while(fread(&patient, sizeof(patient), 1, file) == 1) {
        if(patient.id > id) id = patient.id;
    }

    return id + 1;

    fclose(file);
}

void readPatients(char * filename) {
    FILE * file = fopen(filename, "rb");

    Patient patient;

    while(fread(&patient, sizeof(patient), 1, file) == 1) {
        printPatient(patient);
    }

    fclose(file);
}

void addPatients(char * filename) {
    FILE * file = fopen(filename, "ab");

    int id = getLastId(filename);

    if(file == NULL) {
        perror("file is null");
        return;
    }

    char inp;

    while(inp != 'q') {
        Patient * patient = NULL;

        getPatientInfos(patient);
        patient->id = id;
        id++;

        printf("%d", patient->age);

        fwrite(patient, sizeof(patient), 1, file);


        printf("\nplease enter 'q' for quit : ");
        scanf(" %c", &inp);
    }


    fclose(file);
}

int main() {
    Queue * queue = NULL;

    initialize(&queue);

    addPatients("patients.dat");

    readPatients("patients.dat");



    return 0;
}