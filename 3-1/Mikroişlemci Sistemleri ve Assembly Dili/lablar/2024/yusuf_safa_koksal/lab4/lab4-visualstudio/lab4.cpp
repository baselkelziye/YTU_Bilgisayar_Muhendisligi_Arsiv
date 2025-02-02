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
    unsigned sum;                           // Konvolüsyon toplamını saklayabilirsiniz.
    unsigned row_loop_number, col_loop_number, kernel_loop_number;
    unsigned i = 0, j = 0, k_index_y = 0, k_index_x=0;

    sum = 0;
    // Assembly dilinde 2d konvolüsyon işlemini aşağıdaki blokta yazınız ----->
    __asm {
        // Aşağıdaki kodu silerek başlayabilirsiniz ->
        MOV EAX, output_rows
        DEC EAX
        MOV row_loop_number, EAX
        MOV EAX, output_cols
        DEC EAX
        MOV col_loop_number, EAX
        MOV EAX, k
        DEC EAX
        MOV kernel_loop_number, EAX

        loop_first:
        MOV EAX, i
        CMP EAX, row_loop_number
        JA END
        MOV j, 0

            loop_second:
            MOV EAX, j
            CMP EAX, col_loop_number
            JA loop_first_gec
            MOV k_index_y, 0
            MOV sum, 0
            JMP loop_third

            loop_first_gec:
            INC i
            JMP loop_first

                loop_third:
                MOV EAX, k_index_y
                CMP EAX, kernel_loop_number
                JA loop_second_gec
                MOV k_index_x, 0
                JMP loop_fourth

                loop_second_gec:
                MOV EAX, output_cols
                MOV ECX, i
                MUL ECX
                ADD EAX, j
                MOV EDI, EAX
                MOV EBX, output
                MOV EAX, sum
                MOV [EBX + EDI*4], EAX
                INC j
                JMP loop_second

                    loop_fourth:
                    MOV EAX, k_index_x
                    CMP EAX, kernel_loop_number
                    JA loop_third_gec

                    //konvolusyon
                    MOV EAX, k
                    MUL k_index_y
                    ADD EAX, k_index_x
                    MOV ESI, EAX
                    MOV EBX, kernel
                    MOV ECX, [EBX+ESI*4]

                    MOV EAX, i
                    ADD EAX, k_index_y
                    MUL m
                    ADD EAX, j
                    ADD EAX, k_index_x
                    MOV ESI, EAX
                    MOV EBX, matrix
                    MOV EAX, [EBX+ESI*4]

                    MUL ECX
                    ADD sum, EAX
                    //konvolusyon

                    INC k_index_x
                    JMP loop_fourth

                    loop_third_gec:
                    INC k_index_y
                    JMP loop_third
        END:
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

