#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *ff ;
	int a, b,c;
	
	ff = fopen("G.txt","r");
	fscanf(ff,"%d",&a);
	fscanf(ff,"%d",&b);
	printf("a=%d",a);
	fflush(stdout);
	printf("b=%d\n",b);
	fflush(stdout);
	c=10000;
	printf("sizeofc=%d",sizeof(c));
	fflush(stdout);

	return 0 ;

}