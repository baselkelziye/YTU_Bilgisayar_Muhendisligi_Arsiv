#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Link list node */
struct node
{
    char harf;
    int freq;
    struct node *next, *left, *right;
};

void insertionSort(int arr[][2], int);

struct node *insert(int arr[][2],int);
void printNode(struct node *);

struct node *huffman(struct node *,int);
struct node *topla(struct node *);

void print_agac(struct node*);
int tree_height(struct node *);
void printLevel(struct node* , int);


int main()
{
    struct node *baslangic, *iter, *yeni, *eski;
    char *str;
    printf("Bir string gir: ");
    gets(str);	//stringi kullanicidan alan fonksiyon
    
    int i, j, sumnode;

    for (i = 0; i < strlen(str); i++)
    {
        if (i == 0)	//baslangic dugumu icin 
        {
            baslangic = (struct node *)malloc(sizeof(struct node));	//yer actik
            baslangic->freq = 1;	//ilk defa kullanilan bir harf bu nedenle freq=1
            baslangic->harf = *(str + i);	//harfi stingin i. elemani
            baslangic->left = NULL;		// left right ve nexti simdilik null
            baslangic->right = NULL;
            baslangic->next = NULL;
            eski = baslangic;	//baslangicin degerini kaybetmeden baslangici kullanmak icin
            sumnode = 1;	//kac dugum oldugunu bulmak icin
        }
        else
        {	//baslangic dugum haric digerleri icin
            j = 0;
            iter = baslangic;
            while (iter != NULL)	
            {	
                if (iter->harf == *(str + i))	//bu kisim ayni harften bir tane daha geldiginde frekansi artırmak icin.
                {
                    iter->freq++;
                    j = 1; //ife girdiğini anlamak için koydugumuz bir flag
                }
                iter = iter->next;
            }

            if (j == 0)	//flag 0ken demek ki o harften bir tane daha yok.yeni dugum olustur.
            {
                yeni = (struct node *)malloc(sizeof(struct node));
                yeni->freq = 1;		//frekansi 1.
                yeni->harf = *(str + i);
                yeni->left = NULL;
                yeni->right = NULL;
                yeni->next = NULL;
                eski->next = yeni;
                eski = yeni;
                sumnode++;		//ilk noode'da 1 idi. yeni node olusturdugumuz icin 1 arttırıyoruz.
            }
        }
    }
    int arr[sumnode][2];	//2 boyutlu bir array. ilk sütunu harf, ikinci sütunu frekans degeri
    iter = baslangic;	//dugumu dolasmak icin iter adında bir dugum olusturduk
    i = 0;
    while (iter != NULL)	//dugumu array e yazıyoruz
    {
        arr[i][0] = iter->harf;
        arr[i][1] = iter->freq;
        printf("%c %d\n", arr[i][0], arr[i][1]);
        iter=iter->next;
        i++;
    }

        insertionSort(arr, sumnode);	//arrayi insertion sort algoritmasi ile siraliyoruz. asagidaki yorum satirinda siralanmis halini kontrol ettim.
//        printf("Siralanmis hali: ");
//        for (i = 0; i < sumnode; i++)
//        {
//            printf("%c = %d \t", arr[i][0], arr[i][1]);
//        }
        printf("\n");printf("\n");
    
        baslangic = insert(arr,sumnode);	//arrayi linkli liste yapisina yerlestirme fonksiyonu. 
    	baslangic= huffman(baslangic,sumnode);		//huffman agaci
        
		printf("\n");printf("\n");
    
        print_agac(baslangic);

    return 0;
}


void insertionSort(int arr[][2], int n)		//arrayimize insertionsort algoritması uyguladık.
{
    int i, deger, j;
    char harf;
    for (i = 1; i < n; i++)
    {
        deger = arr[i][1];
        harf = arr[i][0];
        j = i - 1;

        while (j >= 0 && arr[j][1] > deger)		//arrayin frekansının bulunduğu sütun ile karşılaştırma yapıyoruz
        {
            arr[j + 1][1] = arr[j][1];
            arr[j + 1][0] = arr[j][0];
            j = j - 1;
        }
        arr[j + 1][1] = deger;
        arr[j + 1][0] = harf;
    }
}



struct node *insert(int arr[][2],int size)			//linkli liste yapisini olusturdugumuz fonksiyon
{ //{{'a',a},{'b',b},{'c',c},{'d',d},{'e',e}.....};
    int i;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *curr;	//head in degerini kaybetmemek icin 
    curr = head;
    for (i = 0; i < size; i++)
    {
        curr->harf = arr[i][0];
        curr->freq = arr[i][1];
        curr->left = NULL;
        curr->right = NULL;
        curr->next = (struct node *)malloc(sizeof(struct node));	//her seferinde sonrası icin yeni bir node acacak... taa ki en son duguma gelene kadar
        if (i == size-1)	//size-1 'de son dugume gelmis oldu ve next'i NULL olmali
            curr->next = NULL;

        curr = curr->next; 	//linkli listeyi dolasiyoruz.
    }
    printNode(head);	//elemanlari yazdiralim
    return head;
}


void printNode(struct node *head)	//olusturdugumuz linkli listenin dugum yapisinin ekrana temsili yazilmasi
{
    struct node *curr;
    curr = head;
    printf("Dugum yapisi:\n");
    while (curr->next != NULL)
    {
        printf("%c%d  ->  ", curr->harf, curr->freq);
        curr = curr->next;
        if (curr->next == NULL)
        {
            printf("%c%d\t\n", curr->harf, curr->freq);
        }
    }
}


struct node *huffman(struct node *head,int size)	//huffman agacini olusturdugumuz fonksiyon
{
    struct node *iter, *toplam;
    int i;
    for (i = 0; i < size; i++)		
    {
        if (i != size - 1)	//son elemana gelmediyse topla fonk nu cagir
            toplam = topla(head);
        iter = head;
        while (iter != NULL)
        {
            if (iter->next != NULL)
            {
                if (iter->next->freq > toplam->freq && iter != toplam && toplam->freq >= iter->freq)
                {
                    toplam->next = iter->next;		//buyuk oldugu yere ulasip toplami o araya soktuk.
                    iter->next = toplam;			//iter->toplam->iternext seklinde olusturduk yani.
                }
            }
            else if (iter->next == NULL && toplam->freq >= iter->freq && toplam != iter)
            {
                toplam->next = iter->next;		//next'i null iken toplamın freqi iterin freqinden buyukse yine toplami o araya sokacagiz yani toplamin nexti null olacak
                iter->next = toplam;			//iter'in nexti de null yerine toplami gosterecek.
            }
            iter = iter->next;
        }
        if (i != size - 1)
            head = head->next->next;	//cunku ilk 2 en kucuk degeri yok etmek istedigimiz için head i 2 deger sonrasindan baslatiyoruz.
    }
    return head;
}



struct node *topla(struct node *head)	//huffman agacini olustururken en kucuk dugumleri toplamak icin kullandigimiz fonksiyon
{
    struct node *toplam = (struct node *)malloc(sizeof(struct node));
    toplam->freq = head->freq + head->next->freq; //degerler siralanmis oldugu icin bastaki iki değer en kucuk iki değerdir. yani head ve head->next in freqleri 
    toplam->harf = '\0';		//topladığımızda harf degeri bos oluyor.
    toplam->left = head;
    toplam->right = head->next;
    return toplam;		//toplamın next'ini huffman fonksiyonunda ayarlayacağız.
}


void print_agac(struct node* root) 	//agacın yuksekligi kadar donup o seviyedekileri yazdiran fonksiyon
{ 
    int h = tree_height(root); 
    int i; 
    printf("\nHuffman agaci:\n\n");
    for (i=1; i<=h; i++){
        printLevel(root, i);
		printf("\n\n"); 
	}
} 


int tree_height(struct node *node)
{
    if (node == NULL)	//node null ise yukseklik 0 diyelim sonra bir ust node un yani kokun yuksekligi 1 fazlasi olacak.
        return 0;
    else
    {
        int leftheight = tree_height(node->left); 	//null'a ulasana kadar gidecek ve null iken yukseklik 0 olacak.
        int rightheight = tree_height(node->right);	//null'a ulasana kadar gidecek ve null iken yukseklik 0 olacak.
        if (leftheight > rightheight)
            return (leftheight + 1);	//buyuk olanin uzunlugu agacın uzunlugu kabul edilecek
        else
            return (rightheight + 1);	//birbirine esitse right ya da left farketmez 1 artırıyoruz. l<r ise left'i 1 arttırıyoruz ki buyugun uzunluguna esit olsun.
    }
}


void printLevel(struct node* root, int level) //ağacın ilgili seviyesini yazdıran fonksiyon
{ 
    if (root == NULL && level == 1) //son elemansa ve son levelsa sadece bir null(bosluk) yazacak
        printf("   ");
    else if (root == NULL && level != 1) //root nullsa ama en alt seviyeye gelmemisse null'ın ayaklarını ekrana yazar (2 tane null olarak)
        printf("      ");
    else if (level == 1) //level 1se ve root null degilse o seviyenin frekans ve harf degerlerini ekrana yazar
        printf("%d%c  ", root->freq, root->harf); 
    else if (level > 1) //en alt seviyede degilse recursive şekilde ilerler...
    { 
        printLevel(root->left, level-1); 
        printLevel(root->right, level-1); 
    } 
}
