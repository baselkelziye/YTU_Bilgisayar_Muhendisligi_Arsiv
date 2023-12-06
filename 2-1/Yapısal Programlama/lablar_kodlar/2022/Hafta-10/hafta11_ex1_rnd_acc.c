/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta11_codes
cc -o test hafta11_ex1_rnd_acc.c 
./test records.dat
*/
#include <stdio.h>
#include <stddef.h> 
#include <stdlib.h> // Header file for qsort() 
#include <string.h> // for the strcmp function() 

#define MAX_REC_NUM 1000
#define NAME_LEN 19
typedef struct { 	unsigned int day : 5;
 	unsigned int month : 4;
 	unsigned int year : 11;
} DATE;
typedef struct {   char ps_name[NAME_LEN], ps_tcno[11];   DATE ps_birth_date;} PERSONALSTAT;

// structure definition for the index files for our records:
typedef struct {
   int index;
   char key[NAME_LEN];
} INDEX;

/* Reads up to max_rec_num records from a file and stores the key field of each record in an index array. Returns the number of key fields stored. */

int get_records(FILE* data_file, INDEX names_index[], int max_rec_num){
   int offset = 0, counter = 0, k, nm = NAME_LEN;
   char namei[NAME_LEN]; 

   // get only the name of the 1st PERSON: (the first 19 chars is for name field)
   nm=fread(namei, 1, NAME_LEN, data_file);
   for (k = 0; counter < max_rec_num && nm== NAME_LEN; k++){
      strcpy(names_index[k].key, namei); 
      // jump into the beginning of the next person's (next record's) starting point:
      offset += sizeof(PERSONALSTAT);
      fseek(data_file, offset, SEEK_SET);
      counter++;
      // get only the name of the i-th PERSON: (the first 19 chars for each person/record)
      nm=fread(namei, 1, NAME_LEN, data_file);
   } 
   return counter;
}

/* Sort an array of NAMES_INDEX structures by the name field. There are index count elements to be sorted. Returns a pointer to the sorted array. */

int compare_func(INDEX *p, INDEX *q ){
   return strcmp( p->key, q->key);

/* <0: the first character that does not match has a lower value in ptr1 than in ptr2
   0:  the contents of both strings are equal
   >0: the first character that does not match has a greater value in ptr1 than in ptr2
*/
}

void sort_index(INDEX names_index[], int index_count) {
   int j;
   // Assign values to the index field of each structure:
   for (j = 0; j < index_count; j++) 
      names_index[j].index = j;
   qsort(names_index, index_count, sizeof(INDEX), compare_func);
}

/* Print the records in a file in the order * indicated by the index array. */
void print_indexed_records(FILE * data_file, INDEX index[], int index_count ){
  PERSONALSTAT ps;
  int j;
  for (j = 0; j < index_count; j++){
    if (fseek( data_file, sizeof(PERSONALSTAT) * index[j].index, SEEK_SET))
      exit( 1 );
    fread(&ps, 1, sizeof(PERSONALSTAT), data_file);
    printf( "%20s, %u, %u, %u, %12s\n", ps.ps_name, ps.ps_birth_date.day, 
		ps.ps_birth_date.month, ps.ps_birth_date.year, ps. ps_tcno);
  }
}

// To make this program complete, we need a main() function that calls these other functions. We have written main() so the filename can be passed as an argument.int main(int argc, char *argv[]){
  FILE *data_file, *index_file;
  static INDEX index[MAX_REC_NUM];
  int num_recs_read;
  char *filename; 

  if (argc < 2) {
    printf( "Error: must enter index filename\n" ); printf( "Filename: " );
    filename=malloc(60);   scanf( "%s", filename );
  }
  else
    filename = argv[1];
  
  if ((data_file = fopen( filename, "rb" )) == NULL){ 
    printf( "Error opening file %s.\n", filename);
    exit(1);
  }

  num_recs_read = get_records(data_file, index, MAX_REC_NUM ) ;
  printf("num_recs_read: %d\n", num_recs_read);


  sort_index(index, num_recs_read); 

  printf("After the sorting\n");
  print_indexed_records (data_file, index, num_recs_read);

  fclose(data_file);
  return 0;
}
