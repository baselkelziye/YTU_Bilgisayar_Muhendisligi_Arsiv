#include <stdio.h>
#include <stdlib.h>

struct Musteri{
	int siparisKodu;
	int ID;
	char ad[20];
	char urunTipi[20];
	char gun[15];
};

struct Liste* girdiAl(char *dosyaAdi);
void listeYazdir(struct Liste* list);

struct Liste{
	struct Musteri musteri;
	struct Liste *next;
};

int main(){
	struct Liste *list = (struct Liste*) malloc(sizeof(struct Liste));
	char dosyaAdi[] = "input.txt";
	list = girdiAl(dosyaAdi);
	listeYazdir(list);
	
	
	return 0;	
}

struct Liste* girdiAl(char *dosyaAdi){
	FILE *dosya = fopen(dosyaAdi, "r");
	if(dosya == NULL){
		printf("Dosya acilamadi.\n");
		return NULL;
	}
	
	struct Liste *list = (struct Liste*) malloc(sizeof(struct Liste));
	struct Liste *temp = list;
	
	while(!feof(dosya)){
		struct Musteri musteri;
		/*
		fread(&musteri.siparisKodu, sizeof(int), 1, dosya);
		fread(&musteri.ID, sizeof(int), 1, dosya);
		fread(musteri.ad, sizeof(char), sizeof(musteri.ad), dosya);
		fread(musteri.urunTipi, sizeof(char), sizeof(musteri.urunTipi), dosya);
		fread(musteri.gun, sizeof(char), sizeof(musteri.gun), dosya);
		musteri.ad[sizeof(musteri.ad) - 1] = '\0';
        musteri.urunTipi[sizeof(musteri.urunTipi) - 1] = '\0';
        musteri.gun[sizeof(musteri.gun) - 1] = '\0';
        */
        fscanf(dosya, "%d %d %s %s %s",&musteri.siparisKodu, &musteri.ID, musteri.ad, musteri.urunTipi, musteri.gun);
		printf("%d %d %s %s %s\n",musteri.siparisKodu, musteri.ID, musteri.ad, musteri.urunTipi, musteri.gun);
		temp->musteri = musteri;
		struct Liste *next = (struct Liste*) malloc(sizeof(struct Liste));
		temp->next = next;
		temp = next;		
	}
	
	temp->next = NULL;
	temp = NULL;
	
	fclose(dosya);
	return list;
}

void listeYazdir(struct Liste* list){
	struct Liste *temp = list;
	while(temp != NULL){
		printf("11: %d %d %s %s %s\n", temp->musteri.siparisKodu, temp->musteri.ID, temp->musteri.ad, temp->musteri.urunTipi, temp->musteri.gun);
		temp = temp->next;
	}
}
