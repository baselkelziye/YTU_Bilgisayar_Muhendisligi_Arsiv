#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200

typedef struct Stack {
	char items[MAX_SIZE];
	int top;
} Stack;

void initialize(Stack *s) {
	s->top = 0;
}

int isEmpty(Stack *s) {
	return !s->top;
}

int isFull(Stack *s) {
	return s->top == MAX_SIZE;
}

void push(Stack *s, char x) {
	if (isFull(s)) {
		printf("Stack overflow.\n");
		exit(1);
	} else {
		s->items[s->top++] = x;
	}
}

void pop(Stack *s, int count) {
	if (isEmpty(s) || count > s->top) {
		printf("Hatali kod!\n");
		exit(1);
	} else {
		s->top -= count;
	}
}

char *asString(Stack *s) {
	int i, len;
	char *str;

	len = s->top;
	str = (char *) malloc((len + 1) * sizeof(char));

	for (i = 0; i < len; i++) {
		str[i] = s->items[i];
	}
	str[i] = '\0';

	return str;
}

char *decode(char *code, int n) {
	Stack *s = (Stack *) malloc(sizeof(Stack));
	int i;
	char c;
	char *decoded;

	initialize(s);
	
	for (i = 0; i < n; i++) {
		c = code[i];
		if (c >= '0' && c <= '9') {
			pop(s, c - '0');
		} else {
			push(s, c);
		}
	}
	
	decoded = asString(s);
	free(s);
	
	return decoded;
}

int equals(char *s1, char *s2) {
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0') {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int n1, n2;
	char *code1, *code2, *decoded1, *decoded2;
	int i;
	int eq;

	printf("1. kod uzunlugu:\n");
	scanf(" %d", &n1);

	printf("1. kod:\n");
	code1 = (char *) malloc((n1 + 1) * sizeof(char));
	for (i = 0; i < n1; i++) {
		scanf(" %c", code1 + i);
	}
	code1[i] = '\0';

	printf("2. kod uzunlugu:\n");
	scanf(" %d", &n2);

	printf("2. kod:\n");
	code2 = (char *) malloc((n2 + 1) * sizeof(char));
	for (i = 0; i < n2; i++) {
		scanf(" %c", code2 + i);
	}
	code2[i] = '\0';
	
	decoded1 = decode(code1, n1);
	decoded2 = decode(code2, n2);

	printf("1. cozulmus kod: %s\n2. cozulmus kod: %s\n", decoded1, decoded2);

	eq = equals(decoded1, decoded2);
	if (eq) {
		printf("ESIT!\n");
	} else {
		printf("ESIT DEGIL!\n");
	}

	free(code1);
	free(code2);
	free(decoded1);
	free(decoded2);

	return 0;
}