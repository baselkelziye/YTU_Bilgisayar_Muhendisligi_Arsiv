/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta5_codes
cc -o test hafta5_2_typedef.c 
*/
#include <stdio.h>

typedef struct {   char ps_name[20], ps_tcno[11];   short ps_day, ps_month, ps_year;} PERSONALSTAT;int main(){
	int j;
	
	// initialize:
	PERSONALSTAT ps={"George Smith", "0023406710", 3, 5, 1946 };

	PERSONALSTAT ps2[2]={ {"John Smith", "12345054321", 4, 12, 1960 },
			   {"Jane Smith", "23456065432", 5, 10, 1966 }};

	printf("First person: %s\t%s\t%d.%d.%d\n", ps.ps_name, ps.ps_tcno,
		ps.ps_day, ps.ps_month, ps.ps_year);
	for(j=0; j<2; j++)
		printf("%d-th person: %s\t%s\t%d.%d.%d\n", j+1, ps2[j].ps_name, ps2[j].ps_tcno,
			ps2[j].ps_day, ps2[j].ps_month, ps2[j].ps_year);

 	return 0;
}