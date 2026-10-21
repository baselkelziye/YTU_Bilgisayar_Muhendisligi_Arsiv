#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3
#define L 4

//Struct Tanımı.
typedef struct node{
	char *val;			//String değerini tutar.
	int counter;		//Sayac değerini tutar.
	struct node *next;
	struct node *prev;
}node;
//Fonksiyon prototipleri.
node *newNode();	//Yeni node için dinamik yer açar.
node *find(char*);	//Aranılan değeri bulur
void popEnd();	   //En sondaki node'u siler.
int size();		  // Stack boyutunu döndürür.
void list();	  // Listeleme görevi yapar.
void push(char*); // Stack'e pushlar.

node *head; //global değişken tanımlaması.

node *newNode(){ //Yeni node için dinamik yer açıp, değeri geri döndürür.
	node *tmp = (node*)calloc(1,sizeof(node));
	tmp -> next = NULL;
	tmp -> prev = NULL;
	return tmp;
}
node *find(char *data){ //Verilen değerin stackte olup olmadığını gösterir.
	node *tmp = head;
	while(tmp){
		if(strcmp((tmp->val),data) == 0){ //Eğer 0 ise değer bulunup geri döndürülür.
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

void popEnd(){ //Sondan çıkarma işlemi yapılır.
	node *tmp = head;
	node *prv;
	while(tmp->next != NULL){
		tmp	= tmp -> next;
	}
	tmp -> prev -> next = NULL;
	free(tmp); //Değer freelenir.
}

int size(){ //Boyutu döndürür.
	node *tmp = head;
	int n = 0;
	while(tmp){
		n++;
		tmp = tmp->next;
	}
	return n;
}

void list(){ //Listeleme işi yapılır.
	node *tmp = head;
	while(tmp!=NULL){
		printf("%s\t%d\t",tmp->val, tmp->counter);
		tmp = tmp -> next;
	}
	printf("\n");

}


void push(char *data){
	node *tmp = newNode(); //tmp için dinamik yer açılır.
	node *tmp2;

	if(head == NULL){ //Eger head daha önce tanımlanmadııysa.
		tmp->val = data;
		tmp->counter = 1;
		head = tmp;
	}else{
		if(find(data)==NULL){ //Eger head daha önce varsa ve aktarılan veri yoksa.
			head->prev = tmp;
			tmp -> val = data;
			tmp ->next = head;
			tmp -> counter = 1;
			head = tmp;
			if(size()>L) //Boyut eğer aşıldıysa sondaki değer silinir.
				popEnd();				
		}else{ //Eger veri bulunduysa, counterı arttırılır.
			tmp2 = find(data);
			tmp2->counter ++;
			if(tmp2->counter > T){ //EGER Limit aşıldıysa
				node *nxt, *prv;
				nxt = tmp2 ->next;
				prv = tmp2 ->prev;
				if(nxt)				//Null hatası için
					nxt -> prev = prv;
				if(prv)				//Null hatası için
					prv -> next = nxt;
				head -> prev = tmp2;
				tmp2 -> next = head;
				head = tmp2;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	push("A");
	list();
	push("B");
	list();
	push("A");
	list();
	push("AA");
	list();
	push("BBB");
	list();
	push("B");
	list();
	push("A");
	list();
	push("AB");
	list();
	push("A");
	list();
	push("B");
	list();
	push("A");
	list();
	push("BB");
	list();


	return 0;  
}
