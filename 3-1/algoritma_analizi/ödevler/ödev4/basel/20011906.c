#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG_MODE 0
#define WHITE 0
#define GREY 1
#define BLACK 2
#define MAX 9999

struct graph_node
{
    char ad[50];
    char soyad[50];
    int filled;
};
struct graph_node create_node(char[50], char[50]); // verilen isim ve soyisime gore dugum olusturur
void read_file(char *, struct graph_node **);      // dosyayiokur ve grafi olusturur
int calculate_node_count(char *);                  // dosyadaki dugum sayisini hesaplar
void free_graph(struct graph_node **, int);        // graf a ayrilan bellegi temizler
void print_node(struct graph_node **, int, int);   // verilen dugum numarasina gore dugumu erkana yazdirir

// kuyruk icin gerekli fonksiyonlar
int isEmpty(int, int);
int isFull(int, int, int);
int enqueue(int *, int *, int *, int, int);
int dequeue(int *, int *, int *, int);
int front_queue(int *, int, int);

void bfs(int, struct graph_node **, int *);
int get_root_node(struct graph_node **, int); // bfs de gezerken baslangic dugum bulur

// in degreesi verilen degerden dusuk olanlari graftan eler
int eliminate_nodes(int *, struct graph_node **, int, int);

// grafta dugum koparir,bagli oldugu dugumlerin in degreesini azaltir
void delete_node_from_graph(struct graph_node **, int, int, int *);

struct graph_node **reverse_graph(struct graph_node **, int); // yonlu grafin yonunu degistirir

int get_connection_count(struct graph_node **, int, int); // dugume olan dogru ve dolayli yollari hesaplar.

int main()
{

    int V = calculate_node_count("socialNET.txt");
    struct graph_node **my_graph = (struct graph_node **)calloc(V, sizeof(struct graph_node *));
    if (my_graph == NULL)
    {
        printf("ERROR! Couldn't Allocate Memory for graph!");
        exit(101);
    }

    int i;
    for (i = 0; i < V; i++)
    {
        my_graph[i] = (struct graph_node *)calloc(V, sizeof(struct graph_node));
    }
    int M; // in degree icin
    int X; // M den buyuk olacak!
    int Y;
    int selection;
    int *in_degree = (int *)calloc(V, sizeof(int));
    read_file("socialNET.txt", my_graph);
    do
    {
        printf("\n\t\t\t\t\t\tBasel KELZIYE 20011906");
        printf("\n1- Normal Mod:");
        printf("\n2- Detayli Mod:");
        printf("\n3- Cikis\n");
        scanf(" %d", &selection);
        if (selection == 1)
        {
            printf("\n Lutfem Sirasiyla M, X ve Y degerlerini giriniz\n");
            scanf(" %d %d %d", &M, &X, &Y);
            bfs(V, my_graph, in_degree);
            while (eliminate_nodes(in_degree, my_graph, V, M))
                ;
            struct graph_node **new_graph = reverse_graph(my_graph, V);
            for (i = 0; i < V; i++)
            {
                int count = get_connection_count(new_graph, V, i);
                if (Y >= count &&
                    X <= in_degree[i] &&
                    in_degree[i] != MAX)
                {
                    printf("\n%d Node is Influencer!", i + 1);
                }
            }
        }

        if (selection == 2)
        {
            for (i = 0; i < V; i++)
            {
                in_degree[i] = 0;
            }
            bfs(V, my_graph, in_degree);
            printf("\n***************************************************\n");
            printf("\nBaslangic in-degree Sayisi:\n");
            for (i = 0; i < V; i++)
            {
                printf("\nNode %d in-degree: %d", i + 1, in_degree[i]);
            }
            printf("\n***************************************************\n");
            printf("\nLutfen Dugumleri Elemek icin M degerini giriniz:\n");
            scanf(" %d", &M);
            while (eliminate_nodes(in_degree, my_graph, V, M))
                ;
            for (i = 0; i < V; i++)
            {
                if (in_degree[i] != MAX)
                {
                    printf("\nNode %d in-degree: %d", i + 1, in_degree[i]);
                    print_node(my_graph, i, V);
                }
            }
            printf("\n***************************************************\n");
            printf("\nLutfen Sirasiyla X ve Y degerlerini giriniz:\n");
            scanf(" %d %d", &X, &Y);
            struct graph_node **new_graph = reverse_graph(my_graph, V);
            for (i = 0; i < V; i++)
            {
                int count = get_connection_count(new_graph, V, i);
                if (Y >= count &&
                    X <= in_degree[i] &&
                    in_degree[i] != MAX)
                {
                    printf("\n%d Node is Influencer!", i + 1);
                    print_node(my_graph, i, V);
                    printf("In-Degree: %d", in_degree[i]);
                    printf("\nTotal Count Number is: %d", count);
                    printf("\n");
                }
            }
        }
    } while (selection != 3);

    // free(in_degree);
    // 'free(ne)'
    // free_graph(new_graph, V);
    // free_graph(my_graph, V);
    return 0;
}

void read_file(char *file_name, struct graph_node **my_graph)
{

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("\nERROR! Unable To Open TXT file!");
        exit(101);
    }

    // Create a buffer for reading the file
    char buffer[1024];
    int i = 0;
    int index;
    char name[50];
    char last_name[50];
    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        struct graph_node my_node;
        // Tokenize the line by comma
        char *token = strtok(buffer, ",");

        // Print each word
        if (i % 2 == 0)
        {

            while (token != NULL)
            {
                index = (int)strtol(token, (char **)NULL, 10) - 1;
                token = strtok(NULL, ",");
                strcpy(name, token);
                token = strtok(NULL, ",");
                strcpy(last_name, token);

                // printf("%d %s %s\n", index, name, last_name);
                token = strtok(NULL, ",");
            }
            my_node = create_node(name, last_name);
            // print_node(my_node);
        }
        else
        {
            while (token != NULL)
            {
                int destination = (int)strtol(token, (char **)NULL, 10) - 1;
                if (index != destination)
                {
                    // my_node.in_degree++;
                    my_graph[index][destination] = my_node;
                }
                // printf("%s\n", token);
                token = strtok(NULL, ",");
            }
        }
        i++;
    }

    // Close the file
    fclose(fp);
}

int calculate_node_count(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("\nERROR! Unable To Open TXT file!");
        exit(101);
    }
    int index_count = 0;
    char buff[100];

    while (fscanf(fp, "%1023s", buff) == 1)
    {
        index_count++;
    }

    fclose(fp);

    return index_count / 2;
}

void free_graph(struct graph_node **graph, int V)
{
    int i;
    for (i = 0; i < V; i++)
    {
        free(graph[i]);
    }
    free(graph);
}
void print_node(struct graph_node **my_graph, int index, int V)
{
    int i;
    for (i = 0; i < V; i++)
    {
        if (my_graph[index][i].filled == 1)
        {
            printf("\nName is : %s", my_graph[index][i].ad);
            printf("\nLastname is : %s", my_graph[index][i].soyad);
            return;
        }
    }
}

struct graph_node create_node(char name[50], char last_name[50])
{
    struct graph_node my_node;

    strcpy(my_node.ad, name);
    strcpy(my_node.soyad, last_name);
    my_node.filled = 1;

    return my_node;
}

int isEmpty(int rear, int front)
{
    if (rear == -1 && front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(int rear, int front, int len)
{

    if ((rear + 1) % len == front)
    {
        printf("\nQueue is Full");
        return 1;
    }
    else
    {
        return 0;
    }
}

int enqueue(int *Queue, int *front, int *rear, int x, int len)
{
    if (isFull(*rear, *front, len))
    {

        printf("\n enqueuedan dondu");
        return 0;
    }
    else if (isEmpty(*rear, *front))
    {
        *front = 0;
        *rear = 0;
    }
    else
    {
        *rear = (*rear + 1) % len; // we use the modulo so after we delete an element that index is reusable and not wasted!
    }
    Queue[*rear] = x;

    return 0;
}

int dequeue(int *Queue, int *rear, int *front, int len)
{
    if (isEmpty(*rear, *front))
    {
        return 0;
    }
    else if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = (*front + 1) % len;
    }
    return 0;
}

int get_root_node(struct graph_node **my_graph, int V)
{
    int i, j;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (my_graph[j][i].filled == 1)
            {
                return i;
            }
        }
    }
    return -1;
}

void bfs(int V, struct graph_node **my_graph, int *in_degree)
{
    int *queue = (int *)malloc(V * sizeof(int));
    if (queue == NULL)
    {
        printf("\nERROR! Couldnt Allocate Queue!");
        exit(101);
    }

    int rear = -1, front = -1, i; // kuyruk icin degiskenler
    int root_node = get_root_node(my_graph, V);
    int *color = (int *)calloc(V, sizeof(int)); // bfs icin renkler dizisi
    if (root_node == -1)
    {
        printf("\nERROR! Unable to get root node!");
        exit(101);
    }

    printf("\nStarting Node is : %d", root_node);
    enqueue(queue, &front, &rear, root_node, V); // kuyruga buldugumuz root node i at
    do
    {
        int u = front_queue(queue, rear, front);
        dequeue(queue, &rear, &front, V);
        for (i = 0; i < V; i++)
        {
            if (my_graph[u][i].filled == 1)
            {
                in_degree[i]++;
                if (color[i] == WHITE)
                {
                    // printf("\nFrom Node %d to Node %d", u + 1, i + 1);
                    enqueue(queue, &front, &rear, i, V);
                    color[i] = GREY;
                }
            }
        }
        color[u] = BLACK;

    } while (!isEmpty(rear, front));

    // free(queue);
    // free(color);
}

int front_queue(int *queue, int rear, int front)
{
    if (!isEmpty(rear, front))
    {
        return queue[front];
    }
    return -1;
}

int eliminate_nodes(int *in_degree, struct graph_node **my_graph, int V, int semaphore)
{

    int i;
    for (i = 0; i < V; i++)
    {
        if (in_degree[i] < semaphore)
        {
            in_degree[i] = MAX;
            delete_node_from_graph(my_graph, V, i, in_degree);
            // bfs(V, my_graph, in_degree);
            return 1;
        }
    }
    return 0;
}

void delete_node_from_graph(struct graph_node **my_graph, int V, int index, int *in_degree)
{
    int i;
    for (i = 0; i < V; i++)
    {
        if (my_graph[index][i].filled == 1)
        {
            my_graph[index][i].filled = 0;
            if (in_degree[i] != MAX)
            {
                in_degree[i]--;
            }
        }
    }
}

struct graph_node **reverse_graph(struct graph_node **my_graph, int V)
{
    int i, j;

    struct graph_node **new_graph = calloc(V, sizeof(struct graph_node *));
    if (new_graph == NULL)
    {
        printf("\nERROR! Couldn't Allocate Memory For New Graph!");
        exit(101);
    }
    for (i = 0; i < V; i++)
    {
        new_graph[i] = calloc(V, sizeof(struct graph_node));
    }

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (my_graph[i][j].filled == 1 && my_graph[j][i].filled != 1)
            {
                new_graph[j][i].filled = 1;
                new_graph[i][j].filled = 0;
            }

            else if (new_graph[i][j].filled != 1)
            {
                new_graph[i][j] = my_graph[i][j];
            }
        }
    }

    return new_graph;
}

int get_connection_count(struct graph_node **my_graph, int V, int node)
{

    int *queue = (int *)malloc(V * sizeof(int));
    if (queue == NULL)
    {
        printf("\nERROR! Couldnt Allocate Queue!");
        exit(101);
    }
    int rear = -1, front = -1;
    int counter = 0;
    int *color = (int *)calloc(V, sizeof(int));
    int i;
    int flag = 0;
    for (i = 0; i < V; i++)
    {
        if (my_graph[node][i].filled == 1)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        // free(color);
        return -1;
    }
    // counter++;
    enqueue(queue, &front, &rear, node, V);
    do
    {
        int u = front_queue(queue, rear, front);
        dequeue(queue, &rear, &front, V);
        for (i = 0; i < V; i++)
        {
            if (my_graph[u][i].filled == 1)
            {

                if (color[i] == WHITE)
                {
                    // printf("\nFrom Node %d to Node %d", u + 1, i + 1);
                    counter++;
                    enqueue(queue, &front, &rear, i, V);
                    color[i] = GREY;
                }
            }
        }
        color[u] = BLACK;

    } while (!isEmpty(rear, front));

    // free(queue);
    // free(color);
    return counter;
}