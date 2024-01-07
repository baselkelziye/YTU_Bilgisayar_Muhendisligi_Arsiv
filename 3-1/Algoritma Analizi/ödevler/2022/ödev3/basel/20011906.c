#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
#define DEBUG_MODE 0
struct hash_entry
{
    char key[100];     // word
    struct node *head; // head pointer for linkedlist
    int isFull;        // flag to check if entry is filled
};

struct node
{
    struct node *next;
    char related_sites[100];
};

int isPrime(int x);                                                      // takes input number and return 1 if its prime
int find_nearest_prime(int x);                                           // takes input and returns the nearest input;
int get_horner_value(char *, int, int);                                  // returns they numerical indice of a string
int start_with(char[]);                                                  // checks if a word starts with https which means its a site
int calculate_table_entrys(FILE *);                                      // calculates how many words there is in the txt file
int insert_to_table(struct hash_entry *, char[], char[], int, int, int); // inserts entry to the hast_table
struct hash_entry create_entry(char[]);                                  // creates and entry for table with empty flag = 0 and null head
struct node *create_node(char[]);                                        // creates a node that will represent the the sites
void insert_from_txt_to_table(FILE *, struct hash_entry *, int, int);    // inserts the keys and values to the table read from txt file
void print_table(struct hash_entry *, int);                              // prints the table and each key's values
void print_linked_list(struct node *);                                   // prints the related sites to a given key
void parse_input(char[], char[3][50]);                                   // parses the inputs
void search_in_table(struct hash_entry *, char[3][50], int);             // tabloda arama yapar
void add_to_list(struct node **, char[50]);                              // linkli listenin basina eleman ekler
int isPresent(struct node *, char[50]);                                  // bir kelimenin linkli listede olup olmadigini arar
struct node *get_union_list(struct node *, struct node *);               // iki linkli listenin UNION islemini yapar (veya durumu)
struct node *get_intersection_list(struct node *, struct node *);        // iki linkli listenin INTERSECTION islemini yapar(ve)
void free_list(struct node *);                                           // vir linkli listeyi temizler
void free_allocated_memory(struct hash_entry *, int);                    // frees the memory allocated for related sites
int main()
{
    printf("\n");

    FILE *fp = fopen("Sample.txt", "r");
    if (fp == NULL)
    {
        printf("\nERROR! File Couldn't be Opened!");
        exit(101);
    }

    int word_numbers = calculate_table_entrys(fp);
    int mod;
    double load_factor;
    printf("\nPlease Enter Load Facor:\n");
    scanf(" %lf", &load_factor);
    int table_length = word_numbers / load_factor;
    int i;
    char searched_words[3][50];
    char find_word[100];

    table_length = find_nearest_prime(table_length);

    struct hash_entry *hash_table = (struct hash_entry *)calloc(table_length, sizeof(struct hash_entry));
    if (hash_table == NULL)
    {
        printf("\nERROR! Memory Could'nt Be Allocated!");
        exit(101);
    }

    for (i = 0; i < table_length; i++)
    {
        hash_table[i] = create_entry("");
    }

    printf("Please Enter The expression you want to search\n");
    fflush(stdin);
    fgets(find_word, 50, stdin);
    find_word[strcspn(find_word, "\n")] = 0; // delete trailing \n from input
    parse_input(find_word, searched_words);
    // AI ve IT
    printf("\nMODE?\n");

    printf("1-Normal Mode\n");
    printf("2-Detailed Mode\n");
    scanf(" %d", &mod);

    if (mod == 1)
    {
        insert_from_txt_to_table(fp, hash_table, table_length, 0);
        search_in_table(hash_table, searched_words, table_length);
    }
    else if (mod == 2)
    {
        printf("\nTablonun Uzunlugu -> %d", table_length);
        insert_from_txt_to_table(fp, hash_table, table_length, 1);
        print_table(hash_table, table_length);
        search_in_table(hash_table, searched_words, table_length);
    }

    // print_table(hash_table, table_length);
    // search_in_table(hash_table, searched_words, table_length);

    fclose(fp);
    free_allocated_memory(hash_table, table_length);
    free(hash_table);
    printf("\n\n");
    return 0;
}

int get_horner_value(char *entry_string, int string_len, int table_len)
{
    int i;
    long long int sum = 0;
    for (i = 0; i < string_len; i++)
    {
        sum = sum + (pow(31, string_len - i)) * (entry_string[i] - 'a' + 1);
    }

    sum = (sum & 0x7fffffff) % table_len; // <--------------

    if (sum < 0)
    {
        sum = sum + table_len;
    }
    return sum;
}

int find_nearest_prime(int x)
{
    int upper_bound = x;
    int lower_bound = x - 1;

    while (!isPrime(upper_bound) && !isPrime(lower_bound))
    {
        upper_bound++;
        lower_bound--;
    }
    if (isPrime(upper_bound))
        return upper_bound;
    else
        return lower_bound;

    return -1;
}

int isPrime(int x)
{
    int i;
    if (x == 2)
    {
        return 1;
    }
    if (x < 2 || x % 2 == 0)
    {
        return 0;
    }
    for (i = 3; i < x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int start_with(char x[])
{
    return strncmp("https://", x, 8) == 0;
}

int calculate_table_entrys(FILE *fp)
{
    int counter = 0;
    char buff[200];

    while (fscanf(fp, "%1023s", buff) == 1)
    {
        if (!start_with(buff))
        {
            counter++;
        }
    }

    return counter;
}

int insert_to_table(struct hash_entry *hash_table, char key[], char site[], int table_len, int string_len, int flag)
{

    int hash_index = (int)get_horner_value(key, string_len, table_len);

    int i = 0;

    while (hash_table[hash_index].isFull && i < table_len && strcmp(hash_table[hash_index].key, key) != 0)
    {
        hash_index = (hash_index + 1) % table_len;
        i++;
    }

    // 1- bos goze denk geldim
    // 2- tabloyu gezdikten yer bulamadik
    // 3-vya o key zaten bulunuyor

    if (i == table_len)
    {
        printf("\nERROR! Table is FULL!");
        return 0;
    }

    else if (strcmp(hash_table[hash_index].key, key) == 0)
    {
        struct node *new_node = create_node(site);

        if (hash_table[hash_index].head == NULL)
        {
            hash_table[hash_index].head = new_node;
        }
        else
        {
            new_node->next = hash_table[hash_index].head;
            hash_table[hash_index].head = new_node;
        }
    }
    else
    {
        struct hash_entry new_entry = create_entry(key);
        new_entry.isFull = 1;
        hash_table[hash_index] = new_entry;
        hash_table[hash_index].head = create_node(site);
        if (flag)
            printf("\n'%s' kelimesi %d. denemede yerlesti!\n", key, i + 1);
    }

    return 1;
}

struct hash_entry create_entry(char key[100])
{
    struct hash_entry new_struct;
    strcpy(new_struct.key, key);
    new_struct.head = NULL;
    new_struct.isFull = 0;
    return new_struct;
}

struct node *create_node(char site_name[])
{
    struct node *new_node = malloc(sizeof(struct node));
    strcpy(new_node->related_sites, site_name);
    new_node->next = NULL;
    return new_node;
}

void insert_from_txt_to_table(FILE *fp, struct hash_entry *hash_table, int table_len, int flag)
{
    FILE *fp1 = fopen("Sample.txt", "r");
    char buff[200];
    char last_site_name[200];
    while (fscanf(fp1, "%1023s", buff) == 1)
    {
        if (start_with(buff))
        {
            strcpy(last_site_name, buff); // save the last site name
        }
        else
        {
            // the site name that these words are lying under is in "last_site_name" variable
            int string_len = strlen(buff);
            if (DEBUG_MODE)
                printf("\nTrying to insert string: %s\nit belongs to site: %s", buff, last_site_name);
            // insert_to_table(hash_table, buff, last_site_name, table_len, string_len);
            insert_to_table(hash_table, buff, last_site_name, table_len, string_len, flag);
        }
    }

    fclose(fp1);
}

void print_table(struct hash_entry *hash_table, int table_len)
{
    int i;
    for (i = 0; i < table_len; i++)
    {
        printf("\n%d. %s", i, hash_table[i].key);
        print_linked_list(hash_table[i].head);
    }
}

void print_linked_list(struct node *head)
{
    struct node *tmp = head;
    while (tmp != NULL)
    {
        printf(" -> %s", tmp->related_sites);
        tmp = tmp->next;
    }
}

void parse_input(char input[50], char parsed_input[3][50])
{
    int i = 0;
    char *token = strtok(input, " ");
    while (token != NULL)
    {
        strcpy(parsed_input[i], token);
        token = strtok(NULL, " ");
        i++;
    }
}

void search_in_table(struct hash_entry *hash_table, char searched_words[3][50], int table_len)
{

    // AI ve IT
    // 0. 1. 2.

    int hash_index = get_horner_value(searched_words[0], strlen(searched_words[0]), table_len);
    int i = 0;
    int hash_index2 = get_horner_value(searched_words[2], strlen(searched_words[2]), table_len);

    if (strcmp(searched_words[1], "ve") == 0 || strcmp(searched_words[1], "veya") == 0)
    {

        while (strcmp(hash_table[hash_index2].key, searched_words[2]) != 0 && i < table_len)
        {
            i++;
            hash_index2 = (hash_index2 + 1) % table_len;
        }
        if (i == table_len)
        {
            printf("ERROR! The Expression you are looking for is not in the table!");
            exit(101);
        }
    }

    i = 0;
    while (strcmp(hash_table[hash_index].key, searched_words[0]) != 0 && i < table_len)
    {
        i++;
        hash_index = (hash_index + 1) % table_len;
    }

    if (i == table_len)
    {
        printf("ERROR! The Expression you are looking for is not in the table!");
        exit(101);
    }

    // if (strcmp(hash_table[hash_index].key, searched_words[0]) == 0)
    // {
    //     printf("\n%s kelimesinin gectigi siteler", searched_words[0]);
    //     print_linked_list(hash_table[hash_index]);
    // }

    if (strcmp(searched_words[1], "ve") != 0 && strcmp(searched_words[1], "veya") != 0)
    {
        printf("%s nin gectigi siteler: ", searched_words[0]);
        print_linked_list(hash_table[hash_index].head);
        // bir kelime ara.
    }
    else if (strcmp(searched_words[1], "veya") == 0)
    {

        struct node *result_head = NULL;
        result_head = get_union_list(hash_table[hash_index].head, hash_table[hash_index2].head);
        printf("%s veya %s \nbu sitelerden geciyor: ", searched_words[0], searched_words[2]);
        print_linked_list(result_head);
        free_list(result_head);
    }

    else if (strcmp(searched_words[1], "ve") == 0)
    {
        struct node *result_head = NULL;
        result_head = get_intersection_list(hash_table[hash_index].head, hash_table[hash_index2].head);
        if (result_head == NULL)
        {
            printf("\n%s ve %s nin birlikte gectikleri site bulunmamaktadir!", searched_words[0], searched_words[2]);
        }
        else
        {
            printf("\n%s ve %s nin birlikte gectikleri siteler:", searched_words[0], searched_words[2]);
            print_linked_list(result_head);
            free_list(result_head);
        }
    }
}

void add_to_list(struct node **head, char kelime[50])
{
    struct node *tmp = create_node(kelime);
    tmp->next = (*head);
    (*head) = tmp;
}

int isPresent(struct node *head, char kelime[50])
{
    struct node *tmp = head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->related_sites, kelime) == 0)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

struct node *get_union_list(struct node *head1, struct node *head2)
{
    struct node *head_result = NULL;
    struct node *t1 = head1;
    struct node *t2 = head2;
    while (t1 != NULL)
    {
        add_to_list(&head_result, t1->related_sites);
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        if (!isPresent(head_result, t2->related_sites))
        {
            add_to_list(&head_result, t2->related_sites);
        }
        t2 = t2->next;
    }

    return head_result;
}

struct node *get_intersection_list(struct node *head1, struct node *head2)
{
    struct node *head_result = NULL;
    struct node *t1 = head1;

    while (t1 != NULL)
    {
        if (isPresent(head2, t1->related_sites))
        {
            add_to_list(&head_result, t1->related_sites);
        }
        t1 = t1->next;
    }
    return head_result;
}

void free_list(struct node *head)
{
    struct node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void free_allocated_memory(struct hash_entry *hash_table, int table_len)
{

    int i;
    for (i = 0; i < table_len; i++)
    {
        free_list(hash_table[i].head);
    }
}
