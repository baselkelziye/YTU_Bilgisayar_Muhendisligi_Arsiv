#include <stdio.h>
#include <stdlib.h>

int main(){
	char Main_Text[500]="I Want More Text To Search For in Main Text";	//\0
	char Searched[500];
	int Main_Text_Length;
	int Searched_Text_Length;
	int i;
	int j;
	int Control=0;
	printf("Aranacak Metini Giriniz?: ");
	scanf("%s",Searched);
	
	i=0;
	while(Main_Text[i]!='\0'){
		i++;
		Main_Text[i]=tolower(Main_Text[i]);
	}
	Main_Text_Length=i;
	
	i=0;
	while(Searched[i]!='\0'){
		i++;
		Searched[i]=tolower(Searched[i]);
	}
	Searched_Text_Length=i;
	
	
	for(i=0;i<Main_Text_Length-Searched_Text_Length+1;i++){
		j=0;
		while((j<Searched_Text_Length)&&(Searched[j]==Main_Text[i+j]))
			j++;
		
		if(j==Searched_Text_Length){
			printf("Bulundu %d'den %d'ye kadar\n",i+1,i+j+1);
			Control++;
		}
		
	}
	
	if(Control==0){
		printf("Aranan metin Bulunamadi");
	}else{
		printf("Aranan metin %d defa bulundu.",Control);
	}
	
	
	
	
	return 0;
}
