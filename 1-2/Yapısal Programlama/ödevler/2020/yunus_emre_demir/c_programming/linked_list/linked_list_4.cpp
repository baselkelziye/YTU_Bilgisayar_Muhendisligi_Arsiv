#include <stdio.h>
#include <stdlib.h>

struct n{   // bir structure oluþturdum. BU structure bir adet x ten ve kendini point eden bir pointer next ten müteþekkil.
	int x;
	n *next;	
};
typedef struct n node; // n structure cinsinden node diye bir structure yarattým.

void bastir( node *r ){ // bastir diye bir fonctio nyazdýk bu fonsiyon 
	while(r!=NULL){		// verilen node null olana kadar node un x ini yazdýrýyor.
		printf("%d\n",r->x);	// 
		r = r->next ; // r node ponterimizi  bir sonraki node a geçiriyoruz							
	}
}

void ekle (node *r, int x){		//ekle fonksiyonumuz
		while( r->next!= NULL ){	//	nexti null gösterern noda gitmeyi saðlýyor yani en son node
			r = r->next;
		}
		r->next=(node*)malloc(sizeof(node)); // en son node den sonra bir node daha aç nextine koy adresini
		r-> next -> x = x;					// yeni açýlan nosun x i verilen x olasun
		r-> next -> next = NULL;			// yeni oluþturulan nodumuzun nextini NULL yapýyoruz.
	}
		
int main(){
	int i=0;
	node *root, *iter;
	root = (node*)malloc(sizeof(node)); // root un içine bir kutucuk açtým kutucuk iki kýsýndan müteþekkil: 1 data 2 next
	root-> x =555; 
	root -> next = NULL;
//	iter = root; // iterin 1. kutuyu göstersin

	for(i=0;i<5;i++)
		ekle(root,(i*10));
	bastir(root);
}



