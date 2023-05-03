#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

void print_matrix(float matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap_rows(float matrix[ROWS][COLS], int row1, int row2) {
    for (int j = 0; j < COLS; j++) {
        float temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

void scale_row(float matrix[ROWS][COLS], int row, float scalar) {
    for (int j = 0; j < COLS; j++) {
        matrix[row][j] *= scalar;
    }
}

void add_scaled_row(float matrix[ROWS][COLS], int dest_row, int src_row, float scalar) {
    for (int j = 0; j < COLS; j++) {
        matrix[dest_row][j] += scalar * matrix[src_row][j];
    }
}

void rref(float matrix[ROWS][COLS], int rows, int cols) {
    int lead = 0;
    for (int r = 0; r < rows; r++) {
        if (lead >= cols) {
            return;
        }
        int i = r;
        while (matrix[i][lead] == 0) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols) {
                    return;
                }
            }
        }
        swap_rows(matrix, i, r);
        scale_row(matrix, r, 1.0 / matrix[r][lead]);
        for (i = 0; i < rows; i++) {
            if (i != r) {
                add_scaled_row(matrix, i, r, -matrix[i][lead]);
            }
        }
        lead++;
    }
}

int main() {
    float matrix[ROWS][COLS] = {{2, 1, -1, 8}, {-3, -1, 2, -11}, {-2, 1, 2, -3}};
    printf("Original matrix:\n");
    print_matrix(matrix, ROWS, COLS);
    rref(matrix, ROWS, COLS);
    printf("RREF:\n");
    print_matrix(matrix, ROWS, COLS);
    return 0;
}
