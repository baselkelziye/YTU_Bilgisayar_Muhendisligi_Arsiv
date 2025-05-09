#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#undef max
#undef min
#endif

static const char menuUp[] =
"\n***************************************\n"
"     ** ListenLink by Mert Guler **\n"
"***************************************\n"
"                MENU                 \n\n";

static const char menuDown[] =
"***************************************\n";

static const char *choiceSuiteMainMenu[] = {"Quit", "Create User", "Listen Music", "View Top 10"};

static const char *choiceSuiteUserMenu[] = {"Return", "Create List"};

#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define GREEN_BOLD "\033[1;32m"
#define RESET "\033[0m"
#define MAIN_MENU_LENGTH 4
#define USER_MENU_LENGTH 2

typedef struct SongNode {
    int songId;
    char title[256];
    int length;
    struct SongNode *next;
    struct SongNode *prev;
} SongNode;

typedef struct SongListCollection {
    SongNode *songList;
    struct SongListCollection *next;
} SongListCollection;

typedef struct UserNode {
    int userId;
    SongListCollection *lists;
    struct UserNode *next;
} UserNode;

/*
@brief Clears screen
*/
void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*
@brief Frees memory of a Song LinkedList
 
@param head  Head node of the song list
*/
void freeSongs(SongNode* head){
    SongNode* tmp;

   while (head != NULL){
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

/*
@brief Frees memory of the all lists of the user

@param head  Head node of the User list
*/
void freeSongLists(UserNode *head){
    SongListCollection *tempCollection;
    
    while (head->lists != NULL) {
        freeSongs(head->lists->songList);
        tempCollection = head->lists;
        head->lists = head->lists->next;
        free(tempCollection);
    }
}

/*
@brief Frees memory of the users
 
@param head  Head node of the list
*/
void freeUsers(UserNode* head){
   UserNode *tempUserNode;

   while (head != NULL){
       freeSongLists(head);
       tempUserNode = head;
       head = head->next;
       free(tempUserNode);
    }

}

/*
@brief Gets keyboard input from user
 
@return The char has pressed
*/
char getChar(void)
{
#ifdef _WIN32
    return _getch();
#else
    char ch;
    system("stty raw");
    system("stty -echo");
    ch = getchar();
    system("stty cooked");
    system("stty echo");
    return ch;
#endif
}

/*
@brief Processes user input for choice management
 
@return Horizontal difference in the input (Reverse)
*/
int getInput(void){
    while (1){
        char ch = getChar();
        switch (ch){
            case 'w':
                return -1;
            case 's':
                return 1;
            case 'e':
                return 0;
        }
    }
}

/*
@brief Updates choice position and controls bounds
 
@param position  Current position of the choice
@param input  User input as delta
@param bound  Bound of the printing menu
*/
void updateChoice(int *position, int input, int bound){
    *position += input;
    
    if (*position == -1){
        (*position)++;
    } else if (*position >= bound){
        (*position)--;
    }
}

/*
@brief Calculates list count of a user (Needed in listening function)
 
@param userNode The user node

@return Total list count of the user
*/
int calculateTotalListCount(UserNode *userNode){
    int count = 0;
    SongListCollection *iterator = userNode->lists;
    
    while (iterator != NULL) {
        count++;
        iterator = iterator->next;
    }
    return count;
}

/*
@brief Prints total list count of the user with zero control
 
@param userNode The user node
*/
void printTotalListCount(UserNode *userNode){
    int count = calculateTotalListCount(userNode);
    
    if (count != 0){
        printf("User's List Count: %d\n\n", count);
    }
}

/*
@brief Prints total user count of the program, calculation is embedded (No needed in anywhere else)
 
@param users Head node of the users list
*/
void printTotalUserCount(UserNode *usersHead){
    int count = 0;
    UserNode *iterator = usersHead;
    
    while (iterator != NULL) {
        count++;
        iterator = iterator->next;
    }
    
    if (count != 0){
        printf("User Count: %d\n\n", count);
    }
}

/*
@brief Calculates total song count of a list (Needed in listening function)
 
@param songList Head node of the song list

@return Total list count of the list
*/
int calculateTotalSongCount(SongNode *songListHead){
    int count = 1;
    SongNode *iterator = songListHead->next;
    
    while (iterator != NULL && iterator != songListHead) {
        count++;
        iterator = iterator->next;
    }
    return count;
}

/*
@brief Prints songs of a list
 
@param listSongsHead Head node of the song list
*/
void printListSongs(SongNode *listSongsHead){
    SongNode *iterator = listSongsHead;
    printf("%s\n", iterator->title);
    iterator = iterator->next;
    
    while (iterator != NULL && iterator != listSongsHead) {
        printf("%s\n", iterator->title);
        iterator = iterator->next;
    }
}

/*
@brief Prints menus with user's selection is colored
 
@param suite  Char sequence of the menu
@param N  Length of the suite
@param selection  Selection index
@param printDown  Boolean for determining global menuDown to be printed

*/
void printChoices(const char **suite, int N, int selection, int printDown){
    int i;
    printf(menuUp);
    
    for (i = 0; i < N; i++) {
        if (i == selection) {
            printf(GREEN_BOLD "%s" RESET, suite[i]);
        } else {
            printf("%s", suite[i]);
        }
        printf("\n");
    }
    
    printf("\n");
    if (printDown == 1){
        printf(menuDown);
    }
}

/*
@brief Prints songs with selection is colored and already selected songs excluded
 
@param songList  Song list to be printed
@param N  Size of the song list
@param selection  Selection index
@param exclude  The array contains songs to be excluded
*/
void printSongs(SongNode *songList, int N, int selection, int exclude[]){
    int i = 1;
    int j;
    int excluded;
    
    clearScreen();
    printf(menuUp);
    
    if (selection == 0){
        printf(GREEN_BOLD "Save\n" RESET);
    } else {
        printf("Save\n");
    }
    
    while (songList != NULL) {
        excluded = 0;
        for (j = 0; j < N; j++) {
            if (i == exclude[j]){
                excluded = 1;
            }
        }
        
        if (i == selection){
            printf(GREEN_BOLD);
        }
        
        if (excluded == 0){
            printf("%s", songList->title);
        } else {
            printf("--------");
        }
        
        printf(RESET "\n");
        
        songList = songList->next;
        i++;
    }
    
    printf("\n");
    printf(menuDown);
}

/*
@brief Prints top 10 most listened songs
 
@param songNodeHead  Head node of the song list
*/
void printTopList(SongNode *songNodeHead){
    SongNode *iterator = songNodeHead;
    int count = 1;
    
    printf(GREEN_BOLD "Top 10:" RESET "\n%s: %.1f minutes\n", iterator->title, (float) iterator->length / 60);
    iterator = iterator->next;
    
    while (iterator != NULL && count < 10) {
        printf("%s: %.1f minutes\n", iterator->title, (float) iterator->length / 60);
        iterator = iterator->next;
        count++;
    }
}

/*
@brief Creates songs from 1 to N, with naming like: Song 1 - Song 2
 
@param appSongHead  Head node of the app's song list
@param N  Number of the songs to be created
*/
void createSongs(SongNode *appSongsHead, int N){
    int i;

    for (i = 0; i < N; i++) {
        sprintf(appSongsHead->title, "Song %d", i + 1);
        appSongsHead->songId = i;
        appSongsHead->length = (rand() % 240) + 60;
        
        if (i != N - 1){
            appSongsHead->next = (SongNode *)malloc(sizeof(SongNode));
            appSongsHead = appSongsHead->next;
        }
    }
}

/*
@brief Creates a user
 
@param usersHead  Head node of the user list
 
@return Last user of the user list
*/
UserNode* createUser(UserNode **usersHead){
    int count = 0;
    UserNode *iterator = *usersHead;
    
    /* Create head node if null */
    if (*usersHead == NULL){
        *usersHead = (UserNode *)malloc(sizeof(UserNode));
        (*usersHead)->userId = 1;
        return *usersHead;
    } else {
        count = 1;
        /* Iterate to the last point */
        while (iterator->next != NULL) {
            iterator = iterator->next;
            count++;
        }
        
        iterator->next = (UserNode *)malloc(sizeof(UserNode));
        iterator->next->userId = count + 1;
        return iterator->next;
    }
}

/*
@brief Sorts a song list with Insertion Sort
 
@param head  Head node of the song list
 
@return Sorted song list
*/
SongNode* sort(SongNode *head){
    SongNode *temp = (SongNode *)malloc(sizeof(SongNode));
    SongNode *current = head;
    SongNode *prev = temp;
    SongNode *next = NULL;
    SongNode *result;
    
    while (current != NULL) {
        next = current->next;
        while (prev->next != NULL && prev->next->length > current->length) {
            prev = prev->next;
        }
        
        current->next = prev->next;
        prev->next = current;
        prev = temp;
        current = next;
    }
    
    result = temp->next;
    free(temp);
    return result;
}

/*
@brief Updates top song list with increasing listening length and puts elements with avoiding duplication
 
@param topSongList  The top song list
@param song  Song to be updated or added
*/
void updateTopSongList(SongNode *topSongList, SongNode *song){
    SongNode *iterator = topSongList;
    int found = 0;
    
    /* Create head node if empty */
    if (topSongList->length == 0) {
        /* Copy song information */
        strcpy(topSongList->title, song->title);
        topSongList->songId = song->songId;
        topSongList->length = song->length;
        return;
    } else {
        /* Check for head nodes equality to the song*/
        if (topSongList->songId == song->songId){
            topSongList->length += song->length;
            return;
        }
    }
    
    /* Finds if the song exists in the list and increases */
    while (iterator->next != NULL && found == 0) {
        if (iterator->next->songId == song->songId){
            iterator->next->length += song->length;
            found = 1;
        }
        
        iterator = iterator->next;
    }
    
    /* If not found create a new node */
    if (found == 0) {
        iterator->next = (SongNode *)malloc(sizeof(SongNode));
        /* Copy song information */
        strcpy(iterator->next->title, song->title);
        iterator->next->songId = song->songId;
        iterator->next->length = song->length;
    }
}

/*
@brief For all users randomly selects random amount of list to listen and randomly listens songs with random count chosen from all song count (N) . Selects next song randomly within the range [-N/2, N/2].
 
@param users  The list of all users
@param topSongList  The list of top songs list
*/
void listenMusic(UserNode *users, SongNode *topSongList){
    UserNode *userIterator = users;
    SongListCollection *listIterator;
    SongNode *songIterator;

    int i, j, z;
    int listIndex;
    int randomListCount;
    int firstRandomListIndex;
    int randomSongCount;
    int nextSongSkipAmount;
    int totalSongCount;
    int firstRandomSongIndex;

    /* For all users */
    while (userIterator != NULL) {
        printf("\nUser %d: \n", userIterator->userId);

        randomListCount = rand() % calculateTotalListCount(userIterator) + 1;
        
        listIterator = userIterator->lists;
        
        /* For random amount of the lists of the user*/
        /* Starting from first list (assuming user will start from the first list)*/
        i = 0;
        while (i < randomListCount){
            printf(GREEN_BOLD "Playing List: %d" RESET "\n", i);
            totalSongCount = calculateTotalSongCount(listIterator->songList);
            
            randomSongCount = rand() % totalSongCount + 1;
            firstRandomSongIndex = rand() % totalSongCount;
            
            songIterator = listIterator->songList;
            
            /* Select a random song to start for better randomness */
            for (z = 0; z < firstRandomSongIndex; z++) {
                songIterator = songIterator->next;
            }
            
            /* For random amount of the songs of the list*/
            j = 0;
            while (j < randomSongCount) {
                /* Select a skip amount*/
                nextSongSkipAmount = (rand() % (totalSongCount + 1)) - (totalSongCount / 2);
                
                /* For better randomness */
                if (nextSongSkipAmount == 0){
                    nextSongSkipAmount += (rand() % 2) * 2 - 1; /* -1 or 1*/
                }
                
                /* Skip songs */
                for (z = 0; z < abs(nextSongSkipAmount); z++) {
                    if (nextSongSkipAmount < 0){
                        songIterator = songIterator->prev;
                    } else {
                        songIterator = songIterator->next;
                    }
                }
                
                updateTopSongList(topSongList, songIterator);
                printf("Playing : %s\n", songIterator->title);
                j++;
            }
            
            listIterator = listIterator->next;
            i++;
        }
        userIterator = userIterator->next;
    }
}

/*
@brief Selects song with selection index then writes information to third paramater
 
@param appSongs  App's all song list
@param selection  Selection index
@param song The song to data be written
*/
void selectSong(SongNode *appSongs, int selection, SongNode *song){
    int i = 1;
    
    while (appSongs != NULL) {
        if (i == selection) {
            strcpy(song->title, appSongs->title);
            song->length = appSongs->length;
            song->songId = appSongs->songId;
        }
        
        appSongs = appSongs->next;
        i++;
    }
}

/*
@brief Menu function for list and song creation
 
@param appSongs  App's all song list
@param N  size of the appSongs
@param userSongList  The list that contains all song lists of the user
*/
void listMenu(SongNode *appSongs, int N, SongListCollection *userSongList){
    int choice = 0;
    int input = 0;
    int duplicated; /* For avoiding duplications */
    int songCount = 0;
    int j;
    
    /* Exclude already selected songs to avoid duplication */
    int *excludedSongs = (int *)malloc(N * sizeof(int));
    
    /* Use a iterator to avoid losing the head node */
    SongNode *iterator = NULL;
    
    printSongs(appSongs, N, 0, excludedSongs);

    while (1) {
        duplicated = 0;
        input = getInput();
        clearScreen();
        
        if (input == 0){ /* E key is pressed*/
            if (choice == 0){ /* Save option is selected */
                if (songCount > 0){
                    free(excludedSongs);
                    /* Connect head and the tail of the user's song list */
                    iterator->next = userSongList->songList;
                    userSongList->songList->prev = iterator->next;
                    return;
                }
                printf("\nSelect a song first!\n");
            }
            else {
                /* Check if chosen song is already selected */
                for (j = 0; j < N; j++) {
                    if (choice == excludedSongs[j]){
                        duplicated = 1;
                    }
                }
                
                /* If chosen song is new */
                if (duplicated == 0){
                    /* If the song is first then create first node*/
                    if (songCount == 0){
                        userSongList->songList = (SongNode *)malloc(sizeof(SongNode));
                        
                        /* Start the iterator */
                        iterator = userSongList->songList;
                        
                        /* Select song then add to exclude list*/
                        selectSong(appSongs, choice, iterator);
                        excludedSongs[songCount] = choice;
                    }
                    /* If a song is already on the list */
                    else {
                        iterator->next = (SongNode*)malloc(sizeof(SongNode));
                        selectSong(appSongs, choice, iterator->next);
                        
                        excludedSongs[songCount] = choice;
                        /* Connect previous node*/
                        iterator->next->prev = iterator;
                        iterator = iterator->next;
                    }

                    songCount++;
                }
            }
        }
        
        updateChoice(&choice, input, N + 1);
        printSongs(appSongs, N, choice, excludedSongs);
    }
}


/*
@brief Menu function user creation
 
@param users  App's all users list
@param appSongs  App's all songs list (Needed for passing into listMenu)
@param N  The size of the appSongs list
 
@return The created list count
*/
int userMenu(UserNode **users, SongNode *appSongs, int N){
    int choice = 0;
    int input;
    int listCount = 0;
    SongListCollection *iterator = NULL;
    UserNode *user = NULL;

    clearScreen();
    printChoices(choiceSuiteUserMenu, USER_MENU_LENGTH, 0, 1);
    
    while (1) {
        input = getInput();
        clearScreen();
        
        if (input == 0){
            if (choice == 0){
                return listCount;
            }
            
            /* Create a list */
            if (choice == 1){
                if (listCount == 0){
                    /* Create user first */
                    user = createUser(users);
                    /* Create a collection list for storing multiple song lists*/
                    user->lists =    (SongListCollection*)malloc(sizeof(SongListCollection));
                    /* Start the iterator*/
                    iterator = (user)->lists;
                    
                    listMenu(appSongs, N, iterator);
                }
                else {
                    iterator->next = (SongListCollection*)malloc(sizeof(SongListCollection));
                    
                    listMenu(appSongs, N, iterator->next);
                }
                
 
                if (listCount != 0){
                    iterator = iterator->next;
                }
                    
                listCount++;
            }
        }
        
        updateChoice(&choice, input, USER_MENU_LENGTH);

        printChoices(choiceSuiteUserMenu, USER_MENU_LENGTH, choice, 0);
        
        if (listCount != 0){
            printTotalListCount(user);
        }
        
        printf(menuDown);
        
        if (listCount != 0){
            printf("\nSelected songs in the last list:\n");
            printListSongs(iterator->songList);
        }
    }
}

/*
@brief Main menu function
 
@param users  App's all users
@param appSongs  App's all songs list
@param N  Size of the appSongs list
*/
void mainMenu(UserNode *users, SongNode *appSongs, int N){
    int choice = 0;
    int input;
    int userCount = 0;
    int userCreated;
    SongNode *topSongList = (SongNode *)malloc(sizeof(SongNode));
    
    clearScreen();
    printChoices(choiceSuiteMainMenu, MAIN_MENU_LENGTH, 0, 1);
    
    while (1) {
        input = getInput();
        clearScreen();
        
        if (input == 0){ /* E key*/
            switch (choice) {
                case 0:
                    freeSongs(topSongList);
                    return;
                case 1:
                    userCreated = userMenu(&users, appSongs, N);
                    if (userCreated != 0){
                        userCount++;
                    }
                    break;
                case 2:
                    if (userCount == 0){
                        printf("\nWhy not add some users first?\n");
                    } else {
                        listenMusic(users, topSongList);
   
                    }
                    break;
                case 3:
                    if (topSongList->length != 0){
                        topSongList = sort(topSongList);
                        printTopList(topSongList);
                    } else {
                        printf("\nWhy not listen to a song first?\n");
                    }
                    break;
            }
        }
        
        updateChoice(&choice, input, MAIN_MENU_LENGTH);
        
        printChoices(choiceSuiteMainMenu, MAIN_MENU_LENGTH, choice, 0);
        
        if (userCount != 0){
            printTotalUserCount(users);
        }
        
        printf(menuDown);
    }
}

int main(int argc, const char * argv[]) {
    int N;
    SongNode *appSongsHead;
    UserNode *users = NULL; /* Will be created in users menu*/
    
    srand((unsigned int) time(NULL));

    printf("Enter total song count (N): ");
    scanf("%d", &N);
        
    appSongsHead = (SongNode *)malloc(sizeof(SongNode));
    
    createSongs(appSongsHead, N);
    
    mainMenu(users, appSongsHead, N);
    
    free(appSongsHead);
    freeUsers(users); /* Frees all the embedded lists combined */
    return 0;
}

