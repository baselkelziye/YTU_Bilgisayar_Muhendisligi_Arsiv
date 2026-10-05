#include <stdio.h>

#define MAX 100

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    int visited[MAX][MAX] = {0};
    int path_lengths[MAX] = {0}; // Store length of path starting from each row
    int i, j;

    printf("Enter the size of the path matrix (rows columns): \n");
    scanf("%d %d", &rows, &cols);

    printf("Enter the matrix values:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // For each row in first column, try to find a path
    for (int start_row = 0; start_row < rows; start_row++) {
        if (matrix[start_row][0] == 0) continue; // Skip if no path at first column

        int current_row = start_row;
        int current_col = 0;
        int length = 0;
        int path_value = matrix[start_row][0];
        int control = 1;

        // Reset visited array for this path
        for (i = 0; i < rows; i++)
            for (j = 0; j < cols; j++)
                visited[i][j] = 0;

        while (control) {
            length++;
            visited[current_row][current_col] = 1;

            // Priority moves:
            // Right, Down, Up, Diagonals (Down-Right, Down-Left, Up-Right, Up-Left)
            if (current_col + 1 < cols && 
                matrix[current_row][current_col + 1] == path_value && 
                !visited[current_row][current_col + 1]) {
                current_col++;
            }
            else if (current_row + 1 < rows && 
                     matrix[current_row + 1][current_col] == path_value && 
                     !visited[current_row + 1][current_col]) {
                current_row++;
            }
            else if (current_row - 1 >= 0 && 
                     matrix[current_row - 1][current_col] == path_value && 
                     !visited[current_row - 1][current_col]) {
                current_row--;
            }
            else if (current_row + 1 < rows && current_col + 1 < cols &&
                     matrix[current_row + 1][current_col + 1] == path_value && 
                     !visited[current_row + 1][current_col + 1]) {
                current_row++;
                current_col++;
            }
            else if (current_row + 1 < rows && current_col - 1 >= 0 &&
                     matrix[current_row + 1][current_col - 1] == path_value && 
                     !visited[current_row + 1][current_col - 1]) {
                current_row++;
                current_col--;
            }
            else if (current_row - 1 >= 0 && current_col + 1 < cols &&
                     matrix[current_row - 1][current_col + 1] == path_value && 
                     !visited[current_row - 1][current_col + 1]) {
                current_row--;
                current_col++;
            }
            else if (current_row - 1 >= 0 && current_col - 1 >= 0 &&
                     matrix[current_row - 1][current_col - 1] == path_value && 
                     !visited[current_row - 1][current_col - 1]) {
                current_row--;
                current_col--;
            }
            else {
                // No available moves
                control = 0;
            }
        }

        // Check if path reached last column
        if (current_col == cols - 1) {
            path_lengths[start_row] = length;
        } else {
            path_lengths[start_row] = 0; // No complete path
        }
    }

    // Print the results
    for (i = 0; i < rows; i++) {
        if (path_lengths[i] > 0)
            printf("Path starting at row %d has length: %d\n", i, path_lengths[i]);
        else
            printf("No complete path starting at row %d\n", i);
    }

    return 0;
}