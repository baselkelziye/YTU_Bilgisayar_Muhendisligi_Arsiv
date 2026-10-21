/*
This code for finding influencers based on their direct and indirect followers in a given graf structure 
M.Ali Bugday
date created:14.12.2022
date modified:20.12.2022
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct record{
	char *fname;
	char *lname;
	int nums[50];
	int total_num;
}RECORD;

int mod;

void calaculate_inorder(int n, int graph[][n], int M, int *deleted, int *indegree); 
int is_there_delete(int *indegree, int *deleted, int n, int M);
void delete_less_followers(int n, int graph[][n], int *indegree, int *deleted, int M);
void dfs(int n, int graph[][n], int visited_by[][n], int *nodes, int *indegree, int *deleted, int *visited, int start);
void dosya_oku(RECORD *record_array,char *filename);
void adjust_graf(int n, RECORD *record_array, int graph[][n]);
void calculate_indirect_indegrees(int n, int *indegree, int *indirects, int* deleted, int visited_by[][n]);

int main() {
	int i, j, n=12;
	int M, X, Y;
	printf("M degerini giriniz:");
	scanf("%d",&M);
	printf("X degerini giriniz:");
	scanf("%d",&X);
	printf("Y degerini giriniz:");
	scanf("%d",&Y);
	printf("1. Normal mod icin: 1\n");
    printf("2. Detaylý mod icin: 2\n");
	scanf("%d",&mod);
	
	int visited_by[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			visited_by[i][j]=0;
		}
	}
	
	int *deleted=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		deleted[i]=0;
	}
	int *indegree=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		indegree[i]=0;
	}
	
	int *nodes=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		nodes[i]=0;
	}
	int *visited=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	int *indirects=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		indirects[i]=0;
	}
	
	
	RECORD record_array[n];
	char *filename="socialNET.txt";
	dosya_oku(record_array, filename);
	
	int graph[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			graph[i][j]=0;
		}
	}
	
	adjust_graf(n, record_array, graph); 
	
	
	delete_less_followers(n, graph, indegree, deleted, M);
	
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			visited[j]=0;
			nodes[j]=0;
		}
		
		dfs(n, graph, visited_by, nodes, indegree, deleted, visited, i);	
	}
	
	calculate_indirect_indegrees(n, indegree, indirects, deleted, visited_by);
	
	/*printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d-",visited_by[i][j]);
		}
		printf("\n");
	}*/
	
	
	
    
	switch (mod)
    {
        case 1:
			for(i=0;i<n;i++)
			{
				if(indegree[i]>=X)
				{
					if(indirects[i]>=Y)
					{
						printf("%s %s\n",record_array[i].fname, record_array[i].lname);
					}
				}	
			}            
            break;
        case 2:
            printf("Verilen M degeri için silinmeyen kisiler ve indegreeleri:\n");
			for(i=0;i<n;i++)
			{
				if(!deleted[i]){
					printf("%s %s: %d\n", record_array[i].fname, record_array[i].lname, indegree[i]);	
				}
			}
			printf("\nVerilen X ve Y degerleri için infulencer olanlarýn bilgileri:\n");
			for(i=0;i<n;i++)
			{
				if(indegree[i]>=X)
				{
					if(indirects[i]>=Y)
					{
						printf("%s %s direct:%d + indirect:%d total%d\n",record_array[i].fname, record_array[i].lname, indegree[i], indirects[i], indegree[i]+indirects[i]);
					}
				}	
			}      
            break;
    }
            
			
	
	free(deleted);
	free(indegree);
	free(nodes);
	free(visited);
	return 0;
}


void calaculate_inorder(int n, int graph[][n], int M, int *deleted, int *indegree)
{
	int i, j;
	
	for(i=0;i<n;i++){
		
		if(!deleted[i])//if not deleted
		{
			for(j=0;j<n;j++){
				if(graph[i][j]==1){
					indegree[j]++;
				}
			}
		}
	}
}

int is_there_delete(int *indegree, int *deleted, int n, int M)
{
	int i, flag=0;
	for(i=0;i<n;i++){
		if(!deleted[i])
		{
			if(indegree[i]<M){
				flag=1;
			}	
		}
	}
	return flag;
}

void delete_less_followers(int n, int graph[][n], int *indegree, int *deleted, int M)
{
	int i;
	
	calaculate_inorder(n, graph, M, deleted, indegree);
	
	if(mod==2)
	{
		printf("\nBaslangic durumunda noktalarin indegree degerleri:\n");
		for(i=0;i<n;i++)
		{
			printf("%d-",indegree[i]);
		}
		printf("\n");
	}
	
	while(is_there_delete(indegree, deleted, n, M))
	{
		
		for(i=0;i<n;i++){
			if(indegree[i]<M){
				deleted[i]=1;
			}
		}
		for(i=0;i<n;i++){
			indegree[i]=0;
		}
		
		calaculate_inorder(n, graph, M, deleted, indegree);
	}
	
	
}


void dfs(int n, int graph[][n], int visited_by[][n], int *nodes, int *indegree, int *deleted, int *visited, int start)
{
	int j, k;
	
	visited[start] = 1;
	
	for(j=0;j<n;j++){
		if(graph[start][j]==1){
			if(visited[j]==0){//ziyaret edilmemisse
				visited[j]=1;
				if(!deleted[j]){//az takicili degil ise
					nodes[start]=1;
					dfs(n, graph, visited_by, nodes, indegree, deleted, visited, j);
					for(k=0;k<n;k++){
						if(visited_by[j][k]==0){
							visited_by[j][k]=nodes[k];	
						}
					}
					nodes[start]=0;
				}
			}
			/*else
			{
				for(k=0;k<n;k++){
						visited_by[j][k]=nodes[k];
				}
			}*/
		}
	}
		
}

//indirect calculate
void calculate_indirect_indegrees(int n, int *indegree, int *indirects, int *deleted, int visited_by[][n])
{
	int i, j, toplam=0;
	
	
	for(i=0;i<n;i++)
	{
		toplam=0;
		for(j=0;j<n;j++)
		{
			if(visited_by[i][j]==1){
				toplam+=1;	
			}
		}
		indirects[i] = toplam;
	}
	
	
	for(i=0;i<n;i++)
	{
		if(!deleted[i])
		{
			indirects[i]-=indegree[i];//dolayli+dogrudan noktalardan dogrudan olanlarý cikartma islemi 	
		}
	}
	
}
 
 
 
void dosya_oku(RECORD *record_array,char *filename)
{
	int j, order, deger;
	FILE *fp=fopen(filename,"r");
	int len;
	char buf[255];
	char buf2[255];
	char *token;
	
	
	while(fgets(buf,255,fp)!=NULL){
		if(buf!=NULL){
			token = strtok(buf, ",");
		    order = atoi(token);
			order--;
			
		    token = strtok(NULL, ",");
		    record_array[order].fname = malloc(strlen(token)+1);
		    strcpy(record_array[order].fname, token);
		
		    token = strtok(NULL, ",");
		    record_array[order].lname = malloc(strlen(token)+1);
		    strcpy(record_array[order].lname, token);
			j = 0;
			if(fgets(buf2,255,fp)!=NULL){
				token=strtok(buf2,",");
				
				
				if(atoi(token)!=0)
				{	
					deger=atoi(token);
					record_array[order].nums[j]=deger;	
					j++;
					//printf("token:%d\n",deger);
				}
				
				while(token!=NULL)
				{	
					if(token!=NULL){
						token=strtok(NULL,",");
						if(atoi(token)!=0)
						{
							deger=atoi(token);
							record_array[order].nums[j]=deger;	
							j++;
							//printf("token:%d\n",deger);
						}
						
						
					}			
				}
				record_array[order].total_num=j;	
			}
		}
	}
	fclose(fp);
}

void adjust_graf(int n,RECORD *record_array, int graph[][n])
{
	int i, j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<record_array[i].total_num;j++){
			graph[i][record_array[i].nums[j]-1] = 1;
		}
	}
}

