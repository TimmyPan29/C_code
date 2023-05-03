#include"stdio.h"
#include"stdlib.h"

void test(float*); //標頭採用浮點數指標的方式傳入值

int main()
{
float arr[3] = {0};
int i = 0;

test( &arr[0] );
for( i = 0 ; i < 3 ; i++ )
printf("%.2f ",arr[i]);

system("pause");
}
void test(float* arr)
{
int i;
for( i = 0; i < 3 ; i++ )
arr[i] = 1.5;
}