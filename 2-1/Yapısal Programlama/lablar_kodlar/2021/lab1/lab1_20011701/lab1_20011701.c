#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "header.h"

int main(){
	srand(time(NULL));
	int i,m,mari;
	int ari[POPULATION];
	printf("initial Population\n");
    	for(m = 0 ; m < POPULATION ; m++)
   		 {
       		mari = rand() % 24 + 1;
       		printf("%d\t",mari);
   		 }
   	printf("\n\n\n");
	
	for( i = 0; i< ITERATION; i++){
		int j;
		int cost[POPULATION];
		printf("iteration - %d new population\n",i+1);
    	for(j = 0 ; j < POPULATION ; j++)
   		 {
       		ari[j] = rand() % 24 + 1;
       		printf("%d\t",ari[j]);
       		cost[j] = COST(ari[j]);
       		//printf(cost[j])
       		int c, location =0;
       		for (c = 1; c < POPULATION; c++){
       			if (cost[c] < cost[location])
      			location = c;
			   }
   			
   		 }
   		 //printf("ari 2",ari[2]);
   		//printf("best cost %d : %d value",i+1,cost[location]); 
   }
    return 0;
}
