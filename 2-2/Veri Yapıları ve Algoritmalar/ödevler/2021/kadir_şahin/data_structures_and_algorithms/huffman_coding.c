#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node{
    char harf;
    int frekans;
    struct node *left,*right,*next;
}NODE;

NODE* add_node(NODE*,char,int);
void  insert_after(NODE **,NODE *);
void delete_node(char*);
void print_list(NODE*);
void insertion_sort(NODE**);
NODE* huffman(NODE*);
void print_huffman(NODE*);
NODE* enkucuknode_cikar(NODE**);
int tree_height(NODE*);
void print_tree_node(NODE*,int);




void print_tree_node(NODE* iter,int level){    //Fonksiyon, kendisine gonderilen bir agac seviyesindeki node'lari
	if(iter==NULL){							   //recursive olarak surekli tum yollardan ayni node seviyesine
		return;								   //inip geri cikarak yazd�rmaktadir. NULL nodelar� yazdirmiyoruz.
	}
	if(level == 1){
		if(iter->harf==' '){					
			printf("(' '%d) ",iter->frekans);	//bosluklarin gorunurlugu icin
		}
		else if(iter->harf=='$'){				//child olmayan node'larin harfini '$' olarak kodlamistik
			printf("(%d) ",iter->frekans);		//bu sayede parent node'lari bosluk sayisi ile karistirmiyoruz.
		}
		else{
			printf("(%c%d) ",iter->harf,iter->frekans);
		}
		
	}
	else if(level>1){
		print_tree_node(iter->left,level-1);  //girilen herhangi bir level sayisi kadar 
											  //level=1 olana kadar left'e gidiyoruz
											  //NULL degilse 1 olunca indigimiz node'u yazdirip
		print_tree_node(iter->right,level-1); //ayni node'un bir ustunden tekrar level=1 olana kadar
											  //right'a iniyoruz. onu da yazdirip sonra geri ciktikca mumkun olan dallara
											  //tekrar inerek o leveldeki tum node'lari yazdirmis oluyoruz.
		
	}
}




int tree_height(NODE* head){				//Bu fonksiyonla agacin yuksekligini buluyoruz ki
											//tum node'lari eksiksiz yazdirabilelim
	if(head==NULL){
		return 0;
	}
	else{

		int height_L=tree_height(head->left);	//NULL node gorene kadar sol en derine iniyoruz, NULL gordugumuz
		int height_R=tree_height(head->right);	//yerde bir level geri donup tekrar solda NULL yoksa tekrar
												//en derine inmeye devam ederek en alttaki tum child node'lar�
												//dolasmis oluyoruz. 
												
		if(height_L>height_R){					//her dip node'a inince sayaclarimiz fonksiyonlari cagirabildikleri  
			return height_L+1;					//kadar sayiyi bir ust node'a aktariyor
		}										//tum node'lar gezildikten sonra en derin yolun level sayisi donmus oluyor.
		else{									
			return height_R+1;
		}
	}

}

void print_huffman(NODE *head){				// Tree'mizi yazdirma fonksiyonu


	int height=tree_height(head);				//Yazdirmadan once agacimizin yuksekligini hesapl�yoruz
	int i=0;

	for(i=1;i<=height;i++){					//tum node seviyelerini sirayla seviye yazdirma fonksiyonuna gonderiyoruz
		int j;
		for(j=0;j<height-i;j++){
			printf("   ");
		}
					
		print_tree_node(head, i); 		  
        printf("\n");
	}

}


NODE* enkucuknode_cikar(NODE** head){		//Huffman Tree'ye donustururken olusturdugumuz
											//gecici tree'nin child'larini her defasinda listeden
											//en kucuk olan node'u cikartip alarak ayarliyoruz
	NODE *tmp;
	tmp=*head;
    if((*head)->next==NULL){				//son eleman bir eleman kaldiysa 
		tmp=(*head);						
		*head=NULL;							
        return tmp;
    }
	*head=(*head)->next;					//giren eleman son eleman degilse listede o andaki 
											//en kucuk elemandir, onu gecici tree'ye ekleyecegimiz icin
	return tmp;								//listeden cikarttik, listenin yeni head'i bir sonraki eleman oldu
}


void insertion_sort(NODE** head){

	NODE *tmp_list=NULL;					//kaydirdigimiz indisimize kadar olan sirali
	NODE *current=*head;					//listeyi gosteren gecici listemizin head'i
	
	while(current!=NULL){					//listenin en basindan itibaren elemanlari sirayla alip
		NODE *next =current->next;			//uygun yere insert edecegiz, bunun icin sirali listemizi ve onceki
		insert_after(&tmp_list,current);	//siralanmamis listekimizdeki o anki indisi insert fonksiyonuna 
		current=next;						//gonderiyoruz
	}
	
	*head=tmp_list;							//ilk listemizdeki indis NULL gorene kadar insert ile siraladik
											//yeni head'imiz gecici olusturdugumuz sirali listenin head'i
											
}

void insert_after(NODE** head,NODE* tmp){	//insertion_sort'un asil uygun yere koyma isini bu fonksiyon yapiyor
	
	
	
	NODE* current;
	
	if(*head==NULL||(*head)->frekans>tmp->frekans){ 
		tmp->next=*head;
		*head=tmp;
	}
	else{
		current=*head;
		while(current->next!=NULL && current->next->frekans <= tmp->frekans){ 
			current = current->next;			//tmp'in sirali listede uygun oldugu yeri bulana
		}										//kadar current'i iterasyon yaptiriyoruz
												
		tmp->next = current->next;				// uygun yer bulundu ve
		current->next=tmp;						//tmp current ile current->next arasina insert edildi
	}	
}

NODE* add_node(NODE *head,char harf,int frekans){  //girilen metnimizdeki harfler ve frekans sayilari 
    NODE *new;									// sirasiz linkli listeye ekleniyor
    
    new=(NODE*) malloc(sizeof(NODE));
    if(new==NULL){
        printf("malloc hatasi! \n");
        exit(1);
    }
    
    if(head==NULL){								// ilk node ise head ata
        
		head=new;
        head->next=NULL;
        head->left=NULL;
    	head->right=NULL;
    	head->frekans=frekans;
    	head->harf=harf;

		return head;
	}
	
    new->next= head;	
    new->left=NULL;
    new->right=NULL;
	new->frekans=frekans;
	new->harf=harf;

    head=new;									//ilk node degilse  yeni olusturulan node'u head yap
    
    return head;    
}


NODE* huffman(NODE *head){			//Liste'den Tree'ye donusturdugumuz fonksiyon
	
	
	int node_n=0,i;
	NODE *counter;					//kac kez gecici agac olusturacagimizi bilmek icin linkli listedeki
	for(counter=head;counter!=NULL;counter=counter->next){		//node sayisini buluyoruz
		node_n++;
	}
	
	for(i=1;i<node_n;i++){
		NODE *tmp_root;					//olusturacagimiz gecici agacin pointeri
		
		tmp_root=(NODE*)malloc(sizeof(NODE)); //gecici agaci initialize ettik

		tmp_root->left=enkucuknode_cikar(&head);	//left icin listedeki en kucuk frekansli harf bulundu
        tmp_root->right=enkucuknode_cikar(&head);	//right icin tekrar cagrildi
        
		tmp_root->frekans = tmp_root->left->frekans + tmp_root->right->frekans; //gecici agacimizin
													//root'unun frekansi, child node'larin frekanslari toplamina esit
		tmp_root->harf='$';							//yazdirirken ayirt etmek icin boyle kodladik
		
		insert_after(&head,tmp_root);				//olusturdugumuz gecici agaci o anki listedeki 
													//uygun yere insert ediyoruz. head zaten enkucuknode_cikar
													//cagrilinca guncellenmisti.
		}
    return head;

	
}


void print_list(NODE* head){
    if(head==NULL){
        printf("Liste bos \n");
        return;
    }

    NODE* i;

    for(i=head; i!=NULL; i=i->next){  	
		printf("(%c %d)",i->harf, i->frekans); 
    }
	printf("\n");
}

int main(){
    
	char input[250];			
    int frekans[27]={0},i=0;	// frekanslari tutacagimiz alfabe+space  buyuklugunde dizi olusturduk

    NODE *head=NULL;			//olusturacagimiz linkli listenin node'u
    

    printf("bir metin giriniz: ");
    gets(input);
    printf("%s  \n",input);
    for(i=0;input[i]!='\0';i++){
    	if(input[i]>='a' && input[i]<='z'){
    		frekans[input[i]-'a']++;		//kucuk harf ise ilgili indisteki sayaci arttir 
		}
		else if(input[i]=' '){				//bosluk ise o hucreyi arttir
			frekans[26]++;
		}
    	
	}
	
	
	for(i=0;i<27; i++){
		if(frekans[i]!=0 && i<26){
			head=add_node(head,'a'+i,frekans[i]); //frekans dizimizden linkli listeye geciste uygun harfi atamak icin
												  // 'a'+indis
		}
		else if(frekans[i]!=0&&i==26){			 // frekans dizisinde bosluk icin ayrilan gozdeki sayac, bosluk 
			head=add_node(head,' ',frekans[i]);	// karakteriyle birlikte listeye eklendi
		}	
	}

	insertion_sort(&head);						// liste siralanacak
	print_list(head);							
	
	head=huffman(head);							//sirali liste agaca donusturulecek


	print_huffman(head);
	
    getch();
    return 0;
}
