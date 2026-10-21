#include <stdio.h>
#include <stdlib.h>
// sýralý eleman ekleme
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
		while( r->next!= NULL )		//	nexti null gösterern noda gitmeyi saðlýyor yani en son node
			r = r->next;
		r->next=(node*)malloc(sizeof(node)); // en son node den sonra bir node daha aç nextine koy adresini
		r-> next -> x = x;					// yeni açýlan nosun x i verilen x olasun
		r-> next -> next = NULL;			// yeni oluþturulan nodumuzun nextini NULL yapýyoruz.
	}

node *ekleSirali(node *r, int x){
	
	if(r==NULL){  // durum 1 eðer tamammen boþsa hiç biþi yoksa içeride
		r=(node*)malloc(sizeof(node));
		r->next=NULL;
		r -> x = x;
		return r;
	}
	if (x < (r->x) ){ // eðer gelen eleman ilk elemandan küçük ise
		//root deðiþiyor önemli bir nokta
		node *temp =(node*)malloc(sizeof(node));  // ekleyeceðimiz node temp isimli bir pointerde tutuyoruz yarattýk ayný y-zamanda burada
		temp-> x = x;
		temp->next = r;  // iterin nexti artýk nodumuzun nexti olacak ve  !!ÖNEMLÝ ÝLK BUNU YAPMALIYIZ ki next bilgisini kaybetmeyelim.
		return temp;
	}
	
	node *iter=r;
	while(iter->next!=NULL && (iter->next->x) < x) // iterin sonuna kadar ve x ten büyük bir sayý görene dkadar git x ten büyük sayýyý bulup önüne ekleme yapacaðýmýz için iter->next->x yazdýk
		iter=iter->next;
	node *temp=(node*)malloc(sizeof(node));  // ekleyeceðimiz node temp isimli bir pointerde tutuyoruz yarattýk ayný y-zamanda burada
	temp->next =iter->next;  // iterin nexti artýk nodumuzun nexti olacak ve  !!ÖNEMLÝ ÝLK BUNU YAPMALIYIZ ki next bilgisini kaybetmeyelim.
	iter->next=temp;
	temp->x=x;
	return r;
	
}
		
int main(){
	int i=0;
	node *root; /// node structuremizin root yani baþlangýç adresini tutan bir pointer yarattým bu root çok önemli
    root = NULL;

	root= ekleSirali(root,555); // neden roota eþitledik çünkü verilen eleman çok küçükse en baþa alacak ve artýk root bu eleman olacak diðerlerinin hepside baþlangýcý döndürüyor zaten no problemo
	root= ekleSirali(root,55);
	root= ekleSirali(root,5);
	root= ekleSirali(root,700);
	root= ekleSirali(root,57);

	bastir(root);
}

