#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*void print_matrix(float matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}以後可以搭配 define dynamic ptr2ay*/

/*void swap_rows(float matrix[ROWS][COLS], int row1, int row2) {
    for (int j = 0; j < COLS; j++) {
        float temp1 = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp1;
    }
}*/
void RREF(int **h1){  //寫在前面跟寫在後面都可以 副程式寫再全部的後面必須在開頭寫void RREF(int **h1);
/*initial setting*/	
	int i,a,b,j,count,x,index;
	FILE *ff ;
	ff = fopen("G.txt","r");
	fscanf(ff,"%d",&a);
	fscanf(ff,"%d",&b);
	for(i=0; i<b; i++){
		for(j=0; j<a; j++){
			if(h1[i][j]){
				index=j ; //第幾個元素出現首次1
				break;
			}
		}
		for(count=1; count<b; count++){
			if(h1[(i+count)%b][index]){
				for(x=0; x<a; x++){
					h1[(i+count)%b][x]^=h1[i][x];
				}
			}
		}
	}
	fclose(ff);
}

int main(){
	FILE *ff ,*gg ;
	int a, b,c;
	int **h1;
	int **g1;
	int **error_a1;
	int index,x,z,i,j,k;
	int count,length_position_idx;
	int messagelength;
/*開G.txt檔案*/
	ff = fopen("G.txt","r");
	fscanf(ff,"%d",&a);
	fscanf(ff,"%d",&b);
	printf("column a=%d\n",a);
	fflush(stdout);
	printf("row b=%d\n",b);
	fflush(stdout);
	int temp1[b][1],temp2[a-b][1],swap_turn[1][b];
/*主程式裡面 創建二維動態陣列*/
	h1 = malloc(sizeof(int*)*b); //for original matrix
	for (int i=0;i<b;i++){
		h1[i] = malloc(sizeof(int)*a);
	}
	g1 = malloc(sizeof(int*)*(a-b));  //for processed matrix
	for(int i=0;i<(a-b);i++){
		g1[i]=malloc(sizeof(int)*a);
	}
/*矩陣賦值*/
	for (int i=0;i<b;i++){
		for (int j=0;j<a;j++){
			fscanf(ff,"%d",&h1[i][j]);
			printf("%d",h1[i][j]);
		}
		printf("\n");
	}
/*吃error pattern 資料進來*/
	fscanf(ff,"%d",&c); //No. of error pattern
	
	error_a1 = (int**)malloc(sizeof(int*)*c); //for original matrix
	for (int i=0;i<c;i++){
		error_a1[i] = (int*)malloc(sizeof(int)*a);
	}
	printf("error_pattern_a1: \n");
/*error pattern賦值*/
	for (int i=0;i<c;i++){
		for (int j=0;j<a;j++){
			fscanf(ff,"%d",&error_a1[i][j]);
			printf("%d",error_a1[i][j]);
		}
		printf("\n");
	}
/*message賦值*/
	messagelength=c;
	
	fclose(ff); //關txt檔
	

/*RREF*/ 
	int **h2 = malloc(b*sizeof(int*));
	for(i=0; i<a; i++){
		h2[i] = malloc(a*sizeof(int));
	}
	RREF(&h1[0]);//地址的地址
	
/*debug1*/
	printf("\ndebug1\n");
	for (int i=0;i<b;i++){
		for (int j=0;j<a;j++){
			printf("%d",h1[i][j]);
		}
		printf("\n");
	}
/*壓扁找position*/
	printf("\n");
	int position_v1[1][a],position_idx[1][a];
	for(i=0;i<a; i++){//初始值設零
		position_v1[0][i]=0;
		position_idx[0][i]=0;
	}
	for(j=0; j<a; j++){//壓扁
		for(i=0; i<b; i++){
			position_v1[0][j]+=h1[i][j];
		}
		printf("%d",position_v1[0][j]);
	}
   printf("\n");
	count=0;
	for(i=0; i<a; i++){//找index
		if(position_v1[0][i]==1){
			position_idx[0][count]=i;
			printf("%d",position_idx[0][count]);
			count++;
		}
		length_position_idx=count;
	}
	printf("\n");
	printf("length_position_idx= %d\n",length_position_idx);
/*debug*1-2*/	
	printf("\n");
	printf("debug1_2\n");
	for(i=0; i<b; i++){
	count=0;
		do{
			k=position_idx[0][count];
			if(h1[i][k]==1){
				for(x=0; x<b; x++){
					temp1[x][0]=h1[x][i];
					h1[x][i]=h1[x][k];
					h1[x][k]=temp1[x][0];	
					swap_turn[0][i]=k;
				}	
				printf("%d",swap_turn[0][i]);
				break;
			}
			count++;
		}while(count<length_position_idx);
	}
	printf("\n");
/*debug2*/
	printf("\n");
	printf("debug2\n");
	for (int i=0;i<b;i++){
		for (int j=0;j<a;j++){
			printf("%d",h1[i][j]);
		}
		printf("\n");
	}
/*transpose*/

	for(int i = 0; i < b; i++){
		for(int j = b; j < a; j++){
			g1[j-b][i] = h1[i][j]; 
		}
	}
	
	for(int i = 0; i < a-b; i++){
		for(int j = b; j < a; j++){
			g1[i][j] = ((i+b)==j)?1:0;
		}
	}
/*debug3*/
	printf("\n");
	printf("debug3\n");
	for (int i=0;i<a-b;i++){
		for (int j=0;j<a;j++){
			printf("%d",g1[i][j]);
		}
		printf("\n");
	}
/*swap to original coulume in H*/
	for(i=b-1; i>=0; i--){
		k=swap_turn[0][i];
		for(x=0; x<a-b; x++){
			temp2[x][0]=g1[x][i];
			g1[x][i]=g1[x][k];
			g1[x][k]=temp2[x][0];
		}
	}
/*debug4*/
	printf("\n");
	printf("debug4\n");
	for (int i=0;i<a-b;i++){
		for (int j=0;j<a;j++){
			printf("%d",g1[i][j]);
		}
		printf("\n");
	}
	
/*寫入H.txt檔 他會自己創建*/
	gg = fopen("H.txt","w"); 	
	
	fprintf(gg,"%d\n",a);
	printf("processed column a=%d\n",a);
	fprintf(gg,"%d\n",a-b);
	printf("processed row b=%d\n",a-b);
	
	printf("processed matrix:\n");
	for (int i=0;i<a-b;i++){
		for (int j=0;j<a;j++){
			
			fprintf(gg,"%d"" ",g1[i][j]);
			printf("%d",g1[i][j]);
		}
		fprintf(gg,"\n");
		printf("\n");
	}
	
	
	fclose(gg); //關txt檔

	return 0 ;	
}





