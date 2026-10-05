#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_LENGTH 100

int main()
{
    srand(time(NULL));
    int n,m; // dimension of matrix table
    int i,j;
    int round, move, flag, check;
    int x1,y1,x2,y2;
    char backup;
    char matrix[MAX_LENGTH][MAX_LENGTH];
    char characters[]={'*', '/', '+', '%', 'O'};
    char the_character;
    int counter_movedChar;
    int counter_explodedChar;
    int right_counter;
    int down_counter;
    int controller;

    do
    {
        printf("N ve M değerlerini giriniz!\n");
        scanf("%d %d", &n, &m);
    } while (n > 20 || m > 20);
    

     for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            matrix[i][j]='.';
        }
    }

   
do
{
    printf("Oynama modu için 1'e tıklayınız!\n");
    printf("Kontrol modu için 2'ye tıklayınız!\n");

    scanf("%d", &round);

    if (round == 1)
    {
        for (i = n / 2; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                matrix[i][j] = characters[rand() % 5];
            }
        }
    }
    else if (round == 2)
    {
        printf("Tabloyu giriniz!\n");

        for (i = n / 2; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf(" %c", &matrix[i][j]);
            }
        }
    }
    else
    {
        printf("Hatalı giriş. Tekrar deneyiniz!\n");
    }

} while (round != 1 && round != 2);
    
flag = 1;
counter_movedChar = 0;
counter_explodedChar = 0;

while (flag != 0)
{
    do
    {
         for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf("%c ",matrix[i][j]);
        }
        printf("\n");
    }

        printf("Toplam yer değiştirme: %d\n",counter_movedChar);
        printf("Toplam skor: %d\n",counter_explodedChar);
        printf("Yer Değişikliği İçin 1'e tıklayınız!\n");
        printf("Patlama İçin 2'ye tıklayınız!\n");
        printf("Oyunu bitirmek için 3'e tıklayınız!\n");
        scanf("%d", &move);

        if (move == 1)
        {
         do
        {
       printf("Yer değiştirilecek ilk elemanın koordinatlarını giriniz:\n");
       scanf("%d %d", &x1, &y1);

      printf("Yer değiştirilecek ikinci elemanın koordinatlarını giriniz:\n");
       scanf("%d %d", &x2, &y2);

       } while (!(x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && x2 >= 1 && x2 <= n && y2 >= 1 && y2 <= m && matrix[x1 - 1][y1 - 1] != '.' && matrix[x2 - 1][y2 - 1] != '.' && ((x1 == x2 && abs(y2 - y1) == 1) || (y1 == y2 && abs(x2 - x1) == 1)))); 

            counter_movedChar++;
            backup = matrix[x1 - 1][y1 - 1];  // swap
            matrix[x1 - 1][y1 - 1] = matrix[x2 - 1][y2 - 1];
            matrix[x2 - 1][y2 - 1] = backup;
            i = 0;

            while (i < n)
            {
                j = 0;
                while (j < m)
                {
                    if (matrix[i][j] != '.')
                    {
                        if (i != 0) // check whether it is at top or no // 
                        {
                            matrix[i-1][j] = matrix[i][j];
                            if (i - 1 == 0)
                            {
                                flag = 0;
                            }
                            
                        }else
                        {
                            printf("oyun bitti!\n");
                            flag = 0;
                        }
                        
                    }
                    j++;
                }
                i++;
            }

            i = n - 1;    // extra bottom line
            for ( j = 0; j < m; j++)
            {
                matrix[i][j] = characters[rand() % 5];
            }
            
            
        }
        else if (move == 2)
        {
            right_counter = 1;
            down_counter = 1;

           do
           {
              printf("Patlatılacak grubun koordinatlarını giriniz:\n");
              scanf("%d %d", &x1, &y1);

            } while ((x1 < 1) || (x1 > n) || (y1 < 1) || (y1 > m) || (matrix[x1 - 1][y1 - 1] == '.'));
            
            the_character = matrix[x1 - 1][y1 - 1];
            check = 1;

            while (y1 - 1 <= (m - 1) && check)
            {
                if (matrix[x1 - 1][y1 + right_counter - 1] == the_character)
                {
                    right_counter++;
                }
                else
                {
                    check = 0;
                }
                
            }
            if (check == 0)
            {
                check = 1;
            }
            
            while (x1 - 1 <= (n - 1) && check)
            {
                if (matrix[x1 + down_counter - 1][y1 - 1] == the_character)
                {
                    down_counter++;
                }else
                {
                    check = 0;
                }
                
            }

            if (right_counter >= down_counter && right_counter >= 3)
            {
                counter_explodedChar += right_counter; 
                controller = 0;

                while (controller < right_counter)
                {
                    for ( i = (x1 - 1); i > 0; i--)
                    {
                        matrix[i][y1 + controller - 1] = matrix[i - 1][y1 + controller - 1];
                    }
                    matrix[0][y1 - 1] = '.';
                    controller++;
                }
                
            }else if(down_counter >= 3)
            {
                counter_explodedChar += down_counter;
                controller = 0;

                while (controller < down_counter)
                {
                    for ( i = (x1 - 1); i > 0; i--)
                    {
                        matrix[i + controller][y1 - 1] = matrix[i + controller - 1][y1 - 1];
                    }
                    matrix[0][y1 - 1] = '.';
                    controller++;
    
                }

            }
            
           
        }

        else if (move == 3)
        {
            printf("oyun bitirildi!\n");
            printf("Toplam yer değiştirme: %d\n",counter_movedChar);
            printf("Toplam skor: %d\n",counter_explodedChar);
                for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf("%c ",matrix[i][j]);
        }
        printf("\n");
    }
            flag = 0;
        }
        else
        {
            printf("Hatalı giriş. Tekrar deneyiniz!\n");
        }

    } while (move != 1 && move != 2 && move != 3 && flag);


}


if (flag == 0 && move != 3)
{
    printf("oyun bitti!\n");
    printf("Toplam yer değiştirme: %d\n",counter_movedChar);
    printf("Toplam skor: %d\n",counter_explodedChar);

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < m; j++)
        {
            printf("%c ",matrix[i][j]);
        }
        printf("\n");
    }
}


    return 0;
}