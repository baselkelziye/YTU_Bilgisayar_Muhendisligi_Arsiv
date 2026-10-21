//Ali Bugday
//date created 18.11.22
//date modified 20.11.22
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct hash{
	char *key;
	char *value;
	int counter; 
}HASH;


int calculate_horner(char *str);
void insert_hash(HASH *table, int m, char *key, char *value);
void dosya_oku(char *filename, char *delimater, HASH *hashtable, int m);
char* find(HASH *table, int m, char *str);
int find_length_of_hashtable(char *filename, float load_factor);
int is_prime(int m);
void tokenize_and_insert(char *buf,char *buf2, HASH *hashtable, int m);

int main() {
	
	int i, m;
	float load_factor=2;//default deger eleman sayýsýnýn iki katý
	
	printf("enter load factor value:");
	scanf("%f",&load_factor);
	m=find_length_of_hashtable("sample.txt",load_factor);
	printf("%d",m);
	HASH *hashtable = (HASH*)malloc(m*sizeof(HASH));
	for(i=0;i<m;i++)
	{
		hashtable[i].key="";
		hashtable[i].value="";
		hashtable[i].counter=0;	
	}
	
	
	//dosya_oku("sample.txt", " ", hashtable, m);
	
	insert_hash(hashtable, m, "University", "https://ce.yildiz.edu.tr");
	insert_hash(hashtable, m, "Computers ", "https://ce.yildiz.edu.tr");
	insert_hash(hashtable, m, "IT", "https://ce.yildiz.edu.tr");
	insert_hash(hashtable, m, "AI", "https://ce.yildiz.edu.tr");
	insert_hash(hashtable, m, "R&D", "https://ce.yildiz.edu.tr");
	insert_hash(hashtable, m, "Education", "https://ce.yildiz.edu.tr");
	
	insert_hash(hashtable, m, "News", "https://edition.cnn.com");
	
	
	insert_hash(hashtable, m, "Entertainment", "https://www.instagram.com");
	insert_hash(hashtable, m, "SocialNetwork", "https://www.instagram.com");
	
	
	insert_hash(hashtable, m, "AI", "https://www.kaggle.com");
	insert_hash(hashtable, m, "Competition", "https://www.kaggle.com");
	insert_hash(hashtable, m, "Dataset", "https://www.kaggle.com");
	insert_hash(hashtable, m, "Cloud", "https://www.kaggle.com");
	
	
	int mode;
	printf("select mode1 or 2:");
	scanf("%d",&mode);
	if(mode==1){
	
		char key[50]; 
		char key2[50];
		char *baglac;
		//normal mode
		int tek_cift;
		do
		{
			printf("\ntek sorgu icin 1 cift(baglacli) sorgu icin 2 tuslayin");
			scanf("%d",&tek_cift);	
		}while(tek_cift<1 || tek_cift>2);
		
		if(tek_cift==1){
			printf("aranacak olan kelimeyi giriniz:");
			scanf("%s",key);
			find(hashtable, m, key);	
		} 
		else{
			printf("aranacak olan birinci kelimeyi giriniz:");
			scanf("%s",key);
			printf("and icin 1 or icin 2 giriniz:");
			int secim;
			scanf("%d",&secim);
			if(secim==1){
				printf("aranacak olan ikinci kelimeyi giriniz:");
				scanf("%s",key2);
				if(strcmp(find(hashtable, m, key),find(hashtable, m, key2))==0){
					printf("%s",find(hashtable, m, key));
				}
			}
			else{
				printf("aranacak olan ikinci kelimeyi giriniz:");
				scanf("%s",key2);
				printf("%s\n",find(hashtable, m, key));
				printf("%s",find(hashtable, m, key2));
			}
		}
	}
	else{
		for(i=0;i<m;i++){
			printf("%d:%s:%d\n",i,hashtable[i].value, hashtable[i].counter);
			
		}
	}
	
	
	
	return 0;
}

int calculate_horner(char* str)
{
	int i, key=0;
	int length=strlen(str);
	
	for(i=0;i<length;i++){
		key+=(31^i)*(str[i]);
	}
	
	return key;
}

void insert_hash(HASH *table, int m, char *str, char* deger)
{
	int key = calculate_horner(str);
	int i=0;
	int adr = key%m;
	
	while((i<m) && (strcmp(table[adr].value,"")!=0) && (strcmp(table[adr].value,deger)!=0))
	{
		i++;
		adr=(adr+1)%m;
		table[adr].counter++;
	}
	
	
	if(i==m)
	{
		printf("insert edilmedi tablo dolu");
	}
	else
	{
		
		if(strcmp(table[adr].value,"")==0){
			table[adr].value=deger;
			table[adr].key=str;
			
			//printf("table degeri:%s insert edildi\n",table[adr]);
		}
		else
		{
			printf("%s degeri daha önce eklenmis\n",str);
		}
	}
}


void dosya_oku(char *filename, char *delimater, HASH *hashtable, int m)
{
	FILE *fp=fopen(filename,"r");
	int len;
	char buf[255];
	char buf2[255];
	char *token;
	
	
	while(fgets(buf,255,fp)!=NULL){
		
		if(buf!=NULL){
			if(fgets(buf2,255,fp)!=NULL){
				token=strtok(buf2," ");
				if(token!=NULL){
					printf("buf:%s\n",buf);
					insert_hash(hashtable, m, token, buf);
				}
				while(token!=NULL)
				{	
					token=strtok(NULL," ");
					if(token!=NULL){
						printf("token:%s\n",token);
						insert_hash(hashtable, m, token, buf);
					}			
				}		
			}
		}
	}
	fclose(fp);
}

void tokenize_and_insert(char *buf,char *buf2, HASH *hashtable, int m)
{
	char *token=strtok(buf2," ");
	insert_hash(hashtable, m, token,"deger");
	while(token!=NULL)
	{	
		token=strtok(NULL," ");
		if(token!=NULL){
			insert_hash(hashtable, m, token, "deger");
		}			
	}	
}

char* find(HASH *table, int m, char *str)
{
	int key = calculate_horner(str);
	int i=0;
	int adr = key%m;

	while((i<m) && (table[adr].value!="") && (strcmp(table[adr].key,str)!=0))
	{
		i++;
		adr=(adr+1)%m;
	}
	
	
	if(strcmp(table[adr].key,str)==0)
	{
		return table[adr].value;
	}
	else
	{
		printf("\nsearched string does not available in hash table");
	}
} 


int find_length_of_hashtable(char *filename, float load_factor)
{
	FILE *fp=fopen(filename,"r");
	int len, counter=0;
	char buf[255];
	char buf2[255];
	char *token;
	
	while(fgets(buf,255,fp)!=NULL){
		if(buf!=NULL){
			if(fgets(buf2,255,fp)!=NULL){
				token=strtok(buf2," ");
				counter++;
				while(token!=NULL)
				{	
					token=strtok(NULL," ");
					if(token!=NULL){
						counter++;
					}			
				}		
			}
		}
	}
	fclose(fp);
	
	int length = counter*load_factor;
	while(is_prime(length))
	{
		length+=1;
	}
	
	return length;
}

int is_prime(int m)
{
	int i, flag=0;
	
	for(i=2;i<m;i++)
	{
		if(m%i==0)
		{
			flag = 1;	
		}
	}
	
	return flag;
}
