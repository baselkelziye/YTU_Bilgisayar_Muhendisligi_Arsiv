#include <stdio.h>
#define N 50

int letterControl(char letterCode[N], int i)
{
	int j = 0, flag = 0;
	
	while(i > 0 && j != i && flag == 0){
		
		if(letterCode[i] == letterCode[j]){
			flag = 1;
		}
		
		j++;
	}
	
	return flag;
}

int timeControl(int time[N], int i)
{
	int flag = 0;
	
	if(time[i+1] <= time[i]){
		flag = 1;
	}
	
	return flag;
}

void ganttDraw(char letterCode[N], int time[N], int work)
{
	int i, j, k = 0;
	char gannt[N];
	
	for(i=0; i<work; i++){
		
		for(j=1; j<time[k+1]+1; j++){
			
			if(j < time[k]){
				gannt[j] = '_';
			}
			else{
				gannt[j] = letterCode[i];
			}
		}
		
		printf("'%c' islemi: ", letterCode[i]);
		
		for(j=1; j<time[k+1]+1; j++){
			printf("%c", gannt[j]);
		}
		
		printf("\n");
		
		k += 2;
	}
}

int main()
{
	int i, j = 0, work, flag, time[N];
	char letterCode[N];
	
	printf("Toplam is sayisini giriniz: ");
	scanf("%d", &work);
	
	printf("\nYapilacak islerin harf kodlarini giriniz...\n");
	
	for(i=0; i<work; i++){
		
		do{
			
			printf("%d. isin harf kodu: ", i + 1);
			scanf("%s", &letterCode[i]);
		
			flag = letterControl(letterCode, i);
			
		}while(flag == 1);
	}
	
	printf("\nSirasiyla her bir islemin baslangic ve bitis zamanlarini giriniz...\n");
	
	for(i=0; i<work*2; i=i+2){
		
		do{
			
			printf("'%c' islemi icin baslangic zamani: ", letterCode[j]);
			scanf("%d", &time[i]);
			
		}while(time[i] <= 0);
		
		do{
			
			printf("'%c' islemi icin bitis zamani: ", letterCode[j]);
			scanf("%d", &time[i+1]);
		
			flag = timeControl(time, i);
			
		}while(flag == 1 || time[i+1] <= 0);
		
		j++;
	}
	
	printf("\nGantt Cizelgesi asagidaki gibi olusturuldu...\n\n");
	
	ganttDraw(letterCode, time, work);
	
	getch();
	
	return 0;
}

