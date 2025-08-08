/*
 * File:         24011037.c
 * Description:  Structural Programming Semester Project
 * Author:       Burak Basol
 * Created:      2025-05-19
 * Updated:      2025-05-27
 * Version:      2.0
 */

 //---------------------------------------------Include Begin---------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

//----------------------------------------------Include End----------------------------------------------//

//----------------------------------------------Define Begin---------------------------------------------//

#define CLEAR // if defined it clears the screen everytime
#define MAX_LEN 50

//----------------------------------------------Define End-----------------------------------------------//

//----------------------------------------------Definitions Begin----------------------------------------//

typedef struct author {
    char name[MAX_LEN];
    char surname[MAX_LEN];
    unsigned int authorID;
    struct author *next;
} author;

typedef struct student {
    char name[MAX_LEN];
    char surname[MAX_LEN];
    int point; //In the beginning, god created earth and gave every student 100 starting points
    char studentID[9];
    struct student *prev;
    struct student *next;
} student;

typedef struct book {
    char name[MAX_LEN];
    char ISBN[14];
    unsigned int number;
    struct book *next;
} book;

typedef struct bookAuthor {
    char ISBN[14];
    int authorID;
    struct bookAuthor *next;
} bookAuthor;

//----------------------------------------------Definitions End------------------------------------------//

//----------------------------------------------Prototype Begin------------------------------------------//

void clearScreen();
void printLine();
void pause();

void loadStudentsFromCSV(student **head);
void saveStudentsToCSV(student *head);
void loadAuthorsFromCSV(author **head);
void saveAuthorsToCSV(author *head);
void loadBooksFromCSV(book **head);
void saveBooksToCSV(book *head);
void loadBookAuthorsFromCSV(bookAuthor **headBA);
void saveBookAuthorsToCSV(bookAuthor *headBA);

void freeStudents(student *head);
void freeAuthors(author *head);
void freeBooks(book *head);
void freeBookAuthors(bookAuthor *head);

void addStudent(student **head);
void removeStudent(student **head);
void updateStudent(student **head);
void printStudent(student **head);

void displaySingleStudentDetail(student *s_node);
void forEachStudent(student *head, void (*action)(student *s_node));
void printAllStudents(student **head);

void printOwingStudents(student **head, book *headBook);
void printPunishedStudents(student **head);
void takeBook(student **headStudent, book *headBook);
void giveBook(student **headStudent, book *headBook);

void addBook(book **headBook, bookAuthor **headBA, author *headAuthor);
void removeBook(book **headBook, bookAuthor **headBA);
void updateBook(book **headBook);
void printBook(book **headBook);
void printShelfBooks(book *headBook);
void printOwedBooks(book *headBook, student *headStudent);
void printBookAuthorMatch(bookAuthor **headBA, author *headAuthorList, book *headBookList);
void updateBooksAuthor(bookAuthor **headBA, author *headAuthorList, book *headBookList);

void addAuthor(author **headAuthor);
void removeAuthor(author **headAuthor, bookAuthor **headBA);
void updateAuthor(author **headAuthor);
void printAuthor(author **headAuthor);

//----------------------------------------------Prototype End--------------------------------------------//

//----------------------------------------------User Code Begin------------------------------------------//

int main() {
    FILE *authorFile = NULL;
    FILE *studentFile = NULL;
    FILE *bookAuthorFile = NULL;
    FILE *bookDataFile = NULL;
    FILE *bookTakenFile = NULL;
    student *headStudent = NULL;
    author *headAuthor = NULL;
    book *headBook = NULL;
    bookAuthor *headBookAuthor = NULL;
    int choice = 1;
    int tempChoice = -1;
    int main_loop_running = 1;
    int studentChoice = -1;
    int bookChoice = -1;
    int authorChoice = -1;

    authorFile = fopen("authors.csv", "a+");
    studentFile = fopen("students.csv", "a+");
    bookAuthorFile = fopen("bookAuthor.csv", "a+");
    bookDataFile = fopen("bookData.csv", "a+");
    bookTakenFile = fopen("bookTaken.csv", "a+");

    if (!authorFile || !studentFile || !bookAuthorFile || !bookDataFile || !bookTakenFile) {
        perror("One or more essential CSV files failed to open or be created on startup");
        if (authorFile) fclose(authorFile);
        if (studentFile) fclose(studentFile);
        if (bookAuthorFile) fclose(bookAuthorFile);
        if (bookDataFile) fclose(bookDataFile);
        if (bookTakenFile) fclose(bookTakenFile);
        return EXIT_FAILURE;
    }
    fclose(authorFile);
    fclose(studentFile);
    fclose(bookAuthorFile);
    fclose(bookDataFile);
    fclose(bookTakenFile);

    loadStudentsFromCSV(&headStudent);
    loadAuthorsFromCSV(&headAuthor);
    loadBooksFromCSV(&headBook);
    loadBookAuthorsFromCSV(&headBookAuthor);

    while (main_loop_running) {
        choice = -1;
        tempChoice = -1;
        do {
            printLine();
            printf("------------Main Menu---------\n");
            printf("1.Student Operations\n");
            printf("2.Book Operations\n");
            printf("3.Author Operations\n");
            printf("0.Exit\n");
            printLine();

            printf("Please choose: ");
            if (scanf("%d", &tempChoice) != 1) {
                while (getchar() != '\n');
                tempChoice = -1;
            }
            choice = tempChoice;

            if (choice < 0 || choice > 3) {
                printf("\nPlease enter a valid choice (0-3)!\n");
            }
            #ifdef CLEAR
            clearScreen();
            #endif
        } while (choice < 0 || choice > 3);

        if (choice == 0) {
            main_loop_running = 0;
        }
        else {
            if (choice == 1) {
                studentChoice = -1;
                do {
                    printLine();
                    printf("-----Student Menu------\n");
                    printf("1.Add student\n");
                    printf("2.Remove student\n");
                    printf("3.Update student\n");
                    printf("4.Print student\n");
                    printf("5.Print all student\n");
                    printf("6.Print owing students\n");
                    printf("7.Print punished students\n");
                    printf("8.Take book\n");
                    printf("9.Give book\n");
                    printf("0.Back to Main Menu\n");
                    printLine();
                    printf("Please choose: ");
                    if (scanf("%d", &studentChoice) != 1) {
                        while (getchar() != '\n');
                        studentChoice = -1;
                    }

                    if (studentChoice < 0 || studentChoice > 9) {
                        printf("\nPlease enter a valid choice (0-9)!\n");
                    }
                    #ifdef CLEAR
                    clearScreen();
                    #endif
                } while (studentChoice < 0 || studentChoice > 9);

                if (studentChoice != 0) {
                    switch (studentChoice) {
                    case 1: addStudent(&headStudent); break;
                    case 2: removeStudent(&headStudent); break;
                    case 3: updateStudent(&headStudent); break;
                    case 4: printStudent(&headStudent); break;
                    case 5: printAllStudents(&headStudent); break;
                    case 6: printOwingStudents(&headStudent, headBook); break;
                    case 7: printPunishedStudents(&headStudent); break;
                    case 8: takeBook(&headStudent, headBook); break;
                    case 9: giveBook(&headStudent, headBook); break;
                    }
                    pause();
                }
            }
            else if (choice == 2) {
                bookChoice = -1;
                do {
                    printLine();
                    printf("-----Book Menu------\n");
                    printf("1.Add book\n");
                    printf("2.Remove book\n");
                    printf("3.Update book\n");
                    printf("4.Print book details\n");
                    printf("5.Print books on shelf\n");
                    printf("6.Print borrowed books\n");
                    printf("7.Print book-author data\n");
                    printf("8.Update book's author\n");
                    printf("0.Back to Main Menu\n");
                    printLine();
                    printf("Please choose: ");
                    if (scanf("%d", &bookChoice) != 1) {
                        while (getchar() != '\n');
                        bookChoice = -1;
                    }
                    if (bookChoice < 0 || bookChoice > 8) {
                        printf("\nPlease enter a valid choice (0-8)!\n");
                    }
                    #ifdef CLEAR
                    clearScreen();
                    #endif
                } while (bookChoice < 0 || bookChoice > 8);

                if (bookChoice != 0) {
                    switch (bookChoice) {
                    case 1: addBook(&headBook, &headBookAuthor, headAuthor); break;
                    case 2: removeBook(&headBook, &headBookAuthor); break;
                    case 3: updateBook(&headBook); break;
                    case 4: printBook(&headBook); break;
                    case 5: printShelfBooks(headBook); break;
                    case 6: printOwedBooks(headBook, headStudent); break;
                    case 7: printBookAuthorMatch(&headBookAuthor, headAuthor, headBook); break;
                    case 8: updateBooksAuthor(&headBookAuthor, headAuthor, headBook); break;
                    }
                    pause();
                }
            }
            else if (choice == 3) {
                authorChoice = -1;
                do {
                    printLine();
                    printf("-----Author Menu------\n");
                    printf("1.Add author\n");
                    printf("2.Remove author\n");
                    printf("3.Update author\n");
                    printf("4.Print author details\n");
                    printf("0.Back to Main Menu\n");
                    printLine();
                    printf("Please choose: ");
                    if (scanf("%d", &authorChoice) != 1) {
                        while (getchar() != '\n');
                        authorChoice = -1;
                    }
                    if (authorChoice < 0 || authorChoice > 4) {
                        printf("\nPlease enter a valid choice (0-4)!\n");
                    }
                    #ifdef CLEAR
                    clearScreen();
                    #endif
                } while (authorChoice < 0 || authorChoice > 4);

                if (authorChoice != 0) {
                    switch (authorChoice) {
                    case 1: addAuthor(&headAuthor); break;
                    case 2: removeAuthor(&headAuthor, &headBookAuthor); break;
                    case 3: updateAuthor(&headAuthor); break;
                    case 4: printAuthor(&headAuthor); break;
                    }
                    pause();
                }
            }
        }
    }

    saveStudentsToCSV(headStudent);
    saveAuthorsToCSV(headAuthor);
    saveBooksToCSV(headBook);
    saveBookAuthorsToCSV(headBookAuthor);

    freeStudents(headStudent);
    freeAuthors(headAuthor);
    freeBooks(headBook);
    freeBookAuthors(headBookAuthor);

    printf("Exiting program. All data saved.\n");
    return 0;
}

//----------------------------------------------User Code End--------------------------------------------//

//----------------------------------------------Operation Begin------------------------------------------//

void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void printLine() {
    printf("--------------------------------------------------\n");
}

void pause() {
    int c;
    printf("\nPress ENTER to continue...");
    while ((c = getchar()) != '\n' && c != EOF);
    getchar();
}

void loadStudentsFromCSV(student **head) {
    FILE *file;
    char line[256];
    student *newNode;
    student *current;

    file = fopen("students.csv", "r");
    if (!file) {
        printf("students.csv not found or empty. Starting with no students.\n");
    }
    else {
        while (fgets(line, sizeof(line), file)) {
            newNode = (student *)malloc(sizeof(student));
            if (!newNode) {
                perror("Memory allocation failed while reading student");
                fclose(file);
                return;
            }

            if (sscanf(line, "%49[^,],%49[^,],%8[^,],%d", newNode->name, newNode->surname, newNode->studentID, &newNode->point) == 4) {
                newNode->next = NULL;
                newNode->prev = NULL;

                if (*head == NULL) {
                    *head = newNode;
                }
                else {
                    current = *head;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newNode;
                    newNode->prev = current;
                }
            }
            else {
                free(newNode);
            }
        }
        fclose(file);
    }
}

void saveStudentsToCSV(student *head) {
    FILE *file;
    student *current = head;

    file = fopen("students.csv", "w");
    if (!file) {
        perror("Failed to open students.csv for writing");
    }
    else {
        while (current != NULL) {
            fprintf(file, "%s,%s,%s,%d\n", current->name, current->surname, current->studentID, current->point);
            current = current->next;
        }
        fclose(file);
    }
}

void loadAuthorsFromCSV(author **head) {
    FILE *file;
    char line[256];
    author *newNode;
    author *current;

    file = fopen("authors.csv", "r");
    if (!file) {
        printf("authors.csv not found or empty. Starting with no authors.\n");
    }
    else {
        while (fgets(line, sizeof(line), file)) {
            newNode = (author *)malloc(sizeof(author));
            if (!newNode) {
                perror("Memory allocation failed while reading author");
                fclose(file);
                return;
            }

            if (sscanf(line, "%49[^,],%49[^,],%u", newNode->name, newNode->surname, &newNode->authorID) == 3) {
                newNode->next = NULL;
                if (*head == NULL) {
                    *head = newNode;
                }
                else {
                    current = *head;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
            else {
                free(newNode);
            }
        }
        fclose(file);
    }
}

void saveAuthorsToCSV(author *head) {
    FILE *file;
    author *current = head;

    file = fopen("authors.csv", "w");
    if (!file) {
        perror("Failed to open authors.csv for writing");
    }
    else {
        while (current != NULL) {
            fprintf(file, "%s,%s,%u\n", current->name, current->surname, current->authorID);
            current = current->next;
        }
        fclose(file);
    }
}

void loadBooksFromCSV(book **head) {
    FILE *file;
    char line[256];
    book *newNode;
    book *current;

    file = fopen("bookData.csv", "r");
    if (!file) {
        printf("bookData.csv not found or empty. Starting with no books.\n");
    }
    else {
        while (fgets(line, sizeof(line), file)) {
            newNode = (book *)malloc(sizeof(book));
            if (!newNode) {
                perror("Memory allocation failed while reading book");
                fclose(file);
                return;
            }

            if (sscanf(line, "%49[^,],%13[^,],%u", newNode->name, newNode->ISBN, &newNode->number) == 3) {
                newNode->next = NULL;
                if (*head == NULL) {
                    *head = newNode;
                }
                else {
                    current = *head;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
            else {
                free(newNode);
            }
        }
        fclose(file);
    }
}

void saveBooksToCSV(book *head) {
    FILE *file;
    book *current = head;

    file = fopen("bookData.csv", "w");
    if (!file) {
        perror("Failed to open bookData.csv for writing");
    }
    else {
        while (current != NULL) {
            fprintf(file, "%s,%s,%u\n", current->name, current->ISBN, current->number);
            current = current->next;
        }
        fclose(file);
    }
}

void loadBookAuthorsFromCSV(bookAuthor **headBA) {
    FILE *file;
    char line[256];
    bookAuthor *newNode;
    bookAuthor *current;

    file = fopen("bookAuthor.csv", "r");
    if (!file) {
        printf("bookAuthor.csv not found or empty. Starting with no book-author links.\n");
    }
    else {
        while (fgets(line, sizeof(line), file)) {
            newNode = (bookAuthor *)malloc(sizeof(bookAuthor));
            if (!newNode) {
                perror("Memory allocation failed while reading bookAuthor link");
                fclose(file);
                return;
            }

            if (sscanf(line, "%13[^,],%d", newNode->ISBN, &newNode->authorID) == 2) {
                newNode->next = NULL;
                if (*headBA == NULL) {
                    *headBA = newNode;
                }
                else {
                    current = *headBA;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newNode;
                }
            }
            else {
                free(newNode);
            }
        }
        fclose(file);
    }
}

void saveBookAuthorsToCSV(bookAuthor *headBA) {
    FILE *file;
    bookAuthor *current = headBA;

    file = fopen("bookAuthor.csv", "w");
    if (!file) {
        perror("Failed to open bookAuthor.csv for writing");
    }
    else {
        while (current != NULL) {
            fprintf(file, "%s,%d\n", current->ISBN, current->authorID);
            current = current->next;
        }
        fclose(file);
    }
}

void freeStudents(student *head) {
    student *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeAuthors(author *head) {
    author *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeBooks(book *head) {
    book *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void freeBookAuthors(bookAuthor *head) {
    bookAuthor *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

//----------------------------------------------Operation End--------------------------------------------//

//----------------------------------------------Function Begin-------------------------------------------//

void addStudent(student **head) {
    student *newNode;
    student *current;
    student *id_iterator;
    unsigned long maxID = 0;
    unsigned long tempID_val;
    student *tail_finder;

    newNode = (student *)malloc(sizeof(student));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("\nPlease enter the student name: ");
    scanf("%49s", newNode->name);
    printf("Please enter the student surname: ");
    scanf("%49s", newNode->surname);
    newNode->point = 100;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        strcpy(newNode->studentID, "10000000");
        *head = newNode;
    }
    else {
        current = *head;
        maxID = 0;
        if (current != NULL) {
            maxID = strtoul(current->studentID, NULL, 10);
            id_iterator = current;
            while (id_iterator != NULL) {
                tempID_val = strtoul(id_iterator->studentID, NULL, 10);
                if (tempID_val > maxID) {
                    maxID = tempID_val;
                }
                id_iterator = id_iterator->next;
            }
        }
        sprintf(newNode->studentID, "%08lu", maxID + 1);

        tail_finder = *head;
        while (tail_finder->next != NULL) {
            tail_finder = tail_finder->next;
        }
        tail_finder->next = newNode;
        newNode->prev = tail_finder;
    }

    saveStudentsToCSV(*head);
    printf("Student %s %s with ID %s added successfully.\n", newNode->name, newNode->surname, newNode->studentID);
}

void removeStudent(student **head) {
    char targetID[9];
    student *current;
    int found_flag = 0;

    if (*head == NULL) {
        printf("No students to remove.\n");
        return;
    }

    printf("Enter the Student ID to remove: ");
    scanf("%8s", targetID);

    current = *head;
    while (current != NULL && !found_flag) {
        if (strcmp(current->studentID, targetID) == 0) {
            if (current->prev == NULL) {
                *head = current->next;
                if (*head != NULL) {
                    (*head)->prev = NULL;
                }
            }
            else {
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            printf("Student %s %s (ID: %s) removed.\n", current->name, current->surname, current->studentID);
            free(current);
            saveStudentsToCSV(*head);
            found_flag = 1;
        }
        if (!found_flag) {
            current = current->next;
        }
    }
    if (!found_flag) {
        printf("Student with ID %s not found.\n", targetID);
    }
}

void updateStudent(student **head) {
    char targetID[9];
    student *current;
    int found_flag = 0;

    if (*head == NULL) {
        printf("No students to update.\n");
        return;
    }
    printf("Enter the Student ID to update: ");
    scanf("%8s", targetID);

    current = *head;
    while (current != NULL && !found_flag) {
        if (strcmp(current->studentID, targetID) == 0) {
            printf("Updating student: %s %s (ID: %s)\n", current->name, current->surname, current->studentID);
            printf("Enter new name (current: %s): ", current->name);
            scanf("%49s", current->name);
            printf("Enter new surname (current: %s): ", current->surname);
            scanf("%49s", current->surname);
            printf("Enter new point (current: %d): ", current->point);
            scanf("%d", &current->point);

            saveStudentsToCSV(*head);
            printf("Student updated successfully.\n");
            found_flag = 1;
        }
        if (!found_flag) {
            current = current->next;
        }
    }
    if (!found_flag) {
        printf("Student with ID %s not found.\n", targetID);
    }
}

void printStudent(student **head) {
    int choice;
    char inputID[9];
    char inputName[MAX_LEN];
    char inputSurname[MAX_LEN];
    student *current;
    int found = 0;
    int loop_flag = 0;

    if (*head == NULL) {
        printf("No students in the list.\n");
        return;
    }

    printf("Search by:\n1. Student ID\n2. Name and Surname\nChoice: ");
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("Invalid choice format.\n");
        return;
    }

    current = *head;
    if (choice == 1) {
        printf("Enter student ID: ");
        scanf("%8s", inputID);
        while (current != NULL && !loop_flag) {
            if (strcmp(current->studentID, inputID) == 0) {
                printf("\nName: %s\nSurname: %s\nStudent ID: %s\nPoint: %d\n",
                    current->name, current->surname, current->studentID, current->point);
                found = 1;
                loop_flag = 1;
            }
            if (!loop_flag) {
                current = current->next;
            }
        }
    }
    else if (choice == 2) {
        printf("Enter name: ");
        scanf("%49s", inputName);
        printf("Enter surname: ");
        scanf("%49s", inputSurname);
        while (current != NULL) {
            if (strcmp(current->name, inputName) == 0 && strcmp(current->surname, inputSurname) == 0) {
                printf("\nName: %s\nSurname: %s\nStudent ID: %s\nPoint: %d\n",
                    current->name, current->surname, current->studentID, current->point);
                found = 1;
            }
            current = current->next;
        }
    }
    else {
        printf("Invalid choice.\n");
        return;
    }
    if (!found) {
        printf("Student not found.\n");
    }
}

void displaySingleStudentDetail(student *s_node) {
    if (s_node != NULL) {
        printf("Name: %-20s Surname: %-20s Student ID: %s Point: %d\n",
            s_node->name, s_node->surname, s_node->studentID, s_node->point);
    }
}

void forEachStudent(student *head, void (*action)(student *s_node)) {
    student *current = head;
    while (current != NULL) {
        action(current);
        current = current->next;
    }
}

void printAllStudents(student **head) {
    if (*head == NULL) {
        printf("No students in the list.\n");
        return;
    }
    printf("\n--- All Students ---\n");
    forEachStudent(*head, displaySingleStudentDetail);
    printLine();
}

void printOwingStudents(student **head, book *headBook) {
    FILE *file;
    char line[256];
    char csv_studentID[9];
    char csv_tag[MAX_LEN];
    char csv_action[2];
    char csv_date[20];
    int found_owing_overall = 0;
    student *current_student_node;
    int student_match_found_flag;

    file = fopen("bookTaken.csv", "r");
    if (!file) {
        perror("Failed to open bookTaken.csv");
        return;
    }

    printf("\n--- Students with Unreturned Books ---\n");

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%8[^,],%49[^,],%1[^,],%19[^\n]", csv_studentID, csv_tag, csv_action, csv_date) >= 3) {
            if (strcmp(csv_action, "0") == 0 && strcmp(csv_studentID, "Rafta") != 0) {
                current_student_node = *head;
                student_match_found_flag = 0;
                while (current_student_node != NULL && !student_match_found_flag) {
                    if (strcmp(current_student_node->studentID, csv_studentID) == 0) {
                        printf("Student: %s %s (ID: %s) owes Book Tag: %s (Borrowed on: %s)\n",
                            current_student_node->name, current_student_node->surname, current_student_node->studentID,
                            csv_tag, csv_date);
                        found_owing_overall = 1;
                        student_match_found_flag = 1;
                    }
                    if (!student_match_found_flag) {
                        current_student_node = current_student_node->next;
                    }
                }
            }
        }
    }

    if (!found_owing_overall) {
        printf("No students currently owe books.\n");
    }
    printLine();
    fclose(file);
}

void printPunishedStudents(student **head) {
    student *current;
    int found = 0;

    if (*head == NULL) {
        printf("No students in the list.\n");
        return;
    }
    current = *head;
    printf("\n--- Students with Penalty (Points < 100) ---\n");
    while (current) {
        if (current->point < 100) {
            printf("Name: %s %s (ID: %s) - Points: %d\n", current->name, current->surname, current->studentID, current->point);
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("No students currently have penalty points.\n");
    }
    printLine();
}

void takeBook(student **headStudent, book *headBookList) {
    char studentID[9];
    char bookTag[MAX_LEN];
    student *s_current;
    int student_found = 0;
    char isbn_part[14];
    unsigned int copy_num_part = 0;
    book *b_current;
    int book_isbn_exists = 0;
    unsigned int total_copies_for_isbn = 0;
    FILE *takenFile;
    char line[256];
    char lastActionForTag = ' ';
    char current_sID_in_file[9];
    char current_tag_in_file[MAX_LEN];
    char current_action_str[2];
    int tag_ever_recorded = 0;
    time_t now;
    char date[20];
    int student_loop_flag = 0;
    int book_loop_flag = 0;

    printf("Enter student ID: ");
    scanf("%8s", studentID);

    s_current = *headStudent;
    while (s_current && !student_loop_flag) {
        if (strcmp(s_current->studentID, studentID) == 0) {
            student_found = 1;
            if (s_current->point <= 0) {
                printf("Student %s %s (ID: %s) has 0 or fewer points. Cannot borrow books.\n", s_current->name, s_current->surname, s_current->studentID);
                return;
            }
            student_loop_flag = 1;
        }
        if (!student_loop_flag) {
            s_current = s_current->next;
        }
    }
    if (!student_found) {
        printf("Student with ID %s not found.\n", studentID);
        return;
    }

    printf("Enter book tag to borrow (e.g., ISBN_CopyNumber like 1234567890123_1): ");
    scanf("%49s", bookTag);

    if (sscanf(bookTag, "%13[^_]_%u", isbn_part, &copy_num_part) != 2) {
        printf("Invalid book tag format. Expected ISBN_CopyNumber.\n");
        return;
    }

    b_current = headBookList;
    while (b_current && !book_loop_flag) {
        if (strcmp(b_current->ISBN, isbn_part) == 0) {
            book_isbn_exists = 1;
            total_copies_for_isbn = b_current->number;
            book_loop_flag = 1;
        }
        if (!book_loop_flag) {
            b_current = b_current->next;
        }
    }
    if (!book_isbn_exists) {
        printf("No book found with ISBN %s.\n", isbn_part);
        return;
    }
    if (copy_num_part == 0 || copy_num_part > total_copies_for_isbn) {
        printf("Invalid copy number %u for ISBN %s (Total copies: %u).\n", copy_num_part, isbn_part, total_copies_for_isbn);
        return;
    }

    takenFile = fopen("bookTaken.csv", "r");
    if (!takenFile) {
        perror("Failed to open bookTaken.csv for checking availability");
        return;
    }

    while (fgets(line, sizeof(line), takenFile)) {
        if (sscanf(line, "%8[^,],%49[^,],%1[^,]", current_sID_in_file, current_tag_in_file, current_action_str) >= 3) {
            if (strcmp(current_tag_in_file, bookTag) == 0) {
                lastActionForTag = current_action_str[0];
                tag_ever_recorded = 1;
            }
        }
    }
    fclose(takenFile);

    if (!tag_ever_recorded) {
        printf("Book tag %s has no record. It might not have been properly added to the system.\n", bookTag);
        return;
    }

    if (lastActionForTag == '0') {
        printf("Book copy %s is currently taken.\n", bookTag);
        return;
    }

    takenFile = fopen("bookTaken.csv", "a");
    if (!takenFile) {
        perror("Failed to open bookTaken.csv for appending");
        return;
    }

    now = time(NULL);
    strftime(date, sizeof(date), "%d-%m-%Y", localtime(&now));

    fprintf(takenFile, "%s,%s,0,%s\n", studentID, bookTag, date);
    fclose(takenFile);
    printf("Book %s taken by student %s successfully on %s.\n", bookTag, studentID, date);
}


void giveBook(student **headStudent, book *headBookList) {
    char studentID[9];
    char bookTag[MAX_LEN];
    student *s_ptr;
    int student_exists = 0;
    FILE *in;
    FILE *out;
    char line[256];
    char sid_from_file[9];
    char tag_from_file[MAX_LEN];
    char action_from_file[2];
    char oldDate_from_file[20];
    int record_updated = 0;
    char specific_borrow_date[20] = "";
    time_t now_time;
    char return_date_str[20];
    struct tm t1 = { 0 };
    time_t borrowed_time;
    double diff_days;
    student *current_student;
    int student_search_flag = 0;
    int penalty_student_search_flag = 0;


    printf("Enter student ID returning the book: ");
    scanf("%8s", studentID);
    printf("Enter book tag being returned (e.g., ISBN_CopyNumber): ");
    scanf("%49s", bookTag);

    s_ptr = *headStudent;
    while (s_ptr && !student_search_flag) {
        if (strcmp(s_ptr->studentID, studentID) == 0) {
            student_exists = 1;
            student_search_flag = 1;
        }
        if (!student_search_flag) {
            s_ptr = s_ptr->next;
        }
    }
    if (!student_exists) {
        printf("Student with ID %s not found.\n", studentID);
        return;
    }

    in = fopen("bookTaken.csv", "r");
    out = fopen("bookTaken_temp.csv", "w");
    if (!in || !out) {
        perror("Failed to process bookTaken.csv files");
        if (in) fclose(in);
        if (out) fclose(out);
        return;
    }

    while (fgets(line, sizeof(line), in)) {
        if (sscanf(line, "%8[^,],%49[^,],%1[^,],%19[^\n]", sid_from_file, tag_from_file, action_from_file, oldDate_from_file) >= 3) {
            if (strcmp(sid_from_file, studentID) == 0 &&
                strcmp(tag_from_file, bookTag) == 0 &&
                strcmp(action_from_file, "0") == 0 && !record_updated) {

                strcpy(specific_borrow_date, oldDate_from_file);

                now_time = time(NULL);
                strftime(return_date_str, sizeof(return_date_str), "%d-%m-%Y", localtime(&now_time));

                fprintf(out, "%s,%s,1,%s\n", sid_from_file, tag_from_file, return_date_str);
                record_updated = 1;

                if (sscanf(specific_borrow_date, "%d-%d-%d", &t1.tm_mday, &t1.tm_mon, &t1.tm_year) == 3) {
                    t1.tm_mon -= 1;
                    t1.tm_year -= 1900;
                    t1.tm_isdst = -1;
                    borrowed_time = mktime(&t1);

                    if (borrowed_time != -1) {
                        diff_days = difftime(now_time, borrowed_time) / (60.0 * 60.0 * 24.0);
                        if (diff_days > 15.0) {
                            current_student = *headStudent;
                            penalty_student_search_flag = 0;
                            while (current_student && !penalty_student_search_flag) {
                                if (strcmp(current_student->studentID, studentID) == 0) {
                                    current_student->point -= 10;
                                    printf("Book returned late. 10 penalty points deducted. Current points: %d\n", current_student->point);
                                    saveStudentsToCSV(*headStudent);
                                    penalty_student_search_flag = 1;
                                }
                                if (!penalty_student_search_flag) {
                                    current_student = current_student->next;
                                }
                            }
                        }
                    }
                    else {
                        printf("Warning: Could not parse borrow date '%s' for penalty calculation.\n", specific_borrow_date);
                    }
                }
                else {
                    printf("Warning: Borrow date '%s' format error for penalty calculation.\n", specific_borrow_date);
                }
            }
            else {
                fputs(line, out);
            }
        }
        else {
            fputs(line, out);
        }
    }

    fclose(in);
    fclose(out);

    if (record_updated) {
        remove("bookTaken.csv");
        rename("bookTaken_temp.csv", "bookTaken.csv");
        printf("Book %s returned by student %s.\n", bookTag, studentID);
    }
    else {
        remove("bookTaken_temp.csv");
        printf("No active borrow record found for student %s and book tag %s.\n", studentID, bookTag);
    }
}

void addBook(book **headBook, bookAuthor **headBA, author *headAuthorList) {
    book *newBook;
    book *check_b;
    FILE *takenFile;
    unsigned int i;
    char choice_char_link_author;
    int authID_input;
    author *auth_check_ptr;
    int author_exists_flag = 0;
    bookAuthor *newLink_ba;
    bookAuthor *ba_curr_ptr;
    book *current_book_list_ptr;
    int isbn_already_exists_flag = 0;

    newBook = (book *)malloc(sizeof(book));
    if (!newBook) {
        perror("Memory allocation failed for book");
        return;
    }

    printf("Enter book name: ");
    scanf(" %49[^\n]", newBook->name);
    getchar();

    printf("Enter 13-digit ISBN: ");
    scanf("%13s", newBook->ISBN);
    getchar();

    check_b = *headBook;
    isbn_already_exists_flag = 0;
    while (check_b != NULL && !isbn_already_exists_flag) {
        if (strcmp(check_b->ISBN, newBook->ISBN) == 0) {
            isbn_already_exists_flag = 1;
        }
        if (!isbn_already_exists_flag) {
            check_b = check_b->next;
        }
    }
    if (isbn_already_exists_flag) {
        printf("Book with ISBN %s already exists: %s. Cannot add duplicate ISBN.\n", newBook->ISBN, check_b->name);
        free(newBook);
        return;
    }

    printf("How many copies to add: ");
    if (scanf("%u", &newBook->number) != 1 || newBook->number == 0) {
        printf("Invalid number of copies. Must be a positive integer.\n");
        free(newBook);
        while (getchar() != '\n');
        return;
    }
    getchar();

    newBook->next = NULL;

    if (*headBook == NULL) {
        *headBook = newBook;
    }
    else {
        current_book_list_ptr = *headBook;
        while (current_book_list_ptr->next != NULL) {
            current_book_list_ptr = current_book_list_ptr->next;
        }
        current_book_list_ptr->next = newBook;
    }
    saveBooksToCSV(*headBook);

    takenFile = fopen("bookTaken.csv", "a");
    if (!takenFile) {
        perror("Failed to open bookTaken.csv to add initial copies");
    }
    else {
        for (i = 1; i <= newBook->number; i++) {
            fprintf(takenFile, "Rafta,%s_%u,1,\n", newBook->ISBN, i);
        }
        fclose(takenFile);
    }

    printf("Do you want to link an author to this book (ISBN: %s)? (y/n): ", newBook->ISBN);
    scanf(" %c", &choice_char_link_author);
    getchar();
    if (choice_char_link_author == 'y' || choice_char_link_author == 'Y') {
        printf("Enter Author ID to link: ");
        if (scanf("%d", &authID_input) == 1) {
            getchar();

            auth_check_ptr = headAuthorList;
            author_exists_flag = 0;
            while (auth_check_ptr != NULL && !author_exists_flag) {
                if (auth_check_ptr->authorID == (unsigned int)authID_input) {
                    author_exists_flag = 1;
                }
                if (!author_exists_flag) {
                    auth_check_ptr = auth_check_ptr->next;
                }
            }

            if (author_exists_flag) {
                newLink_ba = (bookAuthor *)malloc(sizeof(bookAuthor));
                if (newLink_ba) {
                    strcpy(newLink_ba->ISBN, newBook->ISBN);
                    newLink_ba->authorID = authID_input;
                    newLink_ba->next = NULL;

                    if (*headBA == NULL) {
                        *headBA = newLink_ba;
                    }
                    else {
                        ba_curr_ptr = *headBA;
                        while (ba_curr_ptr->next != NULL) {
                            ba_curr_ptr = ba_curr_ptr->next;
                        }
                        ba_curr_ptr->next = newLink_ba;
                    }
                    saveBookAuthorsToCSV(*headBA);
                    printf("Book linked to author ID %d.\n", authID_input);
                }
                else {
                    perror("Memory allocation failed for book-author link");
                }
            }
            else {
                printf("Author ID %d not found. Book not linked.\n", authID_input);
            }
        }
        else {
            while (getchar() != '\n');
            printf("Invalid Author ID format.\n");
        }
    }
    printf("Book '%s' (ISBN: %s) with %u copie(s) added.\n", newBook->name, newBook->ISBN, newBook->number);
}

void removeBook(book **headBook, bookAuthor **headBA) {
    char targetISBN[14];
    book *current_b, *prev_b;
    int found_b_flag = 0;
    FILE *takenIn, *takenOut;
    char line[256], sID[9], tag[MAX_LEN], action[2], date[20];
    int removed_taken_count = 0;
    char isbn_from_tag[14];
    bookAuthor *baCurrent, *baPrev;
    int ba_loop_flag = 0;


    if (*headBook == NULL) {
        printf("No books available to remove.\n");
        return;
    }

    printf("Enter ISBN of the book to remove: ");
    scanf("%13s", targetISBN);

    current_b = *headBook;
    prev_b = NULL;
    found_b_flag = 0;
    while (current_b != NULL && !found_b_flag) {
        if (strcmp(current_b->ISBN, targetISBN) == 0) {
            if (prev_b == NULL) {
                *headBook = current_b->next;
            }
            else {
                prev_b->next = current_b->next;
            }
            printf("Book '%s' (ISBN: %s) removed from master list.\n", current_b->name, current_b->ISBN);
            free(current_b);
            found_b_flag = 1;
        }
        if (!found_b_flag) {
            prev_b = current_b;
            current_b = current_b->next;
        }
    }

    if (!found_b_flag) {
        printf("Book with ISBN %s not found in master list.\n", targetISBN);
        return;
    }

    saveBooksToCSV(*headBook);

    takenIn = fopen("bookTaken.csv", "r");
    takenOut = fopen("bookTaken_temp.csv", "w");
    if (!takenIn || !takenOut) {
        perror("Error processing bookTaken.csv for book removal");
        if (takenIn) fclose(takenIn);
        if (takenOut) fclose(takenOut);
    }
    else {
        removed_taken_count = 0;
        while (fgets(line, sizeof(line), takenIn)) {
            if (sscanf(line, "%8[^,],%49[^,],%1[^,],%19[^\n]", sID, tag, action, date) >= 3) {
                sscanf(tag, "%13[^_]", isbn_from_tag);
                if (strcmp(isbn_from_tag, targetISBN) != 0) {
                    fputs(line, takenOut);
                }
                else {
                    removed_taken_count++;
                }
            }
            else {
                fputs(line, takenOut);
            }
        }
        fclose(takenIn);
        fclose(takenOut);
        remove("bookTaken.csv");
        rename("bookTaken_temp.csv", "bookTaken.csv");
        printf("%d entries removed from bookTaken.csv for ISBN %s.\n", removed_taken_count, targetISBN);
    }

    baCurrent = *headBA;
    baPrev = NULL;
    while (baCurrent != NULL) {
        ba_loop_flag = 0;
        if (strcmp(baCurrent->ISBN, targetISBN) == 0) {
            if (baPrev == NULL) {
                *headBA = baCurrent->next;
                free(baCurrent);
                baCurrent = *headBA;
            }
            else {
                baPrev->next = baCurrent->next;
                free(baCurrent);
                baCurrent = baPrev->next;
            }
            printf("Link for ISBN %s removed from book-author links.\n", targetISBN);
            ba_loop_flag = 1;
        }
        if (!ba_loop_flag) {
            baPrev = baCurrent;
            baCurrent = baCurrent->next;
        }
    }
    saveBookAuthorsToCSV(*headBA);
}


void updateBook(book **headBook) {
    char targetISBN[14];
    book *current;
    int found_flag = 0;

    if (*headBook == NULL) {
        printf("No books to update.\n");
        return;
    }

    printf("Enter ISBN of the book to update: ");
    scanf("%13s", targetISBN);

    current = *headBook;
    while (current && !found_flag) {
        if (strcmp(current->ISBN, targetISBN) == 0) {
            printf("Updating book: %s (ISBN: %s)\n", current->name, current->ISBN);
            printf("Enter new book name (current: %s): ", current->name);
            scanf(" %49[^\n]", current->name);
            getchar();
            saveBooksToCSV(*headBook);
            printf("Book details updated.\n");
            found_flag = 1;
        }
        if (!found_flag) {
            current = current->next;
        }
    }
    if (!found_flag) {
        printf("Book with ISBN %s not found.\n", targetISBN);
    }
}

void printBook(book **headBook) {
    char search_term[MAX_LEN];
    int search_choice;
    book *current;
    int found = 0;
    int loop_flag = 0;

    if (*headBook == NULL) {
        printf("No books in the list.\n");
        return;
    }

    printf("Search book by:\n1. ISBN\n2. Name\nChoice: ");
    if (scanf("%d", &search_choice) != 1) {
        while (getchar() != '\n');
        printf("Invalid choice.\n"); return;
    }
    getchar();

    current = *headBook;
    if (search_choice == 1) {
        printf("Enter ISBN: ");
        scanf("%13s", search_term);
        getchar();
        while (current && !loop_flag) {
            if (strcmp(current->ISBN, search_term) == 0) {
                printf("\nName: %s\nISBN: %s\nTotal Copies: %u\n", current->name, current->ISBN, current->number);
                found = 1;
                loop_flag = 1;
            }
            if (!loop_flag) {
                current = current->next;
            }
        }
    }
    else if (search_choice == 2) {
        printf("Enter book name (or part of it): ");
        scanf("%49[^\n]", search_term);
        getchar();
        while (current) {
            if (strstr(current->name, search_term) != NULL) {
                printf("\nName: %s\nISBN: %s\nTotal Copies: %u\n", current->name, current->ISBN, current->number);
                found = 1;
            }
            current = current->next;
        }
    }
    else {
        printf("Invalid search choice.\n");
        return;
    }

    if (!found) {
        printf("No book found matching your criteria.\n");
    }
}


void printShelfBooks(book *headBookList) {
    FILE *file;
    typedef struct TagStatus {
        char tag[MAX_LEN];
        char action;
        char studentID[9];
        struct TagStatus *next;
    } TagStatus;
    TagStatus *statusHead = NULL;
    TagStatus *current_status, *prev_status, *new_status_entry, *print_status, *temp_free;
    char line[256];
    char sID_csv[9], tag_csv[MAX_LEN], action_csv_str[2];
    int found_tag_in_status;
    int shelf_count = 0;
    char isbn_part[14];
    book *b_info;
    char book_name_info[MAX_LEN];
    int b_info_found_flag;


    file = fopen("bookTaken.csv", "r");
    if (!file) {
        perror("Failed to open bookTaken.csv");
        return;
    }
    printf("\n--- Books Currently On Shelf (based on latest bookTaken.csv entries) ---\n");

    statusHead = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%8[^,],%49[^,],%1[^,]", sID_csv, tag_csv, action_csv_str) >= 3) {
            current_status = statusHead;
            prev_status = NULL;
            found_tag_in_status = 0;
            while (current_status && !found_tag_in_status) {
                if (strcmp(current_status->tag, tag_csv) == 0) {
                    current_status->action = action_csv_str[0];
                    strcpy(current_status->studentID, sID_csv);
                    found_tag_in_status = 1;
                }
                if (!found_tag_in_status) {
                    prev_status = current_status;
                    current_status = current_status->next;
                }
            }
            if (!found_tag_in_status) {
                new_status_entry = (TagStatus *)malloc(sizeof(TagStatus));
                if (new_status_entry) {
                    strcpy(new_status_entry->tag, tag_csv);
                    new_status_entry->action = action_csv_str[0];
                    strcpy(new_status_entry->studentID, sID_csv);
                    new_status_entry->next = NULL;
                    if (statusHead == NULL) statusHead = new_status_entry;
                    else prev_status->next = new_status_entry;
                }
            }
        }
    }
    fclose(file);

    shelf_count = 0;
    print_status = statusHead;
    while (print_status) {
        if (print_status->action == '1') {
            sscanf(print_status->tag, "%13[^_]", isbn_part);
            b_info = headBookList;
            strcpy(book_name_info, "N/A");
            b_info_found_flag = 0;
            while (b_info && !b_info_found_flag) {
                if (strcmp(b_info->ISBN, isbn_part) == 0) {
                    strcpy(book_name_info, b_info->name);
                    b_info_found_flag = 1;
                }
                if (!b_info_found_flag) {
                    b_info = b_info->next;
                }
            }
            printf("Tag: %-20s (Book: %s)\n", print_status->tag, book_name_info);
            shelf_count++;
        }
        temp_free = print_status;
        print_status = print_status->next;
        free(temp_free);
    }

    if (shelf_count == 0) {
        printf("No books are currently on the shelf according to records.\n");
    }
    printLine();
}


void printOwedBooks(book *headBookList, student *headStudentList) {
    FILE *file;
    typedef struct TagStatus {
        char tag[MAX_LEN];
        char action;
        char studentID[9];
        char date[20];
        struct TagStatus *next;
    } TagStatus;
    TagStatus *statusHead = NULL;
    TagStatus *current_status, *prev_status, *new_status_entry, *print_status, *temp_free;
    char line[256];
    char sID_csv[9], tag_csv[MAX_LEN], action_csv_str[2], date_csv[20];
    int found_tag_in_status;
    int owed_count = 0;
    student *s_info;
    char student_name_info[MAX_LEN * 2];
    char isbn_part[14];
    book *b_info;
    char book_name_info[MAX_LEN];
    int s_info_found_flag, b_info_found_flag;


    file = fopen("bookTaken.csv", "r");
    if (!file) {
        perror("Failed to open bookTaken.csv");
        return;
    }
    printf("\n--- Books Currently Borrowed (based on latest bookTaken.csv entries) ---\n");

    statusHead = NULL;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%8[^,],%49[^,],%1[^,],%19[^\n]", sID_csv, tag_csv, action_csv_str, date_csv) == 4) {
            current_status = statusHead;
            prev_status = NULL;
            found_tag_in_status = 0;
            while (current_status && !found_tag_in_status) {
                if (strcmp(current_status->tag, tag_csv) == 0) {
                    current_status->action = action_csv_str[0];
                    strcpy(current_status->studentID, sID_csv);
                    strcpy(current_status->date, date_csv);
                    found_tag_in_status = 1;
                }
                if (!found_tag_in_status) {
                    prev_status = current_status;
                    current_status = current_status->next;
                }
            }
            if (!found_tag_in_status) {
                new_status_entry = (TagStatus *)malloc(sizeof(TagStatus));
                if (new_status_entry) {
                    strcpy(new_status_entry->tag, tag_csv);
                    new_status_entry->action = action_csv_str[0];
                    strcpy(new_status_entry->studentID, sID_csv);
                    strcpy(new_status_entry->date, date_csv);
                    new_status_entry->next = NULL;
                    if (statusHead == NULL) statusHead = new_status_entry;
                    else prev_status->next = new_status_entry;
                }
            }
        }
    }
    fclose(file);

    owed_count = 0;
    print_status = statusHead;
    while (print_status) {
        if (print_status->action == '0' && strcmp(print_status->studentID, "Rafta") != 0) {
            s_info = headStudentList;
            strcpy(student_name_info, "N/A");
            s_info_found_flag = 0;
            while (s_info && !s_info_found_flag) {
                if (strcmp(s_info->studentID, print_status->studentID) == 0) {
                    sprintf(student_name_info, "%s %s", s_info->name, s_info->surname);
                    s_info_found_flag = 1;
                }
                if (!s_info_found_flag) {
                    s_info = s_info->next;
                }
            }

            sscanf(print_status->tag, "%13[^_]", isbn_part);
            b_info = headBookList;
            strcpy(book_name_info, "N/A");
            b_info_found_flag = 0;
            while (b_info && !b_info_found_flag) {
                if (strcmp(b_info->ISBN, isbn_part) == 0) {
                    strcpy(book_name_info, b_info->name);
                    b_info_found_flag = 1;
                }
                if (!b_info_found_flag) {
                    b_info = b_info->next;
                }
            }

            printf("Tag: %-20s (Book: %s) - Borrowed by: %s (ID: %s) on %s\n",
                print_status->tag, book_name_info, student_name_info, print_status->studentID, print_status->date);
            owed_count++;
        }
        temp_free = print_status;
        print_status = print_status->next;
        free(temp_free);
    }

    if (owed_count == 0) {
        printf("No books are currently borrowed according to records.\n");
    }
    printLine();
}


void printBookAuthorMatch(bookAuthor **headBA, author *headAuthorList, book *headBookList) {
    bookAuthor *current;
    char bookName[MAX_LEN];
    char authorName[MAX_LEN * 2];
    book *b;
    author *a;
    int b_found_flag, a_found_flag;

    if (*headBA == NULL) {
        printf("No book-author links available.\n");
        return;
    }
    printf("\n--- Book-Author Matches ---\n");
    current = *headBA;
    while (current) {
        strcpy(bookName, "N/A (ISBN not in book list)");
        strcpy(authorName, "N/A (Author ID not in author list or -1)");

        b = headBookList;
        b_found_flag = 0;
        while (b && !b_found_flag) {
            if (strcmp(b->ISBN, current->ISBN) == 0) {
                strcpy(bookName, b->name);
                b_found_flag = 1;
            }
            if (!b_found_flag) {
                b = b->next;
            }
        }

        if (current->authorID != -1) {
            a = headAuthorList;
            a_found_flag = 0;
            while (a && !a_found_flag) {
                if (a->authorID == (unsigned int)current->authorID) {
                    sprintf(authorName, "%s %s", a->name, a->surname);
                    a_found_flag = 1;
                }
                if (!a_found_flag) {
                    a = a->next;
                }
            }
        }
        else {
            strcpy(authorName, "Author not assigned or removed");
        }

        printf("Book: '%s' (ISBN: %s) --- Author: %s (ID: %d)\n",
            bookName, current->ISBN, authorName, current->authorID);
        current = current->next;
    }
    printLine();
}

void updateBooksAuthor(bookAuthor **headBA, author *headAuthorList, book *headBookList) {
    char targetISBN[14];
    int newAuthorID;
    book *b_check;
    int isbn_exists = 0;
    author *auth_check;
    int author_id_valid = 0;
    bookAuthor *current_ba, *newLink_ba, *temp_ba;
    int link_found_and_updated = 0;
    int b_check_flag = 0;
    int auth_check_flag = 0;
    int current_ba_flag = 0;


    printf("Enter book ISBN to update its author: ");
    scanf("%13s", targetISBN);
    getchar();

    b_check = headBookList;
    b_check_flag = 0;
    while (b_check && !b_check_flag) {
        if (strcmp(b_check->ISBN, targetISBN) == 0) {
            isbn_exists = 1;
            printf("Selected book: %s\n", b_check->name);
            b_check_flag = 1;
        }
        if (!b_check_flag) {
            b_check = b_check->next;
        }
    }
    if (!isbn_exists) {
        printf("Book with ISBN %s not found in the master book list.\n", targetISBN);
        return;
    }

    printf("Enter new Author ID to assign (or -1 to unassign): ");
    if (scanf("%d", &newAuthorID) != 1) {
        while (getchar() != '\n');
        printf("Invalid Author ID format.\n");
        return;
    }
    getchar();

    if (newAuthorID != -1) {
        auth_check = headAuthorList;
        auth_check_flag = 0;
        while (auth_check && !auth_check_flag) {
            if (auth_check->authorID == (unsigned int)newAuthorID) {
                author_id_valid = 1;
                printf("Assigning to author: %s %s\n", auth_check->name, auth_check->surname);
                auth_check_flag = 1;
            }
            if (!auth_check_flag) {
                auth_check = auth_check->next;
            }
        }
        if (!author_id_valid) {
            printf("Author ID %d not found. Cannot assign.\n", newAuthorID);
            return;
        }
    }

    current_ba = *headBA;
    current_ba_flag = 0;
    while (current_ba && !current_ba_flag) {
        if (strcmp(current_ba->ISBN, targetISBN) == 0) {
            current_ba->authorID = newAuthorID;
            link_found_and_updated = 1;
            current_ba_flag = 1;
        }
        if (!current_ba_flag) {
            current_ba = current_ba->next;
        }
    }

    if (!link_found_and_updated) {
        newLink_ba = (bookAuthor *)malloc(sizeof(bookAuthor));
        if (!newLink_ba) {
            perror("Memory allocation failed for new book-author link");
            return;
        }
        strcpy(newLink_ba->ISBN, targetISBN);
        newLink_ba->authorID = newAuthorID;
        newLink_ba->next = NULL;

        if (*headBA == NULL) {
            *headBA = newLink_ba;
        }
        else {
            temp_ba = *headBA;
            while (temp_ba->next) {
                temp_ba = temp_ba->next;
            }
            temp_ba->next = newLink_ba;
        }
        printf("New author link created for ISBN %s with Author ID %d.\n", targetISBN, newAuthorID);
    }
    else {
        printf("Author link updated for ISBN %s to Author ID %d.\n", targetISBN, newAuthorID);
    }
    saveBookAuthorsToCSV(*headBA);
}


void addAuthor(author **headAuthor) {
    author *newNode;
    unsigned int newID = 1;
    author *current;

    newNode = (author *)malloc(sizeof(author));
    if (!newNode) {
        perror("Memory allocation failed for author");
        return;
    }
    printf("Enter author name: ");
    scanf("%49s", newNode->name);
    printf("Enter author surname: ");
    scanf("%49s", newNode->surname);

    if (*headAuthor == NULL) {
        newNode->authorID = newID;
        *headAuthor = newNode;
    }
    else {
        current = *headAuthor;
        newID = current->authorID;
        while (current->next) {
            current = current->next;
            if (current->authorID > newID) {
                newID = current->authorID;
            }
        }
        newNode->authorID = newID + 1;
        current->next = newNode;
    }
    newNode->next = NULL;

    saveAuthorsToCSV(*headAuthor);
    printf("Author %s %s added with ID: %u\n", newNode->name, newNode->surname, newNode->authorID);
}

void removeAuthor(author **headAuthor, bookAuthor **headBA) {
    unsigned int targetID;
    author *current_auth, *prev_auth;
    int found_auth_flag = 0;
    bookAuthor *baCurrent;
    int links_updated_count = 0;

    if (*headAuthor == NULL) {
        printf("No authors available to remove.\n");
        return;
    }

    printf("Enter Author ID to remove: ");
    if (scanf("%u", &targetID) != 1) {
        while (getchar() != '\n');
        printf("Invalid Author ID format.\n");
        return;
    }

    current_auth = *headAuthor;
    prev_auth = NULL;
    found_auth_flag = 0;
    while (current_auth && !found_auth_flag) {
        if (current_auth->authorID == targetID) {
            if (prev_auth == NULL) {
                *headAuthor = current_auth->next;
            }
            else {
                prev_auth->next = current_auth->next;
            }
            printf("Author %s %s (ID: %u) removed.\n", current_auth->name, current_auth->surname, current_auth->authorID);
            free(current_auth);
            found_auth_flag = 1;
        }
        if (!found_auth_flag) {
            prev_auth = current_auth;
            current_auth = current_auth->next;
        }
    }

    if (!found_auth_flag) {
        printf("Author with ID %u not found.\n", targetID);
        return;
    }

    saveAuthorsToCSV(*headAuthor);

    baCurrent = *headBA;
    links_updated_count = 0;
    while (baCurrent) {
        if (baCurrent->authorID == (int)targetID) {
            baCurrent->authorID = -1;
            links_updated_count++;
        }
        baCurrent = baCurrent->next;
    }
    if (links_updated_count > 0) {
        saveBookAuthorsToCSV(*headBA);
        printf("%d book-author links updated (Author ID set to -1).\n", links_updated_count);
    }
}

void updateAuthor(author **headAuthor) {
    unsigned int targetID;
    author *current;
    int found_flag = 0;

    if (*headAuthor == NULL) {
        printf("No authors available to update.\n");
        return;
    }

    printf("Enter Author ID to update: ");
    if (scanf("%u", &targetID) != 1) {
        while (getchar() != '\n');
        printf("Invalid Author ID format.\n");
        return;
    }

    current = *headAuthor;
    while (current && !found_flag) {
        if (current->authorID == targetID) {
            printf("Updating author: %s %s (ID: %u)\n", current->name, current->surname, current->authorID);
            printf("Enter new name (current: %s): ", current->name);
            scanf("%49s", current->name);
            printf("Enter new surname (current: %s): ", current->surname);
            scanf("%49s", current->surname);

            saveAuthorsToCSV(*headAuthor);
            printf("Author updated successfully.\n");
            found_flag = 1;
        }
        if (!found_flag) {
            current = current->next;
        }
    }
    if (!found_flag) {
        printf("Author with ID %u not found.\n", targetID);
    }
}

void printAuthor(author **headAuthor) {
    char search_name[MAX_LEN];
    char search_surname[MAX_LEN];
    unsigned int search_id;
    int choice;
    author *current;
    int found = 0;
    int loop_flag = 0;

    if (*headAuthor == NULL) {
        printf("No authors to display.\n");
        return;
    }

    printf("Search author by:\n1. Author ID\n2. Name and Surname\nChoice: ");
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("Invalid choice.\n"); return;
    }

    current = *headAuthor;
    if (choice == 1) {
        printf("Enter Author ID: ");
        if (scanf("%u", &search_id) != 1) {
            while (getchar() != '\n');
            printf("Invalid ID format.\n"); return;
        }
        while (current && !loop_flag) {
            if (current->authorID == search_id) {
                printf("\nName: %s %s\nAuthor ID: %u\n", current->name, current->surname, current->authorID);
                found = 1;
                loop_flag = 1;
            }
            if (!loop_flag) {
                current = current->next;
            }
        }
    }
    else if (choice == 2) {
        printf("Enter author name: ");
        scanf("%49s", search_name);
        printf("Enter author surname: ");
        scanf("%49s", search_surname);
        while (current) {
            if (strcmp(current->name, search_name) == 0 && strcmp(current->surname, search_surname) == 0) {
                printf("\nName: %s %s\nAuthor ID: %u\n", current->name, current->surname, current->authorID);
                found = 1;
            }
            current = current->next;
        }
    }
    else {
        printf("Invalid search choice.\n");
        return;
    }

    if (!found) {
        printf("Author not found.\n");
    }
}

//----------------------------------------------Function End---------------------------------------------//