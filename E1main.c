#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void RREF_h1(int**);
void RREF_g1(int**);
void M_seq(int,int,int*);//訊號長度 ,errorpattern數
void RowVectorSum(int**,int,int**,int,int*);
void ScalarVector(int*, int**,int*); //u g1 row1
void error_gen(int,int,int*);

int main(){
	FILE *ff ,*gg ;
	int a, b,c,sum=0;
	int **h1;
	int **g1;
	int **error_a1;
	int index,x,i,j,k;
	int count,length_position_idx;
	int messagelength;
/*開G.txt檔案*/
	ff = fopen("setting.txt","r");
	fscanf(ff,"%d",&a);
	fscanf(ff,"%d",&b);
	printf("column a=%d\n",a);
	fflush(stdout);
	printf("row b=%d\n",b);
	fflush(stdout);
	int temp1[b][1],temp2[a-b][1],swap_turn[1][b],temp_row_turn[1][a];
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
	int **h1_ori = malloc(sizeof(int*)*b);
	for (int i=0;i<b;i++){
		h1_ori[i] = malloc(sizeof(int)*a);
	}
	for (int i=0;i<b;i++){ //original h1 data
		for (int j=0;j<a;j++){
			h1_ori[i][j]=h1[i][j];
		}
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
	messagelength=a-b;
	
	fclose(ff); //關txt檔

/*主程式裡面 創建二維動態陣列 給mseq*/	
	int *mseq = calloc(messagelength*c,sizeof(int));

/*生出 mseq*/
	M_seq(messagelength,c,mseq); //mseq本身就是*型態
	for(i=0; i<messagelength*c; i++){
		printf("%d",mseq[i]);
	}
	printf("\n");
/*RREF*/ 
	RREF_h1(&h1[0]); //**型態 (指標的指標)

/*debug1*/
	printf("debug1\n");
	for (int i=0;i<b;i++){
		for (int j=0;j<a;j++){
			printf("%d",h1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

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
		// printf("%d",position_v1[0][j]);
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
/*swap colume*/	
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
				printf("%d",swap_turn[0][i]); //get swap order
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
/*debug3 g1*/
	printf("\n");
	printf("debug3 g1\n");
	for (int i=0;i<a-b;i++){
		for (int j=0;j<a;j++){
			printf("%d",g1[i][j]);
		}
		printf("\n");
	}
/*swap to original coulume in H*/
	for(i=0; i<b; i++){
		k=swap_turn[0][b-1-i];
		for(x=0; x<a-b; x++){
			temp2[x][0]=g1[x][b-1-i];
			g1[x][b-1-i]=g1[x][k];
			g1[x][k]=temp2[x][0];
		}
	}
/*debug4*/
	printf("\n");
	printf("debug4 \n");
	for (int i=0;i<a-b;i++){
		for (int j=0;j<a;j++){
			printf("%d",g1[i][j]);
		}
		printf("\n");
	}
/*RREF2*/ 
	RREF_g1(g1);
/*debug5*/
	printf("\n");
	printf("debug5\n");		
	for (int i=0;i<a-b;i++){
		for (int j=0;j<a;j++){
			printf("%d",g1[i][j]);
		}
		printf("\n");
	}	
/*change row to standard form*/ 
	for(count=0; count<a-b; count++){
		for(j=0; j<a-b; j++){
			if(g1[count][j]){
				for(x=0; x<a; x++){
					temp_row_turn[0][x]=g1[j][x];
					g1[j][x]=g1[count][x];
					g1[count][x]=temp_row_turn[0][x];
				}
				break;
			}
		}
	}
/*debug6*/
	printf("\n");
	printf("debug6\n");	
	for (int i=0;i<a-b;i++){
		for (int j=0;j<a;j++){
			printf("%d",g1[i][j]);
		}
		printf("\n");
	}	
/*generate codeword according data from mseq*/
	int **u = calloc(c,sizeof(int*)); //創u矩陣
	for (i=0; i<c; i++){
		u[i] = calloc(messagelength,sizeof(int));
	}
	
	for (i=0; i<c; i++){ //賦值
		for(j=0; j<messagelength; j++){	
			u[i][j]=mseq[messagelength*i+j];
		}
	}
	int *u_Vec = calloc(messagelength,sizeof(int));
	int *row1 = calloc(a,sizeof(int)); //產生列向量
	int **codeword = calloc(c,sizeof(int*));
	for (i=0; i<a; i++){
		codeword[i] = calloc(a,sizeof(int));
	}
	for (i=0; i<c; i++){
		for(j=0; j<messagelength; j++){
			u_Vec[j]=u[i][j];
		}
		ScalarVector(u_Vec,g1,row1);
		for(x=0; x<a; x++){
			codeword[i][x]=row1[x];
		}
	}
/*debug7*/
	printf("\n");
	printf("debug7\n");	
	for (int i=0;i<c;i++){
		for (int j=0;j<a;j++){
			printf("%d",codeword[i][j]);
		}
		printf("\n");
	}

/*noise-added codeword*/	
	int **n_codeword = calloc(c,sizeof(int*));
	for (i=0; i<a; i++){
		n_codeword[i] = calloc(a,sizeof(int));
	}
	for (i=0; i<c; i++){
		for (j=0; j<a; j++){
			n_codeword[i][j]=(codeword[i][j]+error_a1[i][j])%2;
		}
	}

/*debug8*/
	printf("\n");
	printf("debug8\n");	
	for (int i=0;i<c;i++){
		for (int j=0;j<a;j++){
			printf("%d",n_codeword[i][j]);
		}
		printf("\n");
	}
/*get the syndrome*/
	int **syndrome = calloc(b,sizeof(int*));
	for (i=0; i<b; i++){
			syndrome[i] = calloc(c,sizeof(int));
		}	
	for (i=0; i<b; i++){
		for (j=0; j<c; j++){
			for (x=0; x<a; x++){
				sum+=h1_ori[i][x]&n_codeword[j][x];		
			}
			syndrome[i][j]=sum%2;
			sum = 0;
		}	
	}
/*debug9*/
	printf("\n");
	printf("debug9\n");	
	for (int i=0;i<b;i++){
		for (int j=0;j<c;j++){
			printf("%d",syndrome[i][j]);
		}
		printf("\n");
	}
/*get error pattern according to syndrome solving above*/
	int **error_a2 = calloc(c,sizeof(int*));
	for (i=0; i<c; i++){
			error_a2[i] = calloc(a,sizeof(int));
		}
	sum=0;
	for (int count=0; count<c; count++){
		sum=0;
		for(int i=0; i<a; i++){
			for(int x=0; x<b; x++){
				sum+=syndrome[x][count]^!h1_ori[x][i];
			}
			if(sum==b){
				index=i;
				error_gen(a,index,row1);
				for(x=0; x<a; x++){
				error_a2[count][x]=row1[x];
				}
				sum=0;
				break;
			}
			else
				sum=0;
			continue;
		}
	}
		
/*debug10*/
	printf("\n");
	printf("debug10\n");	
	for (int i=0;i<c;i++){
		for (int j=0;j<a;j++){
			printf("%d",error_a2[i][j]);
		}
		printf("\n");
	}
/*minus noise from interfered codeword*/
	for (i=0; i<c; i++){
		for (j=0; j<a; j++){
			codeword[i][j]=n_codeword[i][j]^error_a2[i][j];
		}
	}	
/*debug11*/
	printf("\n");
	printf("debug11\n");	
	for (int i=0;i<c;i++){
		for (int j=0;j<a;j++){
			printf("%d",codeword[i][j]);
		}
		printf("\n");
	}
/*extract message from de-interfered codeword*/
	int **message = calloc(c,sizeof(int*));
	for (i=0; i<c; i++){
			message[i] = calloc(messagelength,sizeof(int));
		}
	for (i=0; i<c; i++){
		for (j=0; j<messagelength; j++){
			message[i][j]=codeword[i][j];
		}
	}
/*debug12*/
	printf("\n");
	printf("debug12\n");	
	for (int i=0;i<c;i++){
		for (int j=0;j<messagelength;j++){
			printf("%d",message[i][j]);
		}
		printf("\n");
	}	
/*寫入H.txt檔 他會自己創建*/
	printf("\n");
	gg = fopen("u.txt","w"); 		
	for (int i=0;i<c;i++){
		for (int j=0;j<messagelength;j++){		
			fprintf(gg,"%d"" ",message[i][j]);
			printf("%d",message[i][j]);
		}
		fprintf(gg,"\n");
		printf("\n");
	}
	
	
	fclose(gg); //關txt檔

	return 0 ;	
}

/*--------------------------------------副程式-----------------------------------------*/
/*-------------------------------------------------------------------------------------*/
void RREF_h1(int **h1){
/*initial setting*/	
	int i,a,b,j,count,x,index;
	FILE *ff ;
	ff = fopen("setting.txt","r");
	fscanf(ff,"%d",&a);
	fscanf(ff,"%d",&b);
	
	fclose(ff);
	
/*vice function*/	
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
	
}

void RREF_g1(int **g1){
/*initial setting*/	
	int i,a,b,j,count,x,index;
	FILE *ff ;
	ff = fopen("setting.txt","r");
	fscanf(ff,"%d",&a);
	fscanf(ff,"%d",&b);
	
	fclose(ff);
	
/*vice function*/	
	for(i=0; i<a-b; i++){
		for(j=0; j<a; j++){
			if(g1[i][j]){
				index=j ; //第幾個元素出現首次1
				break;
			}
		}
		for(count=1; count<a-b; count++){
			if(g1[(i+count)%(a-b)][index]){
				for(x=0; x<a; x++){
					g1[(i+count)%(a-b)][x]^=g1[i][x];
				}
			}
		}
	}
}

void M_seq(int messagelength,int c,int *mseq){ //input input output
	int u[6]={1,0,0,0,0,0},temp,i;
	temp = messagelength*c;
	// mseq=calloc(temp,sizeof(int));  //這個不用打 不然函數會出錯
	for(i=0; i<6; i++){
		mseq[i]=u[i];
	}
	for(i=6; i<temp; i++){
		mseq[i]=mseq[i-5]^mseq[i-6];
	}
	
}

void RowVectorSum(int **h1,int m,int **g1,int n,int *row1){ //取矩陣的第m列加上矩陣的第n列 存到一個新向量 
	FILE *ff ;
	int a;
	ff = fopen("setting.txt","r");
	fscanf(ff,"%d",&a);
	fclose(ff);
	for (int x=0; x<a; x++){
		row1[x]=h1[m][x]+g1[n][x];
	}		
}
void ScalarVector(int *u, int **g1, int *row1){
	FILE *ff;
	int a,b,sum=0;
	ff = fopen("setting.txt","r");
	fscanf(ff,"%d",&a);
	fscanf(ff,"%d",&b);
	fclose(ff);
	int messagelength,x;
	messagelength=a-b;
	for(int j=0; j<a; j++){
		for(x=0; x<messagelength; x++){
			sum+=u[x]&g1[x][j];				
		}
		row1[j]=sum;
		sum=0;  //絕對要寫初始值 害我debug半天*******************************************************
	}	
}

void error_gen(int l,int index,int *error_vec){
	int i;
	int row[l];
	for (i=0; i<l; i++){
		row[i]=(i==index)?1:0;
		error_vec[i]=row[i];
	}
}

// /*--------------G*H'--------------*/
	
// 開檔
    // ff=fopen("setting.txt","r");
 // 讀檔
    // fscanf(ff,"%d",&a);  // 行
    // fscanf(ff,"%d",&b);  // 列
	// for (i=0;i<b;i++)
    // {
        // for(j=0;j<a;j++)
        // {
            // fscanf(ff,"%d", &h1[i][j]); // 讀取資料
        // }
    // }
	// fclose(ff);
	
	
	// int sum = 0;
	
	// int **tm;
	// tm = calloc(a-b,sizeof(int*));  // 二維矩陣
	// for(i=0;i<a-b;i++)
	// {
		// tm[i]=calloc(b,sizeof(int));
	// }
	// for (i=0; i<a-b; i++){
		// for (j=0; j<b; j++){
			// for (x=0; x<a; x++){
				// sum+=g1[i][x]&h1[j][x];		
			// }
			// tm[i][j]=sum%2;
		// }
		
	// }
	// printf("\nG*H'\n");
	
	// for (i=0;i<a-b;i++)
    // {
        // for(j=0;j<b;j++)
        // {
			// printf("%d", tm[i][j]);
        // }
		// printf("\n");
    // }
	
//寫一個printf row和printf array