#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *read_to_an_array(FILE *);
int horspool(FILE *, char *, char *, int);
int* shift_table(char*, char *);
char *replaceWord(char *, char *, char *,int,int);

int horspool(FILE *fp, char f[], char *r, int opt)
{
    int i, k,m,n,adet=0;
    char *arr;
    arr = read_to_an_array(fp);

    int *t = shift_table(arr,f);
    m = strlen(f); //len of find
    n = strlen(arr); //len of array

    i = m - 1; //position of the patterns right end
    while (i < n)
    {
        k = 0; //num of matched characters
        while ((k < m)  && (toupper(f[m - 1 - k]) == toupper(arr[i - k])) && opt!=1)//not case sensitive secenegi icin tum harfleri buyutuyor, o sekilde sartlar uyguluyoruz
            k++; 
		
		while ((k < m)  && (f[m - 1 - k] == arr[i - k]) && opt==1)
			k++;

        if(toupper(k)==toupper(m)&&opt!=1)	//for not case sensitive (buyuk harflisi de olsa bulmak istiyoruz kelimeyi)
        	adet++;
        else if (k == m && opt==1)
            adet++;
        i += t[arr[i]];
    }
    char* replace;
    replace=replaceWord(arr, f, r,adet,opt);
    printf("\nYeni hali: %s\n",replace);
    return adet;
}

char *replaceWord(char *s, char *oldW, char *newW, int adet,int option) 
{ 
	char* fake_s = (char *)malloc(strlen(s)+1);	//yeni bir array olusturduk
	strcpy(fake_s,s);	//s dizimizi yeni arraya kopyaladik
	strupr(fake_s);	//bu dizideki harfleri buyuk harf yapiyoruz
	char* fakeold = (char *)malloc(strlen(oldW)+1);		//find ý yazacagimiz bir dizi
	strcpy(fakeold,oldW);
	strupr(fakeold);
    char *result; 
    char *fakeresult;
    int i, j,counter = 0; 
    int newlen = strlen(newW); 
    int oldlen = strlen(oldW); 
    
    result = (char *)malloc(strlen(s)+(adet * (newlen - oldlen))+1); 
    fakeresult = (char *)malloc(strlen(s)+(adet * (newlen - oldlen))+1); 
    
    i = 0; 
    j = 0;
    if(option!=1){	//not case sensitive
    	while (*s!='\0') 
	    {	
	        if (strstr(fake_s, fakeold) == fake_s) //diziyle kelimeyi karsilastiriyoruz
	        { 
	            strcpy(&result[i], newW); //yeni kelimeyi diziye atýyoruz.
	            strcpy(&fakeresult[j], newW);	//yeni kelimeyi fakeresult dizisine atýyoruz.
	            i += newlen; //i yi yeni kelimenin uzunlugu kadar ileri tasiyoruz
	            s += oldlen; //s i de eski kelime kadar ileri tasiyoruz
	            j += newlen; //j yi yeni kelime kadar ileri
	            fake_s += oldlen; 
	        }
	        else{
	        	result[i++] = *s++; //bulmadikca stringde ilerle
	        	fakeresult[j++] = *fake_s++;
			}
	    }
	}
	else{	//case sensitive icin
		while (*s!='\0') //dizinin sonuna gelene kadar...
	    {	
	        if (strstr(s, oldW) == s) //diziyle aranan kelimeyi karsilastiriyoruz.
	        { 
	            strcpy(&result[i], newW); //yeni kelimeyi diziye atýyoruz.
	            i += newlen; //iterasyonu yeni kelimenin uzunlugu kadar ileri tasiyoruz
	            s += oldlen; //s i de eski kelime kadar ileri tasiyoruz
	        }
	        else
	            result[i++] = *s++; //bulmadikca stringde ilerle
	    }
	}
    result[i] = '\0'; 	//string sonuna NULL koyuyoruz
    return result; 
} 

int* shift_table(char array[],char find[])
{ 
    int m, i, j, size=256;
    m = strlen(find);
    int *table;
    table = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        table[i] = m;	//once her degere aranan kelimenin uzunlugunu atadýk.
    }
    //asagida da textte bulunan karakterlere (m-1-indis) hesaplamasini uyguladýk
    //buyuk harf ve kucuk harf icin ayni degerleri almasi onemli, yoksa not case sensitive icin sýkýntý olusur
    for (j = 0; j < m - 1; j++)
    {
        table[tolower(find[j])] = m - 1 - j;
        table[toupper(find[j])] = m - 1 - j;
    }
    return table;
}

char *read_to_an_array(FILE *fp)
{
    int i = 0, size;
    char ch, *array;

    fseek(fp, 0, SEEK_END); /* Go to end of file */
    size = ftell(fp);       /* How many bytes did we pass ? */

    rewind(fp); //Set position of stream to the beginning

    array = (char *)malloc((size + 1) * sizeof(char));

    /* Read the file into the buffer */
    fread(array, size, 1, fp); // Read 1 chunk of size bytes from fp into buffer

    array[size] = '\0'; //son elemana null yaziyoruz satir sonu icin

    return array;
}

int main(int argc, char **argv)
{
	double time_spent=0.0;
    clock_t begin= clock();
    
    FILE *datafile;
    int pos,option;
    char ch, file_name[256];
    char find[256], replace[256];

	printf("Name of the text file :");
    gets(file_name);
    datafile = fopen(file_name, "r");//Dosya okuma iþlevi
    if (datafile == NULL)
    {
        printf("cannot open file...\n");
        clock_t end=clock();
    	time_spent+=(double)(end-begin)/CLOCKS_PER_SEC;
    	printf("Running time is %f seconds",time_spent);
    	exit(EXIT_FAILURE);
	}

    printf("Find: ");
    gets(find);

	printf("Replace:  ");
	gets(replace);
    
	printf("Option (for case sensitive write'1', for not case sensitive write anything else):  ");
	scanf("%d",&option);

	printf("Text: ");
    while ((ch = fgetc(datafile)) != EOF)
        printf("%c", ch);

    printf("\n");

    pos=horspool(datafile, find, replace, option);
    if(pos>=0)
	  printf("\n----Found and replaced: %d ----\n",pos); 
	else
	  printf("\n----The pattern was not found in the given text----\n");

    fclose(datafile);
    
    clock_t end=clock();
    time_spent+=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nRunning time is %f seconds\n",time_spent);
    return 0;
}

