#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//A function that compares two integers and returns biggest.
int max(int x, int y){ 
	return (x > y)? x: y; 
}
int size = 0; 	//Global variable which stores total number of replaced items.
//A function that lowers the characters. Will used in insensitive comparing.
char toLower(char ch){
	if(ch>= 65 && ch<=90)
		ch= ch+32;
	return ch;	
}
//A function that compares two chars 
int compareTwo(char ch1, char ch2){
	if(toLower(ch1) == toLower(ch2))
		return 1;
	else return 0;
}
//An implementation of bad char rule
void badCharRule( char *arr, int N, int badchar[256]){ 								 
	int i; 
	for (i = 0; i < 256; i++)
		badchar[i] = -1;
	for (i = 0; i < N; i++)
		badchar[(int) arr[i]] = i; 
} 
//A function of Boyer Moore string search algorithm.
int *search(char *txt, char *pat,char option){ 
	int *a = (int*)calloc(10,sizeof(int));  
	int M = strlen(pat); 
	int N = strlen(txt); 
	int badchar[256]; 
	badCharRule(pat, M, badchar); 

	int x = 0;  
	int i = 0;
	while(x <= (N - M)){ 
		int j = M-1; 
		if(option == 'Y' || option == 'y')		 //Case sensitive
			while(j >= 0 && pat[j] == txt[x+j]) 
				j--; 
				
		if(option == 'N' || option == 'n') 		//Case insensitive
			while(j >= 0 && compareTwo(pat[j],txt[x+j]) )
				j--; 

		if (j < 0){
			a[i++] = x;
			size++;		//Stores the number of replaced items
			if(x+M < N) 
				x = M + x - badchar[txt[M+x]];
			else
				x = x + 1;
		} 
		else
			x = x + max(1, j - badchar[txt[j+x]]); 
	}
	if(i==0)	 //NOT FOUND ANYTHING
		return NULL;
	else
		return a;
} 
//A function that shifts and writes the new characters.
void shiftAndWrite(char *txt, int index , char *pat, char *chng, int option){
	int lenT = strlen(txt);
	int lenP = strlen(pat);
	int lenC = strlen(chng);
	int shift , i, j;
	
	if(option==-1){ 	 //If length of pat = length of chng, no need to shift the array
		j=0;
		//Writing the new characters
		for(i=index; i<index+lenC; i++)
			txt[i] = chng[j++];	
	}
	
	if(option==0){ 		//If length of pat > length of chng, shift left
		shift = lenP - lenC;   
		//An algorithm that shifts the array right
		for(i=index;i<lenT;i++)
			txt[i + lenC] = txt[i + lenP];
		i=0;
		//For clearing redundant bits
		while(i <= shift)
			txt[lenT - i++] = '\0';
		j=0;
		//Writing the new characters
		for(i=index; i<index+lenC; i++)
			txt[i] = chng[j++];
		
	}if(option==1){		//If length of pat > length of chng, shift right
		shift = lenC - lenP;   
		//An algorithm that shifts the array right
		for(i=lenT-1; i > index + lenP -1 ; i--){  
			txt[i + shift] = txt[i];
			txt[i] = ' '; 
		}
		//For clearing redundant bits
		for(i=lenT+lenC + shift; i>lenT-1+shift;i--) 
			txt[i] ='\0';
		j=0;
		//Writing the new characters
		for(i=index; i<index+lenC; i++)
			txt[i] = chng[j++];	
	}
}
//A function wraps the other functions.
void manipulate(char *txt, char *pat, char *chng,char opt){
	int *index = search(txt,pat,opt);	 //An array which stores occuring indexes 
	int m = 0;  	//index for index array
	int lenT = strlen(txt);   //Length of the text
	int lenP = strlen(pat);	  //Length of the first input
	int lenC = strlen(chng);  //Length of the second input
	int shift, i , j = 0;
	

	if(index != NULL){  // If exists
		while(m<size){ 
			if(lenP == lenC){ //Dont shift just write it	
				shiftAndWrite(txt,(int)index[m],pat,chng,-1); 
			}
			else if(lenP > lenC){ //Shifting left, narrowing the array	
				shift = lenC - lenP;
				shiftAndWrite(txt,(int)index[m] + shift*m ,pat,chng,0);
			}
			else{  //Shifting right, extending the array
				shift = lenC - lenP;
				shiftAndWrite(txt,(int)index[m] +shift*m,pat,chng,1); 
			}
			m++;	
		}	
	}else
		printf("\n\nERROR WORD DOES NOT EXISTS\n");

}


int main(int argc, char *argv[]) {
	FILE *fp = fopen("mytext.txt", "r+");  
	char str[2048];  	  //Stores entire file into char array
	char pattern[128];    //Stores pattern which user gonna enter
	char change[128];     //Stores new input which gonna change the pattern
	char result[8];      //Stores user selection whether case sensitive or not
	int c,i = 0;


    //Choosing case sensitive or not
	printf("Type Yes for Case Sensitive or Type No for Case Insensitive\t");
	gets(result);
	
	//Char by char reading the file and copying it into char arrayno
    while ((c = fgetc(fp)) != EOF){
    	str[i++] = (char)c;
    }

    //Getting first input
    printf("Find    \t");
    gets(pattern);    
	//Getting second input
    printf("Replace \t");
    gets(change);
	//Writing first version of array
	int n = strlen(str);
	printf("\nFirst version of text\n");
	for(i=0;i<n;i++)
		printf("%c",str[i]);
		
	//For calculating the running time of manipulate function
	clock_t begin;
	begin=clock(); 
	
	//Manipulating the char array.
    manipulate(str,pattern,change,result[0]);

    //Writing final verison of array
	n=strlen(str); //Length of the char array
	printf("\n\nFinal version of text\n");
    for(i=0;i<n;i++)
    	printf("%c",str[i]);
	
	//Writing found and replaced items
	printf("\n\nFound and replaced %d items",size);
	
	clock_t end = clock();
    double time_taken = ((double)end - begin) / (CLOCKS_PER_SEC);
	printf("\nCompilation time %f sec\n", time_taken);
	
    //Closing the file which is necessary for writing 
    fclose(fp);
    
	//Writing the file
    fp = fopen("mytext.txt","w");
    fputs(str,fp);
    fclose(fp);	

	return 0;
}

  


