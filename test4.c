#include <stdio.h>
int main()
{
int b=1;
int a=5;
char char_array[5] = {'1', '2', '3', '4', '5'};
int int_array[b][a];
for (int i = 0; i < 5; i++){
    int_array[0][i] = char_array[i] - 48;
	printf("int_array[%d]= %d""\n",i,int_array[0]);
}
return 0;
}