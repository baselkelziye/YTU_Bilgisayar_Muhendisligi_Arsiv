#include <stdio.h>
#include <stdlib.h>

struct n{   // bir structure oluþturdum. BU structure bir adet x ten ve kendini point eden bir pointer next ten müteþekkil.
	int x;
	n *next;	
};
typedef struct n node; // n structure cinsinden node diye bir structure yarattým.

void bastir( node *r ){
	while(r!=NULL){
		printf("%d\n",r->x);
		r = r->next ;
	}
}

int main(){
	int i=0;
	node *root; /* node structuremizin root yani baþlangýç adresini tutan bir pointer yarattým bu root çok önemli
				 Linked listlerde eðer baþlangýcý bilmiyorsak liste yok demektir oyüzden root önemli*/
	root = (node*)malloc(sizeof(node));  // root un içine bir kutucuk açtým kutucuk iki kýsýndan müteþekkil: 1 data 2 next
	root -> x =10;		// kutucuðun data kýsmýna 10 koydum				
	root -> next = (node*)malloc(sizeof(node)); //next kýsmýndada açtýðým bir kutucuðun adresini tutuyorum çünkü next bir pointer.
	root -> next -> x =20; // 1. kutu içindeki nextin gösterdiði adresteki kutunun (yani 2. kutu) data kýsmýna 20 koyuyorum.
	root -> next -> next = (node*)malloc(sizeof(node)); // 2. kutunun next kýsmýna 3. kutu yaratýp adresini koyuyorum.
	root ->next ->next -> x =30; // 3. kutunun data kýsmýna 30 koyduk
	root ->next ->next -> next =NULL;
	node *iter;  // iteration adlý bir pointer tanýmlýyorum buda ayný structureyi point ediyor bunu istediðim gibi gezmek için tanýmladým. Rootu sadece 1. kutunun yerini tutmak için taýmlamýþtým bunun gezmek için tanýmladým.
	iter = root; // iterin 1. kutuyu göstersin
	printf("%d\n",iter->x);  // data kýsmýnda birinci kutunun data kýsmý var.
	iter = iter->next; // iter 2. kutuyu göstersin
	printf("%d\n",iter->x);  // data kýsmýnda 2. kutunun datasý var
	iter=root;
	while(iter->next != NULL){
		i++;
		printf("%d.eleman = %d\n",i,iter ->x);
		iter= iter->next;
	}
	
	for(i=0;i<5;i++){
		iter->next= (node*)malloc(sizeof(node));
		iter = iter->next;
		iter -> x = i*10;	
		iter -> next= NULL;
	}
//	iter -> next= NULL; burayada koyabiliriz.
	bastir(root);
}
