/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta5_codes
cc -o test hafta5_5_unions.c 
*/
#include <stdio.h>

// bitfield e.g.
typedef struct { 	unsigned int day : 5;
 	unsigned int month : 4;
 	unsigned int year : 11;
} DATE; 

typedef struct {   char ps_name[20], ps_tcno[11];   DATE ps_birth_date;
   // Bit field for TC citizenship:    unsigned int TCcitizen : 1;   union{      char nationality[20];      char city_of_birth[20];   } location;} PERSONALSTAT;
int main(){
	int j;
	unsigned int val;
	PERSONALSTAT ps2[2];

	for(j=0; j<2; j++){
		printf("Enter name of the %d-th person:\n", j+1);
		scanf("%s", ps2[j].ps_name);
		printf("Enter tcno of the %d-th person:\n", j+1);
		scanf("%s", ps2[j].ps_tcno);
		printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
		scanf("%u", &val); ps2[j].ps_birth_date.day=val;
		printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
		scanf("%u", &val); ps2[j].ps_birth_date.month=val;
		printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
		scanf("%u", &val); ps2[j].ps_birth_date.year=val;
		printf("Enter 1 if this person is TC citizen, enter 0 otherwise\n");
		scanf("%u", &val); ps2[j].TCcitizen=val;
		if(val==1){
			printf("Enter the city of birth of the %d-th person:\n", j+1);
			scanf("%s", ps2[j].location.city_of_birth);
		}
		if(val==0){
			printf("Enter the nationality of the %d-th person:\n", j+1);
			scanf("%s", ps2[j].location.nationality);
		}
	}

	for(j=0; j<2; j++){
		if(ps2[j].TCcitizen==1)
		   printf("%d-th person: %s\t%s\t%u.%u.%u\t%s\n", j+1, 
			ps2[j].ps_name, ps2[j].ps_tcno, ps2[j].ps_birth_date.day, 
			ps2[j].ps_birth_date.month, ps2[j].ps_birth_date.year, 
			ps2[j].location.city_of_birth);
		else
		   printf("%d-th person: %s\t%s\t%u.%u.%u\t%s\n", j+1, 
			ps2[j].ps_name, ps2[j].ps_tcno, ps2[j].ps_birth_date.day, 
			ps2[j].ps_birth_date.month, ps2[j].ps_birth_date.year, 
			ps2[j].location.nationality);

	}
 
	return 0;
}
