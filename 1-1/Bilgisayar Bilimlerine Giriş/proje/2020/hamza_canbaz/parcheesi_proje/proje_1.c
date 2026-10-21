#include<stdio.h>
#include<time.h>

// Roll Function
int rollTheDice(){
	return (rand()%6 + 1);
}


// Display Game Board
void displayBoard(int rows, int cols, int board[rows][cols]){
	printf("\n");
	printf("\n");
	printf("_______________________________________________________________");
	
	int i,j;
	for(i=0;i<9;i++){
		printf("\n");
		
		for(j=0;j<9;j++){
			if (board[i][j]<10){
				if(board[i][j]==-1){
					printf("|      ",board[i][j]);
				}
				else{
					printf("|   %d  ",board[i][j]);
				}
			}
				
			else{
				
					printf("|  %d  ",board[i][j]);
			}
				
			if(j==8)
				printf("|\n");
		}
		printf("|______|______|______|______|______|______|______|______|______|");
		
		
	}
	printf("\n");
	printf("\n");
}


// update game baord
void update(int row,int col,int board[row][col],int len,int rota[len]){
	
	board[3][0]= rota[0];	board[3][1]= rota[1];
	board[3][2]= rota[2];	board[3][3]= rota[3];
	board[2][3]= rota[4];	board[1][3]= rota[5];
	board[0][3]= rota[6];	board[0][4]= rota[7];
	board[0][5]= rota[8];	board[1][5]= rota[9];
	board[2][5]= rota[10];	board[3][5]= rota[11];
	board[3][6]= rota[12];	board[3][7]= rota[13];
	board[3][8]= rota[14];	board[4][8]= rota[15];
	board[5][8]= rota[16];	board[5][7]= rota[17];
	board[5][6]= rota[18];	board[5][5]= rota[19];
	board[6][5]= rota[20];	board[7][5]= rota[21];
	board[8][5]= rota[22];	board[8][4]= rota[23];
	board[8][3]= rota[24];	board[7][3]= rota[25];
	board[6][3]= rota[26];	board[5][3]= rota[27];
	board[5][2]= rota[28];	board[5][1]= rota[29];
	board[5][0]= rota[30];	board[4][0]= rota[31];
	
}
// update yellows nest
void yellowToBoard(int row,int col,int board[row][col],int i,int j, int yellow[i][j]){
		board[0][0]=yellow[0][0];
		board[0][1]=yellow[0][1];
		board[1][0]=yellow[1][0];
		board[1][1]=yellow[1][1];
}
// update reds nest
void redToBoard(int row,int col,int board[row][col],int i,int j, int red[i][j]){
		board[0][7]=red[0][0];
		board[0][8]=red[0][1];
		board[1][7]=red[1][0];
		board[1][8]=red[1][1];
}
// update greens nest
void greenToBoard(int row,int col,int board[row][col],int i,int j, int green[i][j]){
		board[7][0]=green[0][0];
		board[7][1]=green[0][1];
		board[8][0]=green[1][0];
		board[8][1]=green[1][1];
}
// update blues nest
void blueToBoard(int row,int col,int board[row][col],int i,int j, int blue[i][j]){
		board[7][7]=blue[0][0];
		board[7][8]=blue[0][1];
		board[8][7]=blue[1][0];
		board[8][8]=blue[1][1];
}




int main(){	

	srand(GetTickCount()); // for rand function
	
	// controller of finishing
	int yellowfinish[4]={0};
	int redfinish[4]={0};
	int greenfinish[4]={0};
	int bluefinish[4]={0};
	
	
//	int playToFirstCell;
	int numberOfPlayers;  // player number
	int diceValue;
	int i,j;
	int temp;
//	int min;
	int choice;
//	int whichPiece;
	int wrongOperation = 1;
	int diceValues[2][4] = {1,2,3,4,0,0,0,0};  // kullanici numarasi ve baslama icin atilan zar degerleri 
	int board[9][9]={0};	//all board cells
	board[2][0]=-1;board[2][1]=-1;board[2][2]=-1;board[1][2]=-1;board[0][2]=-1;board[2][6]=-1;board[2][7]=-1;board[2][8]=-1;
	board[0][6]=-1;board[1][6]=-1;board[6][0]=-1;board[6][1]=-1;board[6][2]=-1;board[7][2]=-1;board[8][2]=-1;board[6][6]=-1;
	board[6][7]=-1;board[6][8]=-1;board[7][6]=-1;board[8][6]=-1;board[4][4]=-1;board[4][1]=-1;board[4][2]=-1;board[4][3]=-1;
	board[1][4]=-1;board[2][4]=-1;board[3][4]=-1;board[4][5]=-1;board[4][6]=-1;board[4][7]=-1;board[7][4]=-1;board[6][4]=-1;
	board[5][4]=-1;
	
	
	int rota[32]={0};
	int choosePiece;
	
	int isAnyWinner = 0; //if it is 1 game will be over
	
	int isAlive[4]={4,4,4,4};   // number of players in nest
	
	// rota
	
	
	
	update(9,9, board,32,rota);

	
	int yellow[2][2] = {11,12,13,14}; // nest matrix
	int red[2][2] = {21,22,23,24};
	int blue[2][2] = {31,32,33,34};
	int green[2][2] = {41,42,43,44};
	
	
	int yellowStart[4]={0};          // starting point of each pieces
	int redStart[4]={8,8,8,8};
	int greenStart[4]={24,24,24,24};
	int blueStart[4]={16,16,16,16};
	
	// tüm piyonlar final destinationa geldiginde 4 olacak
	int yellowFinished[4]={0};    
	int redFinished[4]={0};
	int greenFinished[4]={0};
	int blueFinished[4]={0};
	
	int inBoard[4]={0};          // still playing on the map
	int isFinished[4]={0};		// number of finished pieces
	

	
	
	// Number of players control(2-4)
	while(wrongOperation!=0){
			printf("Number of players: ");
			scanf("%d",&numberOfPlayers);
			if(!(numberOfPlayers>=2 && numberOfPlayers<=4)){
				printf("number of players must be between 2 and 4\n");
				wrongOperation=1;
			}
			else
				wrongOperation=0;			
	}
	printf("\n");
//	printf("%d\n",numberOfPlayers);
	
	
	// Colors of players
	if(numberOfPlayers==4){
		printf("Player1 : Yellow\nPlayer2 : Red\nPlayer3 : Green\nPlayer4 : Blue\n");
		yellowToBoard(9,9,board,2,2,yellow);
		redToBoard(9,9,board,2,2,red);
		greenToBoard(9,9,board,2,2,green);
		blueToBoard(9,9,board,2,2,blue);	
	}
		
	else if(numberOfPlayers==3){
		printf("Player1 : Yellow\nPlayer2 : Red\nPlayer3 : Green\n");
		
		yellowToBoard(9,9,board,2,2,yellow);
		redToBoard(9,9,board,2,2,red);
		greenToBoard(9,9,board,2,2,green);
	}
		
	else{
		printf("Player1 : Yellow\nPlayer2 : Red\n");
		
		yellowToBoard(9,9,board,2,2,yellow);
		redToBoard(9,9,board,2,2,red);
	}
		
	
	
	// Decide who to start
	for(i=0;i<numberOfPlayers;i++){
		diceValues[1][i] = rollTheDice();
		printf("%d ",diceValues[1][i]);
	}
	
	for(i=0;i<numberOfPlayers;i++){
		for(j=i+1;j<numberOfPlayers;j++){
			if(diceValues[1][i]>diceValues[1][j]){
				temp = diceValues[1][i];
				diceValues[1][i]=diceValues[1][j];
				diceValues[1][j] = temp;
				temp = diceValues[0][i];
				diceValues[0][i]=diceValues[0][j];
				diceValues[0][j] = temp;
			}
		}
		
	}

	// turn to play
	for(i=numberOfPlayers-1;i>=0;i--){
		printf("\n%d.player  %d value",diceValues[0][i],diceValues[1][i]);
	}
	printf("\nWARNING: If you make an illegal move, you will lose your right");
	
	int sixController;	// is the dice value 6

	displayBoard(9,9,board);
	// store the copy value of numberOfPlayers that will be decreased
	int numberOfPlayersCopy = numberOfPlayers;
	
	
	
	while(isAnyWinner==0){
		int currentPlayer=diceValues[0][numberOfPlayers-1];
		
		if(currentPlayer==1){
			printf("\nYellows turn\n",currentPlayer);
		}
		else if(currentPlayer==2){
			printf("\nReds turn\n",currentPlayer);
		}
		else if(currentPlayer==3){
			printf("\nGreens turn\n",currentPlayer);
		}
		else if(currentPlayer==4){
			printf("\nBlues turn\n",currentPlayer);
		}
		
		
		
		printf("Press 1 to dice: \nPress 2 to pass: \nPress 3 to show the number of pieces in the board: \nPress 4 to show the number of pieces that have completed the game: \n");
		printf("Answer: ");
		
		scanf("%d",&choice);
		if(choice==2){
			printf("You lost your right.\nPlease wait this round.\n");
		}
		if(choice==3){
			printf("Number of pieces in the game: %d\n",inBoard[currentPlayer-1]);
		}
		if(choice==4){
			printf("Number of pieces that have completed the game: %d\n",isFinished[currentPlayer-1]);
		}
		if(choice==1){
		
			int temp = rollTheDice();
			printf("dice value: %d\n",temp);
			sixController=1;
			if(temp==6){
				sixController=1;
				// zar 6 ve oyunda piyon yoksa 
				if( inBoard[currentPlayer-1]==0){
					printf("press 1 for a new piece: ");
					scanf("%d",&choice);
				}
				else{
					if(isAlive[currentPlayer-1]==0){
						printf("press 2 to move a piece: ");
						scanf("%d",&choice);
					}
					else{
						// zar 6, oyunda piyon varsa 
						printf("press 1 for a new piece\npress 2 to move a piece: ");
						scanf("%d",&choice);
					}
					
					
				}
//				//	invalid move
//				if(choice!=1 && choice!=2){
//					printf("You lost your right\n");
//					six
//				}	
				
				if(currentPlayer==1 && choice==1){
					// if player has a piece in the beginning cell and try to move a new piece it is forbidden
						if(rota[0]/10==1){
							printf("There is a piece already in the first cell\n");
							choice=2;
						}
						//	other players pieces should return to its nest.
						else if(rota[0]/10!=1 && rota[0]!=0){
							choice=1;
							//sarý oyuna girerken kýrmýzýyý yerse
							if(rota[0]/10==2){
								if(rota[0]==21)
									red[0][0]=21;
								else if(rota[0]==22)
									red[0][1]=22;
								else if(rota[0]==23)
									red[1][0]=23;
								else if(rota[0]==23)
									red[1][1]=23;
								printf("%d returning to nest\n",rota[0]);
								inBoard[1]--;	
								isAlive[1]++;
								redStart[rota[0]-21]=8;
								redToBoard(9,9,board,2,2,red);
							}
							//sarý oyuna girerken yeþili yerse
							else if(rota[0]/10==4){
								if(rota[0]==41)
									green[0][0]=41;
								else if(rota[0]==42)
									green[0][1]=42;
								else if(rota[0]==43)
									green[1][0]=43;
								else if(rota[0]==44)
									green[1][1]=44;
								printf("%d returning to nest\n",rota[0]);
								inBoard[2]--;	
								isAlive[2]++;
								greenStart[rota[0]-41]=24;
								greenToBoard(9,9,board,2,2,green);
								
							}
							//sarý oyuna girerken maviyi yerse
							else if(rota[0]/10==3){
								if(rota[0]==31)
									blue[0][0]=31;
								else if(rota[0]==32)
									blue[0][1]=32;
								else if(rota[0]==33)
									blue[1][0]=33;
								else if(rota[0]==34)
									blue[1][1]=34;
								printf("%d returning to nest\n",rota[0]);
								inBoard[3]--;	
								isAlive[3]++;
								blueStart[rota[0]-31]=16;
								blueToBoard(9,9,board,2,2,blue);
							}
							
						}
				}
				if(currentPlayer==2 && choice==1){
						if(rota[8]/10==2){
							printf("There is a piece already in the first cell\n");
							choice=2;
						}
				
				else if(rota[8]/10!=2 && rota[8]!=0){
							choice=1;
							//kýrmýzý oyuna girerken sarýyý yerse
							if(rota[8]/10==1){
								if(rota[8]==11)
									yellow[0][0]=11;
								else if(rota[8]==12)
									yellow[0][1]=12;
								else if(rota[8]==13)
									yellow[1][0]=13;
								else if(rota[8]==14)
									yellow[1][1]=14;
								printf("%d returning to nest\n",rota[8]);
								inBoard[0]--;	
								isAlive[0]++;
								yellowStart[rota[8]-11]=0;
								yellowToBoard(9,9,board,2,2,yellow);
								
							}
							//kýrmýzý oyuna girerken yeþili yerse
							else if(rota[8]/10==4){
								if(rota[8]==41)
									green[0][0]=41;
								else if(rota[8]==42)
									green[0][1]=42;
								else if(rota[8]==43)
									green[1][0]=43;
								else if(rota[8]==44)
									green[1][1]=44;
								printf("%d returning to nest\n",rota[8]);
								inBoard[2]--;	
								isAlive[2]++;
								greenStart[rota[0]-41]=24;
								greenToBoard(9,9,board,2,2,	green);
							}
							//kýrmýzý oyuna girerken maviyi yerse
							else if(rota[8]/10==3){
								if(rota[8]==31)
									blue[0][0]=31;
								else if(rota[8]==32)
									blue[0][1]=32;
								else if(rota[8]==33)
									blue[1][0]=33;
								else if(rota[8]==34)
									blue[1][1]=34;
								printf("%d returning to nest\n",rota[8]);
								inBoard[3]--;	
								isAlive[3]++;
								blueStart[rota[24]-31]=16;
								blueToBoard(9,9,board,2,2,blue);
							}
							
							
							}
						}
				if(currentPlayer==4 && choice==1){
						if(rota[16]/10==3){
							printf("There is a piece already in the first cell\n");
							choice=2;
						}
				else if(rota[16]/10!=3 && rota[16]!=0){
					
				
				if(rota[16]/10==1){
						if(rota[16]==11)
							yellow[0][0]=11;
						else if(rota[16]==12)
							yellow[0][1]=12;
						else if(rota[16]==13)
							yellow[1][0]=13;
						else if(rota[16]==14)
							yellow[1][1]=14;
						printf("%d returning to nest\n",rota[16]);
						inBoard[0]--;	
						isAlive[0]++;
						yellowStart[rota[0]-11]=0;
						yellowToBoard(9,9,board,2,2,yellow);
						
					}
				else if(rota[16]/10==2){
						if(rota[16]==21)
							red[0][0]=21;
						else if(rota[16]==22)
							red[0][1]=22;
						else if(rota[16]==23)
							red[1][0]=23;
						else if(rota[16]==23)
							red[1][1]=23;
						printf("%d returning to nest\n",rota[16]);
						inBoard[1]--;	
						isAlive[1]++;
						redStart[rota[16]-21]=8;
						redToBoard(9,9,board,2,2,red);
					}
				else if(rota[16]/10==4){
					if(rota[16]==41)
						green[0][0]=41;
					else if(rota[16]==42)
						green[0][1]=42;
					else if(rota[16]==43)
						green[1][0]=43;
					else if(rota[16]==44)
						green[1][1]=44;
					printf("%d returning to nest\n",rota[16]);
					inBoard[2]--;	
					isAlive[2]++;
					greenStart[rota[16]-41]=24;
					greenToBoard(9,9,board,2,2,green);
					
					}
				}
			}
				
				
				
				if(currentPlayer==3 && choice==1){
						if(rota[24]/10==4){
							printf("There is a piece already in the first cell\n");
							choice=2;
						}
						else if(rota[24]/10!=4 && rota[24]!=0){
							if(rota[24]/10==1){
								if(rota[24]==11)
									yellow[0][0]=11;
								else if(rota[24]==12)
									yellow[0][1]=12;
								else if(rota[24]==13)
									yellow[1][0]=13;
								else if(rota[24]==14)
									yellow[1][1]=14;
								printf("%d returning to nest\n",rota[24]);
								inBoard[0]--;	
								isAlive[0]++;
								yellowStart[rota[24]-11]=0;
								yellowToBoard(9,9,board,2,2,yellow);
								
								}
							else if(rota[24]/10==2){
								if(rota[24]==21)
									red[0][0]=21;
								else if(rota[24]==22)
									red[0][1]=22;
								else if(rota[24]==23)
									red[1][0]=23;
								else if(rota[24]==23)
									red[1][1]=23;
								printf("%d returning to nest\n",rota[24]);
								inBoard[1]--;	
								isAlive[1]++;
								redStart[rota[24]-21]=8;
								redToBoard(9,9,board,2,2,red);
								}
							else if(rota[24]/10==3){
								if(rota[24]==31)
									blue[0][0]=31;
								else if(rota[24]==32)
									blue[0][1]=32;
								else if(rota[24]==33)
									blue[1][0]=33;
								else if(rota[24]==34)
									blue[1][1]=34;
							printf("%d returning to nest\n",rota[24]);
							inBoard[3]--;	
								isAlive[3]++;
								blueStart[rota[24]-31]=16;
								blueToBoard(9,9,board,2,2,blue);
								}
							}
						}
				if(choice==1){
					
					// yellow arrayinin ilk elemaný diyelim
					
					// which piece should play to map
					if(currentPlayer==1){
						if(yellow[0][0]!=0){
							printf("%d entered the game\n",yellow[0][0]);
							rota[0]=yellow[0][0];
							yellow[0][0]=0;
						}
						else if(yellow[0][1]!=0){
							printf("%d entered the game\n",yellow[0][1]);
							rota[0]=yellow[0][1];
							yellow[0][1]=0;
						}
						else if(yellow[1][0]!=0){
							printf("%d entered the game\n",yellow[1][0]);
							rota[0]=yellow[1][0];
							yellow[1][0]=0;
						}
						else if(yellow[1][1]!=0){
							printf("%d entered the game\n",yellow[1][1]);
							rota[0]=yellow[1][1];
							yellow[1][1]=0;
						}
						else{
							printf("All pieces have been played");
						}
					}
					else if(currentPlayer==2){
						if(red[0][0]!=0){
							printf("%d entered the game\n",red[0][0]);
							rota[8]=red[0][0];
							red[0][0]=0;
						}
						else if(red[0][1]!=0){
							printf("%d entered the game\n",red[0][1]);
							rota[8]=red[0][1];
							red[0][1]=0;
						}
						else if(red[1][0]!=0){
							printf("%d entered the game\n",red[1][0]);
							rota[8]=red[1][0];
							red[1][0]=0;
						}
						else if(red[1][1]!=0){
							printf("%d entered the game\n",red[1][1]);
							rota[8]=red[1][1];
							red[1][1]=0;
						}
						else{
							printf("All pieces have been played");
						}
					}
					else if(currentPlayer==3){
						if(green[0][0]!=0){
							printf("%d entered the game\n",green[0][0]);
							rota[24]=green[0][0];
							green[0][0]=0;
						}
						else if(green[0][1]!=0){
							printf("%d entered the game\n",green[0][1]);
							rota[24]=green[0][1];
							green[0][1]=0;
						}
						else if(green[1][0]!=0){
							printf("%d entered the game\n",green[1][0]);
							rota[24]=green[1][0];
							green[1][0]=0;
						}
						else if(green[1][1]!=0){
							printf("%d entered the game\n",green[1][1]);
							rota[24]=green[1][1];
							green[1][1]=0;
						}
						else{
							printf("All pieces have been played");
						}
					}
					else if(currentPlayer==4){
						if(blue[0][0]!=0){
							printf("%d entered the game\n",blue[0][0]);
							rota[16]=blue[0][0];
							blue[0][0]=0;
						}
						else if(blue[0][1]!=0){
							printf("%d entered the game\n",blue[0][1]);
							rota[16]=blue[0][1];
							blue[0][1]=0;
						}
						else if(blue[1][0]!=0){
							printf("%d entered the game\n",blue[1][0]);
							rota[16]=blue[1][0];
							blue[1][0]=0;
						}
						else if(blue[1][1]!=0){
							printf("%d entered the game\n",blue[1][1]);
							rota[16]=blue[1][1];
							blue[1][1]=0;
						}
						else{
							printf("All pieces have been played");
						}
						
					}
					
					inBoard[currentPlayer-1]++;	
					isAlive[currentPlayer-1]--;
					
					// Update players nest
					if(numberOfPlayersCopy==2){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
					}
					if(numberOfPlayersCopy==3){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
						greenToBoard(9,9,board,2,2,green);
					}
					else if(numberOfPlayersCopy==4){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
						greenToBoard(9,9,board,2,2,green);
						blueToBoard(9,9,board,2,2,blue);
					}
					
					// Update board
					update(9,9, board,32,rota);
					sixController=0;
					
				}
				
				// dice = 6 but you want to move your piece that is alive
				else if(choice==2){
					sixController=1; // dice = 6 ?
					
				}
//				sixController=0;
			}
			// dice= 6 but you want to move your piece that is alive OR dice != 6
			 if(sixController==1){
				
				// movement
				if(inBoard[currentPlayer-1]>0 ){
					printf("which piece should movee: ");
					scanf("%d",&choosePiece);
					
					//yellow
					for(i=11;i<15;i++){
						if(i==choosePiece && currentPlayer==1 ){
								// yellow reach the final cell
								if(yellowStart[choosePiece-11]+temp>31  ){
									
									printf("%d completed the tour successfully.",choosePiece);
									inBoard[currentPlayer-1]--;
									isFinished[currentPlayer-1]++;
									//4 pieces have reached the final destination
									if(isFinished[currentPlayer-1]==4){
										isAnyWinner=1;
										printf("\n\nYELLOW IS THE CHAMPION\n\n");
									}
									//	
									rota[yellowStart[choosePiece-11]]=0;
									
									//fill the blanks with finishing pieces
									if(board[4][1]/10!=1)
										board[4][1]=choosePiece;
									else if(board[4][2]/10!=1)
										board[4][2]=choosePiece;
									else if(board[4][3]/10!=1)
										board[4][3]=choosePiece;
									else if(board[4][4]/10!=1)
										board[4][4]=choosePiece;
								}
							// eger hücredeki piyon sarýysa gideme farklý renkse ye ve onu eve gönder
							else if(rota[(yellowStart[choosePiece-11]+temp)%32]/10==1){
								printf("you have your own piece in the cell you want to go\nPlease, wait this round. ");
							}
							//
							else{
								
								if((rota[(yellowStart[choosePiece-11]+temp)%32])/10==2){
								
								//sarý kýrmýzýyý yerse
								if(rota[yellowStart[choosePiece-11]+temp]==21){
									red[0][0]=21;
									redStart[0]=8;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==22){
									red[0][1]=22;
									redStart[1]=8;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==23){
									red[1][0]=23;
									redStart[2]=8;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==24){
									red[1][1]=24;
									redStart[3]=8;								
								}
								
								inBoard[1]--;
								isAlive[1]++;
								}
								if((rota[(yellowStart[choosePiece-11]+temp)%32])/10==4){
								
								// sarý yeþili yerse
								if(rota[yellowStart[choosePiece-11]+temp]==41){
									green[0][0]=41;
									greenStart[0]=24;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==42){
									green[0][1]=42;
									greenStart[1]=24;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==43){
									green[1][0]=43;
									greenStart[2]=24;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==44){
									green[1][1]=44;
									greenStart[3]=24;								
								}
								inBoard[2]--;
								isAlive[2]++;
								}
								if((rota[(yellowStart[choosePiece-11]+temp)%32])/10==3){
									
								
								// sarý maviyi yerse
								if(rota[yellowStart[choosePiece-11]+temp]==31){
									blue[0][0]=31;
									blueStart[0]=16;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==32){
									blue[0][1]=32;
									blueStart[1]=16;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==33){
									blue[1][0]=33;
									blueStart[2]=16;								
								}
								else if(rota[yellowStart[choosePiece-11]+temp]==34){
									blue[1][1]=34;
									blueStart[3]=16;								
								}
								inBoard[3]--;
								isAlive[3]++;
								}
								//movement of yellow
								rota[yellowStart[choosePiece-11]+temp]=rota[yellowStart[choosePiece-11]];
								rota[yellowStart[choosePiece-11]]=0;
								yellowStart[choosePiece-11]+=temp;
								
							
							}
							
						}
					}
					//	if player try to move someone else's piece
					if(choosePiece<15 && choosePiece>=11 && currentPlayer!=1)
						printf("you can only play your own pawns");
					
					//red
					for(i=21;i<25;i++){
						if(i==choosePiece && currentPlayer==2){
							if(redStart[choosePiece-21]+temp>7 && redfinish[choosePiece-21]==1){
									printf("%d completed the tour successfully.",choosePiece);
									isFinished[currentPlayer-1]++;
									
									if(isFinished[currentPlayer-1]==4){
										isAnyWinner=1;
										printf("\n\nRED IS THE CHAMPION\n\n");
									}
									inBoard[currentPlayer-1]--;
									rota[redStart[choosePiece-21]]=0;
									
									if(board[1][4]/10!=2)
										board[1][4]=choosePiece;
									else if(board[2][4]/10!=2)
										board[2][4]=choosePiece;
									else if(board[3][4]/10!=2)
										board[3][4]=choosePiece;
									else if(board[4][4]/10!=2)
										board[4][4]=choosePiece;
									
								}
							else if(rota[(redStart[choosePiece-21]+temp)%32]/10==2){
								printf("you have your own piece in the cell you want to go\nPlease, wait this round. ");
							}
							else{
								
								if((rota[(redStart[choosePiece-21]+temp)%32])/10==1){
									
								//	kirmizi sariyi yerse
								if(rota[(redStart[choosePiece-21]+temp)%32]==11){
									yellow[0][0]=11;
									yellowStart[0]=0;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==12){
									yellow[0][1]=12;
									yellowStart[1]=0;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==13){
									yellow[1][0]=13;
									yellowStart[2]=0;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==14){
									yellow[1][1]=14;
									yellowStart[3]=0;								
								}
								inBoard[0]--;
								isAlive[0]++;
								}
								
								// kirmizi yeþili yerse
								if((rota[(redStart[choosePiece-21]+temp)%32])/10==4){
									
								
								if(rota[(redStart[choosePiece-21]+temp)%32]==41){
									green[0][0]=41;
									greenStart[0]=24;
																	
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==42){
									green[0][1]=42;
									greenStart[1]=24;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==43){
									green[1][0]=43;
									greenStart[2]=24;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==44){
									green[1][1]=44;
									greenStart[3]=24;								
								}
								inBoard[2]--;
								isAlive[2]++;
								}
								// kirmizi maviyi yerse
								if((rota[(redStart[choosePiece-21]+temp)%32])/10==3){
									
								if(rota[(redStart[choosePiece-21]+temp)%32]==31){
									blue[0][0]=31;
									blueStart[0]=16;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==32){
									blue[0][1]=32;
									blueStart[1]=16;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==33){
									blue[1][0]=33;
									blueStart[2]=16;								
								}
								else if(rota[(redStart[choosePiece-21]+temp)%32]==34){
									blue[1][1]=34;
									blueStart[3]=16;								
								}
								inBoard[3]--;
								isAlive[3]++;
								}
								
								
								rota[(redStart[choosePiece-21]+temp)%32]=rota[redStart[choosePiece-21]];
								rota[redStart[choosePiece-21]]=0;
								redStart[choosePiece-21]+=temp;
								if(redStart[choosePiece-21]>31){
									redfinish[choosePiece-21]=1;
								}
								redStart[choosePiece-21]=redStart[choosePiece-21]%32;
							}
							  
						}
					}
					if(choosePiece<25 && choosePiece>=21 && currentPlayer!=2)
						printf("you can only play your own pawns");
					//green
					for(i=41;i<45;i++){
						if(i==choosePiece && currentPlayer==3){
							if(greenStart[choosePiece-41]+temp>23 && greenfinish[choosePiece-41]==1){
									printf("%d completed the tour successfully.",choosePiece);
									isFinished[currentPlayer-1]+=1;
									if(isFinished[currentPlayer-1]==4){
										isAnyWinner=1;
										printf("\n\nGREEN IS THE CHAMPION\n\n");
									}
										
									inBoard[currentPlayer-1]--;
									rota[greenStart[choosePiece-41]]=0;
									if(board[7][4]/10!=4)
										board[7][4]=choosePiece;
									else if(board[6][4]/10!=4)
										board[6][4]=choosePiece;
									else if(board[5][4]/10!=4)
										board[5][4]=choosePiece;
									else if(board[4][4]/10!=4)
										board[4][4]=choosePiece;
								}
							else if(rota[(greenStart[choosePiece-41]+temp)%32]/10==4 ){
								printf("you have your own piece in the cell you want to go\nPlease, wait this round. ");
							}
							else{
								if((rota[(greenStart[choosePiece-41]+temp)%32])/10==1){
									
								// yesil sariyi yerse
								if(rota[(greenStart[choosePiece-41]+temp)%32]==11){
									yellow[0][0]=11;
									yellowStart[0]=0;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==12){
									yellow[0][1]=12;
									yellowStart[1]=0;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==13){
									yellow[1][0]=13;
									yellowStart[2]=0;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==14){
									yellow[1][1]=14;
									yellowStart[3]=0;								
								}
								inBoard[0]--;
								isAlive[0]++;
								}
								
								// yesil kirmiziyi yerse
								if((rota[(greenStart[choosePiece-41]+temp)%32])/10==2){
								
								if(rota[greenStart[choosePiece-41]+temp]==21){
									red[0][0]=21;
									redStart[0]=8;								
								}
								else if(rota[greenStart[choosePiece-41]+temp]==22){
									red[0][1]=22;
									redStart[1]=8;								
								}
								else if(rota[greenStart[choosePiece-41]+temp]==23){
									red[1][0]=23;
									redStart[2]=8;								
								}
								else if(rota[greenStart[choosePiece-41]+temp]==24){
									red[1][1]=24;
									redStart[3]=8;								
								}
								inBoard[1]--;
								isAlive[1]++;
								}
								
								// yesil maviyi yerse
								if((rota[(greenStart[choosePiece-41]+temp)%32])/10==3){
								
								if(rota[(greenStart[choosePiece-41]+temp)%32]==31){
									blue[0][0]=31;
									blueStart[0]=16;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==32){
									blue[0][1]=32;
									blueStart[1]=16;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==33){
									blue[1][0]=33;
									blueStart[2]=16;								
								}
								else if(rota[(greenStart[choosePiece-41]+temp)%32]==34){
									blue[1][1]=34;
									blueStart[3]=16;								
								}
								inBoard[3]--;
								isAlive[3]++;
								}
								
								rota[(greenStart[choosePiece-41]+temp)%32]=rota[greenStart[choosePiece-41]];
								rota[greenStart[choosePiece-41]]=0;
								greenStart[choosePiece-41]+=temp;
								if(greenStart[choosePiece-41]>31){
									greenfinish[choosePiece-41]=1;
								}
								greenStart[choosePiece-41]=greenStart[choosePiece-41]%32;
							}
							
						}
						
					}
					if(choosePiece<45 && choosePiece>=41 && currentPlayer!=3)
						printf("you can only play your own pawns");
					
					//blue
					for(i=31;i<35;i++){
						if(i==choosePiece && currentPlayer==4){
							if(blueStart[choosePiece-31]+temp>15 && bluefinish[choosePiece-31]==1){
									printf("%d completed the tour successfully.",choosePiece);
									isFinished[currentPlayer-1]+=1;
									if(isFinished[currentPlayer-1]==4){
										isAnyWinner=1;
										printf("\n\nBLUE IS THE CHAMPION\n\n");
									}
										
									inBoard[currentPlayer-1]--;
									rota[blueStart[choosePiece-31]]=0;
									
									if(board[4][7]/10!=3)
										board[4][7]=choosePiece;
									else if(board[4][6]/10!=3)
										board[4][6]=choosePiece;
									else if(board[4][5]/10!=3)
										board[4][5]=choosePiece;
									else if(board[4][4]/10!=3)
										board[4][4]=choosePiece;
								}
							else if(rota[(blueStart[choosePiece-31]+temp)%32]/10==3){
								printf("you have your own piece in the cell you want to go\nPlease, wait this round. ");
							}
							else{
								if((rota[(blueStart[choosePiece-31]+temp)%32])/10==1){
								//	mavi sariyi yerse	
								if(rota[(blueStart[choosePiece-31]+temp)%32]==11){
									yellow[0][0]=11;
									yellowStart[0]=0;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==12){
									yellow[0][1]=12;
									yellowStart[1]=0;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==13){
									yellow[1][0]=13;
									yellowStart[2]=0;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==14){
									yellow[1][1]=14;
									yellowStart[3]=0;								
								}
								inBoard[0]--;
								isAlive[0]++;
								}
								
								// mavi kirmiziyi yerse
								if((rota[(blueStart[choosePiece-31]+temp)%32])/10==2){
									
								if(rota[blueStart[choosePiece-31]+temp]==21){
									red[0][0]=21;
									redStart[0]=8;								
								}
								else if(rota[blueStart[choosePiece-31]+temp]==22){
									red[0][1]=22;
									redStart[1]=8;								
								}
								else if(rota[blueStart[choosePiece-31]+temp]==23){
									red[1][0]=23;
									redStart[2]=8;								
								}
								else if(rota[blueStart[choosePiece-31]+temp]==24){
									red[1][1]=24;
									redStart[3]=8;								
								}
								inBoard[1]--;
								isAlive[1]++;
								}
								
								// mavi yesili yerse
								if((rota[(blueStart[choosePiece-31]+temp)%32])/10==4){
								
								if(rota[(blueStart[choosePiece-31]+temp)%32]==41){
									green[0][0]=41;
									greenStart[0]=24;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==42){
									green[0][1]=42;
									greenStart[1]=24;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==43){
									green[1][0]=43;
									greenStart[2]=24;								
								}
								else if(rota[(blueStart[choosePiece-31]+temp)%32]==44){
									green[1][1]=44;
									greenStart[3]=24;								
								}
								inBoard[2]--;
								isAlive[2]++;
								}
								
								
								
								rota[(blueStart[choosePiece-31]+temp)%32]=rota[blueStart[choosePiece-31]];
								rota[blueStart[choosePiece-31]]=0;
								blueStart[choosePiece-31]+=temp;
								if(blueStart[choosePiece-31]>31){
									bluefinish[choosePiece-31]=1;
								}
								
								blueStart[choosePiece-31]=blueStart[choosePiece-31]%32;
							}
							
						}
					}
					if(choosePiece<35 && choosePiece>=31 && currentPlayer!=4)
						printf("you can only play your own pawns");
				}
			
	
				else{
					printf("Please, wait this round. \n");
					
				}
				
				//UPDATE
					if(numberOfPlayersCopy==2){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
					}
					if(numberOfPlayersCopy==3){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
						greenToBoard(9,9,board,2,2,green);
					}
					else if(numberOfPlayersCopy==4){
						yellowToBoard(9,9,board,2,2,yellow);
						redToBoard(9,9,board,2,2,red);
						greenToBoard(9,9,board,2,2,green);
						blueToBoard(9,9,board,2,2,blue);
					}
					
					update(9,9,board,32,rota);
			
			}
	
		}
		else if(choice!=1 && choice!=2 && choice!=3 && choice!=4){
			printf("Invalid Operation\n");
		}
		
//		printf("current player: %d",currentPlayer);
		displayBoard(9,9,board);
		
		//	change player
		numberOfPlayers--;
		
		if(numberOfPlayers==0)
			numberOfPlayers=numberOfPlayersCopy;
	}
	getch();
	return 0;
	
}



