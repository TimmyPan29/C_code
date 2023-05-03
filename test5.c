#include <stdio.h>

#define MAX_ROWS 3
#define MAX_COLS 3

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int transposed[MAX_COLS][MAX_ROWS];
    int rows, cols, i, j;

    // Open the file for reading
    FILE* fp = fopen("matrix.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the matrix dimensions from the file
    fscanf(fp, "%d %d", &rows, &cols);

    // Read the matrix data from the file
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
			printf("%d",matrix[i][j]);
			fflush(stdout);
        }
    }

    // Close the file
    fclose(fp);

    // Transpose the matrix
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }

    // Open the file for writing
    fp = fopen("transposed_matrix.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write the transposed matrix data to the file
    fprintf(fp, "%d %d\n", cols, rows);
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            fprintf(fp, "%d ", transposed[i][j]);
        }
        fprintf(fp, "\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}
