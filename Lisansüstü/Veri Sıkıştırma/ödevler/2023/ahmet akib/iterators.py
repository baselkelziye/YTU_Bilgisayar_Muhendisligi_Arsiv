import numpy as np

def zigzag_iterator(matrix):
    rows, cols = matrix.shape
    for i in range(rows + cols - 1):
        if i % 2 == 0:
            # Iterate upwards along the diagonal
            for row in range(max(0, i - cols + 1), min(i + 1, rows)):
                yield matrix[row, i - row]
        else:
            # Iterate downwards along the diagonal
            for col in range(max(0, i - rows + 1), min(i + 1, cols)):
                yield matrix[i - col, col]
def row_rotate_iterator(matrix):
    rows, cols = matrix.shape
    for i in range(rows):
        if i % 2 == 0:
            # Iterate normally for even lines
            for j in range(cols):
                yield matrix[i, j]
        else:
            # Reverse and iterate for odd lines
            for j in range(cols - 1, -1, -1):
                yield matrix[i, j]
def column_rotate_iterator(matrix):
    rows, cols = matrix.shape
    for i in range(cols):
        if i % 2 == 0:
            # Iterate normally for even lines
            for j in range(rows):
                yield matrix[j, i]
        else:
            # Reverse and iterate for odd lines
            for j in range(rows - 1, -1, -1):
                yield matrix[j, i]   

if __name__ == "__main__": #for testing
    n_size = 10
    matrix = np.zeros((n_size,n_size))
    for i in range(n_size):
        for j in range(n_size):
            matrix[i,j] = i*n_size + j

    for element in range(matrix.shape[0]):
        for element2 in range(matrix.shape[1]):
            print(f"{int(matrix[element,element2])} \t",end=" ")
        print("\n")

    iterator = rotate_iterator(matrix)

    for element in iterator:
        print(element)


