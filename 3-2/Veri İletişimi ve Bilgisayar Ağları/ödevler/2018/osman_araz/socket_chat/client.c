/*
    ATTENTION: This code designed for Linux, it does not work on Windows.
*/

/*
    ATTENTION: Do not delete the "messages" folder within the directory of the source files.
    If there is not such a folder, then create it.
*/

/*
    Programming Languages - Autumn 2017 - Semester Project

    A multi-user chat program. (Client side.)

    @author
    Name: Osman Araz
    Student NO: 16011020
    Date: 08.01.2018
    E-Mail: arazosman@outlook.com
    Compiler used: GCC 7.2.1
    Computer Hardware: 64 bit Quad Core CPU, 8 GB RAM
    IDE: None (Visual Studio Code used as a text editor.)
    Operating System: Manjaro KDE Edition 17.0.6
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>
#include <termios.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// ANSI color defining
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

// Local PORT/IP defining
#define PORT 8900
#define LOCAL_IP "127.0.0.1"

#define bufferSize 1024 // defining size of the buffer

// menuElements array: It stores the menu elements which will be showed to the user.
char *menuElements[] = {"Write Message", "Check Messages", "Add Friend", "Delete Friend", "Exit"};
const int menuSize = 5;
const int endSession = -1; // represents the ending session for a client

int clientSocket;
int *friends, client, countOfFriends = 0, numOfFriends = 100;

/*
    Main funcion: It creates clients and connect them to the server.
*/
void printBanner();
void printMenu();
void goBackToMenu();
int main(int argc, char *argv[])
{
    if (argc < 2) // there must be 2 command line arguments
    {
        perror("No client definition.\n");
        exit(1);
    }

    setlocale(LC_ALL, ""); // localization for Turkish characters

    clientSocket = socket(AF_INET, SOCK_STREAM, 0); // creating the client socket
    struct sockaddr_in serverAddr; // a built-in struct to keep server address
    client = atoi(argv[1]); // the second command line argument represents the client ID
    char buffer[bufferSize]; // a string variable to get and read messages

    if (clientSocket < 0) //  if the socket could not be create, then the program ends
    {
        perror("Failure to connect.");
        exit(1);
    }

    memset(&serverAddr, 0, sizeof(serverAddr)); // cleaning data from the server address variable

    // initializing the server address informations
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(LOCAL_IP);

    // connecting to the server
    if (connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Failure to connect.");
        exit(1);
    }

    // sending the client ID to the server
    if (send(clientSocket, &client, sizeof(int), 0) < 0)
    {
        perror("Failure to send.");
        exit(1);
    }

    // creating an array for all clients which will be kept the ID's of the friends
    friends = (int *)malloc(numOfFriends*sizeof(int));

    printMenu(); // printing the menu

    free(friends); // deallocating the array of the friends

    return 0;
}

/*
    Function which prints the banner of the program.
*/
void printBanner()
{
    system("clear"); // cleaning the screen
    printf(COLOR_CYAN "\n\t#######################################\n");
    printf("\t####" COLOR_YELLOW "           MESSAGING           " COLOR_CYAN "####\n");
    printf("\t#######################################\n\n\n" COLOR_RESET);
}

/*
    Function which displays the menu elements to the clients.
*/
int readKey();
void printMenu()
{
    void printFriends();
    void checkMessages();
    void addFriend();
    void deleteFriend();

	int ch, ind = 0; // ch: arrow key value, ind: an iterator on the menu elements

    do
	{
		system("clear"); // cleaning the screen
        printBanner();

        ind %= menuSize; // iterator always must bounded with range(-menuSize, +menuSize)

        if (ind < 0)
            ind +=  menuSize;

        for (int i = 0; i < menuSize; i++)
        {
            // the menu element which has the iterator indice, will be printed colorful
            if (i == ind)
                printf(COLOR_MAGENTA);

            printf("\t>  %s %s\n", menuElements[i], COLOR_RESET);
        }

        printf("\n");
        ch = readKey(); // getting arrow key from the user

		if (ch == 66) // represents DOWN key, it increases iterator
			ind++;
		else if (ch == 65) // represents UP key, it decreases iterator
            ind--;
    }
    while (ch != 10); // represents ENTER key, it breakes the loop

    // according to the iterator, desired function will be called
    if (ind == 0)
        printFriends();
    else if (ind == 1)
        checkMessages();
    else if (ind == 2)
        addFriend();
    else if (ind == 3)
        deleteFriend();
    else
    {
        // if user selects the exit button, then the client socket closes
        send(clientSocket, &endSession, sizeof(int), 0);
        close(clientSocket);
        system("clear");
    }
}

/*
    Function which prints the friends of the client.
*/
void sendMessage(int);
void printFriends()
{
    int ch, ind = 0; // ch: arrow key value, ind: an iterator on the menu elements

    if (countOfFriends == 0)
    {
        printBanner();
        printf("\tYou do not have friends.\n\n");
        goBackToMenu();
    }
    else
    {
        do
        {
            system("clear");
            printBanner();
            printf(COLOR_YELLOW "\tSend Message:\n\n" COLOR_RESET);
            printf("\tSelect the user whom will you send the message:\n\n");

            ind %= countOfFriends; // iterator always must bounded with range(-countOfFriends, +countOfFriends)

            if (ind < 0)
                ind += countOfFriends;

            for (int i = 0; i < countOfFriends; i++)
            {
                // the menu element which has the iterator indice, will be printed colorful
                if (i == ind)
                    printf(COLOR_MAGENTA);

                printf("\t>  Client #%d %s\n", friends[i], COLOR_RESET);
            }

            printf("\n");
            ch = readKey(); // getting arrow key from the user

            if (ch == 66) // represents DOWN key, it increases iterator
                ind++;
            else if (ch == 65) // represents UP key, it decreases iterator
                ind--;
        }
        while (ch != 10); // represents ENTER key, loop breaks
        
        sendMessage(friends[ind]);
    }
}

/*
    Function which ensures to send message to selected friend.
    @param friend: the ID of the friend which will be recieved to the message
*/
void sendMessage(int friend)
{
    printBanner();
    char buffer[bufferSize];  // a string variable to store message

    printf("\tType your message: ");
    fgets(buffer, bufferSize, stdin); // getting message from the client
    buffer[strlen(buffer)-1] = 0;
    time_t seconds = time(NULL); // getting time from the system

    // sending the ID of the friend to the server
    if (send(clientSocket, &friend, sizeof(int), 0) < 0)
    {
        perror("Failure to send.");
        exit(1);
    }

    // sending the time to the server
    if (send(clientSocket, &seconds, sizeof(int), 0) < 0)
    {
        perror("Failure to send.");
        exit(1);
    }
    
    // sending the message to the server
    if (send(clientSocket, buffer, bufferSize, 0) < 0)
    {
        perror("Failure to send.");
        exit(1);
    }

    printBanner();
    printf(COLOR_GREEN "\tMessage sended to the user!\n\n" COLOR_RESET);
    goBackToMenu();
}

/*
    Function which ensures to check the messages.
*/
void printMessages(int);
void checkMessages()
{
    int ch, ind = 0; // ch: arrow key value, ind: an iterator on the menu elements

    if (countOfFriends == 0)
    {
        printBanner();
        printf("\tYou do not have friends.\n\n");
        goBackToMenu();
    }
    else
    {
        do
        {
            system("clear");
            printBanner();
            printf(COLOR_YELLOW "\tCheck Messages:\n\n" COLOR_RESET);
            printf("\tSelect the user whom do you want check the messages:\n\n");

            ind %= countOfFriends; // iterator always must bounded with range(-countOfFriends, +countOfFriends)

            if (ind < 0)
                ind += countOfFriends;

            for (int i = 0; i < countOfFriends; i++)
            {
                // the menu element which has the iterator indice, will be printed colorful
                if (i == ind)
                    printf(COLOR_MAGENTA);

                printf("\t>  Client #%d %s\n", friends[i], COLOR_RESET);
            }

            printf("\n");
            ch = readKey(); // getting arrow key from the user

            if (ch == 66) // represents DOWN key, it increases iterator
                ind++;
            else if (ch == 65) // represents UP key, it decreases iterator
                ind--;
        }
        while (ch != 10); // represents ENTER key, loop breaks

        printBanner();
        printMessages(friends[ind]); // printing function calling

        goBackToMenu();
    }
}

/*
    Function which prints the history of the messages between the client and the friend.
    @param friend: the ID of the friend
*/
char *getFileName(int, int);
void printMessages(int friend)
{
    // getting file destinations for messaging history between the client and he friend
    char *fileNameClient = getFileName(client, friend);
    char *fileNameFriend = getFileName(friend, client);

    // opening the client file
    FILE *fileClient = fopen(fileNameClient, "r");

    // if file could not be open, then the program tries to open the files as writing mode
    if (!fileClient)
    {
        fileClient = fopen(fileNameClient, "w");
        fclose(fileClient);
        fileClient = fopen(fileNameClient, "r");
    }

    // if file could not be open again, then program ends
    if (!fileClient)
    {
        perror("File could not be open");
        exit(1);
    }

    // opening the friend file
    FILE *fileFriend = fopen(fileNameFriend, "r");

    // if file could not be open, then the program tries to open the files as writing mode
    if (!fileFriend)
    {
        fileFriend = fopen(fileNameFriend, "w");
        fclose(fileFriend);
        fileFriend = fopen(fileNameFriend, "r");
    }

    // if file could not be open again, then program ends
    if (!fileFriend)
    {
        perror("File could not be open");
        exit(1);
    }

    time_t secondsForClient, secondsForFriend; // variables to get time for each message
    char buffer[bufferSize]; // a string variable to store message
    memset(buffer, 0, sizeof(buffer)); // cleaning data of the buffer

    // getting message times from the files
    if (!feof(fileClient))
        fscanf(fileClient, "%ld", &secondsForClient);

    if (!feof(fileFriend))
        fscanf(fileFriend, "%ld", &secondsForFriend);

    // the messages will be displayed according to their times
    while (!feof(fileClient) && !feof(fileFriend))
    {
        if (secondsForClient < secondsForFriend)
        {
            fgets(buffer, 250, fileClient);
            printf("\tYou:       %s%s%s", COLOR_BLUE, buffer, COLOR_RESET);
            fscanf(fileClient, "%ld", &secondsForClient);
        }
        else
        {
            fgets(buffer, 250, fileFriend);
            printf("\tClient #%d: %s%s%s", friend, COLOR_YELLOW, buffer, COLOR_RESET);
            fscanf(fileFriend, "%ld", &secondsForFriend);
        }

        memset(buffer, 0, sizeof(buffer)); // cleaning data of the buffer
    }

    // the remained messages will be displayed
    while (!feof(fileClient))
    {
        fgets(buffer, 250, fileClient);
        printf("\tYou:       %s%s%s", COLOR_BLUE, buffer, COLOR_RESET);
        fscanf(fileClient, "%ld", &secondsForClient);
        memset(buffer, 0, sizeof(buffer));
    }

    while (!feof(fileFriend))
    {
        fgets(buffer, 250, fileFriend);
        printf("\tClient #%d: %s%s%s", friend, COLOR_YELLOW, buffer, COLOR_RESET);
        fscanf(fileFriend, "%ld", &secondsForFriend);
        memset(buffer, 0, sizeof(buffer));
    }    

    // closing the files
    fclose(fileClient);
    fclose(fileFriend);
}

/*
    Function which adds a friend to client's list.
*/
bool searchUser(int);
bool searchFriend(int);
void addFriend()
{
    int friend;

    printBanner();
    printf(COLOR_YELLOW "\tAdd Friend:\n\n" COLOR_RESET);
    printf("\tThe ID of the user whom will you add to your friends: ");
    scanf("%d", &friend);

    if (friend == client)
    {
        printf(COLOR_RED "\n\tYou don't need to add yourself as your friend!\n\n" COLOR_RESET);
        goBackToMenu();
    }
    else if (!searchUser(friend)) // seaching the typed user on the users list
    {
        printf(COLOR_RED "\n\tThere is not such a user which you typed!\n\n" COLOR_RESET);
        goBackToMenu();
    }
    else if (searchFriend(friend)) // seaching the typed user on the friends list
    {
        printf(COLOR_RED "\n\tYou have this user in your contact list already!\n\n" COLOR_RESET);
        goBackToMenu();
    }
    else
    {
        // if count of friends excesses the the array size, then the array extends
        if (countOfFriends >= numOfFriends)
        {
            numOfFriends *= 2;
            friends = realloc(friends, numOfFriends*sizeof(int));
        }

        friends[countOfFriends++] = friend;

        printf(COLOR_GREEN "\n\tThe user added to your contact list!\n\n" COLOR_RESET);
        goBackToMenu();
    }
}

/*
    Function which deletes a friend from client's list.
*/
void deleteFriend()
{
    int ch, ind = 0; // ch: arrow key value, ind: an iterator on the menu elements

    if (countOfFriends == 0)
    {
        printBanner();
        printf("\tYou do not have friends.\n\n");
        goBackToMenu();
    }
    else
    {
        do
        {
            system("clear");
            printBanner();
            printf(COLOR_YELLOW "\tDelete Friend:\n\n" COLOR_RESET);
            printf("\tSelect the user whom will you delete from your friends:\n\n");

            ind %= countOfFriends; // iterator always must bounded with range(-countOfFriends, +countOfFriends)

            if (ind < 0)
                ind += countOfFriends;

            for (int i = 0; i < countOfFriends; i++)
            {
                // the menu element which has the iterator indice, will be printed colorful
                if (i == ind)
                    printf(COLOR_MAGENTA);

                printf("\t>  Client #%d %s\n", friends[i], COLOR_RESET);
            }

            printf("\n");
            ch = readKey(); // getting arrow key from the user

            if (ch == 66) // represents DOWN key, it increases iterator
                ind++;
            else if (ch == 65) // represents UP key, it decreases iterator
                ind--;
        }
        while (ch != 10); // represents ENTER key, loop breaks

        // array of friends are shifting
        for (int i = ind; i < countOfFriends-1; i++)
        friends[i] = friends[i+1];

        countOfFriends--;

        // if count of friends is too low for the array size, then the array shrinks
        if (countOfFriends < numOfFriends/2)
        {
            numOfFriends /= 2;
            friends = realloc(friends, numOfFriends*sizeof(int));
        }

        printBanner();
        printf(COLOR_GREEN "\tThe user deleted from your contact list!\n\n" COLOR_RESET);
        goBackToMenu();
    }
}

/*
    Function which searches a given client ID on the file of the users.
    @param user: the given client ID which will be searched
    @return: if the user will be found, then the function returns true, 
    otherwise returns false
*/
bool searchUser(int user)
{
    int aClient;
    FILE *clients = fopen("clients.txt", "r");

    while (!feof(clients))
    {
        fscanf(clients, "%d", &aClient);

        if (user == aClient)
        {
            fclose(clients);
            return true;
        }       
    }

    fclose(clients);
    return false;
}

/*
    Function which searches a given client ID on the array of the friends of a client.
    @param friend: the given client ID which will be searched
    @return: if the friend will be found, then the function returns true, 
    otherwise returns false
*/
bool searchFriend(int friend)
{
    for (int i = 0; i < countOfFriends; i++)
        if (friends[i] == friend)
            return true;

    return false;
}

/*
    Function which ensures to going back to the main menu.
*/
int readKey();
void goBackToMenu()
{
    printf("\n\tTo back to the main menu, press any key on your keyboard.\n");
    getchar();
    int ch = readKey();
    printMenu();
}

/*
    Function which generates a target file desination for given ID of the client and the friend.
    @param client: the given client ID
    @param friend: the given friend ID
    @return fileName: the generated file destination
*/
char *getFileName(int client, int friend)
{
    char *fileName = (char *)malloc(30*sizeof(char));
    sprintf(fileName, "messages/%d-%d.txt", client ,friend);
    return fileName;
}

/*
    Function which ensures to getting arrow keys from the keyboard. It's a script 
    code that I found on the internet. (I don't know how it works.)
*/
int readKey()
{
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
