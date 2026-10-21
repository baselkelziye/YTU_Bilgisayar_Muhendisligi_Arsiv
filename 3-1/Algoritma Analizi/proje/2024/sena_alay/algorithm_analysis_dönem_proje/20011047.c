//
//  20011047.c
//  termproject
//
//  Created by Sena ALAY on 6.01.2024.
//

//20011047 Sena Alay 
//input.txt dosyası ile çalıştırabilmek için dosyada ilk satırda düğüm sayısı olmalı
//ayrıca dosya komşuluk matrisi ile yazılmış olmalı
//5 tane input.txt dosyası koydum ödev klasörüme

/*
@brief 
 -----Bu program, girilen düğüm sayısına ve komşuluk matrisine göre 
 -----bir ağın topluluklarını (communities) algılar.
 -----Program, input.txt dosyasından düğüm sayısı ve komşuluk matrisini okur. 
 -----Bu matris, ağın yapısını gösterir.
 -----Program, kenarlar arası "betweenness" değerlerini hesaplayarak 
 -----ağın topluluklarını tespit eder ve bunları ekrana basar.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_NODES 100

/*
@brief -> Kenarlar arası "betweenness" değerlerini hesaplar.
@param -> adjacencyMatrix[MAX_NODES][MAX_NODES] Komşuluk matrisi
@param -> numNodes Düğüm sayısı
@param -> edgeBetweenness[MAX_NODES][MAX_NODES] Kenarlar arası betweenness değerlerini tutar
*/
void calculateEdgeBetweenness(int adjacencyMatrix[MAX_NODES][MAX_NODES], int numNodes, float edgeBetweenness[MAX_NODES][MAX_NODES]) {
    // Kenar ara değerlerini sıfırla
    int i,j;
    int source = 0, neighbor = 0;
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            edgeBetweenness[i][j] = 0.0;
        }
    }

    // Her düğüm için BFS uygula
    for (source = 0; source < numNodes; source++) {
        int queue[MAX_NODES], front = 0, rear = 0;
        int distance[MAX_NODES], count[MAX_NODES];
        float credit[MAX_NODES];
        bool visited[MAX_NODES] = {false};

        // BFS için gerekli değişkenleri sıfırla
        for (i = 0; i < numNodes; i++) {
            distance[i] = INT_MAX;
            count[i] = 0;
            credit[i] = 0.0;
        }

        // BFS uygula
        distance[source] = 0;
        count[source] = 1;
        queue[rear++] = source;
        visited[source] = true;

        // BFS sırasında düğümleri ziyaret et ve ara değerleri hesapla
        while (front != rear) {
            int current = queue[front++];
            for (neighbor = 0; neighbor < numNodes; neighbor++) {
                if (adjacencyMatrix[current][neighbor] != 0) {
                    if (!visited[neighbor]) {
                        queue[rear++] = neighbor;
                        visited[neighbor] = true;
                        distance[neighbor] = distance[current] + 1;
                    }
                    if (distance[neighbor] == distance[current] + 1) {
                        count[neighbor] += count[current];
                    }
                }
            }
        }

        // Her düğüm için kredi değerini 1 olarak ata
        for (i = 0; i < numNodes; i++) {
            credit[i] = 1.0;
        }

        // Her düğüm için BFS sırasında hesaplanan kredi değerlerini topla
        while (--rear >= 0) {
            int current = queue[rear];
            for (neighbor = 0; neighbor < numNodes; neighbor++) {
                if (adjacencyMatrix[current][neighbor] != 0 && distance[neighbor] == distance[current] + 1) {
                    float creditShare = ((float) count[current] / count[neighbor]) * (1 + credit[neighbor]);
                    credit[current] += creditShare;
                    edgeBetweenness[current][neighbor] += creditShare;
                }
            }
        }      
    }

    // Kenar ara değerlerini ikiye böl, pdfte verileen göre normalize et
    for (i = 0; i < numNodes; i++) {
        for (j = i + 1; j < numNodes; j++) {
            edgeBetweenness[i][j] = edgeBetweenness[j][i] = (edgeBetweenness[i][j] + edgeBetweenness[j][i]) / 2.0;
        }
    }
}

/*
@brief -> En yüksek "betweenness" değerine sahip kenarı kaldırır. çünkü bu kenar iki topluluğu birbirine bağlıyor olabilir. 
@param -> adjacencyMatrix[MAX_NODES][MAX_NODES] Komşuluk matrisi
@param -> numNodes Düğüm sayısı
@param -> edgeBetweenness[MAX_NODES][MAX_NODES] Kenarlar arası betweenness değerleri
*/
void removeHighestBetweennessEdge(int adjacencyMatrix[MAX_NODES][MAX_NODES], int numNodes, float edgeBetweenness[MAX_NODES][MAX_NODES]) {
    int maxI = -1, maxJ = -1;
    float maxBetweenness = -1.0;
    int i,j;

    // En yüksek ara değere sahip kenarı bul
    for (i = 0; i < numNodes; i++) {
        for (j = i + 1; j < numNodes; j++) {
            if (adjacencyMatrix[i][j] != 0 && edgeBetweenness[i][j] > maxBetweenness) {
                maxBetweenness = edgeBetweenness[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }

    // Bu kenarı kaldır, yani matriste oraya 0 yaz ve simetrik elemanı da 0 yap
    if (maxI != -1 && maxJ != -1) {
        adjacencyMatrix[maxI][maxJ] = adjacencyMatrix[maxJ][maxI] = 0;
    }
}

/*
@brief -> Bağlı bileşenleri bulur.
@param -> adjacencyMatrix[MAX_NODES][MAX_NODES] Komşuluk matrisi
@param -> numNodes Düğüm sayısı
@param -> component[MAX_NODES] Her düğümün ait olduğu bileşeni gösterir
@return -> Bağlı bileşen sayısını döndürür
*/
int findConnectedComponents(int adjacencyMatrix[MAX_NODES][MAX_NODES], int numNodes, int component[MAX_NODES]) {
    bool visited[MAX_NODES] = {false};
    int numComponents = 0;
    int i, neighbor;

    // Her düğüm için BFS uygula, ziyaret edilmemiş düğüm bulduğunda yeni bir bağlı bileşen bulmuş olursun
    for (i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            int queue[MAX_NODES], front = 0, rear = 0;
            queue[rear++] = i;
            visited[i] = true;
            component[i] = numComponents;

            // BFS uygula
            // BFS sırasında ziyaret edilen düğümleri bağlı bileşen olarak işaretle
            // BFS sırasında ziyaret edilen düğümleri kuyruğa ekle
            // BFS sırasında ziyaret edilen düğümleri ziyaret edildi olarak işaretle
            // daha sonra BFS sırasında ziyaret edilen düğümleri kuyruktan çıkar
            while (front != rear) {
                int current = queue[front++];
                for (neighbor = 0; neighbor < numNodes; neighbor++) {
                    if (adjacencyMatrix[current][neighbor] != 0 && !visited[neighbor]) {
                        queue[rear++] = neighbor;
                        visited[neighbor] = true;
                        component[neighbor] = numComponents;
                    }
                }
            }
            numComponents++;
        }
    }

    return numComponents;
}

/*
@brief  -> Toplulukları ekrana yazdırır.
@param  -> component[MAX_NODES] Her düğümün ait olduğu bileşeni gösterir bu dizi
@param  -> numNodes Düğüm sayısı
*/
void printCommunities(int component[MAX_NODES], int numNodes) {
    int numCommunities = 0;
    int communityId[MAX_NODES];
    int i,j;

    for ( i = 0; i < numNodes; i++) {
        communityId[i] = -1;
    }

    for ( i = 0; i < numNodes; i++) {
        if (communityId[component[i]] == -1) {
            communityId[component[i]] = numCommunities++;
        }
    }

    printf("Number of communities: %d\n", numCommunities);
    for (i = 0; i < numCommunities; i++) {
        printf("Community %d: ", i + 1);
        for (j = 0; j < numNodes; j++) {
            if (communityId[component[j]] == i) {
                printf("%c ", 'A' + j);
            }
        }
        printf("\n");
    }
}

/*
@brief Programın ana fonksiyonudur. dosyadan okuma, k ve t değerlerine göre topluluk sayısı ve bileşen bulma burada yapılır.
@return Programın çıkış durumunu gösterir. 0 ise başarılı, diğer türlü başarısız
*/
int main() {
    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    int numNodes;
    float edgeBetweenness[MAX_NODES][MAX_NODES];
    int component[MAX_NODES];
    int i,j;

    // dosyasını oku ve matrisi doldur
    FILE *inputFile = fopen("input1.txt", "r");
    if (inputFile == NULL) {
        printf("There was an error while opening the file, please control accordingly.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &numNodes);
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            fscanf(inputFile, "%d", &adjacencyMatrix[i][j]);
        }
    }
    fclose(inputFile);

    // Matrisi ekrana yazdır, sadece kontrol için koydum
    printf("Matrix from the file:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    // Kullanıcıdan k ve t değerlerini al
    int k, t;
    printf("Enter k - number of consecutive rounds with no change in the number of communities: ");
    scanf("%d", &k);
    printf("Enter t - minimum number of nodes in a community: ");
    scanf("%d", &t);

    int previousNumCommunities, currentNumCommunities;
    int consecutiveRounds = 0;

    previousNumCommunities = findConnectedComponents(adjacencyMatrix, numNodes, component);
    // Her döngüde kenar ara değerlerini hesapla, en yüksek ara değere sahip kenarı kaldır
    bool loopActive = true;
    while (loopActive) {
        calculateEdgeBetweenness(adjacencyMatrix, numNodes, edgeBetweenness);
        removeHighestBetweennessEdge(adjacencyMatrix, numNodes, edgeBetweenness);
        currentNumCommunities = findConnectedComponents(adjacencyMatrix, numNodes, component);

        // k değerine göre döngüyü sonlandır
        if (previousNumCommunities == currentNumCommunities) {
            consecutiveRounds++;
            if (consecutiveRounds >= k) {
                loopActive = false;
            }
        } else {
            consecutiveRounds = 0;
            previousNumCommunities = currentNumCommunities;
        }

        // Her döngüde toplam düğüm sayısını t kontrolü için kontrol et
        if (loopActive) {
            bool conditionMet = false;
            for (i = 0; i < currentNumCommunities && !conditionMet; i++) {
                int count = 0;
                for (j = 0; j < numNodes; j++) {
                    if (component[j] == i) {
                        count++;
                    }
                }
                if (count <= t) {
                    conditionMet = true;
                }
            }
            if (conditionMet) {
                loopActive = false;
            }
        }
    }
    // Sonuçları ekrana yazdır
    printf("Matrix after community detection:\n");  

    printCommunities(component, numNodes);

    printf("If you want to detect another graph with its communities, run again :) \n");
    return 0;
}
