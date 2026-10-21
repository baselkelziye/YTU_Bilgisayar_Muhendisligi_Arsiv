#include <stdio.h>

#define MAX_ARRAYSIZE 100

void insertA(int, int[], int[]);
void insertB(int, int[], int[]);
int search(int, int[], int[]);
void delete(int, int[], int[]);
void printList(int[], int[]);
int median(int[], int[]);
void merge(int[], int[], int[], int[], int[], int[]);

int main()
{
	int valuesA[MAX_ARRAYSIZE], pointersA[MAX_ARRAYSIZE], valuesB[MAX_ARRAYSIZE], pointersB[MAX_ARRAYSIZE];
	int mergedList[MAX_ARRAYSIZE * 2], mergedPointers[MAX_ARRAYSIZE * 2];
	int selectionOut, selectionIn, element, i, med;

	for (i = 0; i < MAX_ARRAYSIZE; i++)
	{
		valuesA[i] = 0;
		valuesB[i] = 0;
		pointersA[i] = -1;
		pointersB[i] = -1;
	}

	for (i = 0; i < MAX_ARRAYSIZE * 2; i++)
	{
		mergedList[i] = 0;
		mergedPointers[i] = -1;
	}

	do
	{
		printf("1) Create linked list A\n");
		printf("2) Create linked list B\n");
		printf("3) Merge lists A and B\n");
		printf("4) Print merged lists\n");
		printf("5) Find median of the merged list\n");
		printf("0) Exit\n");
		printf("Make selection: ");
		scanf("%d", &selectionOut);

		switch (selectionOut)
		{
			case 1:
				do
				{
					printf(">>> 1) Add an element to the linked list.\n");
					printf(">>> 2) Search an element in the linked list.\n");
					printf(">>> 3) Delete an element in the linked list.\n");
					printf(">>> 4) Print the linked list.\n");
					printf(">>> 5) Find median of the linked list.\n");
					printf(">>> 0) Exit\n\n");
					printf(">>> Make selection: ");
					scanf("%d", &selectionIn);

					switch (selectionIn)
					{
						case 1:
							printf(">>> Element to add: ");
							scanf("%d", &element);
							insertA(element, valuesA, pointersA);
							break;

						case 2:
							printf(">>> Element to search: ");
							scanf("%d", &element);
							search(element, valuesA, pointersA);
							break;

						case 3:
							printf(">>> Element to delete: ");
							scanf("%d", &element);
							delete(element, valuesA, pointersA);
							break;

						case 4:
							printf("\n");
							printf(">>> ");
							printList(valuesA, pointersA);
							break;

						case 5:
							med = median(valuesA, pointersA);
							printf(">>> Median: %d\n", med);
							break;
					}

				} while (selectionIn);
				break;

			case 2:
				do
				{
					printf(">>> 1) Add an element to the linked list.\n");
					printf(">>> 2) Search an element in the linked list.\n");
					printf(">>> 3) Delete an element in the linked list.\n");
					printf(">>> 4) Print the linked list.\n");
					printf(">>> 5) Find median of the linked list.\n");
					printf(">>> 0) Exit\n\n");
					printf(">>> Make selection: ");
					scanf("%d", &selectionIn);

					switch (selectionIn)
					{
						case 1:
							printf(">>> Element to add: ");
							scanf("%d", &element);
							insertB(element, valuesB, pointersB);
							break;

						case 2:
							printf(">>> Element to search: ");
							scanf("%d", &element);
							search(element, valuesB, pointersB);
							break;

						case 3:
							printf(">>> Element to delete: ");
							scanf("%d", &element);
							delete(element, valuesB, pointersB);
							break;

						case 4:
							printf("\n");
							printf(">>> ");
							printList(valuesB, pointersB);
							break;

						case 5:
							med = median(valuesB, pointersB);
							printf(">>> Median: %d\n", med);
							break;
					}

				} while (selectionIn);
				break;

			case 3:
				merge(valuesA, pointersA, valuesB, pointersB, mergedList, mergedPointers);
				break;

			case 4:
				printList(mergedList, mergedPointers);
				break;

			case 5:
				med = median(mergedList, mergedPointers);
				printf("Median: %d\n", med);
		}

	} while (selectionOut);

	return 0;
}

void insertA(int element, int values[], int pointers[])
{
	int i = 0, j = 0;
	static int lastIndex = 1;

	values[lastIndex] = element;

	while ((pointers[i] != -1) && (element > values[pointers[i]]))
	{
		i = pointers[i];
	}

	if (pointers[i] == -1)
	{
		pointers[i] = lastIndex;
	}
	else
	{
		j = pointers[i];
		pointers[i] = lastIndex;
		pointers[lastIndex] = j;
	}

	lastIndex++;
}

void insertB(int element, int values[], int pointers[])
{
	int i = 0, j = 0;
	static int lastIndex = 1;

	values[lastIndex] = element;

	while ((pointers[i] != -1) && (element > values[pointers[i]]))
	{
		i = pointers[i];
	}

	if (pointers[i] == -1)
	{
		pointers[i] = lastIndex;
	}
	else
	{
		j = pointers[i];
		pointers[i] = lastIndex;
		pointers[lastIndex] = j;
	}

	lastIndex++;
}

int search(int element, int values[], int pointers[])
{
	int i = 0;

	while ((values[pointers[i]] != element) && (pointers[i] != -1))
	{
		i = pointers[i];
	}

	if (pointers[i] == -1)
	{
		printf("Element (%d) could not found in linked list!\n", element);
	}

	return i;
}

void delete(int element, int values[], int pointers[])
{
	int index;

	if ((index = search(element, values, pointers)) == -1)
	{
		return;
	}
	else
	{
		pointers[index] = pointers[pointers[index]];
		//printf("Element (%d) successfully deleted!\n", element);
	}
}

void printList(int values[], int pointers[])
{
	int i = 0;

	while (pointers[i] != -1)
	{
		printf("%d ", values[pointers[i]]);

		i = pointers[i];
	}

	printf("\n");
}

int median(int values[], int pointers[])
{
	int i = 0, j = 0;

	while ((pointers[j] != -1) && (j != -1))
	{
		j = pointers[pointers[j]];
		i = pointers[i];
	}

	return values[i];
}

void merge(int valuesA[], int pointersA[], int valuesB[], int pointersB[], int mergedList[], int mergedPointers[])
{
	int n = 0, m = 0, i = 0, j = 0, k = 0;

	while (pointersA[i] != -1)
	{
		i = pointersA[i];
		n++;
	}

	while (pointersB[j] != -1)
	{
		j = pointersB[j];
		m++;
	}

	for (i = 1; i<=n; i++)
	{
		mergedList[i] = valuesA[i];
	}

	for (j = 1; j<=m; j++)
	{
		mergedList[j+n] = valuesB[j];
	}

	i = 0;
	j = 0;
	k = 0;

	while ((pointersA[i] != -1) && (pointersB[j] != -1))
	{
		if (valuesA[pointersA[i]] < valuesB[pointersB[j]])
		{
			mergedPointers[k] = pointersA[i];
			i = pointersA[i];
		}
		else
		{
			mergedPointers[k] = pointersB[j] + n;
			j = pointersB[j];
		}
		k = mergedPointers[k];
	}

	if (pointersA[i] == -1)
	{
		while (pointersB[j] != -1)
		{
			mergedPointers[k] = pointersB[j] + n;
			j = pointersB[j];
			k = mergedPointers[k];
		}
	}
	else if (pointersB[j] == -1)
	{
		while (pointersA[i] != -1)
		{
			mergedPointers[k] = pointersA[i];
			i = pointersA[i];
			k = mergedPointers[k];
		}
	}
}