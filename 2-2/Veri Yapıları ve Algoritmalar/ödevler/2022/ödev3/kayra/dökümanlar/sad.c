#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct Node{
    char kelime[MAX];
    char dosyalar[MAX][MAX];
    int dosyaSayisi;
    struct Node * left;
    struct Node * right;
}node;
int menu(){
	printf("Ne yapmak istersin?\nDosya eklemek icin 1\nDosya silmek icin 2\nArama icin 3\nCikis icin 4\n");
	int i;
	scanf("%d",&i);
	return i;
}
node * nodeOlustur(char * buf){
    node * myNode;
    myNode=(node *)malloc(sizeof(node));
    myNode->left=NULL;
    myNode->right=NULL;
    myNode->dosyaSayisi=0;
    strcpy(myNode->kelime,buf);
    return myNode;
}

int dosyaAdiSil(node * head, char * dosyaAdi){
	int i=0,j;
	while(i<head->dosyaSayisi && strcmp(head->dosyalar[i],dosyaAdi)){
		i++;
	}
	if(i!=head->dosyaSayisi && head->dosyaSayisi==1){
		head->dosyaSayisi--;
		return 1;
	}
	else if(i!=head->dosyaSayisi){
		for(j=i;j<head->dosyaSayisi-1;j++){
			strcpy(head->dosyalar[j],head->dosyalar[j+1]);
		}
		head->dosyaSayisi--;
	}
	return 0;
}
node * goLeft(node * head){
	head=head->right;
	if(head!=NULL)
		while(head->left!=NULL){
			head=head->left;
	}
	return head;
}
node * goLeftParent(node * parent){
	if(parent->right->left!=NULL){
		parent=parent->right;
		while(parent->left->left!=NULL){
			parent=parent->left;
		}
	}
	return parent;
}
void swap(node * p1, node * p2){
	node * tmp;
	tmp=(node*)malloc(sizeof(node));
	tmp->left=p1->left;
	tmp->right=p1->right;
	p1->right=p2->right;
	p1->left=p2->left;
	p2->left=tmp->left;
	p2->right=tmp->right;
	free(tmp);
}
void elemanSil(node * parent,node *child){
	node * tmp;
	node * tmpParent;
	if(parent->left==child){
		if(child->left==NULL && child->right == NULL){
			parent->left=NULL;
			free(child);

	}	
		else if(child->left!=NULL && child->right!=NULL){
			tmp=goLeft(child);
			tmpParent=goLeftParent(child);
			swap(tmp,child);
			parent->left=tmp;
			if(tmpParent!=child){
				tmpParent->left=child;
				elemanSil(tmpParent,child);
			}
				
			else{
				tmp->right=child;
				elemanSil(tmp,child);
			}
				
		
		}
		else{
			if(child->left==NULL){
				parent->left=child->right;
				free(child);
			}
			else{
				parent->left=child->left;
				free(child);
			}
		}
	}
	else{
		if(child->left==NULL && child->right == NULL){
			parent->right=NULL;
			free(child);
	}	
		else if(child->left!=NULL && child->right!=NULL){
			tmp=goLeft(child);
			tmpParent=goLeftParent(child);
			swap(tmp,child);
			parent->right=tmp;
			if(tmpParent!=child){
				tmpParent->left=child;
				elemanSil(tmpParent,child);
			}
			else{
				tmp->right=child;
				elemanSil(tmp,child);
			}
				
		}
		else{
			if(child->left==NULL){
				parent->right=child->right;
				free(child);
			}
			else{
				parent->right=child->left;
				free(child);
			}
		}
	}
	}
void dosyaSil(node* parent,node * child,char * dosyaAdi,int rol,int * count){
	while(child != NULL && dosyaAdiSil(child,dosyaAdi)){
		(*count)=1;
		elemanSil(parent,child);
		if(rol){
			child=parent->right;
		}
		else
			child=parent->left;	
	}
	if(child!=NULL){
		
	if(child->left!=NULL){
		dosyaSil(child,child->left,dosyaAdi,0,count);
	}
	if(child->right!=NULL){
		dosyaSil(child,child->right,dosyaAdi,1,count);
	}}
	}
node * dosyaEkle(node * head){ 
    FILE * fp;
    char dosyaAdi[MAX];
    int i;
    node * tmp,*preTmp;
    printf("Lutfen dosya adini gir\n");
    scanf( "%s",dosyaAdi);

    if((fp=fopen(dosyaAdi,"r"))!=NULL){
        char buf[MAX];
        while(fscanf(fp,"%s ",buf)==1){
            tmp=head;
            while(tmp!=NULL && strcmp(tmp->kelime,buf)){
                preTmp=tmp;
              if(strcmp(tmp->kelime,buf)>0){
                tmp=tmp->left;
            }
            else 
                tmp=tmp->right; 
            }
            if(tmp==NULL){
                tmp=nodeOlustur(buf);
            
     
            strcpy(tmp->dosyalar[tmp->dosyaSayisi],dosyaAdi);
            tmp->dosyaSayisi++;
            if(head!=NULL){

              if(strcmp(preTmp->kelime,buf)>0){
               preTmp->left=tmp;
            }
            else
                preTmp->right=tmp;
            }  
            else
             head=tmp;
            }
            
            else{
            	i=0;
            	while(i < tmp->dosyaSayisi && strcmp(tmp->dosyalar[i],dosyaAdi)){
            		i++;
				}
				if(i==tmp->dosyaSayisi){
                	strcpy(tmp->dosyalar[tmp->dosyaSayisi],dosyaAdi);
                	tmp->dosyaSayisi++;}
            }
                
            
        }
        fclose(fp);
        return head;

    }
    else{

       printf("----------------------------\nDosya bulunamadi!!!\n-------------------------------\n"); 
       return head;
    }
        


}

void search(node * head, char * kelime){
	int i;
	while(head != NULL && strcmp(head->kelime,kelime)){
		if(strcmp(head->kelime,kelime)>0){
			head=head->left;
		}
		else{
			head=head->right;
		}
	}
	if(head!=NULL){
		printf("Kelime <----- > %s <------>\n>--<Kelimenin gectigi dosyalar >--<\n",kelime);
		for(i=0;i<head->dosyaSayisi;i++){
			printf("Dosya adi :  ---> %s\n",head->dosyalar[i]);
		}
	}
	else
		printf("--------------------------\nBoyle bir kelime yok\n--------------------------------\n");
}
void freele(node * parent){
	if(parent->right!=NULL)
		freele(parent->right);
	if(parent->left!=NULL)
		freele(parent->left);
	free(parent);
}
int main(){
	int choice,count;
	char dosyaAdi[MAX];
    node *head,*tmp;
    head=(node*)malloc(sizeof(node));
    head->left=NULL;
    head->right=NULL;
    do{
    	choice =menu();
    	switch(choice){
    		case 1:
    			head->right = dosyaEkle(head->right);
				break;
			case 2:
					printf("Dosya ismini giriniz\n");
					scanf("%s",dosyaAdi);
					count=0;
					dosyaSil(head,head->right,dosyaAdi,1,&count);
					if(count){
						printf("--------------------\nBasaryla silindi!!!\n---------------------\n");
					}
					else
						printf("--------------------\nDosya bulunamadi!!!\n-----------------------\n");
					break;
			case 3:
				if(head->right!=NULL){
				printf("Aranacak kelimeyi giriniz\n");
				scanf("%s",dosyaAdi);
				search(head->right,dosyaAdi);}
				else
					printf("Su an herhangi bir kelime yok\n");
				break;
			case 4:
				printf("Cikis yapiliyor !!!\n");
				break;
			default:
				printf("Duzgun sayi giriniz\n");
		}

    	
	}while(choice!=4);
	freele(head);
    
    return 0;
}