#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<dir.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#define PORT 8080

/*
	A struct that stores user information:
	
	userID: holds the user's userID.
	name: holds the user's name.
	surname: holds the user's surname.
	phoneNumber: holds the user's phone number.
*/	
typedef struct USER{
	int userID;
	char name[40];
	char surname[40];
	char phoneNumber[11];
}user;

/*
	A struct that stores message information:
	
	sendUser: holds the user's information that sending the message
	message: holds the message
*/	
typedef struct MESSAGE{
	user* sendUser;
	char message[100];
}message;

struct ThreadArgs {
    SOCKET new_socket;
};

char** parseString(char* input, int* numTokens);
void createFolder(char* dirName);
int findFromSubfolders(char* userName);
int howManyUsersInSystem();
int createRequiredFiles(user currentUser);
int addUsers(char* userID, SOCKET new_socket);
void listContacts(char* userID, SOCKET new_socket);
int deleteUsers(char* userID, SOCKET new_socket);
int sendMessage(char* userID, SOCKET new_socket);
user* getUserFromID(char* userID);
void* handleClient(void* args);
void showMessageBetweenUsers(char* userID, SOCKET new_socket);
void deleteMessage(char* userID, SOCKET new_socket);
void showAllMessages(char* userID, SOCKET new_socket);
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int main() {
    WSADATA wsa;
    SOCKET server_fd;
    ssize_t valread;
    struct sockaddr_in server, client;
    int opt = 1;
    int addrlen = sizeof(server);
    struct ThreadArgs* args;
    pthread_t tid;
    	// Initialize Winsock
	    createFolder("Users");
	    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
	        perror("WSAStartup failed");
	        return 1;
	    }
	
	    // Creating socket file descriptor
	    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
	        perror("socket failed");
	        return 1;
	    }
	
	    // Forcefully attaching socket to the port 8080
	    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt)) == SOCKET_ERROR) {
	        perror("setsockopt");
	        return 1;
	    }
	
	    server.sin_family = AF_INET;
	    server.sin_addr.s_addr = INADDR_ANY;
	    server.sin_port = htons(PORT);
	
	    // Forcefully attaching socket to the port 8080
	    if (bind(server_fd, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
	        perror("bind failed");
	        return 1;
	    }
	
	    if (listen(server_fd, 3) == SOCKET_ERROR) {
	        perror("listen");
	        return 1;
	    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        SOCKET new_socket = accept(server_fd, (struct sockaddr*)&client, &addrlen);
        if (new_socket == INVALID_SOCKET) {
            perror("accept");
            closesocket(server_fd); // Close the listening socket
            WSACleanup();
            return 1;
        }

        // Create thread arguments
        args = (struct ThreadArgs*)malloc(sizeof(struct ThreadArgs));
        if (args == NULL) {
            perror("Memory allocation error");
            closesocket(new_socket);
        }
        args->new_socket = new_socket;

        // Create a new thread for each client
        if (pthread_create(&tid, NULL, handleClient, (void*)args) != 0) {
            perror("pthread_create failed");
            closesocket(new_socket);
            free(args); // Free the memory allocated for thread arguments
        }

        // Detach the thread (optional)
        pthread_detach(tid);
    }

}



/*	
@brief					This function performs the necessary operation based on the information sent from the client. 
						In the case of multiple client connections, it ensures the multithreading process.
		
@param	args			"args" is a way to pass multiple arguments to a thread function by encapsulating them in a structure. 
						It helps organize and simplify the passing of data between the main program and the thread.
*/
void* handleClient(void* args) {
	char *buffer;
	buffer = (char*)calloc(1024, sizeof(char));
    int flag = 0;
    int requestType, isSuccess;
    ssize_t valread;
    struct ThreadArgs* threadArgs = (struct ThreadArgs*)args;
    SOCKET new_socket = threadArgs->new_socket;
    free(args);
    char userID[2];
	while((valread = recv(new_socket, &userID, 2*sizeof(char), 0)) > 0){
		struct USER currentUser;
		int isExist = 100;
		isExist = findFromSubfolders(userID);
		send(new_socket, &isExist, sizeof(int), 0);
		if(isExist == 1){
		    while((valread = recv(new_socket, &requestType, sizeof(int), 0))> 0){
			    	switch(requestType){
				    		case(1):{
				    			printf("List User Request\n");
				    			listContacts(userID, new_socket);
								break;
							}
							case(2): {
							    int userNum;
							    printf("Add User Request\n");
							    isSuccess = addUsers(userID, new_socket);
							    send(new_socket, &isSuccess, sizeof(int), 0);
							    break;
							}
							case(3):{
								printf("Delete User Request\n");
								isSuccess = deleteUsers(userID, new_socket);
								send(new_socket, &isSuccess, sizeof(int), 0);
								break;
							}
							case(4):{
								printf("Send Message Request\n");
								isSuccess = sendMessage(userID, new_socket);
								send(new_socket, &isSuccess, sizeof(int), 0);
								break;
							}
							case(5):{
								printf("Check Messages Request\n");
								isSuccess = checkMessages(userID, new_socket);
								messagesReOrganize(userID);
								break;
							}
							case(6):{
								printf("Show Message History Request\n");
								showMessageBetweenUsers(userID, new_socket);
								break;
							}
							case(7):{
								printf("Delete Message Request\n");
								deleteMessage(userID, new_socket);
								break;
							}
							case(8):{
								printf("Quit Request\n");
								break;
							}
						}
						
				}
		}
		else{
			recv(new_socket, &currentUser, sizeof(struct USER), 0);
			currentUser.userID = atoi(userID);
			createRequiredFiles(currentUser);
			send(new_socket, &isExist, sizeof(int), 0);
		}
		free(buffer);
	    buffer = (char*)calloc(1024, sizeof(char));
	}
    closesocket(new_socket);
    
    pthread_exit(NULL);
}



/*
@brief					This function parses the character array sent to it into segments using a comma and stores the string num into numTokens.

@param	input			The string to be divided
@param	numTokens		The number of tokens that will result from the parsing

@return					An array holding parsed character strings
*/
char** parseString(char* input, int* numTokens){
    char** tokens = (char**)malloc(100 * sizeof(char*));
    char* inputCopy = strdup(input); 		
    char* token = strtok(inputCopy, ",");		// parsing the given input
    *numTokens = 0;
    while (token != NULL && *numTokens < 100) {
        tokens[*numTokens] = strdup(token);		// inserting parsed strings to the array
        (*numTokens)++;
        token = strtok(NULL, ",");				
    }
    free(inputCopy);
    return tokens;
}



/*
@brief					This function verifies the existence of the userID value sent to it in the system.

@param	userID			The ID of the user to be checked

@return					Returns 1 if the user exists in the system, 0 otherwise.
*/
int findFromSubfolders(char* userID){
	DIR *dir;
    struct dirent *entry;
    dir = opendir("./Users");	// file path
	char** parsedStr;
	int numTokens;
    while ((entry = readdir(dir)) != NULL) {	// comparing the given userID with the current folder name
    	if(strcmp(entry->d_name, userID) == 0){
    		return 1;
		}
    }
	return 0;
    closedir(dir);
}



/*
@brief					This function creates the necessary files for the user after the user registration process.

@param	currentUser		A struct that holds the information of the user for whom files will be created.

@return					Returns 1 if function ends without errors, 0 otherwise.
*/
int createRequiredFiles(user currentUser){
    FILE *file;
	char* tmpUserID = (char*)calloc(2,sizeof(char));
    sprintf(tmpUserID, "%d", currentUser.userID); 
    char *dir = strdup("./Users");		// file path
    strcat(dir, "/");
    strcat(dir,tmpUserID );
    free(tmpUserID);
    createFolder(dir);
    char* tmpDir = (char *)malloc(50*(sizeof(char)));

    strcpy(tmpDir, dir);
    strcat(tmpDir, "/friends.txt");
    file = fopen(tmpDir, "w");		// creating "friends.txt" file
    fclose(file);

    strcpy(tmpDir, dir);
    strcat(tmpDir, "/messages.txt");
    file = fopen(tmpDir, "w");		// creating "messages.txt" file
    fclose(file);
    
    strcpy(tmpDir, dir);
    strcat(tmpDir, "/messageHistory.txt");
    file = fopen(tmpDir, "w");		// creating "messageHistory.txt" file
    fclose(file);

    strcpy(tmpDir, dir);
    strcat(tmpDir, "/user_info.txt");	// creating "user_info.txt" file
    file = fopen(tmpDir, "w");
    char* buffer = (char*)calloc(100,sizeof(char));
    char* user_info = (char*)malloc(100*(sizeof(char)));
    char* num = (char*)calloc(20,sizeof(char));
    sprintf(num, "%d", currentUser.userID);
	strcpy(user_info,num);							// inserting user informations in "user_info.txt" file
	strcat(user_info,",");
	strcat(user_info,currentUser.name);				// inserting user informations in "user_info.txt" file
	strcat(user_info,",");
	strcat(user_info,currentUser.surname);			// inserting user informations in "user_info.txt" file
	strcat(user_info,",");
	strcat(user_info,currentUser.phoneNumber);		// inserting user informations in "user_info.txt" file
	fprintf(file, user_info);		
    fclose(file);
    free(dir);
    free(tmpDir);
    free(buffer);
    free(user_info);
    free(num);
//    free(dir);
    return 0;
}



/*
@brief					This function creates a folder with the same name as the userID.

@param	dirName			The name of the file to be created.

@return					void
*/
void createFolder(char* dirName){
    int ret = 0;				// creating the folder with given userID
    mkdir(dirName);
}



/*
@brief					This function adds the users sent by the client to the friend list of the logged-in user in the system.

@param	userID			The UserID of the user to be added.
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					Returns 1 if function ends without errors, 0 otherwise.
*/
int addUsers(char* userID, SOCKET new_socket) {
    int userNum;
    int success = 1;
    recv(new_socket, &userNum, sizeof(int), 0);		// recieving number of users to add
    user* addingUsers = (struct USER*)malloc(userNum * sizeof(struct USER));
    recv(new_socket, addingUsers, userNum * sizeof(struct USER), 0);	// recieving the list of users

    char* dir = (char*)malloc(100 * sizeof(char));

    snprintf(dir, 100, "./Users/%s/friends.txt", userID);

    FILE* file = fopen(dir, "a");	// opening the friends.txt file to add users

    int i = 0;
    for (i = 0; i < userNum; i++) {
        char tmp[10];
        sprintf(tmp, "%d", addingUsers[i].userID);
        if (findFromSubfolders(tmp) && (strcmp(tmp, userID) ) != 0) {	// checking whether users exist in the system
            strcat(tmp, "\n");
            fprintf(file, tmp);
        }
        else{
        	success = 2;
		}
    }
    fclose(file);
    free(addingUsers);
    free(dir);
    return success;
}



/*
@brief					This function deletes the users sent by the client from the friend list of the logged-in user in the system.

@param	userID			The UserID of the user to be added.
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					Returns 1 if function ends without errors, 0 otherwise.
*/
int deleteUsers(char* userID, SOCKET new_socket) {
    FILE* file;
    char* dir = (char*)malloc(100 * sizeof(char));
    char* str = (char*)malloc(50 * sizeof(char));
    int i = 0, j, flag = 0;
    char** parsedStr;
    int deleteUserNum;
    int numTokens;
	
    recv(new_socket, &deleteUserNum, sizeof(int), 0);		// recieving the number of users to delete
    user* deletingUsers = (user*)malloc(deleteUserNum * sizeof(user));
    recv(new_socket, deletingUsers, deleteUserNum * sizeof(user), 0);	// recieving the list of users

    user* contacts = NULL;
    int contactsNumber = 0;

    snprintf(dir, 100, "./Users/%s/friends.txt", userID);		// opening the friends.txt file
    file = fopen(dir, "r");

    while (fgets(str, 50, file) != NULL) {
        contactsNumber++;						// counting the number of users in file
    }

    fclose(file);
    file = fopen(dir, "r");						// opening the friends.txt file

    contacts = (user*)malloc(contactsNumber * sizeof(user));

    while (fgets(str, 50, file) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        if (isExistInFile(deletingUsers, deleteUserNum, str)) {		// checking whether users are in file
            contacts[i].userID = atoi(str);							// keeping users that will not be deleted in an array
            i++;
        }
    }

    contactsNumber = i;
    fclose(file);
    file = fopen(dir, "w");			// openning the file with "w"
    if (file == NULL) {
        perror("Error opening/creating file");
        free(dir);
        free(str);
        return 0;  // Return 0 to indicate an error
    }

    char* tmp;
    for (i = 0; i < contactsNumber; i++) {
        tmp = (char*)malloc(100 * sizeof(char));
        sprintf(tmp, "%d", contacts[i].userID);		// writing the users in array in file
        strcat(tmp, "\n");
        fprintf(file, tmp);
        free(tmp);
    }
    fclose(file);
    free(dir);
    free(str);
    free(deletingUsers);
    free(contacts);
    return 1;
}



/*
@brief					This function verifies if the input user is present in the friend list of the currently logged-in user in the system.

@param	deletingUser	A struct that holds the information of the user to be checked.
@param	deleteUserNum	The number of users.
@param	str				The string on which the comparison process will be performed.

@return					Returns 0 if user exist in file, 1 otherwise.
*/
int isExistInFile(user* deletingUser, int deleteUserNum, char* str) {
    int i;
    char* tmp;
    for (i = 0; i < deleteUserNum; i++) {
        tmp = (char*)malloc(10 * sizeof(char));
        sprintf(tmp, "%d", deletingUser[i].userID);
        if (strcmp(tmp, str) == 0) {		// checking whether the word is among those to be deleted
            free(tmp);
            return 0;
        }
        free(tmp);
    }
    return 1;
}



/*
@brief					This function sends the friend list of the logged-in user to the client.

@param	userID			The ID of the user whose contact list will be printed.
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void listContacts(char* userID, SOCKET new_socket) {
    FILE *file;
    char *dir;
    char *str;
    user *contacts = NULL;
    int contactsNumber = 0;

    dir = (char*)malloc(100 * sizeof(char));
    str = (char*)malloc(50 * sizeof(char));


    snprintf(dir, 100, "./Users/%s/friends.txt", userID);	
    printf("dir: %s\n", dir);

    
    file = fopen(dir, "r");		// opening the friends.txt file


    while (fgets(str, 50, file) != NULL) {
        contactsNumber = contactsNumber + 1;		// counting the number of users
    }
    
	send(new_socket, &contactsNumber, sizeof(int), 0);	// sending the number of contacts to client
	
    fseek(file, 0, SEEK_SET);		// reseting the file cursor



    if (contactsNumber == 0) {
        fclose(file);
        free(dir);
        free(str);
        return;
    }

    contacts = (user*)malloc(contactsNumber * sizeof(user));

    int i = 0;
	char* concatString = NULL;
	fgets(str, 50, file);
	str[strcspn(str, "\n")] = '\0';
	

	concatString = (char*)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(concatString, str);
	
	while (fgets(str, 50, file) != NULL) {
	    str[strcspn(str, "\n")] = '\0';		// inserting the users in 'concatString' char array
	    concatString = (char*)realloc(concatString, (strlen(concatString) + strlen(str) + 2) * sizeof(char));
	    strcat(concatString, ",");
	    strcat(concatString, str);
	}
	printf("allUsers: %s\n", concatString);


	fclose(file);
	

	send(new_socket, concatString, (strlen(concatString) + 1) * sizeof(char), 0); // sending the users array to client
	

	free(dir);
	free(str);
	free(concatString);
	free(contacts);
}



/*
@brief					This function checks whether the given userID is present in the user's connections.

@param	userID			The userID of the user whose connections will be examined.
@param	sendingUser		The userID of the user to be searched.

@return					Returns 1 if user exist in contact list, 0 otherwise.
*/
int isInFriends(char* userID, char* sendingUser) {
    char* dir = (char*)malloc(100 * sizeof(char));
    snprintf(dir, 100, "./Users/%s/friends.txt", userID);

    char* str = NULL;
    FILE* file = fopen(dir, "r");		// opening friends.txt file

    size_t str_size = 0;
    size_t str_capacity = 100;
    str = (char*)malloc(str_capacity * sizeof(char));

    while (fgets(str, str_capacity, file) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        if (strcmp(str, sendingUser) == 0) {	// comparing the given userID with userIDs in friends.txt
            fclose(file);
            free(dir);
            free(str);
            return 1;
        }
        str_size += strlen(str);
        if (str_size >= str_capacity - 1) {
            str_capacity *= 2;
            str = (char*)realloc(str, str_capacity * sizeof(char));
        }
    }

    fclose(file);
    free(dir);
    free(str);
    return 0;
}



/*
@brief					This function performs the task of sending messages to the userID received from the client.

@param	userID			The userID of the user who sent the message.
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					Returns 1 if function ends without errors, 0 otherwise.
*/
int sendMessage(char* userID, SOCKET new_socket){
	time_t t;
	struct tm* currentTime;
	t = time(NULL);
	int messageNum=0;
	char str[100];
	char messageNumChar[2];
	currentTime = localtime(&t);
	char *date= (char*)calloc(40,sizeof(char));		// getting date information from system
	sprintf(date, "%04d-%02d-%02d %02d:%02d",currentTime->tm_year + 1900,currentTime->tm_mon + 1,currentTime->tm_mday,currentTime->tm_hour,currentTime->tm_min);
	char sendingUserID[2];
	char message[100];
	char* tmp = NULL;
	char** parsedStr;
	int numTokens;
	// getting the ID of the user to whom the message will be sent from the client
	recv(new_socket, &sendingUserID, 2*sizeof(char), 0);
	// getting the message from client
	recv(new_socket, &message, 100*sizeof(char), 0);
	
	if(!findFromSubfolders(sendingUserID)){	// checking whether user exist in system
		return 0;
	}
	if(isInFriends(userID, sendingUserID) == 0){	// checking whether user exist in friends.txt
		return 2;
	}
	FILE *file;
	char dir[100];
	snprintf(dir, sizeof(dir),"./Users/%s/messages.txt", sendingUserID);
	
	file = fopen(dir, "a+");	// opening the messages.txt of target user
	while (fgets(str, sizeof(str), file) != NULL){
		messageNum++;		// counting the number of messages
	}
	parsedStr = parseString(str,&numTokens);
	fseek(file, 0, SEEK_END);	// setting the file cursor at the end
	sprintf(messageNumChar,"%d",messageNum);
	if(strcmp(messageNumChar, parsedStr[0]) == 0){
		messageNum++;
		sprintf(messageNumChar,"%d",messageNum);
	}
	
	
	tmp = (char*)malloc(150 * sizeof(char));
	sprintf(tmp, "%s,%s,%s,%s,0\n", messageNumChar, userID, message, date);	// inserting the values into "message.txt" of reciever user
    fprintf(file, "%s", tmp);
	fclose(file);
	free(tmp);
	addMessageHistory(sendingUserID, userID, message, date);	// inserting the values into "messageHistory.txt" of sender user
	return 1;
}



/*
@brief					This function adds the messages sent by the user to the file where their message history is stored.

@param	userID			The userID of the user who sent the message.
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void addMessageHistory(char* sendingUserID, char* userID, char* message, char* date){
	char str[100],dir[100];
	snprintf(dir, sizeof(dir),"./Users/%s/messageHistory.txt", userID);	// the file of sender user
	int messageNum = 0, numTokens;
	char messageNumChar[2];
	char* tmp;
	char** parsedStr;
	FILE* file = fopen(dir, "a+");	// opening the file
	while (fgets(str, sizeof(str), file) != NULL){
		messageNum++;
	}
	parsedStr = parseString(str,&numTokens);
	fseek(file, 0, SEEK_END);	// setting file cursor at the end of file
	sprintf(messageNumChar,"%d",messageNum);
	printf("%s - %s\n",messageNumChar, parsedStr[0]);
	if(strcmp(messageNumChar, parsedStr[0]) == 0){
		
		messageNum++;
		sprintf(messageNumChar,"%d",messageNum);
	}
	
	tmp = (char*)malloc(150 * sizeof(char));
	sprintf(tmp, "%s,%s,%s,%s\n", messageNumChar, sendingUserID, message, date);	// inserting values into file
	printf("tmp: %s",tmp);
    fprintf(file, "%s", tmp);
    free(tmp);
	fclose(file);
}



/*
@brief					This function sends the unread messages of the logged-in user to the client.

@param	userID			User ID of the user whose messages will be listed.
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					Returns 1 if function ends without errors, 0 otherwise.
*/
int checkMessages(char* userID, SOCKET new_socket) {
    char dir[100];
    char str[100];
    char concatenatedStr[100];
    char** parsedStr;
    int numTokens;

    snprintf(dir, sizeof(dir), "./Users/%s/messages.txt", userID);	

    FILE* file = fopen(dir, "r");	// opening messages.txt
    int messageNum = 0;
    while (fgets(str, sizeof(str), file) != NULL) {
        str[strcspn(str, "\n")] = '\0';
        parsedStr = parseString(str, &numTokens);
        if (numTokens == 5 && strcmp(parsedStr[4], "0") == 0) {	// looking for "0" (unread) messages
            messageNum++;
        }
    }
    fclose(file);
    send(new_socket, &messageNum, sizeof(int), 0);

    if (messageNum > 0) {
        file = fopen(dir, "r");
        while (fgets(str, sizeof(str), file) != NULL) {
            str[strcspn(str, "\n")] = '\0';
            parsedStr = parseString(str, &numTokens);	// parsing string
            printf("%s,%s\n", parsedStr[2], parsedStr[1]);
            if (numTokens == 5 && strcmp(parsedStr[4], "0") == 0) {	// sending "0" (unread) messages to client
                snprintf(concatenatedStr, sizeof(concatenatedStr), "%s,%s\n", parsedStr[2], parsedStr[1]);
                send(new_socket, concatenatedStr, sizeof(concatenatedStr), 0);
            }
        }

        fclose(file);
    }

    return 1;
}



/*
@brief					This function changes unseen message to seen message.

@param	fileName		The name of the file where the modification process will take place.

@return					void
*/
void messagesReOrganize(char* fileName) {
    char filePath[256];
    char tmpFilePath[256];
    snprintf(filePath, sizeof(filePath), "./Users/%s/messages.txt", fileName);
    FILE* file = fopen(filePath, "r");
    
    snprintf(tmpFilePath, sizeof(tmpFilePath), "./Users/%s/temp_messages.txt", fileName);
    FILE* tempFile = fopen(tmpFilePath, "w");
    
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        size_t len = strlen(line);
        // check if the line is not empty
        if (len > 0) {
            // find the last index
            size_t lastCommaIndex = len - 1;
            while (lastCommaIndex > 0 && line[lastCommaIndex] != ',') {
                lastCommaIndex--;
            }
            // check if the last index is "0 and replace it with "1
            if (lastCommaIndex > 0 && line[lastCommaIndex + 1] == '0') {
                line[lastCommaIndex + 1] = '1';
            }
        }
        fputs(line, tempFile);
    }
    fclose(file);
    fclose(tempFile);
	file = fopen(filePath,"w");
	tempFile = fopen(tmpFilePath, "r");
	while(fgets(line, sizeof(line), tempFile) != NULL){
		fprintf(file, line);
	}
	fclose(file);
	fclose(tempFile);
    remove(tmpFilePath);
}



/*
@brief					This function sends the messaging history between two users to the client.

@param	userID			UserID of the user whose messaging history will be checked.
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void showMessageBetweenUsers(char* userID, SOCKET new_socket){
	char* tmp;
	char dir[100];
	char str[100];
	char otherUserID[2];
	recv(new_socket, otherUserID, 2*sizeof(char), 0);
	int messageNum = 0;
	char concatenatedStr[100];
	char** parsedStr;
	int numTokens;
	FILE* file;
	snprintf(dir, sizeof(dir), "./Users/%s/messageHistory.txt", userID);	// opening the messageHistory.txt file
	file = fopen(dir, "r");
	while (fgets(str, sizeof(str), file) != NULL) {
		str[strcspn(str, "\n")] = '\0';
        parsedStr = parseString(str, &numTokens);
        if(strcmp(parsedStr[1], otherUserID) == 0){
			messageNum++;
		}
    }
    fclose(file);
    send(new_socket, &messageNum, sizeof(int), 0);
	
	if (messageNum > 0) {
        file = fopen(dir, "r");
        
        while (fgets(str, sizeof(str), file) != NULL) {
            str[strcspn(str, "\n")] = '\0';
            parsedStr = parseString(str, &numTokens);
            if(strcmp(parsedStr[1], otherUserID) == 0){	// sending the messages between main user and given userID's user
            	snprintf(concatenatedStr, sizeof(concatenatedStr), "%s,%s,%s,%s\n",parsedStr[0], parsedStr[1], parsedStr[2], parsedStr[3]);
            	send(new_socket, concatenatedStr, sizeof(concatenatedStr), 0);
			}
        }
        fclose(file);
    }
		
}



/*
@brief					This function deletes the selected message sent by the user. 
						The selected message is also deleted from the messages of the user to whom the message was sent.

@param	userID			The ID of the user whose message will be deleted
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void deleteMessage(char* userID, SOCKET new_socket){
	char messageID[2];
	int flag = 0;
	char str[100];
	showAllMessages(userID, new_socket);
	recv(new_socket, messageID, 2*sizeof(char),0);
	char dir[100];
	int numTokens;
	char allMessages[50][50];
	snprintf(dir, sizeof(dir),"./Users/%s/messageHistory.txt", userID);
	FILE* file;
	file = fopen(dir,"r");	// opening the messageHistory.txt file
	char** parsedStr;
	while((fgets(str, sizeof(str), file) != NULL) && (flag == 0)){
		str[strcspn(str, "\n")] = '\0';
		parsedStr = parseString(str, &numTokens);
		if(strcmp(parsedStr[0], messageID) == 0){	// getting the message with the given ID from the file
			flag = 1;
		}
	}
	fclose(file);
	
	// parsedStr[1] is destination userID
	// parsedStr[2] is message
	// parsedStr[3] is message date
	if(flag != 1){
		send(new_socket, &flag, sizeof(int), 0);
		return;
	}
	// deleting messages from the target user
	FILE* tempFile = fopen("temp.txt", "w");
	snprintf(dir, sizeof(dir), "./Users/%s/messages.txt", parsedStr[1]);
	file = fopen(dir, "r");	
	
	int found = 0;
	while (fgets(str, sizeof(str), file) != NULL) {
        // check if the line contains the userToDelete 
        if (strstr(str, parsedStr[2]) == NULL) {
            // if not, write the line to the temporary file
            fputs(str, tempFile);
        } else {
            // if found, mark as such
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);
    if (remove(dir) != 0) {
        perror("Error deleting original file");
        return;
    }
    // rename the temporary file to the original filename
    if (rename("temp.txt", dir) != 0) {
        perror("Error renaming temporary file");
        
    }
    
    
	// deleting from own message history
	tempFile = fopen("temp.txt", "w");
	snprintf(dir, sizeof(dir), "./Users/%s/messageHistory.txt", userID);
	file = fopen(dir, "r");	
	found = 0;
	while (fgets(str, sizeof(str), file) != NULL) {
        // check if the line contains the userToDelete string
        if (strstr(str, parsedStr[2]) == NULL) {
        	// if not, write the line to the temporary file
            fputs(str, tempFile);
        } else {
            // if found, mark as such
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);
	if (remove(dir) != 0) {
        perror("Error deleting original file");
        return;
    }
    // rename the temporary file to the original filename
    if (rename("temp.txt", dir) != 0) {
        perror("Error renaming temporary file");
        
    }
    send(new_socket, &flag, sizeof(int), 0);
}



/*
@brief					This function sends the entire messaging history of the user to the client.

@param	userID			UserID of the user whose messaging history will be checked.
@param	new_socket		The variable that holds the properties of the socket to be used in the function.

@return					void
*/
void showAllMessages(char* userID, SOCKET new_socket){
	char* tmp;
	char dir[100];
	char str[100];
	int messageNum = 0;
	char concatenatedStr[100];
	char** parsedStr;
	int numTokens;
	FILE* file;
	snprintf(dir, sizeof(dir), "./Users/%s/messageHistory.txt", userID);
	file = fopen(dir, "r");	// opening the messageHistory.txt file
	while (fgets(str, sizeof(str), file) != NULL) {
		messageNum++;	// counting the num of messages
    }
    fclose(file);
    send(new_socket, &messageNum, sizeof(int), 0);	// sending message number to client
	
	if (messageNum > 0) {
        file = fopen(dir, "r");
        if (file == NULL) {
            perror("Error opening file");
            return 0;
        }
        while (fgets(str, sizeof(str), file) != NULL) {
            str[strcspn(str, "\n")] = '\0';
            parsedStr = parseString(str, &numTokens);	// sending the message history to client
            snprintf(concatenatedStr, sizeof(concatenatedStr), "%s,%s,%s,%s\n",parsedStr[0], parsedStr[1], parsedStr[2], parsedStr[3]);
            send(new_socket, concatenatedStr, sizeof(concatenatedStr), 0);
        }
        fclose(file);
    }
		
}


