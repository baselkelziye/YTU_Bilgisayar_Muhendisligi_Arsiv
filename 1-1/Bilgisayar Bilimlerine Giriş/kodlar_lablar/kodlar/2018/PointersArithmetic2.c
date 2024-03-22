// usage of pointers
#include <stdio.h>
int main()
{
	int a[5]={1,2,3,4,5};
	int *p1, *p2;
 	int j; 
	char *p3;
	printf("fark:%d\n",&a[3]-&a[0]);
 	p1=a;
	p2 = p1 + 4; 	/* legal */
	j = p2 - p1; 	/* legal j is assigned 4 */
	printf("j:%d\n",j);
	j = p1 - p2; 	/* legal j is assigned -4 */
	printf("j:%d\n",j);
	p1 = p2 - 2; 	/* legal compatible pointer types */
	printf("*p1:%d\n",*p1);

	//p3 = p1 - 1; 	/* ILLEGAL different pointer types*/
	//j = p1 - p3;	 /* ILLEGAL -- different pointer types*/

	return 0;
}

