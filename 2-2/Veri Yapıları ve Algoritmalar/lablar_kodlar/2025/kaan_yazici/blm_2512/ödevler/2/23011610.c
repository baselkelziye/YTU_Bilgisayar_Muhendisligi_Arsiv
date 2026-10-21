#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "input.txt"

typedef struct song_s {
  size_t name;
  size_t length;
} song;

typedef struct list_node_s {
  song *data;
  struct list_node_s *prev;
  struct list_node_s *next;
} listNode;

typedef struct list_s {
  listNode *head;
  listNode *tail;
} list;

typedef struct playlist_s {
  size_t size;
  list *songs;
  size_t listeningListCount;
  int *listeningList;
} playlist;

typedef struct {
  size_t N;
  size_t K;
} data;

list *createList();
void listPushBack(list *, song *);
song **createSongs(size_t);
playlist **createUsers(size_t, size_t, song **);
playlist *createPlaylist(size_t, song **);
void displayTop10(playlist **, int **, size_t);
int **playSongs(playlist **, size_t);
data *readInput(char*);
size_t computeListenedSongCount(int*, size_t);

int main() {
  srand(time(NULL));

  /** Read `N` and `K` values through input file. */
  data *data = readInput(FILE_NAME);
  size_t N = data->N;
  size_t K = data->K;

  song **songs = createSongs(N);
  playlist **users = createUsers(K, N, songs);
  int **userPlaytimes = playSongs(users, K);
  displayTop10(users, userPlaytimes, K);

  free(userPlaytimes);
  free(users);
  free(songs);
  free(data);
  return 0;
}

/**
 * @brief Computes total playtime for each song in their playlist by traversing their playlist
 * with respect to their listening list for each user.
 * 
 * @param users Array that holds the playlists for each user.
 * @param K Total user count.
 *
 * @return Array that holds every single song's total playtime in their playlist for each user.
 */
int **playSongs(playlist **users, size_t K) {
  size_t i = 0;
  int **userPlaytimes = calloc(K, sizeof(*userPlaytimes));

  for (; i < K; ++i) {
    userPlaytimes[i] = calloc(users[i]->size, sizeof(**userPlaytimes));
    listNode *node = users[i]->songs->head;

    size_t j;

    /** Variable to hold song index to be updated */
    int currentIdx = 0;
    for (j = 0; j < users[i]->listeningListCount; ++j) {
      int shiftAmount = users[i]->listeningList[j];

      /** If `listeningList` value is positive, traverse right for that amount, traverse left if not. */
      if (shiftAmount >= 0) {
        while (shiftAmount-- > 0) {
          node = node->next;
          currentIdx = (currentIdx + 1) % users[i]->size;
        }
      } else {
        while (shiftAmount++ < 0) {
          node = node->prev;
          currentIdx = (currentIdx - 1 + users[i]->size) % users[i]->size;
        }
      }

      /** Update user's song at `currentIdx` with the song's length. */
      userPlaytimes[i][currentIdx] += node->data->length;
    }
  }
  return userPlaytimes;
}

/**
 * @brief Displays top 10 songs for all users.
 *
 * For each user, linearly searches the song with the most playtime. After finding, it marks it's
 * playtime `-1` to find the remaining top 9, does this 10 times and gets the top 10 songs with their
 * playtimes. If there are less than 10 songs listened, only that amount is displayed.
 *
 * @param users Users array to compute their top 10 songs.
 * @param userPlaytimes Array that holds every person's total playtime for each song.
 * @param K Total number of users.
 */
void displayTop10(playlist **users, int **userPlaytimes, size_t K) {
  size_t i = 0;
  for (; i < K; ++i) {
    size_t j = 0;

    listNode *node = users[i]->songs->head;
    fprintf(stdout, "User #%llu's playlist: [ ", i+1);
    for (; j < users[i]->size; ++j) {
      fprintf(stdout, "S%llu(%llumins) ", node->data->name, node->data->length);
      node = node->next;
    }
    fputs("]\n", stdout);

    fprintf(stdout, "User #%llu's listening list: [ ", i+1);
    for (j = 0; j < users[i]->listeningListCount; ++j) {
      fprintf(stdout, "%d ", users[i]->listeningList[j]);
    }
    fputs("]\n\n", stdout);

    size_t k = 0;

    /** No need to show 10 songs if there are not 10 different songs listened. */
    size_t repeat = computeListenedSongCount(userPlaytimes[i], users[i]->size);
    for (; k < repeat; ++k) {
      int maxPlaytime = -1;
      size_t maxPlayedSongId = 0;
      size_t j = 0;
      for (; j < users[i]->size; ++j) {
        if (userPlaytimes[i][j] > maxPlaytime) {
          maxPlaytime = userPlaytimes[i][j];
          maxPlayedSongId = j;
        }
      }

      /** Traverse to the most played songs to get it's name. */
      listNode *node = users[i]->songs->head;
      int shiftAmount = maxPlayedSongId;
      while (shiftAmount-- > 0) {
        node = node->next;
      }
      fprintf(stdout, "Top #%llu song: %llu with playtime %d\n", k + 1, node->data->name, userPlaytimes[i][maxPlayedSongId]);
      userPlaytimes[i][maxPlayedSongId] = -1;
    }
    fputs("===========================================================\n", stdout);
  }
}

/**
 * @brief Creates a playlist for a single user.
 *
 * The playlist length is determined by randomizing in a range [1, 15% of total songs]. Then a listening
 * list for a user is also initialized. Random songs from `songs` array are chosen and distinct songs are
 * added to the person's playlist. Finally listening list is generated by choosing the first songs as a
 * completely random song inside the playlist, then next songs are chosen randomly in a range [-Mx/2, Mx/2]
 * meaning songs can at most jump half a playlist length.
 *
 * @param N Total number of songs.
 * @param songs Songs array to choose songs from.
 *
 * @return Newly created playlist array for a user.
 */
playlist *createPlaylist(size_t N, song **songs) {
  /* Max playlist size is 15% of total song count */
  size_t Mx = 1 + rand() % ((size_t)(N * 0.15) + 1);

  size_t listeningListCount = 1 + rand() % Mx;
  int *listeningList = calloc(listeningListCount, sizeof(*listeningList));

  playlist *playlist = malloc(sizeof(*playlist));
  playlist->size = Mx;
  playlist->songs = createList();
  playlist->listeningListCount = listeningListCount;

  /** Helper array to add only distinct songs to a playlist. */
  size_t *used = calloc(N, sizeof(*used));
  size_t count = 0;
  while (count != Mx) {
    size_t song = rand() % N;
    if (!used[song]) {
      listPushBack(playlist->songs, songs[song]);
      used[song] = 1;
      count++;
    }
  }

  /** First listened song is completely random in the playlist, rest can't jump more than half of playlist. */
  listeningList[0] = rand() % Mx;
  size_t i = 1;
  for (; i < listeningListCount; ++i) {
    listeningList[i] = (rand() % Mx) - Mx / 2;
  }
  playlist->listeningList = listeningList;

  free(used);
  return playlist;
}

/**
 * @brief Creates `K` users with each having a playlist for themselves.
 *
 * @param K Total user count.
 * @param N Total song count.
 * @param songs Songs array to create playlists with.
 *
 * @return Newly created users array.
 */
playlist **createUsers(size_t K, size_t N, song **songs) {
  playlist **users = malloc(K * sizeof(*users));
  size_t i = 0;
  for (; i < K; ++i) {
    users[i] = createPlaylist(N, songs);
  }

  return users;
}

/**
 * @brief Creates `N` songs with randomized length and names that are indexes.
 *
 * @param N Number of total songs available.
 *
 * @return Newly created array that holds struct `song` in each index.
 */
song **createSongs(size_t N) {
  song **songs = malloc(N * sizeof(*songs));
  size_t i = 0;
  for (; i < N; ++i) {
    songs[i] = malloc(sizeof(song));

    /* Song names 0, 1, 2, ..., N-1 */
    songs[i]->name = i;

    /* Song length between 3-10 */
    songs[i]->length = 3 + rand() % 8;
  }

  return songs;
}

/**
 * @brief Computes how many different songs are played for a given user for displaying top 10.
 * 
 * @param userPlaytime Total playing times for each song for a given user.
 * @param playlistSize The length of playlist array for a given user.
 * 
 * @return If listened song count is lesser than 10, that number is returned, if not, 10 is returned
 * for computing top 10. 
 */
size_t computeListenedSongCount(int* userPlaytime, size_t playlistSize) {
  size_t listenedSongCount = 0;
  
  size_t i = 0;
  for (; i < playlistSize; ++i) {
    if (userPlaytime[i]) {
      ++listenedSongCount;
    }
  }

  return (listenedSongCount < 10) ? listenedSongCount : 10;
}

/**
 * @brief Instantiates a doubly linked list that holds nodes of type struct `song`.
 *
 * @return Pointer to created empty list.
 */
list *createList() {
  list *list = malloc(sizeof(*list));
  list->head = NULL;
  list->tail = NULL;

  return list;
}
/**
 * @brief Pushes a `song` node into a list's back while maintaining correct doubly
 * linked list properties.
 *
 * @param list: Doubly linked list to be pushed into.
 * @param newSong: Node of type struct `song`.
 */
void listPushBack(list *list, song *newSong) {
  listNode *node = malloc(sizeof(*node));
  node->data = newSong;
  node->prev = NULL;
  node->next = NULL;

  if (!list->head || !list->tail) {
    list->head = node;
    list->tail = node;
    node->prev = list->tail;
    node->next = list->head;
  } else {
    node->prev = list->tail;
    node->next = list->head;
    list->tail->next = node;
    list->head->prev = node;
    list->tail = node;
  }
}

/**
 * @brief Reads `N` and `K` values from an input file.
 * 
 * @param fileName Name of the file to be read.
 * 
 * @return Pointer to the struct that holds the read data.
 */
data *readInput(char* fileName) {
  FILE *file;
  fopen_s(&file, fileName, "r");

  data *data = malloc(sizeof(*data));

  fscanf(file, "%llu %llu", &data->N, &data->K);

  fclose(file);

  return data;
}
