#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int* GetArrayRowVector(int**,int);//get ith row
int* GetArrayColVector(int**,int);//get ith Col
void Print_M(int**);
void Print_V(int*);
int main(){
	int i,j,k,x,sum=0,check=0,itemp;
	char ctemp;
	int **m1=malloc(2*sizeof(int*));
	for(i=0; i<3; i++){
		m1[i]=malloc(2*sizeof(int));
	}
	//�}�C�ҬO����
	//�@�ӳ���Хe�F8��bytes(�e�F�O����K�ӪŶ�)
	//�@���������Ф]�e8��
	//�@��int�e4��
	int *row1 ;
	m1[0][0]=1;
	m1[0][1]=999;
	m1[1][0]=2131;
	m1[1][1]=11;
	row1 = GetArrayRowVector(m1,0);
	for(i=0; i<2; i++){
	printf("row1[%d]= %d\n ",i,row1[i]);
	fflush(stdout);
	}
	
	return 0;
}

int* GetArrayRowVector(int **M1,int a){
	int i=0,j=0,k,l=0,sum=0,check=0,itemp;
	char ctemp;
	while(M1[i][j]>-9999 && M1[i][j]<9999){
		j=0;
			while(M1[i][j]>-9999 && M1[i][j]<9999){
				j+=1;
			}
			i+=1;
			k=j;
	}
	l=i+1;
	printf("dasdada= %d",l);
			fflush(stdout);
	int *row1 ;
	row1 = malloc(k*sizeof(int));
	
	while(a>=l){
		printf("over NO. row");
		fflush(stdout);
		return 0;
	}
	for (i=0; i<k; i++){
		row1[i]=M1[a][i];
		
	}
	return row1;
}
// k = sizeof(m1[0]);//size(m1[0])�O���o�ӫ��Хe���j�p �o�˼g�O���諸
// //malloc�Mcalloc����C�p�⤣�n��@��{1,2,3,4,6},{,1,2,3,4,5}�o�حp��覡�d�V
// c = sizeof(m1)/sizeof(m1[0]); //�o�˼g���|�o��C��
//M1���������b |9999|����
int* GetArrayColVector(int **M1,int a){
	int i=0,j=0,k,l=0,sum=0,check=0,itemp;
	char ctemp;
	while(M1[j][i]>-9999 && M1[j][i]<9999){
		j=0;
			while(M1[j][i]>-9999 && M1[j][i]<9999){
				j+=1;
			}
			i+=1;
			k=j;
			printf("dasdada= %d",k);
			fflush(stdout);
	}
	l=i+1;
	int *row1 ;
	row1 = malloc(l*sizeof(int));
	
	while(a>=l){
		printf("over NO. Col");
		fflush(stdout);
		return 0;
	}
	for (i=0; i<l; i++){
		row1[i]=M1[i][a];
		
	}
	return row1;
}

void Print_M(int **M1){
	int i=0,j=0,k,l;
	while(M1[i][j]>-9999 && M1[i][j]<9999){
		j=0;
		while(M1[i][j]>-9999 && M1[i][j]<9999){
			j+=1;
		}	
		i+=1;
		k=j-1;
	}
	l=i;
	printf("\nthe matrix you input is as following\n");
	for(i=0; i<l; i++){
		for(j=0; j<k; j++){
			printf("%d ",M1[i][j]);
		}
		printf("\n");
	}
}

void Print_V(int *V1){
	int i=0,k;
	while(V1[i]>-9999 && V1[i]<9999){
		i+=1;
	}
	k=i;
	printf("\nthe vector you input is as following\n");
	for(i=0; i<k; i++){
		printf("%d ",V1[i]);
	}
}