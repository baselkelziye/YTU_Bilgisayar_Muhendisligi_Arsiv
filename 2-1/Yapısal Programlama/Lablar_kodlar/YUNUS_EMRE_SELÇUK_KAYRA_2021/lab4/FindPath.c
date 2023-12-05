#include <stdlib.h>
#include <stdio.h>

int isReachable(int Ax, int Ay, int Bx, int By){
	// base case
	if(Ax > Bx || Ay > By)
		return 0;
	
	// Ax = Bx, Ay = By;
	if(Ax == Bx && Ay == By)
		return 1;
		
	// continue to check
	return (isReachable(Ax + 1, Ay, Bx, By)|| isReachable(Ax, Ay + 1, Bx, By));
}
int main()
{
    int source_Ax = 12, source_Ay = 12;
    int dest_Bx = 5, dest_By = 7;
    int dest_Cx = -2, dest_Cy = 7;
    int dest_Dx = 7, dest_Dy = 9;
    if(isReachable(dest_Dx, dest_Dy, source_Ax, source_Ay))
    	printf("kaynaktan hedefe yol VAR!");
    else
    	printf("kaynaktan hedefe yol YOK!");    
    return 0;
}


