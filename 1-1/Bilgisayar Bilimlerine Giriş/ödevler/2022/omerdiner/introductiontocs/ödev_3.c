#include <stdio.h>
#define N 5000

int main(void){
	FILE *fp;
	char text[N];
	//deðiþken tanýmlarý
	int i, j , uzunluk=0 , kelimeSayisi=0;
	
	//dosyayý açma
	if ((fp = fopen ("soru.txt", "r")) == NULL) {
      printf("Dosya açma hatasý!");
      return 1;
    }
   //Dosyadan okuma
    fgets(text, N-1, fp);
    //printf("%s\n", text);
    
    //kod bloðu
    
    //dizi boyutu
    while(text[uzunluk]!='\0'){
    	     uzunluk=uzunluk+1;
	}
	
	//gereksiz bosluklarý teke indirme
	for(i=0;i<uzunluk;i++){
		
		if(text[i]==' ' && text[i+1]==' '){
			
			for(j=i;j<uzunluk;j++){
				text[j]=text[j+1];
			}
			
			uzunluk=uzunluk-1;
			i=i-1;
		}
		
	}
	
	//son karakteri null yapma
	if(text[uzunluk-1]==' '){
		text[uzunluk-1]='\0';
	}
	
	//kelime sayýsý bulma
	i=0;
	while(text[i]!='\0'){
		
		if(text[i]==' '){
			kelimeSayisi=kelimeSayisi+1;
		}
		
		i=i+1;
	}
	
	 kelimeSayisi=kelimeSayisi+1;
	 
	 //ilk karakter boþluksa kelime sayýsýný düzeltme
	 if(text[0]==' '){
	 	kelimeSayisi=kelimeSayisi-1;
	 }
	 
	//ekrana yazdýrma 
	printf("\nCikti:\n%s", text);
    printf("\nKelime Sayisi:%d",kelimeSayisi);
    
    //kod bloðu sonu


   // Dosyayý kapama
   fclose(fp);
  
   return 0;
	

}
