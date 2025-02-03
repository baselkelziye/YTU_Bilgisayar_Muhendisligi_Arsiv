#include<stdio.h>
#include<string.h>

struct PRODUCT{
	int code;
	char name[20];
	float unitPrice;
	float unitPriceKg;
};

void showProducts(struct PRODUCT products[],int size);
float calculatePrice(int amount, float unitPrice);
float calculateDiscountedPrice(float sum,int (*discountPercent)(float sum));
int findDiscountPercent(float sum);

int main(){
	int i, choice, productCode, amount, control;
	float sum=0;
	char continueShopping;
	
	struct PRODUCT products[6];
	
	products[0].code=1;
	strcpy(products[0].name,"domates");
	products[0].unitPrice=8.25;
	products[0].unitPriceKg=23.75;
	
	products[1].code=2;
	strcpy(products[1].name,"biber");
	products[1].unitPrice=6.25;
	products[1].unitPriceKg=29.50;
	
	products[2].code=3;
	strcpy(products[2].name,"sut");
	products[2].unitPrice=15.85;
	products[2].unitPriceKg=27.15;
	
	products[3].code=4;
	strcpy(products[3].name,"peynir");
	products[3].unitPrice=23.00;
	products[3].unitPriceKg=95.50;
	
	products[4].code=5;
	strcpy(products[4].name,"muz");
	products[4].unitPrice=13.45;
	products[4].unitPriceKg=45.50;
	
	products[5].code=6;
	strcpy(products[5].name,"armut");
	products[5].unitPrice=5.50;
	products[5].unitPriceKg=20.15;
	
	do{
		control=1;
		
		showProducts(products,6);
		
		do{
			if(!control){
				printf("\nHatali urun kodu girdiniz!");
			}
			printf("\nUrun kodu giriniz: ");
			scanf("%d",&productCode);
			if(productCode>products[5].code || productCode<products[0].code)
				control=0;
			else
				control=1;
		}while(!control);
	
		do{
			if(!control){
				printf("\nHatali alis tipi girdiniz!");
			}
			printf("Alis tipi(1: Birim  2: kilo): ");
			scanf("%d",&choice);
			if(choice<1 || choice>2)
				control=0;
			else
				control=1;
		}while(!control);
		
		printf("Miktar giriniz: ");
		scanf("%d",&amount);
		
		if(choice==1){
			sum+=calculatePrice(amount,products[productCode-1].unitPrice);
		}
		else if(choice==2){
			sum+=calculatePrice(amount,products[productCode-1].unitPriceKg);
		}
		
		printf("\nToplam Tutar: %.2f TL",sum);
		
		printf("\nDevam etmek istiyor musunuz? (E/H): ");
		scanf(" %c",&continueShopping);
		
	}while(continueShopping=='E' || continueShopping=='e');
	
	printf("\nToplam Tutar: %.2f TL",sum);
	printf("\nIndirimli Tutar: %.2f TL",calculateDiscountedPrice(sum,findDiscountPercent));
	printf("\nProgramdan cikis yapiliyor");
	
	return 0;
}

float calculateDiscountedPrice(float sum,int (*discountPercent)(float sum)){
	return sum*(100-findDiscountPercent(sum))/100;
}

int findDiscountPercent(float sum){
	if(sum<50)
		return 0;
	else if(sum>=50 && sum<100)
		return 5;
	else if(sum>=100)
		return 10;
}

float calculatePrice(int amount, float unitPrice){
	return amount*unitPrice;
}

void showProducts(struct PRODUCT products[], int size) {
    int i;
	printf("\n%-10s%-20s%-15s%-15s\n", "Kod", "Urun adi", "Birim fiyat", "Kilo fiyat");

    for (i = 0; i < size; i++) {
        printf("%-10d%-20.10s%-15.2f%-15.2f\n", products[i].code, products[i].name, products[i].unitPrice, products[i].unitPriceKg);
    }
}
