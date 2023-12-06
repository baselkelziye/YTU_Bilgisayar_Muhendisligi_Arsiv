/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta5_codes
cc -o test hafta5_3_refer_refWpntr.c 
*/
#include <stdio.h>

typedef struct {   char ps_name[20], ps_tcno[11];   short ps_day, ps_month, ps_year;} PERSONALSTAT;int main(){
	int j;
	PERSONALSTAT ps2[2], *ptrps;

	// REFERENCING STRUCTURE MEMBERS
	for(j=0; j<2; j++){
		printf("Enter name of the %d-th person:\n", j+1);
		scanf("%s", ps2[j].ps_name);
		printf("Enter tcno of the %d-th person:\n", j+1);
		scanf("%s", ps2[j].ps_tcno);
		printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
		scanf("%hd", &ps2[j].ps_day);
		printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
		scanf("%hd", &ps2[j].ps_month);

		if( (ps2[j].ps_day > 31) || (ps2[j].ps_month > 12) ){
			printf("Illegal date.\n"); 
			return -1;
		}

		printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
		scanf("%hd", &ps2[j].ps_year);

	}

	for(j=0; j<2; j++)
		printf("%d-th person: %s\t%s\t%d.%d.%d\n", j+1, ps2[j].ps_name, ps2[j].ps_tcno,
			ps2[j].ps_day, ps2[j].ps_month, ps2[j].ps_year);

	// REFERENCING STRUCTURE MEMBERS WITH POINTERS
	ptrps=&ps2[0];
	printf("%d-th person: %s\t%s\t%d.%d.%d\n", j+1, ptrps->ps_name, ptrps->ps_tcno,
			ptrps->ps_day, ptrps->ps_month, ptrps->ps_year);

	// go on using the pointer address and proceed the next person's record:
	for(j=0; j<2; j++)
		printf("%d-th person: %s\t%s\t%d.%d.%d\n", j+1, (ptrps+j)->ps_name, (ptrps+j)->ps_tcno,
			(ptrps+j)->ps_day, (ptrps+j)->ps_month, (ptrps+j)->ps_year);

 	return 0;
}