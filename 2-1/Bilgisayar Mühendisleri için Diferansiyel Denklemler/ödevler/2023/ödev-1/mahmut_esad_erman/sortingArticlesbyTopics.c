#include <stdio.h>
#include <ctype.h>

#define MAXLENGTH 19150  // the biggest length of an articles (calculated by me using)

int main() {
    FILE *input;
    FILE *business;
    FILE *sport;

    char article[MAXLENGTH];
    int c;
    int i;

    // Reading
    input = fopen("dataset/news/Articles.txt", "r");
    business = fopen("dataset/news/business.txt", "w");
    sport = fopen("dataset/news/sport.txt", "w");

    if (input == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Sorting and omitting non-letter characters
    while ((c = fgetc(input)) != EOF) {
        if(c == '\"'){
            i = 0;
            while ((c = fgetc(input)) != '\"'){
                label:
                if( isalpha( c ))
                    article[i] = c;
                else{
                    article[i] = ' ';
                }
                i++;
            }
            if((c = fgetc(input)) == ','){
                c = fgetc(input);
                if(c == 'b'){
                    article[i] = '\0';
                    fputs(article, business);
                    fputc('\n', business);
                } else if (c == 's'){
                    article[i] = '\0';
                    fputs(article, sport);
                    fputc('\n', sport);
                }else{
                    goto label;
                }
            }
            else{
                goto label;
            }
        }

    }

    fclose(input);
    fclose(business);
    fclose(sport);

    printf("Sorting Completed!");
    return 0;
}
