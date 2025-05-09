#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Disaridan verilen 2 adet N basamakli sayi ayri ayri linkli listelerde saklanmaktadir.
// Sayilari toplayip sonucu tek bir degiskende saklayip ekrana yazdiran programin C kodu asagida eksik verilmistir.

// Doldurulmasi gereken fonksiyonlar:
// -push: Verilen degeri linkli listenin basina ekler.
// -addLinkedLists: Iki linkli listedeki sayilari kucuk basamaktan baslayarak toplar,
// elde varsa (carry) tasima yapar ve sonucu tek bir int degisken olarak dondurur.

// Sayilar dizilerde (digits1, digits2) duz sirayla verilmistir (buyuk basamaktan kucuk basamaga).

//Girdi:  N:4
//Liste 1:   9->3->2->1->NULL (1239'u temsil eder, kucuk basamak basta)
//Liste 2:   8->1->3->4->NULL (4318'i temsil eder)

//Cikti:
//Sonuc: 5557

/////////////////////////////////////////////////////////////////////////////

//.c uzantili lab dosyanizi grupno_ogrenciNo_isim_soyisim.c seklinde isimlendiriniz.

//Ornek: GR1_25011000_Isim_Soyisim.c

//Lab sonunda hocalar izin verdiginde interneti acip asagidaki form linkine .c uzantili kodunuzu yukleyiniz.

//https://l24.im/fThRV

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void push(Node** headRef, int data) {
    Node* temp = createNode(data);
    temp->next = *headRef;
    *headRef = temp;
    
}

int addLinkedLists(Node* l1, Node* l2) {
    int sum = 0;
    int carry = 0;
    int power = 1;
    
    while (l1 != NULL && l2 != NULL){
        sum += (carry + (l1->data + l2->data) % 10) * power;
        carry = (l1->data + l2->data) / 10;
        power *= 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return sum;
}

/* yorumlar ansi hatasi veriyor*/
int main(void) {
    int N = 4;
    
    int digits1[] = {1,2,3,9};
    int digits2[] = {4,3,1,8};
    int i;
    
    Node* number1 = NULL;
    Node* number2 = NULL;
    
    for (i = 0; i < N; i++) {
        push(&number1, digits1[i]);
        push(&number2, digits2[i]);
    }

    int toplam = addLinkedLists(number1, number2);
    printf("Sonuc: %d\n", toplam);
    
    freeList(number1);
    freeList(number2);

    return 0;
}

