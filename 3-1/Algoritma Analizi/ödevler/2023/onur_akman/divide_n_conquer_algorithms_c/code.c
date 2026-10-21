#include <stdio.h>
#include <stdlib.h>

//The function that generates a lock array by placing the values from Key array into random index
//Optionally available
void lock_generator (int Key[], int Lock[],int N){
    int i=0,j=0;
    for (i=0;i<N;i++){
        Lock[i]=-1;
    }
    for(i=0;i<N;i++){
        do j=rand()%N; while(Lock[j]!=-1);
        Lock[j]=Key[i];
    }
}

//The function that does the matching. It works with 2 arrays in the same time.
void match (int Key[], int Lock[], int low, int high){
    int pKey,pLock,j; //pKey, pLock -> pivot values, j -> for printing arrays
    if (low < high){
        //pKey is a random value between low and high
        //pLock is the index value that holds the same value in pLock with what pKey holds in Key array
        pKey=rand()%(high-low);
        pKey=pKey+low;
        pLock=-1; do pLock++; while(Lock[pLock]!=Key[pKey]);

        printf("\n\n\nPartition for KEY. Low = %d, High = %d, Randomly picked pivot index = %d (which is = %d)", low, high, pKey, Key[pKey]);
        pKey=partition(Key, low, high, pKey);
        printf("\nEnd of the partition, the KEY array is now:");
        for (j=low;j<=high;j++) printf("%d ", Key[j]);
        printf(" -> New index of the pivot is %d now.",pKey);

        printf("\n\nPartition for LOCK. Low = %d, High = %d, Randomly picked pivot index = %d (which is = %d)", low, high, pLock, Lock[pLock]);
        pLock=partition(Lock, low, high, pLock);
        printf("\nEnd of the partition, the LOCK array is now:");
        for (j=low;j<=high;j++) printf("%d ", Lock[j]);
        printf(" -> New index of the pivot is %d now.",pLock);
        //We see that pLock will be equal to pKey

        match(Key, Lock, low, pKey-1);
        //Lower values first
        match(Key, Lock, pKey+1, high);
    }
}


//The function separates the array that is given into 2 pieces. Greater and lower values from given value.
//Returns given value's new index
int partition (int array[], int low, int high, int pivot){
    int i = low - 1;
    int j, tmp;
    for (j=low;j<=high;j++){
        if (j!=pivot){
            if (array[j]<=array[pivot])
            {
                i++;
                tmp = array[i]; array[i]=array[j]; array[j]=tmp;
                if (i==pivot) pivot=j;
            }
        }
    }
    i++;
    if (i!=pivot){
        tmp = array[i]; array[i]=array[pivot]; array[pivot]=tmp;
    }
    return i;
}


int main()
{
    int N,i,j;
    printf("Please submit the number of values...");
    scanf("%d",&N);

    int Key[N], Lock[N];

    printf("\nDo you want the values to be randomly generated? 1/0...");
    scanf("%d",&j);

    if(j==1){
        for (i=0;i<N;i++) Key[i]=rand();
        i=1;
    }
    else {
        for (i=0;i<N;i++){
            printf("Please submit the value of the Key #%d...", i+1);
            scanf("%d",&Key[i]);
        }
        printf("\nDo you want the lock values to be randomly placed? 1/0...");
        scanf("%d",&i);
    }


    if(i==1) lock_generator(Key,Lock,N);
    else{
        for (i=0;i<N;i++){
            printf("Please submit the value of the Lock #%d...", i+1);
            scanf("%d",&Lock[i]);
        }
    }

    //Printing initial arrays
    printf("\nKeys :"); for(i=0;i<N;i++) printf(" %d ", Key[i]);
    printf("\nLocks:"); for(i=0;i<N;i++) printf(" %d ", Lock[i]);

    match(Key, Lock, 0, N-1);

    //Printing the final arrays
    printf("\n\n\nRESULT:\n");
    printf("\n  KEYS LOCKS");
    for(i=0;i<N;i++){
        if (Key[i]==Lock[i])
        printf("\n#%d %d    %d  -> MATCH", i+1, Key[i], Lock[i]);
        else
        printf("\n#%d %d    %d  -> FAILED", i+1, Key[i], Lock[i]);
    }


    return 0;
}
