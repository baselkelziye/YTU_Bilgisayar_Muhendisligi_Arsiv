#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

// Function to print a matrix stored in a 1D array
void print_matrix(unsigned* matrix, unsigned rows, unsigned cols, FILE* file);
// Function to read matrix from a file
void read_matrix(const char* filename, unsigned** matrix, unsigned* rows, unsigned* cols);
// Function to read kernel from a file
void read_kernel(const char* filename, unsigned** kernel, unsigned* k);
// Function to write output matrix to a file
void write_output(const char* filename, unsigned* output, unsigned rows, unsigned cols);
// Initialize output as zeros.
void initialize_output(unsigned*, unsigned, unsigned);

int main() {

    unsigned n, m, k;  // n = rows of matrix, m = cols of matrix, k = kernel size
    // Dynamically allocate memory for matrix, kernel, and output
    unsigned* matrix = NULL;  // Input matrix
    unsigned* kernel = NULL;  // Kernel size 3x3
    unsigned* output = NULL;  // Max size of output matrix

    char matrix_filename[30];
    char kernel_filename[30];

    // Read the file names
    printf("Enter matrix filename: ");
    scanf("%s", matrix_filename);
    printf("Enter kernel filename: ");
    scanf("%s", kernel_filename);


    // Read matrix and kernel from files
    read_matrix(matrix_filename, &matrix, &n, &m);  // Read matrix from file
    read_kernel(kernel_filename, &kernel, &k);      // Read kernel from file

    // For simplicity we say: padding = 0, stride = 1
    // With this setting we can calculate the output size
    unsigned output_rows = n - k + 1;
    unsigned output_cols = m - k + 1;
    output = (unsigned*)malloc(output_rows * output_cols * sizeof(unsigned));
    initialize_output(output, output_rows, output_cols);

    // Print the input matrix and kernel
    printf("Input Matrix: ");
    print_matrix(matrix, n, m, stdout);

    printf("\nKernel: ");
    print_matrix(kernel, k, k, stdout);

    /******************* KODUN BU KISMINDAN SONRASINDA DEĞİŞİKLİK YAPABİLİRSİNİZ - ÖNCEKİ KISIMLARI DEĞİŞTİRMEYİN *******************/

    // Assembly kod bloğu içinde kullanacağınız değişkenleri burada tanımlayabilirsiniz. ---------------------->
    // Aşağıdaki değişkenleri kullanmak zorunda değilsiniz. İsterseniz değişiklik yapabilirsiniz.
    unsigned matrix_value, kernel_value;    // Konvolüsyon için gerekli 1 matrix ve 1 kernel değişkenleri saklanabilir.
    unsigned sum;                           // Konvolüsyon toplamını saklayabilirsiniz.
    unsigned matrix_offset;                 // Input matrisi üzerinde gezme işleminde sınırları ayarlamak için kullanılabilir.
    unsigned tmp_si, tmp_di;                // ESI ve EDI döngü değişkenlerini saklamak için kullanılabilir.

    matrix_offset = k / 2;
    sum = 0;
    // Assembly dilinde 2d konvolüsyon işlemini aşağıdaki blokta yazınız ----->
    __asm {
        XOR EAX, EAX                // i = 0
        MOV EDX, output_cols        // EDX = cols
        MOV EBX, k                  // EBX = kernel_size
        PUSH m
        PUSH matrix
        PUSH kernel
        matris_rows :                                                   // i loop
        CMP EAX, output_rows        // i < rows
            JGE matrix_row_end
            PUSH EAX                    // i kaydet

            XOR ECX, ECX                // j = 0
            matris_cols :                                                   // j loop
        CMP ECX, output_cols                // j < cols 
            JGE matris_cols_end
            PUSH ECX                    // j kaydet

            XOR ESI, ESI                // sum = 0
            XOR EDI, EDI                // k = 0
            kernel_rows :                                                   // k loop
        CMP EDI, EBX                // k < kernel_size
            JGE kernel_rows_end
            PUSH EDI

            XOR EDI, EDI                // l = 0
            kernel_cols :                                                   // l loop    
        CMP EDI, EBX                // l < kernel_size
            JGE kernel_cols_end
            PUSH EDI

            // free registers: EAX, ECX, EDI --- EBX = kernel_size --- ESI = sum
            // matris hesaplamasÄ±
            MOV EAX, [ESP + 12]              // i'yi al yigindan
            ADD EAX, [ESP + 4]               // i + k
            MOV EDI, m
            MUL EDI                           // (i + k) * m
            ADD EAX, [ESP + 8]               // (i + k) * m + j
            ADD EAX, [ESP]                   // (i + k) * m + j + l
            MOV ECX, [ESP + 20]              // ECX = matris baÅŸlangÄ±Ã§ adresi
            LEA ECX, [ECX + EAX * 4]         // ECX = matris adresi
            MOV EAX, [ECX]                   // EAX = matrix_value
            PUSH EAX                          // matrix_value sakla

            //kernel hesaplamasÄ±       
            MOV EAX, [ESP + 8]                // k'yi al yigindan
            MUL EBX                            // k * kernel_size
            ADD EAX, [ESP + 4]                // k * kernel_size + l
            MOV ECX, [ESP + 20]               // ECX = kernel baÅŸlangÄ±Ã§ adresi
            LEA ECX, [ECX + EAX * 4]          // ECX = kernel adresi
            MOV EAX, [ECX]                    // EAX = kernel_value

            // konvolusyon
            POP ECX
            IMUL EAX, ECX                      // matrix_value * kernel_value
            ADD ESI, EAX                      // sum += matrix_value * kernel_value

            POP EDI
            INC EDI                           // l++
            JMP kernel_cols

            kernel_cols_end :
        POP EDI
            INC EDI                     // k++
            JMP kernel_rows

            kernel_rows_end :

        // output[i * output_cols + j] = sum;
        // output iÅŸlemi
        MOV EAX, [ESP + 4]          // i'yi al
            MOV ECX, output_cols        // ECX = output_cols
            MUL ECX                     // i * output_cols
            ADD EAX, [ESP]              // i * output_cols + j
            MOV ECX, output             // ECX = output baÅŸlangÄ±Ã§ adresi
            LEA ECX, [ECX + EAX * 4]    // ECX = output adresi
            MOV[ECX], ESI              // output adresine sum yaz

            POP ECX
            INC ECX                     // j++
            JMP matris_cols

            matris_cols_end :
        POP EAX
            INC EAX                     // i ++
            JMP matris_rows

            matrix_row_end :
        POP EAX
            POP EAX
            POP EAX
    }

    /******************* KODUN BU KISMINDAN ÖNCESİNDE DEĞİŞİKLİK YAPABİLİRSİNİZ - SONRAKİ KISIMLARI DEĞİŞTİRMEYİN *******************/


    // Write result to output file
    write_output("./output.txt", output, output_rows, output_cols);

    // Print result
    printf("\nOutput matrix after convolution: ");
    print_matrix(output, output_rows, output_cols, stdout);

    // Free allocated memory
    free(matrix);
    free(kernel);
    free(output);

    return 0;
}

void print_matrix(unsigned* matrix, unsigned rows, unsigned cols, FILE* file) {
    if (file == stdout) {
        printf("(%ux%u)\n", rows, cols);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%u ", matrix[i * cols + j]);
        }
        fprintf(file, "\n");
    }
}

void read_matrix(const char* filename, unsigned** matrix, unsigned* rows, unsigned* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read dimensions
    fscanf(file, "%u %u", rows, cols);
    *matrix = (unsigned*)malloc(((*rows) * (*cols)) * sizeof(unsigned));

    // Read matrix elements
    for (int i = 0; i < (*rows); i++) {
        for (int j = 0; j < (*cols); j++) {
            fscanf(file, "%u", &(*matrix)[i * (*cols) + j]);
        }
    }

    fclose(file);
}

void read_kernel(const char* filename, unsigned** kernel, unsigned* k) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read kernel size
    fscanf(file, "%u", k);
    *kernel = (unsigned*)malloc((*k) * (*k) * sizeof(unsigned));

    // Read kernel elements
    for (int i = 0; i < (*k); i++) {
        for (int j = 0; j < (*k); j++) {
            fscanf(file, "%u", &(*kernel)[i * (*k) + j]);
        }
    }

    fclose(file);
}

void write_output(const char* filename, unsigned* output, unsigned rows, unsigned cols) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Write dimensions of the output matrix
    fprintf(file, "%u %u\n", rows, cols);

    // Write output matrix elements
    print_matrix(output, rows, cols, file);

    fclose(file);
}

void initialize_output(unsigned* output, unsigned output_rows, unsigned output_cols) {
    int i;
    for (i = 0; i < output_cols * output_rows; i++)
        output[i] = 0;
    
}

