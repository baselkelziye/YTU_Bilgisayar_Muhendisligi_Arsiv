//M.Ali Bugday
//Date created: 16.04.2022
//Date Modified: 26.04.2022   


#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char *data;
	struct node* left;
	struct node* right;
	char dizi[10][20];
	int top;
}NODE; 



/* run this program using the console pauser or add your own getch, system("pause") or input loop */

NODE* newNode(char* deger);
NODE* insert(NODE* head, char* deger);
NODE* search(NODE* head, char* value);
void preorder(NODE* head);
NODE* enKucukNode(NODE *head);
NODE *deleteNode(NODE* head, char *deger);
NODE *olustur(NODE*, char*);
NODE *olustur2(NODE*, char*);
NODE* silme_islemi(NODE* head, char* filename);
void arama_islemi(NODE* head, char *aranan);

int main() {
    int option;
    struct node* root = NULL;
    char *kelime = (char*)malloc(20*sizeof(char));
    
    printf("NOT: Bin seceneginde olan dosyalari olustur fonkisyonu, test.txtden a-b-c-d.txtleri olusturmak icin bir kez cagrilabilir\n");
    printf("daha sonra olusan a-b-c-d.txtleri 1. secenek ile tek tek treeye eklenebilir\n\n");
    
    do{
		printf("\n ******** MAIN MENU *********");
		printf("\n 1. Ekleme islemi");
		printf("\n 2. Arama islemi");
		printf("\n 3. Cikarma islemi");
		printf("\n 4. Display");
		printf("\n 5. Cikis");
		printf("\n 1000. dosya olutur(sadece bir kez calistirilir)");
		printf("\n Secenek giriniz: ");
		scanf("%d", &option);		
		
		switch (option)
		{
	    	case 1:
	      		printf("kelimeleri eklenecek olan dosyayi dosya_ismi.txt formatinda giriniz:");
				scanf("%s",kelime);
				
				root = olustur2(root, kelime);
				break;
	    	case 2:
	    		printf("Aranacak olan kelimeyi giriniz:");
	    		scanf("%s",kelime);
	      		arama_islemi(root, kelime);
	      		break;
			
			case 3:
				printf("kelimeleri silinecek olan dosyayi dosya_ismi.txt formatinda giriniz:");
				scanf("%s",kelime);
	      		root = silme_islemi(root, kelime);
	      		break;
	      		
	      	case 4:
	      		preorder(root);
	      		break;
	      		
	      	case 1000:
	      		printf("Genel test.txt dosyasini dosya_ismi.txt formatinda giriniz:");
	    		scanf("%s",kelime);
	      		olustur(root, kelime);
	      		break;
		}
	}while(option!=5);

	return 0;
}//end of main fonction

//--------------------------------------------------------------------------------------------------------

NODE* newNode(char *deger)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->top = 0;
    temp->data = deger;
    temp->left = temp->right = NULL;
    return temp;
}

NODE* insert(NODE *tmp, char *deger){
	
	if(tmp == NULL){
		tmp = newNode(deger);
	}

	if(kucuk(deger, tmp->data)){
		tmp->left = insert(tmp->left, deger);
	}
	
	if(buyuk(deger, tmp->data)){
		tmp->right = insert(tmp->right, deger);
	}
	
	return tmp;
}



NODE* search(NODE* head, char *value){
	
	if(head == NULL){
		//printf("tree bos deger ekleyiniz");
		return NULL;
	}
	
	if(esit(head->data, value)){
		return head;
	}
	
	
	if(buyuk(head->data, value)){
		return search(head->left, value);
	}
	
	if(kucuk(head->data, value)){
		return search(head->right, value);
	}
}

void preorder(NODE* head){
	int i;
	if(head!=NULL){
		printf("%s",head->data);
		while(i<head->top){
			printf("-%s",head->dizi[i]);
			i++;
		}
		printf("\n");
		preorder(head->left);
		preorder(head->right);
	}
}

//--------------------------------------------------------------------------------------------------------

int kucuk(char* str1, char* str2){
	if(strcmp(str1, str2) < 0){
		return 1;
	}else{
		return 0;
	}
}

int buyuk(char* str1, char* str2){
	if(strcmp(str1, str2) > 0){
		return 1;
	}else{
		return 0;
	}
}

int esit(char* str1, char* str2){
	if(strcmp(str1, str2) == 0){
		return 1;
	}else{
		return 0;
	}
}

//--------------------------------------------------------------------------------------------------------

NODE* enKucukNode(NODE *head){
  struct node *current = head;

  //en soldakini bulma islemi
  while (current && current->left != NULL)
    current = current->left;

  return current;
}


NODE *deleteNode(NODE* head, char *deger){
    if (head == NULL){
        return head;	
    }
  
    if(kucuk(deger, head->data)){
  		head->left = deleteNode(head->left, deger);
	}
  	else if (buyuk(deger, head->data)){
  		head->right = deleteNode(head->right, deger);
	}

  	else{
		// sadece bir child varsa 
		if (head->left == NULL) {
		  struct node *temp = head->right;
		  free(head);
		  return temp;
		} else if (head->right == NULL) {
		  struct node *temp = head->left;
		  free(head);
		  return temp;
		}
		
		// eger iki child var ise
		struct node *temp = enKucukNode(head->right);
		
		// yer degistime
		head->data = temp->data;
		
		head->right = deleteNode(head->right, temp->data);
	}
    return head;
}

//--------------------------------------------------------------------------------------------------------

NODE* olustur(NODE* root, char* filename){
	int ch;
	char *kelime, *token, *dosya;
	kelime = (char*)malloc(128*sizeof(char));
	
	FILE *oku; 
	oku = fopen(filename, "r");
	
	while(fgets(kelime, 128, oku) != NULL){ 
		
		token = strtok(kelime, ":");
		
		dosya = token; 
		
		FILE *yaz = fopen(token, "w");
		
		//token = strtok(NULL, " ");
		
		token = strtok(NULL, "\n");
		
		fprintf(yaz, "%s", token);
		
		fclose(yaz);
	
		//root = olustur2(root, dosya);
	}
	
	fclose(oku);
	
	return root;
	
}//end of olustur fonction.

//--------------------------------------------------------------------------------------------------------

NODE* olustur2(NODE* head, char* filename){
	int i;
	NODE* temp;
	char *kelime, *token;
	kelime = (char*)malloc(255*sizeof(char));
	
	FILE *oku; 
	oku = fopen(filename, "r");
	
	fgets(kelime, 255, oku);
	
	fclose(oku);
	
	token = strtok(kelime, " ");
	
	if(token!=NULL){
		if(search(head, token) != NULL){
			temp = search(head, token);
			for(i=0;i<temp->top;i++){
				if(esit(temp->dizi[i], filename)){
					return head;
				}
			}
			strcpy(temp->dizi[temp->top], filename);
			temp->top++;
		}else{
			head = insert(head, token);
			temp = search(head, token);
			strcpy(temp->dizi[temp->top], filename);
			temp->top++;
		}
	}
	
	while(token != NULL){
		token = strtok(NULL, " ");
		if(token!=NULL){
			if(search(head, token) != NULL){
				temp = search(head, token);
				for(i=0;i<temp->top;i++){
					if(esit(temp->dizi[i], filename)){
						return head;
					}
				}
				strcpy(temp->dizi[temp->top], filename);
				temp->top++;
			}else{
				head = insert(head, token);
				temp = search(head, token);
				strcpy(temp->dizi[temp->top], filename);
				temp->top++;
			}
		}
	}

	return head;
}//end of olustur2 function


//--------------------------------------------------------------------------------------------------------
 
 
NODE* silme_islemi(NODE* head, char* filename){
	char *cumle =(char*)malloc(128*sizeof(char));
	char *token;
	int i;
	
	NODE* temp = head;;
	FILE *oku = fopen(filename, "r");
	
	fgets(cumle, 127, oku);
	
	fclose(oku);
	
	token = strtok(cumle, " ");
	
	temp = search(head, token);
	
	if(temp == NULL){
		//pass
	}
	else{
		if(temp->top <= 1){
			temp = deleteNode(head, token);
		}
		else{
			for(i=0;i<temp->top;i++){
				if(esit(temp->dizi[i], filename)){
					strcpy(temp->dizi[i], " ");//degistir
				}
			}
		}
		
		
		while(token != NULL){
			token = strtok(NULL, " ");
			
			if(token != NULL){
				
				temp = search(head, token);
				
				if(temp == NULL){
					//pass
				}else{
					if(temp->top <= 1){
						temp = deleteNode(head, token);
					}
					else{
						for(i=0;i<temp->top;i++){
							if(esit(temp->dizi[i], filename)){
								strcpy(temp->dizi[i], " ");//degistir
							}
						}
					}	
				}
			}
		}
	}
	
	if(temp){
		return temp;			
	}else{
		return head;
	}
	
}//end of silme_islemi fonksiyonu 

//--------------------------------------------------------------------------------------------------------

void arama_islemi(NODE* head, char *aranan){
	NODE* temp;
	
	if(aranan == NULL){
		printf("aranan kelime NULL degerde");
	}
	
	temp = search(head, aranan);
	
	if(temp == NULL){
		printf("aranan kelime treede bulunmuyor\n");
	}
	else{
		if(temp->top > 0){
			printf("%s kelimesinin gectigi dosyalar:",aranan);	
		}
		else{
			printf("%s kelimesinin gectigi dosyalar yazdirilmadi\n",aranan);
		}
		
		int i;
		for(i=0;i<temp->top;i++){
			if(temp->data != " "){
				printf(" %s",temp->dizi[i]);
			}
		}
		printf("\n");	
	}
}//end of arama_islemi fonksiyonu 

