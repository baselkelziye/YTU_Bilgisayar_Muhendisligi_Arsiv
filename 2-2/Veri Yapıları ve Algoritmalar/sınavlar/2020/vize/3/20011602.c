#include <stdio.h>
#include <stdlib.h>

typedef struct File {
	int no, page;
	struct File *next;
} File;

typedef struct Queue {
	File *head;
} Queue;

File *createFile(int no, int page) {
	File *f = (File *) malloc(sizeof(File));
	f->no = no;
	f->page = page;
	f->next = NULL;
	return f;
}

Queue *createQueue() {
	Queue *q = (Queue *) malloc(sizeof(Queue));
	q->head = NULL;
	return q;
}

void freeQueue(Queue *q) {
	File *f;
	while (!isEmpty(q)) {
		f = dequeue(q);
		free(f);
	}
	free(q);
}

/* Soru 1 */
void print(Queue *q) {
	if (isEmpty(q)) {
		printf("Dosya yok");
		return;
	}
	int i;
	File *f = dequeue(q);
	for (i = 1; i <= f->page; i++) {
		printf("Dosya %d, sayfa %d yazdirildi\n", f->no, i);
	}
	free(f);
}

/* Soru 2 */
void delete(Queue *q, int no) {
	Queue *temp;
	File *f;
	int found = 0;
	temp = createQueue();
	while (!isEmpty(q)) {
		f = dequeue(q);
		if (f->no != no) {
			enqueue(temp, f);
		} else {
			free(f);
			found = 1;
		}
	}
	while (!isEmpty(temp)) {
		f = dequeue(q);
		enqueue(q, f);		
	}
	if (!found) {
		printf("Dosya bulunamadi\n");
	}
}

int main() {
	Queue *q;
	int menu;
	int no, page;

	menu = 0;
	while (menu != 4) {
		printf("Siraya Ekle: 1, Yazdir: 2, Sil: 3, Cikis: 4\n");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf("Dosta No:\n");
			scanf("%d", &no);
			printf("Sayfa Sayisi:\n");
			scanf("%d", &page);
			enqueue(q, createFile(no, page));
			break;
		case 2:
			print(q);
			break;
		case 3:
			printf("Dosta No:\n");
			scanf("%d", &no);
			delete(q, no);
			break;
		}
	}

	freeQueue(q);
	return 0;
}
