#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10

void print_graph(int **graph, int N);
int read_graph(int **graph, int *N, char *file_path);
int findPrise(int **graph, int N, int prise_node);
void getNeighbotCount(int **graph, int N, int *neighbor_count);
int isNbr(int **graph, int node, int prise, int N);
void print_array(int *arr, int N);
int find_max_neighbor(int **graph, int *neighbour_count, int *prise_neighbor, int N);
void notNbr(int **graph, int node, int *not_prise);
void itIsNbr(int **graph, int *line, int node, int *not_prise, int *prise_neighbor, int N, int *);
int check_all_neighbors(int **graph, int N, int node, int prise_node);
int isNeighbor(int *line, int prise);

int main()
{
    int N = 0;
    int prise_node = 4;
    int **graph = (int **)calloc(MAXN, sizeof(int *));
    for (int i = 0; i < MAXN; i++)
    {
        graph[i] = (int *)calloc(MAXN, sizeof(int));
        for (int j = 0; j < MAXN; j++)
        {
            graph[i][j] = -1;
        }
    }

    // sıra sıra yorum satırından çıkararak kontrol ediniz. aynı anda 2 grafın açık olmaması gerekmektedir.

    // read_graph(graph, &N, "G1_KList.txt");
    // print_graph(graph, N);
    // printf("\nN: %d\n", N);
    // findPrise(graph, N, 5);

    // read_graph(graph, &N, "G2_KList.txt");
    // print_graph(graph, N);
    // printf("\nN: %d\n", N);
    // findPrise(graph, N, 3);

    read_graph(graph, &N, "G3_KList.txt");
    print_graph(graph, N);
    printf("\nN: %d\n", N);
    findPrise(graph, N, 4);

    for (int i = 0; i < MAXN; i++)
        free(graph[i]);
    free(graph);
}

int isNbr(int **graph, int node, int prise, int N)
{
    int i = 1;
    int flag = 0;
    while (graph[node][i] != -1)
    {
        if (graph[node][i] == prise)
            flag = 1;
        i++;
    }

    return flag;
}

int findPrise(int **graph, int N, int prise_node)
{
    int not_prise[N];
    int prise_neighbor[N];
    int neighbor_count[N];
    int node_list[N];
    int i = 0, j = 0;
    int max;
    int result_node;

    int node, res = 0;
    int *line;
    int find_prise;

    for (int i = 0; i < N; i++)
    {
        not_prise[i] = -1;
        prise_neighbor[i] = -1;
        neighbor_count[i] = 0;
    }

    getNeighbotCount(graph, N, neighbor_count);

    print_array(neighbor_count, N);

    while (res == 0)
    {
        node = find_max_neighbor(graph, neighbor_count, prise_neighbor, N);
        res = isNbr(graph, node, prise_node, N);

        printf("Node: %d,res: %d\n", node, res);
        switch (res)
        {
        case 0:
            prise_neighbor[node] = 0;
            notNbr(graph, node, not_prise);
            break;
        case 1:
            prise_neighbor[node] = 1;
            itIsNbr(graph, &graph[node][1], node, not_prise, prise_neighbor, N, node_list);

            while (node_list[j] != -1)
            {
                find_prise = check_all_neighbors(graph, N, node_list[j], prise_node);
                // printf("prise:%d res:%d\n", node_list[j], find_prise);
                if (find_prise == 1)
                {
                    printf("Prise Node: %d\n", node_list[j]);
                }
                j++;
            }
        }
    }
}

void notNbr(int **graph, int node, int *not_prise)
{
    int i = 0;
    while (graph[node][i] != -1)
    {
        not_prise[graph[node][i]] = 0;
        i++;
    }
}

void itIsNbr(int **graph, int *line, int node, int *not_prise, int *prise_neighbor, int N, int *node_list)
{
    int i = 0, j = 0;
    while (line[i] != -1)
    {
        if (not_prise[line[i]] != 0)
        {
            node_list[j] = line[i];
            printf("%d ", line[i]);
            j++;
        }
        i++;
    }
    node_list[j] = -1;
    printf("\n");
}

int check_all_neighbors(int **graph, int N, int node, int prise_node)
{
    int i = 1;                   // Start from 1 since first element is the node itself
    while (graph[node][i] != -1) // Continue until end of adjacency list
    {
        if (isNbr(graph, graph[node][i], prise_node, N) == 0)
        {
            return 0; // If any neighbor is not connected to prize_node, return 0
        }
        i++;
    }
    return 1; // All neighbors are connected to prize_node
}

int find_max_neighbor(int **graph, int *neighbour_count, int *prise_neighbor, int N)
{
    int i, max, idx;
    max = neighbour_count[0];
    idx = 0;

    for (i = 0; i < N; i++)
    {
        if (neighbour_count[i] >= max && prise_neighbor[i] != 0)
        {
            max = neighbour_count[i];
            idx = i;
        }
    }

    return idx;
}

void getNeighbotCount(int **graph, int N, int *neighbor_count)
{
    int i = 0, j = 0;

    for (i = 0; i < N; i++)
    {
        j = 0;
        while (graph[i][j] != -1)
        {
            neighbor_count[graph[i][0]]++;
            j++;
        }
        neighbor_count[graph[i][0]]--;
    }
}

// int isNeighbor(int *line, int prise)
// {
//     int i = 1;
//     int flag = 0;

//     while (line[i] != -1)
//     {
//         if (line[i] == prise)
//             flag = 1;
//     }

//     return flag;
// }

int read_graph(int **graph, int *N, char *file_path)
{
    FILE *fp;
    int read_flag = 0;
    char line[256];
    char *token;

    fp = fopen(file_path, "r");
    if (!fp)
    {
        perror("Dosya açılamadı");
        return 1;
    }

    int i = 0;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        token = strtok(line, "\t\r\n ");
        i = 0;
        while (token != NULL)
        {
            graph[*N][i] = atoi(token);
            i++;
            token = strtok(NULL, "\t\r\n ");
        }
        graph[*N][i + 1] = -1;

        (*N)++;
    }

    fclose(fp);

    return 0;
}

void print_graph(int **graph, int N)
{

    for (int i = 0; i < N; i++)
    {
        printf("%d:", graph[i][0]);
        int j = 1;
        while (graph[i][j] != -1)
        {
            printf(" %d", graph[i][j]);
            j++;
        }
        printf("\n");
    }
}

void print_array(int *arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}