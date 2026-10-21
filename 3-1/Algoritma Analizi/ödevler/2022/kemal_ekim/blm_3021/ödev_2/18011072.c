// Mustafa Kemal Ekim - 18011072
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Job
{
    int start, finish, profit;
}Job;
 
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int jobCompare(const void* s1, const void* s2)
{
	Job *j1 = (Job *)s1;
	Job *j2 = (Job *)s2;
    return (j1->finish - j2->finish);
}
 
// Sirali dizide cakismayan son reklam bulunur
int lastNoConflict(Job arr[], int i)
{
	int j;
    for (j=i-1; 0<=j; j--)
    {
        if (arr[i].start >= arr[j].finish)
            return j;
    }
    return -1;
}
 

int findMaxProfit(Job arr[], int n)
{
    // Bitis sirasina gore siralama
    qsort(arr, n, sizeof(Job), jobCompare);

    // arr[i]'ye kadar olan cozumleri saklayan dizi
    int table[n];
    table[0] = arr[0].profit;
 
    int i;
    for (i=1; i<n; i++)
    {
        // Mevcut reklami iceren kâr
        int inclProf = arr[i].profit;
        int l = lastNoConflict(arr, i);
        if (l != -1){
        	inclProf += table[l];
        	printf("\ninclProf: %d",inclProf);
		}
        // including ve excluding'in maximumunu depolama
        table[i] = max(inclProf, table[i-1]);
    }
    
    for(i=0;i<n;i++){
    	printf("\nTable[%d]: %d",i,table[i]);
	}
 
    // sonucu saklama
    int sonuc = table[n-1];
 
    return sonuc;
}
 

int main()
{
    FILE * fp; 
	fp = fopen("Sample.txt", "r");
	
	int ch;
	int count=0; // satir sayisi saymak icin
	ch = fgetc(fp); // fgetc -> siradaki karakteri okur
	while(ch != EOF){ // karakterler bitene kadar loop
		if(ch == '\n'){
			count ++;
		}
		ch = fgetc(fp);
	}
	
	rewind(fp); // basa donmek icin
	
	count += 1;
	printf("Satir sayisi: %d",count);
	
	Job arr[count];
	
	int i;
	printf("\nStart | Duration | Value");
	for(i=0;i<count;i++){
		fscanf(fp, "%d %d %d\n", &arr[i].start, &arr[i].finish, &arr[i].profit); // dosyadan scan ve store islemi
		printf("\n%d\t%d\t%d",arr[i].start,arr[i].finish,arr[i].profit);
		arr[i].finish = arr[i].finish + arr[i].start; // duration = finish_time olarak guncellendi
	}
	
	printf("\n*************************");
    printf("\nThe maximum profit is %d", findMaxProfit(arr, count));
    printf("\n*************************");
    
    printf("\nStart | Finish | Value");
	for(i=0;i<count;i++){
		printf("\n%d\t%d\t%d",arr[i].start,arr[i].finish,arr[i].profit);
	}
    
    return 0;
}
