#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 0;

    printf("陣列長度：");
	fflush(stdout);
    scanf("%d", &size);
    int *arr1 = calloc(size, sizeof(int));

    printf("指定元素：\n");
	fflush(stdout);
    for(int i = 0; i < size; i++) {
        printf("arr1[%d] = ", i);
		fflush(stdout);
        scanf("%d" , arr1 + i);
		
    }

    printf("顯示元素：\n");
	fflush(stdout);
    for(int i = 0; i < size; i++) {
        printf("arr1[%d] = %d\n", i, *(arr1 + i));
		fflush(stdout);
    }

    int *arr2 = realloc(arr1, sizeof(int) * size * 2);
    printf("顯示元素：\n");
    for(int i = 0; i < size * 2; i++) {
        printf("arr2[%d] = %d\n", i, *(arr2 + i));
    }

    printf("arr1 位址：%p\n", arr1);
    printf("arr2 位址：%p\n", arr2);

    free(arr2);

    return 0;
}