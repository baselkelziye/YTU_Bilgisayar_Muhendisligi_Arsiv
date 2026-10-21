#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct student { // STUDENT
  char id[20];           // student ID
  char name[20];         // name
  char surname[20];      // surname
  int totalLesson;       // total number of enrolled courses
  int totalCredit;       // total number of enrolled credits
} STUDENT;
typedef struct teacher { // INSTRUCTOR
  char id[20];           // ID
  char title[20];        // title
  char name[20];         // name
  char surname[20];      // surname
} TEACHER;
typedef struct lesson { // COURSE
  char id[20];          // course code
  char name[50];        // course name
  int credit;           // credit
  int usedQuota;        // used quota
  char teacherId[20];   // ID of the instructor who teaches the course
} LESSON;
typedef struct date { // DATE
  int hour, min;
  int day, month, year;
} DATE;

// GENERAL FUNCTIONS
int getCmd(int);
int idCheck(char *, char *);
void setTime(DATE *);
void createTxtFiles();

// CHECK FUNCTIONS
int searchById(char *, char *);
int controlLesson(char *, char *);
int anyLesson(char *);
int getLessonControl(char *, char *);
int getAnyLessonControl(char *);
int anyoneGetLessonControl(char *);
int creditControl(char *, char *, int);
int quotaControl(char *, int);
int addControl(char *, char *);
int emptyFile(char *);

// SEARCH FUNCTIONS
void findStudent(char *, STUDENT *);
void findTeacher(char *, TEACHER *);
void findLesson(char *, LESSON *);

// STUDENT FUNCTIONS
void addLesson(char *, int, int);
void quitLesson(char *);
void studentsLessons(char *);
void searchTeacher();

// INSTRUCTOR FUNCTIONS
void createLesson(char *);
void updateLesson(char *);
void deleteLesson(char *);
void teachersLessons(char *);
void searchLesson();
void attendanceList(char *);

// ADMIN FUNCTIONS
void createStudent();
void updateStudent();
void deleteStudent();
void createTeacher();
void updateTeacher();
void deleteTeacher();

// MENU HELPERS
void mainSignIn();
void mainMenu();
void studentSignIn();
void studentMenu();
void teacherSignIn();
void teacherMenu();
void adminSignIn();
void adminMenu();
int doneMenu();

int main() {
  setlocale(LC_ALL, "Turkish");

  int cmd;            // command
  char currentId[20]; // entered ID
  int maxQuota;       // maximum quota for each course
  int maxCredit;      // maximum credit for each student

  // create the files if they do not exist
  createTxtFiles();

  // program start
  printf("\n --> Course Quota Limit: ");
  scanf(" %d", &maxQuota);
  printf(" --> Student Credit Limit: ");
  scanf(" %d", &maxCredit);
  do { // repeat until exit
    mainSignIn();
    mainMenu();
    cmd = getCmd(0);
    if (cmd == 1) { // STUDENT LOGIN
      studentSignIn();
      printf("\n --> Student ID: ");
      scanf(" %[^\n]s", currentId); // read student ID
      cmd = idCheck(currentId, "STUDENTS.txt");
      if (cmd == 2) {
        do { // repeat until going back or exiting
          printf("\n (!) Welcome!");
          printf("\n (!) ID: %s\n", currentId);
          studentMenu();
          cmd = getCmd(1);
          if (cmd == 1) { // add course
            addLesson(currentId, maxCredit, maxQuota);
            cmd = doneMenu();
          } else if (cmd == 2) { // drop course
            quitLesson(currentId);
            cmd = doneMenu();
          } else if (cmd == 3) { // view enrolled courses
            studentsLessons(currentId);
            cmd = doneMenu();
          } else if (cmd == 4) { // view an instructor's courses
            searchTeacher();
            cmd = doneMenu();
          }
        } while (cmd != 0 && cmd != 9);
      }
    } else if (cmd == 2) { // INSTRUCTOR LOGIN
      teacherSignIn();
      printf("\n --> Instructor ID: ");
      scanf(" %[^\n]s", currentId); // read ID
      cmd = idCheck(currentId, "TEACHERS.txt");
      if (cmd == 2) {
        do { // repeat until going back or exiting
          printf("\n (!) Welcome!");
          printf("\n (!) ID: %s\n", currentId);
          teacherMenu();
          cmd = getCmd(2);
          if (cmd == 1) { // create course
            createLesson(currentId);
            cmd = doneMenu();
          } else if (cmd == 2) { // update course
            updateLesson(currentId);
            cmd = doneMenu();
          } else if (cmd == 3) { // delete course
            deleteLesson(currentId);
            cmd = doneMenu();
          } else if (cmd == 4) { // taught courses
            teachersLessons(currentId);
            cmd = doneMenu();
          } else if (cmd == 5) { // view a course roster
            searchLesson();
            cmd = doneMenu();
          } else if (cmd == 6) { // create attendance list
            attendanceList(currentId);
            cmd = doneMenu();
          }
        } while (cmd != 0 && cmd != 9);
      }
    } else if (cmd == 3) { // ADMIN LOGIN
      do {                 // repeat until going back or exiting
        adminSignIn();
        adminMenu();
        cmd = getCmd(3);
        if (cmd == 1) { // add student
          createStudent();
          cmd = doneMenu();
        } else if (cmd == 2) { // update student
          updateStudent();
          cmd = doneMenu();
        } else if (cmd == 3) { // delete student
          deleteStudent();
          cmd = doneMenu();
        } else if (cmd == 4) { // add instructor
          createTeacher();
          cmd = doneMenu();
        } else if (cmd == 5) { // update instructor
          updateTeacher();
          cmd = doneMenu();
        } else if (cmd == 6) { // delete instructor
          deleteTeacher();
          cmd = doneMenu();
        }
      } while (cmd != 0 && cmd != 9);
    }
  } while (cmd != 0);
  printf("\n (!) Exited.\n");
  printf(" _________________\n");
  printf(" |               |\n");
  printf(" |   Have a nice day!   |\n");
  printf(" |_______________|\n");
  return 0;
}

// GENERAL FUNCTIONS
int getCmd(int X) { // gets a valid command
  // X == 0 --> main menu
  // X == 1 --> student login
  // X == 2 --> instructor login
  // X == 3 --> admin login
  // X == 4 --> post-operation page
  int cmd;
  if (X == 0) {
    do {
      printf("\n --> Command: ");
      scanf("%d", &cmd);
      if (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 0) {
        printf("\n (!) Wrong command!\n");
      }
    } while (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 0);
  } else if (X == 1) {
    do {
      printf("\n --> Command: ");
      scanf("%d", &cmd);
      if (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd != 9 &&
          cmd != 0) {
        printf("\n (!) Wrong command!\n");
      }
    } while (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd != 9 &&
             cmd != 0);
  } else if (X == 2) {
    do {
      printf("\n --> Command: ");
      scanf("%d", &cmd);
      if (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd != 5 &&
          cmd != 6 && cmd != 9 && cmd != 0) {
        printf("\n (!) Wrong command!\n");
      }
    } while (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd != 5 &&
             cmd != 6 && cmd != 9 && cmd != 0);
  } else if (X == 3) {
    do {
      printf("\n --> Command: ");
      scanf("%d", &cmd);
      if (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd != 5 &&
          cmd != 6 && cmd != 9 && cmd != 0) {
        printf("\n (!) Wrong command!\n");
      }
    } while (cmd != 1 && cmd != 2 && cmd != 3 && cmd != 4 && cmd != 5 &&
             cmd != 6 && cmd != 9 && cmd != 0);
  } else if (X == 4) {
    do {
      printf("\n --> Command: ");
      scanf("%d", &cmd);
      if (cmd != 9 && cmd != 0) {
        printf("\n (!) Wrong command!\n");
      }
    } while (cmd != 9 && cmd != 0);
  }
  return cmd;
}
int idCheck(char *id, char *fileName) { // signs in after checking the ID
  // return 0 --> exit
  // return 1 --> back
  // return 2 --> signed in
  int found = 0;
  int cmd;
  found = searchById(id, fileName);
  if (found == 0) {
    printf("\n (!) ID not found.\n");
    cmd = doneMenu();
  } else if (found == 1) {
    printf("\n (!) Signed in.");
    cmd = 2;
  }
  return cmd;
}
void setTime(DATE *date) { // gets the current time and date
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);
  date->day = local->tm_mday;
  date->month = local->tm_mon + 1;
  date->year = local->tm_year + 1900;
  date->hour = local->tm_hour;
  date->min = local->tm_min;
}
void createTxtFiles() {
  FILE *fp;
  fp = fopen("LESSONS.txt", "r");
  if (fp == NULL) {
    fp = fopen("LESSONS.txt", "w");
  }
  fclose(fp);
  fp = fopen("STUDENTS.txt", "r");
  if (fp == NULL) {
    fp = fopen("STUDENTS.txt", "w");
  }
  fclose(fp);
  fp = fopen("TEACHERS.txt", "r");
  if (fp == NULL) {
    fp = fopen("TEACHERS.txt", "w");
  }
  fclose(fp);
  fp = fopen("OgrenciDersKayit.txt", "r");
  if (fp == NULL) {
    fp = fopen("OgrenciDersKayit.txt", "w");
  }
  fclose(fp);
}

// CHECK FUNCTIONS
int searchById(char *id, char *fileName) { // searches by ID
  // found == 0 --> ID not found
  // found == 1 --> ID found
  // found == 2 --> file not found
  int found = 0;
  char *tmpId = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(100 * sizeof(char));
  FILE *fp = fopen(fileName, "r");

  if (fp != NULL) {
    while (!feof(fp) && !found) {
      fscanf(fp, "\n%[^;]s", tmpId);
      fscanf(fp, ";%[^\n]s", tmpStr);
      if (strcmp(tmpId, id) == 0) {
        found = 1;
      }
    }
    fclose(fp);
  } else {
    printf("\n (!) File not found.\n");
    found = 2;
  }
  free(tmpId);
  free(tmpStr);
  return found;
}
int controlLesson(
    char *lessonId,
    char *teacherId) { // checks whether the course belongs to the instructor
  int control = 0;
  FILE *fp;
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  fp = fopen("LESSONS.txt", "r");
  while (!feof(fp) && !control) {
    fscanf(fp, "\n%[^;]s", newLesson->id);
    fscanf(fp, ";%[^;]s", newLesson->name);
    fscanf(fp, ";%[^;]s", newLesson->teacherId);
    fscanf(fp, ";%d;%d", &newLesson->credit, &newLesson->usedQuota);
    if (strcmp(newLesson->id, lessonId) == 0 &&
        strcmp(newLesson->teacherId, teacherId) == 0) {
      control = 1;
    }
  }
  fclose(fp);
  free(newLesson);
  return control;
}
int anyLesson(char *teacherId) { // checks whether the instructor has any course
  // return 0 --> no course
  // return 1 --> course exists
  int control = 0;
  FILE *fp;
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  fp = fopen("LESSONS.txt", "r");
  while (!feof(fp) && !control) {
    fscanf(fp, "\n%[^;]s", newLesson->id);
    fscanf(fp, ";%[^;]s", newLesson->name);
    fscanf(fp, ";%[^;]s", newLesson->teacherId);
    fscanf(fp, ";%d;%d", &newLesson->credit, &newLesson->usedQuota);
    if (strcmp(newLesson->teacherId, teacherId) == 0) {
      control = 1;
    }
  }
  fclose(fp);
  free(newLesson);
  return control;
}
int getLessonControl(
    char *studentId,
    char *lessonId) { // checks whether the student is taking the course
  int control = 0;
  int pairId, status;
  FILE *fp;
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  fp = fopen("OgrenciDersKayit.txt", "r");
  while (!feof(fp) && !control) {
    fscanf(fp, "\n%d", &pairId);
    fscanf(fp, "<%[^-]s", tmpStudent);
    fscanf(fp, "-%[^>]s", tmpLesson);
    fscanf(fp, ">%d", &status);
    fscanf(fp, ";%[^\n]s", tmpStr);
    if (strcmp(tmpStudent, studentId) == 0 &&
        strcmp(tmpLesson, lessonId) == 0 && status == 1) {
      control = 1;
    }
  }
  fclose(fp);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  return control;
}
int getAnyLessonControl(
    char *studentId) { // checks whether the student is taking any course
  int control = 0;
  int pairId, status;
  FILE *fp;
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  fp = fopen("OgrenciDersKayit.txt", "r");
  while (!feof(fp) && !control) {
    fscanf(fp, "\n%d", &pairId);
    fscanf(fp, "<%[^-]s", tmpStudent);
    fscanf(fp, "-%[^>]s", tmpLesson);
    fscanf(fp, ">%d", &status);
    fscanf(fp, ";%[^\n]s", tmpStr);
    if (strcmp(tmpStudent, studentId) == 0 && status == 1) {
      control = 1;
    }
  }
  fclose(fp);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  return control;
}
int anyoneGetLessonControl(
    char *lessonId) { // checks whether any student is taking the course
  int control = 0;
  int pairId, status;
  FILE *fp;
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  fp = fopen("OgrenciDersKayit.txt", "r");
  while (!feof(fp) && !control) {
    fscanf(fp, "\n%d", &pairId);
    fscanf(fp, "<%[^-]s", tmpStudent);
    fscanf(fp, "-%[^>]s", tmpLesson);
    fscanf(fp, ">%d", &status);
    fscanf(fp, ";%[^\n]s", tmpStr);
    if (strcmp(tmpLesson, lessonId) == 0 && status == 1) {
      control = 1;
    }
  }
  fclose(fp);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  return control;
}
int creditControl(char *studentId, char *lessonId,
                  int maxCredit) { // checks the student's credit status
  int totalCredit;
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  findStudent(studentId, newStudent);
  findLesson(lessonId, newLesson);
  totalCredit = newStudent->totalCredit + newLesson->credit;
  if (totalCredit > maxCredit) {
    return 0;
  } else {
    return 1;
  }
  free(newLesson);
  free(newStudent);
}
int quotaControl(char *lessonId,
                 int maxQuota) { // checks the course quota status
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  findLesson(lessonId, newLesson);
  if ((newLesson->usedQuota + 1) > maxQuota) {
    return 0;
  } else {
    return 1;
  }
  free(newLesson);
}
int addControl(char *studentId,
               char *lessonId) { // checks whether the course was added before
  // return 0 --> already taking the course
  // return 1 --> never taken the course
  int control = 1;
  int pairId, status;
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  FILE *fp = fopen("OgrenciDersKayit.txt", "r");
  if (fp != NULL) {
    while (!feof(fp) && control) {
      fscanf(fp, "\n%d", &pairId);
      fscanf(fp, "<%[^-]s", tmpStudent);
      fscanf(fp, "-%[^>]s", tmpLesson);
      fscanf(fp, ">%d", &status);
      fscanf(fp, ";%[^\n]s", tmpStr);
      if (strcmp(tmpStudent, studentId) == 0 &&
          strcmp(tmpLesson, lessonId) == 0 && status == 1) {
        control = 0;
      }
    }
    fclose(fp);
  }
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  return control;
}
int emptyFile(char *fileName) { // checks whether the file is empty
  // return 0 --> empty
  // return 1 --> not empty
  int control = 0;
  FILE *fp = fopen(fileName, "r");
  fseek(fp, 0, SEEK_END);
  control = ftell(fp);
  if (control > 0) {
    control = 1;
  }
  fclose(fp);
  return control;
}

// SEARCH FUNCTIONS
void findStudent(
    char *studentId,
    STUDENT *newStudent) { // find the student and get the information
  int found = 0;
  FILE *fp = fopen("STUDENTS.txt", "r");
  if (fp != NULL) {
    while (!feof(fp) && !found) {
      fscanf(fp, "\n%[^;]s", newStudent->id);
      fscanf(fp, ";%[^;]s", newStudent->name);
      fscanf(fp, ";%[^;]s", newStudent->surname);
      fscanf(fp, ";%d;%d", &newStudent->totalCredit, &newStudent->totalLesson);
      if (strcmp(newStudent->id, studentId) == 0) {
        found = 1;
      }
    }
    fclose(fp);
  }
}
void findTeacher(
    char *teacherId,
    TEACHER *newTeacher) { // find the instructor and get the information
  int found = 0;
  FILE *fp = fopen("TEACHERS.txt", "r");
  if (fp != NULL) {
    while (!feof(fp) && !found) {
      fscanf(fp, "\n%[^;]s", newTeacher->id);
      fscanf(fp, ";%[^;]s", newTeacher->title);
      fscanf(fp, ";%[^;]s", newTeacher->name);
      fscanf(fp, ";%[^\n]s", newTeacher->surname);
      if (strcmp(newTeacher->id, teacherId) == 0) {
        found = 1;
      }
    }
    fclose(fp);
  }
}
void findLesson(char *lessonId,
                LESSON *newLesson) { // find the course and get the information
  int found = 0;
  FILE *fp = fopen("LESSONS.txt", "r");
  if (fp != NULL) {
    while (!feof(fp) && !found) {
      fscanf(fp, "\n%[^;]s", newLesson->id);
      fscanf(fp, ";%[^;]s", newLesson->name);
      fscanf(fp, ";%[^;]s", newLesson->teacherId);
      fscanf(fp, ";%d;%d", &newLesson->credit, &newLesson->usedQuota);
      if (strcmp(newLesson->id, lessonId) == 0) {
        found = 1;
      }
    }
    fclose(fp);
  }
}

// STUDENT FUNCTIONS
void addLesson(char *studentId, int maxCredit, int maxQuota) { // add a course
  int found, control1, control2, control3;
  int pairId, status, counter = 1;
  FILE *fp1, *fp2;
  char *lessonId = (char *)malloc(20 * sizeof(char));
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(100 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  DATE *date = (DATE *)malloc(sizeof(DATE));
  printf("\n (!) Add Course Operation\n");
  printf("\n --> Course Code: ");
  scanf(" %[^\n]s", lessonId); // read course code
  found = searchById(lessonId, "LESSONS.txt");
  control1 = addControl(studentId, lessonId);
  control2 = creditControl(studentId, lessonId,
                           maxCredit); // does the student have enough credits?
  control3 = quotaControl(lessonId, maxQuota); // is there space in the course?
  if (found == 0) { // do not add if the ID does not exist
    printf("\n (!) No course with this code exists.\n");
  } else if (found == 1 &&
             control1 == 0) { // do not add if it was already added before
    printf("\n (!) You are already taking this course.\n");
  } else if (found == 1 &&
             control2 == 0) { // do not add if there are not enough credits
    printf("\n (!) You do not have enough remaining credits.\n");
  } else if (found == 1 && control3 == 0) { // do not add if the quota is full
    printf("\n (!) The course quota is full.\n");
  } else if (found == 1 && control1 == 1 && control2 == 1 && control3 == 1) {
    // 1) add an entry to OgrenciDersKayit.txt
    fp1 = fopen("OgrenciDersKayit.txt", "r");
    fp2 = fopen("NEW_OgrenciDersKayit.txt", "w");
    control1 = emptyFile("OgrenciDersKayit.txt");
    if (control1) { // do this if the file is not empty
      while (!feof(fp1)) {
        fscanf(fp1, "\n%d", &pairId);
        fscanf(fp1, "<%[^-]s", tmpStudent);
        fscanf(fp1, "-%[^>]s", tmpLesson);
        fscanf(fp1, ">%d", &status);
        fscanf(fp1, ";%[^\n]s", tmpStr);
        if (strcmp(tmpStudent, studentId) != 0 ||
            strcmp(tmpLesson, lessonId) != 0 || status == 1) {
          fprintf(fp2, "\n%d<%s-%s>%d;%s", counter++, tmpStudent, tmpLesson,
                  status, tmpStr);
        }
      }
    }
    setTime(date);
    fprintf(fp2, "\n%d<%s-%s>1;", counter, studentId, lessonId);
    fprintf(fp2, "%02d/%02d/%d;%02d:%02d", date->day, date->month, date->year,
            date->hour, date->min);
    fclose(fp1);
    fclose(fp2);
    remove("OgrenciDersKayit.txt"); // delete the old file
    rename("NEW_OgrenciDersKayit.txt",
           "OgrenciDersKayit.txt"); // rename the new file
    // 2) update the student's course and credit totals
    findLesson(lessonId, newLesson);
    fp1 = fopen("STUDENTS.txt", "r");
    fp2 = fopen("NEW_STUDENTS.txt", "w");
    while (!feof(fp1)) {
      fscanf(fp1, "\n%[^;]s", newStudent->id);
      fscanf(fp1, ";%[^;]s", newStudent->name);
      fscanf(fp1, ";%[^;]s", newStudent->surname);
      fscanf(fp1, ";%d;%d", &newStudent->totalCredit, &newStudent->totalLesson);
      if (strcmp(newStudent->id, studentId) == 0) {
        newStudent->totalCredit = newStudent->totalCredit + newLesson->credit;
        newStudent->totalLesson = newStudent->totalLesson + 1;
      }
      // write to the new file
      fprintf(fp2, "\n%s;%s;%s;%d;%d", newStudent->id, newStudent->name,
              newStudent->surname, newStudent->totalCredit,
              newStudent->totalLesson);
    }
    fclose(fp1);
    fclose(fp2);
    remove("STUDENTS.txt"); // delete the old file
    rename("NEW_STUDENTS.txt",
           "STUDENTS.txt"); // rename the new file
    // 3) increase the used course quota
    fp1 = fopen("LESSONS.txt", "r");
    fp2 = fopen("NEW_LESSONS.txt", "w");
    while (!feof(fp1)) {
      fscanf(fp1, "\n%[^;]s", newLesson->id);
      fscanf(fp1, ";%[^;]s", newLesson->name);
      fscanf(fp1, ";%[^;]s", newLesson->teacherId);
      fscanf(fp1, ";%d;%d", &newLesson->credit, &newLesson->usedQuota);
      if (strcmp(newLesson->id, lessonId) == 0) {
        newLesson->usedQuota = newLesson->usedQuota + 1;
      }
      // write to the new file
      fprintf(fp2, "\n%s;%s;%s;%d;%d", newLesson->id, newLesson->name,
              newLesson->teacherId, newLesson->credit, newLesson->usedQuota);
    }
    fclose(fp1);
    fclose(fp2);
    remove("LESSONS.txt");                    // delete the old file
    rename("NEW_LESSONS.txt", "LESSONS.txt"); // rename the new file
    printf("\n (!) Course added successfully.\n");
  }
  free(lessonId);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  free(newLesson);
  free(newStudent);
  free(date);
}
void quitLesson(char *studentId) { // drop a course
  int found, control;
  int pairId, status;
  FILE *fp1, *fp2;
  char *lessonId = (char *)malloc(20 * sizeof(char));
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  DATE *date = (DATE *)malloc(sizeof(DATE));
  printf("\n (!) Drop Course Operation\n");
  control = getAnyLessonControl(studentId);
  if (control) { // proceed only if at least one course is taken
    printf("\n --> Code of the Course You Want to Drop: ");
    scanf(" %[^\n]s", lessonId);                 // read course code
    found = searchById(lessonId, "LESSONS.txt"); // does the course exist?
    control = getLessonControl(studentId,
                               lessonId); // is the student taking the course?
    if (found == 0) { // do nothing if the course does not exist
      printf("\n (!) No course with this code exists.\n");
    } else if (found == 1 &&
               control ==
                   0) { // do nothing if the student is not taking the course
      printf("\n (!) You are not currently taking this course.\n");
    } else if (found == 1 && control == 1) {
      // 1) set the course-taking status in OgrenciDersKayit.txt to 0
      fp1 = fopen("OgrenciDersKayit.txt", "r");
      fp2 = fopen("NEW_OgrenciDersKayit.txt", "w");
      while (!feof(fp1)) {
        fscanf(fp1, "\n%d", &pairId);
        fscanf(fp1, "<%[^-]s", tmpStudent);
        fscanf(fp1, "-%[^>]s", tmpLesson);
        fscanf(fp1, ">%d", &status);
        fscanf(fp1, ";%[^\n]s", tmpStr);
        if (strcmp(tmpStudent, studentId) == 0 &&
            strcmp(tmpLesson, lessonId) == 0 && status == 1) {
          status = 0;
        }
        fprintf(fp2, "\n%d<%s-%s>%d;", pairId, tmpStudent, tmpLesson, status);
        // update the date if it was removed
        if (strcmp(tmpStudent, studentId) == 0 &&
            strcmp(tmpLesson, lessonId) == 0) {
          setTime(date);
          fprintf(fp2, "%02d/%02d/%d;%02d:%02d", date->day, date->month,
                  date->year, date->hour, date->min);
        } else { // write the previous date if it was not removed
          fprintf(fp2, "%s", tmpStr);
        }
      }
      fclose(fp1);
      fclose(fp2);
      remove("OgrenciDersKayit.txt");
      rename("NEW_OgrenciDersKayit.txt", "OgrenciDersKayit.txt");
      // 2) subtract the dropped course and credit from the student
      findLesson(lessonId, newLesson);
      fp1 = fopen("STUDENTS.txt", "r");
      fp2 = fopen("NEW_STUDENTS.txt", "w");
      while (!feof(fp1)) {
        fscanf(fp1, "\n%[^;]s", newStudent->id);
        fscanf(fp1, ";%[^;]s", newStudent->name);
        fscanf(fp1, ";%[^;]s", newStudent->surname);
        fscanf(fp1, ";%d;%d", &newStudent->totalCredit,
               &newStudent->totalLesson);
        if (strcmp(newStudent->id, studentId) == 0) {
          newStudent->totalCredit = newStudent->totalCredit - newLesson->credit;
          newStudent->totalLesson = newStudent->totalLesson - 1;
        }
        // write to the new file
        fprintf(fp2, "\n%s;%s;%s;%d;%d", newStudent->id, newStudent->name,
                newStudent->surname, newStudent->totalCredit,
                newStudent->totalLesson);
      }
      fclose(fp1);
      fclose(fp2);
      remove("STUDENTS.txt"); // delete the old file
      rename("NEW_STUDENTS.txt",
             "STUDENTS.txt"); // rename the new file
      // 3) decrease the used course quota
      fp1 = fopen("LESSONS.txt", "r");
      fp2 = fopen("NEW_LESSONS.txt", "w");
      while (!feof(fp1)) {
        fscanf(fp1, "\n%[^;]s", newLesson->id);
        fscanf(fp1, ";%[^;]s", newLesson->name);
        fscanf(fp1, ";%[^;]s", newLesson->teacherId);
        fscanf(fp1, ";%d;%d", &newLesson->credit, &newLesson->usedQuota);
        if (strcmp(newLesson->id, lessonId) == 0) {
          newLesson->usedQuota = newLesson->usedQuota - 1;
        }
        // write to the new file
        fprintf(fp2, "\n%s;%s;%s;%d;%d", newLesson->id, newLesson->name,
                newLesson->teacherId, newLesson->credit, newLesson->usedQuota);
      }
      fclose(fp1);
      fclose(fp2);
      remove("LESSONS.txt"); // delete the old file
      rename("NEW_LESSONS.txt",
             "LESSONS.txt"); // rename the new file
      printf("\n (!) Course dropped successfully.\n");
    }
  } else {
    printf("\n (!) You are not taking any courses.\n");
  }
  free(lessonId);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  free(newLesson);
  free(newStudent);
  free(date);
}
void studentsLessons(
    char *studentId) { // print the courses taken by the student
  int control;
  int pairId, status;
  FILE *fp;
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  TEACHER *newTeacher = (TEACHER *)malloc(sizeof(TEACHER));
  control = getAnyLessonControl(studentId);
  if (control) {
    printf("\n (!) Courses You Are Taking:\n");
    fp = fopen("OgrenciDersKayit.txt", "r");
    while (!feof(fp)) {
      fscanf(fp, "\n%d", &pairId);
      fscanf(fp, "<%[^-]s", tmpStudent);
      fscanf(fp, "-%[^>]s", tmpLesson);
      fscanf(fp, ">%d", &status);
      fscanf(fp, ";%[^\n]s", tmpStr);
      if (strcmp(tmpStudent, studentId) == 0 && status == 1) {
        findLesson(tmpLesson, newLesson);
        findTeacher(newLesson->teacherId, newTeacher);
        printf(" --- %s --> %s --> Instructor: %s %s %s\n", newLesson->id,
               newLesson->name, newTeacher->title, newTeacher->name,
               newTeacher->surname);
      }
    }
    fclose(fp);
  } else {
    printf("\n (!) You are not taking any courses.\n");
  }
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  free(newLesson);
  free(newTeacher);
}
void searchTeacher() { // list the courses taught by the instructor with the
                       // given ID
  int found, control;
  FILE *fp;
  char *id = (char *)malloc(20 * sizeof(char));
  TEACHER *newTeacher = (TEACHER *)malloc(sizeof(TEACHER));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  printf("\n (!) Instructor Search Operation\n");
  // print the instructors
  printf("\n (!) You can find the courses taught by the instructors");
  printf("\n     below by searching with their IDs.\n\n");
  fp = fopen("TEACHERS.txt", "r");
  while (!feof(fp)) {
    fscanf(fp, "\n%[^;]s", newTeacher->id);
    fscanf(fp, ";%[^;]s", newTeacher->title);
    fscanf(fp, ";%[^;]s", newTeacher->name);
    fscanf(fp, ";%[^\n]s", newTeacher->surname);
    printf(" --- %s --> %s %s %s\n", newTeacher->id, newTeacher->title,
           newTeacher->name, newTeacher->surname);
  }
  fclose(fp);
  // get the instructor ID
  printf("\n --> ID of the Instructor You Want to Search: ");
  scanf(" %[^\n]s", id);                  // read ID
  found = searchById(id, "TEACHERS.txt"); // does the instructor exist?
  control = anyLesson(id); // does the instructor teach any course?
  if (found == 0) {        // warn if the instructor does not exist
    printf("\n (!) No instructor with this ID exists.\n");
  } else if (found == 1 &&
             control == 0) { // warn if the instructor has no course
    printf("\n (!) This instructor does not teach any courses.\n");
  } else if (found == 1 &&
             control == 1) { // print if the instructor has courses
    fp = fopen("LESSONS.txt", "r");
    printf("\n (!) Courses taught by the instructor with ID %s:\n", id);
    while (!feof(fp)) {
      fscanf(fp, "\n%[^;]s", newLesson->id);
      fscanf(fp, ";%[^;]s", newLesson->name);
      fscanf(fp, ";%[^;]s", newLesson->teacherId);
      fscanf(fp, ";%d", &newLesson->credit);
      fscanf(fp, ";%d", &newLesson->usedQuota);
      if (strcmp(newLesson->teacherId, id) == 0) {
        printf(" --- %s --> %s --> Credit: %d\n", newLesson->id,
               newLesson->name, newLesson->credit);
      }
    }
    fclose(fp);
  }
  free(id);
  free(newTeacher);
  free(newLesson);
}

// INSTRUCTOR FUNCTIONS
void createLesson(char *teacherId) { // create a course
  int found;
  FILE *fp;
  char *id = (char *)malloc(20 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  printf("\n (!) Create Course Operation\n");
  printf("\n --> Course Code: ");
  scanf(" %[^\n]s", id); // read course code
  found = searchById(id, "LESSONS.txt");
  if (found == 0) { // add if the ID does not exist
    strcpy(newLesson->id, id);
    printf(" --> Course Name: ");
    scanf(" %[^\n]s", newLesson->name);
    printf(" --> Course Credit: ");
    scanf("%d", &newLesson->credit);
    strcpy(newLesson->teacherId, teacherId);
    newLesson->usedQuota = 0;
    fp = fopen("LESSONS.txt", "a");
    fprintf(fp, "\n%s;%s;%s;%d;%d", newLesson->id, newLesson->name,
            newLesson->teacherId, newLesson->credit, newLesson->usedQuota);
    fclose(fp);
    printf("\n (!) Course created successfully.\n");
  } else if (found == 1) { // do not add if the ID already exists
    printf("\n (!) A course with this code already exists.\n");
  }
  free(id);
  free(newLesson);
}
void updateLesson(char *teacherId) { // update a course
  int found, control;
  FILE *fp1, *fp2;
  char *id = (char *)malloc(20 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  printf("\n (!) Update Course Operation\n");
  control = anyLesson(teacherId);
  if (control) {
    printf(" (!) IMPORTANT: A credit change will not affect");
    printf("\n     students who previously took the course.\n");
    printf("\n --> Course Code to Update: ");
    scanf(" %[^\n]s", id);                 // read ID
    found = searchById(id, "LESSONS.txt"); // search by ID
    control = controlLesson(
        id, teacherId); // check whether the course belongs to the instructor
    if (found == 0) {   // do not update if the ID does not exist
      printf("\n (!) No course with this code exists.\n");
    } else if (found == 1 && control == 0) { // do not update if the course does
                                             // not belong to the user
      printf("\n (!) The course with this code does not belong to you.\n");
    } else if (found == 1 && control == 1) { // update if the ID exists
      printf("\n (!) Course found.");
      fp1 = fopen("LESSONS.txt", "r");
      fp2 = fopen("NEW_LESSONS.txt", "w"); // updated version
      while (!feof(fp1)) {
        fscanf(fp1, "\n%[^;]s", newLesson->id);
        fscanf(fp1, ";%[^;]s", newLesson->name);
        fscanf(fp1, ";%[^;]s", newLesson->teacherId);
        fscanf(fp1, ";%d;%d", &newLesson->credit, &newLesson->usedQuota);
        if (strcmp(newLesson->id, id) ==
            0) { // get new values for the ID being changed
          // print the current information
          printf("\n --- Course Name: %s", newLesson->name);
          printf("\n --- Course Credit: %d\n", newLesson->credit);
          // enter the updated information
          printf("\n (!) Enter the updated course information.");
          printf("\n --> Updated Course Name: ");
          scanf(" %[^\n]s", newLesson->name);
          printf(" --> Updated Course Credit: ");
          scanf("%d", &newLesson->credit);
        }
        // write to the new file
        fprintf(fp2, "\n%s;%s;%s;%d;%d", newLesson->id, newLesson->name,
                newLesson->teacherId, newLesson->credit, newLesson->usedQuota);
      }
      fclose(fp1);
      fclose(fp2);
      remove("LESSONS.txt"); // delete the old file
      rename("NEW_LESSONS.txt",
             "LESSONS.txt"); // rename the new file
      printf("\n (!) Course updated successfully.\n");
    }
  } else {
    printf("\n (!) You do not have any courses assigned to you.\n");
  }
  free(id);
  free(newLesson);
}
void deleteLesson(char *teacherId) { // delete a course
  int found, control;
  int pairId, status, counter = 1;
  FILE *fp1, *fp2, *fp3, *fp4;
  char *lessonId = (char *)malloc(20 * sizeof(char));
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  printf("\n (!) Delete Course Operation\n");
  control = anyLesson(teacherId);
  if (control) {
    printf("\n --> Course Code to Delete: ");
    scanf(" %[^\n]s", lessonId);                 // read ID
    found = searchById(lessonId, "LESSONS.txt"); // search by ID
    control = controlLesson(
        lessonId,
        teacherId);   // check whether the course belongs to the instructor
    if (found == 0) { // do not proceed if the ID does not exist
      printf("\n (!) No course with this code exists.\n");
    } else if (found == 1 && control == 0) { // do not proceed if the course
                                             // does not belong to the user
      printf("\n (!) The course with this code does not belong to you.\n");
    } else if (found == 1 && control == 1) { // proceed if the ID exists
      // 1) apply changes for students who took or dropped the course
      fp1 = fopen("OgrenciDersKayit.txt", "r");
      fp2 = fopen("NEW_OgrenciDersKayit.txt", "w");
      findLesson(lessonId, newLesson);
      while (!feof(fp1)) {
        fscanf(fp1, "\n%d", &pairId);
        fscanf(fp1, "<%[^-]s", tmpStudent);
        fscanf(fp1, "-%[^>]s", tmpLesson);
        fscanf(fp1, ">%d", &status);
        fscanf(fp1, ";%[^\n]s", tmpStr);
        // update students taking the course
        if (strcmp(tmpLesson, lessonId) == 0 && status == 1) {
          fp3 = fopen("STUDENTS.txt", "r");
          fp4 = fopen("NEW_STUDENTS.txt", "w");
          while (!feof(fp3)) {
            fscanf(fp3, "\n%[^;]s", newStudent->id);
            fscanf(fp3, ";%[^;]s", newStudent->name);
            fscanf(fp3, ";%[^;]s", newStudent->surname);
            fscanf(fp3, ";%d;%d", &newStudent->totalCredit,
                   &newStudent->totalLesson);
            // reduce credits and course count for that student
            if (strcmp(newStudent->id, tmpStudent) == 0) {
              newStudent->totalCredit =
                  newStudent->totalCredit - newLesson->credit;
              newStudent->totalLesson = newStudent->totalLesson - 1;
            }
            fprintf(fp4, "\n%s;%s;%s;%d;%d", newStudent->id, newStudent->name,
                    newStudent->surname, newStudent->totalCredit,
                    newStudent->totalLesson);
          }
          fclose(fp3);
          fclose(fp4);
          remove("STUDENTS.txt"); // delete the old file
          rename("NEW_STUDENTS.txt",
                 "STUDENTS.txt"); // rename the new file
        }
        // write all other courses except the deleted one
        if (!(strcmp(tmpLesson, lessonId) == 0)) {
          fprintf(fp2, "\n%d<%s-%s>%d;%s", counter++, tmpStudent, tmpLesson,
                  status, tmpStr);
        }
      }
      fclose(fp1);
      fclose(fp2);
      remove("OgrenciDersKayit.txt");
      rename("NEW_OgrenciDersKayit.txt", "OgrenciDersKayit.txt");
      // 2) remove the course from the course list
      fp1 = fopen("LESSONS.txt", "r");
      fp2 = fopen("NEW_LESSONS.txt", "w"); // updated version
      while (!feof(fp1)) {
        fscanf(fp1, "\n%[^;]s", newLesson->id);
        fscanf(fp1, ";%[^;]s", newLesson->name);
        fscanf(fp1, ";%[^;]s", newLesson->teacherId);
        fscanf(fp1, ";%d;%d", &newLesson->credit, &newLesson->usedQuota);
        if (!(strcmp(newLesson->id, lessonId) ==
              0)) { // write all courses except the deleted one
          fprintf(fp2, "\n%s;%s;%s;%d;%d", newLesson->id, newLesson->name,
                  newLesson->teacherId, newLesson->credit,
                  newLesson->usedQuota);
        }
      }
      fclose(fp1);
      fclose(fp2);
      remove("LESSONS.txt"); // delete the old file
      rename("NEW_LESSONS.txt",
             "LESSONS.txt"); // rename the new file
      printf("\n (!) Course deleted successfully.\n");
    }
  } else {
    printf("\n (!) You do not have any courses assigned to you.\n");
  }
  free(lessonId);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  free(newLesson);
  free(newStudent);
}
void teachersLessons(
    char *teacherId) { // print the courses taught by the instructor
  int control;
  FILE *fp;
  TEACHER *newTeacher = (TEACHER *)malloc(sizeof(TEACHER));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  control = anyLesson(teacherId); // does the instructor teach any course?
  if (!control) {                 // warn if the instructor has no course
    printf("\n (!) You do not teach any courses.\n");
  } else { // print if the instructor has courses
    fp = fopen("LESSONS.txt", "r");
    printf("\n (!) Courses You Teach:\n");
    while (!feof(fp)) {
      fscanf(fp, "\n%[^;]s", newLesson->id);
      fscanf(fp, ";%[^;]s", newLesson->name);
      fscanf(fp, ";%[^;]s", newLesson->teacherId);
      fscanf(fp, ";%d", &newLesson->credit);
      fscanf(fp, ";%d", &newLesson->usedQuota);
      if (strcmp(newLesson->teacherId, teacherId) == 0) {
        printf(" --- %s --> %s --> Credit: %d\n", newLesson->id,
               newLesson->name, newLesson->credit);
      }
    }
    fclose(fp);
  }
  free(newTeacher);
  free(newLesson);
}
void searchLesson() { // print students taking the course with the given ID
  int found, control;
  int pairId, status;
  FILE *fp;
  char *lessonId = (char *)malloc(20 * sizeof(char));
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  printf("\n (!) View Course Roster Operation\n");
  printf("\n --> Course Code: ");
  scanf(" %[^\n]s", lessonId);                 // read course code
  found = searchById(lessonId, "LESSONS.txt"); // does the course exist?
  control =
      anyoneGetLessonControl(lessonId); // is any student taking the course?
  if (found == 0) { // do nothing if the course does not exist
    printf("\n (!) No course with this code exists.\n");
  } else if (found == 1 &&
             control == 0) { // do nothing if no student takes the course
    printf("\n (!) No student is taking this course.\n");
  } else if (found == 1 &&
             control == 1) { // print if students are taking the course
    printf("\n (!) Roster of the Course with Code %s\n", lessonId);
    fp = fopen("OgrenciDersKayit.txt", "r");
    while (!feof(fp)) {
      fscanf(fp, "\n%d", &pairId);
      fscanf(fp, "<%[^-]s", tmpStudent);
      fscanf(fp, "-%[^>]s", tmpLesson);
      fscanf(fp, ">%d", &status);
      fscanf(fp, ";%[^\n]s", tmpStr);
      if (strcmp(tmpLesson, lessonId) == 0) {
        findStudent(tmpStudent, newStudent);
        printf(" --- %s --> %s %s --->", newStudent->id, newStudent->name,
               newStudent->surname);
        if (status) {
          printf(" ENROLLED\n");
        } else {
          printf("DROPPED\n");
        }
      }
    }
    fclose(fp);
  }
  free(lessonId);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  free(newLesson);
  free(newStudent);
}
void attendanceList(char *teacherId) { // list students taking the course with
                                       // the given ID in a txt file
  int found, control1, control2;
  int pairId, status;
  FILE *fp1, *fp2;
  char *fileName = (char *)malloc(50 * sizeof(char));
  char *lessonId = (char *)malloc(20 * sizeof(char));
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  printf("\n (!) Create Attendance List Operation\n");
  printf("\n --> Course Code: ");
  scanf(" %[^\n]s", lessonId);                 // read course code
  found = searchById(lessonId, "LESSONS.txt"); // does the course exist?
  control1 = controlLesson(
      lessonId, teacherId); // does this course belong to the instructor?
  control2 =
      anyoneGetLessonControl(lessonId); // is any student taking the course?
  if (found == 0) { // do nothing if the course does not exist
    printf("\n (!) No course with this code exists.\n");
  } else if (found == 1 && control1 == 0) { // do nothing if the course does not
                                            // belong to the instructor
    printf("\n (!) This course does not belong to you.\n");
  } else if (found == 1 &&
             control2 == 0) { // do nothing if no student takes the course
    printf("\n (!) No student is taking this course.\n");
  } else if (found == 1 && control1 == 1 &&
             control2 == 1) { // create the file if there is no problem
    strcpy(fileName, lessonId);
    strcat(fileName, "_CLASS_LIST.txt");
    fp1 = fopen("OgrenciDersKayit.txt", "r");
    fp2 = fopen(fileName, "w");
    fprintf(fp2, "\n --- Class List of Course %s --- \n\n", lessonId);
    while (!feof(fp1)) {
      fscanf(fp1, "\n%d", &pairId);
      fscanf(fp1, "<%[^-]s", tmpStudent);
      fscanf(fp1, "-%[^>]s", tmpLesson);
      fscanf(fp1, ">%d", &status);
      fscanf(fp1, ";%[^\n]s", tmpStr);
      if (strcmp(tmpLesson, lessonId) == 0 && status == 1) {
        findStudent(tmpStudent, newStudent);
        fprintf(fp2, " --- %s --> %s %s\n", newStudent->id, newStudent->name,
                newStudent->surname);
      }
    }
    fclose(fp1);
    fclose(fp2);
    printf("\n (!) Attendance list created successfully.\n");
  }
  free(fileName);
  free(lessonId);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  free(newLesson);
  free(newStudent);
}

// ADMIN FUNCTIONS
void createStudent() { // create a student
  int found;
  FILE *fp;
  char *id = (char *)malloc(20 * sizeof(char));
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  printf("\n (!) Add Student Operation\n");
  printf("\n --> Student ID: ");
  scanf(" %[^\n]s", id);                  // read student ID
  found = searchById(id, "STUDENTS.txt"); // search by ID
  if (found == 0) {                       // add if the ID does not exist
    strcpy(newStudent->id, id);
    printf(" --> Student Name: ");
    scanf(" %[^\n]s", newStudent->name);
    printf(" --> Student Surname: ");
    scanf(" %[^\n]s", newStudent->surname);
    newStudent->totalCredit = 0;
    newStudent->totalLesson = 0;
    fp = fopen("STUDENTS.txt", "a");
    fprintf(fp, "\n%s;%s;%s;%d;%d", newStudent->id, newStudent->name,
            newStudent->surname, newStudent->totalCredit,
            newStudent->totalLesson);
    fclose(fp);
    printf("\n (!) Student added successfully.\n");
  } else if (found == 1) { // do not add if the ID already exists
    printf("\n (!) A student with this ID already exists.\n");
  }
  free(id);
  free(newStudent);
}
void updateStudent() { // update a student
  int found;
  FILE *fp1, *fp2;
  char *id = (char *)malloc(20 * sizeof(char));
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  printf("\n (!) Update Student Operation\n");
  printf("\n --> Student ID to Update: ");
  scanf(" %[^\n]s", id);                  // read ID
  found = searchById(id, "STUDENTS.txt"); // search by ID
  if (found == 0) { // do not update if the ID does not exist
    printf("\n (!) No student with this ID exists.\n");
  } else if (found == 1) { // update if the ID exists
    printf("\n (!) Student found.");
    fp1 = fopen("STUDENTS.txt", "r");
    fp2 = fopen("NEW_STUDENTS.txt", "w"); // updated version
    while (!feof(fp1)) {
      fscanf(fp1, "\n%[^;]s", newStudent->id);
      fscanf(fp1, ";%[^;]s", newStudent->name);
      fscanf(fp1, ";%[^;]s", newStudent->surname);
      fscanf(fp1, ";%d;%d", &newStudent->totalCredit, &newStudent->totalLesson);
      if (strcmp(newStudent->id, id) ==
          0) { // get new values for the ID being changed
        // print the current information
        printf("\n --- Student Name: %s", newStudent->name);
        printf("\n --- Student Surname: %s\n", newStudent->surname);
        // enter the updated information
        printf("\n (!) Enter the updated student information.");
        printf("\n --> Updated Student Name: ");
        scanf(" %[^\n]s", newStudent->name);
        printf(" --> Updated Student Surname: ");
        scanf(" %[^\n]s", newStudent->surname);
      }
      // write to the new file
      fprintf(fp2, "\n%s;%s;%s;%d;%d", newStudent->id, newStudent->name,
              newStudent->surname, newStudent->totalCredit,
              newStudent->totalLesson);
    }
    fclose(fp1);
    fclose(fp2);
    remove("STUDENTS.txt"); // delete the old file
    rename("NEW_STUDENTS.txt",
           "STUDENTS.txt"); // rename the new file
    printf("\n (!) Student updated successfully.\n");
  }
  free(id);
  free(newStudent);
}
void deleteStudent() { // delete a student
  int found, control;
  int pairId, status, counter = 1;
  FILE *fp1, *fp2, *fp3, *fp4;
  char *studentId = (char *)malloc(20 * sizeof(char));
  char *tmpStudent = (char *)malloc(20 * sizeof(char));
  char *tmpLesson = (char *)malloc(20 * sizeof(char));
  char *tmpStr = (char *)malloc(20 * sizeof(char));
  LESSON *newLesson = (LESSON *)malloc(sizeof(LESSON));
  STUDENT *newStudent = (STUDENT *)malloc(sizeof(STUDENT));
  printf("\n (!) Delete Student Operation\n");
  printf("\n --> Student ID to Delete: ");
  scanf(" %[^\n]s", studentId);                  // read ID
  found = searchById(studentId, "STUDENTS.txt"); // search by ID
  if (found == 0) { // do nothing if the ID does not exist
    printf("\n (!) No student with this ID exists.\n");
  } else if (found == 1) { // proceed if the ID exists
    // 1) delete course records through OgrenciDersKayit.txt
    // if not dropped, decrease the quota through LESSONS.txt and delete it
    // if already dropped, delete it directly
    fp1 = fopen("OgrenciDersKayit.txt", "r");
    fp2 = fopen("NEW_OgrenciDersKayit.txt", "w");
    while (!feof(fp1)) {
      fscanf(fp1, "\n%d", &pairId);
      fscanf(fp1, "<%[^-]s", tmpStudent);
      fscanf(fp1, "-%[^>]s", tmpLesson);
      fscanf(fp1, ">%d", &status);
      fscanf(fp1, ";%[^\n]s", tmpStr);
      // decrease the course quota if the student is taking the course
      if (strcmp(tmpStudent, studentId) == 0 && status == 1) {
        fp3 = fopen("LESSONS.txt", "r");
        fp4 = fopen("NEW_LESSONS.txt", "w");
        while (!feof(fp3)) {
          fscanf(fp3, "\n%[^;]s", newLesson->id);
          fscanf(fp3, ";%[^;]s", newLesson->name);
          fscanf(fp3, ";%[^;]s", newLesson->teacherId);
          fscanf(fp3, ";%d;%d", &newLesson->credit, &newLesson->usedQuota);
          // decrease the quota when that course is found
          if (strcmp(newLesson->id, tmpLesson) == 0) {
            newLesson->usedQuota = newLesson->usedQuota - 1;
          }
          // write to the new file
          fprintf(fp4, "\n%s;%s;%s;%d;%d", newLesson->id, newLesson->name,
                  newLesson->teacherId, newLesson->credit,
                  newLesson->usedQuota);
        }
        fclose(fp3);
        fclose(fp4);
        remove("LESSONS.txt"); // delete the old file
        rename("NEW_LESSONS.txt",
               "LESSONS.txt"); // rename the new file
      }
      // write to the new file if it is not a dropped/registered course of this
      // student
      if (!(strcmp(tmpStudent, studentId) == 0)) {
        fprintf(fp2, "\n%d<%s-%s>%d;%s", counter++, tmpStudent, tmpLesson,
                status, tmpStr);
      }
    }
    fclose(fp1);
    fclose(fp2);
    remove("OgrenciDersKayit.txt");
    rename("NEW_OgrenciDersKayit.txt", "OgrenciDersKayit.txt");
    // 2) delete the student from STUDENTS.txt
    fp1 = fopen("STUDENTS.txt", "r");
    fp2 = fopen("NEW_STUDENTS.txt", "w"); // updated version
    while (!feof(fp1)) {
      fscanf(fp1, "\n%[^;]s", newStudent->id);
      fscanf(fp1, ";%[^;]s", newStudent->name);
      fscanf(fp1, ";%[^;]s", newStudent->surname);
      fscanf(fp1, ";%d;%d", &newStudent->totalCredit, &newStudent->totalLesson);
      if (!(strcmp(newStudent->id, studentId) ==
            0)) { // add everyone except the deleted student
        fprintf(fp2, "\n%s;%s;%s;%d;%d", newStudent->id, newStudent->name,
                newStudent->surname, newStudent->totalCredit,
                newStudent->totalLesson);
      }
    }
    fclose(fp1);
    fclose(fp2);
    remove("STUDENTS.txt"); // delete the old file
    rename("NEW_STUDENTS.txt",
           "STUDENTS.txt"); // rename the new file
    printf("\n (!) Student deleted successfully.\n");
  }
  free(studentId);
  free(tmpStudent);
  free(tmpLesson);
  free(tmpStr);
  free(newLesson);
  free(newStudent);
}
void createTeacher() { // create an instructor
  int found;
  FILE *fp;
  char *id = (char *)malloc(20 * sizeof(char));
  TEACHER *newTeacher = (TEACHER *)malloc(sizeof(TEACHER));
  printf("\n (!) Add Instructor Operation\n");
  printf("\n --> Instructor ID: ");
  scanf(" %[^\n]s", id);                  // read ID
  found = searchById(id, "TEACHERS.txt"); // search by ID
  if (found == 0) {                       // add if the ID does not exist
    strcpy(newTeacher->id, id);
    printf(" --> Instructor Name: ");
    scanf(" %[^\n]s", newTeacher->name);
    printf(" --> Instructor Surname: ");
    scanf(" %[^\n]s", newTeacher->surname);
    printf(" --> Instructor Title: ");
    scanf(" %[^\n]s", newTeacher->title);
    fp = fopen("TEACHERS.txt", "a");
    fprintf(fp, "\n%s;%s;%s;%s", newTeacher->id, newTeacher->title,
            newTeacher->name, newTeacher->surname);
    fclose(fp);
    printf("\n (!) Instructor added successfully.\n");
  } else if (found == 1) { // do not add if the ID already exists
    printf("\n (!) An instructor with this ID already exists.\n");
  }
  free(id);
  free(newTeacher);
}
void updateTeacher() { // update an instructor
  int found;
  FILE *fp1, *fp2;
  char *id = (char *)malloc(20 * sizeof(char));
  TEACHER *newTeacher = (TEACHER *)malloc(sizeof(TEACHER));
  printf("\n (!) Update Instructor Operation\n");
  printf("\n --> Instructor ID to Update: ");
  scanf(" %[^\n]s", id);                  // read ID
  found = searchById(id, "TEACHERS.txt"); // search by ID
  if (found == 0) { // do not update if the ID does not exist
    printf("\n (!) No instructor with this ID exists.\n");
  } else if (found == 1) { // update if the ID exists
    printf("\n (!) Instructor found.");
    fp1 = fopen("TEACHERS.txt", "r");
    fp2 = fopen("NEW_TEACHERS.txt", "w"); // updated version
    while (!feof(fp1)) {
      fscanf(fp1, "\n%[^;]s", newTeacher->id);
      fscanf(fp1, ";%[^;]s", newTeacher->title);
      fscanf(fp1, ";%[^;]s", newTeacher->name);
      fscanf(fp1, ";%[^\n]s", newTeacher->surname);
      if (strcmp(newTeacher->id, id) ==
          0) { // get new values for the ID being changed
        // print the current information
        printf("\n --- Instructor Title: %s", newTeacher->title);
        printf("\n --- Instructor Name: %s", newTeacher->name);
        printf("\n --- Instructor Surname: %s\n", newTeacher->surname);
        // enter the updated information
        printf("\n (!) Enter the updated instructor information.\n");
        printf("\n --> Updated Instructor Name: ");
        scanf(" %[^\n]s", newTeacher->name);
        printf(" --> Updated Instructor Surname: ");
        scanf(" %[^\n]s", newTeacher->surname);
        printf(" --> Updated Instructor Title: ");
        scanf(" %[^\n]s", newTeacher->title);
      }
      // write to the new file
      fprintf(fp2, "\n%s;%s;%s;%s", newTeacher->id, newTeacher->title,
              newTeacher->name, newTeacher->surname);
    }
    fclose(fp1);
    fclose(fp2);
    remove("TEACHERS.txt"); // delete the old file
    rename("NEW_TEACHERS.txt",
           "TEACHERS.txt"); // rename the new file
    printf("\n (!) Instructor updated successfully.\n");
  }
  free(id);
  free(newTeacher);
}
void deleteTeacher() { // delete an instructor
  int found, control;
  FILE *fp1, *fp2;
  char *id = (char *)malloc(20 * sizeof(char));
  TEACHER *newTeacher = (TEACHER *)malloc(sizeof(TEACHER));
  printf("\n (!) Delete Instructor Operation\n");
  printf("\n --> Instructor ID to Delete: ");
  scanf(" %[^\n]s", id);                  // read ID
  found = searchById(id, "TEACHERS.txt"); // search by ID
  control = anyLesson(id); // does the instructor have any course?
  if (found == 0) {        // do nothing if the ID does not exist
    printf("\n (!) No instructor with this ID exists.\n");
  } else if (found == 1 && control == 1) {
    printf("\n (!) This instructor still has assigned courses.");
    printf("\n (!) To delete an instructor, they must not have");
    printf("\n     any courses assigned.\n");
  } else if (found == 1 && control == 0) { // proceed if there is no issue
    fp1 = fopen("TEACHERS.txt", "r");
    fp2 = fopen("NEW_TEACHERS.txt", "w"); // updated version
    while (!feof(fp1)) {
      fscanf(fp1, "\n%[^;]s", newTeacher->id);
      fscanf(fp1, ";%[^;]s", newTeacher->title);
      fscanf(fp1, ";%[^;]s", newTeacher->name);
      fscanf(fp1, ";%[^\n]s", newTeacher->surname);
      if (!(strcmp(newTeacher->id, id) ==
            0)) { // add everyone except the deleted ID
        fprintf(fp2, "\n%s;%s;%s;%s", newTeacher->id, newTeacher->title,
                newTeacher->name, newTeacher->surname);
      }
    }
    fclose(fp1);
    fclose(fp2);
    remove("TEACHERS.txt"); // delete the old file
    rename("NEW_TEACHERS.txt",
           "TEACHERS.txt"); // rename the new file
    printf("\n (!) Instructor deleted successfully.\n");
  }
  free(id);
  free(newTeacher);
}

// MENU HELPERS
void mainSignIn() { // main sign-in screen
  printf(" ________________________\n");
  printf(" |                      |\n");
  printf(" |  COURSE REGISTRATION  |\n");
  printf(" |______________________|\n");
}
void mainMenu() { // main menu
  printf("\n- 1: Student Login");
  printf("\n- 2: Instructor Login");
  printf("\n- 3: Admin Login\n");
  printf("\n- 0: Exit\n");
}
void studentSignIn() { // student sign-in screen
  printf(" ____________________\n");
  printf(" |                  |\n");
  printf(" |   Student Login   |\n");
  printf(" |__________________|\n");
}
void studentMenu() { // student menu
  printf("\n- 1: Add Course");
  printf("\n- 2: Drop Course");
  printf("\n- 3: My Courses");
  printf("\n- 4: Search Instructor\n");
  printf("\n- 9: Back");
  printf("\n- 0: Exit\n");
}
void teacherSignIn() { // instructor sign-in screen
  printf(" __________________________\n");
  printf(" |                        |\n");
  printf(" |  Instructor Login  |\n");
  printf(" |________________________|\n");
}
void teacherMenu() { // instructor menu
  printf("\n- 1: Create Course");
  printf("\n- 2: Update Course");
  printf("\n- 3: Delete Course\n");
  printf("\n- 4: My Courses");
  printf("\n- 5: View Course Roster");
  printf("\n- 6: Create Attendance List\n");
  printf("\n- 9: Back");
  printf("\n- 0: Exit\n");
}
void adminSignIn() { // admin sign-in screen
  printf(" _____________________\n");
  printf(" |                   |\n");
  printf(" |    Admin Login    |\n");
  printf(" |___________________|\n");
}
void adminMenu() { // admin menu
  printf("\n- 1: Add Student");
  printf("\n- 2: Update Student");
  printf("\n- 3: Delete Student\n");
  printf("\n- 4: Add Instructor");
  printf("\n- 5: Update Instructor");
  printf("\n- 6: Delete Instructor\n");
  printf("\n- 9: Back");
  printf("\n- 0: Exit\n");
}
int doneMenu() { // menu shown after an operation finishes
  // return 0 --> exit
  // return 1 --> go back
  int cmd;
  printf("\n- 9: Back");
  printf("\n- 0: Exit\n");
  cmd = getCmd(4);
  if (cmd == 0) {
    return 0;
  } else if (cmd == 9) {
    return 1;
  }
}
