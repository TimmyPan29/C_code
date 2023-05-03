#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int c2num(int n){
    n-='0';
    return n;
}
int main(){
	FILE *fpr;
    fpr = fopen("setting.txt","r");
    if(fpr==NULL){
        return 0;
    }
    //get n,r,H,m,z
    char buffer[50];
    int L=50;
    int n,r,m,temp;
    fgets(buffer,L+1,fpr);
    temp=0;
    for(int i=0;i<L;i++){
        if((int)buffer[i]<48){
            for(int j=0;j<i;j++){
                temp*=10;
                temp+=c2num(buffer[j]);
            }
            n=temp;
			printf("%d\n",n);
            break;
        }
    }
	fgets(buffer,L+1,fpr);
    temp=0;
    for(int i=0;i<L;i++){
        if((int)buffer[i]<48){
            for(int j=0;j<i;j++){
                temp*=10;
                temp+=c2num(buffer[j]);
            }
            r=temp;
			printf("%d\n",r);
            break;
        }
    }
	char temp1;
	temp1='a';
	printf("%d\n",temp1);
	fflush(stdout);
	
	int temp2=0;
	temp2*=10;
	printf("temp=%d",temp2);
	fflush(stdout);
	return 0;
}