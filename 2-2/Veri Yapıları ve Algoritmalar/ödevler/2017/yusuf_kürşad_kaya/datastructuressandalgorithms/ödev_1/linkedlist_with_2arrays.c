#include <stdio.h>

#define MAX_ARRAYSIZE 100

void insert(int, int[], int[]);
int search(int, int[], int[]);
void delete(int, int[], int[]);
void printList(int[], int[]);


int main(int argc, char const *argv[])
{
	int values[MAX_ARRAYSIZE], pointers[MAX_ARRAYSIZE];
	int i, selection;

	for (i = 0; i < MAX_ARRAYSIZE; i++)
	{
		values[i] = 0;
		pointers[i] = -1;
	}

	do
	{
		printf("1) Add an element to the linked list.\n");
		printf("2) Search an element in the linked list.\n");
		printf("3) Delete an element in the linked list.\n");
		printf("4) Print the linked list.\n");
		printf("0) Exit\n\n");
		printf("Make selection: ");
		scanf("%d", &selection);

		switch (selection)
		{
			int element;
			case 1:
				printf("Element to add:");
				scanf("%d", &element);
				insert(element, values, pointers);
				break;

			case 2:
				printf("Element to search: ");
				scanf("%d", &element);
				search(element, values, pointers);
				break;

			case 3:
				printf("Element to delete: ");
				scanf("%d", &element);
				delete(element, values, pointers);
				break;

			case 4:
				printf("\n");
				printList(values, pointers);
				break;
		}

	} while (selection);

	return 0;
}

void insert(int element, int valuesArray[], int pointersArray[])
{
	int i = 0;
	static int lastIndex = 1;

	valuesArray[lastIndex] = element;

	while(pointersArray[i] != -1)
	{
		i = pointersArray[i];
	}

	pointersArray[i] = lastIndex;
	lastIndex++;
}

int search(int element, int valuesArray[], int pointersArray[])
{
	int i = 0;

	while ((valuesArray[pointersArray[i]] != element) && (pointersArray[i] != -1))
	{
		i = pointersArray[i];
	}

	if (pointersArray[i] == -1)
	{
		printf("Element (%d) could not found in linked list!\n", element);
	}

	return i;
}

void delete(int element, int valuesArray[], int pointersArray[])
{
	int index;

	if ((index = search(element, valuesArray, pointersArray)) == -1)
	{
		return;
	}
	else
	{
		pointersArray[index] = pointersArray[pointersArray[index]];

		printf("Element (%d) successfully deleted!\n", element);
	}
}

void printList(int valuesArray[], int pointersArray[])
{
	int i = 0;

	while (pointersArray[i] != -1)
	{
		printf("%d ", valuesArray[pointersArray[i]]);

		i = pointersArray[i];
	}

	printf("\n");
}