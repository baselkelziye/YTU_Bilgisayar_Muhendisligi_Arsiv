#include <stdio.h>

#define dizi_size 23

int main() {
    int width, height;
    int i, j;
    int x, y;                      
    int validMove = 0;            
    int tempX, tempY;    
    int pointK = 0, pointS = 0, pointM = 0;    
    char table[dizi_size][dizi_size];
    int game_running = 1;
    int current_turn = 0;
    char currentPlayer;           
    int emptySpaces;
    
    printf("Triversi Oyununa Hoşgeldiniz\n");
    
    do {
        printf("Oyun Tahtası için boyutları giriniz (max %dx%d):\n", dizi_size, dizi_size);
        scanf("%d %d", &height, &width);
        
        if (width > dizi_size || height > dizi_size) {
            printf("Maksimum seçilebilecek değer %d'tür. Tekrar giriniz\n", dizi_size);
        }
    } while (width > dizi_size || height > dizi_size);
    
    // matrix harflendirme 
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            table[i][j] = '.';
        }
    }
    
    table[height/2][width/2] = 'K';
    current_turn = 1;
    
    while (game_running) {
        // tahtayı gösterme
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                printf("%c ", table[i][j]);
            }
            printf("\n");
        }
        
        // sıranın kimde olduğunu belirleme
        if (current_turn % 3 == 0) currentPlayer = 'K';
        else if (current_turn % 3 == 1) currentPlayer = 'S';
        else currentPlayer = 'M';
        
        validMove = 0;            
        
        while (!validMove) {
            printf("%c oyuncusu nereye taş koymak ister? (x y): ", currentPlayer);
            scanf("%d %d", &x, &y);
            
            if (x >= 0 && x < height && y >= 0 && y < width) {
                if (table[x][y] == '.') {
                    if((x < height-1 && table[x+1][y]!= '.') || 
                       (x > 0 && table[x-1][y]!= '.') || 
                       (y < width-1 && table[x][y+1]!= '.') || 
                       (y > 0 && table[x][y-1]!= '.') || 
                       (x < height-1 && y < width-1 && table[x+1][y+1]!= '.') || 
                       (x > 0 && y > 0 && table[x-1][y-1]!= '.') || 
                       (x < height-1 && y > 0 && table[x+1][y-1]!= '.') || 
                       (x > 0 && y < width-1 && table[x-1][y+1]!= '.')) {
                        validMove = 1;
                        table[x][y] = currentPlayer;
                        
                        // Sağ yön kontrolü
                        if (y < width - 2) {
                            tempY = y + 1;    
                            while (tempY < width && table[x][tempY] != '.') {
                                if (table[x][tempY] == currentPlayer) {
                                    for (i = y + 1; i < tempY; i++) {
                                        table[x][i] = currentPlayer;
                                    }
                                }
                                tempY++;
                            }
                        }
                        
                        // Sol yön kontrolü
                        if (y > 1) {
                            tempY = y - 1;    
                            while (tempY >= 0 && table[x][tempY] != '.') {
                                if (table[x][tempY] == currentPlayer) {
                                    for (i = y - 1; i > tempY; i--) {
                                        table[x][i] = currentPlayer;
                                    }
                                }
                                tempY--;
                            }
                        }

                        // Aşağı yön kontrolü
                        if (x < height - 2) {
                            tempX = x + 1;    
                            while (tempX < height && table[tempX][y] != '.') {
                                if (table[tempX][y] == currentPlayer) {
                                    for (i = x + 1; i < tempX; i++) {
                                        table[i][y] = currentPlayer;
                                    }
                                }
                                tempX++;
                            }
                        }
                        
                        // Yukarı yön kontrolü
                        if (x > 1) {
                            tempX = x - 1;    
                            while (tempX >= 0 && table[tempX][y] != '.') {
                                if (table[tempX][y] == currentPlayer) {
                                    for (i = x - 1; i > tempX; i--) {
                                        table[i][y] = currentPlayer;
                                    }
                                }
                                tempX--;
                            }
                        }

                        // Sağ-aşağı çapraz kontrolü
                        if (x < height - 2 && y < width - 2) {
                            tempX = x + 1;
                            tempY = y + 1;
                            while (tempX < height && tempY < width && table[tempX][tempY] != '.') {
                                if (table[tempX][tempY] == currentPlayer) {
                                    i = x + 1;
                                    j = y + 1;
                                    while (i < tempX && j < tempY) {
                                        table[i][j] = currentPlayer;
                                        i++;
                                        j++;
                                    }
                                }
                                tempX++;
                                tempY++;
                            }
                        }
                        
                        // yukarı-sağ çapraz kontrolü
                        if (x > 1 && y < width - 2) {
                            tempX = x - 1;
                            tempY = y + 1;
                            while (tempX >= 0 && tempY < width && table[tempX][tempY] != '.') {
                                if (table[tempX][tempY] == currentPlayer ) {
                                    
                                    i = x - 1;    
                                    j = y + 1;    
                                    while (i > tempX && j < tempY) {
                                        table[i][j] = currentPlayer;
                                        i--;
                                        j++;
                                    }
                                }
                                tempX--;
                                tempY++;
                            }
                        }
                        
                        // aşağı-sağ çapraz kontrolü
                        if (x < height - 2 && y < width - 2) {
                            tempX = x + 1;
                            tempY = y + 1;
                            while (tempX < height && tempY < width && table[tempX][tempY] != '.') {
                                if (table[tempX][tempY] == currentPlayer ) {
                                    i = x + 1;    
                                    j = y + 1;    
                                    while (i < tempX && j < tempY) {
                                        table[i][j] = currentPlayer;
                                        i++;
                                        j++;
                                    }
                                }
                                tempX++;
                                tempY++;
                            }
                        }
                        
                        // yukarı-sol çapraz kontrolü
                        if (x > 1 && y > 1) {
                            tempX = x - 1;
                            tempY = y - 1;
                            while (tempX >= 0 && tempY >= 0 && table[tempX][tempY] != '.') {
                                if (table[tempX][tempY] == currentPlayer ) {
                                    i = x - 1;
                                    j = y - 1;
                                    while (i > tempX && j > tempY) {
                                        table[i][j] = currentPlayer;
                                        i--;
                                        j--;
                                    }
                                }
                                tempX--;
                                tempY--;
                            }
                        }

                        // aşağı-sol çapraz kontrolü
                        if (x < height - 2 && y > 1) {
                            tempX = x + 1;
                            tempY = y - 1;
                            while (tempX < height && tempY >= 0 && table[tempX][tempY] != '.') {
                                if (table[tempX][tempY] == currentPlayer ) {
                                    i = x + 1;
                                    j = y - 1;
                                    while (i < tempX && j > tempY) {
                                        table[i][j] = currentPlayer;
                                        i++;
                                        j--;
                                    }
                                }
                                tempX++;
                                tempY--;
                            }
                        }
                        
                    }
                    else {
                        printf("Geçersiz koordinatlar.\n");
                    }
                }
                else {
                    printf("Geçersiz koordinatlar.\n");   
                }
            }
            else {
                printf("Geçersiz koordinatlar.\n");
            }
        }
        
        // oyun bitişini kontrol etme 
        emptySpaces = 0;
        for (i = 0; i < height; i++) {
            for (j = 0; j < width; j++) {
                if (table[i][j] == '.') {
                    emptySpaces++;
                }
            }
        }
        
        if (emptySpaces == 0) {
            game_running = 0;
        }
        
        current_turn++;
    }
    
    // oyun bitişini gösterme
    printf("\nOyun Bitti! Son durum:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (table[i][j] == 'K') {
                pointK++;
            }
            else if (table[i][j] == 'S') {
                pointS++;
            }
            else if (table[i][j] == 'M') {
                pointM++;
            }
        }
    }
    
    printf("\nSonuçlar:\n");
    printf("K oyuncusu: %d taş\n", pointK);
    printf("S oyuncusu: %d taş\n", pointS);
    printf("M oyuncusu: %d taş\n", pointM);

    if (pointK > pointS && pointK > pointM) {
        printf("K oyuncusu 1. oldu!\n");
        if (pointS > pointM) {
            printf("S oyuncusu 2. oldu!\n");
            printf("M oyuncusu 3. oldu!\n");
        } else if (pointS < pointM) {
            printf("M oyuncusu 2. oldu!\n");
            printf("S oyuncusu 3. oldu!\n");
        } else {
            printf("S ve M oyuncuları 2. oldular!\n");
        }
    } else if (pointS > pointK && pointS > pointM) {
        printf("S oyuncusu 1. oldu!\n");
        if (pointK > pointM) {
            printf("K oyuncusu 2. oldu!\n");
            printf("M oyuncusu 3. oldu!\n");
        } else if (pointK < pointM) {
            printf("M oyuncusu 2. oldu!\n");
            printf("K oyuncusu 3. oldu!\n");
        } else {
            printf("K ve M oyuncuları 2. oldular!\n");
        }
    } else if (pointM > pointK && pointM > pointS) {
        printf("M oyuncusu 1. oldu!\n");
        if (pointK > pointS) {
            printf("K oyuncusu 2. oldu!\n");
            printf("S oyuncusu 3. oldu!\n");
        } else if (pointK < pointS) {
            printf("S oyuncusu 2. oldu!\n");
            printf("K oyuncusu 3. oldu!\n");
        } else {
            printf("K ve S oyuncuları 2. oldular!\n");
        }
    } else if (pointK == pointS && pointS == pointM) {
        printf("Tüm oyuncular berabere!\n");
    } else if (pointK == pointS) {
        printf("K ve S oyuncuları 1. oldular!\n");
        printf("M oyuncusu 2. oldu!\n");
    } else if (pointK == pointM) {
        printf("K ve M oyuncuları 1. oldular!\n");
        printf("S oyuncusu 2. oldu!\n");
    } else if (pointS == pointM) {
        printf("S ve M oyuncuları 1. oldular!\n");
        printf("K oyuncusu 2. oldu!\n");
    }
    
    return 0;
}