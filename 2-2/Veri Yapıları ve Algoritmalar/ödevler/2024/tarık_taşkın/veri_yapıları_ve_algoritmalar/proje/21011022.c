#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Linkli liste yapisi.
struct NODE{
	char vertex;
	int weight;
	struct NODE* next;
};

//Graf bilgilerinin tutuldugu yapi.
struct GRAPH{
	int vertices; //Graftaki toplam dugum sayisi.
	struct NODE** list; //Dugumlere ait linkli listelerin tutuldugu dizi (Adjacency List).
};

//Grafta bulunan cokgenlerin tutuldugu yapi.
struct POLYGONS{
	char* path; //Siradaki cokgenin dugumlerinin tutuldugu dizi.
	char** paths; //Tum cokgenlerin dugumlerinin tutuldugu matris.
	int totalPolygons; //Toplam cokgen sayisi.
	int* lengths; //Cokgenlerin uzunluklarinin tutuldugu dizi.
	int* count; //Cokgenlerin kenar/kose sayisi.
};

struct GRAPH* getGraph();
void addList(struct NODE*** list, int* vertices, char src, char dest, int weight);
struct NODE* createNode(char vertex, int weight);
void addNode(struct NODE* node, char vertex, int weight);
struct NODE* searchNode(struct NODE** list, int vertices, char src);
void printList(struct NODE** list, int vertices);
void findPolygons();
struct POLYGONS* initialize(int vertices);
void dfs(struct GRAPH* graph, char** visited, char start, char current, int count, int length, struct POLYGONS* polygons);
void addPolygon(struct POLYGONS* polygons, int count, int length);
struct NODE* findList(struct GRAPH* graph, char current);
void markVisited(char** visited, int vertices, char src, char sign);
char getSign(char** visited, int vertices, char src);
void printPolygon(struct POLYGONS* polygons, int vertices);
void freeGraph(struct GRAPH** graph);
void freePolygons(struct POLYGONS** polygon);

int main(){
	int choice;
	
	do{
		printf("1- Graftaki Cokgenleri Bul\n");
		printf("0- Cikis\n");
		printf("Seciminiz : ");
		scanf("%d", &choice);
		
		if(choice == 1){ //Secimin '1' olmasiyla graftaki cokgenler bulunur.
			findPolygons();
		}else if(choice == 0){
			printf("\nCikis yapiliyor...");
		}else{
			printf("Hatali secim yaptiniz!\n\n");
		}
	}while(choice); //Secim 0'dan farkli oldugu surece dongu devam eder.

	return 0;
}

/*
@brief Graf bilgileri dosyadan alinir, sirali olacak seekilde adjacency list olusturulur ve ekrana yazdirilir.

@return Dosyadan okunan graf dondurulur, eger dosya okunamiyorsa NULL dondurulur.
*/
struct GRAPH* getGraph(){
	FILE* file;
	int weight;
	char src, dest;
	struct GRAPH* graph;
	char* fileName = (char*) malloc(256*sizeof(char));
	
	printf("\nDosya Adi: ");
	scanf("%s", fileName);
	
	file = fopen(fileName, "r");	
	if(file == NULL){ //Dosyanin acilamamasi durumunda menuye geri donulur.
		printf("Dosya acilamadi!\n\n");
		return NULL;
	}
	
	graph = (struct GRAPH*) malloc(sizeof(struct GRAPH));	
	graph->vertices = 0;
	graph->list = NULL;
	
	while(fscanf(file," %c %c %d",&src, &dest, &weight) != EOF){
		addList(&graph->list, &graph->vertices, src, dest, weight);
	}	
	printList(graph->list, graph->vertices);
	
	fclose(file);
	free(fileName);
	
	return graph;
}

/*
@brief Verilen kenar bilgileri adjacency list'e eklenir.

@param list, kenar bilgilerinin eklenecegi adjacency list'in adresi.
@param vertices, graftaki toplam dugum sayisinin adresi.
@param src, kenarin kaynak dugumu.
@param dest, kenarin hedef dugumu.
@param weight, kenarin agirlik bilgisi.

@return 
*/
void addList(struct NODE*** list, int* vertices, char src, char dest, int weight){
	if((*list) == NULL){ //Liste yoksa olusturulur, kaynak ve hedef dugumler listeye eklenir.
		(*list) = (struct NODE**) malloc(2*sizeof(struct NODE*));
		struct NODE* srcNode = createNode(src, 0);
		struct NODE* destNode = createNode(dest, 0);
		addNode(srcNode, dest, weight);
		addNode(destNode, src, weight);
		
		if(src < dest){ //Listenin sirali olmasi icin alfabetik olarak once gelen dugum once eklenir.
			(*list)[(*vertices)++] = srcNode;
			(*list)[(*vertices)++] = destNode;
		}else{
			(*list)[(*vertices)++] = destNode;
			(*list)[(*vertices)++] = srcNode;		
		}
	}else{ //Kaynak ve hedef dugumler adjacency list'e eklenir.
		struct NODE* srcNode = searchNode(*list, *vertices, src); //Kaynak dugume ait linkli listeye ulasilir.
		struct NODE* destNode = searchNode(*list, *vertices, dest); //Hedef dugume ait linkli listeye ulasilir.

		if(srcNode == NULL){ //Kaynak dugume ait linkli liste yoksa olusturulur ve adjacency list'e eklenir.
			int i = 0, j;
			//Yeni eklenecek linkli liste sirayi bozmayacak sekilde adjacency list'e yerlestirilir.
			while(i<(*vertices) && (*list)[i]->vertex < src){ 
				i++;
			} 
			(*list) = realloc(*list, ((*vertices) + 1)*sizeof(struct NODE*));
			for(j=(*vertices);j>i;j--){
				(*list)[j] = (*list)[j-1];
			}

			srcNode = createNode(src, 0);
			addNode(srcNode, dest, weight);
			(*list)[i] = srcNode;
			(*vertices)++;
		}else{ //Kaynak dugume ait linkli liste varsa linkli listeye hedef dugum eklenir.
			addNode(srcNode, dest, weight);
		}
		
		if(destNode == NULL){ //Hedef dugume ait linkli liste yoksa olusturulur ve adjacency list'e eklenir.
			int i = 0, j;
			//Yeni eklenecek linkli liste sirayi bozmayacak sekilde adjacency list'e yerlestirilir.
			while(i<(*vertices) && (*list)[i]->vertex < dest){
				i++;
			}
			(*list) = realloc(*list, ((*vertices) + 1)*sizeof(struct NODE*));
			for(j=(*vertices);j>i;j--){
				(*list)[j] = (*list)[j-1];
			}			

			destNode = createNode(dest, 0);
			addNode(destNode, src, weight);
			(*list)[i] = destNode;
			(*vertices)++;
		}else{ //Hedef dugume ait linkli liste varsa linkli listeye kaynak dugum eklenir.
			addNode(destNode, src, weight);
		}
	}
}

/*
@brief Linkli listeye eklenmek uzere yeni bir dugum olusturur.

@param vertex, grafta bulunan kaynak/hedef dugum.
@param weight, kenarin agirligi.

@return Olusturulan dugumun adresi dondurulur.
*/
struct NODE* createNode(char vertex, int weight){
	struct NODE* newNode = (struct NODE*) malloc(sizeof(struct NODE));
	newNode->vertex = vertex;
	newNode->weight = weight;
	newNode->next = NULL;
	
	return newNode;
}

/*
@brief Verilen dugumu linkli listeye sirali bir bicimde ekler.

@param node, linkli listeye eklenecek dugum.
@param vertex, grafta bulunan kaynak/hedef dugum.
@param weight, kenarin agirligi.

@return
*/
void addNode(struct NODE* node, char vertex, int weight){
	struct NODE* prev = node;
	struct NODE* temp = node->next;
	
	//Eklenecek dugumun listedeki yerini bulur.
	while(temp != NULL && temp->vertex < vertex){
		prev = temp;
		temp = temp->next;		
	}
	
	prev->next = createNode(vertex, weight);
	if(temp != NULL){
		prev->next->next = temp;
	}
}

/*
@brief Verilen dugume ait linkli listeyi adjacency list'te binary search ile bulur.

@param list, adjacency list.
@param vertices, grafta bulunan toplam dugum sayisi.
@param src, adjacency list'te aranan dugum.

@return Verilen dugume ait linkli listeyi dondurur, dugume ait linkli liste yoksa NULL dondurur.
*/
struct NODE* searchNode(struct NODE** list, int vertices, char src){
	int first = 0;
	int last = vertices-1;
	int mid = last/2;
	
	while(first<=last && list[mid]->vertex != src){
		if(list[mid]->vertex < src){
			first = mid + 1;
		}else{
			last = mid - 1;
		}
		mid = (last + first) / 2;
	}
	
	if(list[mid]->vertex == src){
		return list[mid];
	}	
	return NULL;
}

/*
@brief Verilen adjacency list'i ekrana yazdirir.

@param list, adjacency list.
@param vertices, grafta bulunan toplam dugum sayisi.

@return
*/
void printList(struct NODE** list, int vertices){
	int i;
	struct NODE* temp;
	
	printf("\n\tAdjacency List\n");
	for(i=0;i<vertices;i++){
		temp = list[i];
		printf("%c ", temp->vertex);
		temp = temp->next;
		while(temp != NULL){
			printf("-> %c(%d) ", temp->vertex, temp->weight);
			temp = temp->next;
		}
		printf("\n");
	}
	printf("\n");
}

/*
@brief Dosyadan alinan graftaki cokgenleri bulur ve ekrana yazdirir.

@return
*/
void findPolygons(){
	int i,j;
	char** visited; //visited[Kose Sayisi][2]
	struct POLYGONS* polygons;
	struct GRAPH* graph = getGraph();
	
	if(graph == NULL){ //Dosya okunamadiysa ana menuye donulur.
		return;
	}
	
	//visited matrisinin 0. sutununda dugum bilgisi, 1. sutununda ise baska dugumler tarafindan gezilme bilgisi saklanir.
	visited = (char**) malloc((graph->vertices)*sizeof(char*));
	for(i=0;i<graph->vertices;i++){
		visited[i] = (char*) malloc(2*sizeof(char));
		for(j=0;j<graph->vertices;j++){
			visited[i][0] = graph->list[i]->vertex;
			visited[i][1] = '0';
		}
	}
	
	polygons = initialize(graph->vertices);	
	
	//Graftaki her dugum sirayla baslangic dugum olacak sekilde gezilir ve
	//graftaki cokgenler bulunur, bir sonraki dugume gecmeden once dugumun gezilme 
	//durumu '1' olarak isaretlenir ve diger dongulerde bu dugum gezilmez. Boylece
	//ayni cokgen birden fazla kez bulunmaz.
	for(i=0;i<graph->vertices;i++){
		dfs(graph, visited, graph->list[i]->vertex, graph->list[i]->vertex, 0, 0, polygons);
		
		//Siradaki dugumler '0' ve '1' disinda ayni zamanda da kaynak dugum ile de isaretlenebildiginden
		//dolayi dfs() fonksiyonu icersinde her dugum gezildikten sonra '0' olarak isaretlenemeyecegi icin
		//siradaki dugumler '0' ile isaretlenir.
		for(j=i+1;j<graph->vertices;j++){
			visited[j][1] = '0';
		}
		visited[i][1] = '1';
	}	
	printPolygon(polygons, graph->vertices); //Grafta bulunan cokgenler ekrana yazdirilir.
	
	//Olusturulan dinamik yapilar bellekten temizlenir.
	for(i=0;i<graph->vertices;i++){
		free(visited[i]);
	}
	free(visited);
	freeGraph(&graph);
	freePolygons(&polygons);
}

/*
@brief Grafta bulunan cokgenlerin kaydedildigi struct yapisini baslatir.

@param vertices, grafta bulunan toplam dugum sayisi.

@return Baslatilan struct yapisi dondurulur.
*/
struct POLYGONS* initialize(int vertices){
	struct POLYGONS* polygons = (struct POLYGONS*) malloc(sizeof(struct POLYGONS));
	polygons->path = (char*) calloc(vertices + 1, sizeof(char)); //Bir cokgenin kenar sayisi maks dugum sayisi kadar olabilir.
	polygons->count = (int*) calloc(polygons->totalPolygons+1, sizeof(int));
	polygons->totalPolygons = 0;
	polygons->lengths = (int*) calloc(polygons->totalPolygons+1, sizeof(int));
	polygons->paths = (char**) calloc(polygons->totalPolygons+1, sizeof(char*));
	
	return polygons;
}

/*
@brief Verilen graftaki cokgenleri ozyinemeli bir sekilde bulur.

@param graph, cokgenlerin arandigi graf.
@param visited, graftaki her bir dugumun gezilme durumunu belirten matris.
@param start, cokgenin baslangic dugumu.
@param current, grafta gezinti sonrasi ulasilan dugum.
@param count, cokgenin kenar sayisi.
@param length, cokgenin kenar uzunluklari toplami.
@param polygons, grafta bulunan cokgenlerin bilgilerinin tutuldugu yapi.

@return 
*/
void dfs(struct GRAPH* graph, char** visited, char start, char current, int count, int length, struct POLYGONS* polygons){
	if(start==current && count>2){ //Grafta gezinti sonrasi baslangic dugumune ulasildiysa ve kenar sayisi en az 3 ise cokgen bilgileri kaydedilir.
		addPolygon(polygons, count, length);	
		return;
	}else if(start==current && count != 0){ //Grafta gezinti sonrasi baslangic dugumune ulasildiysa ve kenar sayisi 3'ten az ise geri donulur.
		return; //Fonskiyon ilk cagrildiginda count=0 ve start=current olacagindan algoritmaya devam edilmelidir.
	}
	
	struct NODE* currentList = findList(graph, current); //Ulasilan dugume ait linlkli liste bulunur.
	polygons->path[count] = currentList->vertex; //Ulasilan dugum cokgenin dugumlerinin tutuldugu diziye eklenir.
	currentList = currentList->next; 
	while(currentList != NULL){ //Linkli listedeki tum dugumler gezilir.
		if(currentList->vertex == start || getSign(visited, graph->vertices, currentList->vertex) == '0'){
			if(start == current){ //Baslangic dugumune komsu olan dugumler baslangic dugumuyle isaretlenir. Boylece her cokgen bir kez gezilmis olur.
				markVisited(visited, graph->vertices, currentList->vertex, start);
			}else{//Diger dugumler '1' ile isaretlenir.
				markVisited(visited, graph->vertices, currentList->vertex, '1');
			}

			polygons->path[count+1] = currentList->vertex; //Dugumun komsu dugumleri cokgenin dugumlerinin tutuldugu diziye eklenir.
			dfs(graph, visited, start, currentList->vertex, count+1, length+currentList->weight, polygons);
			
			if(start != current){ //Baslangic dugumune komsu olmayan dugumler '1' ile isaretlenip dfs() cagirildiktan sonra tekrar '0' ile isaretlenir.
				markVisited(visited, graph->vertices, currentList->vertex, '0');
			}
		}		
		currentList = currentList->next;
	}
}

/*
@brief DFS algoritmasi sonucu grafta bulunan cokgene ait bilgileri ilgili yapiya kaydeder.

@param polygons, grafta bulunan cokgenlerin bilgilerinin tutuldugu yapi.
@param count, cokgenin kenar sayisi.
@param length, cokgenin kenar uzunluklari toplami.

@return 
*/
void addPolygon(struct POLYGONS* polygons, int count, int length){
	polygons->count[polygons->totalPolygons] = count;
	polygons->lengths[polygons->totalPolygons] = length;
	polygons->paths[polygons->totalPolygons] = strdup(polygons->path);
	polygons->totalPolygons = polygons->totalPolygons + 1;
	
	polygons->paths = realloc(polygons->paths, (polygons->totalPolygons+1)*sizeof(struct POLYGONS*));
	polygons->lengths = realloc(polygons->lengths, (polygons->totalPolygons+1)*sizeof(int));
	polygons->count = realloc(polygons->count, (polygons->totalPolygons+1)*sizeof(int));
}

/*
@brief DFS algoritmasi sonucu ulasilan dugume ait linkli listeyi adjacency list'te binary search ile bulur.

@param graph, cokgenlerin arandigi graf.
@param current, grafta gezinti sonrasi ulasilan dugum.

@return Ulasilan dugume ait linkli listeyi dondurur.
*/
struct NODE* findList(struct GRAPH* graph, char current){
	int first = 0;
	int last = graph->vertices-1;
	int mid = last/2;
	
	while(first<=last && graph->list[mid]->vertex != current){
		if(graph->list[mid]->vertex < current){
			first = mid + 1;
		}else{
			last = mid - 1;
		}
		mid = (last + first) / 2;
	}
	
	if(graph->list[mid]->vertex == current){
		return graph->list[mid];
	}	
	return NULL;
}

/*
@brief Verilen dugumun isaretini verilen isaret ile isaretler.

@param visited, graftaki her bir dugumun gezilme durumunu belirten matris.
@param vertices, grafta bulunan toplam dugum sayisi.
@param src, isaretlenecek olan dugum.
@param sign, dugumun yeni isareti.

@return
*/
void markVisited(char** visited, int vertices, char src, char sign){
	int first = 0;
	int last = vertices-1;
	int mid = last/2;
	
	while(first<=last && visited[mid][0] != src){
		if(visited[mid][0] < src){
			first = mid + 1;
		}else{
			last = mid - 1;
		}
		mid = (last + first) / 2;
	}
	
	if(visited[mid][0] == src){
		visited[mid][1] = sign;
	}
}

/*
@brief Verilen dugumun isaretini binary search ile bulur.

@param visited, graftaki her bir dugumun gezilme durumunu belirten matris.
@param vertices, grafta bulunan toplam dugum sayisi.
@param src, isareti istenen dugum.

@return Verilen dugumun isaretini dondurur, eger dugum matriste yoksa '0' dondurur.
*/
char getSign(char** visited, int vertices, char src){
	int first = 0;
	int last = vertices-1;
	int mid = last/2;
	
	while(first<=last && visited[mid][0] != src){
		if(visited[mid][0] < src){
			first = mid + 1;
		}else{
			last = mid - 1;
		}
		mid = (last + first) / 2;
	}
	
	if(visited[mid][0] == src){
		return visited[mid][1];
	}	
	return 0;
}

/*
@brief Grafta bulunan toplam cokgen sayisini ve bu cokgenlerin kenarlarini ekrana yazdirir.

@param polygons, grafta bulunan cokgenlerin bilgilerinin tutuldugu yapi.
@param vertices, grafta bulunan toplam dugum sayisi.

@return
*/
void printPolygon(struct POLYGONS* polygons, int vertices){
	int i,j,k;
	int count;
	
	if(polygons->totalPolygons == 0){
		printf("Herhangi bir cokgen bulunamadi!\n\n");
		return;
	}
	
	printf("Sekil Sayisi: %d\n", polygons->totalPolygons);
	for(i=3;i<vertices+1;i++){
		count = 0;
		for(j=0;j<polygons->totalPolygons;j++){
			if(polygons->count[j] == i){
				count++;
			}			
		}
		if(count!=0){
			printf("%d'gen sayisi: %d\n", i, count);
		}		
	}
	printf("\n");
	
	for(i=3;i<vertices+1;i++){
		count = 0;
		for(j=0;j<polygons->totalPolygons;j++){
			if(polygons->count[j] == i){
				printf("%d. %d'gen: ", ++count, polygons->count[j]);
				for(k=0;k<polygons->count[j]+1;k++){
					printf("%c ",polygons->paths[j][k]);
				}
				printf("Uzunluk: %d\n",polygons->lengths[j]);
			}			
		}
		if(count){
			printf("\n");
		}		
	}
}

/*
@brief Graf bilgilerini bellekten temizler.

@param graph, graf bilgilerinin tutuldugu yapi.

@return
*/
void freeGraph(struct GRAPH** graph){
	int i;
	int vertices = (*graph)->vertices;
	struct NODE* temp;
	
	for(i=0;i<vertices;i++){
		while((*graph)->list[i] != NULL){
			temp = (*graph)->list[i];
			(*graph)->list[i] = (*graph)->list[i]->next;
			free(temp);
		}
	}
	free((*graph)->list);
	free(*graph);
}

/*
@brief Bulunan cokgen bilgilerini bellekten temizler.

@param polygon, cokgen bilgilerinin tutuldugu yapi.

@return
*/
void freePolygons(struct POLYGONS** polygon){
	int i;
	int totalPolygon = (*polygon)->totalPolygons;
	
	free((*polygon)->path);
	free((*polygon)->lengths);
	free((*polygon)->count);
	
	for(i=0;i<totalPolygon;i++){
		free((*polygon)->paths[i]);
	}
	free((*polygon)->paths);
	free(*polygon);
}
