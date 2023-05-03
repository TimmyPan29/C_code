#include <stdio.h>
int main()
{
    int i = 5,n = 0;
    while(i--)
    {
		printf("i= %04d""\n",i);
        if(i == 3)
     // return;
     // break;
        continue;
        else if(i == 1)
            n = 6;
    }
    n = n + 5;
    printf("i=%04d\n",i);
    printf("n=%d\n",n);
        return 0;    
}