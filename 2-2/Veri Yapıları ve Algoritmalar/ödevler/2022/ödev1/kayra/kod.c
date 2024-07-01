#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Link{
	int deger;
	struct Link * next;
	struct Link * down; 
}link;
link * ilk_ekleme(link * head,int n,int * seviye,int * dizi);
int eleman_say(link * curr){
	int i=0;
	while(curr->next!=NULL){
		curr=curr->next;
		i++;
	}
	return i;
}
int menu(){
	int n;
	printf("============================\nEleman eklemek icin 1\nEleman silmek icin 2\nYazdirmak icin 3\nAramak icin 4\nCikis icin 0\n===========================\n");
	scanf("%d",&n);
	return n;
}
void yazdir(link * head,int seviye){
	link * curr,*prev;
	int i;
	curr=head->down;
	prev=head;
	while(curr!=NULL){

	while(curr->next!=NULL){
		for(i=0;i<seviye;i++){
			printf(" ");
		}
		printf("%d",curr->next->deger);
		curr=curr->next;
	}
	if(seviye!=1)
		seviye=(seviye+1)/2;
	else
		seviye=0;
	printf("\n");
	curr=prev->down->down;
	prev=prev->down;
	}
}
link * sil(link * head, int * eleman_sayisi,int * seviye, int sayiSil){
	link * tmp,*head_tmp,*prev;
	int counter=0,*seviye_dizi,i,degisken,deneme=0,*dizi;
	head_tmp=head;
	i=(*seviye);
	while(i){
		head_tmp=head_tmp->down;
		prev=head_tmp;
		tmp=prev->next;
		while(tmp!=NULL && tmp->deger<sayiSil){
			prev=tmp;
			tmp=tmp->next;
	}
		if(tmp!=NULL && tmp->deger==sayiSil){
			prev->next=tmp->next;
			head_tmp=prev;
			free(tmp);
			counter++;
		}
		i--;
	}
	if(counter>0){
	printf("%d elemani listeden silindi ve bulundugu en yuksek seviye %d\n",sayiSil,counter);
	(*eleman_sayisi)--;	
	if(head->down->next==NULL){
		tmp=head;
		head=head->down;
		free(tmp);
		(*seviye)--;
	}
	else{
		if(head->down->down->next->next==NULL){
			tmp=head;
			head=head->down;
			free(tmp);
			tmp=head->next;
			free(tmp);
			head->next=NULL;
			(*seviye)--;
			
		}
		

	}
	seviye_dizi=(int *)malloc(((*seviye))*sizeof(int));
	tmp=head->down;
	i=0;
	while(tmp!=NULL){
		seviye_dizi[i]=eleman_say(tmp);
		tmp=tmp->down;
		i++;
	}
	for(i=(*seviye)-1;i>=0;i--){
		degisken=(seviye_dizi[i]+1)/2;
		if(degisken!=seviye_dizi[i-1]){
			deneme=3;
		}
	}
	if(deneme==3){
		dizi=(int * )malloc((*eleman_sayisi)*sizeof(int));
		tmp=head;
		while(tmp->down!=NULL){
			tmp=tmp->down;
		}
		i=0;
		while(tmp->next!=NULL){
			dizi[i]=tmp->next->deger;
			tmp=tmp->next;
			i++;
		}
		head=NULL;
		head=ilk_ekleme(head,(*eleman_sayisi),seviye,dizi);	
		if((*eleman_sayisi)==0){
			return NULL;
		}
	}}
	else
	printf("%d sayisi listede hic yok\n",sayiSil);
	return head;
}
/*link * sil(link * head,int silinecek,int * eleman_sayisi,int * seviye){
	link * curr,*prev,*curr_prev,*count_prev,*count_curr;
	int k,i,j,count=0,count1=0;
	curr=head->down->next;
	prev=head->down;
	curr_prev=prev;
	while(prev!=NULL){
		count1=0;
		curr=prev->next;
		curr_prev=prev;
		while(curr!=NULL && curr->deger!=silinecek){
			curr_prev=curr;
			curr=curr->next;
			count1++;
		}
			if(curr!=NULL &&curr->deger==silinecek){
			curr_prev->next=curr->next;
			free(curr);
			count++;
			}
		prev=prev->down;
		
		
	}
			if(count>0){
			for(i=(*seviye);i>(*seviye)-count;i--){
			count_prev=head->down;
				for(j=0;j<i;j++){
					prev=count_prev;
					count_prev=count_prev->down;
					count_curr=count_prev->next;
				}
				for(k=0;k<count1;k++){
					count_curr=count_curr->next;
				}
				curr=NULL;
				curr=(link*)malloc(sizeof(link));
				curr->deger=count_curr->deger;
				curr->down=count_curr;
				while(prev!=NULL && prev->deger>curr->deger){
					count_prev=prev;
					prev=prev->next;
				}
				if(prev==NULL){
					count_prev->next=curr;
					curr->next=NULL;
				}
				else {
					count_prev->next=curr;
					curr->next=prev;
				}
			}
		}
	
	
	(*eleman_sayisi)--;
	return head;
}*/
int search(link * head, int aranan,int seviye,int real){
	int count=seviye;
	link * curr,*prev,*curr_prev;
	if(head!=NULL){
	prev=head->down;
	while(prev!=NULL && count!=0){
	curr=prev->next;
	curr_prev=prev;
	while(curr!=NULL && curr->deger<aranan){
		curr_prev=curr;
		curr=curr->next;}
	if(curr==NULL || curr->deger>aranan){
		prev=curr_prev->down;
		count--;
	}
	else{
		if(real){
		printf("%d sayisi %d. seviyede bulundu\n",aranan,count);}
		return 1;
	}

	}
	if(real)
	printf("%d sayisi bulunamadi\n",aranan);
	return 0;			
}
	else{
	if(real)
	printf("Liste su an bos\n");}
	return 0;

}
	
	
/*void recursive(link * head,int num,int seviye){
	
	int number_of_elements=0,number_of_new_elements=0;
	int i,j,kalan,random_number;
	
		tmp=head->down->next;
		
		if(tmp->deger == num){//ilk deger eşitse
			printf("Sayi %d. seviyede bulundu!",seviye+1);
			return;
		}
		else if(tmp->deger > num){//ilk deger buyukse yeni recursive
			if(tmp->pointer==NULL){
				head->pointer = hlpr;
				head->pointer = generate_linked_list();
				head->pointer->next = hlpr;
				return;
			}
			starter=head->next->pointer;
			recursive(head->next,starter,num);
			return;
		}
		else{
			while(tmp->next != NULL && tmp->next->number<num){
				tmp = tmp->next;
			}
			if(tmp->number == num){
				printf("Sayi bulundu!");
				return;
			}
			else{
				starter=tmp;
				recursive(head->next,starter,num);
			}
		}
		
	}*/
/*link * link_olustur(){
	link *tmp;
	tmp = (link*) malloc(sizeof(link));
	tmp->down=NULL;
	tmp->next=NULL;
	return tmp;	
}*/
/*void eleman_olustur(link *Rhead,int n,int seviye){
	int i,j=0,eleman_sayisi=0,yardimci,kalan;
	link *head,*ex_head,*tmp,*ex_tmp,*linked_list;
	ex_head = Rhead;
	Rhead = link_olustur();
	Rhead->down = link_olustur();
	head = Rhead->down;
	if(seviye==0){
		tmp = head;
		for(i=0;i<n;i++){
			tmp->next = link_olustur();
			tmp->deger=rand()%(5)+j;
			j=tmp->deger;
			tmp = tmp->next;
		}
	}
	else{
		eleman_olustur(head,n,seviye-1);
	}
	for(tmp = head;tmp!=NULL;tmp=tmp->next){
		eleman_sayisi++;
	}
	tmp = head;
	ex_head = (link*) malloc(sizeof(link));
	ex_tmp = ex_head;
	kalan=eleman_sayisi;
	for(i=0 ;i<(eleman_sayisi+1)/2 ;i++){
		yardimci = rand()%(kalan - (((eleman_sayisi+1)/2)-i));
		kalan-=yardimci;
		for(j=0;j<yardimci;j++){
			tmp = tmp->next;
		}
		ex_tmp->deger=tmp->deger;
		ex_tmp->down = tmp;
	}
	
	
}*/


link * eleman_ekle(link * head,int deger,int * eleman_sayi,int * seviye){
	link * curr,*node,*node1,*prev;
	(*eleman_sayi)++;
	int i,count=0,j;
	int eleman=(*eleman_sayi);
	if(head==NULL){
		head=(link*)malloc(sizeof(link));
		head->next=NULL;
		curr=(link*)malloc(sizeof(link));
		head->down=curr;
		node=(link*)malloc(sizeof(link));
		node->deger=deger;
		node->next=NULL;
		node->down=NULL;
		curr->next=node;
		curr->down=NULL;
		(*seviye)=1;
		return head;
	}
	else{
		while(eleman%2!=0){
			eleman=(eleman+1)/2;
			count++;
		}
		if(eleman==2){
			curr=(link*)malloc(sizeof(link));
			curr->down=head;
			curr->next=NULL;
			head=curr;
			count++;
			(*seviye)++;
		}
		for(i=0;i<=count;i++){
			curr=head;
			for(j=0;j<(*seviye)-i;j++){
				curr=curr->down;
			}
			prev=curr;
			curr=curr->next;
			while(curr!=NULL && curr->deger<deger){
				prev=curr;
				curr=curr->next;
			}
			node=(link*)malloc(sizeof(link));
			node->deger=deger;
			node->next=NULL;
			if(curr==NULL){
				prev->next=node;
				node->next=NULL;
				node->down=NULL;
			}
			else{
				prev->next=node;
				node->next=curr;
			}
			if(i!=0)
			node->down=node1;
			node1=node;
			node=NULL;
		}
	}
	curr=head;
	for(i=0;i<(*seviye);i++){
		curr=curr->down;
	}
	curr->down=NULL;
	
	return head;
}
link * ilk_ekleme(link * head,int n,int * seviye,int * dizi){
	int i,j=0,k=0,m,l;	
	while(j<(n)){
		srand(time(NULL));
		i=rand()%n;	
		if(!search(head,dizi[i],*seviye,0)){
			head=eleman_ekle(head,dizi[i],&k,seviye);
			n--;
			for(l=i;l<n;l++){
				dizi[l]=dizi[l+1];
			}
		}
		else{
			printf("%d elemanini birden cok girmissiniz tekrar giriniz\n",dizi[i]);
			scanf("%d",&dizi[i]);}
	}
	return head;
}
int main(){
	link * head=NULL,*gezgin_head,*curr,*prev;
	int eleman_sayisi=0,seviye=0,n,i,eleman,choice,silme_count=0,*dizi;
	printf("Eleman sayisi gir\n");
	scanf("%d",&n);
	eleman_sayisi=n;
	//head = (link*) malloc(sizeof(link));
	//eleman_olustur(head,n,seviye);
	dizi=(int*)malloc(n*sizeof(int));
	for(i=0;i<(n);i++){
		printf("Lutfen %d. elemani giriniz\n",i+1);
		scanf("%d",&dizi[i]);
		}
	head=ilk_ekleme(head,n,&seviye,dizi);
	/*for(i=0;i<n;i++){
	printf("%d. elemani gir\n",i+1);
	scanf("%d",&eleman);
	if(search(head,eleman,seviye,0)){
		printf("Ayni elemani ekleyemezsin tekrar dene\n");
		i--;
	}
	else
	head=eleman_ekle(head,eleman,&eleman_sayisi,&seviye);}*/
	do{
		choice=menu();
		switch(choice){
			case 1:
				printf("Eklenecek elemani giriniz\n");
				scanf("%d",&n);
				if(search(head,n,seviye,0))
				printf("Ayni eleman ekleyemezsin\n");
				else{
				head=eleman_ekle(head,n,&eleman_sayisi,&seviye);
				yazdir(head,eleman_sayisi);
				}
				break;
			case 2:
				printf("Silinecek elemani giriniz\n");
				scanf("%d",&n);
				head=sil(head,&eleman_sayisi,&seviye,n);
				yazdir(head,eleman_sayisi);
				break;
			case 3:
				yazdir(head,eleman_sayisi);
				break;
			case 4:
				printf("Aranacak elemani giriniz\n");
				scanf("%d",&n);
				search(head,n,seviye,1);
				break;
			case 0:
				printf("Cikis yapildi\n");
				break;
			default:
				printf("Duzgun sayi giriniz\n");
		}
		
		
		
	}while(choice);
	while(head!=NULL){
		prev=head;
		head=head->down;
		curr=prev->next;
		while(curr!=NULL){
			free(prev);
			prev=curr;
			curr=curr->next;
		}
		free(prev);
	}
	return 0;
}