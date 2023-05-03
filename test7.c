#include <stdio.h>

#define MAX_ROWS 3
#define MAX_COLS 3

int main() {
    FILE *fp;
    char line[100];
    int matrix[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;

    // Open file for reading
    fp = fopen("matrix.txt", 'r');

    // Read matrix from file
    while (fgets(line, 100, fp) != NULL) {
        cols = 0;
        int num;
        char *token = strtok(line, " ");
        while (token != NULL) {
            sscanf(token, "%d", &num);
            matrix[rows][cols] = num;
            cols++;
            token = strtok(NULL, " ");
        }
        rows++;
    }

    // Transpose matrix
    int transposed[MAX_COLS][MAX_ROWS];
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }

    // Write transposed matrix to file
    FILE *fp_out;
    fp_out = fopen("transposed.txt", "w");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            fprintf(fp_out, "%d ", transposed[i][j]);
        }
        fprintf(fp_out, "\n");
    }
    fclose(fp_out);

    // Close file
    fclose(fp);

    return 0;
}
