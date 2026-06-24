/***************************************************************/
/*                           PURPOSE                           */
/*  You are required to design a system for a university that  */
/*  tracks student and course registrations. The system must   */
/*  have a dynamic structure that allows an unlimited number   */
/*  of courses to be added for each student, and all data up-  */
/*  dates must be performed directly through memory addresses. */
/***************************************************************/


/***************************************************************/
/*                           INCLUDES                          */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdarg.h>
#include <limits.h>


/***************************************************************/
/*                         DEFINITIONS                         */
/***************************************************************/

#define bool  int
#define true  (1)
#define false (0)

#define NOT_FOUND                  (-1)

#define MENU_OPERATION_COUNT       (18)

#define MAX_COURSE_NAME_LENGTH     (50)
#define MAX_COURSE_CODE_LENGTH     (10)
#define MAX_STUDENT_NAME_LENGTH    (50)

#define MIDTERM_WEIGHT             (40.0f)
#define FINAL_WEIGHT               (60.0f)

#define COURSE_FAILURE_THRESHOLD   (50.0f)


/***************************************************************/
/*                            MACROS                           */
/***************************************************************/

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define SWAP(a, b, TYPE)   \
do                         \
{                          \
	TYPE temp = (a);       \
	(a) = (b);             \
	(b) = temp;            \
}while(0)

#define CHECK_STUDENT_VALIDANCE(stu)                                                             \
do                                                                                               \
{                                                                                                \
	/* both stu->courses and courseCount should be 0 or both must not be zero */                 \
	bool isNotValid = ((stu) == NULL || (((stu)->courses == NULL) ^ ((stu)->courseCount == 0))); \
	assert(!isNotValid);                                                                         \
	if((isNotValid))                                                                             \
	{                                                                                            \
		fprintf(stderr, "Student is not valid\n");                                               \
		return;                                                                                  \
	}                                                                                            \
}while(0)

#define CHECK_STUDENT_VALIDANCE_RETVAL(stu, retVal)                                              \
do                                                                                               \
{                                                                                                \
	/* both stu->courses and courseCount should be 0 or both must not be zero */                 \
	bool isNotValid = ((stu) == NULL || (((stu)->courses == NULL) ^ ((stu)->courseCount == 0))); \
	assert(!isNotValid);                                                                         \
	if((isNotValid))                                                                             \
	{                                                                                            \
		fprintf(stderr, "Student is not valid\n");                                               \
		return retVal;                                                                           \
	}                                                                                            \
}while(0)

#define CHECK_LIST_VALIDANCE(lst)                                                                \
do                                                                                               \
{                                                                                                \
	/* both lst->list and listSize should be 0 or both must not be zero */                       \
	bool isNotValid = ((lst) == NULL || ((lst)->list == NULL) ^ ((lst)->listSize == 0));         \
	assert(!isNotValid);                                                                         \
	if((isNotValid))                                                                             \
	{                                                                                            \
		fprintf(stderr, "StudentList is not valid\n");                                           \
		return;                                                                                  \
	}                                                                                            \
}while(0)

#define CHECK_SELECTED_STUDENT(lst)                          \
do                                                           \
{                                                            \
	if(lst->selected == NULL)                                \
	{                                                        \
		fprintf(stderr, "No students selected\n");           \
		return;                                              \
	}                                                        \
}while(0)

#define CHECK_PARAMETERS(condition)                      \
do                                                       \
{                                                        \
	assert(!(condition));                                \
	if((condition))                                      \
	{                                                    \
		fprintf(stderr, "Parameters are invalid\n");     \
		return;                                          \
	}                                                    \
}while(0)

#define CHECK_PARAMETERS_RETVAL(condition, retVal)       \
do                                                       \
{                                                        \
	assert(!(condition));                                \
	if((condition))                                      \
	{                                                    \
		fprintf(stderr, "Parameters are invalid\n");     \
		return retVal;                                   \
	}                                                    \
}while(0)

#define CHECK_ALLOCATION(ptr)                            \
do                                                       \
{                                                        \
	assert((ptr));                                       \
	if((ptr) == NULL)                                    \
	{                                                    \
		perror("Allocation error");                      \
		return;                                          \
	}                                                    \
}while(0)


/***************************************************************/
/*                       DATA STRUCTURES                       */
/***************************************************************/

typedef enum
{
	MENU_INVALID = -1,
	MENU_ADD_STUDENT = 0,
	MENU_DELETE_STUDENT,
	MENU_LIST_STUDENTS_SUMMARY,
	MENU_LIST_STUDENTS_DETAILED,
	MENU_SELECT_STUDENT,
	MENU_UNSELECT_STUDENT,
	MENU_UPDATE_STUDENT,
	MENU_ADD_COURSE,
	MENU_DELETE_COURSE,
	MENU_SORT_COURSES,
	MENU_ENTER_COURSE_GRADS,
	MENU_UPDATE_COURSE,
	MENU_PRINT_COURSE_INDEX,
	MENU_PRINT_HIGHEST_GRAD,
	MENU_PRINT_FAILED_COURSES,
	MENU_PRINT_TOTAL_CREDIT,
	MENU_COPY_COURSES,
	MENU_EXIT
}MenuOperation;

typedef struct
{
    char  courseName[MAX_COURSE_NAME_LENGTH];
    char  courseCode[MAX_COURSE_CODE_LENGTH];
    int   credit;
    int   midtermGrade;
    int   finalGrade;
    float average;
}Course;

typedef struct
{
    char    name[MAX_STUDENT_NAME_LENGTH];
    int     studentNo;
    Course *courses;          /* Pointer for dynamic Course array */
    int     courseCount;      /* Number of current courses */
    float   overallAverage;
}Student;

typedef struct
{
	Student  *selected;
	Student **list;
	int       listSize;
}StudentList;

/***************************************************************/
/*                     FUNCTION PROTOTYPES                     */
/***************************************************************/

void initStudent                (Student *stu, char *name, int no);
void addCourse                  (Student *stu, char *name, char *code, int credit);
void deleteCourse               (Student *stu, char *code);
void freeSystem                 (Student *stu);

void enterGrades                (Student *stu, char *code, int midterm, int final);
void calculateOverallAverage    (Student *stu);
void updateCourse               (Student *stu, char *code, char *newName, int newCredit);

int  searchCourse               (Student *stu, char *code);
void findHighestGradeCourse     (Student stu);
void listFailedCourses          (Student stu);

void printReportCard            (Student stu);
void creditLoadReport           (Student stu);
void sortCoursesAlphabetically  (Student *stu);

void updateStudentInfo          (Student *stu, char *newName, int newNo);
void copyCourses                (Student *target, Student source);

MenuOperation getMenuOperation         (void);
void          menuAddStudent           (StudentList *lst);
void          menuDeleteStudent        (StudentList *lst);
void          menuListStudentsSummary  (StudentList *lst);
void          menuListStudentsDetailed (StudentList *lst);
void          menuSelectStudent        (StudentList *lst);
void          menuUnselectStudent      (StudentList *lst);
void          menuUpdateStudent        (StudentList *lst);
void          menuAddCourse            (StudentList *lst);
void          menuDeleteCourse         (StudentList *lst);
void          menuSortCourses          (StudentList *lst);
void          menuEnterCourseGrads     (StudentList *lst);
void          menuUpdateCourse         (StudentList *lst);
void          menuPrintCourseIndex     (StudentList *lst);
void          menuPrintHighestGrad     (StudentList *lst);
void          menuPrintFailedCourses   (StudentList *lst);
void          menuPrintTotalCredit     (StudentList *lst);
void          menuCopyCourses          (StudentList *lst);
void          freeMemory               (StudentList *lst);

void  clearStdin      (void);
int   getIntegerInput (int min, int max, char *msgFormat, ...);
char *getStringInput  (char *buffer, int maxLength, char *msgFormat, ...);



/***************************************************************/
/*                             MAIN                            */
/***************************************************************/

int main()
{
	void (*const menuFunctions[])(StudentList *lst) = {
		menuAddStudent, menuDeleteStudent, menuListStudentsSummary, menuListStudentsDetailed,
		menuSelectStudent, menuUnselectStudent, menuUpdateStudent, menuAddCourse, menuDeleteCourse, menuSortCourses,
		menuEnterCourseGrads, menuUpdateCourse, menuPrintCourseIndex, menuPrintHighestGrad, menuPrintFailedCourses,
		menuPrintTotalCredit, menuCopyCourses
	};
	MenuOperation operation = MENU_INVALID;
	bool isContinue = true;
	StudentList lst = {0};
	
	do
	{
		operation = getMenuOperation();
		if(operation > MENU_INVALID && operation < MENU_EXIT)
		{
			(*(menuFunctions + operation))(&lst);
		}
		else if(operation == MENU_EXIT)
		{
			isContinue = false;
		}
		else
		{
			assert(!"Invalid operation");
			fprintf(stderr, "Invalid operation\n");
		}
	}while(isContinue);
	
	freeMemory(&lst);

	return 0;
}



/***************************************************************/
/*                        MENU FUNCTIONS                       */
/***************************************************************/

MenuOperation getMenuOperation(void)
{
	printf( "%s%s\n",
	        "\n==================================================\n"
	        "Menu:\n"
	        " 1- Add Student\n"
			" 2- Delete Student\n"
			" 3- List Students (summary)\n"
			" 4- List Students (detailed)\n"
			" 5- Select a Student\n"
			" 6- Unselect Currently Selected Student\n"
			" 7- Update Currently Selected Student's Information\n"
			" 8- Add Course to Currently Selected Student\n"
			" 9- Delete Course from Currently Selected Student\n",
			"10- Sort Courses of Currently Selected Student by Alphabetically\n"
			"11- Enter a Course's Grads to Currently Selected Student\n"
			"12- Update a Currently Selected Student's Course\n"
			"13- Print Index of Entered Currently Selected Student's Course Code\n"
			"14- Print Highest Grade of Currently Selected Student\n"
			"15- Print Failed Courses of Currently Selected Student\n"
			"16- Print Total Credit Load of Currently Selected Student\n"
			"17- Copy Another Student's Courses to Currently Selected Student\n"
			"18- Exit\n"
	);
	return (MenuOperation)(getIntegerInput(1, MENU_OPERATION_COUNT, "Enter operation: ")-1);
}

void menuAddStudent(StudentList *lst)
{
	char nameBuffer[MAX_STUDENT_NAME_LENGTH] = {'\0'};
	int no = 0;
	Student **newList = NULL;
	
	CHECK_LIST_VALIDANCE(lst);
	
	if(lst->listSize == 0)
	{
		newList = (Student**)malloc(sizeof(Student*));
	}
	else
	{
		newList = (Student**)realloc(lst->list, (size_t)(lst->listSize+1) * sizeof(Student*));
	}
	
	CHECK_ALLOCATION(newList);
	
	*(newList + lst->listSize) = (Student*)malloc(sizeof(Student));
	CHECK_ALLOCATION(*(newList + lst->listSize));
	
	getStringInput(nameBuffer, MAX_STUDENT_NAME_LENGTH, "Enter Student Name: ");
	no = getIntegerInput(0, INT_MAX, "Enter Student No: ");
	
	initStudent(*(newList + lst->listSize), nameBuffer, no);
	
	lst->list = newList;
	lst->listSize++;

	printf("Student added successfully\n");
}

void menuDeleteStudent(StudentList *lst)
{
	int no = 0, i = 0, studentIndex = NOT_FOUND;
	Student **newList = NULL;
	
	CHECK_LIST_VALIDANCE(lst);
	
	if(lst->list == NULL)
	{
		fprintf(stderr, "Nothing to be delete\n");
		return;
	}
	
	no = getIntegerInput(0, INT_MAX, "Enter Student No: ");
	
	for(i = 0; i < lst->listSize && studentIndex == NOT_FOUND; i++)
	{
		if((*(lst->list + i))->studentNo == no)
		{
			studentIndex = i;
		}
	}
	
	if(studentIndex != NOT_FOUND)
	{		
		if(lst->selected == *(lst->list + studentIndex))
		{
			lst->selected = NULL;
		}
		
		freeSystem(*(lst->list + studentIndex));
		
		if(lst->listSize == 1)
		{
			free(lst->list);
			lst->listSize = 0;
			lst->list = NULL;
			return;
		}

		for(i = studentIndex+1; i < lst->listSize; i++)
		{
			*(lst->list + i - 1) = *(lst->list + i);
		}
	
		newList = (Student**)realloc(lst->list, (size_t)(lst->listSize-1) * sizeof(Student*));
		CHECK_ALLOCATION(newList);
	
		lst->listSize--;
		lst->list = newList;

		printf("Student deleted successfully\n");
	}
	else
	{
		fprintf(stderr, "Student not found\n");
	}
	
	
}

void menuListStudentsSummary(StudentList *lst)
{
	int i = 0;
	
	CHECK_LIST_VALIDANCE(lst);
	
	printf("====================================\n");
	
	for(i = 0; i < lst->listSize; i++)
	{
		if(lst->selected == (*(lst->list + i)))
		{
			printf("|         SELECTED STUDENT         |\n");
		}
		
		calculateOverallAverage((*(lst->list + i)));
		
		printf("|Student %2d:                       |\n", i+1);
		printf("|Name: %28s|\n", (*(lst->list + i))->name);
		printf("|No: %30d|\n", (*(lst->list + i))->studentNo);
		printf("|Overall Average: %17.02f|\n", (*(lst->list + i))->overallAverage);
		printf("|");
		creditLoadReport(**(lst->list + i));
		printf("====================================\n");
	}
	
}

void menuListStudentsDetailed(StudentList *lst)
{
	int i = 0;
	
	CHECK_LIST_VALIDANCE(lst);
	
	for(i = 0; i < lst->listSize; i++)
	{
		if(lst->selected == (*(lst->list + i)))
		{
			printf("SELECTED STUDENT\n");
		}
		printf("Student %d:\n", i+1);
		printReportCard(**(lst->list + i));
		printf("\n");
	}
}

void menuSelectStudent(StudentList *lst)
{
	int i = 0, no = 0, studentIndex = NOT_FOUND;
	
	CHECK_LIST_VALIDANCE(lst);
	
	no = getIntegerInput(0, INT_MAX, "Enter Student Number: ");
	
	for(i = 0; i < lst->listSize && studentIndex == NOT_FOUND; i++)
	{
		if((*(lst->list + i))->studentNo == no)
		{
			studentIndex = i;
		}
	}
	
	if(studentIndex != NOT_FOUND)
	{
		lst->selected = *(lst->list + studentIndex);
		printf("Student %d selected\n", no);
	}
	else
	{
		fprintf(stderr, "Student %d not found\n", no);
	}
}

void menuUnselectStudent(StudentList *lst)
{
	CHECK_LIST_VALIDANCE(lst);
	
	if(lst->selected == NULL)
	{
		fprintf(stderr, "No student selected\n");
	}
	else
	{
		int no = lst->selected->studentNo;

		lst->selected = NULL;

		printf("Student %d unselected\n", no);
	}
}

void menuUpdateStudent(StudentList *lst)
{
	char newName[MAX_STUDENT_NAME_LENGTH] = {'\0'};
	int newNo = 0;
	
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	getStringInput(newName, MAX_STUDENT_NAME_LENGTH, "Enter %s's new name: ", lst->selected->name);
	newNo = getIntegerInput(0, INT_MAX, "Enter %d's new no: ", lst->selected->studentNo);
	
	updateStudentInfo(lst->selected, newName, newNo);

	printf("Student information updated\n");
}

void menuAddCourse(StudentList *lst)
{
	char name[MAX_COURSE_NAME_LENGTH] = {'\0'}, code[MAX_COURSE_CODE_LENGTH] = {'\0'};
	int credit = 0;
	
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	getStringInput(name, MAX_COURSE_NAME_LENGTH, "Enter course name: ");
	getStringInput(code, MAX_COURSE_CODE_LENGTH, "Enter course code: ");
	credit = getIntegerInput(0, INT_MAX, "Enter course credit: ");
	
	addCourse(lst->selected, name, code, credit);
}

void menuDeleteCourse(StudentList *lst)
{
	char code[MAX_COURSE_CODE_LENGTH] = {'\0'};
	
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	getStringInput(code, MAX_COURSE_CODE_LENGTH, "Enter course code: ");
	
	deleteCourse(lst->selected, code);
	
}

void menuSortCourses(StudentList *lst)
{
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	sortCoursesAlphabetically(lst->selected);
}

void menuEnterCourseGrads(StudentList *lst)
{
	char code[MAX_COURSE_CODE_LENGTH] = {'\0'};
	int midterm = 0, final = 0;
	
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	getStringInput(code, MAX_COURSE_CODE_LENGTH, "Enter course code: ");
	midterm = getIntegerInput(0, 100, "Enter midterm grade: ");
	final = getIntegerInput(0, 100, "Enter final grade: ");
	
	enterGrades(lst->selected, code, midterm, final);
}

void menuUpdateCourse(StudentList *lst)
{
	char newName[MAX_COURSE_NAME_LENGTH] = {'\0'}, code[MAX_COURSE_CODE_LENGTH] = {'\0'};
	int newCredit = 0;
	
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	getStringInput(code, MAX_COURSE_CODE_LENGTH, "Enter course code: ");
	getStringInput(newName, MAX_COURSE_NAME_LENGTH, "Enter course new name: ");
	newCredit = getIntegerInput(0, INT_MAX, "Enter course new credit: ");
	
	updateCourse(lst->selected, code, newName, newCredit);
}

void menuPrintCourseIndex(StudentList *lst)
{
	char code[MAX_COURSE_CODE_LENGTH] = {'\0'};
	int index = NOT_FOUND;
	
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	getStringInput(code, MAX_COURSE_CODE_LENGTH, "Enter course code: ");
	
	index = searchCourse(lst->selected, code);
	if(index != NOT_FOUND)
	{
		printf("Index: %d\n", index);
	}
	else
	{
		fprintf(stderr, "Course \'%s\' not found\n", code);
	}
}

void menuPrintHighestGrad(StudentList *lst)
{
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	findHighestGradeCourse(*lst->selected);
}

void menuPrintFailedCourses(StudentList *lst)
{
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	listFailedCourses(*lst->selected);
}

void menuPrintTotalCredit(StudentList *lst)
{
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	creditLoadReport(*lst->selected);
}

void menuCopyCourses(StudentList *lst)
{
	int i = 0, no = 0, studentIndex = NOT_FOUND;
	
	CHECK_LIST_VALIDANCE(lst);
	CHECK_SELECTED_STUDENT(lst);
	
	no = getIntegerInput(0, INT_MAX, "Enter student no: ");
	
	for(i = 0; i < lst->listSize && studentIndex == NOT_FOUND; i++)
	{
		if((*(lst->list + i))->studentNo == no)
		{
			studentIndex = i;
		}
	}
	
	if(studentIndex != NOT_FOUND)
	{
		copyCourses(lst->selected, **(lst->list + studentIndex));
	}
	else
	{
		fprintf(stderr, "Student %d not found\n", no);
	}
	
}

void freeMemory(StudentList *lst)
{
	int i = 0;
	
	CHECK_LIST_VALIDANCE(lst);
	
	for(i = 0; i < lst->listSize; i++)
	{
		freeSystem(*(lst->list + i));
	}

	if(lst->list != NULL)
	{
		free(lst->list);
		lst->list = NULL;
	}

	lst->listSize = 0;
	lst->selected = NULL;
}



/***************************************************************/
/*                     FUNCTION DEFINITIONS                    */
/***************************************************************/

void initStudent(Student *stu, char *name, int no)
{
	CHECK_PARAMETERS(stu == NULL || name == NULL || no < 0);
	
	strncpy(stu->name, name, MAX_STUDENT_NAME_LENGTH-1);
	/* To make sure name null terminated, it wont null terminated by strncpy if argument name's length >= MAX_STUDENT_NAME_LENGTH */
	*(stu->name + MAX_STUDENT_NAME_LENGTH-1) = '\0';
	stu->studentNo = no;
	stu->courses = NULL;
	stu->courseCount = 0;
	stu->overallAverage = 0.0f;
}

void addCourse(Student *stu, char *name, char *code, int credit)
{
	Course *courses = NULL;
	int lastIndex = 0;
	
	CHECK_STUDENT_VALIDANCE(stu);
	CHECK_PARAMETERS(name == NULL || code == NULL);
	
	lastIndex = stu->courseCount;
	
	if(credit < 0)
	{
		fprintf(stderr, "Credit must be non negative integer\n");
		return;
	}
	
	if(stu->courses == NULL)
	{
		courses = (Course*)malloc(sizeof(Course));
	}
	else
	{
		courses = (Course*)realloc(stu->courses, (size_t)(stu->courseCount+1) * sizeof(Course));
	}
	
	CHECK_ALLOCATION(courses);
	
	memset(courses + lastIndex, 0, sizeof(Course)); /* Zero initialization for newly allocated area */
	stu->courses = courses;
	stu->courseCount++;
	
	strncpy((stu->courses + lastIndex)->courseName, name, MAX_COURSE_NAME_LENGTH-1);
	strncpy((stu->courses + lastIndex)->courseCode, code, MAX_COURSE_CODE_LENGTH-1);
	/* To make sure courseName and courseCode null terminated, it wont null terminated by strncpy if argument name's length >= MAX_COURSE_NAME_LENGTH and code's length >= MAX_COURSE_CODE_LENGTH */
	*((stu->courses + lastIndex)->courseName + MAX_COURSE_NAME_LENGTH - 1) = '\0';
	*((stu->courses + lastIndex)->courseCode + MAX_COURSE_CODE_LENGTH - 1) = '\0';
	(stu->courses + lastIndex)->credit = credit;
	/* other values already zero initialized by memset function above */

	printf("Course \'%s\' added\n", code);
}

void deleteCourse(Student *stu, char *code)
{
	int i = 0, courseIndex = NOT_FOUND;
	
	CHECK_STUDENT_VALIDANCE(stu);
	CHECK_PARAMETERS(code == NULL);
	
	for(i = 0; i < stu->courseCount && courseIndex == NOT_FOUND; i++)
	{
		if(!strcmp((stu->courses + i)->courseCode, code))
		{
			courseIndex = i;
		}
	}
	
	if(courseIndex != NOT_FOUND)
	{
		memmove(stu->courses + courseIndex, stu->courses + courseIndex + 1, (size_t)(stu->courseCount - courseIndex - 1) * sizeof(Course));
		
		if(stu->courseCount == 1)
		{
			free(stu->courses);
			
			stu->courseCount = 0;
			stu->courses = NULL;
		}
		else
		{
			Course* courses = (Course*)realloc(stu->courses, (size_t)(stu->courseCount-1) * sizeof(Course));
			if(courses == NULL)
			{
				return;
			}
			
			stu->courseCount--;
			stu->courses = courses;
		}
		
		calculateOverallAverage(stu);

		printf("Course \'%s\' deleted\n", code);
	}
	else
	{
		fprintf(stderr, "Course \'%s\' not found\n", code);
	}
}

void freeSystem(Student *stu)
{
	CHECK_PARAMETERS(stu == NULL);
	
	if(stu->courses != NULL)
	{
		free(stu->courses);
	}
	free(stu);
}

void enterGrades(Student *stu, char *code, int midterm, int final)
{
	bool validParameters = true, courseFound = false;
	int i = 0;
	
	CHECK_STUDENT_VALIDANCE(stu);
	CHECK_PARAMETERS(code == NULL);
	
	if(midterm < 0 || midterm > 100)
	{
		fprintf(stderr, "Midterm grade (%d) must be between 0 and 100\n", midterm);
		validParameters = false;
	}
	if(final < 0 || final > 100)
	{
		fprintf(stderr, "Final grade (%d) must be between 0 and 100\n", final);
		validParameters = false;
	}
	
	if(validParameters == false)
	{
		return;
	}
	
	for(i = 0; i < stu->courseCount && courseFound == false; i++)
	{
		if(!strcmp((stu->courses + i)->courseCode, code))
		{
			courseFound = true;
		}
	}
	
	if(courseFound == true)
	{
		const int courseIndex = i-1;
		(stu->courses + courseIndex)->midtermGrade = midterm;
		(stu->courses + courseIndex)->finalGrade = final;
		(stu->courses + courseIndex)->average = (midterm * MIDTERM_WEIGHT + final * FINAL_WEIGHT) / (MIDTERM_WEIGHT + FINAL_WEIGHT);
		calculateOverallAverage(stu);
	}
	else
	{
		fprintf(stderr, "Course \'%s\' not found\n", code);
	}
	
}

void calculateOverallAverage(Student *stu)
{
	int i = 0, creditTotal = 0;
	float weightedTotal = 0.0f;
	
	CHECK_STUDENT_VALIDANCE(stu);
	
	for(i = 0; i < stu->courseCount; i++)
	{
		weightedTotal += (stu->courses + i)->average * (stu->courses + i)->credit;
		creditTotal += (stu->courses + i)->credit;
	}
	
	stu->overallAverage = (creditTotal != 0) ? (weightedTotal / creditTotal) : 0;
}

void updateCourse(Student *stu, char *code, char *newName, int newCredit)
{
	bool courseFound = false;
	int i = 0;
	
	CHECK_STUDENT_VALIDANCE(stu);
	CHECK_PARAMETERS(code == NULL || newName == NULL);
	
	for(i = 0; i < stu->courseCount && courseFound == false; i++)
	{
		if(!strcmp((stu->courses + i)->courseCode, code))
		{
			courseFound = true;
		}
	}
	
	if(courseFound == true)
	{
		int courseIndex = i-1;
		strncpy((stu->courses + courseIndex)->courseName, newName, MAX_COURSE_NAME_LENGTH-1);
		/* To make sure name null terminated, it wont null terminated by strncpy if argument name's length >= MAX_COURSE_NAME_LENGTH */
		*((stu->courses + courseIndex)->courseName + MAX_COURSE_NAME_LENGTH - 1) = '\0';
		(stu->courses + courseIndex)->credit = newCredit;
		calculateOverallAverage(stu);
	}
	else
	{
		fprintf(stderr, "Course \'%s\' not found\n", code);
	}
}

int searchCourse(Student *stu, char *code)
{
	int i = 0, courseIndex = NOT_FOUND;
	
	CHECK_STUDENT_VALIDANCE_RETVAL(stu, -1);
	CHECK_PARAMETERS_RETVAL(code == NULL, -1);
	
	for(i = 0; i < stu->courseCount && courseIndex == NOT_FOUND; i++)
	{
		if(!strcmp((stu->courses + i)->courseCode, code))
		{
			courseIndex = i;
		}
	}
	
	return courseIndex;
}

void findHighestGradeCourse(Student stu)
{
	int i = 1, max = 0;
	
	CHECK_STUDENT_VALIDANCE(&stu);
	
	if(stu.courses == NULL)
	{
		fprintf(stderr, "No courses have been added yet\n");
		return;
	}
	
	for(i = 1; i < stu.courseCount; i++)
	{
		if((stu.courses + i)->average > (stu.courses + max)->average)
		{
			max = i;
		}
	}
	
	printf( "Highest Average Course %s-%s: %.02f\n",
			(stu.courses + max)->courseCode, (stu.courses + max)->courseName, (stu.courses + max)->average
	);
	
}

void listFailedCourses(Student stu)
{
	int i = 0;
	
	CHECK_STUDENT_VALIDANCE(&stu);
	
	if(stu.courses == NULL)
	{
		fprintf(stderr, "No courses have been added yet\n");
		return;
	}
	
	for(i = 0; i < stu.courseCount; i++)
	{
		if((stu.courses + i)->average < COURSE_FAILURE_THRESHOLD)
		{
			printf("Course %s-%s: %.02f -> FAILED\n", (stu.courses + i)->courseCode, (stu.courses + i)->courseName, (stu.courses + i)->average);
		}
	}
}

void printReportCard(Student stu)
{
	int i = 0;
	
	CHECK_STUDENT_VALIDANCE(&stu);
	
	calculateOverallAverage(&stu);
	
	printf( "=======================================\n"
	        "| Student Name:    %19s|\n"
	        "| Student No:      %19d|\n"
	        "| Course Count:    %19d|\n"
	        "| Student Average: %19.02f|\n"
	        "=======================================\n",
	        stu.name, stu.studentNo, stu.courseCount, stu.overallAverage
	);
	
	for(i = 0; i < stu.courseCount; i++)
	{
		printf( "| Course Name:   %21s|\n"
		        "| Course Code:   %21s|\n"
		        "| Course Credit: %21d|\n"
		        "| Midterm Grade: %21d|\n"
		        "| Final Grade:   %21d|\n"
		        "| Average:       %21.02f|\n"
				"=======================================\n",
				(stu.courses + i)->courseName, (stu.courses + i)->courseCode, (stu.courses + i)->credit,
				(stu.courses + i)->midtermGrade, (stu.courses + i)->finalGrade, (stu.courses + i)->average);
	}
}

void creditLoadReport(Student stu)
{
	int i = 0, totalCredit = 0;
	
	CHECK_STUDENT_VALIDANCE(&stu);
	
	for(i = 0; i < stu.courseCount; i++)
	{
		totalCredit += (stu.courses + i)->credit;
	}
	
	printf("Total credit: %d\n", totalCredit);
}

void sortCoursesAlphabetically(Student *stu)
{
	int i = 0, j = 0;
	
	CHECK_STUDENT_VALIDANCE(stu);
	
	for(i = 0; i < stu->courseCount-1; i++)
	{
		for(j = 0; j < stu->courseCount-i-1; j++)
		{
			if(strcmp((stu->courses + j)->courseName, (stu->courses + j + 1)->courseName) > 0)
			{
				SWAP(*(stu->courses + j), *(stu->courses + j + 1), Course);
			}
		}
	}
	
	printf("Course names: \n");
	for(i = 0; i < stu->courseCount; i++)
	{
		printf("%s\n", (stu->courses + i)->courseName);
	}
}

void updateStudentInfo(Student *stu, char *newName, int newNo)
{
	CHECK_STUDENT_VALIDANCE(stu);
	CHECK_PARAMETERS(newName == NULL || newNo < 0);
	
	strncpy(stu->name, newName, MAX_STUDENT_NAME_LENGTH-1);
	/* To make sure name null terminated, it wont null terminated by strncpy if argument name's length >= MAX_STUDENT_NAME_LENGTH */
	*(stu->name + MAX_STUDENT_NAME_LENGTH - 1) = '\0';
	stu->studentNo = newNo;
}

void copyCourses(Student *target, Student source)
{
	Course *courses = NULL;
	
	CHECK_STUDENT_VALIDANCE(target);
	CHECK_STUDENT_VALIDANCE(&source);
	
	if(source.courseCount == 0)
	{
		fprintf(stderr, "Nothing to copy\n");
	}
	
	if(source.courseCount != 0)
	{
		courses = (Course*)malloc((size_t)source.courseCount * sizeof(Course));
		CHECK_ALLOCATION(courses);
		
		memcpy(courses, source.courses, (size_t)source.courseCount * sizeof(Course));	
	}
	
	if(target->courses != NULL)
	{
		free(target->courses);
	}
	
	target->courseCount = source.courseCount;
	target->courses = courses;
	
	calculateOverallAverage(target);
}


/***************************************************************/
/*                       HELPER FUNCTIONS                      */
/***************************************************************/

void clearStdin(void)
{
	int ch = 0;
	while((ch = getchar()) != '\n' && ch != EOF);
}

/* Both min and max included */
int getIntegerInput(int min, int max, char *msgFormat, ...)
{
	bool isValid = true;
	int input = 0;
	va_list arg;
	
	CHECK_PARAMETERS_RETVAL(min > max, 0);
	
	va_start(arg, msgFormat);
	
	do
	{
		isValid = true;
		
		vprintf(msgFormat, arg);
		
		if(scanf("%d", &input) != 1)
		{
			fprintf(stderr, "Enter an integer value\n");
			clearStdin();
			isValid = false;
		}
		else if(input < min || input > max)
		{
			fprintf(stderr, "Value must be between %d and %d (both included)\n", min, max);
			clearStdin();
			isValid = false;
		}		
	}while(isValid == false);
	
	va_end(arg);
	clearStdin();
	
	return input;
}

/* '\0' character included maxLength (example: maxLength = 5 mean, 4 char + '\0') */
char *getStringInput(char *buffer, int maxLength, char *msgFormat, ...)
{
	int ch = 0, i = 0;
	va_list arg;
	
	CHECK_PARAMETERS_RETVAL(buffer == NULL || maxLength == 0, NULL);
	
	va_start(arg, msgFormat);
	
	vprintf(msgFormat, arg);
	
	va_end(arg);
	
	while((ch = getchar()) != '\n' && ch != EOF)
	{
		if(i < maxLength-1)
		{
			*(buffer + i) = (char)ch;
			i++;
		}
	}
	*(buffer + i) = '\0';
	
	return buffer;
}

