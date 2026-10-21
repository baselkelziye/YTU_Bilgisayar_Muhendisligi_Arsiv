#include <stdio.h>
#include <stdlib.h>
#include "lab1Header.h"

int buyukMu(int a,int b){
	if(a>b){
		return 1;
	}else if(a<b){
		return -1;
	}else{
		return 0;
	}
}
