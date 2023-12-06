/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta5_codes
cc -o test hafta5_4_bitfields_unions.c 
*/
#include <stdio.h>

// bitfield e.g.
typedef struct { 	unsigned int day : 5;
 	unsigned int month : 4;
 	unsigned int year : 11;
} DATE; 			//alternative solution: struct DATE{ };
typedef struct {   char ps_name[20], ps_tcno[11];   DATE ps_birth_date;} PERSONALSTAT;

// union e.g.
typedef union {
   struct{
   	char c1, c2;
   } s;
   long j;
   float x;
} UNION_EG;
int main(){
	int j;
	unsigned int val;
	PERSONALSTAT ps2[2];
	UNION_EG example;
/*
	// BITFIELD:
	for(j=0; j<2; j++){
		printf("Enter name of the %d-th person:\n", j+1);
		scanf("%s", ps2[j].ps_name);
		printf("Enter tcno of the %d-th person:\n", j+1);
		scanf("%s", ps2[j].ps_tcno);
		printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
		// NOT ALLOWED: scanf("%u", &ps2[j].ps_birth_date.day);
		scanf("%u", &val); ps2[j].ps_birth_date.day=val;
		printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
		// NOT ALLOWED: scanf("%u", &ps2[j].ps_birth_date.month);
		scanf("%u", &val); ps2[j].ps_birth_date.month=val;
		printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
		// NOT ALLOWED: scanf("%u", &ps2[j].ps_birth_date.year);
		scanf("%u", &val); ps2[j].ps_birth_date.year=val;		

	}

	for(j=0; j<2; j++)
		printf("%d-th person: %s\t%s\t%u.%u.%u\n", j+1, ps2[j].ps_name, ps2[j].ps_tcno,
			ps2[j].ps_birth_date.day, ps2[j].ps_birth_date.month, ps2[j].ps_birth_date.year);
*/

	// UNION:
	example.s.c1='a';
	example.s.c2='b';
	printf("example.s.c1: %c\n", example.s.c1);
	printf("example.s.c2: %c\n", example.s.c2);
	printf("example.j: %ld\n", example.j);
	printf("example.x: %f\n", example.x);

	example.j=5;
	printf("example.s.c1: %c\n", example.s.c1);
	printf("example.s.c2: %c\n", example.s.c2);
	printf("example.j: %ld\n", example.j);

	return 0;
}