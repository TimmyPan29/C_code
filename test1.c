#include <stdio.h>

int main ()
{
   char ch,c;
	int a[126]={0} ,b;
   for(ch = 1 ; ch <= 126 ; ch++) {
      c=putchar(ch);
	  a[ch]=c-48;
	  printf("a[%d]=%d \n",ch,a[ch]);
	  
   }
   
   return(0);
}