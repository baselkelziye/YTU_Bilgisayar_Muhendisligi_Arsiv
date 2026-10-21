/*
    ATTENTION: This code designed for Linux, it does not work on Windows.
*/

/*
    ATTENTION: Do not delete the "messages" folder within the directory of the source files.
    If there is not such a folder, then create it.
*/

/*
    Programming Languages - Autumn 2017 - Semester Project

    A multi-user chat program. (Server side.)

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
#include <unistd.h>
#include <locale.h>
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

/*
    Main function: It creates a server and supplies to connection for the clients to itself.
*/
bool searchClient(int);
char *getFileName(int, int);
int main()
{
    setlocale(LC_ALL, ""); // localization for Turkish characters
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // creating the server socket
    struct sockaddr_in serverAddr; // a built-in struct to keep server address
    struct sockaddr_in newServerAddr;
    socklen_t addr_size = sizeof(struct sockaddr_in);

    if (sockfd < 0) // if server socket could not create, then the program ends
    {
        perror("Failure to connect.");
        exit(1);
    }
    
    printf("[#] " COLOR_YELLOW "Server socket created.\n" COLOR_RESET);
    memset(&serverAddr, 0, sizeof(serverAddr)); // cleaning data from the server address variable

    // initializing the server address informations
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr(LOCAL_IP);

    // binding
    if (bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Failure to bind.");
        exit(1);
    }

    printf("[#] " COLOR_YELLOW "Binding to port: %d%s\n", PORT, COLOR_RESET);

    // listening up to 1000 clients
    if (listen(sockfd, 1000) < 0)
    {
        perror("Failure to bind.");
        exit(1);
    }
    else
        printf("[#] " COLOR_YELLOW "Listening...\n" COLOR_RESET);


    FILE *clients; // a file pointer which points to a file which stores the ID of clients
    int client, friend; // the ID of the client and the friend, respectively
    time_t seconds; // a time variable which gets the seconds since 00:00, Jan 1 1970
    char buffer[bufferSize]; // a string variable to get and read messages

    while (true)
    {
        // creating a new socket to accept connection from clients
        int newsockfd = accept(sockfd, (struct sockaddr *) &newServerAddr, &addr_size);

        if (newsockfd < 0) //  if the socket could not be create, then the program ends
        {
            perror("Failure to connect.");
            exit(1);
        }

        // getting the ID of the client from the client
        if (recv(newsockfd, &client, sizeof(int), 0) < 0)
        {
            perror("Failure to recieve");
            exit(1);
        }

        printf("[+] " COLOR_GREEN "Client #%d connected to the server.%s\n", client, COLOR_RESET);

        // Searching the client on the file of the clients. If it could not be found,
        // the it will be added to the file.
        if (!searchClient(client))
        {
            clients = fopen("clients.txt", "a");
            fprintf(clients, "%d ", client);
            fclose(clients);
        }

        pid_t childpid = fork(); // used for connect to the multi clients

        if (!childpid)
        {
            while (true)
            {
                memset(buffer, 0, sizeof(buffer)); // cleaning data of the buffer

                // getting ID of the friend
                if (recv(newsockfd, &friend, sizeof(int), 0) < 0)
                {
                    perror("Failure to recieve");
                    exit(1);
                }

                // if friend ID is -1, it means the client disconnected from the server
                if (friend == -1)
                {
                    printf("[-] " COLOR_RED "Client #%d disconnected from the server.%s\n", client, COLOR_RESET);
                    close(newsockfd);
                    break;
                }

                // getting the time of the message
                if (recv(newsockfd, &seconds, sizeof(int), 0) < 0)
                {
                    perror("Failure to recieve");
                    exit(1);
                }

                // getting the message
                if (recv(newsockfd, buffer, bufferSize, 0) < 0)
                {
                    perror("Failure to recieve");
                    exit(1);
                }

                printf("[>] " COLOR_BLUE "Client #%d sended a message to client #%d.%s\n", client, friend, COLOR_RESET);

                // adding the time and the message to the corresponding file
                char *fileName = getFileName(client, friend);
                FILE *fo = fopen(fileName, "a");
                fprintf(fo, "%ld %s\n", seconds, buffer);
                fclose(fo);
            }
        }
    }

    return 0;
}

/*
    Function which searches a given client ID on the file of the clients.
    @param client: the given client ID which will be searched
    @return: if the client will be found, then the function returns true, 
    otherwise returns false
*/
bool searchClient(int client)
{
    int aClient;
    FILE *clients = fopen("clients.txt", "r");

    while (!feof(clients))
    {
        fscanf(clients, "%d", &aClient); // reading client ID's on the file

        if (client == aClient)
        {
            fclose(clients);
            return true;
        }
    }

    fclose(clients);
    return false;
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
