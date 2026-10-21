#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#define FAIL 0
#define SUCCESS 1
#define LINESIZE 100

int noktalivirgulekle(char *, char *);

int tirnakduzelt();

int main(int argc, char *argv[]) {
	
	if( argc < 3 ){
		printf("Arguman sayisi az, main haric 2 parametre giriniz.\n");
		return -1;
	}
	else if(argc >3){
		printf("Arguman sayisi fazla, main haric 2 parametre giriniz.\n");
		return -1;
	}
	else {
		printf("Arguman 1 : %s, Arguman 2 : %s\n",argv[1],argv[2]);
	}

FILE *fp1, *fp2, *fp3;

int m=0,j=0;

char ch[200],ch3;

char * degiskenler[200],*isim[200],*type[200];

char* t2[] = {"_file","_ip","_cp","_lp","_dp","_fp","_f","_l","_d","_c","_i"};

char* t3[] = {"FILE* ","int* ","char* ","long* ","double* ","float* ","float ","long ","double ","char ","int "};

int k=0,son=0,i,x=0;

int b=0;

char file2[20]="pass.txt",deklerasyonfile[20]="tanimlama.txt";

char *file1 = argv[1];

char *ret;

char ch5, alttire='_';


	if ((fp1 = fopen( file1, "r"  ))== NULL){
	printf("pseudo dosyasi acilamadi\n");
	return FAIL;
	}
    printf("pseudo dosyasi acildi\n");
		if ((fp2 = fopen( file2, "w" )) == NULL)
	    {
	    printf("pass dosyasi acilamadi\n");
		fclose ( fp1 );
		return FAIL;
	    }
	    printf("pass dosyasi acildi\n");
	     
	     
  while(son!=-1){

  son=fscanf(fp1,"%s",ch);
	
     if (son==-1){
   	    break;
     }

	  if(strcmp(ch,"PROCEDURE")==0) //reserved wordler ile tam karsilik yazdiriyorum
	  {
	  fputs( "int", fp2 );
  	  }

	  else if(strcmp(ch,"MAIN()")==0)
   	  {
	  fputs( " main()\n", fp2 );
	  }

	  else if(strcmp(ch,"BEGIN")==0)
	  {
	  fputs( " {\n", fp2 );
	  }

	  else if(strcmp(ch,"END")==0)
	  {
	  fputs( " }\n", fp2 );
	  }

	  else if(strcmp(ch,"AND")==0)
	  {
	  fputs( " &&", fp2 );
	  }


	  else if(strcmp(ch,"OR")==0)
	  {
	  fputs( " ||", fp2 );
	  }

	  else if(strcmp(ch,"WHILE")==0)
	  {
	  fputs( " while(", fp2 );
  	  }

	  else if(strcmp(ch,"LOOP")==0)
	  {
	  fputs( " )\n", fp2 );
	  }

	  else if(strcmp(ch,"DO")==0)
	  {
	  fputs( " )\n", fp2 );
   	  }

	  else if(strcmp(ch,"FOR")==0)
	  {
	  fputs( " for(", fp2 );
	  }

	  else if(strcmp(ch,"EQUAL")==0)
	  { 
	  fputs( " ==", fp2 );
	  }

	  else if(strcmp(ch,"NOT_EQUAL")==0)
	  {
	  fputs( " !=", fp2 );
	  }

	  else if(strcmp(ch,"<-")==0)
	  {
	  fputs( " =", fp2 );
	  }

	  else if(strcmp(ch,"PRINT_LINE")==0)
	  {
	  fputs( " printf(", fp2 );
	  }

	  else if(strcmp(ch,"IF")==0)
	  {
	  fputs( " if", fp2 );
	  }

	  else if(strcmp(ch,"THEN")==0)
	  {
	  fputs( " \n", fp2 );
	  }

	  else if(strcmp(ch,"GET_VAL")==0)
	  {
	  fputs( " scanf(", fp2 );
	  }


	  else
	  {
	    if(strpbrk(ch,"”")!=NULL){//prinft ve scanf icin ayricalik

	    fputs(" ",fp2);//fscanf bosluklari okumadigi icin space karakteri koyuyorum

	    fputs(ch,fp2);//cevrilmeyen reserved olmayan kelimeyi aynen yazdiriyorum
	   
	    fputs(")",fp2);
	    }

		else if(strpbrk(ch,"_")!=NULL){//degisken olup olmadigina bakiyorum
		
		degiskenler[k]=(char*)malloc(10*sizeof(char));

		memcpy(degiskenler[k],ch,strlen(ch)+1);//degiskenler dizisinin icerisine chdeki stringi atiyorum
		
		ret=(char*)malloc(5*sizeof(char));
		
		ret=strchr(degiskenler[k],alttire);//tip belirleme iþlemi için alttireden sonra gelen kismi konrol etmek üzere ret'e atiyorum
				
	    if(strcmp(ret,t2[10])==0 || strpbrk(degiskenler[k],".,:[]")!=0){
		
	    type[k]=(char*)malloc(5*sizeof(char));
	    memcpy(type[k],t3[10],strlen(t3[10])+1);
	    
	    }

	    else if(strcmp(ret,t2[9])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[9],strlen(t3[9])+1);
		}
	
		
		else if(strcmp(ret,t2[8])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[8],strlen(t3[8])+1);
		}
		
		else if(strcmp(ret,t2[7])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[7],strlen(t3[7])+1);
		}
		
		else if(strcmp(ret,t2[6])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[6],strlen(t3[6])+1);
		}
		
		else if(strcmp(ret,t2[5])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[5],strlen(t3[5])+1);
		}
		
		else if(strcmp(ret,t2[4])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[4],strlen(t3[4])+1);
		}
		
		else if(strcmp(ret,t2[3])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[3],strlen(t3[3])+1);
		}
		
		else if(strcmp(ret,t2[2])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[2],strlen(t3[2])+1);
		}
		
		else if(strcmp(ret,t2[1])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[1],strlen(t3[1])+1);
		}
		
		else if(strcmp(ret,t2[0])==0){
	    	
		type[k]=(char*)malloc(10*sizeof(char));
	    memcpy(type[k],t3[0],strlen(t3[0])+1);
		}
	
	    k++;
		
		for(x = 0; x<11;x++){
			removeSubstr ( ch, t2[x]);	
		}
	    
	    isim[j]=(char*)malloc(20*sizeof(char));
	    
		memcpy(isim[j],ch,strlen(ch)+1);
	    
		j++;
		
        fputs(ch,fp2);
		fputs(" ",fp2);
		
        }
	    else
	    {
	    fputs(ch,fp2);
	    fputs(" ",fp2);
	    }
        
     }

  }
    
    for(i=0;i<k;i++){ // tekrarlayan degiskenleri \0 yaparak degiskenleri uniquelestirme islemi

	     for(j=i+1;j<k;j++){
			
			if(strcmp(degiskenler[i],degiskenler[j])==0 || strpbrk(degiskenler[i],".,:")!=0 ){
				strcpy(degiskenler[i],"\0");
     		}	
		}
	}
	
	/*for(i=0;i<j;i++){
	printf("isim[%d]:%s\n",i,isim[i]);
    }
    
	for(i=0;i<k;i++){
	printf("degiskenler[%d]:%s\n",i,degiskenler[i]);
    }
    
	for(i=0;i<k;i++){
	printf("type[%d]:%s\n",i,type[i]);
    }
    */
    
   fclose(fp2);
   
    if ((fp2 = fopen( file2, "r"  ))== NULL){

	printf("pass dosyasi acilamadi\n");
	
	return FAIL;
	}
	printf("pass dosyasi acildi\n");

	if ((fp3 = fopen( deklerasyonfile, "w"  ))== NULL){ //degiskenlerin tanimlamasini yapmak icin kullanilacak dosya aciliyor

	printf("tanimlama dosyasi acilamadi\n");
	
	return FAIL;
	}
	printf("tanimlama dosyasi acildi\n");
	
	int cnt=0;
	
	while(!feof(fp2)){
		
		ch5=getc(fp2);
		
		if(feof(fp2)){
		break;
		}
		
		putc(ch5,fp3);
		if(ch5=='{' && cnt==0){
		
			 for(i=0;i<k;i++){
			 	
	             if(strcmp(degiskenler[i],"\0")!=0 && strpbrk(degiskenler[i],".,:")==0){//unique degiskenlerin,
	             
	             memcpy(ch,type[i],strlen(type[i])+1);//tipi ve
		         fputs(ch,fp3);
		         
		         memcpy(ch,isim[i],strlen(isim[i])+1);//ismi yadiriliyor
		         fputs(ch,fp3);
		         
		    
		    	 putc(' ',fp3);
		    	 putc(';',fp3);
		    	 

	             } 
			}
			cnt=1; //1 kere tanimlama  yapabilmek icin sayac
	    }
    }

    fclose(fp3);
    fclose(fp2);
    fclose(fp1);
    
    printf("C dosyasi olusturuluyor...\n");
    
    noktalivirgulekle(deklerasyonfile,argv[2]);
    
    printf("C dosyasi olusturuldu\n");
    
    //derleme islemleri basliyor
    
    char gcc[80] ;
    
    strcpy(gcc, "gcc ");
    
	strcat(gcc,argv[2]); // cfile.c dosyasi arguman olarak(argv[2]) alinir
	
	strcat(gcc," -o "); // gcc cfile.c -o olusturuldu
	
	char *ptr;
	ptr = strchr(argv[2], '.'); //cfile.c yazildiginda 
	
	if (ptr != NULL) { //.c kismi sifirlanir
	    *ptr = '\0';
	}
	 
	strcat(gcc,argv[2]); // gcc cfile.c - o cfile
	strcat(gcc," -w");		
    system(gcc); //yukaridaki satir gonderilerek derleniyor
    
    printf("Derlenme tamamlandi, Basarili ise executable dosya olusturuldu\n");

    system(argv[2]); // olusan exe calistiriliyor
    
    execvp(argv[2],NULL);	//linuxta da calismasi amaciyla yazilmistir

	 return 0;
	 
}

void removeSubstr (char *string, char *sub) {
    char *match;
    int len = strlen(sub);
    while ((match = strstr(string, sub))) {
        *match = '\0';
        strcat(string, match+len);
    }
}

int noktalivirgulekle(char *cfile, char *lastFile)
{

FILE *fp1,*fp2;

char str[20];
char file1[20]="noktalivirgul.txt";

char ch,ch3,ch2=';',ch5;

int x=0,cnt=0, cnt2=0, cnt5=0,t=0, j=0;

	if ((fp1 = fopen( cfile, "r"  ))== NULL){

	printf("tanimlama dosyasi acilamadi\n");

	fclose(fp1);
	return FAIL;
	}
	printf("tanimlama dosyasi acildi\n");
	
		if ((fp2 = fopen( file1, "w" )) == NULL)
	    {
	    printf("noktalivirgul dosyasi acilamadi\n");
		fclose ( fp1 );
		return FAIL;
	    }
	    printf("noktalivirgul dosyasi acildi\n");
  
  fseek(fp1,0,SEEK_SET);
  fscanf(fp1,"%c",&ch);
  
	putc(ch,fp2);
	ch=getc(fp1);
	ch3=ch;
	
   while (!feof(fp1)){
        
	
   	   	if((cnt!=0 || cnt!=2 || ch!=3|| ch!=1)&& ch!='.'){  
		putc(ch,fp2);
	    }
	    
		ch3=getc(fp1);
		ch=ch3;
	    
	  
		if(ch=='k'){//array boyutu tanimlaniyor
			if(cnt2==0){
			putc('1',fp2);
			putc('0',fp2);
			putc('0',fp2);
			ch=NULL;
			}
		cnt2=cnt2+1;
		}
		
		if(ch3=='.'&&(cnt==0||cnt==2||cnt==1||cnt==3) ){  // for icerisindeki noktali alanlarin degistirilmesinde nokta sayisi baz aliniyor
			                                              //en fazla iki tane for dongüsü oldugu var sayilmistir
			if(cnt==0||cnt==2){
			putc('k',fp2);
            cnt=cnt+1;
            ch=NULL;
			}
			
			if(cnt==1||cnt==3){ 
			putc('<',fp2);
			ch=NULL;
			ch3=getc(fp1);
			
			 while(ch3==' '){
				ch3=getc(fp1);
			 }
			 if(ch3!=' '){
				putc(ch3,fp2);
				putc(ch2,fp2);
				putc('k',fp2);
				putc('+',fp2);
				putc('+',fp2);
			 }
			 cnt=cnt+1;			
		    }	 			   
		}
		
		if(ch==']'){
		  
		 ch3=getc(fp1);
		 putc(ch,fp2);
		 ch=ch3;

	     while(ch==' '){
	      ch3=getc(fp1);
	      ch=ch3;
		 }
		 if(ch=='”')
		  ch=NULL;   
     	 }
     	 if(ch=='“'){
		 putc(ch,fp2);
     	 ch3=getc(fp1);
	     ch=ch3;
	       if(ch=='$'){//scanf isleminin icin cye uygun hale getirmek icin
			 putc('%',fp2);
	    	 putc('d',fp2);
			 putc('”',fp2);
	    	 putc(',',fp2);
	    	 putc('&',fp2);
	    	 ch=NULL;
	    	 ch3=getc(fp1);
	    	 ch=ch3;
	    	   while(ch==' '){
	    		ch3=getc(fp1);
				ch=ch3;	    		
			   }
	    	   while(ch!='”'){
	    		putc(ch,fp2);
	    		ch3=getc(fp1);
	    		ch=ch3;
			   }
			   if(ch=='”'){
		    	ch=NULL;
			    putc(ch,fp2);	
	           }
	           while(ch!=')'){
	        	ch3=getc(fp1);
	        	ch=ch3;
			   }
			   if(ch==')'){
				putc(ch,fp2);
				putc(ch2,fp2);
				ch3=getc(fp1);
				ch=ch3;
			   }
		    }
			
		}
            if(ch=='”'){
	      	putc(ch,fp2);
	      	ch3=getc(fp1);
	      	ch=ch3;
	      	   if(ch3==')'){
			  
	      	   putc(ch3,fp2);
	      	   putc(ch2,fp2);
	      	   ch3=getc(fp1);
	      	   ch=ch3;
			   }
		    }
		if(ch=='$'){// spesifik print'in icinin duzenlenmesi icin islemler yapiliyor
		putc('%',fp2);
		putc('d',fp2);
		
		ch=NULL;
		putc(ch,fp2);
		ch3=getc(fp1);
		ch=ch3;
		
		    while(ch!=',')
			{
		    ch3=getc(fp1);
	    	ch=ch3;
			str[t]=ch; 
		    t++;		   
	        }
	        
	        if(ch==','){
	        putc(ch,fp2);
	        }
	        
	        while(ch!='.' && cnt5==0){
	        ch3=getc(fp1);
	        ch=ch3;
	          if(ch!='$'&& ch!='.'){
			
		    	str[t]=ch;
			    t++;
			  }
			  
			}
	        
	        if(ch=='.' && cnt5==0){
	        
	        putc('%',fp2);
			putc('d',fp2);
	        putc(ch,fp2);
			ch3=getc(fp1);
			ch=ch3; 	 
	          while(ch!='”'){
	          putc(ch,fp2);
	          ch3=getc(fp1);
	          ch=ch3;
			  }
			  if(ch=='”'){//printf icerisindeki degiskenlerin yazdirilabilmesi icin degiskenler sonuna ekleniyor
			  	putc(ch,fp2);
			  	putc(',',fp2);
			  	for(j=0;j<=t;j++){
			  	  ch=str[j];
				  putc(ch,fp2);
				}
			  }
			  while(ch!=')'){
			  ch3=getc(fp1);
			  ch=ch3;
		      }
		      if(ch==')'){
		      	putc(ch,fp2);
		      	putc(ch2,fp2);
		      	ch=NULL;
			  }
		    cnt5++;
			}
		
		}
		
   	    while(ch3=='='){// noktali virgul konulacak islem belirteci bulunmali
   	   		
		   putc(ch,fp2);
		   ch=getc(fp1);
	
   	      if(ch=='/n' || ch==NULL || ch=='0'||ch=='-1'||ch=='1'){// 0,1,-1 ile initialize varsayimi var
		   putc(ch,fp2);
           putc(ch2,fp2);
           ch=getc(fp1);
           ch3=NULL;
	      }
	      else if(ch==' '){
	      	putc(ch,fp2);
	      	ch3=getc(fp1);
	      	
			   while (ch3!=']'){//array kullanarak yapilan islemlerden sonra noktali virgul konulmasi icin kontroller
	      	   putc(ch3,fp2);
	      	   ch3=getc(fp1);
	      	   ch=ch3;
	      	   if(ch3=='+')
	      	   break;
			   }
			   if(ch3=='+'){//toplama islemi yapildiginda sonuna ; koydurmak icin(farkli operatorler kullanilirsa degistiriniz)
                putc(ch,fp2);
                ch3 =getc(fp1);
                ch = ch3;

                while(ch3==' '){
                ch3=getc(fp1);

                ch=ch3;
                putc(ch,fp2);
                //ch3=getc(fp1);
                //ch=ch3;
                }
                if(ch3!=' '){
                putc(ch2,fp2);
                //putc(ch,fp2);
                x=1;
                }
			   	
			   }
			   
	      	   if (ch3==']'){  
	      	   putc(ch3,fp2);
	      	   putc(ch2,fp2);
	      	   ch3=getc(fp1);
	      	  
	      	   putc(ch3,fp2);
	      	   ch3=getc(fp1);
			   ch=ch3;
			 
	      	   if(ch3==' '||ch3=='}')
	      	   x=1;// iki kere ; yazmamasi icin kontrol edilecek deger 
	      	   }
			   else{
	      	   ch3=NULL;
			   }
            
			   while(ch3!='}'){
               putc(ch3,fp2);
               ch3=getc(fp1);
               ch=ch3;
               if(ch3==']')
               ch3=NULL;           
			   }
			    if(ch3=='}'){
				if(x!=1) //iki kere ; yazmamasi için kontrol
			    putc(ch2,fp2);
			    }
			    else{
			    ch3=NULL;
			    }
			    
		  }
		  
	    }
	 
   }

fclose(fp1);
fclose(fp2);
tirnakduzelt(file1,lastFile);

	return SUCCESS;
}


int tirnakduzelt(char * file1, char * lastFile){

FILE *fp1, *fp2;
char ch;
char file2[20]="polished.txt";

	if((fp1=fopen(file1,"r"))==NULL){
		printf("noktalivirgul dosyasi acilamadi\n");
	    return FAIL;	
    }
	printf("noktalivirgul dosyasi acildi\n");
	
	if((fp2=fopen(file2,"w"))==NULL){
		printf("polished dosyasi acilamadi\n");
		fclose(fp1);
		return FAIL;
	}
	
	printf("polished dosyasi acildi\n");

  while(!feof(fp1)){
  	
	ch=getc(fp1);
  	while(ch=='\0'){
  	ch=getc(fp1);
	}
	
	if(ch=='“' || ch=='”')//text gorunumundeki tirnaklarin degistirilmesi icin
  	 putc('"',fp2);	  
	else{
	 if(feof(fp1)){
	 break;
	 }
	putc(ch,fp2);
    }
  }
	
	
fclose(fp1);
fclose(fp2);
cyecevir(file2,lastFile);
	
	return SUCCESS;
}


int cyecevir(char *file2,char *lastFile){

FILE * fp1, *fp2;

char line [LINESIZE] ;

	if((fp1=fopen(file2,"r"))==NULL){
		printf("polished dosyasi acilamadi\n");
	    return FAIL;	
    }
	printf("polished dosyasi acildi\n");
	
	if((fp2=fopen(lastFile,"w"))==NULL){
		printf("cfile acilamadi\n");
		fclose(fp1);
		return FAIL;
	}
	printf("cfile acildi\n");
	
    while (fgets( line, LINESIZE, fp1 ) != NULL) //karakter kaybi olmamasi adina satir satir kopyalama islemi
	{
	fputs( line, fp2 ); 
	}
	
fclose( fp1 ); 
fclose( fp2 ); 
	
	return SUCCESS;
}



