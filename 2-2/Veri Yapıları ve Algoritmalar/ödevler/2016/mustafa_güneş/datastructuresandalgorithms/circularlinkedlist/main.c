#include <stdio.h>

void display(int arr[], int deleted[], int n);
void delete(int arr[], int link[], int index);
void game(int arr[], int link[], int M, int n, int deleted[]);

int main(){
	/*int arr[] = {0,1,2,3,4,5,6};
	int link[] = {1,2,3,4,5,6,0};
	int deleted[] = {0,0,0,0,0,0,0};
	int n = 7;
	int M = 3;*/
	
	int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int link[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	int deleted[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int n = 16;
	int M = 5;
	
	game(arr, link, M, n, deleted);
	display(arr, deleted, n);
	
	return 0;
}

void game(int arr[], int link[], int M, int n, int deleted[]){
	 int i;
	 int index = 0;
	 
	 while(n != M){ // 
	 	for(i=0; i<M-2; i++)
	 		index = link[index];
	 		
	 	deleted[arr[link[index]]] = 1;
	 	delete(arr, link, index);
	 	index = link[index];
	 	n--;
	 }
}

//her silme işleminde n bir azalacak
//index, silinecek elemanı gösteren indistir
//index artık gosterdigi elemanin gosterdigi elemani gösterir
void delete(int arr[], int link[], int index){
	printf("\noyundan cikan:%d", arr[link[index]]);
	link[index] = link[arr[link[index]]];
}

void display(int arr[], int deleted[], int n){
	int i;
	for(i=0; i<n; i++){
		if(deleted[i] != 1)
			printf("\n%d", arr[i]);
	}
}
