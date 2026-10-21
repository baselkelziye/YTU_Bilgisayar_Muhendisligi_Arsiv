#include <stdio.h>
#include <stdlib.h>

struct n{   // bir structure oluşturdum. BU structure bir adet x ten ve kendini point eden bir pointer next ten müteşekkil.
	int x;
	n *next;	
};
typedef struct n node; // n structure cinsinden node diye bir structure yarattım.

int main(){
	node *root; /* node structuremizin root yani başlangıç adresini tutan bir pointer yarattım bu root çok önemli
				 Linked listlerde eğer başlangıcı bilmiyorsak liste yok demektir oyüzden root önemli*/
	root = (node*)malloc(sizeof(node));  // root un içine bir kutucuk açtım kutucuk iki kısından müteşekkil: 1 data 2 next
	root -> x =10;		// kutucuğun data kısmına 10 koydum				
	root -> next = (node*)malloc(sizeof(node)); //next kısmındada açtığım bir kutucuğun adresini tutuyorum çünkü next bir pointer.
	root -> next -> x =20; // 1. kutu içindeki nextin gösterdiği adresteki kutunun (yani 2. kutu) data kısmına 20 koyuyorum.
	root -> next -> next = (node*)malloc(sizeof(node)); // 2. kutunun next kısmına 3. kutu yaratıp adresini koyuyorum.
	root ->next ->next -> x =30; // 3. kutunun data kısmına 30 koyduk
	node *iter;  // iteration adlı bir pointer tanımlıyorum buda aynı structureyi point ediyor bunu istediğim gibi gezmek için tanımladım. Rootu sadece 1. kutunun yerini tutmak için taımlamıştım bunun gezmek için tanımladım.
	iter = root; // iterin 1. kutuyu göstersin
	printf("%d\n",iter->x);  // data kısmında birinci kutunun data kısmı var.
	iter = iter->next; // iter 2. kutuyu göstersin
	printf("%d",iter->x);  // data kısmında 2. kutunun datası var
}

