#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 0;

    printf("��J���סG");
	fflush(stdout);
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(int));

    printf("���w�����G\n");
    for(int i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
		fflush(stdout);
        scanf("%d" , arr + i);
    }

    printf("��ܤ����G\n");
    for(int i = 0; i < size; i++) {
        printf("arr[%d] = %p\n", i, &(arr+i));
    }

    free(arr);

    return 0;
}