//LAB 4 İÇİN

#include <stdio.h>
#include <stdlib.h>

static int counter = 0;

typedef struct fly
{
	int id;
	char road[20];
	int hour;
	int minute;
	struct fly *nextptr;
} FLY;

static FLY *head;

FLY *create()
{
	FLY *p;
	p = (FLY *) malloc(sizeof(FLY));
	if (p == NULL)
	{
		printf("Not enough memory.");
		exit(1);
	}
	else p->nextptr = NULL;
	return p;
}

void add(FLY *e)
{
	FLY *p;

	if(head == NULL)
	{
			head = e;
			printf("Lutfen ucus id girin: ");
			scanf("%d", e->id);
			printf("Lutfen yon (Kuzey, Guney, Dogu ya da Bati seklinde) girin: ");
			scanf("%s", e->road);
			printf("Lutfen saat bilgisi girin: ");
			scanf("%d", e->hour);
			printf("Lutfen dakika bilgisi girin: ");
			scanf("%d", e->minute);
			counter++;
			return;
	}
	
	else for(p=head; p->nextptr != NULL; p = p->nextptr)
	{
			p->nextptr = e;
			printf("Lutfen ucus id girin: ");
			scanf("%d", e->id);
			printf("Lutfen yon (Kuzey, Guney, Dogu ya da Bati seklinde) girin: ");
			scanf("%s", e->road);
			printf("Lutfen saat bilgisi girin: ");
			scanf("%d", e->hour);
			printf("Lutfen dakika bilgisi girin: ");
			scanf("%d", e->minute);
			counter++;
			return;
	}	
}

void display()
{
	FLY *p;
	
	for(p=head; p->nextptr != NULL; p = p->nextptr)
	{
		printf("\n%d        %s        %d:%d", p->id, p->road, p->hour, p->minute);
	}
	
	return;
}

void sort()
{
	FLY *p;
	int i;
	FLY *swap;
	
	for(i=0; i<counter; i++)
	{
		for(p=head; p->nextptr != NULL; p = p->nextptr)
		{
			if(p->road > p->nextptr->road)
			{
				swap = p;
				p = p->nextptr;
				p->nextptr = swap;
			}
		}
		
		for(p=head; p->nextptr != NULL; p = p->nextptr)
		{
			if(p->road == p->nextptr->road)
			{
				if(p->hour > p->nextptr->hour)
				{
					swap = p;
					p = p->nextptr;
					p->nextptr = swap;
				}
			}
		}
		
		for(p=head; p->nextptr != NULL; p = p->nextptr)
		{
			if(p->road == p->nextptr->road && p->hour == p->nextptr->hour)
			{
				if(p->minute > p->nextptr->minute)
				{
					swap = p;
					p = p->nextptr;
					p->nextptr = swap;	
				}
			}
		}
	}
	
	return;
}

void hour_sort()
{
	FLY *p;
	
	for(p=head; p->nextptr != NULL; p = p->nextptr)
	{
		if(p->road == p->nextptr->road && p->hour == p->nextptr->hour && p->minute == p->nextptr->minute)
		{
			if(p->nextptr->minute < 30)
			{
				p->nextptr->minute += 30;
			}
			else 
			{
				p->nextptr->minute += 30;
				p->nextptr->minute -= 60;
				p->nextptr->hour += 1;
			}
		}
	}
	
	sort();
	return;
}

int main() 
{
	FLY *p;
	
	
	label :
		
	printf("Lutfen yapmak istediginiz islemi seciniz: ");
	printf("\n 1. Ucus girme: \n 2. Listeyi goruntuleme: \nCikmak icin 3 giriniz: ");
	int choice;
	
	scanf("\n%d", &choice);
	
	switch(choice)
	{
		case 1: 
			create();
			p = create();
			add(p);
			sort();
			hour_sort();
			goto label;
			break;
		case 2: 
			display();
			goto label;
			break;
		case 3:
			break;
		default:
			printf("Yanlis deger girdiniz! ");
			goto label;
			break;
	}	

	return 0;
}
