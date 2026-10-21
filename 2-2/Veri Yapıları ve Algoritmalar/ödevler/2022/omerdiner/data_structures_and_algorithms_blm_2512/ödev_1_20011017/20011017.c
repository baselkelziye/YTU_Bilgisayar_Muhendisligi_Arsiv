#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 5 // max value of counter
#define L 4 // max length of buffer

typedef struct Node
{
    int counter;       // total requests for the page
    char *page;        // page address
    struct Node *prev; // pointer to the previous node
    struct Node *next; // pointer to the next node
} Node;

/*
@brief iterates through the list and frees the memory allocated for each node
@param  pointer to the head of the list
@return 1 if successful
 */
int clearList(Node **head)
{
    Node *iter = *head;
    while (iter != NULL)
    {
        Node *temp = iter;
        iter = iter->next;
        free(temp);
    }
    *head = NULL;

    printf("Buffer cleared.\n");
    return 1;
}

/*
@brief iterates through the list and prints the page and counter of each node
@param  pointer to the head of the list
*/
void printList(Node *head)
{
    Node *iter = head;
    while (iter != NULL)
    {
        printf("%s,%d", iter->page, iter->counter);

        // if there is a next node printing " <-> "
        if (iter->next != NULL)
        {
            printf(" <-> ");
        }
        iter = iter->next;
    }
    printf("\n");
}

/*
@brief iterates through the list and returns the size of the list
@param  pointer to the head of the list
@return size of the list
*/
int checkListSize(Node *head)
{
    int size = 0;
    Node *iter = head;
    while (iter != NULL)
    {
        size++;
        iter = iter->next;
    }
    return size;
}

/*
@brief iterates through the list and checks if the page exists in the buffer
@param  pointer to the head of the list
@param  page to be checked
@return 1 if page exists, 0 if not
*/
int checkIfPageExists(Node *head, char *page)
{
    Node *iter = head;
    while (iter != NULL)
    {
        if (strcmp(iter->page, page) == 0)
        {
            return 1;
        }
        iter = iter->next;
    }
    return 0;
}

/*
@brief checks if the counter passes the threshold(T= max value of counter) value
@param  counter value
@param  threshold value(T)
@return 1 if counter passes threshold, 0 if not
*/
int checkIfCountPassesThreshold(int count, int threshold)
{
    if (count > threshold)
    {
        return 1;
    }
    return 0;
}

/*
@brief iterates through the list and deletes the last node
@param  pointer to the head of the list
@return 1 if successful, 0 if list is empty
*/
int deleteLastNode(Node **head)
{
    // if list is empty then nothing to delete
    if (*head == NULL)
    {
        return 0;
    }
    // if there is only one node in the list
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return 1;
    }

    Node *iter = *head;
    // iterating until the node before the last node , so that we can delete the last node
    while (iter->next->next != NULL)
    {
        iter = iter->next;
    }
    free(iter->next);
    iter->next = NULL;
    return 1;
}

/*
@brief adds a new node to the list
@param  pointer to the head of the list
@param  page to be added
@return 1 if successful
*/
int addNode(Node **head, char *page)
{
    // if page does not exist in the list, adding it to the head
    if (!checkIfPageExists(*head, page))
    {
        // if list has L nodes, deleting the last node
        if (checkListSize(*head) == L)
        {
            printf("Buffer is full. Deleting last node.\n");
            deleteLastNode(head);
        }

        // creating new node and adding it to the head
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->page = (char *)malloc(strlen(page) + 1);
        strcpy(newNode->page, page);
        newNode->counter = 1;

        newNode->prev = NULL;
        newNode->next = *head;
        if (*head != NULL)
        {
            (*head)->prev = newNode;
        }
        *head = newNode;

        printList(*head);
        return 1;
    }
    else
    {
        // increasing the counter of the page if it exists in the list
        Node *iter = *head;
        while (iter != NULL)
        {

            if (strcmp(iter->page, page) == 0)
            {
                iter->counter++;

                // if counter passes threshold , making this node head node
                if (checkIfCountPassesThreshold(iter->counter, T))
                {
                    printf("Threshold passed. Making this node head node.\n");
                    if (iter->prev != NULL)
                    {
                        iter->prev->next = iter->next;
                    }
                    if (iter->next != NULL)
                    {
                        iter->next->prev = iter->prev;
                    }

                    iter->prev = NULL;
                    iter->next = *head;
                    (*head)->prev = iter;
                    *head = iter;
                }

                printList(*head);
                return 1;
            }
            iter = iter->next;
        }
    }

    return 0;
}

/*
@brief prints the menu for the program
*/
void printMenu()
{

    printf("1. Add a page to the list\n");
    printf("2. Clear buffer\n");
    printf("3. Print buffer\n");
    printf("4. Exit\n");
}

/*
@brief takes menu input from the user
@return input from the user
*/
int takeInput()
{
    int input;
    printf("Enter your choice: ");
    scanf("%d", &input);
    return input;
}

int main()
{

    Node *buffer = NULL;
    int input;

    printf("Welcome to the buffer management program.\n");
    printf("If you want to take inputs from a file press 1, if you want to take inputs from the user press 2: ");

    scanf("%d", &input);
    printf("\n");

    // if input is 1 taking inputs from the file
    if (input == 1)
    {

        FILE *file = fopen("PAGES.txt", "r");

        if (file == NULL)
        {
            printf("File could not be opened.\n");
            return 1;
        }
        char *line = (char *)malloc(20 * sizeof(char));

        // reading the file line by line and adding the page address to the buffer list
        while (fgets(line, 20, file) != NULL)
        {
            // removing newline character from the end of the line
            line[strcspn(line, "\n")] = 0;

            printf("Adding %s to the buffer.\n", line);
            addNode(&buffer, line);
            printf("\n");
        }
        fclose(file);
    }
    // if input is 2 taking inputs from the user
    else if (input == 2)
    {

        int choice = 0;

        while (choice != 4)
        {
            printMenu();
            choice = takeInput();
            switch (choice)
            {
                // taking the page address from the user and adding it to the list
            case 1:
            {
                char *page = (char *)malloc(20 * sizeof(char));
                printf("Enter page address: ");
                scanf("%s", page);
                addNode(&buffer, page);
                printf("\n");
                break;
            }
            case 2:
            {
                clearList(&buffer);
                break;
            }
            case 3:
            {
                printList(buffer);
                break;
            }
            case 4:
            {
                printf("Program ended.\n");
                break;
            }
            default:
            {
                printf("Invalid choice.Try again.\n");
                break;
            }
            }
        }
    }
    // if input is not 1 or 2
    else
    {
        printf("Invalid input. Program ended.\n");
    }

    return 0;
}
