#include <stdio.h>
#include <stdlib.h>

struct n {//veri �nitesi
	int data;//veri �nitesinin data k�sm�
	n * next;//veri �nitesinin pointer k�sm�
};

typedef n node;

void yazdir(node * kutucuk){
	while( kutucuk != NULL ){
		printf("%d ",kutucuk -> data);
		kutucuk = kutucuk -> next;
	}
}

void sonaEkle(node * kutu, int data){
	while( kutu -> next != NULL){
		kutu = kutu -> next;
	}
	kutu = kutu -> next;
	kutu = (node *)malloc(sizeof(node));
	kutu -> data = data;
	kutu -> next = NULL; 
}

int main(){
	node * root;
	root = (node *)malloc(sizeof(node));//ilk kutucu�u(komple veri �nitesini) g�steriyor(node * tipinde bir pointer)
	root -> data = 10;//root'un g�sterdi�i kutucu�un data k�sm�na 10 koy
	root -> next = (node *)malloc(sizeof(node));//ilk kutucu�un pointer'�na bir kutucuk daha ba�lad�m
	root -> next -> data = 20;//root'un next'inin data de�erine 20 koy
	root -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> data = 30;
	node * iter;// node * tipinde pointer ile linked list �zerinde gezinece�iz
	iter = root;//1. kutuda
	//printf("%d ",iter -> data);
	iter = iter -> next;//2. kutuda
	//printf("%d ",iter -> data);
	iter = iter -> next;//3. kutuda
	//printf("%d ",iter -> data);
	
	//iter = root;//iter'i ba�a ald�m.
	//iter -> next -> next -> next = NULL;//elle NULL atamak laz�m listenin sonuna
	//int i = 0;
	/*while(iter -> next != NULL){//iter NULL � g�stermiyor iken//!!!!!!!!!iter'in next'i NULL olana kadar git, iter NULL olursa art�k �ok ge� :(
		//SIKINTI next'te
		i++;
		printf("%d. eleman : %d\n",i,iter -> data);
		iter = iter -> next;
		//if(i == 3)//b�yle de NULL atayabiliriz :)
		//	iter -> next = NULL;	
	}*/
	for( int i = 0; i <= 5; i++ ){
		iter -> next = (node *)malloc(sizeof(node));//son kutucu�un next'ine kutucuk atad�m//hala iterator son kutucukta
		iter = iter -> next;//�imdi yeni olu�turdu�um kutuya geldi
		iter -> data = i*10;//datas�na koydum bir �eyler
		iter -> next = NULL;//pointer�na da NULL � atad�m
	}
	
	yazdir(root);
	/*for(int i = 1; i<= 3; i++){
		
	}*/
	
	
}
