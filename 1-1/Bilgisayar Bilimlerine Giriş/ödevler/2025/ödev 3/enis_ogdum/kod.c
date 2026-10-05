#include<stdio.h>
#define MAX_LENGTH 100

int main(){
    int n;
    int matrix[MAX_LENGTH];
    int backup_matrix[MAX_LENGTH];
    int i,backup_i,backup_j;
    int counter,n_counter;
    int flag=1,swap;

printf("how many elements will u enter?\n");
scanf("%d",&n);

for ( i = 0; i < n; i++) // take the data from the user
{
    scanf("%d",&matrix[i]);
}

for ( i = 0; i < n; i++)  // fill other matrix
{ 
    if (matrix[i]<0)
    {
        backup_matrix[i]=-100;
    }else{
       backup_matrix[i]=0; 
    }
    
}         

i=0;
while (i<n && flag)
{
    if (matrix[i]<0)
    {
        counter=0;
        backup_i=i;
        backup_j=i;
        while (backup_i>=0 && counter<=(-matrix[i]) && flag)
        {
            backup_matrix[backup_i]++;
            if (backup_matrix[backup_i]>1) // immediate check for interaction
            {
                flag=0;
                printf("This is not appropriate array!\n");
            }
            backup_i--;
            counter++;
        }
        counter=0;
        while (backup_j<n && counter<=(-matrix[i]) && flag)
        {
            backup_matrix[backup_j]++;
            if (backup_matrix[backup_j]>1) // immediate check for interaction
            {
                flag=0;
                printf("This is not appropriate array!\n");
            }
            backup_j++;
            counter++;
        }
        
    }
    i++;

}
    

i=0;
while (flag && i<n)
{
    swap=1;
    if (matrix[i]<0)
    {
        n_counter=1; // how many elements will be destroyed
        counter=0;
        backup_i=i;
        backup_j=i;
        while (backup_i>=0 && counter<(-matrix[i]))
        {
            backup_i--;
            if (backup_i>=0)
            {
                counter++;
            }
            
        }
        if (backup_i<0)
        {
            backup_i=0;;
        }
        n_counter+=counter;
        counter=0;
        while (backup_j<n && counter<(-matrix[i]))
        {
            backup_j++;
            if (backup_j<n)
            {
               counter++;
            }
        }
        n_counter+=counter;
        if (backup_j==n)
        {
            swap=0;
        }
        
        while (swap && backup_j<n)
        {
            backup_j++;
            if (backup_j<n)
            {
                matrix[backup_i]=matrix[backup_j];
                backup_i++;
            }else{
                swap=0;
            }
            
        }
        n=n-n_counter; // new size of array
        i=-1; // preventing index complexity
    }
    i++;
    
}


while (flag) 
{
    printf("%d\n",n);
    if (n==0)
    {
        printf("no element left!\n");
    }else{

      for ( i = 0; i < n; i++)
    {
        printf("%d ",matrix[i]);  // rest of the array
    }

    }
     flag=0;
}


    return 0;
}