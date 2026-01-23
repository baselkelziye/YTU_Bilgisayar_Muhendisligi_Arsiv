#include <iostream>
#include <iomanip>   

using namespace std;

extern "C" void matmul_asm(const int* A,
    const int* B,
    int* C,
    int A_rows,
    int A_cols,
    int B_cols);

void matmul_c(const int* A,
    const int* B,
    int* C,
    int A_rows,
    int A_cols,
    int B_cols)
{
    int i, j, k;

    for (i = 0; i < A_rows; i++) {
        for (j = 0; j < B_cols; j++) {
            for (k = 0; k < A_cols; k++) {
                C[i * B_cols + j] +=
                    A[i * A_cols + k] *
                    B[k * B_cols + j];
            }
        }
    }
}

void print_matrix(const char* name,
    const int* M,
    int rows,
    int cols)
{
    cout << name << " (" << rows << " x " << cols << "):" << endl;

    const int WIDTH = 5;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(WIDTH) << M[i * cols + j];
        }
        cout << endl;
    }
    cout << endl;
}


bool compare_matrices(const int* C1,
    const int* C2,
    int rows,
    int cols)
{
    int total = rows * cols;
    for (int i = 0; i < total; ++i) {
        if (C1[i] != C2[i]) {
            return false;
        }
    }
    return true;
}

const int A_ROWS = 5;
const int A_COLS = 3;
const int B_ROWS = 3;
const int B_COLS = 4;

int main()
{
    int A[A_ROWS * A_COLS] = {
        1,  2,  3,
        4,  5,  6,
        7,  8,  9,
        1,  0, -1,
        -2,  3,  -4
    };

    int B[B_ROWS * B_COLS] = {
        1,  2,  3,  4,
        5,  6,  7,  8,
        9, -10, 11, -12
    };

    int C_c[A_ROWS * B_COLS] = { 0 };
    int C_asm[A_ROWS * B_COLS] = { 0 };

    if (A_COLS != B_ROWS) {
        cout << "HATA: A_COLS != B_ROWS, matrisler carpilamaz." << endl;
        return 1;
    }

    matmul_c(A, B, C_c, A_ROWS, A_COLS, B_COLS);

    matmul_asm(A, B, C_asm, A_ROWS, A_COLS, B_COLS);

    print_matrix("A matrisi", A, A_ROWS, A_COLS);
    print_matrix("B matrisi", B, B_ROWS, B_COLS);
    print_matrix("C matrisi (C kodu ile)", C_c, A_ROWS, B_COLS);
    print_matrix("C matrisi (ASM kodu ile)", C_asm, A_ROWS, B_COLS);

    bool same = compare_matrices(C_c, C_asm, A_ROWS, B_COLS);
    cout << "Sonuclar " << (same ? "AYNI" : "FARKLI") << endl;

    cout << endl << "Program tamamlandi." << endl;
    system("pause");
    return 0;
}
