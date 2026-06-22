#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Tanımı yapılamayacak kadar uzun. Problemde istenenleri görmek için PDF/txt'e bakabilirsiniz
typedef struct Participant {
    int id;
    char name[50];
    char institution[50];
    int type; // 1: Ogrenci, 2: Mezun, 3: Sirket Temsilcisi
    struct Participant *next;
} Participant;

Participant* createParticipant(int id, char *name, char *institution, int type);
// Menüde create fonksiyonu yok ama PDF'te gene de bizden istenmiş, demek add fonksiyonunda önce oluşturup sonra ekleme yapıcaz
void addParticipant(Participant **head, Participant *newRecord);
void printType(int type);
void listParticipants(Participant *head);
Participant* searchParticipant(Participant *head, int arananID);
int countParticipantsRecursive(Participant *head);

int isStudent(Participant *p);
int isCompanyRepresentative(Participant *p);
void listFilteredParticipants(Participant *head, int (*filter)(Participant *));

void freeParticipants(Participant **head);

int main() {
    int secim, sonlandir = 0;
    int tempID, tempType, arananID;
    char tempName[50], tempIns[50];
    
    Participant *head = NULL;
    Participant *yeniKayit = NULL;
    Participant *bulunan = NULL;
    while(sonlandir == 0) {
        printf("\n--- DEMO DAY EVENT PARTICIPATION SYSTEM ---\n");
        printf("1-> Add participant\n");
        printf("2-> List participants\n");
        printf("3-> Search by participant ID\n");
        printf("4-> Calculate participant count recursively\n");
        printf("5-> List students\n");
        printf("6-> List company representatives\n");
        printf("7-> Exit\n");
        printf("Your Choice: ");
        scanf("%d", &secim);

        if(secim == 1) {
            printf("Participant ID: ");
            scanf("%d", &tempID);
            printf("Name: ");
            scanf(" %49s", tempName);
            printf("Institution: ");
            scanf(" %49s", tempIns);
            printf("Type (1:Student, 2:Graduated, 3:Company): ");
            scanf("%d", &tempType);
            
            yeniKayit = createParticipant(tempID, tempName, tempIns, tempType); // Önce oluştur sonra gönder
            addParticipant(&head, yeniKayit);
            printf("Participant added successfully!\n");
        } 
        else if(secim == 2) {
            listParticipants(head);
        } 
        else if(secim == 3) {
            printf("Enter ID to search: ");
            scanf("%d", &arananID);
            bulunan = searchParticipant(head, arananID);
            if(bulunan != NULL) {
                printf("-> FOUND: ID: %d | Name: %s | Inst: %s | Type: ", bulunan->id, bulunan->name, bulunan->institution);
                printType(bulunan->type);
                printf("\n");
            } else {
                printf("Participant with ID %d not found.\n", arananID);
            }
        } 
        else if(secim == 4) {
            printf("Total Participants: %d\n", countParticipantsRecursive(head));
        } 
        else if(secim == 5) {
            printf("--- STUDENTS ---\n");
            listFilteredParticipants(head, isStudent);
        } 
        else if(secim == 6) {
            printf("--- COMPANY REPRESENTATIVES ---\n");
            listFilteredParticipants(head, isCompanyRepresentative);
        } 
        else if(secim == 7) {
            freeParticipants(&head);
            printf("Memory freed. Exiting system. Have a good day!\n");
            sonlandir = 1;
        } 
        else {
            printf("-> Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

Participant* createParticipant(int id, char *name, char *institution, int type) {
    Participant *yeni = (Participant *)malloc(sizeof(Participant)); // Bu satırı unutursanız 60 puanınız gidebilir :)
    yeni->id = id;
    yeni->type = type;
    strcpy(yeni->name, name);
    strcpy(yeni->institution, institution);
    yeni->next = NULL;
    return yeni;
}

void addParticipant(Participant **head, Participant *newRecord) { // **head ile işlem yapıyoruz. Aksi takdirde değişiklikler maine yansımaz
    Participant *temp;
    if(*head == NULL) {
        *head = newRecord;
    } else {
        temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRecord;
    }
}

void printType(int type) {
    if(type == 1) {
        printf("Student");
    } else if(type == 2) {
        printf("Graduated");
    } else if(type == 3) {
        printf("Company Representative");
    } else {
        printf("Unknown Person!");
    }
}

void listParticipants(Participant *head) {
    Participant *temp = head;
    if(head == NULL) {
        printf("There are no participants registered yet.\n");
    }else{
        while(temp != NULL) {
            printf("ID: %d | Name: %s | Inst: %s | Type: ", temp->id, temp->name, temp->institution);
            printType(temp->type);
            printf("\n");
            temp = temp->next;
        }
    }
}

Participant* searchParticipant(Participant *head, int arananID) {
    Participant *temp = head;
    Participant *bulunan = NULL;
    while(temp != NULL && bulunan == NULL) {
        if(temp->id == arananID) {
            bulunan = temp;
        } else {
            temp = temp->next;
        }
    }
    
    return bulunan;
}

int countParticipantsRecursive(Participant *head) {
    if(head == NULL) {
        return 0;
    }
    return 1 + countParticipantsRecursive(head->next);
}

int isStudent(Participant *p) {
    if(p->type == 1) return 1;
    return 0;
}

int isCompanyRepresentative(Participant *p) {
    if(p->type == 3) return 1;
    return 0;
}

void listFilteredParticipants(Participant *head, int (*filter)(Participant *)) {
    Participant *temp = head;
    int count = 0;
    if(head == NULL) {
        printf("-> List is empty.\n");
    } else {
        while(temp != NULL) {
            if(filter(temp) == 1) {
                printf("ID: %d | Name: %s | Inst: %s\n", temp->id, temp->name, temp->institution);
                count++;
            }
            temp = temp->next;
        }
        if(count == 0) {
            printf("No participants found matching this filter.\n");
        }
    }
}

void freeParticipants(Participant **head) {
    Participant *temp;
    
    while(*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}