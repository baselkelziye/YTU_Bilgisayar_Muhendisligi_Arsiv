#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int row, col, val;
	struct Node *next;
} Node;

Node *createNode(int row, int col, int val) {
	Node *n = (Node *) malloc(sizeof(Node));
	if (n == NULL) {
		printf("Allocation error.\n");
		exit(1);
	}
	n->row = row;
	n->col = col;
	n->val = val;
	n->next = NULL;
}

void freeList(Node *head) {
	Node *current, *prev;
	if (head == NULL) {
		printf("Empty list.\n");
	} else {
		current = head;
		while (current != NULL) {
			prev = current;
			current = current->next;
			free(prev);
		}
	}
}

int main() {
	int count, row, col, val;
	int i;
	Node *head, *iter;
	int columnCount;
	int *columns;

	printf("Deger sayisi:\n");
	scanf("%d", &count);

	head = NULL;
	for (i = 0; i < count; i++) {
		printf("Satir:\n");
		scanf("%d", &row);
		printf("Sutun:\n");
		scanf("%d", &col);
		printf("Deger:\n");
		scanf("%d", &val);
		if (head == NULL) {
			head = createNode(row, col, val);
			iter = head;
		} else {
			iter->next = createNode(row, col, val);
			iter = iter->next;
		}
	}
	columnCount = head->col;
	iter = head->next;
	while (iter != NULL) {
		if (iter->col > columnCount) {
			columnCount = iter->col;
		}
		iter = iter->next;
	}
	columnCount++;

	columns = (int *) calloc(columnCount, sizeof(int));
	
	iter = head;
	while (iter != NULL) {
		columns[iter->col] = 1;
		iter = iter->next;
	}

	printf("Bos sutunlar:\n");
	for (i = 0; i < columnCount; i++) {
		if (columns[i] == 0) {
			printf("%d\n", i);
		}
	}

	free(columns);
	freeList(head);
	return 0;
}
