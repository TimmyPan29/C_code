#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int **arr = calloc(5, sizeof(int*));
    for(int i = 0; i < 5; i++) {
        arr[i] = calloc(6, sizeof(int));
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 6; j++) {
            // printf("%d ", arr[i][j]);
			printf("%p ", &arr[i][j]);
        }
        putchar('\n');
    }

    for(int i = 0; i < 5; i++) {
        free(arr[i]);
    }
    free(arr); 

    return 0;
}