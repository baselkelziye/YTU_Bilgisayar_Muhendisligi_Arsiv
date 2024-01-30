#include <stdio.h>
#include <stdlib.h>

struct n {//veri ünitesi
	int data;//veri ünitesinin data kýsmý
	n * next;//veri ünitesinin pointer kýsmý
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
	root = (node *)malloc(sizeof(node));//ilk kutucuðu(komple veri ünitesini) gösteriyor(node * tipinde bir pointer)
	root -> data = 10;//root'un gösterdiði kutucuðun data kýsmýna 10 koy
	root -> next = (node *)malloc(sizeof(node));//ilk kutucuðun pointer'ýna bir kutucuk daha baðladým
	root -> next -> data = 20;//root'un next'inin data deðerine 20 koy
	root -> next -> next = (node *)malloc(sizeof(node));
	root -> next -> next -> data = 30;
	node * iter;// node * tipinde pointer ile linked list üzerinde gezineceðiz
	iter = root;//1. kutuda
	//printf("%d ",iter -> data);
	iter = iter -> next;//2. kutuda
	//printf("%d ",iter -> data);
	iter = iter -> next;//3. kutuda
	//printf("%d ",iter -> data);
	
	//iter = root;//iter'i baþa aldým.
	//iter -> next -> next -> next = NULL;//elle NULL atamak lazým listenin sonuna
	//int i = 0;
	/*while(iter -> next != NULL){//iter NULL ý göstermiyor iken//!!!!!!!!!iter'in next'i NULL olana kadar git, iter NULL olursa artýk çok geç :(
		//SIKINTI next'te
		i++;
		printf("%d. eleman : %d\n",i,iter -> data);
		iter = iter -> next;
		//if(i == 3)//böyle de NULL atayabiliriz :)
		//	iter -> next = NULL;	
	}*/
	for( int i = 0; i <= 5; i++ ){
		iter -> next = (node *)malloc(sizeof(node));//son kutucuðun next'ine kutucuk atadým//hala iterator son kutucukta
		iter = iter -> next;//þimdi yeni oluþturduðum kutuya geldi
		iter -> data = i*10;//datasýna koydum bir þeyler
		iter -> next = NULL;//pointerýna da NULL ý atadým
	}
	
	yazdir(root);
	/*for(int i = 1; i<= 3; i++){
		
	}*/
	
	
}
