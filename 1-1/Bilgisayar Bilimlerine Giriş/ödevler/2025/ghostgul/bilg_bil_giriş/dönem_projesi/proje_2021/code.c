#include <stdio.h>
#define N 5000
int main(void)
{
 FILE *fp;
 char text[N];
 /********* deðiþken tanýmlarý ************/
 int count = 0;
 int i;
 char c = '.';
 int isWord = 0;
 /********* deðiþken tanýmlarý sonu ************/
 
 // Dosyayý açma
 if ((fp = fopen ("soru.txt", "r")) == NULL) {
 printf("Dosya açma hatasý!");
 return 1;
 }
 // Dosyadan okuma
 fgets(text, N-1, fp);
 printf("%s\n", text);
 printf("\n\n");
 /* 
 * text karakter dizisi deðiþkeninde dosyadan okunan metin yer almaktadýr.
 * toplam kelime sayýsýnýn hesabý ve boþluk temizleme iþlemleri -TERCÝHEN-
 * bu dizi üzerinde yapýlmalýdýr. Harici dizi kullanýmý önerilmemektedir. 
 */
 /********* kod bloðu ************/
 printf("cikti: ");
 for( i=0 ; c!='\0' ; i++ )
 {
	c = text[i];
	if(c!=' ' && c!='\n' && c!='\0'){
		if (isWord==0)
		{
			count++;
		}
		isWord = 1;
		printf("%c", c);
	}
	else{
		if(isWord==1){
			printf(" ");
		}	
		isWord = 0;
 	}
 }
 printf("\n\nKelime sayisi:%d", count);
 /********* kod bloðu sonu ************/
 // Dosyayý kapama
 fclose(fp);
 return 0;
}
