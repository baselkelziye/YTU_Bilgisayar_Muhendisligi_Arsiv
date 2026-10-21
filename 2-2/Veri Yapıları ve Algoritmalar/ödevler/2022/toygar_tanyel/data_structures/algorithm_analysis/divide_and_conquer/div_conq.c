#include <stdio.h>

/**
 * @brief uc sayi arasında maksimum sayiyi döndürmemize olanak saglayan fonksiyon
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return int 
 */
int maximum(int a, int b, int c) {
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    return c;
}


/**
 * @brief Sag ve sol alt kumelerin ortanca deger ile birlikte olan toplamlari
 * 
 * @param ar 
 * @param low 
 * @param mid 
 * @param high 
 * @return int 
 */
int max_ortak_altkume(int ar[], int low, int mid, int high, int *hold_left_idx, int *hold_right_idx) {
    /*
      Ilk left_sum sonsuz gibi olmalıdır.
      limitler.h icerisinden INT_MIN de kullanilabilir.
    */
    int left_sum = -1000000;
    int sum = 0;
    int i;
    /*
      ortadaki degeri de iceren sol alt dizinin 
      maksimum toplamini bulmak icin ortanca degeri
      en dusuk elemana yineleme.
    */

    for (i = mid; i >= low; i--) {
        sum += ar[i];
        if (sum > left_sum){
            left_sum = sum;
            *hold_left_idx = i;
        } 
    }

    /*
      Benzer sekilde, ortanca degerin
      bitisik sagindaki elemani iceren sag alt
      dizinin maksimum toplamini bulma.
    */
    int right_sum = -1000000;
    sum = 0;

    for (i = mid+1; i <= high; i++) {
        sum += ar[i];
        if (sum > right_sum){
            right_sum = sum;
            *hold_right_idx = i;
        }  
    }
 
    /*
      ortanca degeri içeren alt dizinin
      maksimum toplamini dondurme.
    */
    return (left_sum + right_sum);
}


/**
 * @brief sag ve sol alt kumeler icin toplam hesabi yapan fonksiyon
 * 
 * @param ar 
 * @param low 
 * @param high 
 * @return int 
 */
int max_altkume_toplam(int ar[], int low, int high, int *hold_left_idx, int *hold_right_idx) {
    if (high == low) // dizide tek eleman varsa
        return ar[high];
   
    // ortadaki eleman
    int mid = (high + low) / 2;

    
    // sol alt dizideki maksimum toplam (b-max)
    int max_sol_altkume_top = max_altkume_toplam(ar, low, mid, hold_left_idx, hold_right_idx);
    // sag alt dizideki maksimum toplam (c-max)
    int max_sag_altkume_top = max_altkume_toplam(ar, mid+1, high, hold_left_idx, hold_right_idx);
    // ortanca degeri iceren dizideki maksimum toplam (d-max)
    int max_orta_altkume_top = max_ortak_altkume(ar, low, mid, high, hold_left_idx, hold_right_idx);
    

    return maximum(max_sol_altkume_top, max_sag_altkume_top,
                   max_orta_altkume_top);
}

void print_array(int a[], int n){
    int i;

    printf("Notasyon -> {blok : kazanc}\n");
    for(i=0; i<n; i++)
        printf("{%d : %d}, ", i, a[i]);
}

int main() {
    //int a[] = {8, -30, 36, 2, -6, 52, 8, -1, -11, 10, 4}; //test1 (tek)
    //int a[] = {-8, 500, 1, -200, 100, 200, 0, 300, 600, -150, -40}; //test2 (tek)
    //int a[] = {3, 5, 100, 100, 1, 3, 2, 6}; //test3 (cift)
    //int a[] = {1, 1, -100, 1, -4, -4, -1, 1, 1, 3, 2}; //test4 (tek)
    int a[] = {3, 5, 1, -10, 1, 3}; //test5 (cift)
    //int a[] = {3, 5, 1, -10, 2, 20}; //test6 (cift)


    int n = sizeof(a) / sizeof(a[0]);
    int hold_left_idx, hold_right_idx;
    int left_starting_point = 0, left_end_point = n/2-1, right_starting_point = n/2+1, end_point = n-1;
    int protect_bmax_left_index, protect_bmax_right_index, protect_cmax_left_index, protect_cmax_right_index;

    int bmax, cmax, dmax;

    bmax = max_altkume_toplam(a, left_starting_point, left_end_point, &hold_left_idx, &hold_right_idx);
    protect_bmax_left_index = hold_left_idx, protect_bmax_right_index=hold_right_idx;
    cmax = max_altkume_toplam(a, right_starting_point, end_point, &hold_left_idx, &hold_right_idx);
    protect_cmax_left_index = hold_left_idx, protect_cmax_right_index=hold_right_idx;
    dmax = max_altkume_toplam(a, left_starting_point, end_point, &hold_left_idx, &hold_right_idx);


    printf("----------------------------------------------------------------------------------------\n");
    print_array(a, n);
    printf("\n");
    printf("\nEn buyuk altkume bmax: %d\n", bmax);
    printf("\nSol alt kumede kazilmasi gereken bloklar: %d - %d\n", protect_bmax_left_index, protect_bmax_right_index);
    printf("\nEn buyuk altkume cmax: %d\n", cmax);
    printf("\nSağ alt kumede kazilmasi gereken bloklar: %d - %d\n", protect_cmax_left_index, protect_cmax_right_index);
    if( dmax == bmax && dmax > cmax){
        printf("\nortanca eleman negatif ve bmax > cmax && dmax < bmax oldugundan en buyuk kazanc yukarida gosterilen bmax'tir.\n\
        Ayni zamanda kazilmasi gereken son dogru aralik bmax icin gosterilendir.\n");
        printf("----------------------------------------------------------------------------------------");
    }
    else if( dmax == cmax && dmax > bmax) {
        printf("\nortanca eleman negatif ve cmax > bmax && dmax < cmax oldugundan en buyuk kazanc yukarida gosterilen cmax'tir.\n\
        Ayni zamanda kazilmasi gereken son dogru aralik cmax icin gosterilendir.\n");
        printf("----------------------------------------------------------------------------------------");
    }
    else{
        printf("\nEn buyuk altkume dmax: %d\n", dmax);
        printf("\nOrtak alt kumede kazilmasi gereken bloklar: %d - %d\n", hold_left_idx, hold_right_idx);
        printf("----------------------------------------------------------------------------------------");
    }
    


    return 0;
}