#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void easyMode();
void mediumMode();
void hardMode();

int main(){
	 int difficulty;
	 
     printf("Merhaba,kart tahmin oyununa hosgeldin!\n");
     printf("Zorluk secimini yapiniz:(Kolay:1 Orta:2 Zor:3)\nSecim:");
     scanf("%d",&difficulty);
     
     if(difficulty==1){
     	easyMode();
	 }else if(difficulty==2){
	 	mediumMode();
	 }else if(difficulty==3){
	 	hardMode();
	 }else{
	 	printf("YANLIS SECIM..\n");
	 }
	 
	  system("pause");
	  
	return 0;
}
void hardMode(){
	system("color 1");
	int x=0,gameTable[8][8],isGameFinished=0,pcMemoryValues[16],pcMemoryX[16],pcMemoryY[16],i,j,k,m,assignedNumber=1,pcGuesses=0,playerGuesses=0,receivedRow,receivedColumn,randomNumber;
	int playerTurn=1,pcTurn=0,receivedRow2,receivedColumn2,playerTrueGuesses=0,pcTrueGuesses=0,pcRow,pcColumn,pcRow2,pcColumn2,h=0,isThere_A_Pair;
	
	srand(time(NULL));
     
    for(i=0;i<16;i++){
    	pcMemoryValues[i]=0;
	}
	
    for(i=0;i<8;i++){
    	for(j=0;j<8;j++){
    		gameTable[i][j]=-1;
		}
	} 

    while(assignedNumber<33){	
	    	k=rand()%8;
        	m=rand()%8;
     	
          if(gameTable[k][m]==-1){
         	 gameTable[k][m]=assignedNumber;
             x++;
               if(x%2==0){
        	     assignedNumber++;
		       }
	       }
   }
	
    
    printf("\n                OYUN TAHTASI\n");
	printf("  ");
	for(j=0;j<8;j++){
		printf("   %d. ",j+1);
	}printf("\n");
	for(i=0;i<8;i++){
		printf("%d.",i+1);
    	for(j=0;j<8;j++){
    		printf(" |%2d| ",gameTable[i][j]);
		}printf("\n");
	}
	
	printf("\n\nOYUN BASLIYORRR..");
	sleep(6);
	
	while(isGameFinished==0){
		 
		while(playerTurn==1){
			sleep(2);
			system("CLS");
			printf("Oyun tahtasi anlik durum:\n");
		    
		    	printf("  ");
	       for(j=0;j<8;j++){
	        	printf("  %d. ",j+1);
	        }
			 printf("\n");
	       for(i=0;i<8;i++){
	        	printf("%d.",i+1);
    	          for(j=0;j<8;j++){
    	          	if(gameTable[i][j]!=-1)
    	     	       printf(" |*| ",gameTable[i][j]);
    	     	    else
    	     	      printf(" |-| ");
	        	}printf("\n");
	       }
		    
			printf("Oyun Sirasi:Oyuncu\n");
			printf("Acmak istediginiz satir ve sutunu sirayla yazin:");
			scanf("%d",&receivedRow);
			scanf("%d",&receivedColumn);
			
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(i==receivedRow-1&&j==receivedColumn-1){
						if(gameTable[receivedRow-1][receivedColumn-1]!=-1)
						   printf("|%3d|",gameTable[receivedRow-1][receivedColumn-1]);
						else
						   printf("| x |");
					}else if(gameTable[i][j]==-1){
						 printf("| - |");
						
					}else{
						printf("| * |");
					}
				}printf("\n");
			}
			
			printf("Oyun Sirasi:Oyuncu\n");
			printf("Acmak istediginiz satir ve sutunu sirayla yazin:");
			scanf("%d",&receivedRow2);
			scanf("%d",&receivedColumn2);
			
			playerGuesses++;
			
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if((i==receivedRow2-1)&&(j==receivedColumn2-1)){
						if(gameTable[receivedRow2-1][receivedColumn2-1]!=-1)
				           printf("|%3d|",gameTable[receivedRow2-1][receivedColumn2-1]);
				        else
						   printf("| x |");  
					}else if(gameTable[i][j]==-1){
						 printf("| - |");						
					}else{
						printf("| * |");
					}
				}printf("\n");
			}
			
						
			if(((gameTable[receivedRow-1][receivedColumn-1]==gameTable[receivedRow2-1][receivedColumn2-1])&&((receivedRow-1!=receivedRow2-1)||(receivedColumn-1!=receivedColumn2-1)))&&gameTable[receivedRow-1][receivedColumn-1]!=-1){
				  gameTable[receivedRow-1][receivedColumn-1]=-1;
				  gameTable[receivedRow2-1][receivedColumn2-1]=-1;
				  playerTrueGuesses++;
				  playerTurn=1;
				  pcTurn=0;
				  printf("\nTebrikler,bir cift buldunuz.\n");
				  
				if(playerTrueGuesses>16||pcTrueGuesses>16){
					 if(playerTrueGuesses>pcTrueGuesses){
					 	printf("Oyuncu Kazandi,toplam tahmin sayiniz:%d\nToplam dogru tahmin sayiniz:%d\n",playerGuesses,playerTrueGuesses);
					 	playerTurn=0;
					 	isGameFinished=1;
					 }else{
					 	printf("pc kazandi,pcnin toplam tahmin sayisi:%d\nPCnin toplam dogru tahmin sayisi:%d\n",pcGuesses,pcTrueGuesses);
					 	isGameFinished=1;
					 	playerTurn=0;
					 }
				}  
				
				
				if(playerTrueGuesses==16&&pcTrueGuesses==16){
					isGameFinished=1;
					playerTurn=0;
					printf("OYUN BERABERE BITTI...");
				}
			}else{
				printf("\nYanlis eslesme\n");
				playerTurn=0;
			    pcTurn=1;
			    
			   pcMemoryValues[h]=gameTable[receivedRow-1][receivedColumn-1];
			   pcMemoryX[h]=receivedRow-1;
			   pcMemoryY[h]=receivedColumn-1;
			   h++;
			   if(h==16){
			   	h=0;
			   }
			   pcMemoryValues[h]=gameTable[receivedRow2-1][receivedColumn2-1];
			   pcMemoryX[h]=receivedRow2-1;
			   pcMemoryY[h]=receivedColumn2-1;
			   h++;
			   if(h==16){
			   	h=0;
			   }
			   
			}
			
		}
		while(pcTurn==1){
			isThere_A_Pair=0;
			sleep(2);
			system("CLS");
			printf("\nOyun Sirasi:PC\n");
			
			do{
				pcRow=rand()%8;
				pcColumn=rand()%8;
			}while(gameTable[pcRow][pcColumn]==-1);
		
			pcGuesses++;
			pcTurn=0;
			playerTurn=1;
			
			do{
				pcRow2=rand()%8;
				pcColumn2=rand()%8;
			}while(gameTable[pcRow2][pcColumn2]==-1);
        	
        	
        	for(i=0;i<16;i++){
        		for(j=i+1;j<16;j++){
        			if(((pcMemoryValues[i]==pcMemoryValues[j])&&pcMemoryValues[i]!=0)&&(pcMemoryX[j]!=pcMemoryX[i]||pcMemoryY[j]!=pcMemoryY[i])){
        				pcRow=pcMemoryX[i];
					    pcColumn=pcMemoryY[i];
				    	pcMemoryX[i]=0;
				    	pcMemoryY[i]=0;
				     	pcMemoryValues[i]=0;	
				    	pcRow2=pcMemoryX[j];
				    	pcColumn2=pcMemoryY[j];
				    	pcMemoryX[j]=0;
				     	pcMemoryY[j]=0;
				    	pcMemoryValues[j]=0;
					    isThere_A_Pair=1;
        				
					}
				}
			}
        	
        	if(isThere_A_Pair==0){
		    	for(i=0;i<8;i++){
			     	if((gameTable[pcRow][pcColumn]==pcMemoryValues[i])&&(pcRow!=pcMemoryX[i]||pcColumn!=pcMemoryY[i])){
				    	pcRow2=pcMemoryX[i];
				    	pcColumn2=pcMemoryY[i];
				    	pcMemoryX[i]=0;
				    	pcMemoryY[i]=0;
				    	pcMemoryValues[i]=0;
			    	}else if((gameTable[pcRow2][pcColumn2]==pcMemoryValues[i])&&(pcRow2!=pcMemoryX[i]||pcColumn2!=pcMemoryY[i])){
				    	pcRow=pcMemoryX[i];
				    	pcColumn=pcMemoryY[i];
					    pcMemoryX[i]=0;
					    pcMemoryY[i]=0;
				     	pcMemoryValues[i]=0;
			     	}
		    	}
	 	   }
			
			
			printf("Bilgisayarin ilk tahmini\n");
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(i==pcRow&&j==pcColumn){
						if(gameTable[pcRow][pcColumn]!=-1){
								printf("|%3d|",gameTable[pcRow][pcColumn]);
						}
						else{
							printf("| x |");
						}
					}else if(gameTable[i][j]==-1){
						 printf("| - |");
						
					}else{
						printf("| * |");
					}
				}printf("\n");
			}
			printf("Bilgisayarin ikinci tahmini\n");
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
					if(i==pcRow2&&j==pcColumn2){
						if(gameTable[pcRow2][pcColumn2]!=-1){
								printf("|%3d|",gameTable[pcRow2][pcColumn2]);
						}
						else{
							printf("| x |");
						}
					}else if(gameTable[i][j]==-1){
						 printf("| - |");
						
					}else{
						printf("| * |");
					}
				}printf("\n");
			}
			
			
			if(((gameTable[pcRow][pcColumn]==gameTable[pcRow2][pcColumn2])&&((pcRow!=pcRow2)||(pcColumn!=pcColumn2)))&&gameTable[pcRow][pcColumn]!=-1){
				  gameTable[pcRow][pcColumn]=-1;
				  gameTable[pcRow2][pcColumn2]=-1;
				  pcTrueGuesses++;
				  playerTurn=0;
				  pcTurn=1;
				  printf("\nBilgisayar bir cift buldu..\n");
				  
				  if(playerTrueGuesses==16&&pcTrueGuesses==16){
					isGameFinished=1;
					pcTurn=0;
					printf("OYUN BERABERE BITTI...");
				}
			}else{
				printf("\nBilgisayar yanlis tahmin yapti..\n");
				pcMemoryValues[h]=gameTable[pcRow][pcColumn];
			    pcMemoryX[h]=pcRow;
			    pcMemoryY[h]=pcColumn;
			    h++;
			    if(h==16){
			    	h=0;
				}
			   pcMemoryValues[h]=gameTable[pcRow2][pcColumn2];
			   pcMemoryX[h]=pcRow2;
			   pcMemoryY[h]=pcColumn2;
			   h++;
			   if(h==16){
			   	h=0;
			   }
			}
					
			
			if(playerTrueGuesses>16||pcTrueGuesses>16){
					 if(playerTrueGuesses>pcTrueGuesses){
					 	printf("Oyuncu Kazandi,toplam tahmin sayiniz:%d\nToplam dogru tahmin sayiniz:%d\n",playerGuesses,playerTrueGuesses);
					 	pcTurn=0;
					 	isGameFinished=1;
					 }else{
					 	printf("PC kazandi,PCnin toplam tahmin sayisi:%d\nPCnin toplam dogru tahmin sayisi:%d\n",pcGuesses,pcTrueGuesses);
					 	isGameFinished=1;
					 	pcTurn=0;
					 }
			}  
		}
	}
}
void mediumMode(){
	    system("color 3");
		int x=0,gameTable[6][6],isGameFinished=0,pcMemoryValues[6],pcMemoryX[6],pcMemoryY[6],i,j,k,m,assignedNumber=1,pcGuesses=0,playerGuesses=0,receivedRow,receivedColumn,randomNumber;
		int playerTurn=1,pcTurn=0,receivedRow2,receivedColumn2,playerTrueGuesses=0,pcTrueGuesses=0,pcRow,pcColumn,pcRow2,pcColumn2,h=0,isThere_A_Pair;
		
	  srand(time(NULL));
	  
      for(i=0;i<6;i++){
     	pcMemoryValues[i]=0;
	  }
	 
     for(i=0;i<6;i++){
    	for(j=0;j<6;j++){
    		gameTable[i][j]=-1;
		}
	} 

    while(assignedNumber<19){	
	    	k=rand()%6;
        	m=rand()%6;
     	
          if(gameTable[k][m]==-1){
         	 gameTable[k][m]=assignedNumber;
             x++;
               if(x%2==0){
        	     assignedNumber++;
		       }
	       }
   }
	
    
    printf("\n            OYUN TAHTASI\n");
	printf("  ");
	for(j=0;j<6;j++){
		printf("   %d. ",j+1);
	}printf("\n");
	for(i=0;i<6;i++){
		printf("%d.",i+1);
    	for(j=0;j<6;j++){
    		printf(" |%2d| ",gameTable[i][j]);
		}printf("\n");
	}
	
	printf("\n\nOYUN BASLIYORRR..");
	sleep(6);
	
	while(isGameFinished==0){
		 
		while(playerTurn==1){
			sleep(2);
			system("CLS");
			printf("Oyun tahtasi anlik durum:\n");
		    
		    	printf("  ");
	       for(j=0;j<6;j++){
	        	printf("  %d. ",j+1);
	        }
			 printf("\n");
	       for(i=0;i<6;i++){
	        	printf("%d.",i+1);
    	          for(j=0;j<6;j++){
    	          	if(gameTable[i][j]!=-1)
    	     	       printf(" |*| ",gameTable[i][j]);
    	     	    else
    	     	      printf(" |-| ");
	        	}printf("\n");
	       }
		    
			printf("Oyun Sirasi:Oyuncu\n");
			printf("Acmak istediginiz satir ve sutunu sirayla yazin:");
			scanf("%d",&receivedRow);
			scanf("%d",&receivedColumn);
			
			for(i=0;i<6;i++){
				for(j=0;j<6;j++){
					if(i==receivedRow-1&&j==receivedColumn-1){
						if(gameTable[receivedRow-1][receivedColumn-1]!=-1)
						   printf("|%3d|",gameTable[receivedRow-1][receivedColumn-1]);
						else
						   printf("| x |");
					}else if(gameTable[i][j]==-1){
						 printf("| - |");
						
					}else{
						printf("| * |");
					}
				}printf("\n");
			}
			
			printf("Oyun Sirasi:Oyuncu\n");
			printf("Acmak istediginiz satir ve sutunu sirayla yazin:");
			scanf("%d",&receivedRow2);
			scanf("%d",&receivedColumn2);
			
			playerGuesses++;
			
			for(i=0;i<6;i++){
				for(j=0;j<6;j++){
					if((i==receivedRow2-1)&&(j==receivedColumn2-1)){
						if(gameTable[receivedRow2-1][receivedColumn2-1]!=-1)
				           printf("|%3d|",gameTable[receivedRow2-1][receivedColumn2-1]);
				        else
						   printf("| x |");  
					}else if(gameTable[i][j]==-1){
						 printf("| - |");						
					}else{
						printf("| * |");
					}
				}printf("\n");
			}
			
			
			
			if(((gameTable[receivedRow-1][receivedColumn-1]==gameTable[receivedRow2-1][receivedColumn2-1])&&((receivedRow-1!=receivedRow2-1)||(receivedColumn-1!=receivedColumn2-1)))&&gameTable[receivedRow-1][receivedColumn-1]!=-1){
				  gameTable[receivedRow-1][receivedColumn-1]=-1;
				  gameTable[receivedRow2-1][receivedColumn2-1]=-1;
				  playerTrueGuesses++;
				  playerTurn=1;
				  pcTurn=0;
				  printf("\nTebrikler,bir cift buldunuz.\n");
				  
				  if(playerTrueGuesses==8&&pcTrueGuesses==8){
					isGameFinished=1;
					playerTurn=0;
					printf("OYUN BERABERE BITTI...");
				}
				  
				if(playerTrueGuesses>9||pcTrueGuesses>9){
					 if(playerTrueGuesses>pcTrueGuesses){
					 	printf("Oyuncu Kazandi,toplam tahmin sayiniz:%d\nToplam dogru tahmin sayiniz:%d\n",playerGuesses,playerTrueGuesses);
					 	playerTurn=0;
					 	isGameFinished=1;
					 }else{
					 	printf("pc kazandi,pcnin toplam tahmin sayisi:%d\nPCnin toplam dogru tahmin sayisi:%d\n",pcGuesses,pcTrueGuesses);
					 	isGameFinished=1;
					 	playerTurn=0;
					 }
				}  
			}else{
				printf("\nYanlis eslesme\n");
				playerTurn=0;
			    pcTurn=1;
			    
			   pcMemoryValues[h]=gameTable[receivedRow-1][receivedColumn-1];
			   pcMemoryX[h]=receivedRow-1;
			   pcMemoryY[h]=receivedColumn-1;
			   h++;
			   if(h==6){
			   	h=0;
			   }
			   pcMemoryValues[h]=gameTable[receivedRow2-1][receivedColumn2-1];
			   pcMemoryX[h]=receivedRow2-1;
			   pcMemoryY[h]=receivedColumn2-1;
			   h++;
			   if(h==6){
			   	h=0;
			   }
			   
			}
			
		}
		while(pcTurn==1){
			isThere_A_Pair=0;
			sleep(2);
			system("CLS");
			printf("\nOyun Sirasi:PC\n");
			
			do{
				pcRow=rand()%6;
				pcColumn=rand()%6;
			}while(gameTable[pcRow][pcColumn]==-1);
		
			pcGuesses++;
			pcTurn=0;
			playerTurn=1;
			
			do{
				pcRow2=rand()%6;
				pcColumn2=rand()%6;
			}while(gameTable[pcRow2][pcColumn2]==-1);
			
			
			for(i=0;i<6;i++){
        		for(j=i+1;j<6;j++){
        			if(((pcMemoryValues[i]==pcMemoryValues[j])&&pcMemoryValues[i]!=0)&&(pcMemoryX[j]!=pcMemoryX[i]||pcMemoryY[j]!=pcMemoryY[i])){
        				pcRow=pcMemoryX[i];
					    pcColumn=pcMemoryY[i];
				    	pcMemoryX[i]=0;
				    	pcMemoryY[i]=0;
				     	pcMemoryValues[i]=0;	
				    	pcRow2=pcMemoryX[j];
				    	pcColumn2=pcMemoryY[j];
				    	pcMemoryX[j]=0;
				     	pcMemoryY[j]=0;
				    	pcMemoryValues[j]=0;
					    isThere_A_Pair=1;
        				
					}
				}
			}
        	
        	if(isThere_A_Pair==0){	
			   for(i=0;i<6;i++){
			    	if((gameTable[pcRow][pcColumn]==pcMemoryValues[i])&&(pcRow!=pcMemoryX[i]||pcColumn!=pcMemoryY[i])){
				      	pcRow2=pcMemoryX[i];
					    pcColumn2=pcMemoryY[i];
					    pcMemoryX[i]=0;
					    pcMemoryY[i]=0;
					    pcMemoryValues[i]=0;
			    	}else if((gameTable[pcRow2][pcColumn2]==pcMemoryValues[i])&&(pcRow2!=pcMemoryX[i]||pcColumn2!=pcMemoryY[i])){
				     	pcRow=pcMemoryX[i];
				    	pcColumn=pcMemoryY[i];
					    pcMemoryX[i]=0;
					    pcMemoryY[i]=0;
				    	pcMemoryValues[i]=0;
			     	}
			 }
		 }
		
			
			printf("Bilgisayarin ilk tahmini\n");
			for(i=0;i<6;i++){
				for(j=0;j<6;j++){
					if(i==pcRow&&j==pcColumn){
						if(gameTable[pcRow][pcColumn]!=-1){
								printf("|%3d|",gameTable[pcRow][pcColumn]);
						}
						else{
							printf("| x |");
						}
					}else if(gameTable[i][j]==-1){
						 printf("| - |");
						
					}else{
						printf("| * |");
					}
				}printf("\n");
			}
			
			printf("Bilgisayarin ikinci tahmini\n");
			for(i=0;i<6;i++){
				for(j=0;j<6;j++){
					if(i==pcRow2&&j==pcColumn2){
						if(gameTable[pcRow2][pcColumn2]!=-1){
								printf("|%3d|",gameTable[pcRow2][pcColumn2]);
						}
						else{
							printf("| x |");
						}
					}else if(gameTable[i][j]==-1){
						 printf("| - |");
						
					}else{
						printf("| * |");
					}
				}printf("\n");
			}
			
			
			if(((gameTable[pcRow][pcColumn]==gameTable[pcRow2][pcColumn2])&&((pcRow!=pcRow2)||(pcColumn!=pcColumn2)))&&gameTable[pcRow][pcColumn]!=-1){
				  gameTable[pcRow][pcColumn]=-1;
				  gameTable[pcRow2][pcColumn2]=-1;
				  pcTrueGuesses++;
				  playerTurn=0;
				  pcTurn=1;
				  printf("\nBilgisayar bir cift buldu..\n");
				  
				  if(playerTrueGuesses==8&&pcTrueGuesses==8){
					isGameFinished=1;
					pcTurn=0;
					printf("OYUN BERABERE BITTI...");
				}
			}else{
				printf("\nBilgisayar yanlis tahmin yapti..\n");
				pcMemoryValues[h]=gameTable[pcRow][pcColumn];
			    pcMemoryX[h]=pcRow;
			    pcMemoryY[h]=pcColumn;
			    h++;
			    if(h==6){
			    	h=0;
				}
			   pcMemoryValues[h]=gameTable[pcRow2][pcColumn2];
			   pcMemoryX[h]=pcRow2;
			   pcMemoryY[h]=pcColumn2;
			   h++;
			   if(h==6){
			   	h=0;
			   }
			}
				
			
			if(playerTrueGuesses>9||pcTrueGuesses>9){
					 if(playerTrueGuesses>pcTrueGuesses){
					 	printf("Oyuncu Kazandi,toplam tahmin sayiniz:%d\nToplam dogru tahmin sayiniz:%d\n",playerGuesses,playerTrueGuesses);
					 	pcTurn=0;
					 	isGameFinished=1;
					 }else{
					 	printf("PC kazandi,PCnin toplam tahmin sayisi:%d\nPCnin toplam dogru tahmin sayisi:%d\n",pcGuesses,pcTrueGuesses);
					 	isGameFinished=1;
					 	pcTurn=0;
					 }
				}  
		}
	}
}
void easyMode(){
	system("color 2");
	int x=0,gameTable[4][4],isGameFinished=0,pcMemoryValues[2],pcMemoryX[2],pcMemoryY[2],i,j,k,m,assignedNumber=1,pcGuesses=0,playerGuesses=0,receivedRow,receivedColumn,randomNumber;
	int playerTurn=1,pcTurn=0,receivedRow2,receivedColumn2,playerTrueGuesses=0,pcTrueGuesses=0,pcRow,pcColumn,pcRow2,pcColumn2;
	
	srand(time(NULL));

    for(i=0;i<4;i++){
    	for(j=0;j<4;j++){
    		gameTable[i][j]=-1;
		}
	} 

    while(assignedNumber<9){	
	    	k=rand()%4;
        	m=rand()%4;
     	
          if(gameTable[k][m]==-1){
         	 gameTable[k][m]=assignedNumber;
             x++;
               if(x%2==0){
        	     assignedNumber++;
		       }
	       }
   }
	
    
    printf("\n      OYUN TAHTASI\n");
	printf("  ");
	for(j=0;j<4;j++){
		printf("  %d. ",j+1);
	}printf("\n");
	for(i=0;i<4;i++){
		printf("%d.",i+1);
    	for(j=0;j<4;j++){
    		printf(" |%d| ",gameTable[i][j]);
		}printf("\n");
	}
	
	printf("\n\nOYUN BASLIYORRR..");
	sleep(6);
	
	while(isGameFinished==0){
		 
		while(playerTurn==1){
			sleep(2);
			system("CLS");
			printf("Oyun tahtasi anlik durum:\n");
		    
		    	printf("  ");
	       for(j=0;j<4;j++){
	        	printf("  %d. ",j+1);
	        }
			 printf("\n");
	       for(i=0;i<4;i++){
	        	printf("%d.",i+1);
    	          for(j=0;j<4;j++){
    	          	if(gameTable[i][j]!=-1)
    	     	       printf(" |*| ",gameTable[i][j]);
    	     	    else
    	     	      printf(" |-| ");
	        	}printf("\n");
	       }
		    
			printf("Oyun Sirasi:Oyuncu\n");
			printf("Acmak istediginiz satir ve sutunu sirayla yazin:");
			scanf("%d",&receivedRow);
			scanf("%d",&receivedColumn);
			
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(i==receivedRow-1&&j==receivedColumn-1){
						if(gameTable[receivedRow-1][receivedColumn-1]!=-1)
						   printf("|%d|",gameTable[receivedRow-1][receivedColumn-1]);
						else
						   printf("|x|");
					}else if(gameTable[i][j]==-1){
						 printf("|-|");
						
					}else{
						printf("|*|");
					}
				}printf("\n");
			}
			
			printf("Oyun Sirasi:Oyuncu\n");
			printf("Acmak istediginiz satir ve sutunu sirayla yazin:");
			scanf("%d",&receivedRow2);
			scanf("%d",&receivedColumn2);
			
			playerGuesses++;
			
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if((i==receivedRow2-1)&&(j==receivedColumn2-1)){
						if(gameTable[receivedRow2-1][receivedColumn2-1]!=-1)
				           printf("|%d|",gameTable[receivedRow2-1][receivedColumn2-1]);
				        else
						   printf("|x|");  
					}else if(gameTable[i][j]==-1){
						 printf("|-|");						
					}else{
						printf("|*|");
					}
				}printf("\n");
			}
			
			
			
			if(((gameTable[receivedRow-1][receivedColumn-1]==gameTable[receivedRow2-1][receivedColumn2-1])&&((receivedRow-1!=receivedRow2-1)||(receivedColumn-1!=receivedColumn2-1)))&&gameTable[receivedRow-1][receivedColumn-1]!=-1){
				  gameTable[receivedRow-1][receivedColumn-1]=-1;
				  gameTable[receivedRow2-1][receivedColumn2-1]=-1;
				  playerTrueGuesses++;
				  playerTurn=1;
				  pcTurn=0;
				  printf("\nTebrikler,bir cift buldunuz.\n");
				  
				  if(playerTrueGuesses==4&&pcTrueGuesses==4){
					isGameFinished=1;
					playerTurn=0;
					printf("OYUN BERABERE BITTI...\n");
				}
				  
				if(playerTrueGuesses>4||pcTrueGuesses>4){
					 if(playerTrueGuesses>pcTrueGuesses){
					 	printf("Oyuncu Kazandi,toplam tahmin sayiniz:%d\nToplam dogru tahmin sayiniz:%d\n",playerGuesses,playerTrueGuesses);
					 	playerTurn=0;
					 	isGameFinished=1;
					 }else{
					 	printf("pc kazandi,pcnin toplam tahmin sayisi:%d\nPCnin toplam dogru tahmin sayisi:%d\n",pcGuesses,pcTrueGuesses);
					 	isGameFinished=1;
					 	playerTurn=0;
					 }
				}  
			}else{
				printf("\nYanlis eslesme\n");
				playerTurn=0;
			    pcTurn=1;
			    
			   pcMemoryValues[0]=gameTable[receivedRow-1][receivedColumn-1];
			   pcMemoryX[0]=receivedRow-1;
			   pcMemoryY[0]=receivedColumn-1;
			   pcMemoryValues[1]=gameTable[receivedRow2-1][receivedColumn2-1];
			   pcMemoryX[1]=receivedRow2-1;
			   pcMemoryY[1]=receivedColumn2-1;
			   
			}
			
		}
		while(pcTurn==1){
			sleep(2);
			system("CLS");
			printf("\nOyun Sirasi:PC\n");
			
			do{
				pcRow=rand()%4;
				pcColumn=rand()%4;
			}while(gameTable[pcRow][pcColumn]==-1);
			
			pcGuesses++;
			pcTurn=0;
			playerTurn=1;
			
			do{
				pcRow2=rand()%4;
				pcColumn2=rand()%4;
			}while(gameTable[pcRow2][pcColumn2]==-1);
        	
			for(i=0;i<2;i++){
				if((gameTable[pcRow][pcColumn]==pcMemoryValues[i])&&(pcRow!=pcMemoryX[i]||pcColumn!=pcMemoryY[i])){
					pcRow2=pcMemoryX[i];
					pcColumn2=pcMemoryY[i];
					pcMemoryX[i]=0;
					pcMemoryY[i]=0;
				}else if((gameTable[pcRow2][pcColumn2]==pcMemoryValues[i])&&(pcRow2!=pcMemoryX[i]||pcColumn2!=pcMemoryY[i])){
					pcRow=pcMemoryX[i];
					pcColumn=pcMemoryY[i];
					pcMemoryX[i]=0;
					pcMemoryY[i]=0;
					
				}
			}
			
			
			printf("Bilgisayarin ilk tahmini\n");
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(i==pcRow&&j==pcColumn){
						if(gameTable[pcRow][pcColumn]!=-1){
								printf("|%d|",gameTable[pcRow][pcColumn]);
						}
						else{
							printf("|x|");
						}
					}else if(gameTable[i][j]==-1){
						 printf("|-|");
						
					}else{
						printf("|*|");
					}
				}printf("\n");
			}
			
			printf("Bilgisayarin ikinci tahmini\n");
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(i==pcRow2&&j==pcColumn2){
						if(gameTable[pcRow2][pcColumn2]!=-1){
								printf("|%d|",gameTable[pcRow2][pcColumn2]);
						}
						else{
							printf("|x|");
						}
					}else if(gameTable[i][j]==-1){
						 printf("|-|");
						
					}else{
						printf("|*|");
					}
				}printf("\n");
			}
			
			
			if(((gameTable[pcRow][pcColumn]==gameTable[pcRow2][pcColumn2])&&((pcRow!=pcRow2)||(pcColumn!=pcColumn2)))&&gameTable[pcRow][pcColumn]!=-1){
				  gameTable[pcRow][pcColumn]=-1;
				  gameTable[pcRow2][pcColumn2]=-1;
				  pcTrueGuesses++;
				  playerTurn=0;
				  pcTurn=1;
				  printf("\nBilgisayar bir cift buldu..\n");
				  
				  if(playerTrueGuesses==4&&pcTrueGuesses==4){
					isGameFinished=1;
					pcTurn=0;
					printf("OYUN BERABERE BITTI...\n");
				}
			}else{
				printf("\nbilgisayar yanlis tahmin yapti..\n");
			}
					
			
			if(playerTrueGuesses>4||pcTrueGuesses>4){
					 if(playerTrueGuesses>pcTrueGuesses){
					 	printf("Oyuncu Kazandi,toplam tahmin sayiniz:%d\nToplam dogru tahmin sayiniz:%d\n",playerGuesses,playerTrueGuesses);
					 	pcTurn=0;
					 	isGameFinished=1;
					 }else{
					 	printf("pc kazandi,pcnin toplam tahmin sayisi:%d\nPCnin toplam dogru tahmin sayisi:%d\n",pcGuesses,pcTrueGuesses);
					 	isGameFinished=1;
					 	pcTurn=0;
					 }
			}  
		}
	}
	
}
