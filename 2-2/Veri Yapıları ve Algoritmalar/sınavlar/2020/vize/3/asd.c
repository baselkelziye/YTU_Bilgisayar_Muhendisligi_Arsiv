#include <stdio.h>
#include <stdlib.h>

typedef struct File {
	int no, page;
	struct File *next;
} File;

typedef struct Queue {
	File *head;
} Queue;

void enqueue(Queue *q, File *f) {
	File *temp = q->head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = f;
}

File *dequeue(Queue *q, int no) {
	File *temp = q->head;
	File *temp2;
	while (temp->next != NULL && temp->next->no != no) {
		temp = temp->next;
	}
	if (temp->next != NULL && temp->next->no == no) {
		temp2 = 
	}
}

void print(Queue *q) {
	int i;
	File *f = dequeue(q);
	for (i = 1; i <= f->page; i++) {
		printf("Dosya %d, sayfa %d yazdirildi\n", f->no, i);
	}
	free(f);
}

void delete(Queue *q, int no) {
	Queue *temp;
	File *f;
	temp = createQueue();
	while (!isEmpty(q)) {
		f = dequeue(q);
		if (f->no != no) {
			enqueue(temp, f);
		} else {
			free(f);
		}
	}
	while (!isEmpty(temp)) {
		f = dequeue(q);
		enqueue(q, f);		
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
