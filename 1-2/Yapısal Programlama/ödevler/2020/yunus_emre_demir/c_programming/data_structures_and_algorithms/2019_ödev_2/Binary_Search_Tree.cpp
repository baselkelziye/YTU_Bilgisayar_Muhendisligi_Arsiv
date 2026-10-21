#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

struct node { 
    int tc; 
    char ad_soyad[30];
    char arkTc[30];
    struct node *sol;
	struct node *sag; 
}; 
struct node *root = NULL;
 
struct node *yeniNode(int tcno, const char *isim, char arkTcleri[]) {    //Verilen bilgilerle bir node olusturuyor.
	struct node *temp = (struct node*)malloc(sizeof(struct node)); 
    temp->tc = tcno; 
    strcpy(temp->ad_soyad,isim);
    strcpy(temp->arkTc,arkTcleri);
    temp->sol = NULL; 
	temp->sag = NULL; 
    return temp; 
} 

void printOrder(struct node *root) {	//Tc nolara gore siralama yapiyor.
    if (root != NULL) { 
        printOrder(root->sol); 
        printf("%d %s %s  \n", root->tc, root->ad_soyad, root->arkTc); 
        printOrder(root->sag); 
    } 
} 

void printNext(struct node *node) {	// ilgili dugumden sonraki sag ve sol dugumleri yazdiriyor.
    if (node != NULL) { 
        printNext(node->sol); 
        printf("       %d %s %s  \n", node->tc, node->ad_soyad, node->arkTc); 
        printNext(node->sag); 
    } 
} 

struct node* araVarsa(struct node *root, int tc){    	//containsin alt fonksiyonu: Eger var ise buluyor.
    while((root->tc != NULL) && (root->tc != tc)){
	   	if (root->tc > tc) 
	   	 	root=root->sol;
	   	else
	   		root=root->sag;
	}
    printf("Aranan eleman: %d %s \n", root->tc, root->ad_soyad); 
    return root;
}

struct node *contains(struct node *root, int tcno) {	// Tc si verilen kisiyi agacta olup olmadýgýný kontrol ediyor.
    while (root != NULL) { 
		printf(" %d karsilastiriliyor %d\n", tcno, root->tc );
        if (tcno > root->tc){
            root = root->sag;
		}
        else if (tcno < root->tc) 
            root = root->sol; 
        else
        	return araVarsa(root, tcno);
    } 
    printf("Aradiginiz eleman yok efendim.\n");
} 

struct node* friedns(struct node *root, int tc){   // kisinin arkadaslarini getiren fonksiyon
    while((root->tc != NULL) && (root->tc != tc)){
	   	if (root->tc > tc) 
	   	 	root=root->sol;
	   	else
	   		root=root->sag;
	}
    printf(" 		%d %s \n", root->tc, root->ad_soyad); 
}

// insertnNewUserin alt fonksiyonu: eger root mevcut ise geleni ekliyor
struct node *yerlestir1(struct node *node, int tcno, const char* isim, char arkTcleri[]) {  
	// isi yapan kod(if) bu!
    if (node == NULL) 	
		return yeniNode(tcno, isim, arkTcleri);  
	//asagýda yerini bulmaya calýsýyor
    if (tcno < node->tc) 
        node->sol  = yerlestir1(node->sol, tcno, isim, arkTcleri); 
    else if (tcno > node->tc) 
        node->sag = yerlestir1(node->sag, tcno, isim, arkTcleri);    

    return node; 
} 

struct node *insertNewUser(struct node *node, int tcno, const char* isim, char arkTcleri[]) { //eger agacimiz bos ise ilk geleni root yapiyor
	// root == Null ise; ilk geleni root yapýyor!
    if (node == NULL)
    	return	root= yeniNode(tcno, isim, arkTcleri);
    else
  		return yerlestir1(node, tcno, isim, arkTcleri); 
}
 
struct node *enKucukNode(struct node *node) { 
    struct node *current = node; 
    while (current->sol != NULL) 
   		current = current->sol;
    return current; 
}

void printGreater(struct node *root, int contains) { 
    if (root ==NULL) 
    	return;
    else{ 
        if(root->tc > contains){
            printf("%d %s \n", root->tc, root->ad_soyad); 
        }
        printGreater(root->sol, contains);
        printGreater(root->sag, contains);
    } 
}

struct node* deleteUser(struct node* root, int tc) {  // Tc si verilen elemani siliyor.
    if (root == NULL) 
		return root; 

    if (tc < root->tc) 
        root->sol = deleteUser(root->sol, tc); 
    else if (tc > root->tc) 
        root->sag = deleteUser(root->sag, tc); 
    else
    { 
        if (root->sol == NULL) { 
            struct node *temp = root->sag; 
            free(root); 
            return temp; 
        } 
        else if (root->sag == NULL) { 
            struct node *temp = root->sol; 
            free(root); 
            return temp; 
        } 
        struct node* temp = enKucukNode(root->sag); 
        root->tc = temp->tc;
        root->sag = deleteUser(root->sag, temp->tc); 
    } 
    return root; 
}

int size(node* node)  {  
    if (node == NULL)  
        return 0;  
    else
        return (size(node->sol) + 1 + size(node->sag));  
}

void dosyaOkuma(int tcnumarasi){  // Txt dosyasini okuyor. (satir satir)
	char alHarf,dizi[50];
	int i=0,p=0,kisitc=0, k=0;
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
		
	FILE *fp;
	fp=fopen("Input.txt","r+");
	
	
		while(!feof(fp)){
			fscanf (fp, "%d", &kisitc);  // kisinin tc sini alýyoruz integer olarak.

			temp->tc = kisitc; 
			fgetc(fp);
			
			alHarf='\0';
			p=0;
			while(!feof(fp) && alHarf!='\n' && alHarf!=','){
				alHarf=fgetc(fp);
				dizi[p++]=alHarf;
			}
			dizi[--p]='\0';
			strcpy(temp->ad_soyad,dizi);
			
			for(i=0; i<30 ; i++)	// dizimizin içini temizliyor
				dizi[i]='\0';

			p=0;
			while(!feof(fp) && alHarf!='\n'){  //arkadaslarýn tcleri
				alHarf=fgetc(fp);
				dizi[p++]=alHarf;
			}
			dizi[--p]='\0';
	   		strcpy(temp->arkTc,dizi);
	   		
	   		if(tcnumarasi==temp->tc){
				insertNewUser(root, temp->tc, temp->ad_soyad, temp->arkTc);  // derli toplu dursunlar diye bunlarý structure da tuttuk
				printf("   [  Eleman basariyla eklendi. ]  \n");
				k++;
			}
			for(i=0; i<30 ; i++)    // dizimizin içini temizliyor
				dizi[i]='\0';
		}
	
		if(k==0)
			printf("\n Tc'sini girdiðiniz eleman dosyada yok! \n");
}

int main() { 
 	int  sayac, secim=0, sayi=0, i=0, k=0, eleman=0;
 	char ark, adSoyad[50], dizi[50];
 	int kisitc=0;
 	
    while (1){
        printf("\n 1- insertNewUser");
        printf("\n 2- deleteUser");
        printf("\n 3- contains");
        printf("\n 4- printNext");
        printf("\n 5- printGreadter");
        printf("\n 6- Size");
        printf("\n 7- orderPeople");
		printf("\n 8- friends");
		printf("\n 0- exit");
        printf("\n\n Seciminizi yapiniz : ");
        scanf("%d", &secim);

        switch (secim)
        {
            case 0:
				exit(0);
				break;
	
			case 1: 
            	printf("Kac eleman ekleyeceksin ");
                scanf("%d", &eleman);
                for(i=0; i<eleman ; i++){
            		printf("Tc numarasini giriniz : ");
               		scanf("%d", &sayi);
            		dosyaOkuma(sayi);
					k++;
					if (k==10){  // 10 tane adam eklendiðinde yazdýrýyor.
						printf("\n\n");
						printOrder(root);
						k=0;
					}            	
				}
                break;
                
            case 2:
            	sayi=0;
                printf("\nSilmek istediginiz elemani giriniz : ");
                scanf("%d",&sayi);
                deleteUser(root, sayi);
                printf("   [ Aradýginiz eleman silindi. ]  ");
                break;
 
            case 3:
				sayi=0;
                printf("\nAradiginiz Tc numarasini giriniz : ");
                scanf("%d", &sayi);
                contains(root, sayi);
                break;
                
            case 4:
            	sayi=0;
                printf("\n Tc numarasini giriniz : ");
                scanf("%d", &sayi);
            	printNext(contains(root,sayi));
                break;
 
            case 5:
            	printf("\n Tc numarasini giriniz : ");
                scanf("%d", &sayi);
            	printGreater(root,sayi);
                break;
 
            case 6:
            	printf(" Agacimizin boyutu : %d \n", size(root));
                break;
            case 7:
            	printOrder(root);
            	break;
				 
			case 8:
            	int yp=0,i=0, s1=0;
            	sayi=0;
            	char yedek[50];

            	printf("\n Tc numarasini giriniz : ");
            	scanf("%d", &sayi);
            	struct node *temp = contains(root,sayi);
            	strcpy(dizi,temp->arkTc);
            	printf(" Arkadaslari : \n"); 
	            while(dizi[i]!='\0' && i<strlen(dizi)){
					yp=0;
					while((dizi[i]!='-' ) && i<strlen(dizi)){
						yedek[yp++] = dizi[i++];
					}
					yedek[yp]='\0';
					s1=atoi(yedek);
					friedns(root,s1);
					i++;
				}	
            	break;            
        }	
    }
    return 0; 
} 
