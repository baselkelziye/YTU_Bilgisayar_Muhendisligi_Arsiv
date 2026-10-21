#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Define the Hash Table Item here
struct item {
    char* key;
    char* value;
};
typedef struct item Item;


// Define the Hash Table here
struct hashTable {
    // Contains an array of pointers
    // to items
    Item** items;
    int size;
    int count;
};typedef struct hashTable hashTable;


/**
 * @brief Create a item object
 * 
 * @param key 
 * @param value 
 * @return Item* 
 */
Item* create_item(char* key, char* value) {
    // Creates a pointer to a new hash table item
    Item* item = (Item*) malloc (sizeof(Item));
    item->key = (char*) malloc (strlen(key) + 1);
    item->value = (char*) malloc (strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}


/**
 * @brief Free item's attributes
 * 
 * @param item 
 */
void free_item(Item* item) {
    // Frees an item
    free(item->key);
    free(item->value);
    free(item);
}

/**
 * @brief Free table from the memory
 * 
 * @param table 
 */
void free_table(hashTable* table) {
    // Frees the table
    int i;
    for (i=0; i<table->size; i++) {
        Item* item = table->items[i];
        if (item != NULL)
            free_item(item);
    }
    free(table->items);
    free(table);
}


/**
 * @brief Horner's method as a hash function to determine index of given string
 * 
 * @param str 
 * @return int 
 */
int hash_function(char *str, hashTable *table){
    int hashValue = 0, i;
    for (i = 0; i < strlen(str); i++)
        hashValue = ((31 * hashValue) + str[i]) % table->size;
    return hashValue;         // take the final result mod m
}


/**
 * @brief Create a table object
 * 
 * @param size 
 * @return hashTable* 
 */
hashTable* create_table(int size) {
    // Creates a new hashTable
    int i;
    hashTable* table = (hashTable*)malloc(sizeof(hashTable));
    table->size = size;
    table->count = 0;
    table->items = (Item**)calloc(table->size, sizeof(Item*));
    for (i=0; i<table->size; i++)
        table->items[i] = NULL;

    return table;
}


/**
 * @brief We handle with the collision by using linear probing
 * 
 * @param table 
 * @param index 
 * @param item 
 * @param key 
 * @param mode 
 */
void handle_collision(hashTable* table, unsigned long index, Item* item, char* key, int mode) {

    // Compute the index again
    unsigned long i = index;
    int flag = 0, detail_counter = 1;
    //printf("\ni: %lu\n", i); For error tracing
    /* probing through the array until we reach an empty space */
    while (flag == 0){
	    i = (i + 1) % table->size;
        if (table->count == table->size){
		    printf("\n Hash table is full, cannot insert any more item \n");
            return;
        }
        else if (table->items[i] == NULL){
                // Insert item
                table->items[i] = item; 
                table->count++;
                flag = 1;
        }
        //printf("\ni: %lu\n", i);
        detail_counter++;
    }
    if (mode == 2){
            printf("\nCurrent key [%s] is settled in %d. attempt\n", table->items[i]->key, detail_counter);
        }
}


/**
 * @brief Split input into tokens to be able to
 *        understand delimiter (and, or, nothing)
 * 
 *        Also helps us to tokenize string of keywords
 *        
 * 
 * @param inputString 
 * @param delim 
 * @param argv 
 * @param maxtokens 
 * @return size_t 
 */
size_t tokenize(char *inputString, const char *delim, char **argv, size_t maxtokens) 
{
    size_t ntokens = 0;
    char *tokenized = strdup(inputString);
    if(tokenized){
        argv[0] = tokenized;
        while(*tokenized){
            if(strchr(delim, *tokenized)){
                *tokenized = 0;
                ntokens++;
                if(ntokens == maxtokens - 1)
                    break;
                
                argv[ntokens] = tokenized + 1;
            }
            tokenized++;
        }
    }
    return ntokens + 1;
}



/**
 * @brief insert function for adding new key-value item to the hash table
 * 
 * @param table 
 * @param key 
 * @param value 
 * @param mode 
 */
void insert(hashTable* table, char* key, char* value, int mode) {
    
    char* tokens[48];
    int i;
    for(i = 0; i<47; i++){ //clean old token
        tokens[i+1] = NULL;
    }
    size_t ntokens = 1;
 
    if(strstr(key, " ") != NULL){
        ntokens = tokenize(key, " ", tokens , 48);
    }
    else
        strcpy(tokens[0], key);
    
    i = 0;
    while(i < ntokens){
        // Create the item
        if(strstr(tokens[i], "\n") != NULL){
            size_t length = strlen(tokens[i]);
            tokens[i][length-1] ='\0';
        }
                
        Item* item = create_item(tokens[i], value);

        // Compute the index
        unsigned long index = hash_function(tokens[i], table);
        //printf("\nindex: %lu\n", index);

        Item* current_item = table->items[index];

        if (current_item == NULL) {

            // Key does not exist.
            if (table->count == table->size) {
                // Hash Table Full
                printf("Insert Error: Hash Table is full\n");
                // Remove the create item
                free_item(item);
                return;
            }
            
            // Insert directly
            table->items[index] = item; 
            table->count++;
            if (mode == 2){
                printf("\nCurrent key [%s] is settled in first attempt\n", table->items[index]->key);
            }
        }
        else {
            // Handle collision by using linear probing
            handle_collision(table, index, item, tokens[i], mode);
        }
        i++; // next key
    }
    
}



/**
 * @brief This function access the sites that related with
 *        the given keywords
 * 
 * @param table 
 * @param key 
 */
void print_search(hashTable* table, char* key) {
    // Searches the key in the hashTable
    // and returns NULL if it doesn't exist
    Item* current_item;
    int j, not_found = 0, index, index_;
    char* tokens[32];
    tokens[1] = NULL;
    char *available_sites[32];


    if(strstr(key, " ") != NULL){
        size_t ntokens = tokenize(key, " ", tokens , 32);
    }
    else{
        index = hash_function(key, table);
        printf("\n Available websites\n-------------------\n");
        while(table->items[index] != NULL){
            if (strcmp(table->items[index]->key, key) == 0){
                printf("%s", table->items[index]->value);
                not_found = 1;
            }
            index++;
            if(index == table->size)
                index= index % table->size;
        }
    }
    
    if (tokens[1] != NULL && strcmp(tokens[1], "and") == 0 ){

        printf("\n Available websites\n-------------------\n");

        index = hash_function(tokens[0], table);        
        while(table->items[index] != NULL){
            index_ = hash_function(tokens[2], table);
            while(table->items[index_] != NULL){
                if(strcmp(table->items[index]->key, tokens[0]) == 0 && strcmp(table->items[index_]->key, tokens[2]) == 0 && index != index_){
                    if(strcmp(table->items[index]->value, table->items[index_]->value) == 0){
                        printf("%s", table->items[index_]->value);
                        not_found = 1;
                    }
                }
                index_++;
                if(index_ == table->size)
                    index_= index_ % table->size;
            } 
            index++;
            if(index == table->size)
                index= index % table->size;
        }
    }
    else if (tokens[1] != NULL && strcmp(tokens[1], "or") == 0){
        
        printf("\n Available websites\n-------------------\n");


        int flag = 0;
        index = hash_function(tokens[0], table);        
        while(table->items[index] != NULL){
            index_ = hash_function(tokens[2], table);
            //printf("\nindex: %d %s %s- index_: %d %s %s, flag=%d\n", index, table->items[index]->key, tokens[0], index_, table->items[index_]->key, tokens[2], flag);
            if((strcmp(table->items[index]->key, tokens[0]) == 0)){
                while(table->items[index_] != NULL && flag == 0){
                    if((strcmp(table->items[index_]->key, tokens[2]) == 0)){
                        //printf("\nICERDEMA: index: %d %s %s - index_: %d %s %s, flag=%d\n", index, table->items[index]->key, tokens[0], index_, table->items[index_]->key, tokens[2], flag);
                        if(strcmp(table->items[index]->value, table->items[index_]->value) == 0 && index != index_){
                            flag=1;
                            not_found = 1;
                            //printf("\nindexValue: %s - index_Value %s\n", table->items[index]->value, table->items[index_]->value);
                            //printf("\nindex: %d - index_: %d\n", index, index_);
                            break;
                        }
                    }
                index_++;
                if(index_ == table->size)
                    index_= index_ % table->size;
                }
            //printf("\nindex: %d - index_: %d, flag=%d\n", index, index_, flag);
            
            if(flag == 0 && index != index_)
                printf("%s", table->items[index]->value);
            
            flag = 0;
            }
            
            index++;
            if(index == table->size)
                index = index % table->size;
        }


        index_ = hash_function(tokens[2], table);
        while(table->items[index_] != NULL){
            if(strcmp(table->items[index_]->key, tokens[2]) == 0){
                printf("%s", table->items[index_]->value);
                not_found = 1;
            }
            index_++;
            if(index_ == table->size)
                index_ = index_ % table->size;
        }
        
    }

    if (not_found == 0)
        printf("This keyword does not exist.");
    else
        printf("-------------------\n");

}


/**
 * @brief Display every key-value pair in the hash table
 * 
 * @param table 
 */
void print_table(hashTable* table) {
    int i;
    printf("\n\n\nHash Table\n-------------------\n");
    for (i=0; i<table->size; i++) {
        if (table->items[i] != NULL) {
            printf("Index:%d --: Key: %s  ~  Value: %s\n", i, table->items[i]->key, table->items[i]->value);
        }
    }
    printf("-------------------\n\n");
}


int checkPrime(int n){
    int i;
    if (n == 1 || n == 0)
        return 0;
  
    for (i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            return 0;
     
    return 1;
}

int getPrime(int n){
    if (n % 2 == 0)
        n++;

    while (!checkPrime(n))
        n += 2;
  
    return n;
}


/**
 * @brief Counts how many keys we have in the file to be able to
 *        determine size of the hash table
 *        
 * @return int 
 */
int count_key(char* filename){
    FILE *fp;
    int count = 0;  // Line counter (result)
    char c;  // To store a character read from file
 
    // Open the file
    fp = fopen(filename, "r");
 
    // Check if file exists
    if (fp == NULL){
        printf("Could not open file %s", filename);
        return 0;
    }
 
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
 
    // Close the file
    fclose(fp);
    return count;
}



int main() {

    char filename[255];
    // Get file name from user. The file should be
    // either in current folder or complete path should be provided
    printf("Enter file name: ");
    scanf("%s", filename);

    int i=0, j=0, key_count=0, hash_size, input_count = count_key(filename)/2;
    float load_factor;
    char buffer[128], keys[128][128], values[128][128]; 

    
    printf("Enter the load factor: ");
    scanf("%f", &load_factor);


    char *temp1[128];
    /*************** READ FROM FILE ***************/
    int binary_line = 0;
    FILE *fp = fopen(filename, "r");
    while (fgets(buffer, 128, fp)){
        if(binary_line % 2 == 0){
            strcpy(values[i], buffer);
            i++;
        }        
        else{
            strcpy(keys[j], buffer);
            if(strstr(buffer, " ") != NULL){
                key_count += tokenize(buffer, " ", temp1 , 48);
            }
            else key_count++;
            
            j++;
        }
    binary_line++;
    }
    fclose(fp);
    /*************** READ FROM FILE ***************/

    hash_size = getPrime(key_count);
    int new_size;
    if(load_factor > (float)(key_count/hash_size)){
        new_size = (int)(hash_size * (1/load_factor));
        hash_size = getPrime(new_size);
    }

    hashTable *ht = create_table(hash_size);


    int mode;
    char word[32], tmp[1];
   
    printf("\n  Choose mode:  \n1) Normal Mode\n2) Detailed Mode\nChoice: ");
    scanf("%d", &mode);
    scanf("%c", tmp); //escape for enter char
    switch (mode)
    {
    case 1:
        for(i=0; i<input_count; i++)
            insert(ht, keys[i], values[i], mode);
            
        printf("Ask for some keywords... ");
        scanf("%[^'\n']s", word);
        print_search(ht, word);
        break;

    case 2:
        printf("\n\n\n DETAILED INFORMATION\n-------------------\n\
        Length of hash table: %d\n", hash_size);
        
        for(i=0; i<input_count; i++){
            insert(ht, keys[i], values[i], mode);
        }

        print_table(ht);
        printf("Ask for some keywords... ");
        scanf("%[^'\n']s", word);
        print_search(ht, word);
        break;
    
    default:
        printf("Not available choice.");
        break;
    }
    free_table(ht);
    return 0;
}








