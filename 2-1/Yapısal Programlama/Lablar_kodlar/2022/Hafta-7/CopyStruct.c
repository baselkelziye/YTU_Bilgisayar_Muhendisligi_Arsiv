/*
 * http://fresh2refresh.com/c-programming/c-structure-using-pointer/
 * Example program to copy a structure in C
 */
#include <stdio.h>
#include <string.h>

struct student 
{
    int id;
    char name[30];
    float percentage;
};

int main() 
{
    int i;
    struct student record1 = {1, "Raju", 90.5};
    struct student record2, record3, *ptr1, record4;

    printf("Records of STUDENT1 - record1 structure \n");
    printf("  Id : %d \n  Name : %s\n  Percentage : %f\n",
            record1.id, record1.name, record1.percentage);
    printf("  Id : %p \n  Name : %p\n  Percentage : %p\n",
	&record1.id, &record1.name, &record1.percentage);

    // 1st method to copy whole structure to another structure
    record2=record1;  
	
	record1.name[1]='X';  
	
	printf("Records of STUDENT1 - record1 structure \n");
    printf("  Id : %d \n  Name : %s\n  Percentage : %f\n",
            record1.id, record1.name, record1.percentage);
    printf("  Id : %p \n  Name : %p\n  Percentage : %p\n",
	&record1.id, &record1.name, &record1.percentage);

    printf("\nRecords of STUDENT1 - Direct copy from " \
           "record1 \n");
    printf("  Id : %d \n  Name : %s\n  Percentage : %f\n", 
    record2.id, record2.name, record2.percentage);
    printf("  Id : %p \n  Name : %p\n  Percentage : %p\n", 
    &record2.id, &record2.name, &record2.percentage);

    // 2nd method to copy using memcpy function
    ptr1 = &record1; 
    memcpy(&record3, ptr1, sizeof(record1));
   ptr1 = &record3;
    printf("\nRecords of STUDENT1 - copied from record1 " \
           "using memcpy \n");
    printf("  Id : %d \n  Name : %s\n  Percentage : %f\n", 
           ptr1->id, ptr1->name, ptr1->percentage);

    // 3rd method to copy by individual members
    printf("\nRecords of STUDENT1 - Copied individual " \
           "members from record1 \n");
    record4.id=record1.id;
    strcpy(record4.name, record1.name);
    record4.percentage = record1.percentage;

    printf("  Id : %d \n  Name : %s\n  Percentage : %f\n", 
            record4.id, record4.name, record4.percentage);

     return 0;
}
