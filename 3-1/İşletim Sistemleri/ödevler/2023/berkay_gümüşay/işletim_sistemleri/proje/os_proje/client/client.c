#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#define PORT 8080
/*
@brief							A struct that stores user information
	
@params		userID 				holds the user's userID.
@params		name 				holds the user's name.
@params		surname				holds the user's surname.
@params		phoneNumber 		holds the user's phone number.
*/
typedef struct USER{
	int userID;
	char name[40];
	char surname[40];
	char phoneNumber[11];
}user;
/*
@brief							A struct that stores message information
	
@params		sendUser			holds the user's information that sending the message
@params		message				holds the message
*/
typedef struct MESSAGE{
	user* sendUser;
	char message[100];
}message;

void listContacts(SOCKET client_fd);
void addUser(SOCKET client_fd);
void sendMessage(SOCKET client_fd);
void checkMessages(SOCKET client_fd);
void showMessageHistoryBetweenUsers(SOCKET client_fd);
void deleteMessage(SOCKET client_fd);
DWORD WINAPI messageCheckingThread(LPVOID lpParameter);
char user_id[2];
int main(int argc, char *argv[]) {
    WSADATA wsa;
    SOCKET client_fd;
    struct sockaddr_in server_addr;
    ssize_t valread;
    char buffer[1024] = {0};
    char msg[40];
    int i,j,k;
    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        perror("WSAStartup failed");
        return 1;
    }
	
    // Creating socket file descriptor
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        perror("socket failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return 1;
    }

    // Connect to server
    if (connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }
	HANDLE threadHandle;
    DWORD threadId;
    threadHandle = CreateThread(NULL, 0, messageCheckingThread, NULL, 0, &threadId);
    
    // Send data to server
    char userID[2];
    int menu1,menu2 = 0;
    char passWord[20],userName[20];
    strcpy(userID, argv[1]);
    strcpy(user_id, argv[1]);
    int isExist;
    while(1){
    	send(client_fd, &userID, 2*sizeof(char), 0);
    	recv(client_fd, &isExist, sizeof(int), 0);
    	if(isExist){
    		system("cls");
    		printf("!! User Successfully Logged In !!");
			printf("\nPress Enter...");
			getch();
			system("cls");
			while(menu2 != 8){
				printf("1- List Contacts\n2- Add User\n3- Delete User\n4- Send Message\n5- Check Messages\n6- Show Message History\n7- Delete Messages\n8- Exit\nChoice: ");
				scanf("%d",&menu2);
				send(client_fd, &menu2, sizeof(int), 0);
				system("cls");
				switch(menu2){
					case(1):{
						listContacts(client_fd);
						break;
					}
					case(2):{
						addUser(client_fd);
					break;
					}
					case(3):{
						deleteUsers(client_fd);
						break;
					}
					case(4):{
						sendMessage(client_fd);
						break;
					}
					case(5):{
						checkMessages(client_fd);
						break;
					}
					case(6):{
						showMessageHistoryBetweenUsers(client_fd);		
						break;
					}
					case(7):{
						deleteMessage(client_fd);
						break;
					}
					case(8):{
						return 0;
						break;
					}
				}
				printf("\nPress Enter...");
				getch();
				system("cls");
			}
		}
		else{
			user currentUser;
			printf("Name: ");
    		scanf("%s",currentUser.name);
    		printf("Surname: ");
    		scanf("%s",currentUser.surname);
    		printf("Phone Number: ");
    		scanf("%s",currentUser.phoneNumber);
    		send(client_fd, &currentUser, sizeof(struct USER), 0);
    		recv(client_fd, &isExist, sizeof(int), 0);
    		if(!isExist){
    			system("cls");
    			printf("!! User Successfully Registered !!");
				printf("\nPress Enter...");
				getch();
				system("cls");
			}
			else{
				system("cls");
				printf("!! This user already exists in the system !!");
				printf("\nPress Enter...");
				getch();
				system("cls");
			}
		}
	}
	
	
	WaitForSingleObject(threadHandle, INFINITE);
	CloseHandle(threadHandle);
	
    closesocket(client_fd);
    WSACleanup();
    return 0;
}



/*
@brief    This function represents a thread that continuously checks for new messages in a file and prints a message when a new one is detected.

@param    lpParameter   A pointer to the parameters passed to the thread (not used in this function).

@return   NULL
*/
DWORD WINAPI messageCheckingThread(LPVOID lpParameter) {
    char lastReadMessage[1024];
    int lastMessageNum;
	char buffer[1024];
    char currentMessage[1024];
    int currentMessageNum;
    char dir[50];
    snprintf(dir, sizeof(dir),"../Server/Users/%s/messages.txt", user_id);
    
    FILE* file = fopen(dir, "r");											
    lastMessageNum = 0;
    while (fgets(lastReadMessage, sizeof(lastReadMessage), file) != NULL){
    	lastMessageNum++;
	}
	fclose(file);
    while (1) {
    	FILE* file = fopen(dir, "r");
    	currentMessageNum = 0;
    	while (fgets(currentMessage, sizeof(currentMessage), file) != NULL) {
    		currentMessageNum++;
    	}
    	if(currentMessageNum > lastMessageNum){
    		printf("\n!! New Message !!\nChoice:");
    		lastMessageNum = currentMessageNum;
		}
		if(currentMessageNum < lastMessageNum){
			lastMessageNum = currentMessageNum;
		}
		fclose(file);
		Sleep(4000);
    	
    }
    return NULL;
}



/*
@brief					This function takes the message to be sent and the ID of the user to whom the message will be sent as input and sends it to the server.

@param	client_fd		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void sendMessage(SOCKET client_fd){
	char userID[2];
	char message[100];
	int isSuccess;
	printf("Enter the ID Of The User You Want To Send Message To : ");
	scanf("%s", userID);
	send(client_fd, &userID, 2*sizeof(char), 0);
	printf("Enter Your Message: ");
	fflush(stdin);
	fgets(message, sizeof(message), stdin);
	message[strcspn(message, "\n")] = '\0';
	// sending the message to server
	send(client_fd, &message, 100*sizeof(char), 0);
	// recieving the status of process
	recv(client_fd, &isSuccess, sizeof(int), 0);
	if(isSuccess == 1){
		printf("!! Message Sended Successfully !!\n");
	}
	else if(isSuccess == 2){
		printf("!! You Have To Add Friend First !!\n");
	}
	else{
		printf("!! Message Sending is Failed !!\n");
	}
}



/*
@brief					This function takes the IDs of the users to be added to the contact list as input and sends them to the server.

@param	client_fd		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void addUser(SOCKET client_fd){
	int userNum, i, isSuccess;
	printf("Number of Users You Want To Add: ");
	scanf("%d",&userNum);

	user* addingUsers = (struct USER*)malloc(userNum*(sizeof(struct USER)));
	
	for(i=0; i<userNum; i++){
		printf("%d. Users ID: ",i+1);
		scanf("%d",&addingUsers[i].userID);
		printf("\n");
	}
	send(client_fd, &userNum, sizeof(int), 0);
	send(client_fd, addingUsers, userNum * sizeof(struct USER), 0);
	
	recv(client_fd, &isSuccess, sizeof(int), 0);
	if(isSuccess == 1){
		printf("!! Users Added Successfully !!\n");
	}
	else if(isSuccess == 2){
		printf("!! Some Users Could Not Be Added !!");
	}
	else{
		printf("!! Failed !!\n");
	}
}



/*
@brief					This function prints the contact list of the user received from the server to the screen.

@param	client_fd		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void listContacts(SOCKET client_fd) { 
    int numOfContacts, i;
    recv(client_fd, &numOfContacts, sizeof(int), 0);
    if (numOfContacts == 0) {
        printf("\n!! Your Contact List Is Empty !!\n");
        return;
    }

    char allUsers[100];
    if (recv(client_fd, allUsers, 100 * sizeof(char), 0) == SOCKET_ERROR) {
        perror("Error receiving contacts");
        return;
    }
	// struct ile tutmuþtum
    printf("List Of Contacts:\n");
    i = 1;
    char* token = strtok(allUsers, ",");
    while (token != NULL) {
        printf("%d) User %s\n",i, token);
        token = strtok(NULL, ",");
        i++;
    }
}



/*
@brief					This function, by sending the user ID received as input to the server, performs the operation of removing the user from the contact list.

@param	client_fd		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void deleteUsers(SOCKET client_fd){
	int deleteUserNum, i, isSuccess;
	user* deletingUsers;
	printf("Number Of Users You Want To Delete : ");
	scanf("%d",&deleteUserNum);
	send(client_fd, &deleteUserNum, sizeof(int), 0);
	deletingUsers = (user*)malloc(deleteUserNum*sizeof(user));
	for(i=0; i<deleteUserNum; i++){
		printf("%d. Users ID: ",i+1);
		scanf("%d",&deletingUsers[i].userID);
	}
	send(client_fd, deletingUsers, deleteUserNum*sizeof(user), 0);
	recv(client_fd, &isSuccess, sizeof(int), 0);
	if(isSuccess == 1){
		printf("!! User(s) Deleted Successfully !!\n");
	}
	else{
		printf("!! Failed !!\n");
	}
}



/*
@brief					This function prints unread messages received from the server to the screen.

@param	client_fd		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void checkMessages(SOCKET client_fd) {
    int messageNum, i;
    recv(client_fd, &messageNum, sizeof(int), 0);
    char receivedStr[100]; 
    if (messageNum == 0) {
        printf("!! You Have No Messages !!\n");
        return;
    }
    printf("\nMessage\t\t\tSending User's ID\n\n");
    for (i = 0; i < messageNum; i++) {
        recv(client_fd, receivedStr, 100*sizeof(char), 0);
        char* token = strtok(receivedStr, ",");
        if (token != NULL) {
            printf("%s\t\t\t", token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            printf("%s", token);
        }
        printf("\n");
    }

}



/*
@brief					This function prints the messaging history between two users to the screen.

@param	client_fd		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void showMessageHistoryBetweenUsers(SOCKET client_fd){
	int messageNum, i;
	char otherUserID[2];
	printf("Enter User ID:");
	scanf("%s",otherUserID);
	send(client_fd, otherUserID, 2*sizeof(char), 0);
    recv(client_fd, &messageNum, sizeof(int), 0);
    char receivedStr[100]; 
    printf("\n\n");
    if (messageNum == 0) {
        printf("!! No Messages in Message History !!\n");
        return;
    }
    printf("MessageID\t\tUserID\t\t\tMessage\t\t\t\tMessage Date\n\n");
    for (i = 0; i < messageNum; i++) {
        recv(client_fd, receivedStr, 100*sizeof(char), 0);
        char* token = strtok(receivedStr, ",");
        if (token != NULL) {
            printf("%s)\t\t\t", token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            printf("%s\t\t\t", token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            printf("%s\t\t\t", token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            printf("%s", token);
        }
        printf("\n");
    }
}

/*
@brief					This function sends the ID of the message to be deleted to the server.

@param	client_fd		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void deleteMessage(SOCKET client_fd){
	char messageID[2];
	showAllMessages(client_fd);
	printf("\n\nEnter The Message ID of The Message You Want To Delete : ");
	scanf("%s",messageID);
	send(client_fd, &messageID, 2*sizeof(char), 0);
	int flag;
	recv(client_fd, &flag, sizeof(int), 0);
	if(flag != 1){
		printf("\n!! Message Not Found !!\n");
		return;
	}
	else{
		printf("\n!! Message Deleted Successfully !!\n");
		return;
	}
}



/*
@brief					This function lists all the messages sent by the user.

@param	client_fd		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void showAllMessages(SOCKET client_fd){
	int messageNum, i;
    recv(client_fd, &messageNum, sizeof(int), 0);
    char receivedStr[100]; 
    printf("\n\n");
    if (messageNum == 0) {
        printf("!! No Messages in Message History !!\n");
        return;
    }
    printf("MessageID\t\tUserID\t\t\tMessage\t\t\t\tMessage Date\n\n");
    for (i = 0; i < messageNum; i++) {
        recv(client_fd, receivedStr, 100*sizeof(char), 0);
        char* token = strtok(receivedStr, ",");
        if (token != NULL) {
            printf("%s)\t\t\t", token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            printf("%s\t\t\t", token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            printf("%s\t\t\t", token);
        }
        token = strtok(NULL, ",");
        if (token != NULL) {
            printf("%s", token);
        }
        printf("\n");
    }
}












