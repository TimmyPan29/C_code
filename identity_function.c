// C program to print Identity Matrix
#include<stdio.h>

int Identity(int num)//吃甚麼資料
{
	int row, col;
	
	for (row = 0; row < num; row++)
	{
		for (col = 0; col < num; col++)
		{
			// Checking if row is equal to column
			if (row == col)
				printf("%d ", 1);
			else
				printf("%d ", 0);
		}
		printf("\n");
	}
	return 0;
}

// Driver Code
int main()
{
	int input1;
	printf("input the size of identity matrix= ");
	fflush(stdout);
	scanf("%d",&input1);
	Identity(input1);
	return 0;
}
