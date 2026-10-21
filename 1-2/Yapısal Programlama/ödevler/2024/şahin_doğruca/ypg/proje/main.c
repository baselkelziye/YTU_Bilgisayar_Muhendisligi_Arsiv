

#include "game.h"

// holds the logged in user equals null if there is no logged in user
User *currentUser = NULL;

void loginUser(char *);
void registerUser(User **, char *);
void getUserInfo(User **, char *);
void logUserToFile(User *, char *);
int isLoggedIn();
void displayOneUser(char *);
void displayUsers(char *);
int contains(char *, char *);
int isUserExist(char *, char *, char *);
void gameMenu();
void playerMenu();
void mainMenu(char *);
char **getMapArray(char *, char **, int *);
void uploadMap(char *, char *);
void gameInfo();

// check file for conflicting nick names
int contains(char *nick, char *filename)
{

    FILE *file = fopen(filename, "rb");

    if (file != NULL)
    {
        User user;

        while (fread(&user, sizeof(User), 1, file) == 1)
        {
            if (strcmp(user.nickName, nick) == 0)
            {
                printf("\nThis nick name already taken. Please select Another\n");
                fclose(file);
                return 1;
            }
        }

        fclose(file);
        return 0;
    }
    else
    {
        return 0;
    }

    return 0;
}

// check a user logged in
int isLoggedIn()
{
    if (currentUser != NULL)
        return 1;
    return 0;
}

// checks if the given first and last name matches any user credentials in the file
int isUserExist(char *nick, char *password, char *filename)
{
    FILE *file = fopen(filename, "rb");

    if (file != NULL)
    {
        User user;

        while (fread(&user, sizeof(User), 1, file) == 1)
        {
            if (strcmp(user.nickName, nick) == 0 && strcmp(user.password, password) == 0)
            {
                printf("loged in successfully !!!\n");
                User *p = (User *)malloc(sizeof(User));

                strcpy(p->nickName, user.nickName);
                strcpy(p->name, user.name);
                strcpy(p->surname, user.surname);
                strcpy(p->password, user.password);

                // current user is equals to logged in user
                currentUser = p;

                fclose(file);
                return 1;
            }
        }

        fclose(file);
        return 0;
    }
    else
    {
        return 0;
    }

    return 0;
}

void loginUser(char *filename)
{
    system("clear");

    char name[MAX], password[MAX];
    int ch;

    do
    {
        printf("\n1- enter username and password");
        printf("\n2- Enter q or ESC for return back to the main menu : ");
        ch = getch();

        if (ch == 49)
        {
            system("clear");
            printf("\nusername : ");
            scanf("%s", name);
            printf("\npassword : ");
            scanf("%s", password);

            // if there is not a logged in user and credentials true
            // logs in user
            // else
            if (isLoggedIn() || !isUserExist(name, password, filename))
            {
                printf("username or password is wrong\n");
            }
        }

    } while (ch != 27 && ch != 'q' && ch != 2 && !isLoggedIn());
}

void registerUser(User **user, char *filename)
{
    getUserInfo(user, filename);
    logUserToFile(*user, filename);
}

// display user who is logged in credentials
void displayOneUser(char *filename)
{
    FILE *file = fopen(filename, "rb"); // Open the file for binary reading
    int i = 0;
    if (file != NULL)
    {
        User user;
        printf("\nUser Information:\n");

        while (fread(&user, sizeof(User), 1, file) == 1)
        {
            if (strcmp(user.nickName, currentUser->nickName) == 0)
            {
                printf("nickName : %s\n", user.nickName);
                printf("Name : %s\n", user.name);
                printf("Surname : %s\n", user.surname);
                printf("Password : %s\n", user.password);
                printOneUser("players.dat", &user);
            }
        }

        // Close the file
        fclose(file);
        printf("\n");
    }
    else
    {
        printf("Error opening file %s for reading\n", filename);
    }
}

// display all users for devs
void displayUsers(char *filename)
{
    FILE *file = fopen(filename, "rb"); // Open the file for binary reading
    int i = 0;
    if (file != NULL)
    {
        User user;
        printf("\nUser Information:\n");

        while (fread(&user, sizeof(User), 1, file) == 1)
        {
            printf("nickName : %s\n", user.nickName);
            printf("Name : %s\n", user.name);
            printf("Surname : %s\n", user.surname);
            printf("Password : %s\n", user.password);
            printOneUser("players.dat", &user);
            printf("----------------------------\n");
        }

        // Close the file
        fclose(file);
        printf("\n");
    }
    else
    {
        printf("Error opening file %s for reading\n", filename);
    }
}

// write given user to the file
void logUserToFile(User *user, char *filename)
{
    FILE *file = fopen(filename, "ab+");

    if (file != NULL)
    {
        // Write the student structure to the file
        fwrite(user, sizeof(User), 1, file);

        // Close the file
        fclose(file);

        printf("user information has been written to %s\n", filename);
    }
    else
    {
        printf("Error opening file %s for writing\n", filename);
    }
}

void getUserInfo(User **user, char *filename)
{
    User *p;
    p = (User *)malloc(sizeof(User));

    char text[100];

    system("clear");

    do
    {
        printf("Please enter your username : ");
        scanf("%s", text);
        strcpy(p->nickName, text);
        p->nickName[strlen(text)] = '\0';

        // check for conflicting username
    } while (contains(p->nickName, filename));

    printf("Please enter your name : ");
    scanf("%s", text);
    strcpy(p->name, text);
    p->name[strlen(text)] = '\0';

    printf("Please enter your surname : ");
    scanf("%s", text);
    strcpy(p->surname, text);
    p->surname[strlen(text)] = '\0';

    printf("Please enter your password : ");
    scanf("%s", text);
    strcpy(p->password, text);
    p->password[strlen(text)] = '\0';

    (*user) = p;
}

void mainMenu(char *filename)
{

    User *user;
    int inp;

    do
    {
        system("clear");
        printf("Welcome to the game !!!\n");
        printf("1- I am new here - register\n");
        printf("2- I am already joined\n");
        printf("3- show top 5 score\n");
        printf("4- game Information\n");
        printf("5- I want to exit (you can press ESC)\n");

        printf("select one : ");
        inp = getch();

        // if entered 5 or ESC do nothing and exit the program
        if (inp == 53 || inp == 27)
        {
        }
        else if (inp == 49)
        { // equals 1
            registerUser(&user, filename);
        }
        else if (inp == 50)
        { // equals 2
            // logs user and open playerMenu
            loginUser(filename);
            playerMenu();
        }
        else if (inp == 51)
        { // equals 3
            system("clear");

            findTopScores("players.dat");

            printf("press a key to continue\n");
            getch();
        }
        else if (inp == 52)
        {
            system("clear");

            gameInfo();

            printf("press a key to continue");
            getch();
        }

    } while (inp != 53 && inp != 27 && !isLoggedIn());
}

void gameInfo()
{
    printf("\n\nThe aim of this game is to produce antagonistic hydrogens as fast as possible. \nThe more antihydrogens you produce and the faster you do it \nthe more points you get.");
    printf("\n\nScoring : \n\tantihydrogen : 100\n\tremaining time : 2\n\n");
    printf("In the game, K's represent black holes, if you press K, you lose the game\nYou start the game at 'G' (Entrance) and try to reach 'C' before time runs out. \nIf time runs out, you lose the game.\nGood luck !!!\n\n");
}

void playerMenu()
{
    system("clear");
    int ch;
    char name[MAX];

    do
    {
        if (currentUser != NULL)
        {
            system("clear");
            printf("Welcome %s !!\n", currentUser->nickName);
            printf("What would you like to\n");
            printf("1- give it a whirl\n");
            printf("2- upload a map\n");
            printf("3- user Informations\n");
            printf("4- logout (press q or ESC) : \n");

            ch = getch();

            if (ch == 52 || ch == 27 || ch == 113)
            {
                currentUser = NULL;
            }
            else if (ch == 49)
            { // equals 1
                gameMenu();
            }
            else if (ch == 50)
            {
                system("clear");

                printf("Choose a name for map : ");
                scanf("%s", name);
                uploadMap("maps.txt", name);

                printf("press a key to continue\n");
                getch();
            }
            else if (ch == 51)
            {
                system("clear");

                // display user information including scores
                displayOneUser("users.dat");
                printf("press a key to continue\n");
                getch();
            }
        }
    } while (ch != 52 && ch != 27 && ch != 113 && isLoggedIn());
}

void uploadMap(char *filename, char *name)
{
    FILE *file;

    // if there is not a file named 'name' return
    // upload file first
    char tempFname[100];
    strcpy(tempFname, name);
    strcat(tempFname, ".txt");
    if (!(file = fopen(tempFname, "r")))
    {
        printf("please load the map first\n");
        return;
    }

    file = fopen(filename, "a");

    if (file != NULL)
    {
        fprintf(file, ":%s.txt", name);

        fclose(file);
    }
    else
    {
        printf("Error when open the file");
    }
}

// read the maps.txt file and assign those to the maps array
char **getMapArray(char *filename, char **maps, int *mapCount)
{
    FILE *file = fopen(filename, "r");
    maps = (char **)malloc(sizeof(char *) * 0);
    int i = 0, j = 0;

    char line[100];
    fread(line, sizeof(line), 1, file);

    char *token = strtok(line, ":");

    while (token != NULL)
    {
        maps = realloc(maps, sizeof(char *) * (i + 1));
        maps[i] = malloc(sizeof(char) * (sizeof(token) + 1));
        strcpy(maps[i], token);
        maps[i][sizeof(token)] = '\0';
        i++;
        token = strtok(NULL, ":");
    }

    *mapCount = i;

    fclose(file);
    return maps;
}

void gameMenu()
{
    int ch, i;
    char **maps;

    int mapCount = 0;

    // load maps from the maps.txt
    maps = getMapArray("maps.txt", maps, &mapCount);

    do
    {
        system("clear");
        printf("maps : \n");
        for (i = 0; i < mapCount; i++)
        {
            printf("%d- %s\n", i + 1, maps[i]);
        }

        printf("\nPress q or ESC for return back to the player menu\n");
        printf("select : ");
        ch = getch();

        // if client don't press the 'q! or ESC
        if (ch != 113 && ch != 27)
        {
            // 49 equals to 1
            // so if client press 2(50) access maps[1] : second map

            preparations(maps[ch - 49], currentUser);
        }

    } while (ch == 133 || ch == 27);

    free(maps);
}

int main()
{
    mainMenu("users.dat");

    return 0;
}
