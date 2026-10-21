#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
int main(){


	int N,M,i,j,s,k,l,cevap;
	char oyun[100][100]; 
    printf("Oynamak istediginiz boyutlari giriniz:\n");
    //printf("(20x10 onerilir.)\n");
    scanf("%d",&N); scanf("%d",&M);
    for(i=0;i<N;i++){
    	for(j=0;j<M;j++){
    		oyun[i][j]=' ';
		}
	}
	for(i=N;i<=N;i++){
		for(j=0;j<M;j++){
			oyun[i][j]='#';
		}
	}
	

	char matris1[1][1], matris2[2][2], matris30[4][1], matris31[1][4];
	char matrisL1[3][2], matrisL2[2][3], matrisL3[3][3], matrisL4[2][3];
	char matrisucdik[3][1], matrisikidik[2][1], matrisZ[2][3];
		for(k=0;k<1;k++){
		for(l=0;l<1;l++){
		matris1[k][l]='#';
		}
	}

	for(k=0;k<2;k++){
		for(l=0;l<2;l++){
			matris2[k][l]='#';
		}
	}

	for(k=0;k<4;k++){
		for(l=0;l<1;l++){
			matris30[k][l]='#';
		}
	}
	
	for(k=0;k<1;k++){
		for(l=0;l<4;l++){
			matris31[k][l]='#';
		}
	}
	
    matrisL1[0][0]='#'; matrisL1[1][0]='#'; matrisL1[2][0]='#'; matrisL1[0][1]=' '; matrisL1[1][1]=' '; matrisL1[2][1]='#';
    
	matrisL2[0][0]=' '; matrisL2[0][1]=' '; matrisL2[0][2]='#'; matrisL2[1][0]='#'; matrisL2[1][1]='#'; matrisL2[1][2]='#';
	
	matrisL3[0][0]='#'; matrisL3[0][1]='#'; matrisL3[1][0]=' '; matrisL3[1][1]='#'; matrisL3[2][0]=' '; matrisL3[2][1]='#';

	matrisL4[0][0]='#'; matrisL4[0][1]='#'; matrisL4[0][2]='#'; matrisL4[1][0]='#'; matrisL4[1][1]=' '; matrisL4[1][2]=' ';
	
    for(i=0;i<3;i++){
    	for(j=0;j<1;j++){
    		matrisucdik[i][j]='#';
		}
	}

	for(i=0;i<2;i++){
		for(j=0;j<1;j++){
			matrisikidik[i][j]='#';
		}
	}
	
	matrisZ[0][0]=' '; matrisZ[0][1]='#'; matrisZ[0][2]='#'; matrisZ[1][0]='#'; matrisZ[1][1]='#'; matrisZ[1][2]=' ';
	

    int skor = 0;
	char keep='a';
	char cevab;
	while(keep=='a'){ //oyun baþlangýçý
	int sekil;
    int a,sayac,score;	
    
    a=1;
	sayac=0;
	while(a<N){
		for(j=0;j<M;j++){
			if(oyun[a][j]=='#'){
				sayac=sayac+1;
			}else{
				
			}
		}                                //84-104 arasý satýr silme 
		if(sayac==M){
		   for(k=a;k>0;k--){
		   	for(l=0;l<M;l++){
		   		oyun[k][l]=oyun[k-1][l];
			   }
		   }
		    score=(a+1)*10;
		    skor=skor+score;
		}else{
			a=a+1;
		}
		sayac=0;
	}
	
	srand(time(NULL));
	sekil=1+rand()%9;
	system("cls");
	printf("\n\n\n");
	printf("~~~~~~~~~~~~~~~~~~~~~SKOR:%d~~~~~~~~~~~~~~~~~~~~~",skor);
	printf("\n\n\n");
	printf("_______TETRIS________");
	printf("\n\n\n\n\n"); 
		for(i=0;i<N;i++){
		//printf("\n");
    	for(j=0;j<M;j++){
    		printf("%c|",oyun[i][j]);
		}printf("\n");
	}
	
	//printf("Rastgele sekil = %d\n",sekil);
	//sekil=9;

	
	switch(sekil){             //þekillerin baþlangýçý
		case 1:
			for(i=0;i<1;i++){
				printf("\n");
				for(j=0;j<1;j++){
					printf("%c",matris1[i][j]);
				}
			}
						printf("\nSekli yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	        scanf(" %d",&s);
	        i=1;
	        while(oyun[i][s-1]==' '){
	        	i=i+1;}
				oyun[i-1][s-1]='#';
				for(i=0;i<N;i++){
					for(j=0;j<M;j++){	
						printf("%c|",oyun[i][j]);
					}printf("\n");
				}

			break;
		case 2:
			for(k=0;k<2;k++){
		    for(l=0;l<2;l++){
			printf("%c",matris2[k][l]);
		    }printf("\n");
	    }
	    	printf("\nSag alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
				scanf("%d",&s);
				i=1;
				while(oyun[i][s-1]==' ' && oyun[i][s-2]==' '){
					i=i+1;}
					oyun[i-1][s-1]='#';
					oyun[i-2][s-1]='#';
					oyun[i-1][s-2]='#';
					oyun[i-2][s-2]='#';
					for(i=0;i<N;i++){
					for(j=0;j<M;j++){
						printf("%c|",oyun[i][j]);
					}printf("\n");
				} 
	    break;
	    case 3:
	    	for(k=0;k<4;k++){
		    for(l=0;l<1;l++){
			printf("%c",matris30[k][l]);
		    }printf("\n");
	    }
	    printf("\nSekli dondurmek ister misiniz?\n");
	    printf("Evet icin e'ye, Hayir icin h'ye basiniz.\n");
	    scanf(" %c",&cevab);
	    switch(cevab){
	    	case 'e':
	    		for(k=0;k<1;k++){
		        for(l=0;l<4;l++){
			    printf("%c",matris31[k][l]);
		        }printf("\n");
	        }
						printf("\n1. '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
					scanf("%d",&s);
					i=1;
					while(oyun[i][s-1]==' ' && oyun[i][s]==' ' && oyun[i][s+1]==' ' && oyun[i][s+2]==' '){
						i=i+1;}
						oyun[i-1][s-1]='#';
						oyun[i-1][s]='#';
						oyun[i-1][s+1]='#';
						oyun[i-1][s+2]='#';
						for(i=0;i<N;i++){
					    for(j=0;j<M;j++){
						printf("%c|",oyun[i][j]);
					    }printf("\n");
				    } 
			 break;
	    	case 'h':
	    		for(k=0;k<4;k++){
		        for(l=0;l<1;l++){
			    printf("%c",matris30[k][l]);
		        }printf("\n");
	        } 
				printf("\nBaslatmak istediginiz sutunun numarasini giriniz:\n");
			    	scanf("%d",&s);
			    	i=1;
			    	while(oyun[i][s-1]==' '){
			    		i=i+1;}
			    		oyun[i-1][s-1]='#';
			    		oyun[i-2][s-1]='#';
			    		oyun[i-3][s-1]='#';
			    		oyun[i-4][s-1]='#';
			    		for(i=0;i<N;i++){
					    for(j=0;j<M;j++){
						printf("%c|",oyun[i][j]);
					    }printf("\n");
				    }
			break;
	    		
		} 
		break;
		case 4:
			
	printf("\n\n\n");
			
			for(i=0;i<3;i++){
		    for(j=0;j<2;j++){
			printf("%c",matrisL1[i][j]);
		    }printf("\n");
	    }
	    printf("\nSekli dondurmek ister misiniz?\n");
	    printf("Evet icin 1'e, Hayir icin 2'ye basiniz.\n");
	    scanf(" %d",&cevap);
	    if(cevap==1){
	    	for(i=0;i<2;i++){
		    for(j=0;j<3;j++){
			printf("%c",matrisL2[i][j]);
		    }printf("\n");
	    }
	    printf("\nSekli dondurmek ister misiniz?\n");
	    printf("Evet icin 1'e, Hayir icin 2'ye basiniz.\n");
	    scanf(" %d",&cevap);
	    if(cevap==1){
	    	for(i=0;i<3;i++){
		    for(j=0;j<2;j++){
			printf("%c",matrisL3[i][j]);
		    }printf("\n");
	    }
	  
	    printf("\nSekli dondurmek ister misiniz?\n");
	    printf("Evet icin 1'e, Hayir icin 2'ye basiniz.\n");
	    scanf(" %d",&cevap);
	    if(cevap==1){
	    	for(i=0;i<2;i++){
		    for(j=0;j<3;j++){
			printf("%c",matrisL4[i][j]);
		    }printf("\n");
	    } 
	    						printf("\nsol alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:");
						scanf("%d",&s);
						i=1;
						while(oyun[i][s-1]==' ' && oyun[i-1][s]==' ' && oyun[i-1][s+1]==' '){
							i=i+1;
						}
						oyun[i-1][s-1]='#';
						oyun[i-2][s-1]='#';
						oyun[i-2][s]='#';
						oyun[i-2][s+1]='#';
						for(i=0;i<N;i++){
					    for(j=0;j<M;j++){
						printf("%c|",oyun[i][j]);
					    }printf("\n");
				    }	
		}else{
			for(i=0;i<3;i++){
		    for(j=0;j<2;j++){
			printf("%c",matrisL3[i][j]);
		    }printf("\n");
	    }
	   							printf("\nsag alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:");
							scanf("%d",&s);
							i=2;
							while(oyun[i][s-1]==' ' && oyun[i-2][s-2]==' '){
								i=i+1;
							}
							oyun[i-3][s-2]='#';
							oyun[i-3][s-1]='#';
							oyun[i-2][s-1]='#';
							oyun[i-1][s-1]='#';
							for(i=0;i<N;i++){
					    for(j=0;j<M;j++){
						printf("%c|",oyun[i][j]);
					    }printf("\n");
				    }
		}
		}else{
			for(i=0;i<2;i++){
		    for(j=0;j<3;j++){
			printf("%c",matrisL2[i][j]);
		    }printf("\n");
	    }
	    						printf("\nsol alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun nuamarasini giriniz:");
						scanf("%d",&s);
						i=1;
						while(oyun[i][s-1]==' ' && oyun[i][s]==' ' && oyun[i][s+1]==' '){
							i=i+1;
						}
						
						oyun[i-1][s-1]='#';
						oyun[i-1][s]='#';
						oyun[i-1][s+1]='#';
						oyun[i-2][s+1]='#';
						for(i=0;i<N;i++){
					    for(j=0;j<M;j++){
						printf("%c|",oyun[i][j]);
					    }printf("\n");
				    }
		}
		}else{
			for(i=0;i<3;i++){
		    for(j=0;j<2;j++){
			printf("%c",matrisL1[i][j]);
		    }printf("\n");
	    }
	   					printf("\nsag alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:");
					scanf("%d",&s);
					i=1;
					while(oyun[i][s-1]==' ' && oyun[i][s-2]==' '){
						i=i+1;
					}
					oyun[i-1][s-1]='#';
					oyun[i-1][s-2]='#';
					oyun[i-2][s-2]='#';
					oyun[i-3][s-2]='#';
					for(i=0;i<N;i++){
					    for(j=0;j<M;j++){
						printf("%c|",oyun[i][j]);
					    }printf("\n");
				    }
		}
	    
		break;
		case 5:
			for(i=0;i<3;i++){
		    printf("\n");
    	    for(j=0;j<1;j++){
    		printf("%c",matrisucdik[i][j]);
		    }
	    }
	    printf("\nSekli dondurmek ister misiniz?\n");
	    printf("Evet icin 1'e, Hayir icin 2'ye basiniz.\n");
	    scanf(" %d",&cevap);
	    if(cevap==1){
	    	for(j=0;j<1;j++){
		    printf("\n");
		    for(i=2;i>=0;i--){
			printf("%c",matrisucdik[i][j]);
		    }
	      }
	    printf("\nIlk '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	    scanf("%d",&s);
	    i=1;
	    while(oyun[i][s-1]==' ' && oyun[i][s]==' ' && oyun[i][s+1]==' '){
	    	i=i+1;
		}
		oyun[i-1][s-1]='#';
		oyun[i-1][s]='#';
		oyun[i-1][s+1]='#';
		for(i=0;i<N;i++){
		for(j=0;j<M;j++){
		printf("%c|",oyun[i][j]);
		}printf("\n");
		}
	}else{
		printf("En alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	    scanf("%d",&s);
	    i=1;
	    while(oyun[i][s-1]==' '){
	    	i=i+1;
		}
		oyun[i-1][s-1]='#';
		oyun[i-2][s-1]='#';
		oyun[i-3][s-1]='#';
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
			printf("%c|",oyun[i][j]);
			}printf("\n");
	    }
		
	}
	break;
	
	case 6:
		for(j=0;j<1;j++){
		printf("\n");
		for(i=2;i>=0;i--){
		printf("%c",matrisucdik[i][j]);
		}
	}
	    printf("\nSekli dondurmek ister misiniz?\n");
	    printf("Evet icin 1'e, Hayir icin 2'ye basiniz.\n");
	    scanf(" %d",&cevap);
	    if(cevap==1){
	    	for(i=0;i<3;i++){
		    printf("\n");
    	    for(j=0;j<1;j++){
    		printf("%c",matrisucdik[i][j]);
		    }
	    }
	    printf("\nEn alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	    scanf("%d",&s);
	    i=1;
	    while(oyun[i][s-1]==' '){
	    	i=i+1;
		}
		oyun[i-1][s-1]='#';
		oyun[i-2][s-1]='#';
		oyun[i-3][s-1]='#';
		for(i=0;i<N;i++){
			for(j=0;j<M;j++){
			printf("%c|",oyun[i][j]);
			}printf("\n");
	    }
	}else{
		printf("\nIlk '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	    scanf("%d",&s);
	    i=1;
	    while(oyun[i][s-1]==' ' && oyun[i][s]==' ' && oyun[i][s+1]==' '){
	    	i=i+1;
		}
		oyun[i-1][s-1]='#';
		oyun[i-1][s]='#';
		oyun[i-1][s+1]='#';
		for(i=0;i<N;i++){
		for(j=0;j<M;j++){
		printf("%c|",oyun[i][j]);
		}printf("\n");
		}
	}
	break;
	
    case 7:
    	for(i=0;i<2;i++){
		printf("\n");
    	for(j=0;j<1;j++){
    	printf("%c",matrisikidik[i][j]);
		}
	}
	printf("\nSekli dondurmek ister misiniz?\n");
	printf("Evet icin 1'e, Hayir icin 2'ye basiniz.\n");
	scanf(" %d",&cevap);
	if(cevap==1){
		for(j=0;j<1;j++){
		printf("\n");
		for(i=1;i>=0;i--){
		printf("%c",matrisikidik[i][j]);
		}
	}
	printf("\nIlk '#' referans olmak uzere yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	scanf("%d",&s);
	i=1;
	while(oyun[i][s-1]==' ' && oyun[i][s]==' '){
		i=i+1;
	}
	oyun[i-1][s-1]='#';
	oyun[i-1][s]='#';
	for(i=0;i<N;i++){
	for(j=0;j<M;j++){
	printf("%c|",oyun[i][j]);
	}printf("\n");
    }
}else{
	printf("En alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	scanf("%d",&s);
	i=1;
	while(oyun[i][s-1]==' '){
		i=i+1;
	}
	oyun[i-1][s-1]='#';
	oyun[i-2][s-1]='#';
	for(i=0;i<N;i++){
	for(j=0;j<M;j++){
	printf("%c|",oyun[i][j]);
	}printf("\n");
	}
}
break;
   
    case 8:
    for(j=0;j<1;j++){
    printf("\n");
    for(i=1;i>=0;i--){
	printf("%c",matrisikidik[i][j]);
	}
   }
    printf("\nSekli dondurmek ister misiniz?\n");
	printf("Evet icin 1'e, Hayir icin 2'ye basiniz.\n");
	scanf(" %d",&cevap);
	if(cevap==1){
		for(i=0;i<2;i++){
		printf("\n");
    	for(j=0;j<1;j++){
    	printf("%c",matrisikidik[i][j]);
		}
	}
	printf("\nEn alt '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	scanf("%d",&s);
	i=1;
	while(oyun[i][s-1]==' '){
		i=i+1;
	}
	oyun[i-1][s-1]='#';
	oyun[i-2][s-1]='#';
	for(i=0;i<N;i++){
	for(j=0;j<M;j++){
	printf("%c|",oyun[i][j]);
	}printf("\n");
	}
}else{
	printf("\nIlk '#' referans olmak uzere yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	scanf("%d",&s);
	i=1;
	while(oyun[i][s-1]==' ' && oyun[i][s]==' '){
		i=i+1;
	}
	oyun[i-1][s-1]='#';
	oyun[i-1][s]='#';
	for(i=0;i<N;i++){
	for(j=0;j<M;j++){
	printf("%c|",oyun[i][j]);
	}printf("\n");
    }
}
break;

    case 9:
    	for(i=0;i<2;i++){
		printf("\n");
		for(j=0;j<3;j++){
			printf("%c",matrisZ[i][j]);
		}
	}
	printf("\nSekli dondurmek ister misiniz?\n");
	printf("Evet icin 1'e, Hayir icin 2'ye basiniz.\n");
	scanf(" %d",&cevap);
	if(cevap==1){
		for(j=0;j<3;j++){
		printf("\n");
		for(i=1;i>=0;i--){
		printf("%c",matrisZ[i][j]);
		}
	}
	printf("\nSol ust '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	scanf("%d",&s);
	i=1;
	while(oyun[i][s-1]==' ' && oyun[i+1][s]==' '){
		i=i+1;
	}
	if(oyun[i+1][s]=='#'){
		oyun[i][s]='#';
		oyun[i-1][s]='#';
		oyun[i-1][s-1]='#';
		oyun[i-2][s-1]='#';
	}else{
		oyun[i-1][s-1]='#';
		oyun[i-2][s-1]='#';
		oyun[i-1][s]='#';
		oyun[i][s]='#';
	}
	for(i=0;i<N;i++){
	for(j=0;j<M;j++){
	printf("%c|",oyun[i][j]);
	}printf("\n");
    }
	
}else{
	printf("\nSol ust '#' referans olmak uzere, yerlestirmek istediginiz sutunun numarasini giriniz:\n");
	scanf("%d",&s);
	i=1;
	while(oyun[i][s-2]==' ' && oyun[i][s-1]==' ' && oyun[i-1][s]==' '){
		i=i+1;
	}
	if(oyun[i-1][s]=='#'){
		oyun[i-1][s-1]='#';
		oyun[i-1][s-2]='#';
		oyun[i-2][s-1]='#';
		oyun[i-2][s]='#';
	}else{
		oyun[i-1][s-2]='#';
		oyun[i-1][s-1]='#';
		oyun[i-2][s-1]='#';
		oyun[i-2][s]='#';
	}
	for(i=0;i<N;i++){
	for(j=0;j<M;j++){
	printf("%c|",oyun[i][j]);
	}printf("\n");
    }
}
	break;
    
	    
	}  //þekillerin bitiþi
	
	int sayac1,t;
	sayac1=0;
	t=0;
	while(t<M && sayac1!=1){
		if(oyun[0][t]=='#'){
			sayac1=sayac1+1;
		keep='z';	
		}else{
			
		}
		t=t+1;
	}
	
		
	}   // while bitiþi
	
    printf("oyun bitti.");
	
	return 0;
	getch();
}
