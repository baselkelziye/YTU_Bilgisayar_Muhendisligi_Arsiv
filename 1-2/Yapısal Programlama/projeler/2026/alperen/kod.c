/***************************************************************/
/*                           INCLUDES                          */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>
#include <math.h>
#include <limits.h>


/***************************************************************/
/*                         DEFINITIONS                         */
/***************************************************************/

#define bool   int
#define true   (1)
#define false  (0)

#define VERBOSE_LEVEL (1)

#define SAVE_GAMESTATE_IN_AUTO_MODE (1)  /* making this 1, may reduce your disk health and slowing down algorithm speed drastically */
                                         /* Its recommedended that making this value 0, or you may use ramdisk to speed up */

#define PRINT_MOVE_UNDO_IN_AUTO_MODE (1) /* making this 1, may slowing down algorithm speed drastically */
										 
#define FILENAME_LAST_GAME  "Last.dat"
#define FILENAME_SCORES     "Scores.csv"

#define LAST_HEADER_SIGNATURE_SIZE  (4)
#define LAST_HEADER_SIGNATURE   "AA!"

#define MATRIX_EMPTY_ELEMENT (0)

#define FILENAME_MAX_LENGTH (4096)

#define MATRIX_MIN_SIZE  (3)
#define MATRIX_MAX_SIZE  (10)
#define MATRIX_WARNING_THRESHOLD (8)

#define DIRECTION_COUNT  (4)
#define MAIN_MENU_COUNT (3)
#define GAME_MENU_COUNT (2)
#define INGAME_MENU_COUNT (2)

#define LENGTH_PLAYER_NAME (50)

#define INTEGER_ERROR (-1)
#define NOT_EXIST  (-1)
#define POSITION_NOT_SET (-1)

#define SCORE_CALCULATION_TOLERATE_UNDO (1)
#define SCORE_CALCULATION_TOLERATE_TIME (1)

#define SCORE_REWARD_MUL (100.0)
#define SCORE_UNDO_MUL (10.0)

#define SCORE_RANDOM_MUL  (2.0)
#define SCORE_FIlE_MUL    (1.0)
#define SCORE_AUTO_MUL    (0.5)
#define SCORE_MAUNAL_MUL  (1.0)

#define SCORE_READ_BUFFER_LEN  (64)

/***************************************************************/
/*                            MACROS                           */
/***************************************************************/


#define CHECK_PARAMETERS(condition, action)              \
do                                                       \
{                                                        \
	bool conditionStatus = (condition);                  \
	assert(!(conditionStatus));                          \
	if((conditionStatus))                                \
	{                                                    \
		fprintf(stderr, "Parameters are invalid\n");     \
		action;                                          \
	}                                                    \
}while(0)

#define CHECK_OPERATION(operation, action)            \
do                                                    \
{                                                     \
	bool operationStatus = (bool)!!(operation);       \
	assert((operationStatus));                        \
	if((operationStatus) == false)                    \
	{                                                 \
		fprintf(stderr, "Operation are failed\n");    \
		action;                                       \
	}                                                 \
}while(0)

#define CHECK_ALLOCATION(ptr, action)                    \
do                                                       \
{                                                        \
	void *localPtr = (void*)ptr;                         \
	assert((localPtr));                                  \
	if((localPtr) == NULL)                               \
	{                                                    \
		perror("Allocation error");                      \
		action;                                          \
	}                                                    \
}while(0)

#define CHECK_MATRIX(mat, action)                        \
do                                                       \
{                                                        \
	bool isNotValid = ((mat) == NULL) ||                 \
		(((mat)->N == 0) ^ ((mat)->data == NULL)) ||     \
		((mat)->N < 0);                                  \
	assert(!isNotValid);                                 \
	if(isNotValid)                                       \
	{                                                    \
		fprintf(stderr, "Matrix is invalid\n");          \
		action;                                          \
	}                                                    \
}while(0)

#define CHECK_POSLIST(plst, action)                      \
do                                                       \
{                                                        \
	bool isNotValid = ((plst) == NULL) ||                \
		(((plst)->N == 0) ^ ((plst)->pos == NULL)) ||    \
		((plst)->N < 0);                                 \
	assert(!isNotValid);                                 \
	if(isNotValid)                                       \
	{                                                    \
		fprintf(stderr, "PosList is invalid\n");         \
		action;                                          \
	}                                                    \
}while(0)

#define CHECK_GAMESTATE(g, action)                               \
do                                                               \
{                                                                \
	bool isNotValid = ((g) == NULL) ||                           \
		(((g)->matrixCount == 0) ^ ((g)->mat == NULL)) ||        \
		((g)->matrixCount < 0) ||                                \
		((g)->matrixSize < 0);                                   \
	assert(!isNotValid);                                         \
	if(isNotValid)                                               \
	{                                                            \
		fprintf(stderr, "GameState is invalid\n");               \
		action;                                                  \
	}                                                            \
}while(0)

#define CHECK_LASTHEADER(l, action)                                                    \
do                                                                                     \
{                                                                                      \
	bool isNotValid = ((l) == NULL) ||                                                 \
		strncmp((l)->signature, LAST_HEADER_SIGNATURE, LAST_HEADER_SIGNATURE_SIZE) ||  \
		((l)->matrixCount < 0) ||                                                      \
		((l)->matrixSize < 0);                                                         \
	assert(!isNotValid);                                                               \
	if(isNotValid)                                                                     \
	{                                                                                  \
		fprintf(stderr, "LastHeader is invalid\n");                                    \
		action;                                                                        \
	}                                                                                  \
}while(0)

#define CHECK_SCORELIST(slst, action)                    \
do                                                       \
{                                                        \
	bool isNotValid = ((slst) == NULL) ||                \
		(((slst)->N == 0) ^ ((slst)->head == NULL));     \
	assert(!isNotValid);                                 \
	if(isNotValid)                                       \
	{                                                    \
		fprintf(stderr, "ScoreList is invalid\n");       \
		action;                                          \
	}                                                    \
}while(0)

#define CHECK_LISTOFLISTS(lst, action)            \
do                                                \
{                                                 \
	CHECK_GAMESTATE(&(lst)->g, action);           \
	CHECK_SCORELIST(&(lst)->slst, action);        \
}while(0)


#define NEXT_POSITION(index, newPos, oldPos)                           \
do                                                                     \
{                                                                      \
	if(index == 0) position_left(newPos, oldPos);                      \
	else if(index == 1) position_right(newPos, oldPos);                \
	else if(index == 2) position_above(newPos, oldPos);                \
	else if(index == 3) position_bellow(newPos, oldPos);               \
	else fprintf(stderr, "Not valid index in NEXT_POSITION macro\n");  \
}while(0)


#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))


/***************************************************************/
/*                       DATA STRUCTURES                       */
/***************************************************************/

typedef char *String;

typedef enum MainMenuOperations
{
	MAIN_MENU_RANDOM,
	MAIN_MENU_FILE,
	MAIN_MENU_SCORES,
	MAIN_MENU_EXIT
}MainMenuOperations;

typedef enum GameMenuOperations
{
	GAME_MENU_AUTOMATIC,
	GAME_MENU_MAUNAL,
	GAME_MENU_RETURN
}GameMenuOperations;

typedef enum InGameMenuOperations
{
	INGAME_MENU_UNDO,
	INGAME_MENU_MOVE,
	INGAME_MENU_RESIGN
}InGameMenuOperations;

typedef struct Position
{
	int X, Y;
}Position;

typedef struct PosList
{
	Position *pos;  /* positions array */
	int N;          /* element count */
}PosList;

typedef struct Matrix
{
	int **data;
	int N;
}Matrix;

typedef struct GameState
{
	Matrix *mat;     /* using as a stack */
	int matrixCount;
	
	int matrixSize;  /* N */
	
	unsigned long totalTime;      /* second */
	
	unsigned long undoCount;
	
	MainMenuOperations mainMenuOperations;
	
	GameMenuOperations gameMenuOperations;
	
	char playerName[LENGTH_PLAYER_NAME];
	
}GameState;

typedef struct LastHeader
{
	char signature[LAST_HEADER_SIGNATURE_SIZE];
	int matrixCount;
	int matrixSize;
	unsigned long totalTime;
	unsigned long undoCount;
	MainMenuOperations mainMenuOperations;
	GameMenuOperations gameMenuOperations;
	char playerName[LENGTH_PLAYER_NAME];
	
	/* datas start followed by header */	
}LastHeader;

typedef struct Score
{
	char playerName[LENGTH_PLAYER_NAME];
	double score;
	struct Score *next;
}Score;

typedef struct ScoreList
{
	Score *head;
	int N;
}ScoreList;

typedef struct ListOfLists
{
	GameState g;
	ScoreList slst;
}ListOfLists;


/***************************************************************/
/*                     FUNCTION PROTOTYPES                     */
/***************************************************************/

int random_number(int min, int max);

bool position_is_in_range(Position pos, int N);
bool position_is_aligned(Position pos1, Position pos2);
bool position_is_same(Position pos1, Position pos2);
bool position_left(Position *newPos, const Position *oldPos);
bool position_right(Position *newPos, const Position *oldPos);
bool position_above(Position *newPos, const Position *oldPos);
bool position_bellow(Position *newPos, const Position *oldPos);

bool poslist_init(PosList *plst, int N);
bool poslist_deinit(PosList *plst);
bool poslist_clear(PosList *plst);

bool matrix_init(Matrix *mat, int N);
bool matrix_deinit(Matrix *mat);
bool matrix_clear(Matrix *mat);
bool matrix_duplicate(const Matrix *src, Matrix *dest);
bool matrix_is_full(const Matrix *mat);
bool matrix_has_dead_end(const Matrix *mat, const PosList *currPosLst, const PosList *endPosLst);
bool matrix_print(const Matrix *mat);
bool matrix_recursive_generator(Matrix *mat, Position *pos, int elementLimit, int elementCount);
bool matrix_generator(const int N, Matrix *mat, PosList *startPosLst, PosList *endPosLst);
int matrix_neighboor_number_count(const Matrix *mat, Matrix *hasChecked, const Position currPos);
bool matrix_is_solved(const Matrix *mat, const PosList *currPosLst, const PosList *endPosLst);
bool matrix_clean_except_poslists(Matrix *mat, const PosList *startPosLst, const PosList *endPosLst);
bool matrix_to_poslist(const Matrix *mat, PosList *startPosLst, PosList *endPosLst);
bool matrix_data_file_write(const Matrix *mat, FILE *fh);
bool matrix_data_file_read(Matrix *mat, int N, FILE *fh);
bool matrix_file_read(Matrix *mat, FILE *fh);

bool gamestate_recursive_solver(GameState *g, PosList *currPosLst, const PosList *endPosLst, int varIndex);
bool gamestate_solver(GameState *g);
bool gamestate_to_lastheader(const GameState *g, LastHeader *l);
bool gamestate_from_lastheader(GameState *g, const LastHeader *l);
bool gamestate_init(GameState *g);
bool gamestate_deinit(GameState *g);
bool gamestate_push_matrix(GameState *g, Matrix *mat);
bool gamestate_pop_matrix(GameState *g);
bool gamestate_top_matrix(const GameState *g, Matrix **mat);
bool gamestate_file_write(const GameState *g);
bool gamestate_file_read(GameState *g);
bool gamestate_file_push(const GameState *g);
bool gamestate_file_pop(const GameState *g);

Score *score_create(char *playerName, double score);
bool score_delete(Score *s);
bool score_insert(Score *target, Score *source);
bool score_file_write(const Score *s, FILE *fh);
bool score_file_read(Score *s, FILE *fh);
bool score_print(const Score *s);

bool scorelist_init(ScoreList *slst);
bool scorelist_deinit(ScoreList *slst);
bool scorelist_add_in_order(ScoreList *slst, Score *s);
int scorelist_game_count_of_player(const ScoreList *slst, const char *name);
bool scorelist_file_write(const ScoreList *slst);
bool scorelist_file_read(ScoreList *slst);
bool scorelist_print(const ScoreList *slst);

void main_menu_print(void);
MainMenuOperations main_menu_get_operation(void);
bool main_menu_random(void);
bool main_menu_file(void);
bool main_menu_score(void);

double lol_calculate_score(ListOfLists *lst);

void game_menu_print(void);
GameMenuOperations game_menu_get_operation(void);
bool game_menu_automatic(ListOfLists *lst);
bool game_menu_manual(ListOfLists *lst);

void ingame_menu_print(void);
InGameMenuOperations ingame_menu_get_operation(void);
bool ingame_menu_undo(ListOfLists *lst);
bool ingame_menu_move(ListOfLists *lst);


void clear_stdin(void);
Position get_position_input(int minX, int minY, int maxX, int maxY, const char *msgFormat, ...);
FILE *get_file_input(const char *fileMode, const char *msgFormat, ...);
int get_integer_input(int min, int max, const char *msgFormat, ...);
char *get_string_input(char *buffer, int maxLength, const char *msgFormat, ...);



/***************************************************************/
/*                       RANDOM FUNCTIONS                      */
/***************************************************************/

/* Input: int min, max.    Output: int random number */
/* return random number range between min and max */
int random_number(int min, int max)
{
	return min + (rand() % (max + 1 - min) );
}


/***************************************************************/
/*                     POSITION FUNCTIONS                      */
/***************************************************************/

/* Input: Position *pos, int minX, minY, maxX, maxY.    Output: bool is in range or not */
/* check position with N, return true if in range, false otherwise */
bool position_is_in_range(Position pos, int N)
{
	if(	pos.X >= 0 &&
		pos.X < N && 
		pos.Y >= 0 &&
		pos.Y < N
	)
	{
		return true;
	}
	return false;
}

/* Input: Position pos1, pos2.    Output: bool is aligned or not */
/* return true if positions in same row OR column, false otherwise */
bool position_is_aligned(Position pos1, Position pos2)
{
	return pos1.X == pos2.X || pos1.Y == pos2.Y;
}

/* Input: Position pos1, pos2.    Output: bool is same or not */
/* return true if positions in same row AND column, false otherwise */
bool position_is_same(Position pos1, Position pos2)
{
	return pos1.X == pos2.X && pos1.Y == pos2.Y;
}

/* Input: Position *newPos, oldPos.    Output: bool (success/fail), Position *newPos */
/* Fill newPos with oldPos'es left position. return true if succeed, false otherwise */
bool position_left(Position *newPos, const Position *oldPos)
{
	CHECK_PARAMETERS(newPos == NULL || oldPos == NULL, return false);
	newPos->X = oldPos->X-1, newPos->Y = oldPos->Y;
	return true;
}

/* Input: Position *newPos, oldPos.    Output: bool (success/fail), Position *newPos */
/* Fill newPos with oldPos'es right position. return true if succeed, false otherwise */
bool position_right(Position *newPos, const Position *oldPos)
{
	CHECK_PARAMETERS(newPos == NULL || oldPos == NULL, return false);
	newPos->X = oldPos->X+1, newPos->Y = oldPos->Y;
	return true;
}

/* Input: Position *newPos, oldPos.    Output: bool (success/fail), Position *newPos */
/* Fill newPos with oldPos'es above position. return true if succeed, false otherwise */
bool position_above(Position *newPos, const Position *oldPos)
{
	CHECK_PARAMETERS(newPos == NULL || oldPos == NULL, return false);
	newPos->X = oldPos->X, newPos->Y = oldPos->Y-1;
	return true;
}

/* Input: Position *newPos, oldPos.    Output: bool (success/fail), Position *newPos */
/* Fill newPos with oldPos'es bellow position. return true if succeed, false otherwise */
bool position_bellow(Position *newPos, const Position *oldPos)
{
	CHECK_PARAMETERS(newPos == NULL || oldPos == NULL, return false);
	newPos->X = oldPos->X, newPos->Y = oldPos->Y+1;
	return true;
}


/***************************************************************/
/*                      POSLIST FUNCTIONS                      */
/***************************************************************/

/* Input: Position *plst, int N.    Output: bool (success/fail), PosList *plst */
/* initialize poslist with N position. return true if succeed, false otherwise */
bool poslist_init(PosList *plst, int N)
{
	Position *pos = NULL;
	
	CHECK_PARAMETERS(plst == NULL, return false);
	CHECK_PARAMETERS(N <= 0, return false);
	
	pos = (Position*)calloc(N, sizeof(Position));
	CHECK_ALLOCATION(pos, return false);
	
	plst->pos = pos;
	plst->N = N;
	
	return true;
}

/* Input: Position *plst.    Output: bool (success/fail) */
/* deinitialize poslist and free up memory. return true if succeed, false otherwise */
bool poslist_deinit(PosList *plst)
{
	CHECK_POSLIST(plst, return false);
	
	if(plst->pos != NULL)
	{
		free(plst->pos);
	}
	
	plst->N = 0;
	plst->pos = NULL;
	
	return true;
}

/* Input: Position *plst.    Output: bool (success/fail) */
/* clear all positions in poslist, return true if succeed, false otherwise  */
bool poslist_clear(PosList *plst)
{
	int i = 0;
	
	CHECK_POSLIST(plst, return false);
	
	if(plst->pos == NULL) /* no data */
	{
		return true;
	}
	
	for(i = 0; i < plst->N; i++)
	{
		plst->pos[i].X = POSITION_NOT_SET;
		plst->pos[i].Y = POSITION_NOT_SET;
	}
	
	return true;
}


/***************************************************************/
/*                       MATRIX FUNCTIONS                      */
/***************************************************************/

/* Input: Matrix *mat, int N.    Output: bool (success/fail), Matrix *mat */
/* initialize matrix with NxN size. return false if failed, true otherwise */
bool matrix_init(Matrix *mat, int N)
{
	int i = 0;
	int **data = NULL;
	
	CHECK_PARAMETERS(mat == NULL, return false);
	CHECK_PARAMETERS(N <= 0, return false);
	
	data = (int**)malloc(N * sizeof(int*));
	CHECK_ALLOCATION(data, return false);
	
	for(i = 0; i < N; i++)
	{
		data[i] = (int*)malloc(N * sizeof(int));
		CHECK_ALLOCATION(data[i], {int j = 0; for(j = 0; j < i; j++){ free(data[j]); } free(data);} return false);
		memset(data[i], MATRIX_EMPTY_ELEMENT, N * sizeof(int));
	}
	
	mat->data = data;
	mat->N = N;
	
	return true;
}

/* Input: Matrix *mat.    Output: bool (success/fail) */
/* deinitialize matrix and free up memory. return true if succeed, false otherwise */
bool matrix_deinit(Matrix *mat)
{
	int i = 0;
	
	CHECK_MATRIX(mat, return false);
	
	if(mat->data != NULL)
	{
		for(i = 0; i < mat->N; i++)
		{
			free(mat->data[i]);
		}
		free(mat->data);
	}
	
	mat->N = 0;
	mat->data = NULL;
	
	return true;
}

/* Input: Matrix *mat.    Output: bool (success/fail) */
/* set all elements as MATRIX_EMPTY_ELEMENT, return false if failed, true otherwise */
bool matrix_clear(Matrix *mat)
{
	int i = 0, j = 0;
	
	CHECK_MATRIX(mat, return false);
	
	for(i = 0; i < mat->N; i++)
	{
		for(j = 0; j < mat->N; j++)
		{
			mat->data[i][j] = MATRIX_EMPTY_ELEMENT;
		}
	}
	
	return true;
}

/* Input: Matrix *src, *dest.    Output: bool (success/fail), Matrix *dest */
/* duplicate src matrix to dest. dest matrix must not be initialized. return true if succeed, false otherwise */
bool matrix_duplicate(const Matrix *src, Matrix *dest)
{
	int i = 0, j = 0;
	
	CHECK_MATRIX(src, return false);
	CHECK_PARAMETERS(dest == NULL, return false);
	
	CHECK_OPERATION(matrix_init(dest, src->N), return false);
	
	for(i = 0; i < src->N; i++)
	{
		for(j = 0; j < src->N; j++)
		{
			dest->data[i][j] = src->data[i][j];
		}
	}
	
	return true;
}

/* Input: Matrix *mat.    Output: bool is full or not */
/* return true if matrix full (no element is MATRIX_EMPTY_ELEMENT), false otherwise */
bool matrix_is_full(const Matrix *mat)
{
	int i = 0, j = 0;
	
	CHECK_MATRIX(mat, return false);
	
	for(i = 0; i < mat->N; i++)
	{
		for(j = 0; j < mat->N; j++)
		{
			if(mat->data[i][j] == MATRIX_EMPTY_ELEMENT)
			{
				return false;
			}
		}
	}
	return true;
}

/* Input: Matrix *mat, PosList *currPosLst, *endPosLst.    Output: bool has dead end or not */
/* Dead end: any of empty element have less than 2 empty or tail neighboor element */
/* currPosLst and endPosLst are tail positions. return true if matrix is dead end, false otherwise */
bool matrix_has_dead_end(const Matrix *mat, const PosList *currPosLst, const PosList *endPosLst)
{
	int i = 0, j = 0;
	
	CHECK_MATRIX(mat, return false);
	CHECK_POSLIST(currPosLst, return false);
	CHECK_POSLIST(endPosLst, return false);
	
	for(i = 0; i < mat->N; i++)
	{
		for(j = 0; j < mat->N; j++)
		{
			if(mat->data[i][j] == MATRIX_EMPTY_ELEMENT)
			{
				int k = 0;
				int EmptyOrTailCount = 0;
				Position oldPos = {0};
				Position newPos = {0};
				oldPos.X = j, oldPos.Y = i;
				for(k = 0; k < DIRECTION_COUNT; k++)
				{
					NEXT_POSITION(k, &newPos, &oldPos);
					if(position_is_in_range(newPos, mat->N))
					{
						if(mat->data[newPos.Y][newPos.X] == MATRIX_EMPTY_ELEMENT) /* empty */
						{
							EmptyOrTailCount++;
						}
						else if(currPosLst->pos[mat->data[newPos.Y][newPos.X]-1].X == newPos.X &&
							currPosLst->pos[mat->data[newPos.Y][newPos.X]-1].Y == newPos.Y)
						{
							EmptyOrTailCount++;
						}
						else if(endPosLst->pos[mat->data[newPos.Y][newPos.X]-1].X == newPos.X &&
							endPosLst->pos[mat->data[newPos.Y][newPos.X]-1].Y == newPos.Y)
						{
							EmptyOrTailCount++;
						}
					}
				}
				if(EmptyOrTailCount < 2)
				{
					return true;
				}
			}
		}
	}
	return false;
}

/* Input: Matrix *mat.    Output: bool (success/fail) */
/* print matrix table and elements except MATRIX_EMPTY_ELEMENT */
bool matrix_print(const Matrix *mat)
{
	int i = 0, j = 0;
	
	CHECK_MATRIX(mat, return false);
	
	printf("\n    |");
	for(i = 0; i < mat->N; i++)
	{
		printf("%2d|", i);
	}
	printf("\n");
	
	for(i = 0; i < 3*mat->N + 5; i++)
	{
		printf("-");
	}
	printf("\n");
	for(i = 0; i < 3*mat->N + 5; i++)
	{
		printf("-");
	}
	printf("\n");
	
	for(i = 0; i < mat->N; i++)
	{
		printf(" %2d||", i);
		for(j = 0; j < mat->N; j++)
		{
			if(mat->data[i][j] != MATRIX_EMPTY_ELEMENT)
			{
				printf("%2d|", mat->data[i][j]);
			}
			else
			{
				printf("  |");
			}
		}
		printf("\n");
		
		for(j = 0; j < 3*mat->N + 5; j++)
		{
			printf("-");
		}
		printf("\n");
	}
	
	return true;
}

/* Input: Matrix *mat, Position *pos, int elementLimit, elementCount.    Output: bool (success/fail), Matrix *mat */
/* internal function which used in matrix_generator */
bool matrix_recursive_generator(Matrix *mat, Position *pos, int elementLimit, int elementCount)
{
	int i = 0, w = 0;
	Position newPos = {0};
	PosList plst = {0};
	
	if(elementLimit == 0)
	{
		return true;
	}
	
	poslist_init(&plst, DIRECTION_COUNT);
	
	for(i = 0; i < DIRECTION_COUNT; i++)
	{
		NEXT_POSITION(i, &newPos, pos);
		if(position_is_in_range(newPos, mat->N) && mat->data[newPos.Y][newPos.X] == MATRIX_EMPTY_ELEMENT)
		{
			plst.pos[w++] = newPos;
		}
	}
	
	if(w == 0) /* there is no empty element */
	{
		if(elementCount <= 2) /* no matching element */
		{
			return false;
		}
		return true;
	}
	
	newPos = plst.pos[random_number(0, w-1)]; /* continue to random position */
	
	poslist_deinit(&plst);
	
	mat->data[newPos.Y][newPos.X] = mat->data[pos->Y][pos->X];
	
	*pos = newPos;
	
	return matrix_recursive_generator(mat, pos, elementLimit-1, elementCount+1);
	
}

/* Input: int N, Matrix *mat, PosList *startPosLst, *endPosLst.    Output: bool (success/fail), Matrix *mat */
/* parameters must not be initialized. return true if succeed, false otherwise */
bool matrix_generator(const int N, Matrix *mat, PosList *startPosLst, PosList *endPosLst)
{
	PosList emptyPosLst = {0};
	bool isMatrixFailed = false;
	
	CHECK_PARAMETERS(mat == NULL, return false);
	CHECK_PARAMETERS(startPosLst == NULL, return false);
	CHECK_PARAMETERS(endPosLst == NULL, return false);
	CHECK_PARAMETERS(N < 0, return false);
	
	if(N == 0)
	{
		return true;
	}
	
	CHECK_OPERATION(matrix_init(mat, N), return false);
	CHECK_OPERATION(poslist_init(startPosLst, N), matrix_deinit(mat); return false);
	CHECK_OPERATION(poslist_init(endPosLst, N), poslist_deinit(startPosLst); matrix_deinit(mat); return false);
	CHECK_OPERATION(poslist_init(&emptyPosLst, N * N), poslist_deinit(startPosLst); poslist_deinit(endPosLst); matrix_deinit(mat); return false);
	
	
	do
	{	
		int k = 0;
		
		
		poslist_clear(startPosLst);
		poslist_clear(endPosLst);
		matrix_clear(mat);
		
		isMatrixFailed = false;
		
		for(k = 0; k < N && isMatrixFailed == false; k++)
		{
			int emptyCount = 0, elementLimit = 0;
			int i = 0, j = 0;
			
			/*poslist_clear(&emptyPosLst);*/
			
			for(i = 0; i < N; i++)
			{
				for(j = 0; j < N; j++)
				{
					if(mat->data[i][j] == MATRIX_EMPTY_ELEMENT)
					{
						emptyPosLst.pos[emptyCount].X = j;
						emptyPosLst.pos[emptyCount].Y = i;
						emptyCount++;
					}
				}
			}
			
			if(emptyCount <= 2)  /* clear all data and retry */
			{
				isMatrixFailed = true;
			}
			else
			{
			
				startPosLst->pos[k] = emptyPosLst.pos[random_number(0, emptyCount-1)];
				endPosLst->pos[k] = startPosLst->pos[k]; /* initially, same as startPos */
				
				mat->data[startPosLst->pos[k].Y][startPosLst->pos[k].X] = k+1;
				
				elementLimit = (k == mat->N-1) ? mat->N*mat->N : random_number(3, mat->N*2); /* if last element, fill whole matrix, limit otherwise */
				
				isMatrixFailed = !matrix_recursive_generator(mat, &endPosLst->pos[k], elementLimit-1, 1);
			}
		}	
	}while(matrix_is_full(mat) == false || isMatrixFailed == true);
	
	poslist_deinit(&emptyPosLst);
	
	return true;
}

/* Input: Matrix *mat *hasChecked, Position currPos.    Output: int neighboor count, Matrix *hasChecked */
/* hasChecked: memory matrix, which contain an element whether checked or not */
/* return total count of same number which neighboor or currPos */
int matrix_neighboor_number_count(const Matrix *mat, Matrix *hasChecked, const Position currPos)
{
	int i = 0;
	Position nextPos = {0};
	int retCount = 0;
	
	hasChecked->data[currPos.Y][currPos.X] = true;
	
	for(i = 0; i < DIRECTION_COUNT; i++)
	{
		NEXT_POSITION(i, &nextPos, &currPos);
		if(position_is_in_range(nextPos, mat->N))
		{
			if(	mat->data[currPos.Y][currPos.X] == mat->data[nextPos.Y][nextPos.X] &&
				hasChecked->data[nextPos.Y][nextPos.X] == false
			)
			{
				retCount += matrix_neighboor_number_count(mat, hasChecked, nextPos);
			}
		}
	}
	
	return retCount+1;
}

/* Input: Matrix *mat PosList *currPosLst, *endPosLst.    Output: bool is solved or not */
/* currPosLst and endPosLst can be NULL. return true if matrix solved, false otheriwse */
bool matrix_is_solved(const Matrix *mat, const PosList *currPosLst, const PosList *endPosLst)
{
	Matrix hasChecked = {0};
	int i = 0, j = 0, k = 0;
	
	CHECK_MATRIX(mat, return false);
	if(mat->data == NULL)
	{
		return false;
	}
		
	if(matrix_is_full(mat) == false)
	{
		return false;
	}
		
	if(currPosLst != NULL && endPosLst != NULL)
	{
		CHECK_POSLIST(currPosLst, return false);
		CHECK_POSLIST(endPosLst, return false);
		CHECK_PARAMETERS(mat->N != currPosLst->N, return false);
		CHECK_PARAMETERS(mat->N != endPosLst->N, return false);
		
		for(k = 0; k < mat->N; k++)
		{
			if(currPosLst->pos[k].X != endPosLst->pos[k].X || currPosLst->pos[k].Y != endPosLst->pos[k].Y)
			{
				return false; /* last positions not equal to endPositions */
			}
		}
	}
	
	CHECK_OPERATION(matrix_init(&hasChecked, mat->N), return false);
	
	for(k = 1; k <= mat->N; k++)
	{
		Position firstPos = {POSITION_NOT_SET, POSITION_NOT_SET};
		int neighboorCount = 0, totalCount = 0;
		
		for(i = 0; i < mat->N; i++)
		{
			for(j = 0; j < mat->N; j++)
			{
				if(mat->data[i][j] == k)
				{
					if(totalCount == 0) /* first time */
					{
						firstPos.Y = i;
						firstPos.X = j;
					}
					
					totalCount++;
				}
			}
		}
		
		neighboorCount = matrix_neighboor_number_count(mat, &hasChecked, firstPos);
		
		if(totalCount != neighboorCount)
		{
			matrix_deinit(&hasChecked);
			return false;
		}
	}
	matrix_deinit(&hasChecked);
	
	return true;
}

/* Input: Matrix *mat PosList *currPosLst, *endPosLst.    Output: bool (success/fail), Matrix *mat */
/* clean all elements except startPosLst and endPosLst */
bool matrix_clean_except_poslists(Matrix *mat, const PosList *startPosLst, const PosList *endPosLst)
{
	int i = 0, j = 0;
	
	CHECK_MATRIX(mat, return false);
	CHECK_POSLIST(startPosLst, return false);
	CHECK_POSLIST(endPosLst, return false);
	CHECK_PARAMETERS(mat->N != startPosLst->N, return false);
	CHECK_PARAMETERS(mat->N != endPosLst->N, return false);
	
	#if (VERBOSE_LEVEL >= 2)
	for(i = 0; i < startPosLst->N; i++)
	{
		printf("startPosLst.pos[%d] = {%d, %d}\n", i, startPosLst->pos[i].X, startPosLst->pos[i].Y);
		printf("endPosLst.pos[%d] = {%d, %d}\n", i, endPosLst->pos[i].X, endPosLst->pos[i].Y);
	}
	printf("\n");
	#endif
	
	for(i = 0; i < mat->N; i++)
	{
		for(j = 0; j < mat->N; j++)
		{
			int index = mat->data[i][j]-1;
			if(	(index != MATRIX_EMPTY_ELEMENT-1) &&
				(startPosLst->pos[index].X != j || startPosLst->pos[index].Y != i) &&
				(endPosLst->pos[index].X != j || endPosLst->pos[index].Y != i)
			)
			{
				mat->data[i][j] = MATRIX_EMPTY_ELEMENT;
			}
		}
	}
	
	return true;
}

/* Input: Matrix *mat PosList *currPosLst, *endPosLst.    Output: bool (success/fail), PosList *startPosLst, *endPosLst */
/* PosLists must not be uninitialized, startPosLst filled with first seen positions, endPosLst filled with last seen positions. return true if succeed */
bool matrix_to_poslist(const Matrix *mat, PosList *startPosLst, PosList *endPosLst)
{
	int i = 0, j = 0;
	
	CHECK_MATRIX(mat, return false);
	CHECK_PARAMETERS(startPosLst == NULL, return false);
	CHECK_PARAMETERS(endPosLst == NULL, return false);
	
	CHECK_OPERATION(poslist_init(startPosLst, mat->N), return false);
	CHECK_OPERATION(poslist_init(endPosLst, mat->N), poslist_deinit(startPosLst); return false);
	
	for(i = 0; i < mat->N; i++)
	{
		startPosLst->pos[i].X = POSITION_NOT_SET, startPosLst->pos[i].Y = POSITION_NOT_SET; /* set as unseted */
		endPosLst->pos[i].X = POSITION_NOT_SET, endPosLst->pos[i].Y = POSITION_NOT_SET; /* set as unseted */
	}
	
	for(i = 0; i < mat->N; i++)
	{
		for(j = 0; j < mat->N; j++)
		{
			int index = mat->data[i][j]-1;
			if(index < 0 || index >= mat->N)
			{
				if(index != MATRIX_EMPTY_ELEMENT-1)
				{
					/* not valid element */
					fprintf(stderr, "%d is not vaild element\n", mat->data[i][j]);
					poslist_deinit(startPosLst);
					poslist_deinit(endPosLst);
					return false;
				}
			}
			else
			{
				if(startPosLst->pos[index].X == POSITION_NOT_SET && startPosLst->pos[index].Y == POSITION_NOT_SET) /* firt time to see this number */
				{
					startPosLst->pos[index].X = j, startPosLst->pos[index].Y = i;
				}
				else
				{
					endPosLst->pos[index].X = j, endPosLst->pos[index].Y = i;
				}
			}
		}
	}
	
	return true;	
}

/* Input: Matrix *mat FILE *fh.    Output: bool (success/fail), FILE *fh writeing to file */
/* write only data of matrix to given file */
bool matrix_data_file_write(const Matrix *mat, FILE *fh)
{
	int i = 0;
	
	CHECK_MATRIX(mat, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	for(i = 0; i < mat->N; i++)
	{
		fwrite(mat->data[i], sizeof(int), mat->N, fh);
	}
	
	return true;
}

/* Input: Matrix *mat FILE *fh.    Output: bool (success/fail), Matrix *mat, FILE *fh readeing from file */
/* read only data of matrix from given file */
bool matrix_data_file_read(Matrix *mat, int N, FILE *fh)
{
	int i = 0;
	
	CHECK_PARAMETERS(mat == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	for(i = 0; i < N; i++)
	{
		if(fread(mat->data[i], sizeof(int), N, fh) != (size_t)N)
		{
			matrix_clear(mat);
			return false;
		}
	}
	mat->N = N;
	
	return true;
}

/* Input: Matrix *mat FILE *fh.    Output: bool (success/fail), Matrix *mat, FILE *fh readeing from file */
/* read matrix from file for file reading game mode */
bool matrix_file_read(Matrix *mat, FILE *fh)
{
	Position pos = {0};
	int value = 0;
	int i = 0;
	
	CHECK_PARAMETERS(mat->data == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	rewind(fh);
	matrix_clear(mat);
	
	for(i = 0; i < mat->N * 2; i++)
	{
		bool isValid = true;
		if(fscanf(fh, "%d %d %d\n", &pos.Y, &pos.X, &value) != 3 && !feof(fh))
		{
			fprintf(stderr, "Reading from file failed: Not enought matrix data\n");
			isValid = false;
		}
		if(pos.Y < 0 || pos.Y >= mat->N || pos.X < 0 || pos.X >= mat->N)
		{
			fprintf(stderr, "Position (%d %d) is invalid\n", pos.Y, pos.X);
			isValid = false;
		}
		if(value < MATRIX_EMPTY_ELEMENT || value > mat->N)
		{
			fprintf(stderr, "Number %d is not in range [%d-%d]\n", value, 1, mat->N);
			isValid = false;
		}
		if(mat->data[pos.Y][pos.X] != MATRIX_EMPTY_ELEMENT)
		{
			fprintf(stderr, "Position (%d %d) already filled by %d\n", pos.Y, pos.X, mat->data[pos.Y][pos.X]);
			isValid = false;
		}
		
		if(isValid == false)
		{
			matrix_clear(mat);
			return false;
		}
		
		mat->data[pos.Y][pos.X] = (value == 0) ? MATRIX_EMPTY_ELEMENT : value; /* 0 is empty element in example files */
	}
	
	return true;
}

/***************************************************************/
/*                     GAMESTATE FUNCTIONS                     */
/***************************************************************/

/* Input: GameState *g, PosList *currPosLst, const PosList *endPosLst, int varIndex.    Output: bool (success/fail), GameState *g, PosList *currPosLst */
/* internal function for solver */
bool gamestate_recursive_solver(GameState *g, PosList *currPosLst, const PosList *endPosLst, int varIndex)
{
	int i = 0;
	Matrix *mat = &g->mat[g->matrixCount-1];
	
	/* parameter will not check because cost of check in every iteration is high */
			
	if(varIndex >= mat->N) /* finished */
	{
		return matrix_is_solved(mat, currPosLst, endPosLst); /* check is solved */
	}
	
	if(currPosLst->pos[varIndex].X == endPosLst->pos[varIndex].X && currPosLst->pos[varIndex].Y == endPosLst->pos[varIndex].Y)
	{
		return gamestate_recursive_solver(g, currPosLst, endPosLst, varIndex+1);
	}
	
	if(matrix_has_dead_end(mat, currPosLst, endPosLst) == true)
	{
		return false;
	}
	
	for(i = 0; i < DIRECTION_COUNT; i++)
	{
		Position oldPos = currPosLst->pos[varIndex];
		Position newPos = {0, 0};
		
		NEXT_POSITION(i, &newPos, &oldPos);
		
		if(position_is_in_range(newPos, mat->N))
		{
			if(	mat->data[newPos.Y][newPos.X] == MATRIX_EMPTY_ELEMENT ||
				(endPosLst->pos[varIndex].X == newPos.X &&
				endPosLst->pos[varIndex].Y == newPos.Y)
			)
			{
				int oldVal = mat->data[newPos.Y][newPos.X];
				currPosLst->pos[varIndex] = newPos;
				mat->data[newPos.Y][newPos.X] = varIndex+1;
				
				#if (SAVE_GAMESTATE_IN_AUTO_MODE == 1)
				gamestate_file_write(g);
				#endif
				
				#if (PRINT_MOVE_UNDO_IN_AUTO_MODE == 1)
				printf("moving number %d from (%d, %d) to (%d, %d)\n", varIndex+1, oldPos.Y, oldPos.X, newPos.Y, newPos.X);
				#endif
				
				if(gamestate_recursive_solver(g, currPosLst, endPosLst, varIndex) == true)
				{
					return true;
				}
				
				#if (PRINT_MOVE_UNDO_IN_AUTO_MODE == 1)
				printf("undoing %d from (%d, %d)\n", varIndex+1, newPos.Y, newPos.X);
				#endif
				
				
				g->undoCount++;
				
				currPosLst->pos[varIndex] = oldPos;
				mat->data[newPos.Y][newPos.X] = oldVal;
				
				#if (SAVE_GAMESTATE_IN_AUTO_MODE == 1)
				gamestate_file_write(g);
				#endif
				
			}
		}
	}
	
	return false;
}

/* Input: GameState *g.    Output: bool (success/fail), GameState *g */
/* solve given matrix (g->mat[g->matrixCount-1]) */
bool gamestate_solver(GameState *g)
{
	PosList startPosLst = {0}, endPosLst = {0};
	Matrix *mat = NULL;
	bool retVal = true;
	
	CHECK_GAMESTATE(g, return false);
	if(g->matrixCount == 0)
	{
		fprintf(stderr, "There is no matrix to solve\n");
		return false;
	}
	
	CHECK_OPERATION(gamestate_top_matrix(g, &mat), return false);	
	CHECK_OPERATION(poslist_init(&startPosLst, mat->N), return false);
	CHECK_OPERATION(poslist_init(&endPosLst, mat->N), poslist_deinit(&startPosLst); return false);
	
	if(matrix_to_poslist(mat, &startPosLst, &endPosLst) == false)
	{
		poslist_deinit(&startPosLst);
		poslist_deinit(&endPosLst);
		return false;
	}
	
	#if (VERBOSE_LEVEL >= 2)
		{int i = 0;
		for(i = 0; i < startPosLst.N; i++)
		{
			printf("startPosLst.pos[%d] = {%d, %d}\n", i, startPosLst.pos[i].X, startPosLst.pos[i].Y);
			printf("endPosLst.pos[%d] = {%d, %d}\n", i, endPosLst.pos[i].X, endPosLst.pos[i].Y);
		}
		printf("\n");}
	#endif
	
	retVal = gamestate_recursive_solver(g, &startPosLst, &endPosLst, 0);
	
	poslist_deinit(&startPosLst);
	poslist_deinit(&endPosLst);
	
	return retVal;
}

/* Input: GameState *g, LastHeader *l.    Output: bool (success/fail), LastHeader *l */
/* Fill LastHeader from given GameState, return true if succeed */
bool gamestate_to_lastheader(const GameState *g, LastHeader *l)
{
	CHECK_GAMESTATE(g, return false);
	CHECK_PARAMETERS(l == NULL, return false);
	
	strncpy(l->signature, LAST_HEADER_SIGNATURE, LAST_HEADER_SIGNATURE_SIZE);
	l->matrixCount = g->matrixCount;
	l->matrixSize = g->matrixSize;
	l->totalTime = g->totalTime;
	l->undoCount = g->undoCount;
	l->mainMenuOperations = g->mainMenuOperations;
	l->gameMenuOperations = g->gameMenuOperations;
	strncpy(l->playerName, g->playerName, LENGTH_PLAYER_NAME);	
	
	return true;
}

/* Input: GameState *g, LastHeader *l.    Output: bool (success/fail), GameState *g */
/* Fill GameState from given LastHeader, return true if succeed */
bool gamestate_from_lastheader(GameState *g, const LastHeader *l)
{
	CHECK_LASTHEADER(l, return false);
	CHECK_PARAMETERS(g == NULL, return false);
	
	CHECK_OPERATION(!strncmp(l->signature, LAST_HEADER_SIGNATURE, LAST_HEADER_SIGNATURE_SIZE), return false);
	
	g->matrixCount = l->matrixCount;
	g->matrixSize = l->matrixSize;
	g->totalTime = l->totalTime;
	g->undoCount = l->undoCount;
	g->mainMenuOperations = l->mainMenuOperations;
	g->gameMenuOperations = l->gameMenuOperations;
	strncpy(g->playerName, l->playerName, LENGTH_PLAYER_NAME);	
	
	return true;
}

/* Input: GameState *g.    Output: bool (success/fail), GameState *g */
/* initialize gamestate, matrix is numm and matrixCount is 0, return true if succeed, false otherwise */
bool gamestate_init(GameState *g)
{
	CHECK_PARAMETERS(g == NULL, return false);
	
	g->mat = NULL;
	g->matrixCount = 0;
	g->matrixSize = 0;
	g->totalTime = 0;
	g->undoCount = 0;
	g->mainMenuOperations = 0;
	g->gameMenuOperations = 0;
	memset(g->playerName, 0, sizeof(g->playerName));
	
	return true;
}

/* Input: GameState *g.    Output: bool (success/fail) */
/* deinitialize gamestate, delete matrixes and free up memory, return true if succeed, false otherwise */
bool gamestate_deinit(GameState *g)
{
	CHECK_GAMESTATE(g, return false);
	
	if(g->mat != NULL)
	{
		int i = 0;
		for(i = 0; i < g->matrixCount; i++)
		{
			matrix_deinit(&g->mat[i]);
		}
		free(g->mat);
	}
	memset(g, 0, sizeof(GameState));
	
	return true;
}

/* Input: GameState *g, Matrix *mat.    Output: bool (success/fail), GameState *g */
/* add new matrix to GameState, return true if succeed, false otherwise */
bool gamestate_push_matrix(GameState *g, Matrix *mat)
{
	Matrix *newPtr = NULL;
	
	CHECK_GAMESTATE(g, return false);
	CHECK_MATRIX(mat, return false);
	
	if(g->matrixCount == 0)
	{
		newPtr = (Matrix*)malloc(sizeof(Matrix));
	}
	else
	{
		newPtr = (Matrix*)realloc(g->mat, (g->matrixCount+1) * sizeof(Matrix));
	}
	
	CHECK_ALLOCATION(newPtr, return false);
	
	newPtr[g->matrixCount] = *mat;
	
	g->mat = newPtr;
	g->matrixCount++;
	
	return true;
}

/* Input: GameState *g.    Output: bool (success/fail), GameState *g */
/* remove last matrix from gamestate. return true if succeed */
bool gamestate_pop_matrix(GameState *g)
{
	Matrix *newPtr = NULL;
	
	CHECK_GAMESTATE(g, return false);
	
	if(g->matrixCount == 0)
	{
		return false;
	}
	
	CHECK_OPERATION(matrix_deinit(&g->mat[g->matrixCount-1]), return false);
	
	if(g->matrixCount == 1)
	{
		free(g->mat);
		newPtr = NULL;
	}
	else
	{
		newPtr = (Matrix*)realloc(g->mat, (g->matrixCount-1) * sizeof(Matrix));
		CHECK_ALLOCATION(newPtr, return false);
	}
	
	g->matrixCount--;
	g->mat = newPtr;
	
	return true;
}

/* Input: GameState *g, Matrix **mat.    Output: bool (success/fail), Matrix **mat */
/* parameter "mat" must not be initialized. return true if succeed */
bool gamestate_top_matrix(const GameState *g, Matrix **mat)
{
	CHECK_GAMESTATE(g, return false);
	CHECK_PARAMETERS(mat == NULL, return false);
	
	if(g->matrixCount == 0)
	{
		return false;
	}
	
	*mat = &g->mat[g->matrixCount-1];
	
	return true;
}

/* Input: GameState *g.    Output: bool (success/fail) */
/* write gamestate to Last.dat */
bool gamestate_file_write(const GameState *g)
{
	FILE *fh = NULL;
	int i = 0;
	LastHeader l = {0};
	
	CHECK_GAMESTATE(g, return false);
	
	CHECK_OPERATION(gamestate_to_lastheader(g, &l), return false);
	
	fh = fopen(FILENAME_LAST_GAME, "wb");
	CHECK_OPERATION(fh, return false);
	
	
	
	fwrite(&l, sizeof(LastHeader), 1, fh);
	
	for(i = 0; i < g->matrixCount; i++)
	{
		CHECK_OPERATION(matrix_data_file_write(&g->mat[i], fh), return false);
	}
	
	return !fclose(fh);
}

/* Input: GameState *g.    Output: bool (success/fail), GameState *g */
/* read gamestate from Last.dat */
bool gamestate_file_read(GameState *g)
{
	FILE *fh = NULL;
	int i = 0;
	LastHeader l = {0};
	
	CHECK_PARAMETERS(g == NULL, return false);
	
	fh = fopen(FILENAME_LAST_GAME, "rb");
	if(fh == NULL)
	{
		return false;
	}
	
	if(fread(&l, sizeof(LastHeader), 1, fh) != 1)
	{
		fprintf(stderr, "File corrupted\n");
		fclose(fh);
		return false;
	}
	
	if(gamestate_from_lastheader(g, &l) == false)
	{
		fprintf(stderr, "File or memory corrupted");
		fclose(fh);
		return false;
	}
	
	g->mat = (Matrix*)calloc(g->matrixCount, sizeof(Matrix));
	CHECK_ALLOCATION(g->mat, fclose(fh); return false);
	
	for(i = 0; i < g->matrixCount; i++)
	{
		CHECK_OPERATION(matrix_init(&g->mat[i], g->matrixSize), 
		{
			int j = 0;
			fprintf(stderr, "Matrix initialization failed\n");
			for(j = 0; j < i; j++)
			{
				matrix_deinit(&g->mat[j]);
			}
			free(g->mat);
			g->mat = NULL;
			g->matrixCount = 0;
			fclose(fh);
			gamestate_deinit(g);
			return false;
		});
		CHECK_OPERATION(matrix_data_file_read(&g->mat[i], g->matrixSize, fh),
		{
			int j = 0;
			fprintf(stderr, "File corrupted\n");
			for(j = 0; j <= i; j++)
			{
				matrix_deinit(&g->mat[j]);
			}
			free(g->mat);
			g->mat = NULL;
			g->matrixCount = 0;
			fclose(fh);
			gamestate_deinit(g);
			return false;
		});
	}
	
	return !fclose(fh);
}

/* Input: GameState *g.    Output: bool (success/fail), GameState *g */
/* write only lastest matrix and matrixCount. Don't call this function when file not already initialized */
bool gamestate_file_push(const GameState *g)
{
	FILE *fh = NULL;
	int skipBytesCount = 0;
	LastHeader l = {0};
	
	CHECK_GAMESTATE(g, return false);
	
	if(g->matrixCount == 0)
	{
		fprintf(stderr, "There is no matrix to push\n");
		return false;
	}
	
	CHECK_OPERATION(gamestate_to_lastheader(g, &l), return false);
	
	fh = fopen(FILENAME_LAST_GAME, "rb+");
	CHECK_OPERATION(fh, return false);
	
	
	skipBytesCount = (char*)&l.matrixCount - (char*)&l;
	
	fseek(fh, skipBytesCount, SEEK_SET);
	
	fwrite(&l.matrixCount, sizeof(l.matrixCount), 1, fh);
	
	fseek(fh, 0L, SEEK_END);
	
	CHECK_OPERATION(matrix_data_file_write(&g->mat[g->matrixCount-1], fh), fclose(fh); return false);
	
	return !fclose(fh);
}

/* Input: GameState *g.    Output: bool (success/fail) */
/* There is no way to "cut" some parts of file, so this function is wrapper of gamestate_file_write */
bool gamestate_file_pop(const GameState *g)
{
	return gamestate_file_write(g);
}


/***************************************************************/
/*                       SCORE FUNCTIONS                       */
/***************************************************************/

/* Input: char *playerName, double score.    Output: Score* */
/* Create score with given playerName and score, return object if success, NULL otherwise */
Score *score_create(char *playerName, double score)
{
	Score *s = (Score*)malloc(sizeof(Score));
	CHECK_ALLOCATION(s, return NULL);
	
	if(playerName != NULL)
	{
		strncpy(s->playerName, playerName, LENGTH_PLAYER_NAME);
	}
	else
	{
		memset(s->playerName, 0, LENGTH_PLAYER_NAME * sizeof(char));
	}
	s->score = score;
	s->next = NULL;
	
	return s;
}

/* Input: Score *s.    Output: bool (success/fail) */
/* Delete score and free up memory, return true if success */
bool score_delete(Score *s)
{
	CHECK_PARAMETERS(s == NULL, return false);
	
	free(s);
	
	return true;
}

/* Input: Score *target, *source.    Output: bool (success/fail), Score *target, *source */
/* insert new score (source) to target's next. return true if succeed */
bool score_insert(Score *target, Score *source)
{
	Score *tempNext = NULL;
	
	CHECK_PARAMETERS(target == NULL, return false);
	CHECK_PARAMETERS(source == NULL, return false);
	
	tempNext = target->next;
	
	target->next = source;
	source->next = tempNext;
	
	return true;
}

/* Input: Score *s, FILE *fh.    Output: bool (success/fail), FILE *fh writeing to file */
/* write score to given file handle (write acceess required). return true if succeeed */
bool score_file_write(const Score *s, FILE *fh)
{
	CHECK_PARAMETERS(s == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	return fprintf(fh, "%.*s, %lf\n", LENGTH_PLAYER_NAME-1, s->playerName, s->score) > 0;
}

/* Input: Score *s, FILE *fh.    Output: bool (success/fail), Score *s, FILE *fh reading from file */
/* read score from given file handle (read access required). return true if succeed */
bool score_file_read(Score *s, FILE *fh)
{
	char buffer[SCORE_READ_BUFFER_LEN] = {0};
	
	CHECK_PARAMETERS(s == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	sprintf(buffer, "%%%d[^,],%%lf\n", LENGTH_PLAYER_NAME-1);
	
	return fscanf(fh, buffer, s->playerName, &s->score) == 2;
}

/* Input: Score *s.    Output: bool (success/fail) */
/* print given score to screen */
bool score_print(const Score *s)
{
	CHECK_PARAMETERS(s == NULL, return false);
	
	printf("Name: %s  Score: %lf\n", s->playerName, s->score);
	
	return true;
}


/***************************************************************/
/*                     SCORELIST FUNCTIONS                     */
/***************************************************************/

/* Input: ScoreList *slst.    Output: bool (success/fail), ScoreList *slst */
/* initialize ScoreList */
bool scorelist_init(ScoreList *slst)
{
	CHECK_PARAMETERS(slst == NULL, return false);
	
	memset(slst, 0, sizeof(ScoreList));
	
	return true;
}

/* Input: ScoreList *slst.    Output: bool (success/fail) */
/* deinitialize and freeing up memory of given ScoreList */
bool scorelist_deinit(ScoreList *slst)
{
	Score *s = NULL;
	
	CHECK_SCORELIST(slst, return false);
	
	s = slst->head;
	while(s != NULL)
	{
		Score *temp = s->next;
		
		score_delete(s);
		
		s = temp;
	}
	
	slst->head = NULL;
	slst->N = 0;
	return true;
}

/* Input: ScoreList *slst, Score *s.    Output: bool (success/fail), ScoreList *slst, Score *s */
/* add new score to scorelist by alphabetic and (if same name) score order. return true if succeed */
bool scorelist_add_in_order(ScoreList *slst, Score *s)
{
	Score *node = NULL, dummy = {0};
	bool addedToList = false;
	
	CHECK_PARAMETERS(s == NULL, return false);
	CHECK_SCORELIST(slst, return false);
	
	dummy.next = slst->head;
	
	node = &dummy;
	
	while(node->next != NULL && addedToList == false)
	{
		int strncmpRes = strncmp(s->playerName, node->next->playerName, LENGTH_PLAYER_NAME-1);
		if(strncmpRes == 0) /* same string */
		{
			while(node->next != NULL && addedToList == false && !strncmp(s->playerName, node->next->playerName, LENGTH_PLAYER_NAME-1))
			{
				if(s->score > node->next->score)
				{
					score_insert(node, s);
					addedToList = true;
				}
				else
				{
					node = node->next;
				}
			}
		}
		else if(strncmpRes < 0)
		{
			score_insert(node, s);
			addedToList = true;
		}
		else
		{
			node = node->next;
		}
	}
	
	if(addedToList == false)
	{
		addedToList = score_insert(node, s);
	}
	
	if(addedToList == true)
	{
		slst->head = dummy.next;
		slst->N++;
		return true;
	}
	
	return false;
}

/* Input: ScoreList *slst, char *name.    Output: int count */
/* return count of game of given name's player if succeed, INTEGER_ERROR otherwise */
int scorelist_game_count_of_player(const ScoreList *slst, const char *name)
{
	Score *node = NULL;
	int count = 0;
	
	CHECK_SCORELIST(slst, return INTEGER_ERROR);
	CHECK_PARAMETERS(name == NULL, return INTEGER_ERROR);
	
	if(strlen(name) >= LENGTH_PLAYER_NAME) /* early exit */
	{
		return 0;
	}
	
	node = slst->head;
	while(node != NULL)
	{
		if(!strncmp(node->playerName, name, LENGTH_PLAYER_NAME-1))
		{
			count++;
		}
		node = node->next;
	}
	
	return count;
}

/* Input: ScoreList *slst.    Output: bool (success/fail) */
/* write given scorelist to Scores.csv (text mode). return true if succeed */
bool scorelist_file_write(const ScoreList *slst)
{
	FILE *fh = NULL;
	Score *node = NULL;
	
	CHECK_SCORELIST(slst, return false);
	
	fh = fopen(FILENAME_SCORES, "w");
	CHECK_OPERATION(fh, return false);
	
	node = slst->head;
	while(node != NULL)
	{
		score_file_write(node, fh);
		node = node->next;
	}
	
	return !fclose(fh);
}

/* Input: ScoreList *slst.    Output: bool (success/fail), ScoreList *slst */
/* read scorelist from Scores.cvs (text mode). return true if succeed */
bool scorelist_file_read(ScoreList *slst)
{
	FILE *fh = NULL;
	bool isContinue = true;
	
	CHECK_PARAMETERS(slst == NULL, return false);
	
	fh = fopen(FILENAME_SCORES, "r");
	if(fh == NULL)
	{
		return false;
	}
	
	do
	{
		Score *s = score_create(NULL, 0.0);
		CHECK_OPERATION(s, 
		{
			fclose(fh);
			scorelist_deinit(slst);
			return false;
		});
		if(score_file_read(s, fh) == true)
		{
			scorelist_add_in_order(slst, s);
		}
		else
		{
			score_delete(s);
			isContinue = false;
		}
	}while(isContinue);
	
	return !fclose(fh);
}

/* Input: ScoreList *slst.    Output: bool (success/fail) */
/* print scorelist to screen. return true if succeed */
bool scorelist_print(const ScoreList *slst)
{
	Score *node = NULL;
	
	CHECK_SCORELIST(slst, return false);
	
	node = slst->head;
	while(node != NULL)
	{
		score_print(node);
		node = node->next;
	}
	
	return true;
}


/***************************************************************/
/*                     MAIN MENU FUNCTIONS                     */
/***************************************************************/

/* Input: -.    Output: - */
/* print main menu to screen. */
void main_menu_print(void)
{
	printf(	"+-----------------------------+\n"
			"| 1- Create Random Matrix     |\n"
			"| 2- Create Matrix from File  |\n"
			"| 3- Show User Scores         |\n"
			"| 4- Exit                     |\n"
			"+-----------------------------+\n"
	);
}

/* Input: -.    Output: MainMenuOperations operation code */
/* get main menu operation code from user */
MainMenuOperations main_menu_get_operation(void)
{
	return (MainMenuOperations)get_integer_input(MAIN_MENU_RANDOM+1, MAIN_MENU_EXIT+1, "Enter main menu operation [%d-%d]: ", MAIN_MENU_RANDOM+1, MAIN_MENU_EXIT+1)-1;
}

/* Input: -.    Output: bool (success/fail) */
/* random matrix creation menu. return true if succeed */
bool main_menu_random(void)
{
	bool (* const gameMenuFp[GAME_MENU_COUNT]) (ListOfLists *lst) = {
		game_menu_automatic,
		game_menu_manual
	};
	ListOfLists lst = {0};
	Matrix mat = {0};
	PosList startPosLst = {0}, endPosLst = {0};
	bool returnValue = true;
	
	CHECK_OPERATION(gamestate_init(&lst.g), return false);
	
	scorelist_init(&lst.slst);
	scorelist_file_read(&lst.slst);
	
	lst.g.mainMenuOperations = MAIN_MENU_RANDOM;
	lst.g.matrixSize = get_integer_input(MATRIX_MIN_SIZE, MATRIX_MAX_SIZE, "Enter matrix size [%d-%d]: ", MATRIX_MIN_SIZE, MATRIX_MAX_SIZE);
	get_string_input(lst.g.playerName, LENGTH_PLAYER_NAME, "Enter Player Name: ");
	
	printf("\nCreating random %dx%d matrix . . .\n", lst.g.matrixSize, lst.g.matrixSize);
	
	#if (VERBOSE_LEVEL >= 1)
	if(lst.g.matrixSize >= MATRIX_WARNING_THRESHOLD)
	{
		fprintf(stderr, "This may take long time to generate\n");
	}
	#endif
	
	CHECK_OPERATION(matrix_generator(lst.g.matrixSize, &mat, &startPosLst, &endPosLst),
		poslist_deinit(&startPosLst); poslist_deinit(&endPosLst); scorelist_deinit(&lst.slst); gamestate_deinit(&lst.g); return false);
	CHECK_OPERATION(matrix_clean_except_poslists(&mat, &startPosLst, &endPosLst),
		matrix_deinit(&mat); poslist_deinit(&startPosLst); poslist_deinit(&endPosLst); scorelist_deinit(&lst.slst); gamestate_deinit(&lst.g); return false);
	
	poslist_deinit(&startPosLst);
	poslist_deinit(&endPosLst);
	
	printf("Matrix created\n");
	
	matrix_print(&mat);
	
	game_menu_print();
	CHECK_OPERATION(gamestate_push_matrix(&lst.g, &mat), 
		matrix_deinit(&mat); scorelist_deinit(&lst.slst); gamestate_deinit(&lst.g); return false);
	
	lst.g.gameMenuOperations = game_menu_get_operation();
	
	if(lst.g.gameMenuOperations < GAME_MENU_RETURN)
	{
		returnValue = gameMenuFp[lst.g.gameMenuOperations](&lst);
	}
	
	scorelist_deinit(&lst.slst);
	gamestate_deinit(&lst.g);
	
	return returnValue;
}

/* Input: -.    Output: bool (success/fail) */
/* matrix from file menu. return true if succeed */
bool main_menu_file(void)
{
	bool (* const gameMenuFp[GAME_MENU_COUNT]) (ListOfLists *lst) = {
		game_menu_automatic,
		game_menu_manual
	};
	ListOfLists lst = {0};
	Matrix mat = {0};
	bool returnValue = false;
	FILE *fh = NULL;
	
	CHECK_OPERATION(gamestate_init(&lst.g), return false);
	
	scorelist_init(&lst.slst);
	scorelist_file_read(&lst.slst);
	
	lst.g.mainMenuOperations = MAIN_MENU_FILE;
	lst.g.matrixSize = get_integer_input(MATRIX_MIN_SIZE, MATRIX_MAX_SIZE, "Enter matrix size [%d-%d]: ", MATRIX_MIN_SIZE, MATRIX_MAX_SIZE);
	get_string_input(lst.g.playerName, LENGTH_PLAYER_NAME, "Enter Player Name: ");
	
	CHECK_OPERATION(matrix_init(&mat, lst.g.matrixSize), scorelist_deinit(&lst.slst); gamestate_deinit(&lst.g); return false);
	
	fh = get_file_input("r", "Enter %dx%d matrix file name: ", lst.g.matrixSize, lst.g.matrixSize);
	
	CHECK_OPERATION(matrix_file_read(&mat, fh), matrix_deinit(&mat); scorelist_deinit(&lst.slst); gamestate_deinit(&lst.g); fclose(fh); return false);
	
	CHECK_OPERATION(gamestate_push_matrix(&lst.g, &mat), 
		matrix_deinit(&mat); scorelist_deinit(&lst.slst); gamestate_deinit(&lst.g); return false);
	
	matrix_print(&mat);
	
	game_menu_print();
	lst.g.gameMenuOperations = game_menu_get_operation();
	
	
	if(lst.g.gameMenuOperations < GAME_MENU_RETURN)
	{
		returnValue = gameMenuFp[lst.g.gameMenuOperations](&lst);
	}
	
	scorelist_deinit(&lst.slst);
	gamestate_deinit(&lst.g);
	fclose(fh);
	
	return returnValue;
}

/* Input: -.    Output: bool (success/fail) */
/* print score menu. return true if succeed */
bool main_menu_score(void)
{
	ScoreList slst = {0};
	
	CHECK_OPERATION(scorelist_init(&slst), return false);
	
	if(scorelist_file_read(&slst) == false)
	{
		fprintf(stderr, "No score found\n");
		scorelist_deinit(&slst);
		return false;
	}
	
	scorelist_print(&slst);
	
	scorelist_deinit(&slst);
	
	printf("Press Enter (Return) key to continue . . .\n");
	clear_stdin();
	return true;
}


/***************************************************************/
/*                    LISTOFLISTS FUNCTIONS                    */
/***************************************************************/

/* Input: ListOfLists *lst.    Output: double score */
/* calculate and return score using listoflists and definitions. */
double lol_calculate_score(ListOfLists *lst)
{
	#if (SCORE_CALCULATION_TOLERATE_UNDO == 1)
		double undoExp = 1.0;
	#else
		double undoExp = 2.0;
	#endif
	#if (SCORE_CALCULATION_TOLERATE_TIME == 1)
		double timeExp = 1.0/3.0;
	#else
		double timeExp = 1.0/2.0;
	#endif
	
	const double matrixCreationMultipliersArr[] = {SCORE_RANDOM_MUL, SCORE_FIlE_MUL};
	const double gameModeMultiplierArr[] = {SCORE_AUTO_MUL, SCORE_MAUNAL_MUL};
	
	int playerGameCount = 0;
	double rewardPart = 0.0;
	double penaltyPart = 0.0;
	double totalMultiplier = 0.0;
	double gameModeMultiplier = 0.0;
	double matrixCreationModeMultiplier = 0.0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	CHECK_PARAMETERS(lst->g.mat == NULL, return false);
	
	if(matrix_is_solved(&lst->g.mat[lst->g.matrixCount-1], NULL, NULL) == false)
	{
		fprintf(stderr, "Matrix is not solved\n");
		return false;
	}
	
	gameModeMultiplier = gameModeMultiplierArr[lst->g.gameMenuOperations == GAME_MENU_MAUNAL];
	matrixCreationModeMultiplier = matrixCreationMultipliersArr[lst->g.mainMenuOperations == MAIN_MENU_FILE];
	
	playerGameCount = scorelist_game_count_of_player(&lst->slst, lst->g.playerName);
	
	totalMultiplier = sqrt(1.0 + playerGameCount/10.0);
	
	rewardPart = (pow(lst->g.matrixSize, 3) * gameModeMultiplier * matrixCreationModeMultiplier * SCORE_REWARD_MUL) / (pow(lst->g.totalTime+1.0, timeExp));
	
	penaltyPart = (lst->g.undoCount * SCORE_UNDO_MUL * pow(lst->g.matrixSize, undoExp));
	
	return (rewardPart - penaltyPart) > 0 ? ((rewardPart - penaltyPart) * totalMultiplier) : ((rewardPart - penaltyPart) / totalMultiplier);
}


/***************************************************************/
/*                     GAME MENU FUNCTIONS                     */
/***************************************************************/

/* Input: -.    Output: - */
/* print game menu to screen. */
void game_menu_print(void)
{
	printf(	"+---------------------------+\n"
			"| 1- Play in Automatic Mode |\n"
			"| 2- Play in Manual Mode    |\n"
			"| 3- Return to Main Menu    |\n"
			"+---------------------------+\n"
	);
}

/* Input: -.    Output: GameMenuOperations operation code */
/* get game menu operation code from user */
GameMenuOperations game_menu_get_operation(void)
{
	return (GameMenuOperations)get_integer_input(GAME_MENU_AUTOMATIC+1, GAME_MENU_RETURN+1, "Enter game menu operation [%d-%d]: ", GAME_MENU_AUTOMATIC+1, GAME_MENU_RETURN+1)-1;
}

/* Input: ListOfLists *lst.    Output: bool (success/fail), ListOfLists *lst */
/* automatic gameplay menu. return true if succeed */
bool game_menu_automatic(ListOfLists *lst)
{
	Score *s = NULL;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	if(lst->g.matrixCount == 0)
	{
		fprintf(stderr, "There is no matrix to solve\n");
		return false;
	}
	
	#if (VERBOSE_LEVEL >= 1)
	if(lst->g.matrixSize >= MATRIX_WARNING_THRESHOLD)
	{
		fprintf(stderr, "This may take long time to solve\n");
	}
	#endif
	
	lst->g.totalTime = (lst->g.totalTime == 0 ? (unsigned long)time(NULL) : lst->g.totalTime);
	
	if(gamestate_solver(&lst->g) == false)
	{
		fprintf(stderr, "Matrix is not solveable\n");
		return false;
	}
	
	lst->g.totalTime = time(NULL) - lst->g.totalTime;
	
	matrix_print(&lst->g.mat[lst->g.matrixCount-1]);
	
	printf("Time (second) elapsed: %lu\n", lst->g.totalTime);
	printf("Undo count: %lu\n", lst->g.undoCount);
	
	s = score_create(lst->g.playerName, lol_calculate_score(lst));
	scorelist_add_in_order(&lst->slst, s);
	scorelist_file_write(&lst->slst);
	printf("Score: %lf\n", s->score);
	
	remove(FILENAME_LAST_GAME);
	
	return true;
}

/* Input: ListOfLists *lst.    Output: bool (success/fail), ListOfLists *lst */
/* manual gameplay menu. return true if succeed */
bool game_menu_manual(ListOfLists *lst)
{
	bool (* const inGameMenuFp[INGAME_MENU_COUNT]) (ListOfLists *lst) = {
		ingame_menu_undo,
		ingame_menu_move
	};
	InGameMenuOperations op = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	if(lst->g.matrixCount == 0)
	{
		fprintf(stderr, "There is no matrix to solve\n");
		return false;
	}
	
	lst->g.totalTime = (lst->g.totalTime == 0 ? (unsigned long)time(NULL) : lst->g.totalTime);
	
	gamestate_file_write(&lst->g);
	
	do
	{
		matrix_print(&lst->g.mat[lst->g.matrixCount-1]);
		ingame_menu_print();
		op = ingame_menu_get_operation();
		
		if(op < INGAME_MENU_RESIGN)
		{
			inGameMenuFp[op](lst);
		}
		
	}while(op != INGAME_MENU_RESIGN && matrix_is_solved(&lst->g.mat[lst->g.matrixCount-1], NULL, NULL) == false);
	
	if(op != INGAME_MENU_RESIGN)
	{
		Score *s = NULL;
		matrix_print(&lst->g.mat[lst->g.matrixCount-1]);
		
		lst->g.totalTime = time(NULL) - lst->g.totalTime;
		
		printf("Time (second) elapsed: %lu\n", lst->g.totalTime);
		printf("Undo count: %lu\n", lst->g.undoCount);
		
		s = score_create(lst->g.playerName, lol_calculate_score(lst));
		scorelist_add_in_order(&lst->slst, s);
		scorelist_file_write(&lst->slst);
		printf("Score: %lf\n", s->score);
		
	}
	else
	{
		printf("Resigned\n");
	}
	remove(FILENAME_LAST_GAME);
	
	
	return true;
}


/***************************************************************/
/*                    INGAME MENU FUNCTIONS                    */
/***************************************************************/

/* Input: -.    Output: - */
/* print ingame menu to screen. */
void ingame_menu_print(void)
{
	printf(	"+------------+\n"
			"| 1- Undo    |\n"
			"| 2- Move    |\n"
			"| 3- Resign  |\n"
			"+------------+\n"
	);
}

/* get ingame menu operation code from user */
InGameMenuOperations ingame_menu_get_operation(void)
{
	return (InGameMenuOperations)get_integer_input(INGAME_MENU_UNDO+1, INGAME_MENU_RESIGN+1, "Enter operation [%d-%d]: ", INGAME_MENU_UNDO+1, INGAME_MENU_RESIGN+1)-1;
}

/* Input: ListOfLists *lst.    Output: bool (success/fail), ListOfLists *lst */
/* undo last movement. return true if succeed */
bool ingame_menu_undo(ListOfLists *lst)
{
	CHECK_LISTOFLISTS(lst, return false);
	
	if(lst->g.matrixCount <= 1)
	{
		fprintf(stderr, "Undo stack is empty\n");
		return false;
	}
	
	lst->g.undoCount++;
	
	CHECK_OPERATION(gamestate_pop_matrix(&lst->g), return false);
	CHECK_OPERATION(gamestate_file_pop(&lst->g), return false);
	
	return true;
}

/* Input: ListOfLists *lst.    Output: bool (success/fail), ListOfLists *lst */
/* movement. return true if succeed */
bool ingame_menu_move(ListOfLists *lst)
{
	Position srcPos = {0}, destPos = {0};
	Matrix mat = {0};
	int i = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	if(lst->g.matrixCount == 0)
	{
		fprintf(stderr, "There is not matrix\n");
		return false;
	}
	
	CHECK_OPERATION(matrix_duplicate(&lst->g.mat[lst->g.matrixCount-1], &mat), return false);
	
	srcPos = get_position_input(0, 0, lst->g.matrixSize-1, lst->g.matrixSize-1, "Enter source position (row, column): ");
	destPos = get_position_input(0, 0, lst->g.matrixSize-1, lst->g.matrixSize-1, "Enter destination position (row, column): ");
	
	if(position_is_aligned(srcPos, destPos) == false)
	{
		fprintf(stderr, "Coordinates are not aligned\n");
		matrix_deinit(&mat);
		return false;
	}
	else if(position_is_same(srcPos, destPos))
	{
		fprintf(stderr, "Coordinates are same\n");
		matrix_deinit(&mat);
		return false;
	}
	
	if(mat.data[srcPos.Y][srcPos.X] == MATRIX_EMPTY_ELEMENT)
	{
		fprintf(stderr, "Position (%d, %d) is empty\n", srcPos.Y, srcPos.X);
		matrix_deinit(&mat);
		return false;
	}
	
	if(srcPos.X == destPos.X)
	{
		bool isValid = true;
		const int from = MIN(srcPos.Y, destPos.Y);
		const int to = MAX(srcPos.Y, destPos.Y);
		
		for(i = from; i <= to && isValid == true; i++)
		{
			if(mat.data[srcPos.Y][srcPos.X] != mat.data[i][srcPos.X] &&
				mat.data[i][srcPos.X] != MATRIX_EMPTY_ELEMENT
			)
			{
				isValid = false;
			}
		}
		if(isValid == false)
		{
			fprintf(stderr, "Line is not empty or not same element as souce coordinate element\n");
			matrix_deinit(&mat);
			return false;
		}
		
		/* make movement */
		for(i = from; i <= to; i++)
		{
			mat.data[i][srcPos.X] = mat.data[srcPos.Y][srcPos.X];
		}
		
		
		
	}
	else if(srcPos.Y == destPos.Y)
	{
		bool isValid = true;
		const int from = MIN(srcPos.X, destPos.X);
		const int to = MAX(srcPos.X, destPos.X);
		
		for(i = from; i <= to && isValid == true; i++)
		{
			if(mat.data[srcPos.Y][srcPos.X] != mat.data[srcPos.Y][i] &&
				mat.data[srcPos.Y][i] != MATRIX_EMPTY_ELEMENT
			)
			{
				isValid = false;
			}
		}
		if(isValid == false)
		{
			fprintf(stderr, "Line is not empty or not same element as srcPos coordinate element\n");
			matrix_deinit(&mat);
			return false;
		}
				
		/* make movement */
		for(i = from; i <= to; i++)
		{
			mat.data[srcPos.Y][i] = mat.data[srcPos.Y][srcPos.X];
		}		
	}
	
	if(gamestate_push_matrix(&lst->g, &mat) == false)
	{
		matrix_deinit(&mat);
		return false;
	}
	return gamestate_file_push(&lst->g);
}


/***************************************************************/
/*                             MAIN                            */
/***************************************************************/

/* Input: -.    Output: int return value to CRT */
int main(void)
{
	bool (* const mainMenuFp[MAIN_MENU_COUNT]) (void) = {
		main_menu_random,
		main_menu_file,
		main_menu_score
	};
	MainMenuOperations op = 0;
	ListOfLists lst = {0};
	
	srand(time(NULL));
	
	if(gamestate_file_read(&lst.g) != false)
	{
		if(lst.g.gameMenuOperations == GAME_MENU_AUTOMATIC || lst.g.gameMenuOperations == GAME_MENU_MAUNAL)
		{
			bool (* const gameMenuFp[GAME_MENU_COUNT]) (ListOfLists *lst) = {
				game_menu_automatic,
				game_menu_manual
			};
			scorelist_init(&lst.slst);
			scorelist_file_read(&lst.slst);
			if(gameMenuFp[lst.g.gameMenuOperations](&lst) == false)
			{
				fprintf(stderr, "Operation failed\n");
			}
			scorelist_deinit(&lst.slst);
		}
		else
		{
			fprintf(stderr, "%s file corrupted\n", FILENAME_LAST_GAME);
		}
		gamestate_deinit(&lst.g);
	}
	
	do
	{				
		main_menu_print();
		op = main_menu_get_operation();
		
		if(op < MAIN_MENU_EXIT)
		{
			if(mainMenuFp[op]() == false)
			{
				fprintf(stderr, "Operation failed\n");
			}
		}
		printf("\n\n");
		
	}while(op != MAIN_MENU_EXIT);
	
	return 0;
}



/***************************************************************/
/*                       INPUT FUNCFIONS                       */
/***************************************************************/

/* Input: -    Output: - */
/* clear stdin after using scanf or getchar */
void clear_stdin(void)
{
	int ch = 0;
	while((ch = getchar()) != '\n' && ch != EOF);
}

/* Input: int minX, minY, maxX, maxY, char *msgFormat, ...    Output: Position */
/* both min and max included */
Position get_position_input(int minX, int minY, int maxX, int maxY, const char *msgFormat, ...)
{
	bool isValid = true;
	Position input = {-1, -1};
	va_list arg = NULL;
	
	CHECK_PARAMETERS(minX > maxX, return input);
	CHECK_PARAMETERS(minY > maxY, return input);
	
	if(msgFormat != NULL)
	{
		va_start(arg, msgFormat);
	}
	
	do
	{
		isValid = true;
		
		if(msgFormat != NULL)
		{
			vprintf(msgFormat, arg);
		}
		
		if(scanf("%d %d", &input.Y, &input.X) != 2)
		{
			fprintf(stderr, "Enter two integer value separated by space\n");
			isValid = false;
		}
		else if(input.X < minX || input.X > maxX)
		{
			fprintf(stderr, "The x (colmun) value must be between %d and %d (both included)\n", minX, maxX);
			isValid = false;
		}
		else if(input.Y < minY || input.Y > maxY)
		{
			fprintf(stderr, "The y (row) value must be between %d and %d (both included)\n", minY, maxY);
			isValid = false;
		}
		
		if(isValid == false)
		{
			clear_stdin();
		}
		
	}while(isValid == false);
	
	if(msgFormat != NULL)
	{
		va_end(arg);
	}
	
	clear_stdin();

	return input;
}

/* Input: char *fileMode, char *msgFormat, ...    Output: FILE *file opend file name */
FILE *get_file_input(const char *fileMode, const char *msgFormat, ...)
{
	FILE *fh = NULL;
	char fileName[FILENAME_MAX_LENGTH] = {'\0'};
	
	CHECK_PARAMETERS(fileMode == NULL, return NULL);
	
	do
	{
		int ch = 0, i = 0;
		va_list arg = NULL;
		
		if(msgFormat != NULL)
		{
			va_start(arg, msgFormat);
			vprintf(msgFormat, arg);
			va_end(arg);
		}
		
		while((ch = getchar()) != '\n' && ch != EOF)
		{
			if(i < FILENAME_MAX_LENGTH-1)
			{
				fileName[i++] = (char)ch;
			}
		}
		fileName[i] = '\0';
		
		fh = fopen(fileName, fileMode);
		
		if(fh == NULL)
		{
			perror("File can't open");
		}
	}while(fh == NULL);
	
	return fh;
}

/* Input: int min, max, char *msgFormat, ...    Output: int integer from stdin */
/* Get integer from stdin, both min and max included */
int get_integer_input(int min, int max, const char *msgFormat, ...)
{
	bool isValid = true;
	int input = 0;
	va_list arg = NULL;
	
	CHECK_PARAMETERS(min > max, return 0);
	
	if(msgFormat != NULL)
	{
		va_start(arg, msgFormat);
	}
	
	do
	{
		isValid = true;
		
		if(msgFormat != NULL)
		{
			vprintf(msgFormat, arg);
		}
		
		if(scanf("%d", &input) != 1)
		{
			fprintf(stderr, "Enter an integer value\n");
			clear_stdin();
			isValid = false;
		}
		else if(input < min || input > max)
		{
			fprintf(stderr, "Value must be between %d and %d (both included)\n", min, max);
			clear_stdin();
			isValid = false;
		}		
	}while(isValid == false);
	
	if(msgFormat != NULL)
	{
		va_end(arg);
	}
	
	clear_stdin();

	return input;
}

/* Input: char *buffer, int maxLength, char *msgFormat, ...    Output: char *buffer */
/* Get string fom stdin, '\0' character included maxLength (example: maxLength = 5 mean, 4 char + '\0') */
char *get_string_input(char *buffer, int maxLength, const char *msgFormat, ...)
{
	int ch = 0, i = 0;
	va_list arg = NULL;
	
	CHECK_PARAMETERS(buffer == NULL || maxLength == 0, return NULL);
	
	if(msgFormat != NULL)
	{
		va_start(arg, msgFormat);
		vprintf(msgFormat, arg);
		va_end(arg);
	}
	
	while((ch = getchar()) != '\n' && ch != EOF)
	{
		if(i < maxLength-1)
		{
			buffer[i++] = (char)ch;
		}
	}
	buffer[i] = '\0';
	
	return buffer;
}
