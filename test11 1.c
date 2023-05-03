#include<stdio.h>
int main()
{
    // Read in the user's favorite number
    int fav_num;
    printf("Enter your favorite number from 0 to 99: ");
	fflush(stdout);
    scanf("%d", &fav_num);
    
    int count = 0;
    while(count < 100)
    {
        printf("\nThe value of count is %d.", count);
		fflush(stdout);
        if (count == fav_num)
    		break;
        count++;
    }
    return 0;
}