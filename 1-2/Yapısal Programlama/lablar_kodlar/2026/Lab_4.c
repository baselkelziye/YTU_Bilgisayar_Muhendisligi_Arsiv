#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct USER{
    int streamID;
    char name[30];
    char title[30];
    char genre[20];
    char type[20];
    struct USER* next;
} USER; // Madde 1

USER* insertSorted(USER* head, USER* newNode){ // Küçükten büyüğe istenmiş
    if(head == NULL || newNode->streamID < head->streamID){ // En baştakinden küçükse yeni head'imiz newNode olmalı
        newNode->next = head;
        return newNode;
    }
    USER* current = head;
    while(current->next != NULL && current->next->streamID < newNode->streamID){
        current = current->next;
    }
    newNode->next = current->next; // Önce current'dan sonrasını bağlamalıyız ki liste kopmasın
    current->next = newNode; // Sonra current'ı newNode'a bağlıyoruz. Baştan sona korunmuş oldu.
    return head;
}

USER* createLinked(const char filename[]){ // Madde 2
    FILE* fp = fopen(filename, "r");
    if(!fp) {
        printf("File Error!");
        return NULL;
    }
    USER* head = NULL; // Gönderilen ilk Node'un head olması için şu an oluşturduğumuz head'e NULL atamayı unutmuyoruz!
    USER current; // Önce current yaratıp doğru sayıda değer okunduğu kesinleşince newNode'a atamak daha güvenli
    while(fscanf(fp, "%d %s %s %s %s", &current.streamID, current.name, current.title, current.genre, current.type) == 5){
        USER* newNode = malloc(sizeof(USER));
        *newNode = current;
        newNode->next = NULL;
        
        head = insertSorted(head, newNode); // Sıralı olarak Linked List oluşturuyoruz
    }
    fclose(fp);
    return head;
}

void printList(USER* head) {
    USER* temp = head;
    while(temp){
        printf("%d %s %s %s %s\n", temp->streamID, temp->name, temp->title, temp->genre, temp->type);
        temp = temp->next;
    }
}

void skipped(const char filename[], const char status[], USER* head){
    FILE* fp = fopen(filename, "w");
    if(!fp) {
        printf("File Error!");
        return;
    }
    while(head){
        if(strcmp(head->type, status) == 0){
            fprintf(fp, "%d %s %s %s %s\n", head->streamID, head->name, head->title, head->genre, head->type);
        }
        head = head->next;
    }
    fclose(fp);
}

void createBinary(USER* head, const char filename[]){
    FILE* fp = fopen(filename, "wb");
    if(!fp) {
        printf("File Error!");
        return;
    }
    USER* temp = head;
    while(temp){
        fwrite(temp, sizeof(USER), 1, fp);
        temp = temp->next;
    }
    fclose(fp);
}
void updateLinked(const char filename[]){
    FILE* fp = fopen(filename, "rb+");
    if(!fp) {
        printf("File Error!");
        return;
    }
    int targetID;
    printf("Enter the target ID: "); scanf("%d", &targetID);
    USER temp; // Burada bir şey atamadık Çünkü fread okuduğu bilgiyi temp'in içine gömecek.
    while(fread(&temp, sizeof(USER), 1, fp) == 1){
        if(targetID == temp.streamID){
            strcpy(temp.type, "Liked");
            fseek(fp, -sizeof(USER), SEEK_CUR); // fread sebebiyle cursor bir sonraki öğrenciye geçmişti, olması gereken yere çektik
            fwrite(&temp, sizeof(USER), 1, fp);
        }
    }
    fclose(fp);
}
void printBinary(char filename[]){
    FILE* fp = fopen(filename, "rb");
    if(!fp) {
        printf("File Error!");
        return;
    }
    USER temp;
    printf("\nUpdate Binary File Records:\n");
    while(fread(&temp, sizeof(USER), 1, fp) == 1){
        printf("%d %s %s %s %s %s", temp.streamID, temp.name, temp.title, temp.genre, temp.type);
    }
    fclose(fp);
}
int main(){
    USER* head = createLinked("songs.txt");
    if(head != NULL){
        printf("Sorted Linked List\n");
        printList(head); // Madde 3

        skipped("skipped.txt", "Skipped", head); // Madde 4

        createBinary(head, "songs.dat"); // Madde 5

        updateLinked("songs.dat"); // Madde 6 ve 7
        printBinary("songs.dat"); // Madde 8

        USER* current;
        while(head){
            current = head->next;
            free(head);
            head = current;
        }
    }
    return 0;
}