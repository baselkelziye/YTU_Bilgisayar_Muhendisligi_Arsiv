#include <iostream>
#include <conio.h>


int main() {
	int X, Y;printf("Lutfen iki sayi giriniz : ");scanf("%d",&X);scanf("%d",&Y);
	
	//*****************************************************ALGORÝTMA********************************************************
	while(X != Y){
		if(X > Y)
			X = X - Y;
		else
			Y = Y - X;
	}
	
	printf("EBOB = %d", X);
	
	//******************************************************ÖKLÝD***********************************************************
	/*
	while(X != 0 && Y != 0){
		if(X > Y)
			X = X % Y; 
		else
			Y = Y % X;
	}
	if(X == 0)
		printf("EBOB = %d", Y);
	else
		printf("EBOB = %d", X);
	*/
	
	getch();
	return 0;
}
