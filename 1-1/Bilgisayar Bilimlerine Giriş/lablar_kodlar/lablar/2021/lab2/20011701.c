#include <stdio.h>
#define N 500


int main(){
	int i=0,j=0;
	char metin[N];
	printf("Duzeltilmesi istenen en fazla 500 karakter uzunlugundaki metni giriniz\n");
	gets(metin);
	
	if(metin[0] >= 'a' && metin[0]<='z' ){
		metin[0]= metin[0]-32;
	}
	
	while(metin[i] != NULL){
		if(metin[i] == '.'){
			if(metin[i+1] >= 'a' && metin[i+1]<='z'){
				metin[i+1]= metin[i+1]-32;
				i++;	
			}else if(metin[i+1]==' ' && (metin[i+2] >= 'a' && metin[i+2]<='z')){
					metin[i+2]= metin[i+2]-32;
					i++;
			}
		}
		i++;
	} 
	
	printf("\nCIKTI:\n");
	
	for(j=0;j<i;j++){
		printf("%c",metin[j]);
	}
	
	return 0;
	

}

