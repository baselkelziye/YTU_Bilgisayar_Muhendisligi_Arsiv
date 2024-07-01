#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_NODES];
    int size;
} AdjList;

typedef struct {
    int *nodes;
    int size;
    int cost;
} Cycle;

bool isUniqueCycle(Cycle *shapes, int shapesCount, int *cycleNodes, int cycleSize);
void dfs(AdjList adjList[], int start, int path[], int pathSize, int nodesCount, bool visited[], Cycle *shapes, int *shapesCount);
void findCyclicShapes(AdjList adjList[], int nodesCount, Cycle *shapes, int *shapesCount);
void readAdjacencyList(char *filePath, AdjList adjList[], int *nodesCount, char nodes[][16], int *nodesIndex);
void printShapes(Cycle *shapes, int shapesCount, char nodes[][16]);

int main() {
    char filePath[] = "Sample4.txt";  // Dosya yolu burada degistirilebilir

    int nodesCount = 0;
    char nodes[MAX_NODES][16];
    int nodesIndex[MAX_NODES];
    AdjList adjList[MAX_NODES] = {0};
    Cycle shapes[MAX_NODES];
    int shapesCount = 0;
    int i;

    readAdjacencyList(filePath, adjList, &nodesCount, nodes, nodesIndex);

    findCyclicShapes(adjList, nodesCount, shapes, &shapesCount);

    if (shapesCount == 0) {
        printf("Cokgen tespit edilemedi\n");
    } else {
        printShapes(shapes, shapesCount, nodes);
    }

    // Ciklus dugumleri icin ayrilan bellegi serbest birakir
    for (i = 0; i < shapesCount; i++) {
        free(shapes[i].nodes);
    }

    return 0;
}


/**
 * @params shapes Cycle *shapes: Cokgenlerin kaydedildigi dizi
 *         shapesCount int shapesCount: Cokgenlerin sayisi
 *         cycleNodes int *cycleNodes: Yeni bulunan cokgenin dugumleri
 *         cycleSize int cycleSize: Yeni bulunan cokgenin dugum sayisi
 * @definition Yeni bulunan cokgenin daha once bulunanlar arasinda olup olmadigini kontrol eder.
 * @return bool: Benzersizse true, degilse false dondurur.
 */
bool isUniqueCycle(Cycle *shapes, int shapesCount, int *cycleNodes, int cycleSize) {
    int k, l, m;
    bool found, sameCycle;
    for (k = 0; k < shapesCount; k++) {
        if (shapes[k].size == cycleSize) {
            sameCycle = true;
            for (l = 0; l < cycleSize; l++) {
                found = false;
                for (m = 0; m < cycleSize; m++) {
                    if (shapes[k].nodes[l] == cycleNodes[m]) {
                        found = true;
                        m = cycleSize;
                    }
                }
                if (!found) {
                    sameCycle = false;
                    l = cycleSize;
                }
            }
            if (sameCycle) {
                return false;
            }
        }
    }
    return true;
}


/**
 * @params adjList AdjList adjList[]: Komþuluk listesi
 *         start int start: Baslangic dugumu
 *         path int path[]: Su anki yol
 *         pathSize int pathSize: Yolun boyutu
 *         nodesCount int nodesCount: Dugumlerin sayisi
 *         visited bool visited[]: Ziyaret edilen dugumler
 *         shapes Cycle *shapes: Bulunan cikluslerin kaydedildigi dizi
 *         shapesCount int *shapesCount: Bulunan cikluslerin sayisi
 * @definition Derinlik oncelikli arama (DFS) kullanarak graf icinde ciklus arar ve benzersiz olanlari kaydeder.
 * @return void
 */
void dfs(AdjList adjList[], int start, int path[], int pathSize, int nodesCount, bool visited[], Cycle *shapes, int *shapesCount) {
    visited[start] = true;
    path[pathSize++] = start;
    int i, j, k, l, neighbor, weight, cycleSize, cycleCost;
    int* cycleNodes;
    
    for (i = 0; i < adjList[start].size; i++) {
        neighbor = adjList[start].edges[i].node;
        weight = adjList[start].edges[i].weight;

        if (!visited[neighbor]) {
            dfs(adjList, neighbor, path, pathSize, nodesCount, visited, shapes, shapesCount);
        } else {
            for (j = 0; j < pathSize; j++) {
                if (path[j] == neighbor) {  // Cokgen bulundu
                    cycleSize = pathSize - j;
                    cycleNodes = (int *)malloc((cycleSize + 1) * sizeof(int));
                    cycleCost = 0;

                    for (k = 0; k < cycleSize; k++) {
                        cycleNodes[k] = path[j + k];
                    }
                    cycleNodes[cycleSize] = neighbor;

                    for (k = 0; k < cycleSize; k++) {
                        for (l = 0; l < adjList[cycleNodes[k]].size; l++) {
                            if (adjList[cycleNodes[k]].edges[l].node == cycleNodes[k + 1]) {
                                cycleCost += adjList[cycleNodes[k]].edges[l].weight;
                                l = adjList[cycleNodes[k]].size;
                            }
                        }
                    }

                    if (isUniqueCycle(shapes, *shapesCount, cycleNodes, cycleSize + 1)) {
                    	if(cycleSize + 1 > 3){
                    		shapes[*shapesCount].nodes = cycleNodes;
                        	shapes[*shapesCount].size = cycleSize + 1;
                        	shapes[*shapesCount].cost = cycleCost;
                        	(*shapesCount)++;
						}
                        
                    } else {
                        free(cycleNodes);
                    }
                }
            }
        }
    }

    visited[start] = false;
}

/**
 * @params adjList AdjList adjList[]: Komþuluk listesi
 *         nodesCount int nodesCount: Dugumlerin sayisi
 *         shapes Cycle *shapes: Bulunan cikluslerin kaydedildigi dizi
 *         shapesCount int *shapesCount: Bulunan cikluslerin sayisi
 * @definition Grafin tum dugumleri icin DFS yaparak ciklus arar ve benzersiz olanlari kaydeder.
 * @return void
 */
void findCyclicShapes(AdjList adjList[], int nodesCount, Cycle *shapes, int *shapesCount) {
    int i;
    bool visited[MAX_NODES];
    
    for (i = 0; i < nodesCount; i++) {
        int path[MAX_NODES];
        memset(visited, 0, sizeof(visited));
        dfs(adjList, i, path, 0, nodesCount, visited, shapes, shapesCount);
    }
}

/**
 * @params filePath char *filePath: Dosya yolu
 *         adjList AdjList adjList[]: Komþuluk listesi
 *         nodesCount int *nodesCount: Dugumlerin sayisi
 *         nodes char nodes[][16]: Dugum isimleri
 *         nodesIndex int *nodesIndex: Dugum indeksleri
 * @definition Verilen dosyadan komsuluk listesini okur ve dugum bilgilerini kaydeder.
 * @return void
 */
void readAdjacencyList(char *filePath, AdjList adjList[], int *nodesCount, char nodes[][16], int *nodesIndex) {
    FILE *file = fopen(filePath, "r");
    if (!file) {
        fprintf(stderr, "File could not be opened.\n");
        exit(1);
    }

    char line[256];
    int edges[MAX_NODES][3];
    int i, edgeCount = 0, node1, node2, weight, index1, index2;
	bool found1, found2;
    while (fgets(line, sizeof(line), file)) {
        char node1[16], node2[16];
        weight;
        sscanf(line, "%s %s %d", node1, node2, &weight);

		found1 = false;
		found2 = false;
        index1 = -1; 
		index2 = -1;

        for (i = 0; i < *nodesCount; i++) {
            if (strcmp(nodes[i], node1) == 0) {
                found1 = true;
                index1 = i;
            }
            if (strcmp(nodes[i], node2) == 0) {
                found2 = true;
                index2 = i;
            }
        }

        if (!found1) {
            strcpy(nodes[*nodesCount], node1);
            index1 = (*nodesCount)++;
        }

        if (!found2) {
            strcpy(nodes[*nodesCount], node2);
            index2 = (*nodesCount)++;
        }

        edges[edgeCount][0] = index1;
        edges[edgeCount][1] = index2;
        edges[edgeCount][2] = weight;
        edgeCount++;
    }
    fclose(file);

    for (i = 0; i < edgeCount; i++) {
        node1 = edges[i][0];
        node2 = edges[i][1];
        weight = edges[i][2];

        adjList[node1].edges[adjList[node1].size++] = (Edge){node2, weight};
        adjList[node2].edges[adjList[node2].size++] = (Edge){node1, weight};  // Yönsüz grafik varsayýlýyor
    }

    for (i = 0; i < *nodesCount; i++) {
        nodesIndex[i] = i;
    }
}


/**
 * @params shapes Cycle *shapes: Bulunan cikluslerin kaydedildigi dizi
 *         shapesCount int shapesCount: Bulunan cikluslerin sayisi
 *         nodes char nodes[][16]: Dugum isimleri
 * @definition Bulunan ciklusleri ve cevrelerini yazdirir.
 * @return void
 */
void printShapes(Cycle *shapes, int shapesCount, char nodes[][16]) {
    int i, j, k, a=1, count;
    int validShapesCount = 0;

    for (i = 3; i <= MAX_NODES; i++) {
        count = 0;
        for (j = 0; j < shapesCount; j++) {
            if (shapes[j].size == i + 1) {
                if (count == 0) {
                    printf("%d'gen sayisi: ", i);
                }
                count++;
                validShapesCount++;
            }
        }
        if (count > 0) {
            printf("%d\n", count);
            a=1;
            for (j = 0; j < shapesCount; j++) {
                if (shapes[j].size == i + 1) {
                    printf("%d. %d'gen: ", a, i);
                    for (k = 0; k < shapes[j].size; k++) {
                        printf("%s ", nodes[shapes[j].nodes[k]]);
                    }a++;
                    printf("cevresi:  %d\n", shapes[j].cost);
                }
            }
            printf("\n");
        }
    }
    printf("Toplam yazdirilan cokgen sayisi: %d\n", validShapesCount);
}



