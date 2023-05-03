#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 0;

    printf("輸入長度：");
	fflush(stdout);
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    printf("指定元素：\n");
    for(int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
		fflush(stdout);
        scanf("%d" , arr + i);
    }

    printf("顯示元素：\n");
    for(int i = 0; i < size; i++) {
        printf("arr[%d] = %p\n", i, &(arr+i));
    }

    free(arr);

    return 0;
}