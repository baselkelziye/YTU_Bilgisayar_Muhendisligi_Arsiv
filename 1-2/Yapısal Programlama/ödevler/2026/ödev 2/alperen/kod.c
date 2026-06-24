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

#define NOT_EXIST (-1)

#define MENU_EXIT (21)

#define LENGTH_MIN_ISBN  (13)

#define LENGTH_STUDENT_NO  (9)
#define LENGTH_ISBN        (25)
#define LENGTH_NAME        (40)
#define LENGTH_SURNAME     (40)

#define STUDENT_STR_BUFFER_LEN (256)
#define AUTHOR_STR_BUFFER_LEN (128)
#define BOOKINSTANCE_STR_BUFFER_LEN (64)
#define BOOK_STR_BUFFER_LEN (128)
#define BORROW_STR_BUFFER_LEN (256)

#define LENGTH_BUFFER_INITIALIZE (4)
#define SIZE_STUDENTLIST_INITIAL (4)

#define INITIAL_STUDENT_SCORE  (100)

#define ON_SHELF           (0)    /* NULL */
#define ON_SHELF_STRING   "ON SHELF"

#define FILENAME_AUTHORS        "Authors.csv"
#define FILENAME_STUDENTS       "Students.csv"
#define FILENAME_BOOKBORROWING  "BookBorrow.csv"
#define FILENAME_BOOKS			"Books.csv"
#define FILENAME_BOOKSINSTANCE  "BooksInstance.csv"
#define FILENAME_BOOKAUTHOR     "BookAuthor.dat"

#define BOOK_BORROW_THRESHOLD (15) /* totalDay >= this: -10 score */
#define BOOK_BORROW_SCORE     (-10)

/***************************************************************/
/*                            MACROS                           */
/***************************************************************/


#define CHECK_PARAMETERS(condition, action)              \
do                                                       \
{                                                        \
	assert(!(condition));                                \
	if((condition))                                      \
	{                                                    \
		fprintf(stderr, "Parameters are invalid\n");     \
		action;                                          \
	}                                                    \
}while(0)

#define CHECK_ALLOCATION(ptr, action)                    \
do                                                       \
{                                                        \
	assert((ptr));                                       \
	if((ptr) == NULL)                                    \
	{                                                    \
		perror("Allocation error");                      \
		action;                                          \
	}                                                    \
}while(0)

#define CHECK_STUDENT(s, action)\
do\
{\
	bool isNotValid = (s) == NULL\
		|| (s)->score > INITIAL_STUDENT_SCORE;\
	assert(!isNotValid);\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "Student is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_STUDENTLIST(slst, action)\
do\
{\
	bool isNotValid = (slst) == NULL || (slst)->capacity < 0 || (slst)->size < 0 || \
		(slst)->size > (slst)->capacity || (((slst)->data == NULL) ^ ((slst)->capacity == 0));\
	assert(!isNotValid);\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "StudentList is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_AUTHOR(a, action)\
do\
{\
	bool isNotValid = (a) == NULL || (a)->id < 0;\
	assert(!isNotValid);\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "Author is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_AUTHORLIST(alst, action)\
do\
{\
	bool isNotValid = (alst) == NULL || (alst)->lastId < 0 || (alst)->count < 0 ||\
		(((alst)->count == 0) ^ ((alst)->head == NULL)) ||\
		(((alst)->count == 0) ^ ((alst)->tail == NULL));\
	assert(!isNotValid);\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "AuthorList is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_BOOKINSTANCE(bi, action)\
do\
{\
	bool isNotValid = (bi) == NULL || \
		(((bi)->isBorrowed == 0) ^ (strncmp((bi)->borrowedNo, ON_SHELF_STRING, LENGTH_STUDENT_NO-1) == 0));\
	assert(!isNotValid);\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "BookInstance is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_BOOK(b, action)\
do\
{\
	bool isNotValid = (b) == NULL || \
		(((b)->instanceCount == 0) ^ ((b)->bi == NULL));\
	assert(!isNotValid);\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "Book is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_BOOKLIST(blst, action)\
do\
{\
	bool isNotValid = (blst) == NULL || (blst)->count < 0 ||\
		(((blst)->count == 0) ^ ((blst)->head == NULL)) ||\
		(((blst)->count == 0) ^ ((blst)->tail == NULL));\
	assert(!isNotValid);\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "BookList is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_BOOKAUTHOR(ba, action)\
do\
{\
	bool isNotValid = (ba) == NULL;\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "BookAuthor is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_BOOKAUTHORLIST(balst, action)\
do\
{\
	bool isNotValid = (balst) == NULL || ((balst)->count < 0) || \
		(((balst)->count == 0) ^ ((balst)->data == NULL));\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "BookAuthorList is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_BORROW(br, action)\
do\
{\
	bool isNotValid = (br) == NULL || \
		((br)->type != BOOK_BORROW && (br)->type != BOOK_DELIVER);\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "Borrow is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_BORROWLIST(brlst, action)\
do\
{\
	bool isNotValid = (brlst) == NULL || ((brlst)->count < 0) || \
		(((brlst)->count == 0) ^ ((brlst)->data == NULL));\
	if(isNotValid == true)\
	{\
		fprintf(stderr, "BorrowList is not valid\n");\
		action;\
	}\
}while(0)

#define CHECK_LISTOFLISTS(lst, action)\
do\
{\
	if((lst) == NULL)\
	{\
		action;\
	}\
	CHECK_STUDENTLIST(&(lst)->slst, action);\
	CHECK_AUTHORLIST(&(lst)->alst, action);\
	CHECK_BOOKLIST(&(lst)->blst, action);\
	CHECK_BOOKAUTHORLIST(&(lst)->balst, action);\
	CHECK_BORROWLIST(&(lst)->brlst, action);\
}while(0)

#define CHECK_OPERATION_SUCCESS(operation, action) \
do                                     \
{                                      \
	if((operation) == NULL)                  \
	{                                  \
		action;                        \
	}                                  \
}while(0);

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))


/***************************************************************/
/*                       DATA STRUCTURES                       */
/***************************************************************/

typedef char *String;

typedef struct Author
{
	int            id;
	char           name[LENGTH_NAME];
	char           surname[LENGTH_SURNAME];
	struct Author *next;
}Author;

typedef struct AuthorList
{
	int     lastId;
	int     count;    /* Author count */
	Author *head;
	Author *tail;
}AuthorList;

typedef struct Student
{
	char   no[LENGTH_STUDENT_NO];
	char   name[LENGTH_NAME];
	char   surname[LENGTH_SURNAME];
	int    score;                  /* 100 at start */
}Student;

typedef struct StudentList
{
	Student *data;
	int size;
	int capacity;
}StudentList;

typedef struct BookInstance
{
	char isbn[LENGTH_ISBN];             /* 1234567891011_instanceIndex format */
	bool isBorrowed;
	char borrowedNo[LENGTH_STUDENT_NO]; /* No of student if any student borrowed book */
	int  instanceIndex;    /* 1, 2, 3, 4, ... */
}BookInstance;

typedef struct Book
{
	char          name[LENGTH_NAME];
	char          isbn[LENGTH_ISBN]; 
	int           instanceCount;     /* number of copy */
	BookInstance *bi;
	struct Book  *next;
}Book;

typedef struct BookList
{
	int   count;   /* Book count */
	Book *head;
	Book *tail;
}BookList;

typedef struct BookAuthor
{
	char isbn[LENGTH_MIN_ISBN+1];
	int  authorId;
}BookAuthor;

typedef struct BookAuthorList
{
	BookAuthor *data;
	int count;
}BookAuthorList;

typedef enum BorrowType
{
	BOOK_BORROW = 0,
	BOOK_DELIVER
}BorrowType;

typedef struct OperationDate
{
	unsigned day:   5;
	unsigned month: 4;
	unsigned year:  23;
}OperationDate;

typedef struct Borrow
{
	char          isbn[LENGTH_ISBN];
	char          studentNo[LENGTH_STUDENT_NO];
	BorrowType    type;
	OperationDate date;
}Borrow;

typedef struct BorrowList
{
	Borrow *data;
	int count;
}BorrowList;

typedef struct ListOfLists
{
	StudentList slst;
	AuthorList alst;
	BookList blst;
	BookAuthorList balst;
	BorrowList brlst;
}ListOfLists;

/***************************************************************/
/*                     FUNCTION PROTOTYPES                     */
/***************************************************************/


bool studentlist_init(StudentList *slst);
bool studentlist_deinit(StudentList *slst);
bool studentlist_reserve(StudentList *slst, int newCapacity);
bool studentlist_shrink_to_fit(StudentList *slst);

int book_get_max_instance_index(Book *b);

bool bookauthorlist_init(BookAuthorList *balst);
bool bookauthorlist_deinit(BookAuthorList *balst);
bool bookauthorlist_remove_isbn(BookAuthorList *balst, char *isbn);
bool bookauthorlist_update_isbn(BookAuthorList *balst, char *oldIsbn, char *newIsbn);
bool bookauthorlist_update_id(BookAuthorList *balst, int oldId, int newId);
bool bookauthorlist_print(BookAuthorList *balst);
bool bookauthorlist_add_back(BookAuthorList *balst, BookAuthor *ba);
bool bookauthorlist_remove_at(BookAuthorList *balst, int index);
bool bookauthorlist_file_write(BookAuthorList *balst, char *fileName);
bool bookauthorlist_file_read(BookAuthorList *balst, char *fileName);


int get_integer_input(int min, int max, char *msgFormat, ...);
bool get_student_no_input(char *studentNo, char *msgFormat, ...);
bool get_isbn_input(char *isbn, char *msgFormat, ...);
OperationDate get_date_input(char *msgFormat, ...);
char *get_string_input(char *buffer, int maxLength, char *msgFormat, ...);


/***************************************************************/
/*                       GLOBAL CONSTANTS                      */
/***************************************************************/



/***************************************************************/
/*                    INTERACTION FUNCTIONS                    */
/***************************************************************/

void print_menu(void)
{
	printf("%s%s%s%s", 
			"+-------------------------------------------------+\n"
			"| Student Operations:                             |\n"
			"|  1- Add Student                                 |\n"
			"|  2- Delete Student                              |\n"
			"|  3- Update Student                              |\n"
			"|  4- Display Student                             |\n"
			"|  5- List Students Who Have Not Returned Books   |\n"
			"|  6- List Penalized Students                     |\n"
			"|  7- List All Students                           |\n",
			"|  8- Borrow Book                                 |\n"
			"|  9- Return Book                                 |\n"
			"+-------------------------------------------------+\n"
			"| Book Operations:                                |\n"
			"|  10- Add Book                                   |\n"
			"|  11- Delete Book                                |\n"
			"|  12- Update Book                                |\n"
			"|  13- Display Book Information                   |\n"
			"|  14- List Book on the Shelf                     |\n",
			"|  15- List Book Not Returned on Time             |\n"
			"|  16- Match Book-Author                          |\n"
			"|  17- Update the Author of a Book                |\n"
			"+-------------------------------------------------+\n",
			"| Author Operations:                              |\n"
			"|  18- Add Author                                 |\n"
			"|  19- Delete Author                              |\n"
			"|  20- Update Author                              |\n"
			"|  21- Display Author Information                 |\n"
			"+-------------------------------------------------+\n"
			"|  22- Exit                                       |\n"
			"+-------------------------------------------------+\n"
	);
			
			
}


/***************************************************************/
/*                     TIME-DATE FUNCTIONS                     */
/***************************************************************/

/* return o2 - o1; */
int diffDay(OperationDate o1, OperationDate o2)
{
	struct tm d = {0};
	time_t t1 = 0, t2 = 0;
	
	d.tm_mday = o1.day;
	d.tm_mon = o1.month-1;
	d.tm_year = o1.year-1900;
	t1 = mktime(&d);
	if(t1 == -1)
	{
		fprintf(stderr, "OperationDate o1 did not converted to struct tm");
		return 0;
	}
	
	memset(&d, 0, sizeof(struct tm));
	d.tm_mday = o2.day;
	d.tm_mon = o2.month-1;
	d.tm_year = o2.year-1900;
	t2 = mktime(&d);
	if(t2 == -1)
	{
		fprintf(stderr, "OperationDate o2 did not converted to struct tm");
		return 0;
	}
	
	return (t2 - t1) / (60 * 60 * 24);
}


/***************************************************************/
/*                      STUDENTS FUNCTIONS                     */
/***************************************************************/

bool student_init(Student *s, char *no, char *name, char *surname)
{
	CHECK_PARAMETERS(s == NULL, return false);
	
	memset(s, 0, sizeof(Student));
	
	if(no != NULL)
	{
		strncpy(s->no, no, LENGTH_STUDENT_NO);
	}
	
	if(name != NULL)
	{
		strncpy(s->name, name, LENGTH_NAME);
	}
	
	if(surname != NULL)
	{
		strncpy(s->surname, surname, LENGTH_SURNAME);
	}
	
	s->score = INITIAL_STUDENT_SCORE;
	
	return true;
}

bool student_deinit(Student *s)
{
	CHECK_STUDENT(s, return false);
	
	memset(s, 0, sizeof(Student));
	
	return true;
}

bool student_update(Student *s, char *newNo, char *newName, char *newSurname, int newScore)
{
	CHECK_STUDENT(s, return false);
	CHECK_PARAMETERS(newScore < 0 || newScore > INITIAL_STUDENT_SCORE, return false);
	
	if(newNo != NULL)
	{
		strncpy(s->no, newNo, LENGTH_STUDENT_NO);
	}
	
	if(newName != NULL)
	{
		strncpy(s->name, newName, LENGTH_NAME);
	}
	
	if(newSurname != NULL)
	{
		strncpy(s->surname, newSurname, LENGTH_SURNAME);
	}
	
	s->score = newScore;
	
	return true;
}

bool student_print(Student *s)
{
	CHECK_STUDENT(s, return false);
	
	printf(	"Student No: %s\n"
			"Student Name: %s\n"
			"Student Surname: %s\n"
			"Student Score: %d\n",
			s->no, s->name, s->surname, s->score
	);
	
	return true;
}

bool student_file_write(Student *s, FILE *fh)
{
	CHECK_STUDENT(s, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	fprintf(fh, "%.*s, %.*s, %.*s, %d\n",
		LENGTH_STUDENT_NO-1, s->no, LENGTH_NAME-1, s->name,
		LENGTH_SURNAME-1, s->surname, s->score);
	
	return true;
}

bool student_file_read(Student *s, FILE *fh)
{
	char buff[STUDENT_STR_BUFFER_LEN] = {'\0'};
	
	CHECK_STUDENT(s, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	sprintf(buff, "%%%d[^,], %%%d[^,], %%%d[^,], %%d\n", LENGTH_STUDENT_NO-1, LENGTH_NAME-1, LENGTH_SURNAME-1);
	
	return fscanf(fh, buff, s->no, s->name, s->surname, &s->score) == 4;
}


/***************************************************************/
/*                    STUDENTLIST FUNCTIONS                    */
/***************************************************************/

bool studentlist_init(StudentList *slst)
{
	CHECK_PARAMETERS(slst == NULL, return false);
	
	memset(slst, 0, sizeof(StudentList));
	
	return studentlist_reserve(slst, SIZE_STUDENTLIST_INITIAL);
}

bool studentlist_deinit(StudentList *slst)
{
	int i = 0;
	
	CHECK_STUDENTLIST(slst, return false);
	
	if(slst->data != NULL)
	{
		for(i = 0; i < slst->size; i++)
		{
			if(student_deinit(&slst->data[i]) == false)
			{
				return false;
			}
		}
		free(slst->data);
	}
	
	memset(slst, 0, sizeof(StudentList));
	
	return true;
}

bool studentlist_reserve(StudentList *slst, int newCapacity)
{
	Student *s = NULL;
	
	CHECK_STUDENTLIST(slst, return false);
	CHECK_PARAMETERS(newCapacity <= 0, return false);
	
	if(newCapacity < slst->capacity)
	{
		return true;
	}
	
	if(slst->data == NULL)
	{
		s = (Student*)malloc(newCapacity * sizeof(Student));
		CHECK_ALLOCATION(s, return false);
	}
	else
	{
		s = (Student*)realloc(slst->data, newCapacity * sizeof(Student));
		CHECK_ALLOCATION(s, return false);
	}
	
	memset(&s[slst->capacity], 0, (newCapacity - slst->capacity) * sizeof(Student));
	slst->data = s;
	slst->capacity = newCapacity;
	
	return true;
}

bool studentlist_shrink_to_fit(StudentList *slst)
{
	Student *s = NULL;
	
	CHECK_STUDENTLIST(slst, return false);
	
	s = (Student*)realloc(slst->data, slst->size * sizeof(Student));
	CHECK_ALLOCATION(s, return false);
	
	slst->capacity = slst->size;
	slst->data = s;
	
	return true;
}

bool studentlist_add_back(StudentList *slst, Student *s)
{
	CHECK_STUDENTLIST(slst, return false);
	CHECK_STUDENT(s, return false);
	
	if(slst->size == slst->capacity)
	{
		if(studentlist_reserve(slst, slst->capacity * 2) == false)
		{
			return false;
		}
	}
	
	slst->data[slst->size++] = *s;
	
	return true;
}

bool studentlist_remove_at(StudentList *slst, int index)
{
	CHECK_STUDENTLIST(slst, return false);
	CHECK_PARAMETERS(index < 0 || index >= slst->size, return false);
	
	if(student_deinit(&slst->data[index]) == false)
	{
		return false;
	}
	
	memmove(&slst->data[index], &slst->data[index+1], (slst->size-1 - index) * sizeof(Student));	
	memset(&slst->data[slst->size-1], 0, sizeof(Student));
	
	slst->size--;
	
	return true;
}

int studentlist_find(StudentList *slst, char no[LENGTH_STUDENT_NO])
{
	int i = 0;
	
	CHECK_STUDENTLIST(slst, return NOT_EXIST);
	
	for(i = 0; i < slst->size; i++)
	{
		if(!strncmp(slst->data[i].no, no, LENGTH_STUDENT_NO))
		{
			return i;
		}
	}
	
	return NOT_EXIST;
}

bool studentlist_print(StudentList *slst)
{
	int i = 0;
	
	CHECK_STUDENTLIST(slst, return false);
	
	for(i = 0; i < slst->size; i++)
	{
		printf("=====================================\n");
		student_print(&slst->data[i]);
	}
	printf("=====================================\n");
	
	return true;
}

bool studentlist_file_write(StudentList *slst, char *fileName)
{
	FILE *f = NULL;
	int i = 0;
	
	CHECK_STUDENTLIST(slst, return false);
	CHECK_PARAMETERS(fileName == NULL, return false);
	
	f = fopen(fileName, "w");
	CHECK_OPERATION_SUCCESS(f, return false);
	
	for(i = 0; i < slst->size; i++)
	{
		if(student_file_write(&slst->data[i], f) == false)
		{
			fclose(f);
			return false;
		}
	}
	
	fclose(f);
	return true;
}

bool studentlist_file_read(StudentList *slst, char *fileName)
{
	
	FILE *f = NULL;
	Student s = {0};
	bool isContinue = true;
	
	CHECK_STUDENTLIST(slst, return false);
	CHECK_PARAMETERS(fileName == NULL, return false);
	
	f = fopen(fileName, "r");
	CHECK_OPERATION_SUCCESS(f, return false);
	
	do
	{
		student_init(&s, NULL, NULL, NULL);
		
		if(student_file_read(&s, f) == true)
		{
			studentlist_add_back(slst, &s);
		}
		else
		{
			isContinue = false;
		}
		
	}while(isContinue);
	
	
	fclose(f);
	return true;	
}



/***************************************************************/
/*                       AUTHOR FUNCTIONS                      */
/***************************************************************/

Author *author_create(char *name, char *surname)
{
	Author *a = NULL;
	
	a = (Author*)malloc(sizeof(Author));
	CHECK_ALLOCATION(a, return NULL);
	
	memset(a, 0, sizeof(Author));
	
	if(name != NULL)
	{
		strncpy(a->name, name, LENGTH_NAME);
	}
	
	if(surname != NULL)
	{
		strncpy(a->surname, surname, LENGTH_SURNAME);
	}
	
	return a;
}

bool author_delete(Author *a)
{
	CHECK_AUTHOR(a, return false);
	
	free(a);
	
	return true;
}

bool author_update(Author *a, int id, char *name, char *surname)
{
	CHECK_AUTHOR(a, return false);
	
	if(id > 0)
	{
		a->id = id;
	}
	
	if(name != NULL)
	{
		strncpy(a->name, name, LENGTH_NAME);
	}
	
	if(surname != NULL)
	{
		strncpy(a->surname, surname, LENGTH_SURNAME);
	}
	
	return true;
}

bool author_print(Author *a)
{
	CHECK_AUTHOR(a, return false);
	
	printf(	"Author ID: %d\n"
			"Author Name: %s\n"
			"Author Surname: %s\n",
			a->id, a->name, a->surname
	);
	
	return true;
}

bool author_file_write(Author *a, FILE *fh)
{
	CHECK_AUTHOR(a, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	fprintf(fh, "%d, %.*s, %.*s\n",
		a->id, LENGTH_NAME-1, a->name,
		LENGTH_SURNAME-1, a->surname);
	
	return true;
}

bool author_file_read(Author *a, FILE *fh)
{
	char buff[AUTHOR_STR_BUFFER_LEN] = {'\0'};
	
	CHECK_PARAMETERS(a == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	sprintf(buff, "%%d, %%%d[^,], %%%d[^\n]\n", LENGTH_NAME-1, LENGTH_SURNAME-1);
	
	return fscanf(fh, buff, &a->id, a->name, a->surname) == 3;
}


/***************************************************************/
/*                       AUTHOR FUNCTIONS                      */
/***************************************************************/

bool authorlist_init(AuthorList *alst)
{
	CHECK_PARAMETERS(alst == NULL, return false);
	
	memset(alst, 0, sizeof(AuthorList));
	
	return true;
}

bool authorlist_deinit(AuthorList *alst)
{
	Author *node = NULL;
	
	CHECK_AUTHORLIST(alst, return false);
	
	node = alst->head;
	while(node != NULL)
	{
		Author *tempNode = node->next;
		
		author_delete(node);
		
		node = tempNode;
	}
	
	memset(alst, 0, sizeof(AuthorList));
	
	
	return true;
}

bool authorlist_add_back(AuthorList *alst, Author *a)
{	
	CHECK_AUTHORLIST(alst, return false);
	CHECK_AUTHOR(a, return false);
	
	if(a->id == 0)
	{
		a->id = ++alst->lastId;
	}
	else if(a->id > alst->lastId)
	{
		alst->lastId = a->id;
	}
	
	if(alst->head == NULL)
	{
		alst->head = a;
		alst->tail = a;
	}
	else
	{
		alst->tail->next = a;
		alst->tail = alst->tail->next;
	}
	
	alst->count++;
	
	return true;
}

bool authorlist_add_front(AuthorList *alst, Author *a)
{	
	CHECK_AUTHORLIST(alst, return false);
	CHECK_AUTHOR(a, return false);
	
	a->id = ++alst->lastId;
	
	if(alst->head == NULL)
	{
		alst->head = a;
		alst->tail = a;
	}
	else
	{
		a->next = alst->head;
		alst->head = a;
	}
	
	alst->count++;
	
	return true;
}

bool authorlist_remove(AuthorList *alst, Author *a)
{
	Author *node = NULL;
	
	CHECK_AUTHORLIST(alst, return false);
	CHECK_AUTHOR(a, return false);
	
	if(alst->head == a)
	{
		alst->head = alst->head->next;
		if(alst->head == NULL)
		{
			alst->tail = NULL;
		}
		author_delete(a);
		alst->count--;
		
		return true;
	}
	
	node = alst->head;
	while(node->next != NULL)
	{
		if(node->next == a)
		{
			if(alst->tail == node->next)
			{
				alst->tail = node;
			}
			node->next = node->next->next;
			author_delete(a);
			alst->count--;
			
			return true;
		}
		node = node->next;
	}
	
	return false;
}

Author *authorlist_find(AuthorList *alst, char *name, char *surname)
{
	Author *node = NULL;
	
	CHECK_AUTHORLIST(alst, return NULL);
	CHECK_PARAMETERS(name == NULL || surname == NULL, return NULL);
	
	node = alst->head;
	while(node != NULL)
	{
		if(!strncmp(node->name, name, LENGTH_NAME) && !strncmp(node->surname, surname, LENGTH_SURNAME))
		{
			return node;
		}
		node = node->next;
	}
	
	return NULL;	
}

bool authorlist_check_author_exist(AuthorList *alst, int id)
{
	Author *node = NULL;
	
	CHECK_AUTHORLIST(alst, return false);
	
	node = alst->head;
	while(node != NULL)
	{
		if(node->id == id)
		{
			return true;
		}
		node = node->next;
	}
	
	return false;
}

bool authorlist_print(AuthorList *alst)
{
	Author *node = NULL;
	
	CHECK_AUTHORLIST(alst, return false);
	
	node = alst->head;
	while(node != NULL)
	{
		printf("=====================================\n");
		author_print(node);
		node = node->next;
	}
	printf("=====================================\n");
	
	return true;
}

bool authorlist_file_write(AuthorList *alst, char *fileName)
{
	FILE *f = NULL;
	Author *node = NULL;
	
	CHECK_AUTHORLIST(alst, return false);
	CHECK_PARAMETERS(fileName == NULL, return false);
	
	f = fopen(fileName, "w");
	CHECK_OPERATION_SUCCESS(f, return false);
	
	node = alst->head;
	while(node != NULL)
	{
		if(author_file_write(node, f) == false)
		{
			fclose(f);
			return false;
		}
		node = node->next;
	}
	
	fclose(f);
	return true;
}

bool authorlist_file_read(AuthorList *alst, char *fileName)
{
	
	FILE *f = NULL;
	Author *a = NULL;
	bool isContinue = true;
	
	CHECK_AUTHORLIST(alst, return false);
	CHECK_PARAMETERS(fileName == NULL, return false);
	
	f = fopen(fileName, "r");
	CHECK_OPERATION_SUCCESS(f, return false);
	
	do
	{
		a = author_create(NULL, NULL);
		CHECK_OPERATION_SUCCESS(a, fclose(f); return false);
		
		if(author_file_read(a, f) == true)
		{
			authorlist_add_back(alst, a);
		}
		else
		{
			author_delete(a);
			isContinue = false;
		}
		
	}while(isContinue);
	
	
	fclose(f);
	return true;	
}


/***************************************************************/
/*                    BOOKINSTANCE FUNCTIONS                   */
/***************************************************************/

bool bookinstance_init(BookInstance *bi, char *originalISBN, int instanceIndex, bool isBorrowed, char *borrowedNo)
{
	CHECK_PARAMETERS(bi == NULL, return false);
	CHECK_PARAMETERS((isBorrowed == false) ^ (borrowedNo == NULL), return false);
	CHECK_PARAMETERS(instanceIndex < 0, return false);
	
	memset(bi, 0, sizeof(BookInstance));
	
	if(originalISBN != NULL)
	{
		sprintf(bi->isbn, "%.*s_%d", LENGTH_MIN_ISBN, originalISBN, instanceIndex);
	}
	
	bi->instanceIndex = instanceIndex;
	bi->isBorrowed = isBorrowed;
	
	if(borrowedNo != NULL)
	{
		strncpy(bi->borrowedNo, borrowedNo, LENGTH_STUDENT_NO);
	}
	else
	{
		strncpy(bi->borrowedNo, ON_SHELF_STRING, LENGTH_STUDENT_NO);
	}
	
	
	return true;
}

bool bookinstance_deinit(BookInstance *bi)
{
	CHECK_BOOKINSTANCE(bi, return false);
	
	memset(bi, 0, sizeof(BookInstance));
	
	return true;
}

bool bookinstance_borrow(BookInstance *bi, char *studentNo)
{
	CHECK_BOOKINSTANCE(bi, return false);
	CHECK_PARAMETERS(studentNo == NULL || strlen(studentNo) != LENGTH_STUDENT_NO-1, return false);
	
	if(bi->isBorrowed == true)
	{
		return false;
	}
	
	strncpy(bi->borrowedNo, studentNo, LENGTH_STUDENT_NO);
	bi->isBorrowed = true;
	
	return true;
}

bool bookinstance_return(BookInstance *bi)
{
	CHECK_BOOKINSTANCE(bi, return false);
	
	if(bi->isBorrowed == false)
	{
		return false;
	}
	
	bi->isBorrowed = false;
	strncpy(bi->borrowedNo, ON_SHELF_STRING, LENGTH_STUDENT_NO);
	
	return true;
}

bool bookinstance_print(BookInstance *bi)
{
	CHECK_BOOKINSTANCE(bi, return false);
	
	printf(	"BookInstance ISBN: %s\n"
			"BookInstance is Borrowed? %d\n"
			"BookInstance Borrowed Student No: %s\n"
			"BorrowInstance index: %d\n",
			bi->isbn, bi->isBorrowed, bi->borrowedNo, bi->instanceIndex
	);
	
	return true;
}

bool bookinstance_file_write(BookInstance *bi, FILE *fh)
{
	CHECK_BOOKINSTANCE(bi, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	fprintf(fh, "%.*s, %.*s\n",
		LENGTH_ISBN-1, bi->isbn, LENGTH_STUDENT_NO-1, (bi->isBorrowed == false) ? ON_SHELF_STRING : bi->borrowedNo);
	
	return true;
}

bool bookinstance_file_read(BookInstance *bi, FILE *fh)
{
	bool isValid = false;
	char formatBuff[BOOKINSTANCE_STR_BUFFER_LEN] = {'\0'};
	
	CHECK_PARAMETERS(bi == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	sprintf(formatBuff, "%%%d[^,], %%%d[^\n]\n", LENGTH_ISBN-1, LENGTH_STUDENT_NO-1);
	
	isValid = fscanf(fh, formatBuff, bi->isbn, bi->borrowedNo) == 2;
	
	if(strncmp(bi->borrowedNo, ON_SHELF_STRING, LENGTH_STUDENT_NO-1))
	{
		bi->isBorrowed = true;
	}
	
	bi->instanceIndex = atoi(bi->isbn + LENGTH_MIN_ISBN+1);
	
	return isValid;
}


/***************************************************************/
/*                        BOOK FUNCTIONS                       */
/***************************************************************/

Book *book_create(char *name, char *isbn)
{
	Book *b = NULL;
	
	b = (Book*)malloc(sizeof(Book));
	CHECK_ALLOCATION(b, return NULL);
	
	memset(b, 0, sizeof(Book));
	
	if(isbn != NULL)
	{
		size_t length = strlen(isbn);
		if(length < LENGTH_MIN_ISBN || length >= LENGTH_ISBN)
		{
			return NULL;
		}
		strncpy(b->isbn, isbn, LENGTH_ISBN);
	}
	
	if(name != NULL)
	{
		strncpy(b->name, name, LENGTH_NAME);
	}
	
	return b;
}

bool book_delete(Book *b)
{
	CHECK_BOOK(b, return false);
	
	if(b->bi != NULL)
	{
		free(b->bi);
	}
	free(b);
	
	return true;
}

bool book_update(Book *b, char *name, char *isbn)
{
	int i = 0;
	
	CHECK_BOOK(b, return false);
	
	if(isbn != NULL)
	{
		size_t length = strlen(isbn);
		if(length < LENGTH_MIN_ISBN || length >= LENGTH_ISBN)
		{
			return false;
		}
		strncpy(b->isbn, isbn, LENGTH_ISBN);
	}
	
	if(name != NULL)
	{
		strncpy(b->name, name, LENGTH_NAME);
	}
	
	for(i = 0; i < b->instanceCount; i++)
	{
		memcpy(b->bi[i].isbn, isbn, sizeof(char) * LENGTH_MIN_ISBN);
	}
	
	
	return true;
}

bool book_add_instance(Book *b, int addedInstanceCount)
{
	int i = 0, index = 0;
	BookInstance *bi = NULL;
	
	CHECK_BOOK(b, return false);
	CHECK_PARAMETERS(addedInstanceCount < 0, return false);
	
	if(addedInstanceCount == 0)
	{
		return true;
	}
	
	if(b->bi == NULL)
	{
		bi = (BookInstance*)malloc(addedInstanceCount * sizeof(BookInstance));
	}
	else
	{
		bi = (BookInstance*)realloc(b->bi, (b->instanceCount + addedInstanceCount) * sizeof(BookInstance));
	}
	
	CHECK_ALLOCATION(bi, return false);
	
	index = book_get_max_instance_index(b);
	
	for(i = b->instanceCount; i < b->instanceCount + addedInstanceCount; i++)
	{
		index++;
		bookinstance_init(&bi[i], b->isbn, index, false, NULL);
	}
	
	b->bi = bi;
	b->instanceCount += addedInstanceCount;
	
	return true;
}

bool book_remove_instance(Book *b, int index)
{
	BookInstance *bi = NULL;
	
	CHECK_BOOK(b, return false);
	CHECK_PARAMETERS(index < 0, return false);
	
	if(index >= b->instanceCount)
	{
		return false;
	}
	
	memmove(&b->bi[index], &b->bi[index+1], (b->instanceCount-1 - index) * sizeof(BookInstance));
	
	if(b->instanceCount == 1)
	{
		bookinstance_deinit(&b->bi[0]);
		free(b->bi);
		b->bi = NULL;
		b->instanceCount = 0;
	}
	else
	{
		bi = (BookInstance*)realloc(b->bi, (b->instanceCount-1) * sizeof(BookInstance));
		CHECK_ALLOCATION(bi, return false);
		
		b->bi = bi;
		b->instanceCount--;
	}
	
	
	return true;
}

bool book_is_same_name(Book *b, char *name)
{
	CHECK_BOOK(b, return false);
	CHECK_PARAMETERS(name == NULL, return false);
	
	return !strncmp(b->name, name, LENGTH_NAME);
}

bool book_is_same_isbn(Book *b, char *isbn)
{
	CHECK_BOOK(b, return false);
	CHECK_PARAMETERS(isbn == NULL, return false);
	
	return !strncmp(b->isbn, isbn, LENGTH_ISBN);
}

int book_get_max_instance_index(Book *b)
{
	int i = 0, maxIndex = 0;
	
	CHECK_BOOK(b, return NOT_EXIST);
	
	for(i = 0; i < b->instanceCount; i++)
	{
		maxIndex = MAX(b->bi[i].instanceIndex, maxIndex);
	}
	
	return maxIndex;
}

int book_find_instance(Book *b)
{
	int i = 0;
	
	CHECK_BOOK(b, return NOT_EXIST);
	
	for(i = 0; i < b->instanceCount; i++)
	{
		if(b->bi[i].isBorrowed == false)
		{
			return i;
		}
	}
	
	return NOT_EXIST;
}

int book_find_instance_by_isbn(Book *b, char *longIsbn)
{
	int i = 0;
	
	CHECK_BOOK(b, return NOT_EXIST);
	CHECK_PARAMETERS(longIsbn == false, return false);
	
	for(i = 0; i < b->instanceCount; i++)
	{
		if(!strncmp(b->bi[i].isbn, longIsbn, LENGTH_ISBN))
		{
			return i;
		}
	}
	
	return NOT_EXIST;
}

bool book_print(Book *b)
{
	CHECK_BOOK(b, return false);
	
	printf(	"Book ISBN: %s\n"
			"Book Name: %s\n"
			"Book Instance Count: %d\n",
			b->isbn, b->name, b->instanceCount
	);
	
	return true;
}

bool book_is_borrowed(Book *b)
{
	int i = 0;
	
	CHECK_BOOK(b, return false);
	
	for(i = 0; i < b->instanceCount; i++)
	{
		if(b->bi[i].isBorrowed)
		{
			return true;
		}
	}
	
	return false;
}

bool book_file_write(Book *b, FILE *fh)
{
	CHECK_BOOK(b, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	fprintf(fh, "%.*s, %.*s, %d\n",
		LENGTH_NAME-1, b->name, LENGTH_ISBN-1, b->isbn, b->instanceCount);
	
	return true;
}

bool book_file_read(Book *b, FILE *fh)
{
	int instanceCount = 0;
	bool isValidInput = false;
	char buff[BOOK_STR_BUFFER_LEN] = {'\0'};
	
	CHECK_PARAMETERS(b == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	sprintf(buff, "%%%d[^,], %%%d[^,], %%d\n", LENGTH_NAME-1, LENGTH_ISBN-1);
	
	isValidInput = fscanf(fh, buff, b->name, b->isbn, &instanceCount) == 3;
	
	if(isValidInput)
	{
		b->bi = NULL;
		b->instanceCount = 0;
		
		return true;
	}
	
	return false;
}

bool book_file_write_all_instances(Book *b, FILE *fh)
{
	int i = 0;
	
	CHECK_BOOK(b, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	for(i = 0; i < b->instanceCount; i++)
	{
		if(bookinstance_file_write(&b->bi[i], fh) == false)
		{
			return false;
		}
	}
	
	return true;
}


/***************************************************************/
/*                      BOOKLIST FUNCTIONS                     */
/***************************************************************/

bool booklist_init(BookList *blst)
{
	CHECK_PARAMETERS(blst == NULL, return false);
	
	memset(blst, 0, sizeof(BookList));
	
	return true;
}

bool booklist_deinit(BookList *blst)
{
	Book *node = NULL;
	
	CHECK_BOOKLIST(blst, return false);
	
	node = blst->head;
	while(node != NULL)
	{
		Book *tempNode = node->next;
		
		book_delete(node);
		
		node = tempNode;
	}
	
	memset(blst, 0, sizeof(BookList));
	
	
	return true;
}

bool booklist_update_student_no(BookList *blst, char *oldStudentNo, char *newStudentNo)
{
	Book *node = NULL;
	
	CHECK_BOOKLIST(blst, return false);
	CHECK_PARAMETERS(oldStudentNo == NULL || newStudentNo == NULL, return false);
	
	while(node != NULL)
	{
		int i = 0;
		
		for(i = 0; i < node->instanceCount; i++)
		{
			if(!strncmp(node->bi[i].borrowedNo, oldStudentNo, LENGTH_STUDENT_NO))
			{
				strncpy(node->bi[i].borrowedNo, newStudentNo, LENGTH_STUDENT_NO);
			}
		}
		
		node = node->next;
	}
	
	return true;
}

bool booklist_add(BookList *blst, Book *b)
{
	Book dummy = {0};
	Book *node = NULL;
	bool isContinue = true;
	bool isSameName = false;
	
	CHECK_BOOKLIST(blst, return false);
	CHECK_BOOK(b, return false);
	
	if(blst->head == NULL)
	{
		blst->head = b;
		blst->tail = b;
	}
	else
	{
		Book *tempNode = NULL;
		dummy.next = blst->head;
		node = &dummy;
		while(node->next != NULL && isContinue == true)
		{
			int retVal = strncmp(node->next->name, b->name, LENGTH_NAME);
			if(retVal >= 0)
			{
				isSameName = retVal == 0;
				isContinue = false;
			}
			else
			{
				node = node->next;
			}
		}
		
		if(isSameName == true) /* add as isbn */
		{
			isContinue = true;
			while(node->next != NULL && isContinue == true)
			{
				if(strncmp(node->next->name, b->name, LENGTH_NAME))
				{
					isContinue = false;
				}
				else
				{
					int retVal = strncmp(node->next->isbn, b->isbn, LENGTH_ISBN);
					if(retVal < 0)
					{
						isContinue = false;
					}
					else
					{
						node = node->next;
					}
				}
			}
		}
		
		if(node == &dummy)
		{
			blst->head = b;
		}
		else if(node->next == NULL)
		{
			blst->tail = b;
		}
		
		tempNode = node->next;
		node->next = b;
		b->next = tempNode;
		
	}
	
	blst->count++;
	
	return true;
}

bool booklist_remove(BookList *blst, Book *b)
{
	Book *node = NULL;
	
	CHECK_BOOKLIST(blst, return false);
	CHECK_BOOK(b, return false);
	
	if(blst->head == b)
	{
		blst->head = blst->head->next;
		if(blst->head == NULL)
		{
			blst->tail = NULL;
		}
		book_delete(b);
		blst->count--;
		
		return true;
	}
	
	node = blst->head;
	while(node->next != NULL)
	{
		if(node->next == b)
		{
			if(node->next == blst->tail)
			{
				blst->tail = node;
			}
			node->next = node->next->next;
			book_delete(b);
			blst->count--;
			
			return true;
		}
		
		node = node->next;
	}
	
	return false;
}

Book *booklist_find_by(BookList *blst, char *arg, bool (*is_same)(Book *b, char *arg))
{
	Book *node = NULL;
	
	CHECK_BOOKLIST(blst, return NULL);
	CHECK_PARAMETERS(is_same == NULL, return NULL);
	
	node = blst->head;
	while(node != NULL)
	{
		if(is_same(node, arg))
		{
			return node;
		}
		node = node->next;
	}
	
	return NULL;	
}

bool booklist_print(BookList *blst)
{
	Book *node = NULL;
	
	CHECK_BOOKLIST(blst, return false);
	
	node = blst->head;
	while(node != NULL)
	{
		int i = 0;
		printf("=====================================\n");
		book_print(node);
		printf("\n");
		for(i = 0; i < node->instanceCount; i++)
		{
			bookinstance_print(&node->bi[i]);
			printf("\n");
		}
		node = node->next;
	}
	printf("=====================================\n");
	
	return true;
}

bool booklist_file_write(BookList *blst, char *booksFileName, char *booksInstanceFileName)
{
	FILE *booksHandle = NULL, *booksInstanceHandle = NULL;
	Book *node = NULL;
	
	CHECK_BOOKLIST(blst, return false);
	CHECK_PARAMETERS(booksFileName == NULL || booksInstanceFileName == NULL, return false);
	
	booksHandle = fopen(booksFileName, "w");
	CHECK_OPERATION_SUCCESS(booksHandle, return false);
	
	booksInstanceHandle = fopen(booksInstanceFileName, "w");
	CHECK_OPERATION_SUCCESS(booksInstanceHandle, fclose(booksHandle); return false);
	
	node = blst->head;
	while(node != NULL)
	{
		if(book_file_write(node, booksHandle) == false || book_file_write_all_instances(node, booksInstanceHandle) == false)
		{
			fclose(booksHandle);
			fclose(booksInstanceHandle);
			return false;
		}
		node = node->next;
	}
	
	fclose(booksHandle);
	fclose(booksInstanceHandle);
	return true;
}

bool booklist_file_read(BookList *blst, char *booksFileName, char *booksInstenceFileName)
{
	
	FILE *booksHandle = NULL, *booksInstanceHandle = NULL;
	Book *b = NULL;
	bool isContinue = true;
	
	CHECK_BOOKLIST(blst, return false);
	CHECK_PARAMETERS(booksFileName == NULL || booksInstenceFileName == NULL, return false);
	
	booksHandle = fopen(booksFileName, "r");
	CHECK_OPERATION_SUCCESS(booksHandle, return false);
	
	do
	{
		b = book_create(NULL, NULL);
		CHECK_OPERATION_SUCCESS(b, fclose(booksHandle); return false);
		
		if(book_file_read(b, booksHandle) == true)
		{
			booklist_add(blst, b);
		}
		else
		{
			book_delete(b);
			isContinue = false;
		}
		
	}while(isContinue);
	
	fclose(booksHandle);
	
	booksInstanceHandle = fopen(booksInstenceFileName, "r");
	CHECK_OPERATION_SUCCESS(booksInstanceHandle, return false);
	
	isContinue = true;
	do
	{
		BookInstance bi = {0};
		bookinstance_init(&bi, NULL, 0, false, NULL);
		
		if(bookinstance_file_read(&bi, booksInstanceHandle) == true)
		{
			bool isFound = false;
			b = blst->head;
			while(b != NULL && isFound == false)
			{
				if(!strncmp(b->isbn, bi.isbn, LENGTH_MIN_ISBN))
				{
					book_add_instance(b, 1);
					b->bi[b->instanceCount-1] = bi;
					isFound = true;
				}
				b = b->next;
			}
			if(isFound == false)
			{
				fprintf(stderr, "Book for %s not found\n", bi.isbn);
			}
		}
		else
		{
			bookinstance_deinit(&bi);
			isContinue = false;
		}
		
	}while(isContinue);
	
	return true;	
}



/***************************************************************/
/*                     BOOKAUTHOR FUNCTIONS                    */
/***************************************************************/

bool bookauthor_init(BookAuthor *ba, char *isbn, int authorId)
{
	CHECK_PARAMETERS(ba == NULL, return false);
	
	memset(ba, 0, sizeof(BookAuthor));
	
	if(isbn != NULL)
	{
		strncpy(ba->isbn, isbn, LENGTH_MIN_ISBN);
		ba->isbn[LENGTH_MIN_ISBN] = '\0';
	}
	ba->authorId = authorId;
	
	return true;
}

bool bookauthor_deinit(BookAuthor *ba)
{
	CHECK_BOOKAUTHOR(ba, return false);
	
	memset(ba, 0, sizeof(BookAuthor));
	
	return true;
}

bool bookauthor_update(BookAuthor *ba, char *isbn, int authorId)
{
	return bookauthor_init(ba, isbn, authorId);
}

bool bookauthor_print(BookAuthor *ba)
{
	CHECK_BOOKAUTHOR(ba, return false);
	
	printf(	"Book ISBN: %s\n"
			"Author ID: %d\n",
			ba->isbn, ba->authorId
	);
	
	return true;
}

bool bookauthor_file_write(BookAuthor *ba, FILE *fh)
{
	CHECK_BOOKAUTHOR(ba, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	fwrite(ba, sizeof(BookAuthor), 1, fh);
	
	return true;
}

bool bookauthor_file_read(BookAuthor *ba, FILE *fh)
{
	CHECK_PARAMETERS(ba == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	return fread(ba, sizeof(BookAuthor), 1, fh) == 1;
}


/***************************************************************/
/*                   BOOKAUTHORLIST FUNCTIONS                  */
/***************************************************************/

bool bookauthorlist_init(BookAuthorList *balst)
{
	CHECK_PARAMETERS(balst == NULL, return false);
	
	memset(balst, 0, sizeof(BookAuthorList));
	
	return true;
}

bool bookauthorlist_deinit(BookAuthorList *balst)
{
	CHECK_BOOKAUTHORLIST(balst, return false);
	
	if(balst->data != NULL)
	{
		free(balst->data);
	}
	
	memset(balst, 0, sizeof(BookAuthorList));
	
	return true;
}

bool bookauthorlist_remove_isbn(BookAuthorList *balst, char *isbn)
{
	int i = 0;
	
	CHECK_BOOKAUTHORLIST(balst, return false);
	CHECK_PARAMETERS(isbn == NULL || strlen(isbn) != LENGTH_MIN_ISBN, return false);
	
	for(i = 0; i < balst->count; i++)
	{
		if(!strncmp(balst->data[i].isbn, isbn, LENGTH_MIN_ISBN))
		{
			bookauthorlist_remove_at(balst, i);
			i--;
		}
	}
	
	return true;
}

bool bookauthorlist_update_isbn(BookAuthorList *balst, char *oldIsbn, char *newIsbn)
{
	int i = 0;
	
	CHECK_BOOKAUTHORLIST(balst, return false);
	CHECK_PARAMETERS(oldIsbn == NULL || newIsbn == NULL || strlen(oldIsbn) != LENGTH_MIN_ISBN || strlen(newIsbn) != LENGTH_MIN_ISBN, return false);
	
	for(i = 0; i < balst->count; i++)
	{
		if(!strncmp(balst->data[i].isbn, oldIsbn, LENGTH_MIN_ISBN))
		{
			strncpy(balst->data[i].isbn, newIsbn, LENGTH_MIN_ISBN);
		}
	}
	
	return true;
}

bool bookauthorlist_update_id(BookAuthorList *balst, int oldId, int newId)
{
	int i = 0;
	
	CHECK_BOOKAUTHORLIST(balst, return false);
	
	for(i = 0; i < balst->count; i++)
	{
		if(balst->data[i].authorId == oldId)
		{
			balst->data[i].authorId = newId;
		}
	}
	
	return true;
}

bool bookauthorlist_print(BookAuthorList *balst)
{
	int i = 0;
	
	CHECK_BOOKAUTHORLIST(balst, return false);
	
	for(i = 0; i < balst->count; i++)
	{
		printf("=====================================\n");
		bookauthor_print(&balst->data[i]);
	}
	printf("=====================================\n");
	
	return true;
}

bool bookauthorlist_add_back(BookAuthorList *balst, BookAuthor *ba)
{
	BookAuthor *temp = NULL;
	
	CHECK_BOOKAUTHORLIST(balst, return false);
	CHECK_BOOKAUTHOR(ba, return false);
	
	if(balst->data == NULL)
	{
		temp = (BookAuthor*)malloc(sizeof(BookAuthor));
	}
	else
	{
		temp = (BookAuthor*)realloc(balst->data, (balst->count+1) * sizeof(BookAuthor));
	}
	
	CHECK_ALLOCATION(temp, return false);
	
	memset(&temp[balst->count], 0, sizeof(BookAuthor));
	
	strncpy(temp[balst->count].isbn, ba->isbn, LENGTH_MIN_ISBN+1);
	temp[balst->count].authorId = ba->authorId;
	
	balst->data = temp;
	balst->count++;
		
	return true;
}

int bookauthorlist_find(BookAuthorList *balst, char *isbn, int authorId)
{
	int i = 0;
	
	CHECK_BOOKAUTHORLIST(balst, return NOT_EXIST);
	CHECK_PARAMETERS(isbn == NULL, return NOT_EXIST);
	
	for(i = 0; i < balst->count; i++)
	{
		if(balst->data[i].authorId == authorId && !strncmp(balst->data[i].isbn, isbn, LENGTH_ISBN))
		{
			return i;
		}
	}
	
	return NOT_EXIST;
}

bool bookauthorlist_remove_at(BookAuthorList *balst, int index)
{
	CHECK_BOOKAUTHORLIST(balst, return false);
	CHECK_PARAMETERS(index < 0 || index >= balst->count, return false);
	
	if(bookauthor_deinit(&balst->data[index]) == false)
	{
		return false;
	}
	
	memmove(&balst->data[index], &balst->data[index+1], (balst->count-1 - index) * sizeof(BookAuthor));	
	memset(&balst->data[balst->count-1], 0, sizeof(BookAuthor));
	
	balst->count--;
	
	return true;
}

bool bookauthorlist_file_write(BookAuthorList *balst, char *fileName)
{
	FILE *f = NULL;
	int i = 0;
	
	CHECK_BOOKAUTHORLIST(balst, return false);
	CHECK_PARAMETERS(fileName == NULL, return false);
	
	f = fopen(fileName, "wb");
	CHECK_OPERATION_SUCCESS(f, return false);
	
	for(i = 0; i < balst->count; i++)
	{
		if(bookauthor_file_write(&balst->data[i], f) == false)
		{
			fclose(f);
			return false;
		}
	}
	
	fclose(f);
	
	return true;
}

bool bookauthorlist_file_read(BookAuthorList *balst, char *fileName)
{
	FILE *f = NULL;
	bool isContinue = true;
	
	CHECK_BOOKAUTHORLIST(balst, return false);
	CHECK_PARAMETERS(fileName == NULL, return false);
	
	f = fopen(fileName, "rb");
	CHECK_OPERATION_SUCCESS(f, return false);
	
	do
	{
		BookAuthor ba = {0};
		bookauthor_init(&ba, NULL, 0);
		
		if(bookauthor_file_read(&ba, f) == true)
		{
			bookauthorlist_add_back(balst, &ba);
		}
		else
		{
			bookauthor_deinit(&ba);
			isContinue = false;
		}
		
	}while(isContinue);
	
	fclose(f);
	
	return true;	
}



/***************************************************************/
/*                       BORROW FUNCTIONS                      */
/***************************************************************/

bool borrow_init(Borrow *br, char *isbn, char *studentNo, BorrowType type, OperationDate date)
{
	CHECK_PARAMETERS(br == NULL, return false);
	
	memset(br, 0, sizeof(BookAuthor));
	
	if(isbn != NULL)
	{
		strncpy(br->isbn, isbn, LENGTH_ISBN);
	}
	if(studentNo != NULL)
	{
		strncpy(br->studentNo, studentNo, LENGTH_STUDENT_NO);
	}
	
	br->type = type;
	br->date = date;
	
	return true;
}

bool borrow_deinit(Borrow *br)
{
	CHECK_BORROW(br, return false);
	
	memset(br, 0, sizeof(BookAuthor));
	
	return true;
}

bool borrow_print(Borrow *br)
{
	CHECK_BORROW(br, return false);
	
	printf(	"Book ISBN: %s\n"
			"Student No: %s\n"
			"Operation Type: %s\n"
			"Operation Date: %d.%d.%d\n",
			br->isbn, br->studentNo, br->type == BOOK_BORROW ? "Borrowed" : "Delivered", br->date.day, br->date.month, br->date.year
	);
	
	return true;
}

bool borrow_file_write(Borrow *br, FILE *fh)
{
	CHECK_BORROW(br, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	return fprintf(fh, "%s, %s, %d, %d.%d.%d\n",
			br->isbn, br->studentNo, br->type, br->date.day, br->date.month, br->date.year) != 0;
}

bool borrow_file_read(Borrow *br, FILE *fh)
{
	bool isValid = false;
	char formatBuffer[BORROW_STR_BUFFER_LEN] = {0};
	int tempDate = 0, tempMonth = 0, tempYear = 0;
	
	CHECK_PARAMETERS(br == NULL, return false);
	CHECK_PARAMETERS(fh == NULL, return false);
	
	sprintf(formatBuffer, "%%%d[^,], %%%d[^,], %%d, %%d.%%d.%%d\n", LENGTH_ISBN-1, LENGTH_STUDENT_NO-1);
	
	isValid = fscanf(fh, formatBuffer, br->isbn, br->studentNo, &br->type, &tempDate, &tempMonth, &tempYear) ==  6;
	
	if(isValid)
	{
		br->date.day = tempDate;
		br->date.month = tempMonth;
		br->date.year = tempYear;
	}
	
	return isValid;
}


/***************************************************************/
/*                     BORROWLIST FUNCTIONS                    */
/***************************************************************/

bool borrowlist_init(BorrowList *brlst)
{
	CHECK_PARAMETERS(brlst == NULL, return false);
	
	memset(brlst, 0, sizeof(BorrowList));
	
	return true;
}

bool borrowlist_deinit(BorrowList *brlst)
{
	CHECK_BORROWLIST(brlst, return false);
	
	if(brlst->data != NULL)
	{
		free(brlst->data);
	}
	
	memset(brlst, 0, sizeof(BorrowList));
	
	return true;
}

bool borrowlist_print(BorrowList *brlst)
{
	int i = 0;
	
	CHECK_BORROWLIST(brlst, return false);
	
	for(i = 0; i < brlst->count; i++)
	{
		printf("=====================================\n");
		borrow_print(&brlst->data[i]);
	}
	printf("=====================================\n");
	
	return true;
}

bool borrowlist_add_back(BorrowList *brlst, Borrow *br)
{
	Borrow *temp = NULL;
	
	CHECK_BORROWLIST(brlst, return false);
	CHECK_BORROW(br, return false);
	
	if(brlst->data == NULL)
	{
		temp = (Borrow*)malloc(sizeof(Borrow));
	}
	else
	{
		temp = (Borrow*)realloc(brlst->data, (brlst->count+1) * sizeof(Borrow));
	}
	
	CHECK_ALLOCATION(temp, return false);
	
	strncpy(temp[brlst->count].isbn, br->isbn, LENGTH_ISBN);
	strncpy(temp[brlst->count].studentNo, br->studentNo, LENGTH_STUDENT_NO);
	temp[brlst->count].type = br->type;
	temp[brlst->count].date = br->date;
	
	brlst->data = temp;
	brlst->count++;
		
	return true;
}

bool borrowlist_update_student_no(BorrowList *brlst, char *oldStudentNo, char *newStudentNo)
{
	int i = 0;
	
	CHECK_BORROWLIST(brlst, return false);
	CHECK_PARAMETERS(oldStudentNo == NULL || newStudentNo == NULL, return false);
	
	for(i = 0; i < brlst->count; i++)
	{
		if(!strncmp(brlst->data[i].studentNo, oldStudentNo, LENGTH_STUDENT_NO))
		{
			strncpy(brlst->data[i].studentNo, newStudentNo, LENGTH_STUDENT_NO);
		}
	}
	
	return true;
}

int borrowlist_find(BorrowList *brlst, char *isbn, char *studentNo, BorrowType type)
{
	int i = 0;
	
	CHECK_BORROWLIST(brlst, return NOT_EXIST);
	CHECK_PARAMETERS(isbn == NULL || studentNo == NULL, return NOT_EXIST);
	
	/* search from last to first */
	for(i = brlst->count - 1; i >= 0; i--)
	{
		if(!strncmp(brlst->data[i].isbn, isbn, LENGTH_ISBN) &&
			!strncmp(brlst->data[i].studentNo, studentNo, LENGTH_STUDENT_NO) &&
			brlst->data[i].type == type
		)
		{
			return i;
		}
	}
	
	return NOT_EXIST;
}

bool borrowlist_file_write(BorrowList *brlst, char *fileName)
{
	FILE *f = NULL;
	int i = 0;
	
	CHECK_BORROWLIST(brlst, return false);
	CHECK_PARAMETERS(fileName == NULL, return false);
	
	f = fopen(fileName, "w");
	CHECK_OPERATION_SUCCESS(f, return false);
	
	for(i = 0; i < brlst->count; i++)
	{
		if(borrow_file_write(&brlst->data[i], f) == false)
		{
			fclose(f);
			return false;
		}
	}
	
	fclose(f);
	
	return true;
}

bool borrowlist_file_read(BorrowList *brlst, char *fileName)
{
	FILE *f = NULL;
	bool isContinue = true;
	
	CHECK_BORROWLIST(brlst, return false);
	CHECK_PARAMETERS(fileName == NULL, return false);
	
	f = fopen(fileName, "r");
	CHECK_OPERATION_SUCCESS(f, return false);
	
	do
	{
		Borrow br = {0};
		OperationDate od = {0};
		borrow_init(&br, NULL, NULL, 0, od);
		
		if(borrow_file_read(&br, f) == true)
		{
			borrowlist_add_back(brlst, &br);
		}
		else
		{
			borrow_deinit(&br);
			isContinue = false;
		}
		
	}while(isContinue);
	
	fclose(f);
	
	return true;	
}



/***************************************************************/
/*                    MENU HELPER FUNCTIONS                    */
/***************************************************************/

bool mh_student_filter_nothing(ListOfLists *lst, Student *s)
{
	CHECK_LISTOFLISTS(lst, return false);
	CHECK_STUDENT(s, return false);
	return true;
}

bool mh_student_filter_not_returned_book(ListOfLists *lst, Student *s)
{
	int i = 0;
	int returnCount = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	CHECK_STUDENT(s, return false);
	
	/* not ideal detection mechanism */
	for(i = 0; i < lst->brlst.count; i++)
	{
		if(!strncmp(lst->brlst.data[i].studentNo, s->no, LENGTH_STUDENT_NO))
		{
			if(lst->brlst.data[i].type == BOOK_BORROW)
			{
				returnCount--;
			}
			else if(lst->brlst.data[i].type == BOOK_DELIVER)
			{
				returnCount++;
			}
		}
	}
	
	if(returnCount < 0)
	{
		return true;
	}
	else if(returnCount == 0)
	{
		return false;
	}
	
	assert(!"Data's changed outside of program");
	return false;
}

bool mh_student_filter_penalized(ListOfLists *lst, Student *s)
{
	CHECK_LISTOFLISTS(lst, return false);
	CHECK_STUDENT(s, return false);
	
	return s->score < INITIAL_STUDENT_SCORE;
}

bool mh_student_print_filter(ListOfLists *lst, bool (*filter)(ListOfLists *lst, Student *s))
{
	int i = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	CHECK_PARAMETERS(filter == NULL, return false);
	
	for(i = 0; i < lst->slst.size; i++)
	{
		if(filter(lst, &lst->slst.data[i]))
		{
			printf("=====================================\n");
			student_print(&lst->slst.data[i]);
		}
	}
	printf("=====================================\n");
	
	return true;
}


bool mh_book_filter_on_shelf(ListOfLists *lst, BookInstance *bi)
{
	CHECK_LISTOFLISTS(lst, return false);
	CHECK_BOOKINSTANCE(bi, return false);
	
	return bi->isBorrowed == false;
}

bool mh_book_not_returned_on_time(ListOfLists *lst, BookInstance *bi)
{
	BorrowList *brlst = NULL;
	Borrow *borrow = NULL, *returned = NULL;
	int i = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	CHECK_BOOKINSTANCE(bi, return false);
	
	brlst = &lst->brlst;
	
	for(i = 0; i < brlst->count; i++)
	{
		if(!strncmp(brlst->data[i].isbn, bi->isbn, LENGTH_ISBN))
		{
			if(brlst->data[i].type == BOOK_BORROW)
			{
				borrow = &brlst->data[i];
			}
			else if(brlst->data[i].type == BOOK_DELIVER)
			{
				returned = &brlst->data[i];
			}
			else
			{
				fprintf(stderr, "Type of %s is invalid\n", bi->isbn);
			}
		}
		
		if(borrow != NULL && returned != NULL)
		{
			if(diffDay(borrow->date, returned->date) >= BOOK_BORROW_THRESHOLD)
			{
				return true;
			}
		}
		
	}
	
	return false;	
}

bool mh_book_print_filter(ListOfLists *lst, bool (*filter)(ListOfLists *lst, BookInstance *bi))
{
	int i = 0;
	Book *node = NULL;
	
	CHECK_LISTOFLISTS(lst, return false);
	CHECK_PARAMETERS(filter == NULL, return false);
	
	node = lst->blst.head;
	while(node != NULL)
	{
		for(i = 0; i < node->instanceCount; i++)
		{
			if(filter(lst, &node->bi[i]))
			{
				printf("=====================================\n");
				printf("Book Name: %s\n", node->name);
				bookinstance_print(&node->bi[i]);
			}
		}
		node = node->next;
	}
	printf("=====================================\n");
	
	return true;
}

bool mh_author_sync_book(ListOfLists *lst)
{
	int i = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	for(i = 0; i < lst->balst.count; i++)
	{
		if(booklist_find_by(&lst->blst, lst->balst.data[i].isbn, book_is_same_isbn) == NULL) /* book removed */
		{
			bookauthorlist_remove_at(&lst->balst, i);
			i--;
		}
		else if(authorlist_check_author_exist(&lst->alst, lst->balst.data[i].authorId) == false) /* author removed */
		{
			bookauthorlist_update_id(&lst->balst, lst->balst.data[i].authorId, -1);
		}
	}
	
	
	return true;
}

/***************************************************************/
/*                        MENU FUNCTIONS                       */
/***************************************************************/

bool menu_students_add(ListOfLists *lst)
{
	Student s = {0};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	student_init(&s, NULL, NULL, NULL);
	
	get_student_no_input(s.no, "Enter Student No: ");
	get_string_input(s.name, LENGTH_NAME, "Enter name (max %d character): ", LENGTH_NAME-1);
	get_string_input(s.surname, LENGTH_SURNAME, "Enter surname (max %d character): ", LENGTH_SURNAME-1);
	
	if(studentlist_add_back(&lst->slst, &s) == false)
	{
		return false;
	}
	
	return studentlist_file_write(&lst->slst, FILENAME_STUDENTS);
}

bool menu_students_delete(ListOfLists *lst)
{
	int index = 0;
	char no[LENGTH_STUDENT_NO] = {'\0'};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_student_no_input(no, "Enter student number you want to delete: ");
	
	index = studentlist_find(&lst->slst, no);
	if(index == NOT_EXIST)
	{
		fprintf(stderr, "Student %s not found\n", no);
		return false;
	}
	
	if(mh_student_filter_not_returned_book(lst, &lst->slst.data[index]) == true)
	{
		fprintf(stderr, "can not delete student because of unreturned books.\n");
		return false;
	}
		
	if(studentlist_remove_at(&lst->slst, index))
	{
		return studentlist_file_write(&lst->slst, FILENAME_STUDENTS);
	}
	return false;
	
}

bool menu_students_update(ListOfLists *lst)
{
	int index = 0;
	char no[LENGTH_STUDENT_NO] = {'\0'};
	char newNo[LENGTH_STUDENT_NO] = {'\0'}, newName[LENGTH_NAME] = {'\0'}, newSurname[LENGTH_SURNAME] = {'\0'};
	int newScore = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_student_no_input(no, "Enter student number you want to update: ");
	
	index = studentlist_find(&lst->slst, no);
	if(index == NOT_EXIST)
	{
		fprintf(stderr, "Student %s not found\n", no);
		return false;
	}
	
	get_student_no_input(newNo, "Enter new student number: ");
	get_string_input(newName, LENGTH_NAME, "Enter new name: ");
	get_string_input(newSurname, LENGTH_SURNAME, "Enter new surname: ");
	newScore = get_integer_input(0, INITIAL_STUDENT_SCORE, "Enter new score: ");
	
	if(student_update(&lst->slst.data[index], newNo, newName, newSurname, newScore) == false)
	{
		fprintf(stderr, "Updating student failed\n");
		return false;
	}
	
	if(borrowlist_update_student_no(&lst->brlst, no, newNo) == false)
	{
		fprintf(stderr, "Updating borrowlist failed\n");
		return false;
	}
	
	if(booklist_update_student_no(&lst->blst, no, newNo) == false)
	{
		fprintf(stderr, "Updating booklist failed\n");
		return false;
	}
	
	if(booklist_file_write(&lst->blst, FILENAME_BOOKS, FILENAME_BOOKSINSTANCE) == false ||
		borrowlist_file_write(&lst->brlst, FILENAME_BOOKBORROWING) == false ||
		studentlist_file_write(&lst->slst, FILENAME_STUDENTS) == false
	)
	{
		fprintf(stderr, "Writing to files failed\n");
		return false;
	}
	
	return true;
	
}

bool menu_students_display(ListOfLists *lst)
{
	int index = 0, i = 0;
	char no[LENGTH_STUDENT_NO] = {'\0'};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_student_no_input(no, "Enter student number you want to display informations: ");
	
	index = studentlist_find(&lst->slst, no);
	if(index == NOT_EXIST)
	{
		fprintf(stderr, "Student %s not found\n", no);
		return false;
	}
	
	printf("=====================================\n");
	student_print(&lst->slst.data[index]);
	
	for(i = 0; i < lst->brlst.count; i++)
	{
		printf("=====================================\n");
		if(!strncmp(lst->brlst.data[i].studentNo, lst->slst.data[index].no, LENGTH_STUDENT_NO))
		{
			borrow_print(&lst->brlst.data[i]);
		}
	}
	printf("=====================================\n");
	
	return true;
}

bool menu_students_not_returned_book(ListOfLists *lst)
{
	CHECK_LISTOFLISTS(lst, return false);
	return mh_student_print_filter(lst, mh_student_filter_not_returned_book);
}

bool menu_students_penalized(ListOfLists *lst)
{
	CHECK_LISTOFLISTS(lst, return false);
	return mh_student_print_filter(lst, mh_student_filter_penalized);
}

bool menu_students_list_all(ListOfLists *lst)
{
	CHECK_LISTOFLISTS(lst, return false);
	return mh_student_print_filter(lst, mh_student_filter_nothing);
}

bool menu_students_borrow_book(ListOfLists *lst)
{
	Student *s = NULL;
	Book *b = NULL;
	int index = 0;
	char no[LENGTH_STUDENT_NO] = {'\0'};
	char isbn[LENGTH_ISBN] = {'\0'}, minIsbn[LENGTH_MIN_ISBN+1] = {'\0'};
	OperationDate date = {0};
	Borrow br = {0};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_student_no_input(no, "Enter student number (length=%d): ", LENGTH_STUDENT_NO-1);
	
	index = studentlist_find(&lst->slst, no);
	if(index == NOT_EXIST)
	{
		fprintf(stderr, "Student %s not found\n", no);
		return false;
	}
	
	s = &lst->slst.data[index];
	
	if(s->score <= 0)
	{
		printf("Borrowing failed because of student's score <= 0\n");
		return false;
	}
	
	get_string_input(isbn, LENGTH_ISBN, "Enter ISBN of book instance: ");
	memcpy(minIsbn, isbn, LENGTH_MIN_ISBN);
	minIsbn[LENGTH_MIN_ISBN] = '\0';
	
	b = booklist_find_by(&lst->blst, minIsbn, book_is_same_isbn);
	if(b == NULL)
	{
		fprintf(stderr, "Book %s not found\n", isbn);
		return false;
	}
	
	index = book_find_instance_by_isbn(b, isbn);
	if(index == NOT_EXIST)
	{
		fprintf(stderr, "Book %s not found\n", isbn);
		return false;
	}
	if(b->bi[index].isBorrowed == true)
	{
		fprintf(stderr, "Book %s already borrowed\n", isbn);
		return false;
	}
	
	date = get_date_input("Enter date: \n");
	
	borrow_init(&br, isbn, no, BOOK_BORROW, date);
	
	if(borrowlist_add_back(&lst->brlst, &br) == false)
	{
		fprintf(stderr, "Adding borrowlist is failed\n");
		return false;
	}
	
	bookinstance_borrow(&b->bi[index], no);
	
	if(borrowlist_file_write(&lst->brlst, FILENAME_BOOKBORROWING) == false ||	
		booklist_file_write(&lst->blst, FILENAME_BOOKS, FILENAME_BOOKSINSTANCE) == false
	)
	{
		fprintf(stderr, "Writing to file is failed\n");
		return false;
	}
	
	return true;	
}

bool menu_students_return_book(ListOfLists *lst)
{
	Book *b = NULL;
	int studentIndex = 0, instanceIndex = 0, borrowIndex = 0;
	char no[LENGTH_STUDENT_NO] = {'\0'};
	char isbn[LENGTH_ISBN] = {'\0'};
	char minIsbn[LENGTH_MIN_ISBN+1] = {'\0'};
	OperationDate date = {0};
	Borrow br = {0};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_student_no_input(no, "Enter student number (length=%d): ", LENGTH_STUDENT_NO-1);
	
	studentIndex = studentlist_find(&lst->slst, no);
	if(studentIndex == NOT_EXIST)
	{
		fprintf(stderr, "Student %s not found\n", no);
		return false;
	}
	
	get_string_input(isbn, LENGTH_ISBN, "Enter ISBN of book instance: ");
	memcpy(minIsbn, isbn, LENGTH_MIN_ISBN);
	minIsbn[LENGTH_MIN_ISBN] = '\0';
	
	b = booklist_find_by(&lst->blst, minIsbn, book_is_same_isbn);
	if(b == NULL)
	{
		fprintf(stderr, "Book %s not found\n", minIsbn);
		return false;
	}
	
	instanceIndex = book_find_instance_by_isbn(b, isbn);
	if(instanceIndex == NOT_EXIST)
	{
		fprintf(stderr, "Instance %s not found\n", isbn);
		return false;
	}
	
	if(b->bi[instanceIndex].isBorrowed == false)
	{
		fprintf(stderr, "book already on shelf\n");
		return false;
	}
	
	borrowIndex = borrowlist_find(&lst->brlst, isbn, no, BOOK_BORROW);
	if(borrowIndex == NOT_EXIST)
	{
		fprintf(stderr, "Book did not borrowed\n");
		return false;
	}
	
	date = get_date_input("Enter date: \n");
	
	if(diffDay(lst->brlst.data[borrowIndex].date, date) >= BOOK_BORROW_THRESHOLD)
	{
		printf("Late return %d score for %s\n", BOOK_BORROW_SCORE, lst->slst.data[studentIndex].no);
		lst->slst.data[studentIndex].score += BOOK_BORROW_SCORE;
	}
	
	borrow_init(&br, isbn, no, BOOK_DELIVER, date);
	
	if(borrowlist_add_back(&lst->brlst, &br) == false)
	{
		fprintf(stderr, "Adding borrowlist is failed\n");
		return false;
	}
	
	bookinstance_return(&b->bi[instanceIndex]);
	
	if(borrowlist_file_write(&lst->brlst, FILENAME_BOOKBORROWING) == false ||	
		booklist_file_write(&lst->blst, FILENAME_BOOKS, FILENAME_BOOKSINSTANCE) == false ||
		studentlist_file_write(&lst->slst, FILENAME_STUDENTS) == false
	)
	{
		fprintf(stderr, "Writing to file is failed\n");
		return false;
	}
	
	return true;
}

bool menu_books_add(ListOfLists *lst)
{
	Book *b = NULL;
	char name[LENGTH_NAME] = {0}, isbn[LENGTH_ISBN] = {0};
	int instanceCount = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_string_input(name, LENGTH_NAME, "Enter book name: ");
	get_isbn_input(isbn, "Enter isbn of book: ");
	instanceCount = get_integer_input(1, INT_MAX, "Enter count of copy: ");
	
	b = book_create(name, isbn);
	if(b == NULL)
	{
		fprintf(stderr, "Creating book is falied\n");
		return false;
	}
	
	if(book_add_instance(b, instanceCount) == false)
	{
		fprintf(stderr, "Adding instance is failed\n");
		return false;
	}
	
	if(booklist_add(&lst->blst, b) == false)
	{
		fprintf(stderr, "Adding book to booklist is failed\n");
		return false;
	}
	
	if(booklist_file_write(&lst->blst, FILENAME_BOOKS, FILENAME_BOOKSINSTANCE) == false)
	{
		fprintf(stderr, "Writing to file is failed\n");
		return false;
	}
	
	return true;
}

bool menu_books_delete(ListOfLists *lst)
{
	Book *b = NULL;
	char isbn[LENGTH_ISBN] = {0};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_isbn_input(isbn, "Enter isbn of book you want to delete: ");
	
	b = booklist_find_by(&lst->blst, isbn, book_is_same_isbn);
	if(b == NULL)
	{
		fprintf(stderr, "Book %s not found\n", isbn);
		return false;
	}
	
	if(book_is_borrowed(b))
	{
		fprintf(stderr, "Book %s already borrowerd, so can not be deleted\n", isbn);
		return false;
	}
	
	if(booklist_remove(&lst->blst, b) == false)
	{
		fprintf(stderr, "Removing book %s failed\n", isbn);
		return false;
	}
	
	if(booklist_file_write(&lst->blst, FILENAME_BOOKS, FILENAME_BOOKSINSTANCE) == false)
	{
		fprintf(stderr, "Writing to file is failed\n");
		return false;
	}
	
	mh_author_sync_book(lst);
	
	if(bookauthorlist_file_write(&lst->balst, FILENAME_BOOKAUTHOR) == false)
	{
		fprintf(stderr, "Writing to BookAuthorList to file failed\n");
		return false;
	}
	
	
	return true;
}

bool menu_books_update(ListOfLists *lst)
{
	int i = 0;
	int yesNo = 0;
	Book *b = NULL;
	char isbn[LENGTH_ISBN] = {0};
	char newName[LENGTH_NAME] = {0}, newIsbn[LENGTH_ISBN] = {0};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_isbn_input(isbn, "Enter isbn of book you want to update: ");
	
	b = booklist_find_by(&lst->blst, isbn, book_is_same_isbn);
	if(b == NULL)
	{
		fprintf(stderr, "Book %s not found\n", isbn);
		return false;
	}
	
	get_string_input(newName, LENGTH_NAME, "Enter book new name: ");
	get_isbn_input(newIsbn, "Enter new isbn of book: ");
	
	book_update(b, newName, newIsbn);
	
	if(strncmp(isbn, newIsbn, LENGTH_MIN_ISBN) != 0)
	{
		bookauthorlist_update_isbn(&lst->balst, isbn, newIsbn);
	}
	
	for(i = 0; i < b->instanceCount; i++)
	{
		bookinstance_print(&b->bi[i]);
		yesNo = get_integer_input(0, 1, "Do you want to remove this instance (1 yes, 0 no): ");
		if(yesNo == 1)
		{
			if(b->bi[i].isBorrowed == true)
			{
				fprintf(stderr, "Instance can not delete because of its borrowed.\n");
			}
			else
			{
				if(book_remove_instance(b, i))
				{
					i--;
				}
				else
				{
					fprintf(stderr, "Removing instance failed\n");
				}
			}
		}
	}
	
	yesNo = get_integer_input(0, 1, "Do you want to add new instance (1 yes, 0 no): ");
	if(yesNo == 1)
	{
		int addedCount = 0;
		addedCount = get_integer_input(1, INT_MAX, "Enter new created instance count: ");
		book_add_instance(b, addedCount);
	}
	
	
	if(booklist_file_write(&lst->blst, FILENAME_BOOKS, FILENAME_BOOKSINSTANCE) == false ||
		bookauthorlist_file_write(&lst->balst, FILENAME_BOOKAUTHOR) == false
	)
	{
		fprintf(stderr, "Writing to file is failed\n");
		return false;
	}
	
	return true;
}

bool menu_books_display_info(ListOfLists *lst)
{
	Book *b = NULL;
	int i = 0;
	char name[LENGTH_NAME] = {'\0'};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_string_input(name, LENGTH_NAME, "Enter book name you want to see informations: ");
	
	b = booklist_find_by(&lst->blst, name, book_is_same_name);
	if(b == NULL)
	{
		fprintf(stderr, "Book %s not found\n", name);
		return false;
	}
	
	printf("=====================================\n");
	book_print(b);
	
	for(i = 0; i < b->instanceCount; i++)
	{
		printf("=====================================\n");
		bookinstance_print(&b->bi[i]);
	}
		
	return true;
}

bool menu_books_list_on_shelf(ListOfLists *lst)
{
	CHECK_LISTOFLISTS(lst, return false);
	return mh_book_print_filter(lst, mh_book_filter_on_shelf);
}

bool menu_books_list_not_returned(ListOfLists *lst)
{
	CHECK_LISTOFLISTS(lst, return false);
	return mh_book_print_filter(lst, mh_book_not_returned_on_time);
}

bool menu_books_match_author(ListOfLists *lst)
{
	BookAuthor ba = {0};
	char newIsbn[LENGTH_ISBN] = {'\0'};
	int newId = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	newId = get_integer_input(1, INT_MAX, "Enter new author Id: ");
	if(authorlist_check_author_exist(&lst->alst, newId) == false)
	{
		fprintf(stderr, "Author %d not exist\n", newId);
		return false;
	}
	
	get_isbn_input(newIsbn, "Enter new ISBN: ");
	if(booklist_find_by(&lst->blst, newIsbn, book_is_same_isbn) == NULL)
	{
		fprintf(stderr, "Book %s not found\n", newIsbn);
		return false;
	}
	
	bookauthor_init(&ba, newIsbn, newId);
	
	if(bookauthorlist_add_back(&lst->balst, &ba) == false)
	{
		fprintf(stderr, "adding new bookauthor to Bookauthorlist is failed\n");
		return false;
	}
	
	if(bookauthorlist_file_write(&lst->balst, FILENAME_BOOKAUTHOR) == false)
	{
		fprintf(stderr, "Writing to BookAuthorList to file failed\n");
		return false;
	}	
	
	return true;
}

bool menu_books_update_author(ListOfLists *lst)
{
	char isbn[LENGTH_ISBN], newIsbn[LENGTH_ISBN] = {'\0'};
	int authorId = 0, newId = 0, index = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	authorId = get_integer_input(1, INT_MAX, "Enter author id: ");
	get_isbn_input(isbn, "Enter isbn: ");
	
	index = bookauthorlist_find(&lst->balst, isbn, authorId);
	if(index == NOT_EXIST)
	{
		fprintf(stderr, "Book-Author not found\n");
		return false;
	}
	
	newId = get_integer_input(1, INT_MAX, "Enter new author Id: ");
	if(authorlist_check_author_exist(&lst->alst, newId) == false)
	{
		fprintf(stderr, "Author %d not exist\n", newId);
		return false;
	}
	
	get_isbn_input(newIsbn, "Enter new ISBN: ");
	if(booklist_find_by(&lst->blst, newIsbn, book_is_same_isbn) == NULL)
	{
		fprintf(stderr, "Book %s not found\n", newIsbn);
		return false;
	}
	
	if(bookauthor_update(&lst->balst.data[index], newIsbn, newId) == false)
	{
		fprintf(stderr, "Updateing bookauthor failed\n");
		return false;
	}
	
	if(bookauthorlist_file_write(&lst->balst, FILENAME_BOOKAUTHOR) == false)
	{
		fprintf(stderr, "Writing to BookAuthorList to file failed\n");
		return false;
	}	
	
	return true;
}

bool menu_authors_add(ListOfLists *lst)
{
	Author *a = NULL;
	char name[LENGTH_NAME] = {'\0'}, surname[LENGTH_SURNAME] = {'\0'};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_string_input(name, LENGTH_NAME, "Enter name of author: ");
	get_string_input(surname, LENGTH_SURNAME, "Enter surname of author: ");
	
	a = author_create(name, surname);
	if(a == NULL)
	{
		fprintf(stderr, "Creation author is failed\n");
		return false;
	}
	
	if(authorlist_add_back(&lst->alst, a) == false)
	{
		fprintf(stderr, "Adding to authorlist is failed\n");
		return false;
	}
	
	if(authorlist_file_write(&lst->alst, FILENAME_AUTHORS) == false)
	{
		fprintf(stderr, "Writing to authorlist file is failed\n");
		return false;
	}
	
	return true;
}

bool menu_authors_delete(ListOfLists *lst)
{
	char name[LENGTH_NAME] = {'\0'}, surname[LENGTH_SURNAME] = {'\0'};
	Author *a = NULL;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_string_input(name, LENGTH_NAME, "Enter author name: ");
	get_string_input(surname, LENGTH_SURNAME, "Enter author surname: ");
	
	a = authorlist_find(&lst->alst, name, surname);
	if(a == NULL)
	{
		fprintf(stderr, "Author not found\n");
		return false;
	}
	
	if(authorlist_remove(&lst->alst, a) == false)
	{
		fprintf(stderr, "Removing author from authorlist is failed\n");
		return false;
	}
	
	if(authorlist_file_write(&lst->alst, FILENAME_AUTHORS) == false)
	{
		fprintf(stderr, "Writing authorlist to file is failed\n");
		return false;
	}
	
	mh_author_sync_book(lst);
	
	if(bookauthorlist_file_write(&lst->balst, FILENAME_BOOKAUTHOR) == false)
	{
		fprintf(stderr, "Writing to BookAuthorList to file failed\n");
		return false;
	}
	
	return true;
}

bool menu_authors_update(ListOfLists *lst)
{
	Author *a = NULL;
	char name[LENGTH_NAME] = {'\0'}, surname[LENGTH_SURNAME] = {'\0'};
	char newName[LENGTH_NAME] = {'\0'}, newSurname[LENGTH_SURNAME] = {'\0'};
	int oldId = 0, newId = 0;
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_string_input(name, LENGTH_NAME, "Enter name of author: ");
	get_string_input(surname, LENGTH_SURNAME, "Enter surname of author: ");
	
	a = authorlist_find(&lst->alst, name, surname);
	if(a == NULL)
	{
		fprintf(stderr, "Author %s %s not found\n", name, surname);
		return false;
	}
	
	oldId = a->id;
	
	do
	{
		newId = get_integer_input(1, INT_MAX, "Enter new id: ");
	}while(authorlist_check_author_exist(&lst->alst, newId) && newId != oldId);
	
	get_string_input(newName, LENGTH_NAME, "Enter new name: ");
	get_string_input(newSurname, LENGTH_SURNAME, "Enter new surname: ");
	
	author_update(a, newId, newName, newSurname);
	
	if(authorlist_file_write(&lst->alst, FILENAME_AUTHORS) == false)
	{
		fprintf(stderr, "Writing to authorlist file is failed\n");
		return false;
	}
	
	bookauthorlist_update_id(&lst->balst, oldId, newId);
	
	mh_author_sync_book(lst);
	
	if(bookauthorlist_file_write(&lst->balst, FILENAME_BOOKAUTHOR) == false)
	{
		fprintf(stderr, "Writing to BookAuthorList to file failed\n");
		return false;
	}
	
	return true;
}

bool menu_authors_display(ListOfLists *lst)
{
	int i = 0;
	Author *a = NULL;
	char name[LENGTH_NAME] = {'\0'}, surname[LENGTH_SURNAME] = {'\0'};
	
	CHECK_LISTOFLISTS(lst, return false);
	
	get_string_input(name, LENGTH_NAME, "Enter name of author you want to see informations: ");
	get_string_input(surname, LENGTH_SURNAME, "Enter surname of author you want to see informations: ");
	
	a = authorlist_find(&lst->alst, name, surname);
	if(a == NULL)
	{
		fprintf(stderr, "Author %s %s not found\n", name, surname);
		return false;
	}
	
	author_print(a);
	
	for(i = 0; i < lst->balst.count; i++)
	{
		if(lst->balst.data[i].authorId == a->id)
		{
			Book *b = booklist_find_by(&lst->blst, lst->balst.data[i].isbn, book_is_same_isbn);
			if(b == NULL)
			{
				fprintf(stderr, "Book %s not found\n", lst->balst.data[i].isbn);
			}
			else
			{
				printf("=====================================\n");
				book_print(b);
			}
		}
	}
	
	printf("=====================================\n");	
	
	return true;
}


/***************************************************************/
/*                             MAIN                            */
/***************************************************************/

int main(void)
{
	int input = 0;
	bool (* const menuFunctions[]) (ListOfLists *lst) = {
		menu_students_add, menu_students_delete, menu_students_update, menu_students_display,
		menu_students_not_returned_book, menu_students_penalized, menu_students_list_all,
		menu_students_borrow_book, menu_students_return_book, menu_books_add, menu_books_delete,
		menu_books_update, menu_books_display_info, menu_books_list_on_shelf, menu_books_list_not_returned,
		menu_books_match_author, menu_books_update_author, menu_authors_add, menu_authors_delete,
		menu_authors_update, menu_authors_display
	};
	ListOfLists lst = {0};
	
	if( studentlist_init(&lst.slst) == false ||
		authorlist_init(&lst.alst) == false ||
		booklist_init(&lst.blst) == false ||
		bookauthorlist_init(&lst.balst) == false ||
		borrowlist_init(&lst.brlst) == false
	)
	{
		fprintf(stderr, "Initialization failed\n");
	}
	
	studentlist_file_read(&lst.slst, FILENAME_STUDENTS);
	authorlist_file_read(&lst.alst, FILENAME_AUTHORS);
	booklist_file_read(&lst.blst, FILENAME_BOOKS, FILENAME_BOOKSINSTANCE);
	bookauthorlist_file_read(&lst.balst, FILENAME_BOOKAUTHOR);
	borrowlist_file_read(&lst.brlst, FILENAME_BOOKBORROWING);
	
	do
	{
		print_menu();
		
		input = get_integer_input(1, MENU_EXIT+1, "Enter operation number: ")-1;
		
		if(input != MENU_EXIT)
		{
			if(menuFunctions[input](&lst) == false)
			{
				fprintf(stderr, "Operation failed\n");
			}
		}
		
	}while(input != MENU_EXIT);
	
	studentlist_deinit(&lst.slst);
	authorlist_deinit(&lst.alst);
	booklist_deinit(&lst.blst);
	bookauthorlist_deinit(&lst.balst);
	borrowlist_deinit(&lst.brlst);
	
	return 0;
}


/***************************************************************/
/*              INPUT, FILE AND STRING FUNCFIONS               */
/***************************************************************/

/* clear stdin after using scanf or getchar */
void clear_stdin(void)
{
	int ch = 0;
	while((ch = getchar()) != '\n' && ch != EOF);
}

/* Get integer from stdin, both min and max included */
int get_integer_input(int min, int max, char *msgFormat, ...)
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

bool get_student_no_input(char *studentNo, char *msgFormat, ...)
{
	bool isValidInput = true;
	int i = 0;
	va_list arg = NULL;
	
	CHECK_PARAMETERS(studentNo == NULL, return false);
	
	if(msgFormat != NULL)
	{
		va_start(arg, msgFormat);
	}
	
	do
	{
		if(msgFormat != NULL)
		{
			vprintf(msgFormat, arg);
		}
		
		isValidInput = true;
		get_string_input(studentNo, LENGTH_STUDENT_NO, NULL);
		
		if(strlen(studentNo) != LENGTH_STUDENT_NO-1)
		{
			isValidInput = false;
		}
		
		for(i = 0; studentNo[i] != '\0' && isValidInput == true; i++)
		{
			if(!isdigit(studentNo[i]))
			{
				isValidInput = false;
			}
		}
		
		if(isValidInput == false)
		{
			fprintf(stderr, "Student No input is invalid\n");
		}
		
	}while(isValidInput == false);
	
	if(msgFormat != NULL)
	{
		va_end(arg);
	}
	
	return true;
}

bool get_isbn_input(char *isbn, char *msgFormat, ...)
{
	bool isValidInput = true;
	int i = 0;
	va_list arg = NULL;
	
	CHECK_PARAMETERS(isbn == NULL, return false);
	
	if(msgFormat != NULL)
	{
		va_start(arg, msgFormat);
	}
	
	do
	{
		if(msgFormat != NULL)
		{
			vprintf(msgFormat, arg);
		}
		
		isValidInput = true;
		get_string_input(isbn, LENGTH_MIN_ISBN+1, NULL);
		
		if(strlen(isbn) != LENGTH_MIN_ISBN)
		{
			isValidInput = false;
		}
		
		for(i = 0; isbn[i] != '\0' && isValidInput == true; i++)
		{
			if(!isdigit(isbn[i]))
			{
				isValidInput = false;
			}
		}
		
		if(isValidInput == false)
		{
			fprintf(stderr, "ISBN input is invalid\n");
		}
		
	}while(isValidInput == false);
	
	if(msgFormat != NULL)
	{
		va_end(arg);
	}
	
	return true;
}

OperationDate get_date_input(char *msgFormat, ...)
{
	OperationDate date = {0};
	va_list arg = NULL;
	
	if(msgFormat != NULL)
	{
		va_start(arg, msgFormat);
		vprintf(msgFormat, arg);
		va_end(arg);
	}
	
	date.day = get_integer_input(1, 31, "Enter day of month: ");
	date.month = get_integer_input(1, 12, "Enter month of year: ");
	date.year = get_integer_input(-10000, 10000, "Enter year: ");
	
	return date;
}

/* Get string fom stdin, '\0' character included maxLength (example: maxLength = 5 mean, 4 char + '\0') */
char *get_string_input(char *buffer, int maxLength, char *msgFormat, ...)
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
