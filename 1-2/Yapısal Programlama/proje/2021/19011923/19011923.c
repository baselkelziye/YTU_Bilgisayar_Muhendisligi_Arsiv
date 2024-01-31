#ifdef _WIN32
#include <windows.h> //import windows.h to change console color
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COURSES "courses.txt"
#define ENROLLMENT "courseEnrollment.txt"
#define INSTRUCTORS "instructors.txt"
#define STUDENTS "students.txt"
#define TEMP_FILE "temp.txt"
#define DB_INFO "db_info.txt"
#define USERS "users.txt"
#define COURSES_HEADER "Code - Name - Credit - Capacity - Instructor Id"
#define STUDENTS_HEADER "Number - Name - Surname - Number of lessons - Total credit"
#define INSTRUCTORS_HEADER "ID - Name - Surname - Title"
#define INFO_HEADER "Credit limit - Lessons number limit - Course count - Instructor count - Student count - Log count"
#define ENROLLMENT_HEADER "ID - Number - Course Code - Date - Enrolled"
#define SEPERATOR "\t===============\n"
#define MAX_LINE_SIZE 300
#define COLUMN_MAX 10
#define MAX_COLUMN_SIZE 75
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define RESET 0

typedef struct {
  char number[30];
  char name[75];
  char surname[30];
  int lessonCount;
  int totalCredit;
} Student;

typedef struct {
  char code[20];
  char name[75];
  int credit;
  int capacity;
  char instructorId[30];
} Course;

typedef struct {
  char id[30];
  char name[30];
  char surname[30];
  char title[20];
} Instructor;

typedef struct {
  int id;
  char studentNumber[30];
  char courseCode[20];
  char date[20];
  int enrolled;
} EnrollmentLog;

int addDataToFile(char*,char*);
void addTextToPosition(FILE*,char*,int);
void alterCourses();
void alterInstructors();
void alterSettings();
void alterStudents();
void changeDataCounter(int,int);
int checkPassword(char*, char*, int);
void clearConsole();
int countEnrollments(char*);
int countRows(FILE*);
int createNewFile(char*);
void createPassword(char*,char*,int);
int decryptPassword(char*,char*,char*);
int deleteDataFromFile(char*,char*);
int deleteUser(char*,int);
char* encryptPassword(char*,char*,int);
void enrollStudent(char*,char*);
int exportEnrolledStudents(char*);
int findDataPosition(FILE*,char*,int);
int getColumnString(FILE*,char*,int,int,char*);
void greetAdmin(char*,char*);
void greetStudent(char*,char*);
void greetInstructor(char*,char*);
int hasColumn(char*,char*,int);
int isEnrolled(FILE*,char*,char*);
void listAllData(char*,const char*);
void listAssignedCourses(char*);
int listEnrolledStudents(char*);
void listStudentEnrollments(char*);
void* parseToStruct(char*,int);
void setColor(int);
void throwError(int,int,int);
void unEnrollStudent(char*,char*,int);
int unEnrollAllStudents(char*);
void updateAttendersCredit(char*, int);
int updateCourseDetails(char*);
int updateDataInFile(char*,char*,int*,const char*);
int updateStudentEnrollment(char*,int,int,int);

int main(int argc, char const *argv[]) {
  char *operator, *username, *password;
  int cont = 1;
  srand(time(0));
  operator = (char*) malloc(COLUMN_MAX * sizeof(char));
  username = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  password = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  do {
    printf("Choose user type or type 'e' to exit\n"
            "[1] Admin, [2] Instructor, [3] Student: ");
    fgets(operator,COLUMN_MAX,stdin);
    clearConsole();
    if (operator[0] < '4' && operator[0] > '0') {
      printf("Username: ");fgets(username, MAX_COLUMN_SIZE, stdin);
      printf("Password: ");fgets(password, MAX_COLUMN_SIZE, stdin);
      strtok(username, "\n"),strtok(password, "\n");
      if (strlen(username) <= 0 || strlen(password) <= 0) {
        throwError(50, 0, __LINE__);
        operator[0] = '!';
      }
    }
    switch (operator[0]) {
      case '1':
        greetAdmin(username, password);
      break;
      case '2':
        greetInstructor(username, password);
      break;
      case '3':
        greetStudent(username, password);
      break;
      case '!':
        cont=1;
      break;
      default:
        cont = 0;
    }
  } while(cont);
  free(password);
  free(username);
  free(operator);
  return 0;
}

int addDataToFile(char* text,char* fileName) {
  char **columnsHolder, *control, *firstColumn, *prompt, *stringToCompare, *tempStringHolder;
  FILE* fileToChange;
  long int previousPosition, position;
  int i, compareVar;
  //check if the file can be opened with "r+" if not ask to create it
  if ((fileToChange = fopen(fileName, "r+")) == NULL) {
    prompt = (char*) malloc(COLUMN_MAX * sizeof(char));
    printf("Warning: Couldn't open the file %s.\n", fileName);
    setColor(RED);
    printf("(The following WILL delete any existing file with the same name)");
    setColor(RESET);
    printf("\nShould I (re)create it? (y/n): ");
    fgets(prompt, COLUMN_MAX, stdin);
    if (prompt[0] == 'Y' || prompt[0] == 'y') {
      if (!createNewFile(fileName)) {
        printf("info: Created %s successfully\n", fileName);
        fileToChange = fopen(fileName, "r+");
      } else {
        return -1;
      }
      free(prompt);
    } else {
      setColor(RED);
      printf("Terminating the process without adding data...\n");
      setColor(RESET);
      free(prompt);
      return -1;
    }
  }
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  stringToCompare = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  firstColumn = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  strcpy(stringToCompare, text);
  tempStringHolder = strtok(stringToCompare, ",");
  strcpy(firstColumn, tempStringHolder);
  //loop through the file to determine where to add text
  previousPosition = ftell(fileToChange);
  if ((control = fgets(stringToCompare,MAX_LINE_SIZE,fileToChange))) {
    //divide the string into columns based on ','
    i = 0;
    tempStringHolder = strtok(stringToCompare, ",");
    strcpy(columnsHolder[i], tempStringHolder);
    i++;
    while ((tempStringHolder = strtok(NULL,",")) && i < COLUMN_MAX)
      strcpy(columnsHolder[i], tempStringHolder),i++;
  }
  position = ftell(fileToChange);
  if (control) {
    while ((compareVar = strcmp(columnsHolder[0], firstColumn)) < 0 && fgets(stringToCompare,MAX_LINE_SIZE, fileToChange)) {
      i=0;
      tempStringHolder = strtok(stringToCompare, ",");
      previousPosition = position;
      position = ftell(fileToChange);
      strcpy(columnsHolder[i], tempStringHolder);
      i++;
      while ((tempStringHolder = strtok(NULL, ",")))
        strcpy(columnsHolder[i], tempStringHolder),i++;
    }
    if (compareVar >0) {
      fseek(fileToChange, previousPosition, SEEK_SET);
      addTextToPosition(fileToChange, text, 0);
      fclose(fileToChange);
      remove(fileName);
      rename(TEMP_FILE, fileName);
    } else if (!compareVar) {
      throwError(71, 0, __LINE__);
      free(firstColumn);
      for (i = 0; i < COLUMN_MAX; i++)
        free(columnsHolder[i]);
      free(columnsHolder);
      free(stringToCompare);
      fclose(fileToChange);
      return -1;
    } else {
      fprintf(fileToChange, "%s", text);
      fclose(fileToChange);
    }
  } else {
    fprintf(fileToChange, "%s", text);
    fclose(fileToChange);
  }
  free(firstColumn);
  for (i = 0; i < COLUMN_MAX; i++)
    free(columnsHolder[i]);
  free(columnsHolder);
  free(stringToCompare);
  return 0;
}

void addTextToPosition(FILE* filePointer, char* text, int deleteLine) {
  long int currentPosition;
  char *stringHolder;
  FILE *tempFile;
  //add text if exists else only remove line
  if ((tempFile = fopen(TEMP_FILE, "w")) == NULL) {return;}
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  currentPosition = ftell(filePointer);
  fseek(filePointer, 0, SEEK_SET);
  while (ftell(filePointer) < currentPosition) {
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    fprintf(tempFile, "%s", stringHolder);
  }
  if (deleteLine) {fgets(stringHolder, MAX_LINE_SIZE, filePointer);}
  if (strlen(text)>0) {
    strcpy(stringHolder,text);
    strtok(stringHolder,"\n");
    fprintf(tempFile, "%s\n", stringHolder);
  }
  while (fgets(stringHolder, MAX_LINE_SIZE, filePointer)) {
    fprintf(tempFile, "%s", stringHolder);
  }
  free(stringHolder);
  fclose(tempFile);
}

void alterCourses() {
  char *operator, *textHolder;
  Course courseInstance, *updatedCourse, *currentCourse;
  int *arrayPointer, cont=1, control;
  FILE* filePointer;
  textHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  arrayPointer = (int*) malloc(COLUMN_MAX * sizeof(int));
  operator = (char*) malloc(COLUMN_MAX * sizeof(char));
  do {
    printf("[1] List courses\n"
            "[2] Add a course\n"
            "[3] Edit a course\n"
            "[4] Remove a course\n"
            "[5] List enrolled students\n"
            "[6] Back\n"
            "Select from above [1-6]: ");
    fgets(operator,COLUMN_MAX,stdin);
    switch (operator[0]) {
      case '1':
        listAllData(COURSES, COURSES_HEADER);
      break;
      case '2':
        printf("Enter course details.\n");
        printf("Code: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s", courseInstance.code);
        printf("Name: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s", courseInstance.name);
        printf("Credit: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%d", &courseInstance.credit);
        printf("Capacity: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%d", &courseInstance.capacity);
        printf("Instructor ID: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        if ((control = hasColumn(INSTRUCTORS, textHolder, 0)) != 1) {
          setColor(YELLOW);
          printf("No instructor with the ID %s. Try again:\n", textHolder);
          setColor(RESET);
          printf("Instructor ID: ");
          fgets(textHolder,MAX_COLUMN_SIZE,stdin);
          control = hasColumn(INSTRUCTORS, textHolder, 0);
        }
        if (control == 1) {
          sscanf(textHolder,"%s", courseInstance.instructorId);
          sprintf(textHolder, "%s,%s,%d,%d,%s\n", courseInstance.code, courseInstance.name, courseInstance.credit, courseInstance.capacity, courseInstance.instructorId);
          if (!addDataToFile(textHolder, COURSES)) {changeDataCounter(2,1);}
        } else {
          setColor(YELLOW);
          printf("The instructor should be registed before assigning them to a course.\n");
          setColor(RESET);
        }
      break;
      case '3':
        printf("Course code: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        strtok(textHolder, "\n");
        control = 0;
        if ((filePointer = fopen(COURSES, "r"))) {
          if (findDataPosition(filePointer, textHolder, 0) != -1) {
            fgets(textHolder, MAX_LINE_SIZE, filePointer);
            fclose(filePointer);
            currentCourse = parseToStruct(textHolder, 1);
            control = 1;
          } else {
            setColor(YELLOW);
            printf("Course doesn't exist!\n");
            setColor(RESET);
            fclose(filePointer);
          }
        } else {
          setColor(YELLOW);
          printf("Course doesn't exist!\n");
          setColor(RESET);
        }
        arrayPointer[0]=1,arrayPointer[1]=2,arrayPointer[2]=3,arrayPointer[3]=4,arrayPointer[4]=-1;
        if (control && !updateCourseDetails(currentCourse -> code)) {
          //apply the credit change to every enrolled student
          if ((filePointer = fopen(COURSES, "r"))) {
            findDataPosition(filePointer, currentCourse -> code, 0);
            fgets(textHolder, MAX_LINE_SIZE, filePointer);
            updatedCourse = parseToStruct(textHolder, 1);
            fclose(filePointer);
            if (updatedCourse && ((updatedCourse -> credit) - (currentCourse -> credit))) {
              updateAttendersCredit(currentCourse -> code, ((updatedCourse -> credit) - currentCourse -> credit));
              free(updatedCourse);
            } else if (updatedCourse) {
              free(updatedCourse);
            }
          }
          free(currentCourse);
        }
      break;
      case '4':
        printf("Course code: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s", courseInstance.code);
        if(unEnrollAllStudents(courseInstance.code)) {
          if(!deleteDataFromFile(courseInstance.code, COURSES)){changeDataCounter(2,0);}
        }
      break;
      case '5':
      printf("Course code: ");
      fgets(textHolder,MAX_COLUMN_SIZE,stdin);
      sscanf(textHolder,"%[^\n]s", courseInstance.code);
      listEnrolledStudents(courseInstance.code);
      break;
      default:
       cont=0;
    }
  } while(cont);
  free(operator);
  free(textHolder);
  free(arrayPointer);
}

void alterInstructors() {
  char *operator, *textHolder;
  Instructor instructorInstance;
  int *arrayPointer, cont=1;
  textHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  operator = (char*) malloc(COLUMN_MAX * sizeof(char));
  arrayPointer = (int*) malloc(COLUMN_MAX * sizeof(int));
  do {
    printf("[1] List instructors\n"
            "[2] Add an instructor\n"
            "[3] Update an instructor\n"
            "[4] Remove an instructor\n"
            "[5] Back\n"
            "Select from above [1-5]: ");
    fgets(operator,COLUMN_MAX,stdin);
    switch (operator[0]) {
      case '1':
        listAllData(INSTRUCTORS, INSTRUCTORS_HEADER);
      break;
      case '2':
        printf("Enter instructor details:\n");
        printf("ID: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s",instructorInstance.id);
        printf("Name: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s",instructorInstance.name);
        printf("Surname: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s",instructorInstance.surname);
        printf("Title: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s",instructorInstance.title);
        sprintf(textHolder, "%s,%s,%s,%s\n", instructorInstance.id, instructorInstance.name, instructorInstance.surname, instructorInstance.title);
        if (!addDataToFile(textHolder, INSTRUCTORS)) {changeDataCounter(3,1);}
      break;
      case '3':
        printf("Enter instructor's ID: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%s", instructorInstance.id);
        sprintf(textHolder,"%s",instructorInstance.id);
        arrayPointer[0]=1,arrayPointer[1]=2,arrayPointer[2]=3,arrayPointer[3]=-1;
        updateDataInFile(textHolder, INSTRUCTORS, arrayPointer, INSTRUCTORS_HEADER);
      break;
      case '4':
        printf("Enter instructor's ID: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        strtok(textHolder, "\n");
        if (hasColumn(COURSES, textHolder, 4) == 1) {
          setColor(YELLOW);
          printf("Instructor with the given ID (%s) has assigned course(s).\nPlease assign new instructors to the course(s) first.\n"
                  , textHolder);
          setColor(RESET);
        } else {
          if(!deleteDataFromFile(textHolder, INSTRUCTORS)) {
            changeDataCounter(3,0);
            deleteUser(textHolder, 2);
          }
        }
      break;
      default:
       cont=0;
    }
  } while(cont);
  free(operator);
  free(textHolder);
  free(arrayPointer);
}

void alterStudents() {
  char *operator, *textHolder;
  Student studentInstance;
  EnrollmentLog *logInstance;
  int *arrayPointer, cont=1;
  FILE* filePointer;
  textHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  operator = (char*) malloc(COLUMN_MAX * sizeof(char));
  arrayPointer = (int*) malloc(COLUMN_MAX * sizeof(int));
  do {
    printf("[1] List students\n"
            "[2] Add a student\n"
            "[3] Update a student\n"
            "[4] Remove a student\n"
            "[5] Print enrollment log\n"
            "[6] Back\n"
            "Select from above [1-6]: ");
    fgets(operator,COLUMN_MAX,stdin);
    switch (operator[0]) {
      case '1':
        listAllData(STUDENTS, STUDENTS_HEADER);
      break;
      case '2':
        printf("Enter student details:\n");
        printf("Number: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s",studentInstance.number);
        printf("Name: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s",studentInstance.name);
        printf("Surname: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s",studentInstance.surname);
        studentInstance.lessonCount = 0, studentInstance.totalCredit = 0;
        sprintf(textHolder, "%s,%s,%s,%d,%d\n", studentInstance.number, studentInstance.name, studentInstance.surname, studentInstance.lessonCount, studentInstance.totalCredit);
        if (!addDataToFile(textHolder, STUDENTS)) {changeDataCounter(4,1);}
      break;
      case '3':
        printf("Enter student details:\n");
        printf("Number: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s", studentInstance.number);
        arrayPointer[0]=1,arrayPointer[1]=2,arrayPointer[2]=-1;
        updateDataInFile(studentInstance.number, STUDENTS, arrayPointer, STUDENTS_HEADER);
      break;
      case '4':
        printf("Enter student details:\n");
        printf("Number: ");
        fgets(textHolder,MAX_COLUMN_SIZE,stdin);
        sscanf(textHolder,"%[^\n]s",studentInstance.number);
        if(!deleteDataFromFile(studentInstance.number, STUDENTS)) {
          changeDataCounter(4,0);
          deleteUser(studentInstance.number, 3);
          if ((filePointer = fopen(ENROLLMENT, "r"))) {
            while (findDataPosition(filePointer, studentInstance.number, 1) != -1) {
              fgets(textHolder, MAX_LINE_SIZE, filePointer);
              logInstance = parseToStruct(textHolder, 3);
              fclose(filePointer);
              if (logInstance) {
                sscanf(textHolder, "%d", &(logInstance -> id));
                deleteDataFromFile(textHolder, ENROLLMENT);
                changeDataCounter(5,0);
                free(logInstance);
              }
              if (!(filePointer = fopen(ENROLLMENT, "r"))) {
                throwError(67,0,__LINE__);
                free(operator);
                free(textHolder);
                free(arrayPointer);
                return;
              }
            }
            fclose(filePointer);
          }
        }
      break;
      case '5':
        listAllData(ENROLLMENT, ENROLLMENT_HEADER);
      break;
      default:
       cont=0;
    }
  } while(cont);
  free(operator);
  free(textHolder);
  free(arrayPointer);
}

void alterSettings() {
  FILE* filePointer;
  char *stringHolder, *tempStringHolder,**columnsHolder, *operator;
  int cont=1, i, *arrayPointer;
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  operator = (char*) malloc(COLUMN_MAX * sizeof(char));
  arrayPointer = (int*) malloc(COLUMN_MAX * sizeof(int));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  do {
    if ((filePointer = fopen(DB_INFO, "r+")) == NULL) {
      if (!createNewFile(DB_INFO)) {
        filePointer = fopen(DB_INFO, "r+");
        fprintf(filePointer, "30,10,0,0,0,0\n");
      } else {
        throwError(68, 0, __LINE__);
        free(arrayPointer);
        free(operator);
        free(stringHolder);
        for (i = 0; i < COLUMN_MAX; i++)
          free(columnsHolder[i]);
        free(columnsHolder);
        return;
      }
    }
    fseek(filePointer,0,SEEK_SET);
    fgets(stringHolder,MAX_LINE_SIZE,filePointer);
    i=0;
    tempStringHolder = strtok(stringHolder,",");
    strcpy(columnsHolder[i],tempStringHolder);
    i++;
    while ((tempStringHolder = strtok(NULL, ","))) {
      strcpy(columnsHolder[i],tempStringHolder),i++;
    }
    fclose(filePointer);
    strtok(columnsHolder[i-1], "\n");
    setColor(YELLOW);
    printf("The database has:\n");
    setColor(RESET);
    printf("%s courses, %s instructors, %s students, %s enrollment logs\n",columnsHolder[2], columnsHolder[3], columnsHolder[4],columnsHolder[5]);
    setColor(YELLOW);
    printf("Current settings:\n");
    setColor(RESET);
    printf("Credit limit: %s\nLesson Number Limit: %s\n", columnsHolder[0], columnsHolder[1]);
    printf("[1] Change settings\n"
            "[2] Back\n"
            "Select from above [1-2]: ");
    fgets(operator,COLUMN_MAX,stdin);
    switch (operator[0]) {
      case '1':
        setColor(YELLOW);
        printf("Already enrolled students won't be affected!\n");
        setColor(RESET);
        arrayPointer[0] = 0,arrayPointer[1] = 1,arrayPointer[2] = -1;
        updateDataInFile(columnsHolder[0], DB_INFO, arrayPointer, INFO_HEADER);
      break;
      default:
        cont=0;
    }
  } while(cont);
  free(arrayPointer);
  free(operator);
  free(stringHolder);
  for (i = 0; i < COLUMN_MAX; i++)
    free(columnsHolder[i]);
  free(columnsHolder);
}

void changeDataCounter(int dataColumn, int shouldIncrease) {
  FILE* filePointer;
  char *stringHolder, *tempStringHolder, **columnsHolder;
  int count, i, columnsCounter;
  long int position;
  if ((filePointer = fopen(DB_INFO, "r+")) == NULL) {
    if (!createNewFile(DB_INFO)) {
      filePointer = fopen(DB_INFO, "r+");
      fprintf(filePointer, "30,10,0,0,0,0\n");
      fseek(filePointer, 0, SEEK_SET);
    } else {
      throwError(68, 0, __LINE__);
      return;
    }
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  position = ftell(filePointer);
  fgets(stringHolder, MAX_LINE_SIZE, filePointer);
  i=0;
  tempStringHolder = strtok(stringHolder, ",");
  strcpy(columnsHolder[i], tempStringHolder);
  i++;
  while ((tempStringHolder = strtok(NULL, ",")))
    strcpy(columnsHolder[i], tempStringHolder),i++;
  columnsCounter = i;
  if (dataColumn < columnsCounter) {
    sscanf(columnsHolder[dataColumn], "%d", &count);
    shouldIncrease ? count++ : count--;
    sprintf(columnsHolder[dataColumn], "%d", count);
  } else {
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++)
      free(columnsHolder[i]);
    free(columnsHolder);
    fclose(filePointer);
    return;
  }
  strcpy(stringHolder, columnsHolder[0]);
  for (i = 0; i < columnsCounter-1; i++){
    strcat(stringHolder, ",");
    strcat(stringHolder, columnsHolder[i+1]);
  }
  fseek(filePointer, position, SEEK_SET);
  addTextToPosition(filePointer,stringHolder,1);
  free(stringHolder);
  for (i = 0; i < COLUMN_MAX; i++)
    free(columnsHolder[i]);
  free(columnsHolder);
  fclose(filePointer);
  remove(DB_INFO);
  rename(TEMP_FILE, DB_INFO);
}

int checkPassword(char* username, char* password, int userType) {
  FILE* filePointer;
  char *stringHolder, *decryptedUsername, *decryptedPassword;
  if (!(filePointer = fopen(USERS, "r"))) {
    return -1;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  decryptedUsername = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  decryptedPassword = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  while (fgets(stringHolder, MAX_LINE_SIZE, filePointer)) {
    if (userType == decryptPassword(decryptedUsername, decryptedPassword, stringHolder)) {
      if (!strcmp(username, decryptedUsername)) {
        if (!strcmp(password, decryptedPassword)) {
          free(stringHolder);
          free(decryptedUsername);
          free(decryptedPassword);
          fclose(filePointer);
          return 1;
        } else {
          free(stringHolder);
          free(decryptedUsername);
          free(decryptedPassword);
          fclose(filePointer);
          return 0;
        }
      }
    }
  }
  free(stringHolder);
  free(decryptedUsername);
  free(decryptedPassword);
  fclose(filePointer);
  return -1;
}

int countEnrollments(char* courseCode) {
  FILE* filePointer;
  char **columnsHolder, *stringHolder, *tempStringHolder;
  int i, statusColumn = 4, courseColumn = 2, j = 0;
  if ((filePointer = fopen(ENROLLMENT, "r")) == NULL) {
    throwError(67, 0, __LINE__);
    return -1;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  while (fgets(stringHolder, MAX_LINE_SIZE, filePointer)) {
    strtok(stringHolder, "\n");
    tempStringHolder = strtok(stringHolder, ",");
    i=0;
    strcpy(columnsHolder[i], tempStringHolder);
    i++;
    while ((tempStringHolder = strtok(NULL, ",")))
      strcpy(columnsHolder[i], tempStringHolder), i++;
    if (!strcmp(columnsHolder[courseColumn], courseCode) && !strcmp(columnsHolder[statusColumn], "1")) {j++;}
  }
  for (i = 0; i < COLUMN_MAX; i++)
    free(columnsHolder[i]);
  free(columnsHolder);
  free(stringHolder);
  fclose(filePointer);
  return j;
}

int countRows(FILE* filePointer) {
  char *stringToCompare, *control;
  long int previousPosition, position;
  int j=0;
  if (!filePointer) {
    setColor(RED);
    printf("Error: Can't use NULL pointer to count rows. Terminating current process\n");
    setColor(RESET);
    return -1;
  }
  stringToCompare = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  //loop through the file to find the position of key
  previousPosition = ftell(filePointer);
  control = fgets(stringToCompare,MAX_LINE_SIZE,filePointer);
  position = ftell(filePointer);
  if (control) {
    j++;
    while (fgets(stringToCompare,MAX_LINE_SIZE, filePointer)) {
      previousPosition = position;
      position = ftell(filePointer);
      j++;
    }
    fseek(filePointer, previousPosition, SEEK_SET);
  } else {
    free(stringToCompare);
    return 0;
  }
  free(stringToCompare);
  return j;
}

int createNewFile(char* fileName) {
  FILE* fileToCreate;
  if ((fileToCreate = fopen(fileName, "w")) == NULL) {
    throwError(68, 0, __LINE__);
    return -1;
  }
  fclose(fileToCreate);
  return 0;
}

void createPassword(char* username,char* password,int userType) {
  FILE* filePointer;
  char* stringHolder;
  if (!(filePointer = fopen(USERS, "a"))) {
    throwError(67, 0, __LINE__);
    return;
  }
  if (strlen(password) < 2) {
    setColor(RED);
    printf("Password should be at least two characters long!\n");
    setColor(RESET);
    fclose(filePointer);
    return;
  }
  //remove '\n' if it exists
  strtok(username, "\n"), strtok(password, "\n");
  stringHolder = encryptPassword(username, password, userType);
  strtok(stringHolder, "\n");
  fprintf(filePointer, "%s\n", stringHolder);
  free(stringHolder);
  fclose(filePointer);
  setColor(GREEN);
  printf("Success. Log in using your password.\n");
  setColor(RESET);
}

int decryptPassword(char* username, char* password, char* encryptedPassword) {
  int magicNum, length, i, j, userType;
  strtok(encryptedPassword, "\n");
  magicNum = encryptedPassword[2] - ':';
  userType = encryptedPassword[1] - '[' - magicNum;
  length = encryptedPassword[0] - '!' - magicNum;
  for (i = 0; i < length; i++) {
    username[i] = encryptedPassword[3+i] - magicNum;
  }
  username[i] = 0;
  j=0;
  while (encryptedPassword[3+i+j] != 0) {
    password[j] = encryptedPassword[3+i+j] - magicNum;
    j++;
  }
  password[j] = 0;
  return userType;
}

int deleteDataFromFile(char* key, char* fileName) {
  char *control, *firstColumn, *prompt, *stringToCompare, *tempStringHolder;
  FILE* fileToChange;
  long int previousPosition, position;
  int i;
  //check if the file can be opened with "r+" if not ask to create it
  if ((fileToChange = fopen(fileName, "r+")) == NULL) {
    prompt = (char*) malloc(COLUMN_MAX * sizeof(char));
    printf("Warning: Couldn't open the file %s.\n", fileName);
    setColor(RED);
    printf("(The following WILL delete any existing file with the same name)");
    setColor(RESET);
    printf("\nShould I (re)create it? (y/n): ");
    fgets(prompt,COLUMN_MAX,stdin);
    if (prompt[0] == 'Y' || prompt[0] == 'y') {
      if (!createNewFile(fileName)) {
        printf("info: Created %s successfully\n", fileName);
        fileToChange = fopen(fileName, "r+");
      } else {
        return -1;
      }
      free(prompt);
    } else {
      printf("Terminating the process without adding data...\n");
      free(prompt);
      return -1;
    }
  }
  stringToCompare = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  firstColumn = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  //loop through the file to determine where to add text
  previousPosition = ftell(fileToChange);
  if ((control = fgets(stringToCompare,MAX_LINE_SIZE,fileToChange))) {
    //divide the string into columns based on ','
    i = 0;
    tempStringHolder = strtok(stringToCompare, ",");
    strcpy(firstColumn, tempStringHolder);
    i++;
    while ((tempStringHolder = strtok(NULL,",")) && i < COLUMN_MAX)
      i++;
  }
  position = ftell(fileToChange);
  if (control) {
    while (strcmp(firstColumn, key) && fgets(stringToCompare,MAX_LINE_SIZE, fileToChange)) {
      tempStringHolder = strtok(stringToCompare, ",");
      previousPosition = position;
      position = ftell(fileToChange);
      strcpy(firstColumn, tempStringHolder);
      i=1;
      while ((tempStringHolder = strtok(NULL, ",")))
        i++;
    }
    if (!strcmp(firstColumn, key)) {
      fseek(fileToChange, previousPosition, SEEK_SET);
      addTextToPosition(fileToChange, "", 1);
      fclose(fileToChange);
      remove(fileName);
      rename(TEMP_FILE, fileName);
      setColor(GREEN);
      printf("Deleted %s successfully\n", key);
      setColor(RESET);
    } else {
      throwError(69, 1, __LINE__);
      fclose(fileToChange);
      free(firstColumn);
      free(stringToCompare);
      return -1;
    }
  } else {
    throwError(69, 1, __LINE__);
    fclose(fileToChange);
    free(firstColumn);
    free(stringToCompare);
    return -1;
  }
  free(firstColumn);
  free(stringToCompare);
  return 0;
}

int deleteUser(char* username,int userType) {
  FILE* filePointer;
  long int position, previousPosition;
  int decryptedUserType;
  char *stringHolder, *control, *decryptedPassword, *decryptedUsername;
  if (!(filePointer = fopen(USERS, "r+"))) {
    throwError(67,0,__LINE__);
    return -1;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  decryptedUsername = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  decryptedPassword = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  previousPosition = ftell(filePointer);
  strtok(username, "\n");
  if ((control = fgets(stringHolder, MAX_LINE_SIZE, filePointer))) {
    decryptedUserType = decryptPassword(decryptedUsername, decryptedPassword, stringHolder);
  }
  position = ftell(filePointer);
  if (!control) {
    throwError(69,0, __LINE__);
    free(stringHolder);
    free(decryptedUsername);
    free(decryptedPassword);
    fclose(filePointer);
    return -1;
  }
  //loop while user is not found and not reached EOF
  while ((strcmp(username, decryptedUsername) || (decryptedUserType != userType)) && fgets(stringHolder,MAX_LINE_SIZE,filePointer)) {
    decryptedUserType = decryptPassword(decryptedUsername, decryptedPassword, stringHolder);
    previousPosition = position;
    position = ftell(filePointer);
  }
  if (!strcmp(username, decryptedUsername) && (decryptedUserType == userType)) {
    fseek(filePointer, previousPosition, SEEK_SET);
    addTextToPosition(filePointer, "", 1);
  } else {
    setColor(RED);
    printf("User won't be deleted as they don't exist.\n");
    setColor(RESET);
    free(stringHolder);
    free(decryptedUsername);
    free(decryptedPassword);
    fclose(filePointer);
    return -1;
  }
  free(decryptedUsername);
  free(decryptedPassword);
  free(stringHolder);
  fclose(filePointer);
  remove(USERS);
  rename(TEMP_FILE, USERS);
  return 0;
}

char* encryptPassword(char* username, char* password, int userType) {
  int magicNum = rand() % 5 + 1, i,j;
  char* encryptedPassword;
  encryptedPassword = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  encryptedPassword[0] = strlen(username) + '!' + magicNum;
  encryptedPassword[1] = userType % 10 + '[' + magicNum; //expects values under 10, the modulus is only to prevent possible errors
  encryptedPassword[2] = ':' + magicNum;
  i=0;
  while (username[i] != 0) {
    encryptedPassword[3+i] = username[i] + magicNum;
    i++;
  }
  j=0;
  while (password[j] != 0) {
    encryptedPassword[3+i] = password[j] + magicNum;
    i++,j++;
  }
  encryptedPassword[3+i] = 0;
  return encryptedPassword;
}

void enrollStudent(char* studentNumber, char* courseCode) {
  int courseCapacity, courseCredit, enrolledCounter, i, lastId, studentLessonNumber, studentCreditNumber;
  int maxCredit, maxCourseNumber;
  long int position;
  EnrollmentLog logInstance;
  //column numbers in the file
  int capacityColumn =3, creditColumn = 2;
  char *stringHolder, **columnsHolder, *dateString, *tempStringHolder;
  FILE* filePointer;
  if (!(filePointer = fopen(COURSES, "r"))) {
    setColor(RED);
    printf("Error: Can't access courses. Make sure at least a course is defined.\n");
    setColor(RESET);
    return;
  }
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  if (findDataPosition(filePointer, courseCode, 0) == -1) {
    throwError(81, 0, __LINE__);
    fclose(filePointer);
    return;
  }
  dateString = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  fgets(stringHolder, MAX_LINE_SIZE, filePointer);
  fclose(filePointer);
  //print the date of the day to dateString
  sprintf(dateString, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
  //divide the string into columns based on ','
  tempStringHolder = strtok(stringHolder, ",");
  i=0;
  strcpy(columnsHolder[i], tempStringHolder);
  i++;
  while ((tempStringHolder = strtok(NULL,","))) {
    strcpy(columnsHolder[i], tempStringHolder);
    i++;
  }
  sscanf(columnsHolder[creditColumn], "%d", &courseCredit);
  sscanf(columnsHolder[capacityColumn], "%d", &courseCapacity);
  if (!(filePointer = fopen(STUDENTS, "r+"))) {
    throwError(67, 0, __LINE__);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    return;
  }
  //check if the student exists
  if (getColumnString(filePointer, studentNumber, 0, 3, stringHolder) == -1) {
    setColor(RED);
    printf("Student doesn't exist\n");
    setColor(RESET);
    throwError(69,1,__LINE__);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    fclose(filePointer);
    return;
  }
  //get the number of the courses the student is enrolled in
  sscanf(stringHolder, "%d", &studentLessonNumber);
  getColumnString(filePointer, studentNumber, 0, 4, stringHolder);
  sscanf(stringHolder, "%d", &studentCreditNumber);
  fclose(filePointer);
  //get the max number of the courses the student can enroll
  if (!(filePointer = fopen(DB_INFO, "r"))) {
    throwError(67, 0, __LINE__);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    return;
  }
  getColumnString(filePointer, "", 0, 0, stringHolder);
  sscanf(stringHolder, "%d", &maxCredit);
  getColumnString(filePointer, "", 0, 1, stringHolder);
  sscanf(stringHolder, "%d", &maxCourseNumber);
  if (studentLessonNumber >= maxCourseNumber) {
    setColor(RED);
    printf("Can't exceed allowed maximum course number. Terminating without adding course.\n");
    setColor(RESET);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    fclose(filePointer);
    return;
  } else if ((studentCreditNumber + courseCredit) >= maxCredit) {
    setColor(RED);
    printf("Can't exceed allowed maximum credit. Terminating without adding course.\n");
    setColor(RESET);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    fclose(filePointer);
    return;
  }
  fclose(filePointer);
  if (!(filePointer = fopen(ENROLLMENT, "r+"))) {
    if (createNewFile(ENROLLMENT)) {
      throwError(67,0,__LINE__);
      free(stringHolder);
      for (i = 0; i < COLUMN_MAX; i++) {
        free(columnsHolder[i]);
      }
      free(columnsHolder);
      free(dateString);
      return;
    }
    if (!(filePointer = fopen(ENROLLMENT, "r+"))) {
      throwError(67,0,__LINE__);
      free(stringHolder);
      for (i = 0; i < COLUMN_MAX; i++) {
        free(columnsHolder[i]);
      }
      free(columnsHolder);
      free(dateString);
      return;
    }
  }
  if ((lastId = isEnrolled(filePointer, studentNumber, courseCode)) == 2) {
    setColor(YELLOW);
    printf("Already enrolled in %s.\n", courseCode);
    setColor(RESET);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    fclose(filePointer);
    return;
  } else if (lastId == -1) {
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    return;
    //the only value other than zero is 1. Check isEnrolled documentation
  } else if (lastId) {
    position = ftell(filePointer);
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    fseek(filePointer, position, SEEK_SET);
    strtok(stringHolder, "\n");
    tempStringHolder = strtok(stringHolder, ",");
    i=0;
    strcpy(columnsHolder[i], tempStringHolder);
    i++;
    while ((tempStringHolder = strtok(NULL, ",")))
      strcpy(columnsHolder[i], tempStringHolder), i++;
    //get enrollment log from file and parse it
    i=0;
    sscanf(columnsHolder[i],"%d",&logInstance.id),i++;
    sscanf(columnsHolder[i],"%s",logInstance.studentNumber),i++;
    sscanf(columnsHolder[i],"%s",logInstance.courseCode),i++;
    sscanf(columnsHolder[i],"%s",logInstance.date),i++;
    sscanf(columnsHolder[i],"%d",&logInstance.enrolled),i++;
    strcpy(logInstance.date, dateString);
    logInstance.enrolled = 1;
    sprintf(stringHolder,"%d,%s,%s,%s,%d",logInstance.id,logInstance.studentNumber,logInstance.courseCode,
            logInstance.date, logInstance.enrolled);
    addTextToPosition(filePointer, stringHolder,1);
    fclose(filePointer);
    remove(ENROLLMENT);
    rename(TEMP_FILE, ENROLLMENT);
    updateStudentEnrollment(studentNumber, courseCredit,1, 1);
    setColor(GREEN);
    printf("Enrolled in %s successfully.\n", courseCode);
    setColor(RESET);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    return;
  }
  fclose(filePointer);
  //open the enrollmentLog file to count number of enrollments
  if((enrolledCounter = countEnrollments(courseCode)) != -1) {
    if (enrolledCounter < courseCapacity) {
      if((filePointer = fopen(ENROLLMENT, "r+"))) {
        if (countRows(filePointer) > 0) {
          fgets(stringHolder,MAX_LINE_SIZE,filePointer);
          tempStringHolder = strtok(stringHolder,",");
          sscanf(tempStringHolder, "%d",&lastId);
          fclose(filePointer);
          if (!(filePointer = fopen(ENROLLMENT, "a"))) {
            free(stringHolder);
            for (i = 0; i < COLUMN_MAX; i++) {
              free(columnsHolder[i]);
            }
            free(columnsHolder);
            free(dateString);
            return;
          }
          fprintf(filePointer, "%d,%s,%s,%s,1\n",lastId+1,studentNumber,courseCode,dateString);
        } else {
          fprintf(filePointer, "0,%s,%s,%s,1\n",studentNumber,courseCode,dateString);
        }
        setColor(GREEN);
        printf("Enrolled in %s successfully.\n", courseCode);
        setColor(RESET);
        fclose(filePointer);
        changeDataCounter(5,1);
        updateStudentEnrollment(studentNumber,courseCredit,1,1);
      } else {
        throwError(67, 0, __LINE__);
        free(stringHolder);
        for (i = 0; i < COLUMN_MAX; i++) {
          free(columnsHolder[i]);
        }
        free(columnsHolder);
        free(dateString);
        return;
      }
    } else {
      throwError(80, 0, __LINE__);
    }
  } else {
    if(!createNewFile(ENROLLMENT)) {
      free(stringHolder);
      for (i = 0; i < COLUMN_MAX; i++) {
        free(columnsHolder[i]);
      }
      free(columnsHolder);
      free(dateString);
      return;
    }
    //add the log directly to the newly created log file if capacity is not 0
    if (courseCapacity) {
      if(!(filePointer = fopen(ENROLLMENT, "w"))){
        throwError(67, 0, __LINE__);
        free(stringHolder);
        for (i = 0; i < COLUMN_MAX; i++) {
          free(columnsHolder[i]);
        }
        free(columnsHolder);
        free(dateString);
        return;
      }
      fprintf(filePointer, "0,%s,%s,%s,1\n",studentNumber,courseCode,dateString);
      setColor(GREEN);
      printf("Enrolled in %s successfully.\n", courseCode);
      setColor(RESET);
      fclose(filePointer);
      changeDataCounter(5,1);
      updateStudentEnrollment(studentNumber,courseCredit,1,1);
    } else {
      throwError(80,0, __LINE__);
    }
  }
  free(stringHolder);
  for (i = 0; i < COLUMN_MAX; i++) {
    free(columnsHolder[i]);
  }
  free(columnsHolder);
  free(dateString);
}

int exportEnrolledStudents(char* courseCode) {
  FILE *filePointer, *fileToCreate;
  long int position;
  char *stringHolder;
  EnrollmentLog *logInstance;
  Student *studentInstance;
  if (!(filePointer = fopen(ENROLLMENT, "r"))) {
    throwError(67,0,__LINE__);
    return -1;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  sprintf(stringHolder, "%s_studentList.txt", courseCode);
  if (!(fileToCreate = fopen(stringHolder, "w"))) {
    free(stringHolder);
    throwError(68,0,__LINE__);
    return -1;
  }
  setColor(YELLOW);
  printf("Number - Name - Surname\n");
  setColor(RESET);
  while (findDataPosition(filePointer, courseCode, 2) != -1) {
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    position = ftell(filePointer);
    fclose(filePointer);
    logInstance = parseToStruct(stringHolder,3);
    if (logInstance -> enrolled) {
      if (!(filePointer = fopen(STUDENTS, "r"))) {
        free(logInstance);
        free(stringHolder);
        return -1;
      }
      if (findDataPosition(filePointer, logInstance -> studentNumber, 0)) {
        fgets(stringHolder, MAX_LINE_SIZE, filePointer);
        studentInstance = parseToStruct(stringHolder, 0);
        printf("%s - %s - %s\n", studentInstance -> number,studentInstance -> name,
                studentInstance -> surname);
        fprintf(fileToCreate, "%s - %s - %s\n", studentInstance -> number,studentInstance -> name,
                studentInstance -> surname);
        free(studentInstance);
      }
    }
    free(logInstance);
    fclose(filePointer);
    if (!(filePointer = fopen(ENROLLMENT, "r"))) {
      throwError(67,0,__LINE__);
      return -1;
    }
    fseek(filePointer, position, SEEK_SET);
  }
  setColor(YELLOW);
  printf("\t===END OF DATA===\n");
  setColor(RESET);
  free(stringHolder);
  fclose(fileToCreate);
  fclose(filePointer);
  return 0;
}

int findDataPosition(FILE* filePointer, char* key, int columnNumber) {
  char *control, *columnHolder, *stringToCompare, *tempStringHolder;
  long int previousPosition, position;
  int i,j=0;
  if (!filePointer) {
    setColor(RED);
    printf("Error: Can't use NULL pointer to search. Terminating current process\n");
    setColor(RESET);
    return -1;
  }
  strtok(key, "\n");
  stringToCompare = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnHolder = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  //loop through the file to find the position of key
  previousPosition = ftell(filePointer);
  if ((control = fgets(stringToCompare,MAX_LINE_SIZE,filePointer))) {
    //divide the string into columns based on ','
    tempStringHolder = strtok(stringToCompare, ",");
    i = 0;
    while (i < columnNumber && (tempStringHolder = strtok(NULL,",")))
      i++;
    strcpy(columnHolder, tempStringHolder);
    strtok(columnHolder, "\n");
    j++;
  }
  position = ftell(filePointer);
  if (control) {
    while (strcmp(columnHolder, key) && fgets(stringToCompare,MAX_LINE_SIZE, filePointer)) {
      previousPosition = position;
      position = ftell(filePointer);
      tempStringHolder = strtok(stringToCompare, ",");
      i=0;
      while (i < columnNumber && (tempStringHolder = strtok(NULL, ",")))
        i++;
      strcpy(columnHolder, tempStringHolder);
      strtok(columnHolder, "\n");
      j++;
    }
    if (!strcmp(columnHolder, key)) {
      fseek(filePointer, previousPosition, SEEK_SET);
    } else {
      free(columnHolder);
      free(stringToCompare);
      return -1;
    }
  } else {
    free(columnHolder);
    free(stringToCompare);
    return -1;
  }
  free(columnHolder);
  free(stringToCompare);
  return j;
}

int getColumnString(FILE* filePointer, char* key, int keyColumnNumber, int stringColumnNumber, char* returnString) {
  char *stringHolder, *tempStringHolder;
  int i, dataPosition;
  long int position;
  if (strlen(key) > 0) {
    if ((dataPosition = findDataPosition(filePointer, key, keyColumnNumber)) != -1) {
      stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
      position = ftell(filePointer);
      fgets(stringHolder, MAX_LINE_SIZE, filePointer);
      fseek(filePointer, position, SEEK_SET);
      i = 0;
      tempStringHolder = strtok(stringHolder, ",");
      while (i < stringColumnNumber && (tempStringHolder = strtok(NULL, ",")))
        i++;
      strcpy(returnString, tempStringHolder);
      free(stringHolder);
      return dataPosition;
    } else {
      return dataPosition;
    }
  } else {
    stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    position = ftell(filePointer);
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    fseek(filePointer, position, SEEK_SET);
    i = 0;
    tempStringHolder = strtok(stringHolder, ",");
    while (i < stringColumnNumber && (tempStringHolder = strtok(NULL, ",")))
      i++;
    strcpy(returnString, tempStringHolder);
    free(stringHolder);
    return 1;
  }
}

void greetAdmin(char* username, char* password) {
  int cont=1, control;
  char *operator, *stringHolder;
  if (!(control = checkPassword(username, password, 1))) {
    setColor(RED);
    printf("Wrong password.\n");
    setColor(RESET);
    return;
  } else if(control == -1) {
    stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    printf("Hi %s. Create a password: ",username);
    fgets(stringHolder, MAX_LINE_SIZE, stdin);
    strtok(stringHolder, "\n");
    createPassword(username, stringHolder, 1);
    free(stringHolder);
    return;
  }
  operator = (char*) malloc(COLUMN_MAX * sizeof(char));
  do {
    clearConsole();
    printf("Welcome %s!\n"
            "[1] Change settings\n"
            "[2] Instructor operations\n"
            "[3] Student operations\n"
            "[4] Course operations\n"
            "[5] Log out\n"
            "Select from above [1-5]: ", username);
    fgets(operator,COLUMN_MAX,stdin);
    clearConsole();
    switch (operator[0]) {
      case '1':
        alterSettings();
      break;
      case '2':
        alterInstructors();
      break;
      case '3':
        alterStudents();
      break;
      case '4':
        alterCourses();
      break;
      default:
      cont = 0;
    }
  } while(cont);
  free(operator);
}

void greetInstructor(char* username, char* password) {
  int cont=1, *arrayPointer, control;
  char *operator, *stringHolder, *columnHolder;
  FILE* filePointer;
  Instructor *instructorInstance;
  Course *courseInstance;
  if (!(control = checkPassword(username, password, 2))) {
    setColor(RED);
    printf("Wrong password.\n");
    setColor(RESET);
    return;
  } else if(control == -1) {
    stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    if (hasColumn(INSTRUCTORS,username,0) == 1) {
      printf("Create a password for %s: ",username);
      fgets(stringHolder, MAX_LINE_SIZE, stdin);
      strtok(stringHolder, "\n");
      createPassword(username, stringHolder, 2);
      free(stringHolder);
      return;
    } else {
      setColor(RED);
      printf("User doesn't exist\n");
      setColor(RESET);
      free(stringHolder);
      return;
    }
  }
  operator = (char*) malloc(COLUMN_MAX * sizeof(char));
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnHolder = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  arrayPointer = (int*) malloc(COLUMN_MAX * sizeof(int));
  do {
    //Get instructor info to print
    if(!(filePointer = fopen(INSTRUCTORS, "r"))) {
      throwError(67,0,__LINE__);
      free(columnHolder);
      free(stringHolder);
      free(operator);
      free(arrayPointer);
      return;
    }
    if (findDataPosition(filePointer, username, 0) < 1) {
      setColor(RED);
      printf("Can't find instructor (%s).\n", username);
      setColor(RESET);
      free(stringHolder);
      free(columnHolder);
      free(arrayPointer);
      free(operator);
      fclose(filePointer);
      return;
    }
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    fclose(filePointer);
    instructorInstance = parseToStruct(stringHolder,2);
    setColor(YELLOW);
    printf("Welcome %s %s %s!\n", instructorInstance -> title, instructorInstance -> name, instructorInstance -> surname);
    setColor(RESET);
    free(instructorInstance);
    printf( "[1] List assigned courses\n"
            "[2] Edit course details\n"
            "[3] Export enrolled students list\n"
            "[4] Log out\n"
            "Select from above [1-4]: ");
    fgets(operator,COLUMN_MAX,stdin);
    switch (operator[0]) {
      case '1':
        listAssignedCourses(username);
      break;
      case '2':
        printf("Course code: ");
        fgets(columnHolder, MAX_COLUMN_SIZE, stdin);
        strtok(columnHolder, "\n");
        //open file then get the course info and check if it is assigned to instructor
        if (!(filePointer = fopen(COURSES, "r"))) {
          setColor(RED);
          printf("Course doesn't exist.\n");
          setColor(RESET);
        } else {
          if (findDataPosition(filePointer, columnHolder, 0) != -1) {
              fgets(stringHolder, MAX_LINE_SIZE, filePointer);
              courseInstance = parseToStruct(stringHolder, 1);
              if (strcmp(courseInstance -> instructorId, username)) {
                setColor(YELLOW);
                printf("Sorry, you are not assigned such a course.\n");
                setColor(RESET);
              } else {
                arrayPointer[0]=1,arrayPointer[1]=3,arrayPointer[2]=-1;
                updateDataInFile(courseInstance -> code, COURSES, arrayPointer, COURSES_HEADER);
              }
              free(courseInstance);
          } else {
            setColor(RED);
            printf("Course doesn't exist.\n");
            setColor(RESET);
          }
          fclose(filePointer);
        }
      break;
      case '3':
      printf("Course code: ");
      fgets(columnHolder, MAX_COLUMN_SIZE, stdin);
      strtok(columnHolder, "\n");
      //open file then get the course info and check if it is assigned to instructor
      if (!(filePointer = fopen(COURSES, "r"))) {
        setColor(RED);
        printf("Course doesn't exist.\n");
        setColor(RESET);
      } else {
        if (findDataPosition(filePointer, columnHolder, 0) != -1) {
            fgets(stringHolder, MAX_LINE_SIZE, filePointer);
            courseInstance = parseToStruct(stringHolder, 1);
            if (strcmp(courseInstance -> instructorId, username)) {
              setColor(YELLOW);
              printf("Sorry, you are not assigned such a course.\n");
              setColor(RESET);
              fclose(filePointer);
            } else {
              fclose(filePointer);
              exportEnrolledStudents(courseInstance -> code);
            }
            free(courseInstance);
        } else {
          setColor(RED);
          printf("Course doesn't exist.\n");
          setColor(RESET);
          fclose(filePointer);
        }
      }
      break;
      default:
        cont = 0;
    }
  } while(cont);
  clearConsole();
  free(columnHolder);
  free(arrayPointer);
  free(stringHolder);
  free(operator);
}

void greetStudent(char* username, char* password) {
  int cont=1, control;
  char *operator, *stringHolder;
  FILE* filePointer;
  Student* studentInstance;
  if (!(control = checkPassword(username, password, 3))) {
    setColor(RED);
    printf("Wrong password.\n");
    setColor(RESET);
    return;
  } else if(control == -1) {
    stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    if (hasColumn(STUDENTS,username,0) == 1) {
      printf("Create a password for %s: ",username);
      fgets(stringHolder, MAX_LINE_SIZE, stdin);
      strtok(stringHolder, "\n");
      createPassword(username, stringHolder, 3);
      free(stringHolder);
      return;
    } else {
      setColor(RED);
      printf("User doesn't exist\n");
      setColor(RESET);
      free(stringHolder);
      return;
    }
  }
  operator = (char*) malloc(COLUMN_MAX * sizeof(char));
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  do {
    //Get student info to print
    if(!(filePointer = fopen(STUDENTS, "r"))) {
      throwError(67,0,__LINE__);
      free(stringHolder);
      free(operator);
      return;
    }
    if (findDataPosition(filePointer, username, 0) < 1) {
      setColor(RED);
      printf("Can't find student (%s).\n", username);
      setColor(RESET);
      free(stringHolder);
      free(operator);
      fclose(filePointer);
      return;
    }
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    fclose(filePointer);
    studentInstance = parseToStruct(stringHolder,0);
    setColor(YELLOW);
    printf("Welcome %s %s!\n", studentInstance -> name, studentInstance -> surname);
    printf("Your credit: %d\t Number of courses: %d\n", studentInstance -> totalCredit, studentInstance -> lessonCount);
    setColor(RESET);
    free(studentInstance);
    printf( "[1] List enrolled courses\n"
            "[2] List available courses\n"
            "[3] Enroll in a course\n"
            "[4] Drop a course\n"
            "[5] Log out\n"
            "Select from above [1-5]: ");
    fgets(operator,COLUMN_MAX,stdin);
    clearConsole();
    switch (operator[0]) {
      case '1':
        listStudentEnrollments(username);
      break;
      case '2':
        listAllData(COURSES, COURSES_HEADER);
      break;
      case '3':
        printf("Enter course code: ");
        fgets(operator, COLUMN_MAX, stdin);
        strtok(operator, "\n");
        enrollStudent(username, operator);
      break;
      case '4':
        printf("Enter course code: ");
        fgets(operator, COLUMN_MAX, stdin);
        strtok(operator, "\n");
        unEnrollStudent(username, operator,1);
      break;
      default:
        cont = 0;
    }
  } while(cont);
  free(stringHolder);
  free(operator);
}

int hasColumn(char* fileName,char* key,int columnNumber) {
  char *control, *columnHolder, *stringToCompare, *tempStringHolder;
  int i;
  FILE* filePointer;
  if (!(filePointer = fopen(fileName, "r"))) {
    setColor(RED);
    throwError(67,0,__LINE__);
    setColor(RESET);
    return -1;
  }
  stringToCompare = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnHolder = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  //loop through the file to find the position of key
  strtok(key,"\n");
  if ((control = fgets(stringToCompare,MAX_LINE_SIZE,filePointer))) {
    //divide the string into columns based on ','
    tempStringHolder = strtok(stringToCompare, ",");
    i = 0;
    while (i < columnNumber && (tempStringHolder = strtok(NULL,",")))
      i++;
    strcpy(columnHolder, tempStringHolder);
    strtok(columnHolder,"\n");
  }
  if (control) {
    while (strcmp(columnHolder, key) && fgets(stringToCompare,MAX_LINE_SIZE, filePointer)) {
      tempStringHolder = strtok(stringToCompare, ",");
      i=0;
      while (i < columnNumber && (tempStringHolder = strtok(NULL, ",")))
        i++;
      strcpy(columnHolder, tempStringHolder);
    }
    if (strcmp(columnHolder, key)) {
      free(columnHolder);
      free(stringToCompare);
      fclose(filePointer);
      return 0;
    }
  } else {
    free(columnHolder);
    free(stringToCompare);
    fclose(filePointer);
    return 0;
  }
  free(columnHolder);
  free(stringToCompare);
  fclose(filePointer);
  return 1;
}

int isEnrolled(FILE* filePointer, char* studentNumber, char* courseCode) {
  char **columnsHolder, *stringHolder, *tempStringHolder;
  int i, numberColumn = 1, courseColumn = 2,statusColumn = 4;
  long int position, previousPosition;
  if (!filePointer) {
    return -1;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  previousPosition = ftell(filePointer);
  position = previousPosition;
  while (fgets(stringHolder, MAX_LINE_SIZE, filePointer)) {
    previousPosition = position;
    position = ftell(filePointer);
    strtok(stringHolder, "\n");
    tempStringHolder = strtok(stringHolder, ",");
    i=0;
    strcpy(columnsHolder[i], tempStringHolder);
    i++;
    while ((tempStringHolder = strtok(NULL, ",")))
      strcpy(columnsHolder[i], tempStringHolder), i++;
    if (!strcmp(columnsHolder[courseColumn], courseCode) && !strcmp(columnsHolder[numberColumn], studentNumber)) {
      if (!strcmp(columnsHolder[statusColumn], "1")) {
        fseek(filePointer, previousPosition, SEEK_SET);
        for (i = 0; i < COLUMN_MAX; i++)
          free(columnsHolder[i]);
        free(columnsHolder);
        free(stringHolder);
        return 2;
      } else {
        fseek(filePointer, previousPosition, SEEK_SET);
        for (i = 0; i < COLUMN_MAX; i++)
          free(columnsHolder[i]);
        free(columnsHolder);
        free(stringHolder);
        return 1;
      }
    }
  }
  fseek(filePointer, previousPosition, SEEK_SET);
  for (i = 0; i < COLUMN_MAX; i++)
    free(columnsHolder[i]);
  free(columnsHolder);
  free(stringHolder);
  return 0;
}

void listAllData(char* fileName, const char* headerRow) {
  FILE* filePointer;
  char *stringHolder, *tempStringHolder;
  if ((filePointer = fopen(fileName, "r")) == NULL) {
    throwError(67, 0, __LINE__);
    return;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  setColor(YELLOW);
  printf("%s\n", headerRow);
  setColor(RESET);
  while (fgets(stringHolder, MAX_LINE_SIZE, filePointer)) {
    tempStringHolder = strtok(stringHolder,",");
    printf("%s", tempStringHolder);
    while ((tempStringHolder = strtok(NULL, ",")))
      printf(" - %s", tempStringHolder);
  }
  setColor(YELLOW);
  printf("\t=== END OF DATA ===\n");
  setColor(RESET);
  free(stringHolder);
  fclose(filePointer);
}

void listStudentEnrollments(char* studentNumber) {
  FILE* filePointer;
  char* stringHolder;
  EnrollmentLog* logInstance;
  int j=0;
  if (!(filePointer = fopen(ENROLLMENT,"r"))) {
    throwError(67,0,__LINE__);
    return;
  }
  setColor(YELLOW);
  printf("Course Code - Enrollment Date");
  printf("\n");
  setColor(RESET);
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  while (findDataPosition(filePointer, studentNumber, 1) != -1) {
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    logInstance = parseToStruct(stringHolder, 3);
    if (logInstance -> enrolled) {
      printf("%s - %s\n",logInstance -> courseCode, logInstance -> date);
      j++;
    }
    free(logInstance);
  }
  setColor(YELLOW);
  printf("\t=== END OF DATA ===\n");
  setColor(RESET);
  printf("You are enrolled in %d course(s).\n", j);
  free(stringHolder);
  fclose(filePointer);
}

void listAssignedCourses(char* instructorId) {
  FILE* filePointer;
  char* stringHolder;
  Course* courseInstance;
  int j=0;
  if (!(filePointer = fopen(COURSES,"r"))) {
    throwError(67,0,__LINE__);
    return;
  }
  setColor(YELLOW);
  printf("Code - Name - Credit - Capacity");
  printf("\n");
  setColor(RESET);
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  while (findDataPosition(filePointer, instructorId, 4) != -1) {
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    courseInstance = parseToStruct(stringHolder, 1);
    printf("%s - %s - %d - %d\n",courseInstance -> code, courseInstance -> name,
            courseInstance -> credit, courseInstance -> capacity);
    j++;
    free(courseInstance);
  }
  setColor(YELLOW);
  printf("\t=== END OF DATA ===\n");
  setColor(RESET);
  printf("You are assigned %d course(s).\n", j);
  free(stringHolder);
  fclose(filePointer);
}

int listEnrolledStudents(char* courseCode) {
  FILE *filePointer;
  long int position;
  char *stringHolder;
  EnrollmentLog *logInstance;
  Student *studentInstance;
  if (!(filePointer = fopen(ENROLLMENT, "r"))) {
    throwError(67,0,__LINE__);
    return -1;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  setColor(YELLOW);
  printf("Number - Name - Surname\n");
  setColor(RESET);
  while (findDataPosition(filePointer, courseCode, 2) != -1) {
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    position = ftell(filePointer);
    fclose(filePointer);
    logInstance = parseToStruct(stringHolder,3);
    if (logInstance -> enrolled) {
      if (!(filePointer = fopen(STUDENTS, "r"))) {
        free(logInstance);
        free(stringHolder);
        return -1;
      }
      if (findDataPosition(filePointer, logInstance -> studentNumber, 0)) {
        fgets(stringHolder, MAX_LINE_SIZE, filePointer);
        studentInstance = parseToStruct(stringHolder, 0);
        printf("%s - %s - %s\n", studentInstance -> number,studentInstance -> name,
                studentInstance -> surname);
        free(studentInstance);
      }
    }
    free(logInstance);
    fclose(filePointer);
    if (!(filePointer = fopen(ENROLLMENT, "r"))) {
      throwError(67,0,__LINE__);
      return -1;
    }
    fseek(filePointer, position, SEEK_SET);
  }
  setColor(YELLOW);
  printf("\t===END OF DATA===\n");
  setColor(RESET);
  free(stringHolder);
  fclose(filePointer);
  return 0;
}

void* parseToStruct(char* stringToParse, int structType) {
  char *tempStringHolder, **columnsHolder;
  void* structPointer;
  int i;
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  strtok(stringToParse, "\n");
  tempStringHolder = strtok(stringToParse, ",");
  i=0;
  strcpy(columnsHolder[i], tempStringHolder);
  i++;
  while ((tempStringHolder = strtok(NULL, ",")))
    strcpy(columnsHolder[i], tempStringHolder), i++;
  //get student info from file and parse it
  i=0;
  switch (structType) {
    case 0:
      //student
      structPointer = (Student*) malloc(sizeof(Student));
      sscanf(columnsHolder[i],"%s",((Student*) structPointer) -> number),i++;
      sscanf(columnsHolder[i],"%[^,]s",((Student*) structPointer) -> name),i++;
      sscanf(columnsHolder[i],"%[^,]s",((Student*) structPointer) -> surname),i++;
      sscanf(columnsHolder[i],"%d",&(((Student*) structPointer) -> lessonCount)),i++;
      sscanf(columnsHolder[i],"%d",&(((Student*) structPointer) -> totalCredit)),i++;
    break;
    case 1:
      //course
      structPointer = (Course*) malloc(sizeof(Course));
      sscanf(columnsHolder[i],"%s",((Course*) structPointer) -> code),i++;
      sscanf(columnsHolder[i],"%[^,]s",((Course*) structPointer) -> name),i++;
      sscanf(columnsHolder[i],"%d",&(((Course*) structPointer) -> credit)),i++;
      sscanf(columnsHolder[i],"%d",&(((Course*) structPointer) -> capacity)),i++;
      sscanf(columnsHolder[i],"%[^,]s",((Course*) structPointer) -> instructorId),i++;
    break;
    case 2:
      //instructor
      structPointer = (Instructor*) malloc(sizeof(Instructor));
      sscanf(columnsHolder[i],"%[^,]s",((Instructor*) structPointer) -> id),i++;
      sscanf(columnsHolder[i],"%[^,]s",((Instructor*) structPointer) -> name),i++;
      sscanf(columnsHolder[i],"%[^,]s",((Instructor*) structPointer) -> surname),i++;
      sscanf(columnsHolder[i],"%[^,]s",((Instructor*) structPointer) -> title),i++;
    break;
    case 3:
      //log
      structPointer = (EnrollmentLog*) malloc(sizeof(EnrollmentLog));
      sscanf(columnsHolder[i],"%d",&(((EnrollmentLog*) structPointer) -> id)),i++;
      sscanf(columnsHolder[i],"%[^,]s",((EnrollmentLog*) structPointer) -> studentNumber),i++;
      sscanf(columnsHolder[i],"%[^,]s",((EnrollmentLog*) structPointer) -> courseCode),i++;
      sscanf(columnsHolder[i],"%[^,]s",((EnrollmentLog*) structPointer) -> date),i++;
      sscanf(columnsHolder[i],"%d",&(((EnrollmentLog*) structPointer) -> enrolled)),i++;
    break;
    default:
      setColor(RED);
      printf("Can't parse string: unknown struct type (%d). Returning NULL\n", structType);
      setColor(RESET);
  }
  for (i = 0; i < COLUMN_MAX; i++) {
    free(columnsHolder[i]);
  }
  free(columnsHolder);
  return structPointer;
}

void throwError(int errorCode, int isWarning, int lineNumber) {
  isWarning ? setColor(YELLOW) : setColor(RED);
  //Uncomment below to figure out error positions
  //printf("%s:%d > ", __FILE__,lineNumber);
  switch (errorCode) {
    case 50:
      printf("Can't leave field empty (Error Code: 50)\n");
    break;
    case 67:
      printf("Couldn't open file. Terminating the current operation with failure. (Error Code: 67)\n");
    break;
    case 68:
      printf("Couldn't create file. Terminating the current operation with failure. (Error Code: 68)\n");
    break;
    case 69:
      printf("Can't alter non-existing data. Make sure an entry with the value you entered exists. (Warning Code: 69)\n");
    break;
    case 70:
      printf("Exceeded number of columns. Aborting without updating. (Error Code: 70)\n");
    break;
    case 71:
      printf("Duplicate key value. Aborting without adding data. (Error Code: 71)\n");
    break;
    case 80:
      printf("Can't add course. Reached full capacity. (Error Code: 80)\n");
    break;
    case 81:
      printf("Can't use course. Course doesn't exist. (Error Code: 80)\n");
    break;
    default:
      printf("Can't print error details.\nReach the developer with error code %d\n", errorCode);
  }
  setColor(RESET);
}

void unEnrollStudent(char* studentNumber, char* courseCode, int isStudent) {
  int courseCapacity, courseCredit, i, isEnrolled;
  long int position, previousPosition;
  EnrollmentLog logInstance;
  //column numbers in the file
  int capacityColumn =3, creditColumn = 2, numberColumn = 1, courseColumn = 2,statusColumn = 4;
  char *stringHolder, **columnsHolder, *dateString, *tempStringHolder;
  FILE* filePointer;
  if (!(filePointer = fopen(COURSES, "r"))) {
    setColor(RED);
    printf("Error: Can't access courses. Make sure at least a course is defined.\n");
    setColor(RESET);
    return;
  }
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  if (findDataPosition(filePointer, courseCode, 0) == -1) {
    throwError(81, 0, __LINE__);
    fclose(filePointer);
    return;
  }
  dateString = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  fgets(stringHolder, MAX_LINE_SIZE, filePointer);
  fclose(filePointer);
  //print the date of the day to dateString
  sprintf(dateString, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
  //divide the string into columns based on ','
  tempStringHolder = strtok(stringHolder, ",");
  i=0;
  strcpy(columnsHolder[i], tempStringHolder);
  i++;
  while ((tempStringHolder = strtok(NULL,","))) {
    strcpy(columnsHolder[i], tempStringHolder);
    i++;
  }
  sscanf(columnsHolder[creditColumn], "%d", &courseCredit);
  sscanf(columnsHolder[capacityColumn], "%d", &courseCapacity);
  if (!(filePointer = fopen(STUDENTS, "r+"))) {
    throwError(67, 0, __LINE__);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    return;
  }
  //check if the student exists
  if (getColumnString(filePointer, studentNumber, 0, 3, stringHolder) == -1) {
    setColor(RED);
    printf("Student doesn't exist\n");
    setColor(RESET);
    throwError(69,1,__LINE__);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    fclose(filePointer);
    return;
  }
  //if student exists close the file
  fclose(filePointer);
  if ((filePointer = fopen(ENROLLMENT, "r+")) == NULL) {
    throwError(67, 0, __LINE__);
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    return;
  }
  //check if student is enrolled and stay in position
  isEnrolled = 0;
  position = ftell(filePointer);
  previousPosition = position;
  while (!isEnrolled && fgets(stringHolder, MAX_LINE_SIZE, filePointer)) {
    previousPosition = position;
    position = ftell(filePointer);
    strtok(stringHolder, "\n");
    tempStringHolder = strtok(stringHolder, ",");
    i=0;
    strcpy(columnsHolder[i], tempStringHolder);
    i++;
    while ((tempStringHolder = strtok(NULL, ",")))
      strcpy(columnsHolder[i], tempStringHolder), i++;
    if (!strcmp(columnsHolder[courseColumn], courseCode) && !strcmp(columnsHolder[statusColumn], "1") && !strcmp(columnsHolder[numberColumn], studentNumber)) {
      isEnrolled = 1;
    }
  }
  fseek(filePointer, previousPosition, SEEK_SET);
  if (!isEnrolled) {
    free(stringHolder);
    for (i = 0; i < COLUMN_MAX; i++) {
      free(columnsHolder[i]);
    }
    free(columnsHolder);
    free(dateString);
    fclose(filePointer);
    setColor(RED);
    printf("You are not enrolled in %s\n", courseCode);
    setColor(RESET);
    return;
  }
  //get enrollment log from file and parse it
  i=0;
  sscanf(columnsHolder[i],"%d",&logInstance.id),i++;
  sscanf(columnsHolder[i],"%s",logInstance.studentNumber),i++;
  sscanf(columnsHolder[i],"%s",logInstance.courseCode),i++;
  sscanf(columnsHolder[i],"%s",logInstance.date),i++;
  sscanf(columnsHolder[i],"%d",&logInstance.enrolled),i++;
  //modify date and enrollment status
  strcpy(logInstance.date, dateString);
  logInstance.enrolled = 0;
  sprintf(stringHolder,"%d,%s,%s,%s,%d",logInstance.id,logInstance.studentNumber,logInstance.courseCode,
          logInstance.date, logInstance.enrolled);
  addTextToPosition(filePointer, stringHolder,1);
  fclose(filePointer);
  remove(ENROLLMENT);
  rename(TEMP_FILE, ENROLLMENT);
  updateStudentEnrollment(studentNumber, courseCredit, 1, 0);
  //show success message if a student is calling the function
  if (isStudent) {
    setColor(GREEN);
    printf("Unenrolled from %s successfully.\n", courseCode);
    setColor(RESET);
  }
  free(stringHolder);
  for (i = 0; i < COLUMN_MAX; i++) {
    free(columnsHolder[i]);
  }
  free(columnsHolder);
  free(dateString);
}

int unEnrollAllStudents(char* courseCode) {
  FILE* filePointer;
  EnrollmentLog* logInstance;
  int position;
  char* stringHolder;
  if (!(filePointer = fopen(ENROLLMENT, "r"))) {
    return -1;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  while (findDataPosition(filePointer, courseCode,2) > 0) {
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    position = ftell(filePointer);
    fclose(filePointer);
    logInstance = parseToStruct(stringHolder,3);
    if ((logInstance -> enrolled)) {
      unEnrollStudent(logInstance -> studentNumber, courseCode,0);
    }
    if (!(filePointer = fopen(ENROLLMENT, "r"))) {
      free(stringHolder);
      return 0;
    }
    fseek(filePointer, position, SEEK_SET);
    if (logInstance) {free(logInstance);}
  }
  free(stringHolder);
  fclose(filePointer);
  return 1;
}

void updateAttendersCredit(char* courseCode, int creditChange) {
  FILE* filePointer;
  char* stringHolder;
  long int position;
  EnrollmentLog *logInstance;
  if (!(filePointer = fopen(ENROLLMENT, "r"))) {
    return;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  while (findDataPosition(filePointer, courseCode,2) > 0) {
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    position = ftell(filePointer);
    fclose(filePointer);
    logInstance = parseToStruct(stringHolder,3);
    if ((logInstance -> enrolled)) {
      updateStudentEnrollment(logInstance -> studentNumber, creditChange,0,1);
    }
    if (!(filePointer = fopen(ENROLLMENT, "r"))) {
      if (logInstance) {free(logInstance);}
      free(stringHolder);
      free(stringHolder);
      return;
    }
    fseek(filePointer, position, SEEK_SET);
    if (logInstance) {free(logInstance);}
  }
  free(stringHolder);
  fclose(filePointer);
}

int updateCourseDetails(char* key) {
  Course* courseInstance;
  FILE* filePointer;
  char *stringHolder;
  long int position;
  int i=0, control;
  if (!(filePointer = fopen(COURSES, "r+"))) {
    setColor(RED);
    printf("Course doesn't exist.\n");
    setColor(RESET);
    return -1;
  }
  strtok(key, "\n");
  if(findDataPosition(filePointer, key, 0) != -1) {
    stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
    position = ftell(filePointer);
    fgets(stringHolder, MAX_LINE_SIZE, filePointer);
    courseInstance = parseToStruct(stringHolder, 1);
    if (courseInstance) {
      printf("(%s) Enter new name: ", courseInstance -> name);
      fgets(stringHolder, MAX_COLUMN_SIZE, stdin);
      if (strcmp(stringHolder, "\n")) {
        strtok(stringHolder, "\n");
        sprintf(courseInstance -> name, "%s",stringHolder);
        i++;
      }
      printf("(%d) Enter new credit: ", courseInstance -> credit);
      fgets(stringHolder, MAX_COLUMN_SIZE, stdin);
      if (strcmp(stringHolder, "\n")) {
        setColor(YELLOW);
        printf("Already enrolled students won't be affected if they pass credit limit!\n");
        setColor(RESET);
        strtok(stringHolder, "\n");
        sscanf(stringHolder, "%d", &(courseInstance -> credit));
        i++;
      }
      printf("(%d) Enter new capacity: ", courseInstance -> capacity);
      fgets(stringHolder, MAX_COLUMN_SIZE, stdin);
      if (strcmp(stringHolder, "\n")) {
        strtok(stringHolder, "\n");
        sscanf(stringHolder, "%d", &(courseInstance -> capacity));
        i++;
      }
      printf("(%s) Enter new instructor ID: ", courseInstance -> instructorId);
      fgets(stringHolder, MAX_COLUMN_SIZE, stdin);
      if (strcmp(stringHolder, "\n")) {
        if ((control = hasColumn(INSTRUCTORS,stringHolder,0)) != 1) {
          setColor(YELLOW);
          printf("No instructor with the ID %s. Try again:\n", stringHolder);
          setColor(RESET);
          printf("(%s) Enter new instructor ID: ", courseInstance -> instructorId);
          fgets(stringHolder, MAX_COLUMN_SIZE, stdin);
          control = hasColumn(INSTRUCTORS,stringHolder,0);
        }
        if (control != 1) {
          setColor(RED);
          printf("The instructor should be registed before assigning them to a course.\n");
          setColor(RESET);
          free(courseInstance);
          free(stringHolder);
          return -1;
        }
        strtok(stringHolder, "\n");
        sscanf(stringHolder, "%s", courseInstance -> instructorId);
        i++;
      }
    } else {
      setColor(RED);
      printf("%s:%d > can't parse course string to struct.\n",__FILE__,__LINE__);
      setColor(RESET);
      free(stringHolder);
      return -1;
    }
    if (i > 0) {
      sprintf(stringHolder, "%s,%s,%d,%d,%s", courseInstance -> code, courseInstance -> name,
              courseInstance -> credit, courseInstance -> capacity, courseInstance -> instructorId);
      fseek(filePointer, position, SEEK_SET);
      addTextToPosition(filePointer, stringHolder, 1);
      fclose(filePointer);
      remove(COURSES);
      rename(TEMP_FILE, COURSES);
      setColor(GREEN);
      printf("Updated %s successfully.\n", courseInstance -> code);
      setColor(RESET);
    } else {
      setColor(YELLOW);
      printf("%s won't be changed.\n", courseInstance -> code);
      setColor(RESET);
      fclose(filePointer);
    }
    free(courseInstance);
    free(stringHolder);
    return 0;
  } else {
    return -1;
  }
}

int updateDataInFile(char* key,char* fileName,int* editableColumns,const char* headerRow) {
  char *control, *tempColumnHolder, *stringToCompare, *tempStringHolder, **headerColumns, *headerHolder, **columnsHolder;
  FILE* fileToChange;
  long int previousPosition, position;
  int i,j,columnsCounter, columnNumber;
  //check if the file can be opened with "r+" if not abort the operation
  if ((fileToChange = fopen(fileName, "r+")) == NULL) {
    setColor(RED);
    printf("Error: Couldn't open the file %s. Can't edit unreachable data.\n", fileName);
    setColor(RESET);
    printf("Terminating the process with failure...\n");
    return -1;
  }
  stringToCompare = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  tempColumnHolder = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  headerHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  headerColumns = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    headerColumns[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  //loop through the file to determine where to add text
  previousPosition = ftell(fileToChange);
  if ((control = fgets(stringToCompare,MAX_LINE_SIZE,fileToChange))) {
    //divide the string into columns based on ','
    i = 0;
    tempStringHolder = strtok(stringToCompare, ",");
    strcpy(tempColumnHolder, tempStringHolder);
    i++;
    while ((tempStringHolder = strtok(NULL,",")) && i < COLUMN_MAX)
      i++;
  }
  position = ftell(fileToChange);
  if (control) {
    while (strcmp(tempColumnHolder, key) && fgets(stringToCompare,MAX_LINE_SIZE, fileToChange)) {
      tempStringHolder = strtok(stringToCompare, ",");
      previousPosition = position;
      position = ftell(fileToChange);
      strcpy(tempColumnHolder, tempStringHolder);
      i=1;
      while ((tempStringHolder = strtok(NULL, ",")))
        i++;
    }
    if (!strcmp(tempColumnHolder, key)) {
      fseek(fileToChange, previousPosition, SEEK_SET);
      fgets(stringToCompare,MAX_LINE_SIZE,fileToChange);
      fseek(fileToChange, previousPosition, SEEK_SET);
      i=0;
      tempStringHolder = strtok(stringToCompare,",");
      strcpy(columnsHolder[i], tempStringHolder);
      i++;
      while ((tempStringHolder = strtok(NULL,",")))
        strcpy(columnsHolder[i], tempStringHolder),i++;
      columnsCounter = i;
      strcpy(headerHolder, headerRow);
      //get the name of columns from headerRow to print them when asking for new values
      i=0;
      tempStringHolder = strtok(headerHolder,"-");
      strcpy(headerColumns[i], tempStringHolder);
      i++;
      while ((tempStringHolder = strtok(NULL,"-")))
        strcpy(headerColumns[i], tempStringHolder),i++;
      i=0,j=0;
      setColor(YELLOW);
      printf("Press Enter to keep (old value)\n");
      setColor(RESET);
      while ((columnNumber = editableColumns[i]) != -1) {
        sscanf(columnsHolder[columnNumber],"%[^\n]s",tempColumnHolder);
        printf("(%s) Enter new %s: ", tempColumnHolder, headerColumns[columnNumber]);
        fgets(tempColumnHolder,MAX_COLUMN_SIZE,stdin);
        strtok(tempColumnHolder,"\n");
        if (strcmp(tempColumnHolder,"\n")) {
          strcpy(columnsHolder[columnNumber],tempColumnHolder);
          j++; //count the number of changed columns
        }
        i++;
      }
      if (j) {
        strcpy(stringToCompare, columnsHolder[0]);
        for (i = 0; i < columnsCounter-1; i++){
          strcat(stringToCompare, ",");
          strcat(stringToCompare, columnsHolder[i+1]);
        }
        printf("Updating as: %s\n",stringToCompare);
        addTextToPosition(fileToChange, stringToCompare, 1);
        fclose(fileToChange);
        remove(fileName);
        rename(TEMP_FILE, fileName);
        setColor(GREEN);
        printf("Updated %s successfully\n", key);
        setColor(RESET);
      } else {
        fclose(fileToChange);
        setColor(YELLOW);
        printf("%s won't be changed.\n", key);
        setColor(RESET);
      }
    } else {
      throwError(69, 1, __LINE__);
      free(headerHolder);
      for (i = 0; i < COLUMN_MAX; i++)
        free(headerColumns[i]);
      free(headerColumns);
      for (i = 0; i < COLUMN_MAX; i++)
        free(columnsHolder[i]);
      free(columnsHolder);
      free(tempColumnHolder);
      free(stringToCompare);
      fclose(fileToChange);
      return 1;
    }
  } else {
    throwError(69, 1, __LINE__);
    free(headerHolder);
    for (i = 0; i < COLUMN_MAX; i++)
      free(headerColumns[i]);
    free(headerColumns);
    for (i = 0; i < COLUMN_MAX; i++)
      free(columnsHolder[i]);
    free(columnsHolder);
    free(tempColumnHolder);
    free(stringToCompare);
    fclose(fileToChange);
    return 1;
  }
  free(headerHolder);
  for (i = 0; i < COLUMN_MAX; i++)
    free(headerColumns[i]);
  free(headerColumns);
  for (i = 0; i < COLUMN_MAX; i++)
    free(columnsHolder[i]);
  free(columnsHolder);
  free(tempColumnHolder);
  free(stringToCompare);
  return 0;
}

int updateStudentEnrollment(char* studentNumber, int courseCredit, int lessonNumber, int enrolled) {
  FILE* filePointer;
  int i;
  long int position;
  char *stringHolder, **columnsHolder, *tempStringHolder;
  Student studentInstance;
  if (!(filePointer = fopen(STUDENTS, "r+"))) {
    throwError(67, 0, __LINE__);
    return -1;
  }
  stringHolder = (char*) malloc(MAX_LINE_SIZE * sizeof(char));
  columnsHolder = (char**) malloc(COLUMN_MAX * sizeof(char*));
  for (i = 0; i < COLUMN_MAX; i++)
    columnsHolder[i] = (char*) malloc(MAX_COLUMN_SIZE * sizeof(char));
  findDataPosition(filePointer, studentNumber, 0);
  position = ftell(filePointer);
  fgets(stringHolder, MAX_LINE_SIZE, filePointer);
  fseek(filePointer, position, SEEK_SET);
  i=0;
  tempStringHolder = strtok(stringHolder, ",");
  strcpy(columnsHolder[i], tempStringHolder);
  i++;
  while ((tempStringHolder = strtok(NULL, ",")))
    strcpy(columnsHolder[i], tempStringHolder),i++;
  i=0;
  sscanf(columnsHolder[i],"%[^,]s",studentInstance.number),i++;
  sscanf(columnsHolder[i],"%[^,]s",studentInstance.name),i++;
  sscanf(columnsHolder[i],"%[^,]s",studentInstance.surname),i++;
  sscanf(columnsHolder[i],"%d",&studentInstance.lessonCount),i++;
  sscanf(columnsHolder[i],"%d",&studentInstance.totalCredit),i++;
  if (enrolled) {
    studentInstance.lessonCount += lessonNumber;
    studentInstance.totalCredit += courseCredit;
  } else {
    studentInstance.lessonCount -= lessonNumber;
    studentInstance.totalCredit -= courseCredit;
  }
  sprintf(stringHolder,"%s,%s,%s,%d,%d",studentInstance.number,studentInstance.name,studentInstance.surname,
          studentInstance.lessonCount,studentInstance.totalCredit);
  addTextToPosition(filePointer, stringHolder, 1);
  fclose(filePointer);
  remove(STUDENTS);
  rename(TEMP_FILE, STUDENTS);
  free(stringHolder);
  for (i = 0; i < COLUMN_MAX; i++)
    free(columnsHolder[i]);
  free(columnsHolder);
  return 0;
}

//functions that are defined differently based on platform
#ifdef _WIN32
void clearConsole() {
  system("cls");
}
void setColor(int color) {
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  switch (color) {
    case 31:
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    break;
    case 32:
      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    break;
    case 33:
      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    break;
    case 34:
      SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    break;
    default:
      SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
  }
}
#else
void clearConsole() {
  printf("\033[H\033[J");
}
void setColor(int color) {
  printf("\x1b[%dm", color);
}
#endif
