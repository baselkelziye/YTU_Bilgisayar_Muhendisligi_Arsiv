#include<stdio.h>
#include<time.h>

//dizi yazdýrma fonksiyonu
void print_array(int fonk_arr[], int num){
	int i;
	for(i=0; i<num; i++){
	    printf("%d ", fonk_arr[i]);
	}
}
//histogram için 
void print_count_array(int fonk_num[], double fonk_arr[], int num){
	int i;
	for(i=0; i<num; i++){
		printf("%d: %lf \n", fonk_num[i], fonk_arr[i]);
	}
}

int main(){
	int i, j, n, example[20], arr[50000], arr_num[5], arr_line[5], bas, son, temp, max, count, a, b, c, d, e;
	
	double arr_time[5];
	srand(time(NULL));
	
	//zamansýz örnek		
	printf("\nORNEK:\n------\n\nEleman sayisi: ");
	scanf("%d", &n);
	printf("\n");
	bas=0;
	son=n-1; 	       
	printf("Rastgele elemanlar: ");                   	
	for(i=0; i<n; i++){
	    example[i]=rand()%100;
	    printf("%d ", example[i]);	    
    }
	printf("\n\n");
		
	while(bas<son){
		count=1;
		for(i=bas; i<son; i++){			
			if(example[i]>example[i+1]){
				//swap
                temp=example[i];
		        example[i]=example[i+1];
		        example[i+1]=temp;
		        printf("\t%d. swap: ", count);
		        print_array(example,n);
		        printf("\n");
		        count++;
			}
		}	
		count=1;
		printf("\n");			
		son--;			
		for(i=son; i>bas; i--){			
			if(example[i]<example[i-1]){
				//swap
				temp=example[i];
		        example[i]=example[i-1];
		        example[i-1]=temp;
		        printf("\t%d. swap: ", count);
		        print_array(example,n);
		        printf("\n");
		        count++;
			}
		}
		bas++;		
		printf("\n");
	}
	
	//zaman analizli kýsým	
	printf("\nDaha buyuk sayilarla ve Zamanlayici ile:\n");
	printf("------------------------------------------");		    
	
	count=0;    
	while(count<5){ //5 tane farklý büyüklükteki diziyi almak için
		printf("\n\nEleman sayisi: ");
		scanf("%d", &n);
		printf("\t\t\t");
	                          
	    bas=0;                                         
	    son=n-1;
	    for(i=0; i<n; i++){
		    arr[i]=rand()%100;
	    }
	
	    long before=clock(); //zamaný baþlatma
	
	    while(bas<son){ //bas=son durumu: dizide ortaya gelinmiþtir, sýralanmýþtýr.
	    	//saða gidiþ
		    for(i=bas; i<=son; i++){
			    if(arr[i]>arr[i+1]){
				    //swap
                    temp=arr[i];
		            arr[i]=arr[i+1];
		            arr[i+1]=temp;
			    }
		    }				
		    son--;
			
			//sola gidiþ
		    for(i=son; i>=bas; i--){
			    if(arr[i]<arr[i-1]){
				    //swap
				    temp=arr[i];
		            arr[i]=arr[i-1];
		            arr[i-1]=temp;
			    }
		    }
		    bas++;
	    }	
	    long after=clock(); //zamaný bitirme
	    double elapsed = (double) (after-before)/CLOCKS_PER_SEC;
	    arr_time[count]=elapsed;
	    printf("zaman: %lf saniye.\n\n", elapsed);
	    arr_num[count]=n; //histogramda kullanmak için
	    count++;
    }	
    printf("\n\n");
    print_count_array(arr_num,arr_time,count);
    
    //histogram satýr sayýsý hesaplama
    arr_line[0] = (double) arr_time[0]*10;
    max = arr_line[0];
    for(i=1; i<count; i++){
    	arr_line[i] = (double) arr_time[i] * 10;
    	if(arr_line[i]>max){
    		max=arr_line[i];
		}		
	}
	max=max/3; //daha küçük bir histogram için
		
	a = max-(arr_line[0])/3;
	b = max-(arr_line[1])/3;
	c = max-(arr_line[2])/3;
	d = max-(arr_line[3])/3;
	e = max-(arr_line[4])/3;
			
	printf("\n\n\nArr-1  Arr-2  Arr-3  Arr-4  Arr-5\n\n");
	
	//histogram
	for(i=0; i<max; i++){
		if(a>0){
			printf("       ");		
		}
		else printf("   |   ");
		
		if(b>0){
			printf("       ");		
		}
		else printf("   |   ");
		
		if(c>0){
			printf("       ");		
		}
		else printf("   |   ");
	
		if(d>0){
			printf("       ");		
		}
		else printf("   |   ");	
		
		if(e>0){
			printf("       ");		
		}
		else printf("   |   ");		
		a--;
	    b--;
	    c--;
	    d--;
	    e--;
	    printf("\n");
	}
	for(i=0; i<5; i++){
		printf(" %d ", arr_num[i]);
	}
}
