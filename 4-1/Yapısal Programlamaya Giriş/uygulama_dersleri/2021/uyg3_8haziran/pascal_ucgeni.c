#include<stdio.h>

void computePascal(int n);
void initializeArray(int array[],int size);
void printArray(int array[],int size);

int main()
{
    int n;
    printf("N?\n"); 
    scanf("%d",&n);
    computePascal(n);
    return 0;
}

void initializeArray(int array[],int size) 
{
    int i;
    for(i=0;i<size;i++)
    {
        array[i]=0;
    }
}

void printArray(int array[],int size) 
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");

}

void computePascal(int n)
{
    int i,j,temp;
    int array[50];
    initializeArray(array,n);  //dizinin ilk n elemanýný 0'layalým
    array[0]=1; 
    printArray(array,1);
    array[1]=1;
    printArray(array,2);
    for (i=2;i<n;i++) // satir indisi
    {
        	//array[j] üstündeki ve sol carprazdakinin toplamý olmalý
			//temp ilk basta sol carprazi tutuyor
		temp=1;
        for(j=1;j<=i;j++) // array[0] hep ayný. array[1] den itibaren güncelle. i. satýrda i+1 eleman var
        {
            array[j]=array[j]+temp;	//sol carprazýn ile kendi hizandakini(indisindekini) topla
        	temp=array[j]-temp;		//temp array[j]'nin guncellenmemiþ halini tutuyor. 		
        }							//Bir sonraki iterasyonda j artýnca temp yine sol carprazi tutuyor olacak
        printArray(array,i+1);
    }
    
}
