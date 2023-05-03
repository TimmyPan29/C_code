//寫副程式要用動態陣列的話 主程式 和副程式都要有相應的動態指標陣列  void name (type*,type*)指的是回傳的資料型態
#include <stdio.h>
#include <stdlib.h>
void arraysum(int**,int**);
int main()
{
    int i,j,x,z;	
    int a,b;
	int count = 0;
	FILE *fpr;
	
	
 //開檔
    fpr=fopen("Hello.txt","r");
 //讀檔
    fscanf(fpr,"%d",&a);  // 行
    fscanf(fpr,"%d",&b);  // 列
    printf("%d\n", a);
	printf("%d\n", b);
	
	int **arr1;
	arr1 = malloc(b*sizeof(int*));  // G 二維矩陣
	for(i=0;i<b;i++)
	{
		arr1[i]=malloc(a*sizeof(int));
	}
	
	int **arr2;
	arr2 = malloc(b*sizeof(int*));  // H 二維矩陣
	for(i=0;i<(a-b);i++)
	{
		arr2[i]=malloc(a*sizeof(int));
	}
	int **ans;
	ans = malloc(b*sizeof(int*));  // G 二維矩陣
	for(i=0;i<b;i++)
	{
		ans[i]=malloc(a*sizeof(int));
	}
	printf("\n");
	
	for (i=0;i<b;i++)
    {
        for(j=0;j<a;j++)
        {
            fscanf(fpr,"%d", &arr1[i][j]); // 讀取資料
			printf("%d", arr1[i][j]);
        }
		printf("\n");
    }
	printf("\n");
	for (i=0;i<b;i++)
    {
        for(j=0;j<a;j++)
        {
            fscanf(fpr,"%d", &arr2[i][j]); // 讀取資料
			printf("%d", arr2[i][j]);
			fflush(stdout);
        }
		printf("\n");
    }
	printf("\n");
	
	arraysum(&arr1[0],&arr2[0]);
	
	for (i=0;i<b;i++)
    {
        for(j=0;j<a;j++)
        {
			printf("%d", ans[i][j]);
        }
		printf("\n");
    }
	fclose(fpr);
	
	
	return 0;
}

void arraysum(int **arr1,int **arr2){
	int i,j,x,z;	
    int a,b;
	int count = 0;
	FILE *fpr;
	//開檔
    fpr=fopen("Hello.txt","r");
 //讀檔
    fscanf(fpr,"%d",&a);  // 行
    fscanf(fpr,"%d",&b);  // 列
    // printf("%d\n", a);
	// printf("%d\n", b);
	
	/*arr1 = malloc(b*sizeof(int*));  // G 二維矩陣
	for(i=0;i<b;i++)
	{
		arr1[i]=malloc(a*sizeof(int));
	}
	
	arr2 = malloc(b*sizeof(int*));  // H 二維矩陣
	for(i=0;i<(a-b);i++)
	{
		arr2[i]=malloc(a*sizeof(int));
	}
	上面這一段多打得 其實不用打*/ 
	int **ans;
	ans = malloc(b*sizeof(int*));  // G 二維矩陣
	for(i=0;i<b;i++)
	{
		ans[i]=malloc(a*sizeof(int));
	}
	for(int i=0; i<b;i++){
		for(int j=0; j<a; j++){
			ans[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	fclose(fpr);
	
}
