#include <stdio.h>
#define N 5000
int main(void)
{
FILE *fp;
char text[N];
/********* degisken tanimlari ************/
int i=0,j=0,wordCount=0;


/********* degisken tanimlari sonu ************/
// Dosyayi açma
if ((fp = fopen ("soru.txt", "r")) == NULL) {
printf("Dosya açma hatasi!");
return 1;
}
// Dosyadan okuma
fgets(text, N-1, fp);
//printf("%s\n", text);

/*
* text karakter dizisi degiskeninde dosyadan okunan metin yer almaktadir.
* toplam kelime sayisinin hesabi ve bosluk temizleme islemleri -TERCIHEN-
* bu dizi üzerinde yapilmalidir. Harici dizi kullanimi önerilmemektedir.
*/
/********* kod blogu ************/


//while loop ile metnin sonuna kadar
while(text[i] != '\0'){
	//bosluk olmadligi surece siradaki karakter i indisinden j indisine atar
	if(text[i] != ' '){
		text[j] = text[i];
		i++;
		j++;
	}else{
	// eger bosluk varsa kelime sayisini bir artirir
		wordCount++;
		text[j]= text[i];//bir bosluk da j indisine atanir
		while(text[i] == ' '){
		//sonraki tum bosluklar gecilir
			i++;
		}
		j++;
	}

}

//aradaki bosluklar silindigi icin metin kisalmistir. 
//bu nedenle yeni metnin sonunda yer alan eski metinden kalan karakterler silinmelidir.
for(j;j<i;j++){
	text[j] = '\0';
}

printf("%s\n", text);
//wordCount sayisi kelime sonrasi bosluk sayisina gore arttigi icin son kelime sonrasi bolsuk bulunmamasi durumunda 1 artirilarak sonuca varilir

printf("\nNumber of Words:\t%d",wordCount);

/********* kod blogu sonu ************/
// Dosyayi kapama
fclose(fp);
return 0;
}
