#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH	50	// max deðiþken adý uzunluðu
#define MAX_VARIABLES 100	// max deðiþken sayýsý
#define NORMAL_MODE 0	
#define DEBUG_MODE 1

// Deðiþkenlerin türlerini temsil eden enum
typedef enum {
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_CHAR
} VarType;

// hash tablosunda her bir giriþi temsil eden struct
typedef struct {
	char name[MAX_NAME_LENGTH];	// deðiþken adý
	VarType type;				// deðiþken tipi
	int is_valid;				// geçerlilik durumu (1: geçerli, 0: geçersiz)
} SymbolTableEntry;

// GLOBAL DEÐÝÞKENLER
SymbolTableEntry* symbol_table; // sembol tablosu
int table_size;					// tablo boyutu
int mode;						// çalýþma modu

unsigned long calculate_hash_key(const char* name);
int h1(unsigned long key, int table_size);
int h2(unsigned long key, int table_size);
int double_hash(unsigned long key, int i, int table_size);
int is_prime(int n);
int determine_table_size(int variable_count);
void initialize_symbol_table(SymbolTableEntry* table, int size);
int insert(SymbolTableEntry* table, int table_size, const char* name, VarType type);
int lookup(SymbolTableEntry* table, int table_size, const char* name);
void print_symbol_table(SymbolTableEntry* table, int table_size, int mode);
void process_input_line(char* line);
void process_file(const char* filename, int mode);

/*
@brief 	Bir string için hash-key hesaplar.
@param  name Hash hesaplanacak string
@return Hash-key döner
*/
unsigned long calculate_hash_key(const char* name) {
	unsigned long key = 0;
	int lenght = strlen(name);
	int i;
	
	for (i = 0; i < lenght; i++){
		key = key * 31 + name[i];
	}
	
	return key;
}

/*
@brief   Ýlk hash fonksiyonu.
@param   key Hash-key.
@param   table_size Tablo boyutu.
@return  Ýlk hash'in sonucu.
*/
int h1(unsigned long key, int table_size) {
	return key % table_size;
}

/*
@brief   Ýkinci hash fonksiyonu.
@param   key Hash-key.
@param   table_size Tablo boyutu.
@return  Ýkinci hash'in sonucu.
*/
int h2(unsigned long key, int table_size) {
	return 1 + (key % (table_size - 3));
}

/*
@brief   Double hashing algoritmasý ile index hesaplar.
@param   key Hash-key.
@param   i Çakýþma çözümü için deneme sayýsý.
@param   table_size Tablo boyutu.
@return  Hesaplanan tablo indexi.
*/
int double_hash(unsigned long key, int i, int table_size) {
	return (h1(key, table_size) + i * h2(key, table_size)) % table_size;
}

/*
@brief   Bir sayýnýn asal olup olmadýðýný kontrol eder.
@param   n Kontrol edilecek sayý.
@return  Asal ise 1, deðilse 0 döndürür.
*/
int is_prime(int n){
	int i;
	
	if (n <= 1) return 0;
	
	for (i = 2; i * i <= n; i++){
		if (n % i == 0) return 0;
	}
	
	return 1;
}

/*
@brief   Hash tablosu için uygun boyutu belirler.
@param   variable_count Deðiþken sayýsý.
@return  Belirlenen tablo boyutu.
*/
int determine_table_size(int variable_count) {
	int size = variable_count * 2;
	
	while (!is_prime(size)) {
		size++;
	}
	
	return size;
}

/*
@brief   Hash tablosunu baþlatýr.
@param   table Hash tablosu.
@param   size Tablo boyutu.
*/
void initialize_symbol_table(SymbolTableEntry* table, int size) {
	int i;
	
	for (i = 0; i < size; i++){
		table[i].is_valid = 0;
	}
}


/*
@brief   Hash tablosuna yeni bir giriþ ekler.
@param   table Hash tablosu.
@param   table_size Tablo boyutu.
@param   name Eklenmek istenen deðiþkenin adý.
@param   type Deðiþken tipi.
@return  Baþarýlý ekleme için index, hata için -1 döndürür.
*/
int insert(SymbolTableEntry* table, int table_size, const char* name, VarType type) {
	unsigned long key = calculate_hash_key(name);
	int i, index;
	
	for (i = 0; i < table_size; i++){
		index = double_hash(key, i, table_size);
		
		if (!table[index].is_valid) {
			strcpy(table[index].name, name);
			table[index].type = type;
			table[index].is_valid = 1;
			
			if (mode == DEBUG_MODE) {
				printf("Inserting %s at index %d (first hash: %d)\n", name, index, h1(key, table_size));
			}
		
			return index;
		}
		
		if (strcmp(table[index].name, name) == 0) {
			printf("Error: Variable %s already declared\n", name);
			return -1;
		}
	}
	
	printf("ERROR: Symbol table is full!\n");
	return -1;
}


/*
@brief   Hash tablosunda bir deðiþken arar.
@param   table Sembol tablosu.
@param   table_size Tablo boyutu.
@param   name Aranacak deðiþkenin adý.
@return  Bulunan index, bulunamazsa -1 döndürür.
*/
int lookup(SymbolTableEntry* table, int table_size, const char* name) {
	unsigned long key = calculate_hash_key(name);
	int i, index;
	
	for (i = 0; i < table_size; i++){
		index = double_hash(key, i, table_size);
		
		if (!table[index].is_valid) {
			return -1;
		}
		
		if (strcmp(table[index].name, name) == 0) {
			return index;
		}
	}
	
	return -1;
}

/*
@brief   Hash tablosunu ekrana yazdýrýr.
@param   table Hash tablosu.
@param   table_size Tablo boyutu.
@param   mode Çalýþma modu.
*/
void print_symbol_table(SymbolTableEntry* table, int table_size, int mode) {
	if (mode == DEBUG_MODE) {
		printf("\nSymbol Table Contents:\n");
		printf("Table Size: %d\n", table_size);
		int i;
		
		for (i = 0; i < table_size; i++){
			if (table[i].is_valid) {
				printf("Index %d: Name=%s, Type=%d\n", i, table[i].name, table[i].type);
			}
		}
	}
}

/*
@brief   Bir satýrý iþleyerek deðiþkenleri sembol tablosuna ekler.
@param   line Ýþlenecek satýr.
*/
void process_input_line(char* line) {
    char* token;
    VarType type;
    
    while (*line && (*line == ' ' || *line == '\t')) line++;
    
    if (strstr(line, "int ")) {
        type = TYPE_INT;
        token = strstr(line, "int ") + 4;
    } else if (strstr(line, "float ")) {
        type = TYPE_FLOAT;
        token = strstr(line, "float ") + 6;
    } else if (strstr(line, "char ")) {
        type = TYPE_CHAR;
        token = strstr(line, "char ") + 5;
    } else {
        return; 
    }
    
    token = strtok(token, " ,;");
    while (token) {

        if (token[0] == '_') {

            char* space = strchr(token, '=');
            if (space) *space = '\0';
            
 
            insert(symbol_table, table_size, token, type);
        }
        
        token = strtok(NULL, " ,;");
    }
}


/*
@brief   Bir dosyayý okuyup hash tablosunu oluþturur.
@param   filename Dosya adý.
@param   mode Çalýþma modu.
*/
void process_file(const char* filename, int mode) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    int variable_count = 0;
    char line[200];

    // First pass: deklere edilen deðiþken sayýsýný say
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "int ") || 
            strstr(line, "float ") || 
            strstr(line, "char ")) {
            variable_count++;
        }
    }

    // Reset dosya pointer
    rewind(file);

    // tablo büyüklüðünü belirle
    table_size = determine_table_size(variable_count);

    // Allocate symbol table
    symbol_table = malloc(table_size * sizeof(SymbolTableEntry));
    initialize_symbol_table(symbol_table, table_size);

    while (fgets(line, sizeof(line), file)) {
        process_input_line(line);
    }

	// Reset dosya pointer
    rewind(file);

    // kullanýlmýþlýk kontrolü
    while (fgets(line, sizeof(line), file)) {
        char* token = strtok(line, " \t,;=()+-*/");

        while (token) {
            if (token[0] == '_' && token[1] != '\0') {
                // deðiþken önceden deklere edilmiþ mi kontrol et
                if (lookup(symbol_table, table_size, token) == -1) {
                    printf("Error: Variable %s is undeclared\n", token);
                }
            }
            // sonraki token'a geç
            token = strtok(NULL, " \t,;=()+-*/");
        }
    }

    // DEBUG modu için hash tablosunu printle
    print_symbol_table(symbol_table, table_size, mode);


    fclose(file);
    free(symbol_table);
}


/*
@brief Programýn giriþ noktasý. Sembol tablosu iþlemlerini yönetir.
@param argc Komut satýrý argüman sayýsý.
@param argv Komut satýrý argümanlarý.
@return Çýkýþ kodu.
*/
int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <mode>\n", argv[0]);
        printf("Mode can be NORMAL or DEBUG\n");
        return 1;
    }
    

    mode = (strcmp(argv[2], "DEBUG") == 0) ? DEBUG_MODE : NORMAL_MODE;
    
    // Process dosya
    process_file(argv[1], mode);
    
    return 0;
}

























































