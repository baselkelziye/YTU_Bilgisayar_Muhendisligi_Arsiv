#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define R 31
#define a 97

typedef struct link_node
{
    char url[255];
    struct link_node *next;
} link_node;

typedef struct hash_node
{
    char word[255];
    struct link_node *links;

} hash_node;

unsigned int hash_index(char *key, int size)
{
    int len = strlen(key);
    int i;
    unsigned int key_value = 0;
    for (i = len - 1; i >= 0; i--)
    {
        key_value += pow(R, i) * key[i] - a + 1;
    }
    return key_value % size;
}

void print(hash_node *hash_table[], int size)
{
    printf("\nHash Table\n---------------------\n");
    int i;
    for (i = 0; i < size; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("%d\t___\n", i);
        }
        else
        {
            printf("%d\t%s\n", i, hash_table[i]->word);
        }
    }
}

int insert(char word[], char url[], hash_node *hash_table[], int size, int *count)
{
    int i;
    int index = hash_index(word, size);

    for (i = 0; i < size; i++)
    {
        int new_i = (i + index) % size;
        if (hash_table[new_i] == NULL)
        {
            struct hash_node *new_hash_node = malloc(sizeof(struct hash_node));
            strcpy(new_hash_node->word, word);
            struct link_node *new_link_node = malloc(sizeof(struct link_node));
            strcpy(new_link_node->url, url);
            new_hash_node->links = new_link_node;
            new_link_node->next = NULL;

            new_hash_node->links->next = NULL;
            hash_table[new_i] = new_hash_node;
            *count += 1;
            return i;
        }
        else if (strcmp(hash_table[new_i]->word, word) == 0)
        {
            struct link_node *new_link_node = malloc(sizeof(struct link_node));
            strcpy(new_link_node->url, url);
            link_node *tmp = hash_table[new_i]->links;

            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = new_link_node;
            new_link_node->next = NULL;

            new_link_node->next = NULL;
            return 0;
        }
    }

    return -1;
}

hash_node *find(char *word, hash_node *hash_table[], int size)
{
    int i;
    int index = hash_index(word, size);
    for (i = 0; i < size; i++)
    {
        int new_i = (index + i) % size;
        if (hash_table[new_i] != NULL && strcmp(hash_table[new_i]->word, word) == 0)
        {
            return hash_table[new_i];
        }
    }
    return NULL;
}

void search(hash_node *hash_table[], int size)
{
    char word_s[255];
    char w1[255];
    char w2[255];
    int s_mode = 0;

    printf("\nKelime: ");
    gets(word_s);
    gets(word_s);
    strlwr(word_s);
    if (strstr(word_s, "veya"))
    {
        sscanf(word_s, "%s veya %s", w1, w2);
        s_mode = 2;
    }
    else if (strstr(word_s, "ve"))
    {
        sscanf(word_s, "%s ve %s", w1, w2);
        s_mode = 1;
    }
    else
    {
        strcpy(w1, word_s);
        s_mode = 0;
    }
    if (s_mode == 0)
    {
        hash_node *find_word = find(w1, hash_table, size);
        if (find_word != NULL)
        {
            link_node *tmp = find_word->links;
            printf("\nResults for %s:\n", find_word->word);
            while (tmp != NULL)
            {
                printf("-%s", tmp->url);
                tmp = tmp->next;
            }
        }
        else
        {
            printf("Not found!\n");
        }
    }
    else if (s_mode == 1)
    {
        hash_node *find_word1 = find(w1, hash_table, size);
        hash_node *find_word2 = find(w2, hash_table, size);
        if (find_word1 == NULL || find_word2 == NULL)
        {
            printf("Not found!\n");
        }
        else
        {
            printf("\nResults for %s:\n", word_s);
            int i = 0, j = 0;
            link_node *tmp1 = find_word1->links;
            link_node *tmp2 = find_word2->links;
            link_node *tmp3;
            while (tmp1 != NULL)
            {
                tmp3 = tmp2;
                while (tmp3 != NULL)
                {
                    if (strcmp(tmp1->url, tmp3->url) == 0)
                    {
                        printf("-%s", tmp1->url);
                    }
                    tmp3 = tmp3->next;
                }
                tmp1 = tmp1->next;
            }
        }
    }
    else
    {
        hash_node *find_word1 = find(w1, hash_table, size);
        hash_node *find_word2 = find(w2, hash_table, size);
        if (find_word1 == NULL && find_word2 == NULL)
        {
            printf("Not found!\n");
        }
        else
        {
            printf("\nResults for %s:\n", word_s);
            if (find_word1 == NULL)
            {
                link_node *tmp = find_word2->links;
                while (tmp != NULL)
                {
                    printf("-%s", tmp->url);
                    tmp = tmp->next;
                }
            }
            else if (find_word2 == NULL)
            {
                link_node *tmp = find_word1->links;
                while (tmp != NULL)
                {
                    printf("-%s", tmp->url);
                    tmp = tmp->next;
                }
            }
            else
            {
                link_node *tmp1 = find_word1->links;
                link_node *tmp2 = find_word2->links;
                link_node *tmp3;
                // link_node *tmp4;
                tmp3 = tmp1;
                while (tmp3 != NULL)
                {
                    printf("-%s", tmp3->url);
                    tmp3 = tmp3->next;
                }
                while (tmp2 != NULL)
                {
                    int printed = 0;
                    tmp3 = tmp1;
                    while (tmp3 != NULL)
                    {
                        if (strcmp(tmp2->url, tmp3->url) == 0)
                        {
                            printed = 1;
                        }
                        tmp3 = tmp3->next;
                    }
                    if (printed == 0)
                    {
                        printf("-%s", tmp2->url);
                    }
                    tmp2 = tmp2->next;
                }
            }
        }
    }
}

int prime(int n)
{
    int i, c = 0;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            c++;
        }
    }
    if (c == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char filename[100] = "arama.txt";
    int i, def_size = 100;
    float load;
    int count = 0;
    int again = 1;

    // farkli olan kelimleri bulmak icin gecisi bir hash table olusturuldu.
    // daha sonra hesaplanan size'a gore asil kullanilacak hash table olusturulacak.
    hash_node *hash_table[def_size];
    for (i = 0; i < def_size; i++)
    {
        hash_table[i] = NULL;
    }

    FILE *file;

    char line[255];
    char url[255];
    char *word;

    printf("Load Factor: ");
    scanf("%f", &load);

    int try, mode;
    printf("1-NORMAL\n2-DETAIL\nMode: ");
    scanf("%d", &mode);
    file = fopen(filename, "r");

    // asagidaki while dongusu ile unique kelime sayisi bulunur
    while (fgets(line, 255, file))
    {
        strcpy(url, line);
        fgets(line, 255, file);
        fgets(line, 255, file);
        strtok(line, "\n");
        word = strtok(line, " ");
        int i = 1;
        while (word)
        {
            strlwr(word);
            try = insert(word, url, hash_table, def_size, &count);
            word = strtok(NULL, " ");
        }
        fgets(line, 255, file);
    }
    fclose(file);
    for (i = 0; i < def_size; i++)
    {
        free(hash_table[i]);
    }

    int size = floor(count / load);
    int ext = 0;
    while (ext != 1)
    {
        size += 1;
        if (prime(size) == 1)
        {
            ext = 1;
        }
    }
    int real_count = count;
    printf("\nUnique words: %d\n", count);
    printf("Size: %d\n", size);
    hash_node *hash_table_main[size];

    for (i = 0; i < size; i++)
    {
        hash_table_main[i] = NULL;
    }

    if (mode == 2)
    {
        file = fopen(filename, "r");
        printf("\nRecords:\nTry\t\tWord\t\tLink\n-----------------------------------------------------------\n");
        while (fgets(line, 255, file))
        {
            strcpy(url, line);
            fgets(line, 255, file);
            fgets(line, 255, file);
            strtok(line, "\n");
            word = strtok(line, " ");
            int i = 1;
            while (word)
            {
                strlwr(word);
                try = insert(word, url, hash_table_main, size, &count);
                printf("%d\t\t%s\t%s", try, word, url);
                word = strtok(NULL, " ");
            }
            fgets(line, 255, file);
        }
        printf("(0 -> Hash index, -1 -> No space)\n");
        print(hash_table_main, size);
        fclose(file);
    }
    else
    {
        file = fopen(filename, "r");
        while (fgets(line, 255, file))
        {
            strcpy(url, line);
            fgets(line, 255, file);
            fgets(line, 255, file);
            strtok(line, "\n");
            word = strtok(line, " ");
            int i = 1;
            while (word)
            {
                strlwr(word);
                try = insert(word, url, hash_table_main, size, &count);
                word = strtok(NULL, " ");
            }
            fgets(line, 255, file);
        }
        fclose(file);
    }

    while (again == 1)
    {
        search(hash_table_main, size);
        printf("\nAgain? (1-Yes 2-No): ");
        scanf("%d", &again);
    }
    for (i = 0; i < size; i++)
    {
        free(hash_table_main[i]);
    }
    return 1;
}
