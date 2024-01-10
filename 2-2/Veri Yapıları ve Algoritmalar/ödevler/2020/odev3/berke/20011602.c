/* Berke Özgen 20011602 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEARCH_SIZE 100
#define MAX_RESULT_COUNT 3

typedef struct Node {
	int searchValue;
	int searchCount;
	struct Node *next;
} Node;

typedef struct Graph {
	int count;
	Node **adj;
} Graph;

Node *createNode(int searchValue, int searchCount) {
	Node *n = (Node *) malloc(sizeof(Node));
	n->searchValue = searchValue;
	n->searchCount = searchCount;
	n->next = NULL;
	return n;
}

Graph *createGraph(int count) {
	int i;
	Graph *g = (Graph *) malloc(sizeof(Graph));
	g->count = count;
	g->adj = (Node **) malloc(count * sizeof(Node *));
	for (i = 0; i < count; i++) {
		g->adj[i] = NULL;
	}
	return g;
}

void printNode(Node *n, char **symbols) {
	if (n != NULL) {
		printf("\t\t%s: %d\n", symbols[n->searchValue], n->searchCount);
		printNode(n->next, symbols);
	}
}

void printGraph(Graph *g, char **symbols) {
	int i;
	printf("[\n");
	for (i = 0; i < g->count; i++) {
		printf("\t%s -> [", symbols[i]);
		if (g->adj[i] != NULL) printf("\n");
		printNode(g->adj[i], symbols);
		if (g->adj[i] != NULL) printf("\t");
		printf("]\n");
	}
	printf("]\n");
}

void freeNode(Node *n) {
	if (n != NULL) {
		freeNode(n->next);
		free(n);
	}
}

void freeGraph(Graph *g) {
	int i;
	if (g != NULL) {
		for (i = 0; i < g->count; i++) {
			freeNode(g->adj[i]);
		}
		free(g->adj);
		free(g);
	}
}

void addEdge(Graph *g, int src, int dest, int srcSearchCount, int destSearchCount) {
	Node *n = createNode(dest, destSearchCount);
	n->next = g->adj[src];
	g->adj[src] = n;
	n = createNode(src, srcSearchCount);
	n->next = g->adj[dest];
	g->adj[dest] = n;
}

void *updateNodeRecursively(Node *n, int offset) {
	if (n != NULL) {
		n->searchValue += offset;
		updateNodeRecursively(n->next, offset);
	}
}

void appendNode(Node *root, Node *n) {
	if (root != NULL) {
		if (root->next == NULL) {
			root->next = n;
		} else {
			appendNode(root->next, n);
		}
	}
}

int nodeExists(Graph *g, char **symbols, char *symbol) {
	int i = 0;
	while (i < g->count) {
		if (!strcmp(symbol, symbols[i])) {
			return i;
		} else {
			i++;
		}
	}
	return -1;
}

void updateAllOccurences(Graph *g, char **symbols, char *symbol, int val) {
	int i, exists;
	Node *iter;
	for (i = 0; i < g->count; i++) {
		iter = g->adj[i];
		exists = 0;
		while (iter != NULL && !exists) {
			if (symbols[iter->searchValue] != NULL && !strcmp(symbol, symbols[iter->searchValue])) {
				exists = 1;
			} else {
				iter = iter->next;
			}
		}
		if (exists) {
			iter->searchValue = val;
		}
	}
}

Node *copyNode(Node *n) {
	Node *copied = NULL;
	if (n != NULL) {
		copied = createNode(n->searchValue, n->searchCount);
		copied->next = copyNode(n->next);
	}
	return copied;
}

void packGraph(Graph *g, char **symbols) {
	int i, j, k, duplicates = 0;
	for (i = 0; i < g->count - 1; i++) {
		if (g->adj[i] == NULL && symbols[i] == NULL) {
			j = i + 1;
			while (j < g->count && symbols[j] == NULL) {
				j++;
			}
			if (j < g->count) {
				updateAllOccurences(g, symbols, symbols[j], i);
				g->adj[i] = g->adj[j];
				symbols[i] = symbols[j];
				g->adj[j] = NULL;
				symbols[j] = NULL;
			}
		}
	}
	for (i = 0; i < g->count; i++) {
		if (g->adj[i] == NULL && symbols[i] == NULL) {
			duplicates++;
		}
	}
	g->count -= duplicates;
}

char *copySymbol(char *symbol) {
	char *copied = NULL;
	if (symbol != NULL) {
		copied = (char *) malloc((strlen(symbol) + 1) * sizeof(char));
		strcpy(copied, symbol);
	}
	return copied;
}

Graph *mergeGraphs(Graph *g1, Graph *g2, char **symbols1, char **symbols2, char **symbols3) {
	Graph *merged = createGraph(g1->count + g2->count);
	int i;
	int exists;
	Node *temp;
	for (i = 0; i < g1->count; i++) {
		symbols3[i] = copySymbol(symbols1[i]);
		merged->adj[i] = copyNode(g1->adj[i]);
	}
	for (i = 0; i < g2->count; i++) {
		temp = copyNode(g2->adj[i]);
		updateNodeRecursively(temp, g1->count);
		merged->adj[i + g1->count] = temp;
		symbols3[i + g1->count] = copySymbol(symbols2[i]);
	}
	for (i = 0; i < g2->count; i++) {
		exists = nodeExists(g1, symbols1, symbols2[i]);
		if (exists != -1) {
			updateAllOccurences(merged, symbols3, symbols2[i], exists);
			appendNode(merged->adj[exists], merged->adj[i + g1->count]);
			merged->adj[i + g1->count] = NULL;
			free(symbols3[i + g1->count]);
			symbols3[i + g1->count] = NULL;
		}
	}
	packGraph(merged, symbols3);
	return merged;
}

Node **topRelevantSearches(Graph *g, char **symbols, char *symbol) {
	Node **arr = (Node **) malloc(g->count * sizeof(Node *));
	int exists;
	Node *iter;
	int i, j, max;
	for (i = 0; i < g->count; i++) {
		arr[i] = NULL;
	}
	exists = nodeExists(g, symbols, symbol);
	if (exists != -1) {
		i = 0;
		iter = g->adj[exists];
		while (iter != NULL) {
			arr[i] = iter;
			i++;
			iter = iter->next;
		}
		i = 0;
		while (i < g->count && arr[i] != NULL) {
			max = i;
			j = i + 1;
			while (j < g->count && arr[j] != NULL) {
				if (arr[j]->searchCount > arr[max]->searchCount) {
					max = j;
				}
				j++;
			}
			iter = arr[i];
			arr[i] = arr[max];
			arr[max] = iter;
			i++;
		}
	}
	return arr;
}

void incrementSearchCount(Graph *g, char **symbols, char *symbol) {
	int i, exists;
	Node *iter;
	for (i = 0; i < g->count; i++) {
		iter = g->adj[i];
		exists = 0;
		while (iter != NULL && !exists) {
			if (symbols[iter->searchValue] != NULL && !strcmp(symbol, symbols[iter->searchValue])) {
				exists = 1;
			} else {
				iter = iter->next;
			}
		}
		if (exists) {
			iter->searchCount++;
		}
	}
}

int main() {
	Graph *g1, *g2, *merged;
	int count1, count2;
	char **symbols1, **symbols2, **symbols3;
	int srcSearchCount, destSearchCount;
	int i;
	char *search;
	int cont;
	Node **results;

	printf("1. graftaki dugum sayisi:\n");
	scanf("%d", &count1);

	g1 = createGraph(count1);
	symbols1 = (char **) malloc(count1 * sizeof(char *));
	for (i = 0; i < count1; i++) {
		symbols1[i] = (char *) malloc(MAX_SEARCH_SIZE * sizeof(char));
	}

	printf("1. sorgu:\n");
	scanf("%s", symbols1[0]);
	printf("1. sorgu sayisi:\n");
	scanf("%d", &srcSearchCount);

	for (i = 1; i < count1; i++) {
		printf("--> %d. benzer sorgu:\n", i);
		scanf("%s", symbols1[i]);
		printf("--> %d. benzer sorgunun sorgu sayisi:\n", i);
		scanf("%d", &destSearchCount);
		addEdge(g1, 0, i, srcSearchCount, destSearchCount);
	}

	printf("2. graftaki dugum sayisi:\n");
	scanf("%d", &count2);

	g2 = createGraph(count2);
	symbols2 = (char **) malloc(count2 * sizeof(char *));
	for (i = 0; i < count2; i++) {
		symbols2[i] = (char *) malloc(MAX_SEARCH_SIZE * sizeof(char));
	}

	printf("2. sorgu:\n");
	scanf("%s", symbols2[0]);
	printf("2. sorgu sayisi:\n");
	scanf("%d", &srcSearchCount);

	for (i = 1; i < count2; i++) {
		printf("--> %d. benzer sorgu:\n", i);
		scanf("%s", symbols2[i]);
		printf("--> %d. benzer sorgunun sorgu sayisi:\n", i);
		scanf("%d", &destSearchCount);
		addEdge(g2, 0, i, srcSearchCount, destSearchCount);
	}
	
	symbols3 = (char **) malloc((count1 + count2) * sizeof(char *));
	merged = mergeGraphs(g1, g2, symbols1, symbols2, symbols3);
	printGraph(merged, symbols3);

	search = (char *) malloc(MAX_SEARCH_SIZE * sizeof(char));
	cont = 1;
	while (cont) {
		printf("Sorgu:\n");
		scanf("%s", search);
		results = topRelevantSearches(merged, symbols3, search);
		if (*results == NULL) {
			printf("Ilgili sorgu bulunamadi.\n");
		} else {
			printf("Ilgili sorgular:\n");
			i = 0;
			while (i < merged->count && results[i] != NULL && i < MAX_RESULT_COUNT) {
				printf("--> %d. %s: %d\n", i + 1, symbols3[results[i]->searchValue], results[i]->searchCount);
				i++;
			}
		}
		incrementSearchCount(merged, symbols3, search);
		free(results);
		printf("Devam? 1/0:\n");
		scanf("%d", &cont);
	}

	for (i = 0; i < count1; i++) {
		free(symbols1[i]);
	}
	free(symbols1);
	freeGraph(g1);

	for (i = 0; i < count2; i++) {
		free(symbols2[i]);
	}
	free(symbols2);
	freeGraph(g2);
	
	for (i = 0; i < merged->count; i++) {
		free(symbols3[i]);
	}
	free(symbols3);
	freeGraph(merged);

	free(search);

	return 0;
}