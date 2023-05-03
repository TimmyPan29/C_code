#include <stdio.h>

void print(int **v, int height, int width){
	int i ,j ;
	for (i = 0; i< height; i++){
		for(j=0; j<width; j++){
			printf("%d", v[i][j]);
		}
		printf("\n");
	}	
}
int main(){
	int v[2][3] = {{1,2,3},{4,5,6}};
	int *p[2] = {&v[0][0],&v[1][0]};
	print(&p[0],2,3);
	return 0 ;
}