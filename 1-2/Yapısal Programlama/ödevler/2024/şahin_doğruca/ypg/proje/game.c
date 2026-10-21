#include "game.h"

// to perceive arrow keys and ESC
int getch(void)
{
    int buf = 0;
    struct termios old = {0};

    fflush(stdout);

    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");

    old.c_lflag &= ~(ICANON | ECHO);
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");

    if (read(0, &buf, sizeof(buf)) < 0)
        perror("read()");

    old.c_lflag |= ICANON | ECHO;

    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");

    return buf;
}

// read from the file and convert map to the matrix
void loadMap(char *filename, char ***mapRef, int *rowCount, int *wordCount)
{

    FILE *file = fopen(filename, "r");


    if (file != NULL)
    {
        int i;
        char text[1000];

        while (fgets(text, sizeof(text), file) != NULL)
        {
            (*mapRef) = realloc((*mapRef), sizeof(char *) * (*rowCount + 1));
            (*mapRef)[*rowCount] = (char *)malloc(sizeof(char) * 0);
            *wordCount = 0;

            for (i = 0; text[i] != '\0'; i++)
            {
                (*mapRef)[*rowCount] = realloc((*mapRef)[*rowCount], sizeof(char) * ((*wordCount) + 1));
                (*mapRef)[*rowCount][*wordCount] = text[i];
                (*wordCount)++;
            }

            (*mapRef)[*rowCount][*wordCount] = '\0';

            (*rowCount)++;
        }

        fclose(file);
    }
    else
    {
        perror("Error opening file");
    }
}

void printMap(char **map, int rowCount)
{
    int i, j;
    printf("\n\n");

    for (i = 0; i < rowCount; i++)
    {
        for (j = 0; map[i][j] != '\0'; j++)
        {
            printf("%c\t", map[i][j]);
        }
        printf("\n");
    }
}

// finds the number of rows and columns of the first match of the queried character
void find(char **map, int rowCount, char term, int *y, int *x)
{
    for ((*y) = 0; (*y) < rowCount; (*y)++)
    {
        for ((*x) = 0; map[*y][*x] != '\0'; (*x)++)
        {
            if (map[*y][*x] == term)
                return;
        }
    }
}

void printOneUser(char *filename, User *user)
{
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Player player;

    // Print player which is queried scores
    while (fread(&player, sizeof(Player), 1, file) == 1)
    {
        if (strcmp(player.name, user->nickName) == 0)
        {
            printf("%s (%d scores):", player.name, player.scoreCount);
            for (int i = 0; i < player.scoreCount; i++)
            {
                printf(" %d", player.scores[i]);
            }
            printf("\n");
            break;
        }
    }

    fclose(file);
}

void addScore(char *filename, const char *name, int score)
{
    FILE *file = fopen(filename, "rb+");

    if (file == NULL)
    {
        file = fopen(filename, "wb");
        fclose(file);
        file = fopen(filename, "rb+");
    }

    Player player;
    int found = 0;

    // Search for the player in the file
    while (fread(&player, sizeof(Player), 1, file) == 1)
    {
        if (strcmp(player.name, name) == 0)
        {
            // Player found, update the scores
            if (player.scoreCount < MAX)
            {
                player.scores[player.scoreCount++] = score;
                // delete the player and write it again
                printf("%d", score);
                // return back to the player struct's start
                fseek(file, -sizeof(Player), SEEK_CUR);
                // and write it again
                fwrite(&player, sizeof(Player), 1, file);
            }
            else
            {
                printf("Player's score array is full. Cannot add a new score.\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        // Player not found, append a new entry
        fseek(file, 0, SEEK_END);
        strcpy(player.name, name);
        player.scores[0] = score;
        player.scoreCount = 1;
        fwrite(&player, sizeof(Player), 1, file);
    }

    fclose(file);
}

void findSubatomicalPatterns(char **map, int **path, int coorCount, char **aMatters, int *aMatterCount)
{
    int i;
    char term;
    for (i = coorCount - 1; i >= 0; i--)
    {
        term = map[path[i][0]][path[i][1]];
        if (term == 'P' || term == 'p' || term == 'e' || term == 'E')
        {
            (*aMatters) = realloc(*aMatters, sizeof(char) * ((*aMatterCount) + 1));
            (*aMatters)[*aMatterCount] = term;
            (*aMatterCount)++;
        }
    }
}

// preps before beginning of the game
void preparations(char *filename, User *currentUser)
{
    int rowCount = 0, wordCount = 0;
    char **map;
    int seconds = 60, remain_sec = 0;
    int i, ch, aHydrogens = 0;

    printf("\n1- user (manuel)\n");
    printf("2- automatic \n");
    printf("3- return back to the player menu\n");
    printf("select : ");

    ch = getch();

    if (ch != 51 && ch != 27)
    {
        // load map
        map = (char **)malloc(sizeof(char *) * 0);
        loadMap(filename, &map, &rowCount, &wordCount);

        if (ch == 50)
        {
            // auto play
            system("clear");
            // stores shortest path coordinates
            int **path;
            int coorCount = 0;

            // stores subatomical anti matters
            char *aMatters;
            int aMatterCount = 0;
            aMatters = (char *)malloc(sizeof(char) * 0);

            findShortestPath(&path, &coorCount, map, rowCount, wordCount);

            for (i = coorCount - 1; i >= 0; i--)
            {
                if (i != 0)
                    printf("(%d,%d) -> ", path[i][0], path[i][1]);
                else
                    printf("(%d,%d)\n", path[i][0], path[i][1]);
            }

            findSubatomicalPatterns(map, path, coorCount, &aMatters, &aMatterCount);
            printMatters(aMatters, aMatterCount);
            printf("\n");
            updateAMatters(&aMatters, &aMatterCount);
            printMatters(aMatters, aMatterCount);

            isGameWon(aMatters, aMatterCount);

            getch();

            for (i = 0; i < coorCount; i++)
                free(path[i]);
            free(path);
        }
        else if (ch == 49)
        {
            // user

            // thread for countdown
            pthread_t thread;
            pthread_create(&thread, NULL, countdown, (void *)&seconds);

            aHydrogens = startUser(&map, rowCount, &seconds, &remain_sec);

            // it means game is won and we have anti Hydrogens
            if (aHydrogens > 0)
            {
                // then stop the countdown and return to the menu

                if (remain_sec == 0)
                {
                    remain_sec = seconds;
                    seconds = 0;
                }



                addScore("players.dat", currentUser->name, (aHydrogens * 100) + (remain_sec * 2));

                system("clear");
                printf("\nCongratulations !!! \nYou win the game\nYour score is %d\n", (aHydrogens * 100) + (remain_sec * 2));
                printf("\npress a key for continue");
                getch();
            }
            if (aHydrogens == 0)
            {
                // time is over
                seconds = 0;
            }

            pthread_join(thread, NULL);
        }
    }

    for (i = 0; i < rowCount; i++)
    {
        free(map[i]);
    }
    free(map);
}

// start of the automatic play

// queue operaions required for automatic play
Queue *createQueue(unsigned capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (Node *)malloc(capacity * sizeof(Node));
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->front > queue->rear;
}

void enqueue(Queue *queue, int row, int col, int distance)
{
    Node newNode;
    newNode.row = row;
    newNode.col = col;
    newNode.distance = distance;

    if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
        queue->array[0] = newNode;
    }
    else
    {
        queue->rear++;
        queue->array[queue->rear] = newNode;
    }
}

Node dequeue(Queue *queue)
{
    Node emptyNode = {-1, -1, -1};
    if (isEmpty(queue))
    {
        return emptyNode;
    }

    Node frontNode = queue->array[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }

    return frontNode;
}

// is valid function for automatic play
int isValidAuto(int row, int col, int ROW, int COL)
{
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

int isDestination(int row, int col, int destRow, int destCol)
{
    return (row == destRow && col == destCol);
}

void printMapWithTraversal(char **map, int ROW, int COL, int visited[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (visited[i][j])
            {
                printf("X ");
            }
            else
            {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void findShortestPath(int ***pathRef, int *coorCount, char **map, int ROW, int COL)
{

    // declare start and end coordinates
    int startRow, startCol;
    int destRow, destCol;

    find(map, ROW, 'G', &startRow, &startCol);
    find(map, ROW, 'C', &destRow, &destCol);

    Queue *queue = createQueue(ROW * COL);
    (*pathRef) = (int **)malloc(sizeof(int *) * 0);

    // visited array for optimization
    // we don't want to visit a visited node
    int visited[ROW][COL];
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            visited[i][j] = 0;
        }
    }

    // add start to queue
    enqueue(queue, startRow, startCol, 0);
    visited[startRow][startCol] = 1;
    printMapWithTraversal(map, ROW, COL, visited);

    int parent[ROW][COL]; // Her hücrenin bir önceki hücresini saklamak için
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            parent[i][j] = -1;
        }
    }

    // direction matrixes
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    while (!isEmpty(queue))
    {
        // take one node from the queue
        Node current = dequeue(queue);

        int row = current.row;
        int col = current.col;
        int distance = current.distance;

        if (isDestination(row, col, destRow, destCol))
        {
            // En kısa yolun mesafesini yazdır
            printf("shortest path : %d step\n", distance);

            // en kısa yolu oluşturur
            while (parent[row][col] != -1)
            {

                (*pathRef) = realloc(*pathRef, sizeof(int *) * (*coorCount + 1));
                (*pathRef)[*coorCount] = (int *)malloc(sizeof(int) * 2);
                ((*pathRef)[*coorCount])[0] = row;
                ((*pathRef)[*coorCount])[1] = col;
                (*coorCount)++;

                int tempRow = row;
                int tempCol = col;

                // calculate new row and column
                col = parent[tempRow][tempCol] % COL;
                row = parent[tempRow][tempCol] / COL;
            }

            // add last point
            (*pathRef) = realloc(*pathRef, sizeof(int *) * (*coorCount + 1));
            (*pathRef)[*coorCount] = (int *)malloc(sizeof(int) * 2);
            ((*pathRef)[*coorCount])[0] = row;
            ((*pathRef)[*coorCount])[1] = col;
            (*coorCount)++;

            return;
        }

        for (int i = 0; i < 4; i++)
        {
            // looks along every direction
            int newRow = row + rowNum[i];
            int newCol = col + colNum[i];

            // check is there isn't out of bounds, no wall and no visited point
            if (isValidAuto(newRow, newCol, ROW, COL) && map[newRow][newCol] != '1' && !visited[newRow][newCol])
            {
                visited[newRow][newCol] = 1;
                parent[newRow][newCol] = row * COL + col; // Önceki hücrenin indisini sakla

                // add point to the queue
                enqueue(queue, newRow, newCol, distance + 1);

                printMapWithTraversal(map, ROW, COL, visited);
            }
        }
    }

    printf("The path to C was not found.\n");
}

// end of the automatic play

// starts user play

// is valid function for user play
int isValid(char **map, int rowCount, int y, int x, int dirX[], int dirY[], int dir)
{
    int nx = x + dirX[dir];
    int ny = y + dirY[dir];

    if (ny < 0 || ny >= rowCount)
        return 0;
    if (nx < 0 || map[ny][nx] == '\0')
        return 0;
    if (map[ny][nx] == '1')
        return 0;

    return 1;
}

void updateMap(char ***mapRef, int *y, int *x, int dirX[], int dirY[], int dir)
{
    // mark the last node with 0 and update x and y

    (*mapRef)[*y][*x] = '0';
    (*y) += dirY[dir];
    (*x) += dirX[dir];
}

// print matters in a beautiful format
void printMatters(char *aMatters, int len)
{
    int i;
    printf("\ncollected subatomic particles : \n");
    for (i = 0; i < len; i++)
    {
        switch (aMatters[i])
        {
        case 'e':
            printf("e-");
            break;
        case 'E':
            printf("e+");
            break;
        case 'P':
            printf("P+");
            break;
        case 'p':
            printf("P-");
            break;
        default:
            break;
        }
        printf(" ");
    }

    printf("\n");
}

int isGameWon(char *aMatters, int len)
{
    int i;
    int aHydrogen = 0;

    // we'll have to have twice as many terms left.
    // because we just have to have anti hydrogens
    if (len % 2 == 1)
        return 0;

    // checks anti hydrogens
    for (i = 0; i < len; i += 2)
    {
        if ((aMatters[i] == 'p' && aMatters[i + 1] == 'E') || (aMatters[i] == 'E' && aMatters[i + 1] == 'p'))
        {
            ++aHydrogen;
        }
    }

    // we have p p E p so we must check len equals to (anti hydrogen * 2)
    if (aHydrogen == (len / 2))
        return aHydrogen;

    return 0;
}

void updateAMatters(char **aMatters, int *len)
{
    int i, nLen = 0;
    char temp;
    char *arr = (char *)malloc(sizeof(char) * nLen);

    // if we have P p or E e we must delete this
    // so i mark those adjacent with 0
    for (i = 0; i < (*len) - 1; i++)
    {
        if (((*aMatters)[i] == 'p' && (*aMatters)[i + 1] == 'P') || ((*aMatters)[i] == 'P' && (*aMatters)[i + 1] == 'p'))
        {
            (*aMatters)[i] = '0';
            (*aMatters)[i + 1] = '0';
        }
        else if (((*aMatters)[i] == 'E' && (*aMatters)[i + 1] == 'e') || ((*aMatters)[i] == 'e' && (*aMatters)[i + 1] == 'E'))
        {
            (*aMatters)[i] = '0';
            (*aMatters)[i + 1] = '0';
        }
        else if ((*aMatters)[i] != '0')
        {
            (*aMatters)[nLen] = (*aMatters)[i];
            nLen++;
        }
    }

    if (((*aMatters)[i] != '0'))
    {
        (*aMatters)[nLen] = (*aMatters)[i];
        nLen++;
    }

    (*aMatters) = realloc((*aMatters), sizeof(char) * (nLen));
    *len = nLen;
}

int startUser(char ***mapRef, int rowCount, int *seconds, int *remain_sec)
{
    int isGameLost = 0, isGameEnd = 0;
    int matterCount = 0;
    char *aMatters = (char *)malloc(sizeof(char) * matterCount);

    int y = 0, x = 0;

    find(*mapRef, rowCount, 'G', &y, &x); // get X coordinates

    int dirY[] = {0, 1, 0, -1};
    int dirX[] = {1, 0, -1, 0};
    int dir, ch;

    while (isGameLost == 0 && isGameEnd == 0)
    {
        system("clear");

        (*mapRef)[y][x] = 'X';
        // marks the current position with x

        printMatters(aMatters, matterCount);

        printMap(*mapRef, rowCount);
        printf("Which way do you want to go (use arrow keys) : \n");
        ch = getch();
        switch (ch)
        {
        case 4414235: // right
            if (isValid(*mapRef, rowCount, y, x, dirX, dirY, 0))
                updateMap(mapRef, &y, &x, dirX, dirY, 0);
            break;
        case 4348699: // down
            if (isValid(*mapRef, rowCount, y, x, dirX, dirY, 1))
                updateMap(mapRef, &y, &x, dirX, dirY, 1);
            break;
        case 4479771: // left
            if (isValid(*mapRef, rowCount, y, x, dirX, dirY, 2))
                updateMap(mapRef, &y, &x, dirX, dirY, 2);
            break;
        case 4283163: // up
            if (isValid(*mapRef, rowCount, y, x, dirX, dirY, 3))
                updateMap(mapRef, &y, &x, dirX, dirY, 3);
            break;
        case 27:
            // if pressed esc exit the game
            isGameLost = 1;
            break;
        }

        if ((*mapRef)[y][x] == 'K')
        {
            // lost the game
            isGameLost = 1;
            seconds = 0;
        }
        else if ((*mapRef)[y][x] == 'C')
        {
            isGameEnd = 1;
        }
        else if ((*mapRef)[y][x] != '0')
        {
            aMatters = realloc(aMatters, sizeof(char) * (matterCount + 1));
            aMatters[matterCount] = (*mapRef)[y][x];
            matterCount++;
        }
        else if (*seconds == 0)
        {
            // time is up
            isGameLost = 1;
        }

        (*mapRef)[y][x] = 'X';
    }

    if (isGameLost == 1)
    {
        printf("\nYou lost the game \n");
        return 0;
    }
    else if (isGameEnd == 1)
    {
        printMatters(aMatters, matterCount);

        // delete the p P e E
        updateAMatters(&aMatters, &matterCount);
        printMatters(aMatters, matterCount);
        *remain_sec = *seconds;
        *seconds = 0;
        printf("press a key to continue");
        getch();
        return isGameWon(aMatters, matterCount);
    }

    return 0;
}

void *countdown(void *seconds)
{
    while (*((int *)seconds) > 0)
    {
        printf("\r%04d", *((int *)seconds));
        fflush(stdout);
        clock_t stop = clock() + CLOCKS_PER_SEC;
        while (clock() < stop)
        {
        }
        (*((int *)seconds))--;
    }

    return NULL;
}

// check for a > b
int compareScores(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

// Function to find and print the top 5 scores
void findTopScores(char *filename)
{
    FILE *file = fopen(filename, "rb");

    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    Player player;
    int playerCount = 0, i, j, count = 0, playerId = 0;

    // for store player names (user nicknames)
    char **names = (char **)malloc(sizeof(char *) * 0);

    while (fread(&player, sizeof(Player), 1, file) == 1)
    {
        names = realloc(names, sizeof(char) * (playerCount + 1));
        names[playerCount] = (char *)malloc(sizeof(char) * (strlen(player.name) + 1));
        strcpy(names[playerCount], player.name);
        names[playerCount][strlen(player.name)] = '\0';
        playerCount++;
    }

    // to return begin of the file
    fseek(file, 0, SEEK_SET);

    // store scores
    int topScores[MAX][2] = {0};

    // Read scores and store in the topScores array
    while (fread(&player, sizeof(Player), 1, file) == 1)
    {
        for (i = 0; i < player.scoreCount; i++)
        {
            topScores[count][0] = playerId;
            topScores[count++][1] = player.scores[i];
        }
        playerId++;
        // every player has a unique id, so later we can access them with id
    }

    fclose(file);

    // Sort the topScores array in descending order
    int max = 0;
    int temp;

    // 5 because we just want biggest 5 scores
    for (i = 0; i < 5; i++)
    {
        max = i;
        for (j = i + 1; j < count; j++)
        {
            if (topScores[j][1] > topScores[max][1])
            {
                temp = topScores[j][0];
                topScores[j][0] = topScores[max][0];
                topScores[max][0] = temp;

                temp = topScores[j][1];
                topScores[j][1] = topScores[max][1];
                topScores[max][1] = temp;
            }
        }
    }

    // Print the top 5 scores
    printf("\n\nTop 5 Scores:\n");
    for (i = 0; i < 5 && i < count; i++)
        printf("%s : %d\n", names[topScores[i][0]], topScores[i][1]);

    printf("\n");

    for (i = 0; i < playerCount; i++)
        free(names[i]);
    free(names);
}
