#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct Flight {
    int flightCode;
    char departureCity[20];
    char arrivalCity[20];
    char time[6];
    int domestic;
    int runway;
    struct Flight* next;
} Flight;

Flight* insert_sorted(Flight* head, Flight* newFlight) {
    if (head == NULL || head->flightCode > newFlight->flightCode) {
        newFlight->next = head;
        return newFlight;
    }
    Flight* current = head;
    while (current->next != NULL && current->next->flightCode < newFlight->flightCode) {
        current = current->next;
    }
    newFlight->next = current->next;
    current->next = newFlight;
    return head;
}

void print_list(Flight* head) {
    Flight* current = head;
    while (current != NULL) {
        printf("%d %s %s %s %d %d\n", current->flightCode, current->departureCity, current->arrivalCity, current->time, current->domestic, current->runway);
        current = current->next;
    }
}

void save_to_files(Flight* head) {
    Flight* current = head;
    while (current != NULL) {
        char filename[20];
        sprintf(filename, "runway%d.txt", current->runway);
        FILE* file = fopen(filename, "a");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        fprintf(file, "%d %s %s %s %d %d\n", current->flightCode, current->departureCity, current->arrivalCity, current->time, current->domestic, current->runway);
        fclose(file);
        current = current->next;
    }
}

int main() {
    FILE* file = fopen("flights.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Flight* head = NULL;
    while (!feof(file)) {
        Flight* newFlight = (Flight*)malloc(sizeof(Flight));
        if (fscanf(file, "%d %s %s %s %d %d", &newFlight->flightCode, newFlight->departureCity, newFlight->arrivalCity, newFlight->time, &newFlight->domestic, &newFlight->runway) != 6) {
            free(newFlight);
            break;
        }
        newFlight->next = NULL;
        head = insert_sorted(head, newFlight);
    }
    fclose(file);

    printf("Printed to screen (Linked List):\n");
    print_list(head);

    save_to_files(head);

    Flight* current = head;
    while (current != NULL) {
        Flight* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

