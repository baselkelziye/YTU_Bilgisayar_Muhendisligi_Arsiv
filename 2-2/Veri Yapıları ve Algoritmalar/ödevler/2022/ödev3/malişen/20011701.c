#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct files{
	char *dosyaAdi;
	struct files *next;
}FILES;

typedef struct node{
  char *word;
  struct files *dosya;
  struct node *left, *right;
}NODE;


NODE *newNode(char *newWord, FILES *file) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->word = (char* )malloc(sizeof(char)*(strlen(newWord)+1));
  temp->dosya = file;
  //file->next = NULL;
  strcpy(temp->word,newWord);
  temp->left = temp->right = NULL;
  return temp;
}

void preorder(struct node *root) {
  if (root != NULL) {
  	printf("%s -> ", root->word);
  	
    preorder(root->left);

    preorder(root->right);
  }
  
}

NODE *insertWord(NODE *root, char *kelime, char *dosyaAdi ) {
    
  if (root == NULL){
  	FILES *docs= (FILES* )malloc(sizeof(FILES));
   	docs->dosyaAdi = (char*)malloc(sizeof(char)*(strlen(dosyaAdi)+1));
  	strcpy(docs->dosyaAdi,dosyaAdi);
  	docs->next = NULL;
  	return newNode(kelime,docs);
}

  if (strcmp(kelime, root->word) < 0)
    root->left = insertWord(root->left, kelime, dosyaAdi);
  else if(strcmp(kelime, root->word) > 0 )
    root->right = insertWord(root->right, kelime, dosyaAdi);

	else if (strcmp(kelime, root->word) == 0 ){

		FILES *temp = root->dosya;

		
		while(temp->next != NULL && strcmp(temp->dosyaAdi,dosyaAdi)){

			temp = temp->next;
		};
		if(strcmp(temp->dosyaAdi,dosyaAdi) != 0){

			FILES *docs= (FILES* )malloc(sizeof(FILES));
   			docs->dosyaAdi = (char*)malloc(sizeof(char)*(strlen(dosyaAdi)+1));
  			strcpy(docs->dosyaAdi,dosyaAdi);
  			temp->next = docs;
  			docs->next = NULL;
		}
	}
		
	
	
  return root;
}

void searchElement(NODE *root, char* string){
	if(root == NULL){
		printf("OYLE BIR KELIME YOK!!!");
		return ;
	}
	
	if (strcmp(string, root->word) < 0)
    	searchElement(root->left, string );
 	else if(strcmp(string, root->word) > 0 )
     	searchElement(root->right, string);

	else if (strcmp(string, root->word) == 0 ){

		FILES *temp = root->dosya;

		printf("\n \'%s\' kelimesi",root->word);
		while(temp != NULL){
			printf("\n%s\n", temp->dosyaAdi );

			temp = temp->next;
		};
		printf("dosyalarinda gecmektedir.");
		
	}
	
	printf("\n");
}

void addNewFile(char *tmp, NODE *root){
	FILE *fp = fopen(tmp, "r");
	char *docs;
	char *sentence;
	char *word;
	char buffer[400];
	char matris[10][200];
	
	int i = 0, j=0, ctr=0;
	
	do {
		buffer[i] = fgetc(fp);
	} while (buffer[i++] != EOF);
	buffer[i - 1] = 0;

	for(i=0;i<=(strlen(buffer));i++){
		if(buffer[i] == '\n' || buffer[i] == EOF){
			matris[ctr][j] = '\n';
			ctr++;
			j=0;
		}else{
			matris[ctr][j] = buffer[i];
			j++;
		}
	}
 
	for(i=0; i<=ctr; i++){
		docs = strtok(matris[i], ":");
		sentence = strtok(NULL, "\n") + 1;
		word = strtok(sentence," ");
		while(word != NULL){
			root = insertWord(root,word,docs);

			word = strtok(NULL," ");
		}
	}
}

void deleteFile(char *tmp, NODE *root){
	
}



int main(){
	FILE *f = fopen("test.txt", "r");
	char *docs;
	char *sentence;
	char *word;
	char buffer[400];
	char matris[10][200];
	NODE *kok = NULL;
	
	char tmp[20];
	int i = 0, j=0, ctr=0, choice;
	do {
		buffer[i] = fgetc(f);
	} while (buffer[i++] != EOF);
	buffer[i - 1] = 0;
	for(i=0;i<=(strlen(buffer));i++){
		if(buffer[i] == '\n' || buffer[i] == EOF){
			matris[ctr][j] = '\n';
			ctr++;
			j=0;
		}else{
			matris[ctr][j] = buffer[i];
			j++;
		}
	}
 
	for(i=0; i<=ctr; i++){
		docs = strtok(matris[i], ":");
		sentence = strtok(NULL, "\n") + 1;
		word = strtok(sentence," ");
		while(word != NULL){
			kok = insertWord(kok,word,docs);
			word = strtok(NULL," ");
		}

	}
	do{
        printf("Kelime Aramak icin 1 \n Dosya Eklemek icin 2 \n Dosya Silmek icin 3 \n Preorder Yazdirmak icin 4\n Cikis icin 0\n:");
        scanf("%d",&choice);
        switch (choice){
            case 2:
                printf("eklenecek dosyayi (.txt  ile) giriniz");
                printf("\n");
                scanf("%s",&tmp);
                addNewFile(tmp,kok);
                
                break;
            case 3:
            	printf("SILME ISLEMI YAPILAMIYOR\n");
                //printf("silinecek dosya giriniz");
                //scanf("%d",&tmp);
                //deleteFile(tmp,kok);
                break;  
            case 1:
                printf("aranacak kelime giriniz\n");
                scanf("%s",&tmp);
                //arama finksiyonu ekle
                searchElement(kok,tmp);
                break;
            case 4:
                preorder(kok);
                printf("\n\n");
                
                break;
            case 0:
                printf("Cikis yapildi\n");
                break;
            default:
                printf("Duzgun deger gir\n");
        }

    }while(choice);

	fclose(f);
		
}
