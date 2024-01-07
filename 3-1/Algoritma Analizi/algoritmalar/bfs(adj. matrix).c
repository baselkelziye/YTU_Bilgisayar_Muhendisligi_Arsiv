#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10000

typedef struct queue {
  int items[MAX_QUEUE_SIZE];
  int front;
  int rear;
} queue;

void enqueue(queue *q, int value) {
  if (q->rear == MAX_QUEUE_SIZE - 1) {
    printf("Queue full\n");
  } else {
    q->items[++(q->rear)] = value;
  }
}

int dequeue(queue *q) {
  if (q->front > q->rear) {
    printf("Queue empty\n");
    return -1;
  } else {
    return q->items[(q->front)++];
  }
}

int is_empty(queue *q) {
  return q->front > q->rear;
}

void bfs(int graph[][6], int start, int n) {
  queue q;
  int i;
  int visited[6] = {0};

  q.front = 0;
  q.rear = -1;

  enqueue(&q, start);
  visited[start] = 1;

  while (!is_empty(&q)) {
    int current = dequeue(&q);
    printf("%d ", current);

    for (i = 0; i < n; i++) {
      if (graph[current][i] && !visited[i]) {
        enqueue(&q, i);
        visited[i] = 1;
      }
    }
  }
}

int main() {
  int graph[6][6] = {
      {0, 1, 1, 0, 0, 0},
      {1, 0, 0, 1, 1, 0},
      {1, 0, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 1},
      {0, 1, 0, 0, 0, 1},
      {0, 0, 1, 1, 1, 0},
  };

  bfs(graph, 0, 6);

  return 0;
}
//uygulama, kullanýcýnýn Ýstanbul içerisinde daha önceden gittiði yerleri, ilçelere bulunduðu yakýnlýðý ve kullanýcýnýn kiþiliði ile belirli sorular sorularak 

