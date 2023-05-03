#include <stdio.h>
int main()
{
char char_array[5] = {'1', '2', '3', '4', '5'};
int int_array[5] = {0};
for (int i = 0; i < 5; i++){
    int_array[i] = char_array[i] - 48;
	printf("int_array[%d]= %d""\n",i,int_array[i]);
}
return 0;
}