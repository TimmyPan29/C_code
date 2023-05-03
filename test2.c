
// g++ cpp-fgets3.cpp -o a.out
#include <stdio.h>

int main() {
    char buffer[32];
    printf("input: ");
	fflush(stdout);
    fgets(buffer, 32, stdin);
    printf("\n%s\n", buffer);

    return 0;
}