#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define EOP -1
#define TOP 10
typedef struct Song
{
    char name[10];
    int duration;
} Song;

typedef struct Song_Info
{
    char name[10];
    int listen_ctr;
    int duration;
} Song_Info;

typedef struct DoubleNode
{
    Song song;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;

typedef struct Node
{
    Song song;
    struct Node *next;
} Node;

typedef struct User
{
    DoubleNode *playlist_head;
    Node *listened_head;
    int playlist_length;
    int listened_count;
    int listened_duration;
} User;

/**
 * @brief Creates a new double-linked list node with the given song.
 *
 * @param song The song to be stored in the new node.
 * @return DoubleNode* Pointer to the newly created node.
 */
DoubleNode *createNode(Song song);

/**
 * @brief Appends a new node with the given song to the end of the double-linked list.
 *
 * @param head Pointer to the head of the double-linked list.
 * @param song The song to be added to the list.
 */
void append(DoubleNode **head, Song song);

/**
 * @brief Prints the playlist stored in the double-linked list.
 *
 * @param head Pointer to the head of the double-linked list.
 */
void printPlaylist(DoubleNode *head);

/**
 * @brief Moves a pointer in the double-linked list by a specified number of steps.
 *
 * @param start Pointer to the starting node.
 * @param steps The number of steps to move (positive for forward, negative for backward).
 * @return DoubleNode* Pointer to the node reached after moving.
 */
DoubleNode *moveSteps(DoubleNode *start, int steps);

/**
 * @brief Appends a new node with the given song to the end of a single-linked list.
 *
 * @param head Pointer to the head of the single-linked list.
 * @param song The song to be added to the list.
 */
void appendNormal(Node **head, Song song);

/**
 * @brief Creates a new single-linked list node with the given song.
 *
 * @param song The song to be stored in the new node.
 * @return Node* Pointer to the newly created node.
 */
Node *createNormalNode(Song song);

/**
 * @brief Prints the songs stored in the single-linked list.
 *
 * @param head Pointer to the head of the single-linked list.
 */
void printNormalList(Node *head);

/**
 * @brief Searches for a song in a single-linked list.
 *
 * @param song The song to search for.
 * @param list_head Pointer to the head of the single-linked list.
 * @return int Index of the song in the list if found, -1 otherwise.
 */
int search_in_llist(Song song, Node *list_head);

/**
 * @brief Creates a top-X list of songs based on listening data.
 *
 * @param songs Array of all songs.
 * @param listened_songs_head Pointer to the head of the single-linked list of listened songs.
 * @param song_info_arr Array to store information about the top-X songs.
 * @param top_x The number of top songs to include in the list.
 * @param N The total number of songs in the array.
 */
void makeTopxList(Song *songs, Node *listened_songs_head, Song_Info *song_info_arr, int top_x, int N);

int main()
{
    int N, K;
    Song *songs;
    User *users;
    Song_Info *arr;
    int songNo = 0;
    int i, j = 0;
    int rnd_max, rnd_min;

    srand(time(NULL));

    // N , K - file read operation
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d %d", &N, &K);

    songs = (Song *)malloc(N * sizeof(Song));
    users = (User *)malloc(K * sizeof(User));
    arr = (Song_Info *)malloc(K * sizeof(Song_Info));

    if (songs == NULL || users == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // song and user read operation

    // Read song info
    for (i = 0; i < N; i++)
    {
        fscanf(file, "%s %d", songs[i].name, &songs[i].duration);
    }

    // Print song information
    for (i = 0; i < N; i++)
    {
        printf("Song %d: Name = %s, Duration = %d seconds\n", i + 1, songs[i].name, songs[i].duration);
    }

    for (i = 0; i < K; i++)
    {
        users[i].playlist_head = NULL;
        users[i].listened_head = NULL;
        users[i].listened_count = 0;
        users[i].listened_duration = 0;
        users[i].playlist_length = 0;

        songNo = 0;
        while (songNo != EOP)
        {
            fscanf(file, "%d", &songNo);
            printf("%d ", songNo);

            if (songNo != EOP)
            {
                append(&users[i].playlist_head, songs[songNo - 1]);
                users[i].playlist_length++;
            }
        }
    }

    fclose(file);

    // Print playlists for all users
    for (i = 0; i < K; i++)
    {
        printf("User %d's Playlist:\n", i + 1);
        printPlaylist(users[i].playlist_head);
    }

    // DoubleNode *song;
    // song = moveSteps(users[0].playlist_head, 2);

    // printf("%s %d", song->song.name, song->song.duration);

    DoubleNode *listened_song_current;
    Node *listened_songs_head = NULL;
    for (i = 0; i < K; i++) // users listens music
    {
        printf("User %d is listening to songs.\n", i + 1);
        printf("User %d's playlist length: %d\n", i + 1, users[i].playlist_length);
        rnd_max = users[i].playlist_length;
        rnd_min = users[i].playlist_length / 2;

        int song_count = rnd_min + rand() % (rnd_max - rnd_min + 1);
        // printf("rnd_max = %d, rnd_min = %d\n", rnd_max, rnd_min);
        // printf("Random song count to listen: %d\n", song_count);

        rnd_max = users[i].playlist_length / 2;
        rnd_min = (users[i].playlist_length / 2) * -1;

        // printf("rnd_max = %d, rnd_min = %d\n", rnd_max, rnd_min);
        // printf("Random song count to listen: %d\n", song_count);

        listened_song_current = users[i].playlist_head;

        for (j = 0; j < song_count; j++)
        {
            int r = rnd_min + rand() % (rnd_max - rnd_min + 1);
            listened_song_current = moveSteps(listened_song_current, r);
            appendNormal(&users[i].listened_head, listened_song_current->song);
            appendNormal(&listened_songs_head, listened_song_current->song);
        }
    }

    // Print listened songs for all users
    for (i = 0; i < K; i++)
    {
        printf("User %d's Listened Songs:\n", i + 1);
        printNormalList(users[i].listened_head);
    }

    // Print all listened songs
    printf("All Listened Songs:\n");
    printNormalList(listened_songs_head);

    makeTopxList(songs, listened_songs_head, arr, TOP, N);

    return 0;
}

DoubleNode *createNode(Song song)
{
    DoubleNode *newNode = (DoubleNode *)malloc(sizeof(DoubleNode));
    newNode->song = song;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void append(DoubleNode **head, Song song)
{
    DoubleNode *newNode = createNode(song);

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    DoubleNode *tail = (*head)->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = *head;
    (*head)->prev = newNode;
}

// Function to print the playlist of a user
void printPlaylist(DoubleNode *head)
{
    if (head == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    DoubleNode *current = head;
    do
    {
        printf("Song: Name = %s, Duration = %d seconds\n", current->song.name, current->song.duration);
        current = current->next;
    } while (current != head);
}

DoubleNode *moveSteps(DoubleNode *start, int steps)
{
    if (start == NULL)
        return NULL;

    DoubleNode *current = start;

    if (steps >= 0)
    {
        for (int i = 0; i < steps; i++)
            current = current->next;
    }
    else
    {
        for (int i = 0; i < -steps; i++)
            current = current->prev;
    }

    return current;
}

Node *createNormalNode(Song song)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->song = song;
    newNode->next = NULL;
    return newNode;
}

void appendNormal(Node **head, Song song)
{
    Node *newNode = createNormalNode(song);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

void printNormalList(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        printf("Song: Name = %s, Duration = %d seconds\n", current->song.name, current->song.duration);
        current = current->next;
    }
}

int search_in_llist(Song song, Node *list_head)
{
    int count = 0;
    Node *current = list_head;

    while (current != NULL)
    {
        if (strcmp(current->song.name, song.name) == 0)
        {
            count++;
        }
        current = current->next;
    }

    return count;
}

void makeTopxList(Song *songs, Node *listened_songs_head, Song_Info *song_info_arr, int top_x, int N)
{
    int song_ctr, i, j;
    for (i = 0; i < N; i++)
    {
        song_ctr = search_in_llist(songs[i], listened_songs_head);
        strcpy(song_info_arr[i].name, songs[i].name);
        song_info_arr[i].duration = songs[i].duration * song_ctr;
        song_info_arr[i].listen_ctr = song_ctr;
    }

    // Sort songs by liten count
    for (i = 0; i < N - 1; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (song_info_arr[i].listen_ctr < song_info_arr[j].listen_ctr)
            {
                Song_Info temp = song_info_arr[i];
                song_info_arr[i] = song_info_arr[j];
                song_info_arr[j] = temp;
            }
        }
    }

    // print sorted songs
    printf("\nTop %d Songs:\n", top_x);
    for (i = 0; i < top_x; i++)
    {
        printf("Name: %s, Duration: %d seconds, Listen Count: %d\n",
               song_info_arr[i].name, song_info_arr[i].duration, song_info_arr[i].listen_ctr);
    }
}