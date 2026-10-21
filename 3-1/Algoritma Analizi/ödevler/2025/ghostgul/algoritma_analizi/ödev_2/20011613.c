/*
@brief k-way divide and conquer algoritmasý implementasyonu.
Bu algoritma, verilen bir diziyi k parçaya bölerek sýralama iþlemi yapar.
Bölünen parçalar kendi içlerinde sýralanýr (mergsort gibi) ve sonra k parça birleþtirilir.
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*
@brief Verilen N boyutlarýna göre elemanlarý unique olmak üzere bir dizi oluþturulur.
@param arr oluþturulacak dizi
@param N   dizinin boyutu
@return void
*/
void generateUniqueArray(int *arr, int N) {
    int i;
    // 1'den N'e kadar olan sayýlarý yerleþtir diziye.
    for (i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

	// Knuth Shuffle algoritmasý ile basitçe diziyi karýþtýr.
    for (i = N - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/*
@brief K adeti kadar parçaladýðýmýz parçalarýn sýralanmýþ halini birleþtirme.
@param arr    ana dizi
@param temp   geçici dizi
@param start  ilk indeks
@param end    son indeks
@param k      parça sayýsý
@return void
*/
void mergePartsK(int *arr, int *temp, int start, int end, int k) {
    if (k <= 0 || start >= end) return;

    // parça boyutu ve kalan hesaplanmasý
    int total_elements = end - start + 1;
    int base_part_size = total_elements / k;
    int remainder = total_elements % k;

    // indeks ve limit dizileri için bellek alaný verilmesi
    int *indices = (int *)malloc(k * sizeof(int));
    int *limits = (int *)malloc(k * sizeof(int));
    
    // malloc problemi çýkarsa diye var
    if (!indices || !limits) {
        printf("Memory allocation failed\n");
        exit(1);
    }
	
    // her parçanýn ilk ve son indeksi belirleme
    int i;
	int curr_pos = start;
    for  (i = 0; i < k; i++) {
        indices[i] = curr_pos;
        int part_size = base_part_size + (i < remainder ? 1 : 0);
        curr_pos += part_size;
        limits[i] = curr_pos;
    }

    /* 
	@brief her adýmda k parçadan en küçük elemaný seç ve temp dizisine ekle.
	bu þekilde oluþan temp dizi, ilk verilen dizinin bizden istenildiði gibi sortlanmýþ haline bürünüyor.
	k tane parçayý ayný anda birleþtirmek için kullandým.
	*/
	int temp_pos = start;
    while (temp_pos <= end) {
        int min_val = INT_MAX;
        int min_idx = -1;

        for (i = 0; i < k; i++) {
        	// eðer þu anki parçada, eleman kaldýysa 
			// VE kalan eleman þu ana kadar bulunan min'den küçükse
			// Yeni min deðeri ve onun bulunduðu parçalarý indeksini güncelle
            if (indices[i] < limits[i] && (min_idx == -1 || arr[indices[i]] < min_val)) {
                min_val = arr[indices[i]];
                min_idx = i;
            }
        }
		
		// sortlanacak parça kalmadýysa ÇIK
        if (min_idx == -1) break;
        
		//  min deðeri temp dizisine ekle ve bir sonraki aramada bu parçadaki sýradaki elemana bakýlmasý için indeks konumunu ileri taþý
        temp[temp_pos++] = min_val;
        indices[min_idx]++;
    }

    // sonuçlarý ana diziye kopyalama
    for (i = start; i <= end; i++) {
        arr[i] = temp[i];
    }

    free(indices);
    free(limits);
}

/*
@brief 
@param arr	  ana dizi (bunu sýralicaz)
@param temp	  geçici dizi	
@param start  ilk indeks
@param end    son indeks
@param k      bölündüðü parça sayýsý
@return void
*/
void kWayMergeSort(int *arr, int *temp, int start, int end, int k) {
    if (start >= end) return;
    
    // toplam eleman sayýsýný VE kalan elemanlarý hesapla
    int total_elements = end - start + 1;
    // parçanýn toplam eleman sayýsý < k ise,, k = toplam eleman sayýsý yapar, 
    // bunun sayesinde k parçaya bölme iþlem eleman sayýsýna uygun olur.
    if (total_elements <= k) k = total_elements / 2;
    int base_part_size = total_elements / k;
    int remainder = total_elements % k;
	int i, j;
	
    // bölünmüþ parçalarý birer birer sýrala
    int curr_start = start;
    for (i = 0; i < k; i++) {
        int part_size = base_part_size + (i < remainder ? 1 : 0);
        int curr_end = curr_start + part_size - 1;
        
        // parçalarýn eleman sayýsý k'den düþük ise insertion sort kullan.
        // küçük dizilerde daha hýzlýdýr ve daha iyi performans saðlar.
        if (curr_start < curr_end) {			// düzgün  parçalanmýþ mý
            if (curr_end - curr_start < k) {
                //insertion sort
				for (j = curr_start + 1; j <= curr_end; j++) {
                    int key = arr[j];
                    int l = j - 1;
                    while (l >= curr_start && arr[l] > key) {
                        arr[l + 1] = arr[l];
                        l--;
                    }
                    arr[l + 1] = key;
                }
            } else { 
				// eðer parçalarýn eleman sayýsý 'k' veya daha büyükse buraya düþ
				// k-way mergeSort'u rekürsif olarak çaðýrarak bu alt parçayý daha küçük parçalara böl ve sýrala. 
                kWayMergeSort(arr, temp, curr_start, curr_end, k);
            }
        }
        curr_start = curr_end + 1;
    }

    // sýralanmýþ parçalarý birleþtirme algoritmasýný çaðýr
    mergePartsK(arr, temp, start, end, k);
}

int main() {
	// rastgele sayý üretimi için ayar
    srand((unsigned int)time(0));

    // özel test dizi ile kontrolü fonksiyonu ile ilk testi yap
    // testExample();

    printf("\nPerformans testleri basliyor...\n");

    // bize verilen N deðerlerini tanýmlama
    int N_values[] = { 100, 1000, 10000, 100000, 1000000, 10000000};
    int num_N = sizeof(N_values) / sizeof(N_values[0]);
    int i, k, j;
    
	// her bir N deðeri için sýralama algoritmasý test edilecek bu loopin içinde
    for (i = 0; i < num_N; i++) {
        int N = N_values[i];
        int *arr = (int *)malloc(N * sizeof(int));
        // Kontrol amaçlý, continue boþuna dönmesin diye kullanýldý.
		if (!arr) {
            printf("Memory allocation failed for N = %d\n", N);
            continue;
        }
		
		// rastgele unique elemanlardan oluþan bir dizi oluþturma fonksiyonunu çaðýr
        generateUniqueArray(arr, N);

        printf("\n==============================\n");
        printf("Tests for N = %d\n", N);
        printf("==============================\n");
		
		// bellek doðru ayrýldý mý kontrolü -- problem debuglamak için yazdým.
        int *temp = (int *)malloc(N * sizeof(int));
        // Kontrol amaçlý, continue boþuna dönmesin diye kullanýldý.
		if (!temp) {
            printf("Memory allocation failed for temp array\n");
            free(arr);
            continue;
        }

        // bize verilen her k-way deðeri için yazdýðýmýz divide and conquer algoritmasýný çalýþtýr ve süreyi ölçeceðiz
        for (k = 2; k <= 10; k++) {
            int *test_arr = (int *)malloc(N * sizeof(int));
            // Kontrol amaçlý, continue boþuna dönmesin diye kullanýldý.
			if (!test_arr) {
                printf("Memory allocation failed for test array\n");
                continue;
            }

            // diziyi kopyala
            for (j = 0; j < N; j++) {
                test_arr[j] = arr[j];
            }
			
			// zamanlayýcý baþlat, sýralama süresini hesaplayacaðýz daha sonra
            LARGE_INTEGER frequency, start, end;
            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);
			
			// k-way merge sort'u çalýþtýr
            kWayMergeSort(test_arr, temp, 0, N-1, k);
			
			// zamanlayýcýyý durdur ve süreyi hesapla
            QueryPerformanceCounter(&end);
            double time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

            // sýralamanýn doðru olup olmadýðýný kontrol et kopyasý ile
            int sorted = 1;
            for (j = 1; j < N; j++) {
                if (test_arr[j] < test_arr[j-1]) {
                    sorted = 0;
                    // burdaki break, boþu boþuna dönmesin.
                    break;
                }
            }

            printf("k=%d: %.6f seconds %s\n", k, time_taken, 
                   sorted ? "" : "- WARNING: not properly sorted!");

            free(test_arr);
        }

        free(temp);
        free(arr);
    }

    return 0;
}
