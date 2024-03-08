#include<stdio.h>
#define  DEBUG_MODE 0
#define SMALLEST_NUMBER -99999



int max_subset_brute_force(int[], int , int*,int*);
int divide_and_conquer(int [], int ,int*,int*);


int main(){

     //pdfteki ornek
    //  int arr[] = {8,-30,36,2,-6,52,8,-1,-11,10,4};
    

    // en buyuk alt dizi son eleman
    //   int arr[] = {-3,-2,-5,-3,-10,-1,5};
    
    
 

  
   
  
   
    // en buyuk alt dizi sol kisimda (1,2) veya(1,3) cunku sifir var
    // int arr[] = {-1,3,2,0,-4,1};


     
    // en buyuk alt dizi  sag kisimda (5,7) 
    // int arr[] = {-2,-3,4,-5,-2,1,5,3}; 

  


    // en buyuk alt dizi ortada (2,6)..
       int arr[]  = {-2,-3,4,-1,-2,1,5,-3};




       //en buyuk ilk eleman
    //    int arr[] = {5,-2,-1,-6,-35,-39};

     
  
    // int arr[]  = {-1,-2,-3,10,-4};
    int len = sizeof(arr)/sizeof(arr[0]);

    int left,right;
    // int max = max_subset_brute_force(arr,len,&left,&right);
    int max = divide_and_conquer(arr,len,&left,&right);

   printf("max sum is -> %d, left -> %d right -> %d", max,left,right);
   printf("\n");
    return 0;
}


int max_subset_brute_force(int arr[], int len, int*left, int*right){
    int i,j;
    int cumulative_sum;
    int max = arr[0];
    for(i = 0; i < len; i++){
    cumulative_sum = 0;
        for(j = i; j < len; j++){
            cumulative_sum = cumulative_sum + arr[j];
            if(DEBUG_MODE) printf("\ni -> %d\nj -> %d\ncumulative sum -> %d\nmax -> %d\n",i,j,cumulative_sum,max);//debug yaparken 1 yapiyorum makro yu
            if(max <= cumulative_sum){
                max = cumulative_sum;
                *left = i;
                *right = j;
            }
        }
    }
    return max;
}


int divide_and_conquer(int arr[], int len,int *left_index, int*right_index){
   if (len == 1){
     return arr[0];
   }
    
   
    int mid = len/2;

    int leftsum = SMALLEST_NUMBER, rightsum = SMALLEST_NUMBER,left_tmp, right_tmp;
    int sum = 0;
    int i;
    int max_sum;
    int left_max_subset = divide_and_conquer(arr,mid,left_index,right_index); 
    int right_max_subset = divide_and_conquer(arr+mid, len-mid,left_index,right_index);

  
   

   
    // printf("\nright index is -> %d",left_index);
 

    for(i = (mid-1); i>=0; i--){
        sum = sum + arr[i];
        if(leftsum <= sum){
            leftsum = sum;
             *left_index = i;    
        }
    }

   sum = 0;

     for(i = mid; i < len; i++){
        sum = sum + arr[i];
        if(rightsum <= sum){
            rightsum = sum;
            *right_index= i;
        }
    }
    // printf("\nleft index is -> %d ", right_index);

    if(left_max_subset > right_max_subset){
        max_sum = left_max_subset;
    }
    else{
        max_sum = right_max_subset;
    }

    if(max_sum > leftsum + rightsum){
        
        return max_sum;
    }
    
    else{
        return (leftsum + rightsum);
    }
    

 
}
